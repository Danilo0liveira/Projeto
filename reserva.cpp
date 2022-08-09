#include "reserva.h" //include do arquivo 'reserva.h'

//definição do constructor
Reserva::Reserva(int nm_acmp, int nm_quarto, int dias, string nome, string tipo_quarto)
{
    this->nm_acmp = nm_acmp;
    this->nm_quarto = nm_quarto;
    this->nome = nome;
    this->tipo_quarto = tipo_quarto;
    this->dias = dias;

    //incluir na main
    //gera número aleatório para a reserva
    this->nm_res = 66666 + (rand() % 6666) + (rand() % 6666);
}

void Reserva::set_nmReserva(int& nm_res)
{
    this->nm_res = nm_res;
}

//definição dos métodos gets
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
