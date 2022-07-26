#include "quartop.h"

Quarto_premium :: Quarto_premium(int andar, int camas, int capacidade, float diaria, int numero, bool situacao) : Quarto(int andar, int camas, int capacidade, float diaria, int numero, bool situacao){
    this -> ar_cnd = 0;
    this -> chuv_el = 0;
    this -> servico = 0;
    this -> tv = 0;
    this -> wifi = 0;
}

void Quarto_premium :: setAR_CND(int ar_cnd){
    this -> ar_cnd = ar_cnd;
}

void Quarto_premium :: setC_EL(int chuv_el){
    this -> chuv_el = chuv_el;
}

void Quarto_premium :: setServico(int servico){
    this -> servico = servico;
}

void Quarto_premium :: setTV(int tv){
    this -> tv = tv;
}

void Quarto_premium :: setWifi(int wifi){
    this -> wifi = wifi;
}

int Quarto_premium :: getAR_CND() const{
    return ar_cnd;
}

int Quarto_premium :: getC_EL() const{
    return chuv_el;
}

int Quarto_premium :: getServico() const{
    return servico;
}

int Quarto_premium :: getTV() const{
    return tv;
}

int Quarto_premium :: getWifi() const{
    return wifi;
}