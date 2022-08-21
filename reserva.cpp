#include "reserva.h" //include do arquivo 'reserva.h'

//  Constructor
Reserva::Reserva(int nm_acmp, int nm_quarto, int dias, string nome, string tipo_quarto)
{
    this->nm_acmp = nm_acmp;
    this->nm_quarto = nm_quarto;
    this->nome = nome;
    this->tipo_quarto = tipo_quarto;
    this->dias = dias;

    // É gerado um número aleatório para a reserva na main
    this->nm_res = 0;
}

//  Métodos set
void Reserva::set_montante(float montante)
{
    this->montante = montante;
}

void Reserva::set_nmReserva(int& nm_res)
{
    this->nm_res = nm_res;
}

//  Métodos get
float Reserva::getmontante() const
{
    return montante;
}

int Reserva::getdias() const
{
    return dias;
}

int Reserva::get_nmReserva() const
{
    return nm_res;
}

int Reserva::get_nmAc() const 
{
    return nm_acmp;
}

int Reserva::get_nmquarto() const
{
    return nm_quarto;
}

string Reserva::get_nome() const 
{
    return nome;
}

string Reserva::get_tipoQuarto() const
{
    return tipo_quarto;
}
