#ifndef quarto_h
#define quarto_h

class Quarto{
    private:
        bool situacao;
        float diaria;
        int andar, camas, capacidade, numero, ranking;
    
    public:
        Quarto(int, int, int, float, int, bool);

        /*
        void setAndar(int);
        void setCamas(int);
        void setCapacidade(int);
        void setDiaria(float);
        void setNumero(int);
        void setSituacao(bool);
        void setRanking(int);
        */

        int getAndar() const;
        int getCamas() const;
        int getCapacidade() const;
        float getDiaria() const;
        int getNumero() const;
        int getRanking() const;
        bool getSituacao() const;
};

#endif