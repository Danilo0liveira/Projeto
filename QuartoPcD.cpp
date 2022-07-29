#include "QuartoPcD.h"

//constructor
QuartoPcD::QuartoPcD(int numQuarto, int andar, int camas, int capacidade, float diaria, string tipoAdaptacao, int servicoEspecial): Quarto(numQuarto, andar, camas, capacidade, diaria){
    setTipoAdaptacao(tipoAdaptacao);
    setServ(servicoEspecial);
}

//métodos set (atributos da classe derivada)
void QuartoPcD::setTipoAdaptacao(string tipoAdaptacao){
    this->tipoAdaptacao = tipoAdaptacao;
}

void QuartoPcD::setServ(int servicoEspecial){
    this->servicoEspecial = servicoEspecial;
}

//metodos gets
string QuartoPcD::getTipoAdaptacao() const{
    return tipoAdaptacao;
}

int QuartoPcD::getServ() const{
    return servicoEspecial;
}
