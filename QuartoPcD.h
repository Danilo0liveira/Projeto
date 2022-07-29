#ifndef QuartoPcD_H
#define QuartoPcD_H

//Quarto vai ser incluido na main
//supondo que using namespace std;

class QuartoPcD : public Quarto
{
// atributos privados
private:
    string tipoAdaptacao;
    int servicoEspecial;
public:
// constructor
    QuartoPcD(int, int, int, int, float, string, int);
//  métodos sets
    void setTipoAdaptacao(string);
    void setServ(int);
//  métodos gets
    string getTipoAdaptacao() const;
    int getServ() const;
    
};

#endif
