#ifndef QUARTOPREMIUM_H
#define QUARTOPREMIUM_H

class QuartoPremium : public Quarto
{
private:
    int wifi,chuvelet,servquart;
    float arcond,tv;
public:
    QuartoPremium(int andar, int camas, int capacidade, float diaria, int numero);
    // métodos gets
    void setWifi(const int&);
    void setChuvelet(const int&);
    void setArcond(const float&);
    void setTv(const float&);
    void setServico(const int&);
    int getWifi() const;
    int getChuvelet() const;
    float getArcond() const;
    float getTv() const;
    int getServico() const;

};

#endif
