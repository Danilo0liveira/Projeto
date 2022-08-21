#ifndef quarto_h
#define quarto_h


// Quarto Padrão (base)

class Quarto{
    private:
        // Atributos
        bool situacao;
        float diaria;
        int andar, camas, capacidade, numero;

    public:
        // Construtor
        Quarto(int = 0, int = 0, int = 0, float = 0.0, int = 0);

        // Metodos Set
        void setSituacao(bool);
        void setDiaria(float);
        void setCamas(int);
        void setCapacidade(int);

        // Metodos Get
        int getAndar() const;
        int getCamas() const;
        int getCapacidade() const;
        float getDiaria() const;
        int getNumero() const;
        bool getSituacao() const;
};

#endif

