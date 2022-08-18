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
    QuartoPcD(int, int, int, float, int, string, int);
    void setTipoAdaptacao(string);
    void setServicoEspecial(int);
//  métodos gets
    string getTipoAdaptacao() const;
    int getServ() const;

};

#endif
