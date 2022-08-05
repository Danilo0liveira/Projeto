#ifndef RESERVA_h
#define RESERVA_h

class Reserva
{
private:
    int nm_res, nm_acmp, nm_quarto;
    float custo;
    string nome;
    //incluir tipo de quarto ?

public:
    // constructor
    Reserva(int nm_acmp, int nm_quarto, string nome);
    //métodos gets
    int get_nmReserva() const;
    int get_nmAc() const;
    int get_nmquarto() const;
    string get_nome() const;

};

#endif
