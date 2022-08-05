#include "quartopremium.h" //include do headerfile

QuartoPremium::QuartoPremium(int andar, int camas, int capacidade, float diaria, int numero) : Quarto(andar, camas, capacidade , diaria, numero)
{
    this -> wifi = 0; 
    this -> chuvelet = 0;   
    this -> arcond = 0;
    this -> tv = 0;
    this -> servquart = 0;
}

//métodos sets
void QuartoPremium::setWifi(const int& wifi)
{
    this->wifi = wifi;
}

void QuartoPremium::setChuvelet(const int& chuvelet)
{
    this->chuvelet = chuvelet;
}

void QuartoPremium::setArcond(const int& arcond)
{
    this->arcond = arcond;
}

void QuartoPremium::setTv(const int& tv)
{
    this->tv = tv;
}

void QuartoPremium::setServico(const int& servquart)
{
    this->servquart = servquart;
}

//definição dos métodos do get
int QuartoPremium::getWifi() const
{
    return wifi;
}

int QuartoPremium::getChuvelet() const
{
    return chuvelet;
}

int QuartoPremium::getArcond() const
{
    return arcond;
}

int QuartoPremium::getTv() const
{
    return tv;
}

int QuartoPremium::getServico() const
{
    return servquart;
}

