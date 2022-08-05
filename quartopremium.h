#ifndef QUARTOPREMIUM_H
#define QUARTOPREMIUM_H

class QuartoPremium : public Quarto 
{
private:
    int wifi,chuvelet,arcond,tv,servquart;
public:
    QuartoPremium(int andar, int camas, int capacidade, float diaria, int numero);
    // métodos gets
    void setWifi(const int&);
    void setChuvelet(const int&);
    void setArcond(const int&);
    void setTv(const int&);
    void setServico(const int&);
    int getWifi() const;
    int getChuvelet() const;
    int getArcond() const;
    int getTv() const;
    int getServico() const;

};

#endif
