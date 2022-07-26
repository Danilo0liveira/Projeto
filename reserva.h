#ifndef reserva_h
#define reserva_h

#include <iostream>
#include <string>
#include <cstdlib>

class Reserva
{
private:
    int nm_res, nm_acmp, nm_quarto;
    std::string nome;

public:
    Reserva(int& nm_acmp, int& nm_quarto, std::string& nome);
    int get_nmReserva() const;
    int get_nmAc() const;
    int get_nmquarto() const;
    std::string get_nome() const;

};

#endif
