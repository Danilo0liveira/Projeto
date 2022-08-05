#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

#include "quarto.cpp"
#include "QuartoPcD.cpp"
#include "quartopremium.cpp"
#include "reserva.cpp"

#include "hotel.cpp"

int main()
{
    Hotel hotel;
    Quarto quarto(1,2,3,4.5,5);
    hotel.addQuarto(quarto);
    // QuartoPremium quarto_plus(1,2,3,5.5,4);
    // std:cout << "@@@@" << hotel.addPcD(quartopcd) << std::endl;

    hotel.printQuartos();
}