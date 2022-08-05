#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>

using namespace std;

#include "quarto.cpp"
#include "QuartoPcD.cpp"
#include "quartopremium.cpp"
#include "reserva.cpp"
#include "hotel.cpp"

int main()
{
    // criação do objeto 'hotel' do tipo 'Hotel'
    srand((unsigned) time(0));
    Hotel hotel;

    hotel.setAndares(2);
    hotel.setMaxQuartos(5);

    cout << "Andares do hotel: " << hotel.getAndares() << endl;
    cout << "Capacidade maxima de quartos: " << hotel.getMaxQuartos() << endl << endl;

    // criação dos objetos que serão inseridos nos vectors do hotel
    Quarto quarto(1,2,3,4.87,544);
    QuartoPcD quarto_pcd(1,2,3,4,566, "Teste", 3);
    QuartoPremium quarto_plus(2,3,4,5,236);

    //métodos sets do 'quarto_plus'
    quarto_plus.setArcond(3);
    quarto_plus.setChuvelet(8);
    quarto_plus.setServico(9);
    quarto_plus.setTv(3);
    quarto_plus.setWifi(2);

    // chamando métodos 'add' para acrescentar os quartos ao hotel
    hotel.addQuarto(quarto);
    hotel.addPcD(quarto_pcd);
    hotel.addPremium(quarto_plus);


    // mostra os quartos adicionados
    hotel.printQuartos();
    cin.get();
    
    // chamando metodo de remoção de quarto
    hotel.rmv_quarto(566, 3);
    hotel.printQuartos();
    cin.get();


    // realizando reserva

    // criação do objeto 'reserva' do tipo 'Reserva'
    Reserva reserva(1,236,"Nome");
    Reserva reserva2(1,544,"Nome dois");

    // chamando método 'addReserva' do objeto 'hotel'

    hotel.addReserva(reserva2);

    // mostra reservas
    cout << "Reservas: " << endl << endl;
    hotel.printReservas();
    cin.get();

    cout << "Numero de pessoas: " << hotel.getPessoas() << endl << endl;
    cin.get();

    cout << "Quartos apos a reserva: " << endl << endl;
    hotel.printQuartos();
    cin.get();

    // remove reserva
    hotel.removerReserva(reserva2.get_nmReserva());
    
    cout << "Quartos apos a remocao da reserva: " << endl << endl;
    hotel.printReservas();
    cin.get();

    cout << "Print dos quartos desocupados:" << endl << endl;
    hotel.printQuarDesocupados();

    // simulando avaliação
    hotel.defRanking(2);
    
    cout << "\navaliacao: " << hotel.getRanking()/hotel.get_contAva() << endl;
    cout << "Numero de avaliacoes: " << hotel.get_contAva() << endl;
    cout << "numero de quartos: " << hotel.getContador();
}