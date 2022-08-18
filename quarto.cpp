// incluindo a biblioteca
#include "quarto.h"

// construtor inicializando variáveis
Quarto :: Quarto(int andar, int camas, int capacidade, float diaria, int numero){
    this -> andar = andar;
    this -> camas = camas;
    this -> capacidade = capacidade;
    this -> diaria = diaria;
    this -> numero = numero;
    this -> situacao = false;
}

// inicializando a situação como falsa
void Quarto :: setSituacao(bool situacao){
    this -> situacao = situacao;
}

void Quarto::setDiaria(float diaria){
    this->diaria = diaria;
}

void Quarto::setCamas(int camas){
    this->camas = camas;
}

void Quarto::setCapacidade(int capacidade){
    this->capacidade = capacidade;
}

// metodos get
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
