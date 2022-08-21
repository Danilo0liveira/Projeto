#include "QuartoPcD.h"

// Construtor
QuartoPcD::QuartoPcD(int andar, int camas, int capacidade, float diaria, int num, string tipoAdaptacao, int servicoEspecial) : Quarto(andar, camas, capacidade, diaria, num)
{
    this->tipoAdaptacao = tipoAdaptacao;
    this->servicoEspecial = servicoEspecial;
}

//  Métodos set
void QuartoPcD::setTipoAdaptacao(string tipoAdaptacao)
{
    this->tipoAdaptacao = tipoAdaptacao;
}

void QuartoPcD::setServicoEspecial(int servicoEspecial)
{
    this->servicoEspecial = servicoEspecial;
}

//  Métodos get
string QuartoPcD::getTipoAdaptacao() const
{
    return tipoAdaptacao;
}

int QuartoPcD::getServ() const
{
    return servicoEspecial;
}
