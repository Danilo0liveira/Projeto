#include <iostream>

using namespace std;

#include "quarto.cpp"//Incluimos o quarto.cpp para testar o quarto.

int main(){
    Quarto quartoVazio;//Criacao do objeto com construtor vazio.
    Quarto quartoConstrutor(2, 4, 5, 250.25 , 240);//Criacao do objeto com construtor completo.

    //Impressao completa do quartoVazio.
    cout << "Quarto vazio: " << endl << "Andar: " << quartoVazio.getAndar()
    << endl << "Camas: " << quartoVazio.getCamas() << endl << "Capacidade: "<< quartoVazio.getCapacidade()
    << endl << "Diaria: " << quartoVazio.getDiaria()
    << endl << "Numero: " << quartoVazio.getNumero() << endl;

    if(quartoVazio.getSituacao())
        cout << "Situacao: ocupado" << endl;

    else
        cout << "Situacao: desocupado" << endl;

    //Impressao completa do quartoConstrutor.
    cout << "Quarto construtor: " << endl << "Andar: " << quartoConstrutor.getAndar()
    << endl << "Camas: " << quartoConstrutor.getCamas() << endl << "Capacidade: " << quartoConstrutor.getCapacidade()
    << endl << "Diaria: " << quartoConstrutor.getDiaria()
    << endl << "Numero: " << quartoConstrutor.getNumero() << endl;

    if(quartoConstrutor.getSituacao())
        cout << "Situacao: ocupado" << endl;

    else
        cout << "Situacao: desocupado" << endl;

    //Mudanca da situacao dos quartos.
    quartoVazio.setSituacao(true);
    quartoConstrutor.setSituacao(true);

    //Cout da mudanca dos quartos feita com sucesso.
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
