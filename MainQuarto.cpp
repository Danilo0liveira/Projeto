//int andar, int camas, int capacidade, float diaria, int numero


#include <iostream>

using namespace std;

#include "quarto.cpp"

int main(){
    Quarto quartoVazio;
    Quarto quartoConstrutor(2, 4, 5, 250.25 , 240);

    cout << "Quarto vazio: " << endl << "Andar: " << quartoVazio.getAndar()
    << endl << "Camas: " << quartoVazio.getCamas() << endl << "Capacidade: "<< quartoVazio.getCapacidade()
    << endl << "Diaria: " << quartoVazio.getDiaria()
    << endl << "Numero: " << quartoVazio.getNumero() << endl;

    if(quartoVazio.getSituacao())
        cout << "Situacao: ocupado" << endl;

    else
        cout << "Situacao: desocupado" << endl;

    cout << "Quarto construtor: " << endl << "Andar: " << quartoConstrutor.getAndar()
    << endl << "Camas: " << quartoConstrutor.getCamas() << endl << "Capacidade: " << quartoConstrutor.getCapacidade()
    << endl << "Diaria: " << quartoConstrutor.getDiaria()
    << endl << "Numero: " << quartoConstrutor.getNumero() << endl;

    if(quartoConstrutor.getSituacao())
        cout << "Situacao: ocupado" << endl;

    else
        cout << "Situacao: desocupado" << endl;

    quartoVazio.setSituacao(true);
    quartoConstrutor.setSituacao(true);

    if(quartoVazio.getSituacao())
        cout << "Situacao: ocupado" << endl;

    else
        cout << "Situacao: desocupado" << endl;

    if(quartoConstrutor.getSituacao())
        cout << "Situacao: ocupado" << endl;

    else
        cout << "Situacao: desocupado" << endl;

    return 0;
}
