#ifndef RESERVA_h
#define RESERVA_h

class Reserva
{
private:
    int nm_res, nm_acmp, nm_quarto, dias;
    string nome, tipo_quarto;
    float montante;
    //incluir tipo de quarto ?

public:
    // constructor
    Reserva(int nm_acmp, int nm_quarto, int dias, string nome, string tipo_quarto);
    //métodos gets
    void set_nmReserva(int&);
    void set_montante(float montante);
    float getmontante() const;
    int getdias() const;
    int get_nmReserva() const;
    int get_nmAc() const;
    int get_nmquarto() const;
    string get_nome() const;
    string get_tipoQuarto() const;

};

#endif
