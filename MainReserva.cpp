#include <iostream>
#include <ctime>
using namespace std;

#include "reserva.cpp"//Inclui-se o arquivo reserva.cpp.

int main(){
    srand((unsigned) time(0));
    Reserva reservaConstrutor(5, 200, "ANGELO");//Criado o objeto reserva com os construtores setados.

    //Imprimido os valores de reserva.
    cout << "Reserva:" << endl << "Numero de reserva: " << reservaConstrutor.get_nmReserva()
    << endl << "Numero de acompanhantes: " << reservaConstrutor.get_nmAc()
    << endl << "Numero do quarto: " << reservaConstrutor.get_nmquarto() << endl
    << "Nome do cliente: " << reservaConstrutor.get_nome() << endl;

    return 0;
}
