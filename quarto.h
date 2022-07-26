#ifndef quarto_h
#define quarto_h

class Quarto{
    private:
        bool situacao;
        float diaria;
        int andar, camas, capacidade, numero;
    public:
        Quarto(int, int, int, float, int);

        /*
        void setAndar(int);
        void setCamas(int);
        void setCapacidade(int);
        void setDiaria(float);
        void setNumero(int);
        */
    
        void setSituacao(bool);
        int getAndar() const;
        int getCamas() const;
        int getCapacidade() const;
        float getDiaria() const;
        int getNumero() const;
        bool getSituacao() const;
};

#endif
