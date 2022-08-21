#ifndef QUARTOPREMIUM_H
#define QUARTOPREMIUM_H

class QuartoPremium : public Quarto
{
private:
    int wifi,chuvelet,servquart; // velocidade do wifi, número de chuveiros elétricos e quantidade de funcionários que prestam serviço especializado ao cliente
    float arcond,tv; // BTUs do ar condicionado e polegadas da tv

public:

    // Construtor
    QuartoPremium(int andar, int camas, int capacidade, float diaria, int numero);

    //  Métodos set
    void setWifi(const int&);
    void setChuvelet(const int&);
    void setArcond(const float&);
    void setTv(const float&);
    void setServico(const int&);

    //  Métodos get
    int getWifi() const;
    int getChuvelet() const;
    float getArcond() const;
    float getTv() const;
    int getServico() const;

};

#endif
