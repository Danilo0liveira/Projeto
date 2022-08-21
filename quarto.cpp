// Incluindo o protótipo da classe
#include "quarto.h"

// Construtor Inicializando Variáveis
Quarto :: Quarto(int andar, int camas, int capacidade, float diaria, int numero){
    this -> andar = andar;
    this -> camas = camas;
    this -> capacidade = capacidade;
    this -> diaria = diaria;
    this -> numero = numero;

    // Inicializando a situação do quarto como falsa (desocupado)
    this -> situacao = false;
}

// Metodos set

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

// Metodos get
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
