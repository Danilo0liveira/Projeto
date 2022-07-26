#ifndef QuartoPcD_H
#define QuartoPcD_H

//Quarto vai ser incluido na main

//supondo que using namespace std;

class QuartoPcD:public Quarto{
    string tipoAdaptacao;
    int servicoEspecial;
    public:
        QuartoPcD(int, int, int, int, float, bool, string, int);
        void setTipoAdaptacao(string);
        void setServ(int);
        string getTipoAdaptacao() const;
        int getServ() const;
};

#endif