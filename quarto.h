#ifndef quarto_h
#define quarto_h

class Quarto{
    private:
        // atributos
        bool situacao;
        float diaria;
        int andar, camas, capacidade, numero;
        
    public:
        // construtor
        Quarto(int, int, int, float, int);
        
        // metodos
        void setSituacao(bool);
        int getAndar() const;
        int getCamas() const;
        int getCapacidade() const;
        float getDiaria() const;
        int getNumero() const;
        bool getSituacao() const;
};

#endif
