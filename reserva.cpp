#include "reserva.h"

Reserva::Reserva(int& nm_acmp, int& nm_quarto, std::string& nome)
{
    this->nm_acmp = (nm_acmp < 0) ? 0 : nm_acmp;
    this->nm_quarto = (nm_quarto < 0) ? 0 : nm_quarto;
    this->nome = nome;
    
//     srand(unsigned time(0)); incluir na main
    this->nm_res = 66666 + (rand() % 6666) + (rand() % 6666);
}

int Reserva::get_nmReserva() const
{
    return nm_res;
}

int Reserva::get_nmAc() const 
{
    return nm_acmp;
}

std::string Reserva::get_nome() const 
{
    return nome;
}

int Reserva::get_nmquarto() const
{
    return nm_quarto;
}
