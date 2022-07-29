#ifndef reserva_h
#define reserva_h

//bibliotecas que serão incluidas na main
// #include <iostream>
// #include <string>
// #include <cstdlib>

class Reserva
{
private:
    int nm_res, nm_acmp, nm_quarto;
    string nome;

public:
    // constructor
    Reserva(int& nm_acmp, int& nm_quarto, string& nome);
    //métodos gets
    int get_nmReserva() const;
    int get_nmAc() const;
    int get_nmquarto() const;
    string get_nome() const;

};

#endif
