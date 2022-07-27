#include "quarto.h"

Quarto :: Quarto(int andar, int camas, int capacidade, float diaria, int numero){
    this -> andar = andar;
    this -> camas = camas;
    this -> capacidade = capacidade;
    this -> diaria = diaria;
    this -> numero = numero;
    this -> situacao = situacao;
}

/*
void Quarto :: setAndar(int andar){
    this -> andar = andar
}

void Quarto :: setCamas(int camas){
    this -> camas = camas
}

void Quarto :: setCapacidade(int capacidade){
    this -> capacidade = capacidade
}

void Quarto :: setDiaria(float diaria){
    this -> diaria = diaria
}

void Quarto :: setNumero(int numero){
    this -> numero = numero
}
*/

void Quarto :: setSituacao(bool situacao){
    this -> situacao = false;
}

int Quarto :: getAndar() const{
    return andar;
}

int Quarto :: getCamas() const{
    return camas;
}

int Quarto :: getCapacidade() const{
    return capacidade;
}

float Quarto :: getDiaria() const{
    return diaria;
}

int Quarto :: getNumero() const{
    return numero;
}

bool Quarto :: getSituacao() const{
    return situacao;
}
