#ifndef QUARTOPREMIUM_H
#define QUARTOPREMIUM_H

class QuartoPremium : public Quarto 
{
private:
    int wifi,chuvelet,arcond,tv,servquart;
public:
    QuartoPremium(int numero,int andar,int camas,int capacidade,int diaria);
    // métodos gets
    int getwifi{} const;
    int getchuvelet{} const;
    int getarcond{} const;
    int gettv{} const;
    int getservquart{} const;

};

#endif
