#ifndef QuartoPcD_H
#define QuartoPcD_H

// Quarto para pessoas com deficiência (herda Quarto Padrão)
class QuartoPcD : public Quarto
{

// Atributos Privados
private:
    string tipoAdaptacao;
    int servicoEspecial; // Número de funcionários que auxiliam o cliente com ajuda especializada 

public:
// Construtor
    QuartoPcD(int, int, int, float, int, string, int);

//  Métodos set
    void setTipoAdaptacao(string);
    void setServicoEspecial(int);

//  Métodos get
    string getTipoAdaptacao() const;
    int getServ() const;

};

#endif
