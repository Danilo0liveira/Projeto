#include "quartopremium.h" //include do headerfile

//construtor
QuartoPremium::QuartoPremium(int numero,int andar,int camas,int capacidade,int diaria) : Quarto(numero,andar,camas,capacidade,diaria)
{
    this -> wifi = 0; 
    this -> chuvelet = 0;   
    this -> arcond = 0;
    this -> tv = 0;
    this -> servquart = 0;
}

//definição dos métodos do get
int QuartoPremium::getwifi()
{
    return wifi;
}

int QuartoPremium::getchuvelet()
{
    return chuvelet;
}

int QuartoPremium::getarcond()
{
    return arcond;
}

int QuartoPremium::gettv()
{
    return tv;
}

int QuartoPremium::getservquart()
{
    return servquart;
}

