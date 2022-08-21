#ifndef RESERVA_h
#define RESERVA_h

class Reserva
{
private:
    int nm_res, nm_acmp, nm_quarto, dias; // num. reserva, num. de acompanhantes, num. do quarto, num. de dias
    string nome, tipo_quarto;
    float montante; // Diaria x Quantidade de dias da reserva

public:
    //  Constructor
    Reserva(int nm_acmp, int nm_quarto, int dias, string nome, string tipo_quarto);

    //  Métodos set
    void set_nmReserva(int&);
    void set_montante(float montante);

    //  Métodos get
    float getmontante() const;
    int getdias() const;
    int get_nmReserva() const;
    int get_nmAc() const;
    int get_nmquarto() const;
    string get_nome() const;
    string get_tipoQuarto() const;

};

#endif
