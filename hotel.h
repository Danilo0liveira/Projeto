#ifndef Hotel_H
#define Hotel_H

class Hotel{
    private:
        vector<Quarto> lista_quarto;
        vector<QuartoPremium> lista_premium;
        vector<QuartoPcD> lista_PcD;
        vector<Reserva> lista_reservas;
        int ranking;
        int andares;
        int pessoas;
        int maxQuartos;
        int contador;

    public:
        Hotel();
        bool addQuarto(Quarto);
        bool addPremium(QuartoPremium);
        bool addPcD(QuartoPcD);
        bool addReserva(Reserva);
        bool cancelaReserva(int);
        void setAndares(int);
        void defRanking();
        void printQuartos() const;
        void printQuarDesocupados() const;
        void pesquisaQuarto(int) const;
        int getRanking() const;
        int getAndares() const;
        void setMaxQuartos(int);
        void defPessoas();
        int getPessoas();
        int getMaxQuartos();
        int getContador();
        ~Hotel();
};
#endif
