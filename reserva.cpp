#include "reserva.h" //include do arquivo 'reserva.h'

//definição do constructor
Reserva::Reserva(int nm_acmp, int nm_quarto, string nome)
{
    this->nm_acmp = (nm_acmp < 0) ? 0 : nm_acmp;
    this->nm_quarto = (nm_quarto < 0) ? 0 : nm_quarto;
    this->nome = nome;
    
    //incluir na main
    //gera número aleatório para a reserva
    this->nm_res = 66666 + (rand() % 6666) + (rand() % 6666);
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

string Reserva::get_nome() const 
{
    return nome;
}

int Reserva::get_nmquarto() const
{
    return nm_quarto;
}
