#ifndef QUARTOPREMIUM_H
#define QUARTOPREMIUM_H

class QuartoPremium : public Quarto 
{
private:
    int wifi,chuvelet,arcond,tv,servquart;
public:
    QuartoPremium{int numero,int andar,int camas,int capacidade,int diaria}
   /*
    void setwifi{}; 
    void setchuvelet{};
    void setarcond{};
    void settv{};
    void setservquart{};
    */
    int getwifi{} const;
    int getchuvelet{} const;
    int getarcond{} const;
    int gettv{} const;
    int getservquart{} const;

    
};
#endif