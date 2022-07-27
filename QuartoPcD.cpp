#include "QuartoPcD.h"

QuartoPcD::QuartoPcD(int numQuarto, int andar, int camas, int capacidade, float diaria, string tipoAdaptacao, int servicoEspecial): Quarto(numQuarto, andar, camas, capacidade, diaria){
    setTipoAdaptacao(tipoAdaptacao);
    setServ(servicoEspecial);
}

void QuartoPcD::setTipoAdaptacao(string tipoAdaptacao){
    this->tipoAdaptacao = tipoAdaptacao;
}

void QuartoPcD::setServ(int servicoEspecial){
    this->servicoEspecial = servicoEspecial;
}

string QuartoPcD::getTipoAdaptacao() const{
    return tipoAdaptacao;
}

int QuartoPcD::getServ() const{
    return servicoEspecial;
}
