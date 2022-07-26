#ifndef Hotel_H
#define Hotel_H

class Hotel{
    private:
        vector<Quarto> lista_quarto;
        vector<QuartoPremium> lista_premium;
        vector<QuartoPcD> lista_PcD;
        vector<Reserva> lista_reservas;
        int ranking;
        static int pessoas;
        static int maxQuartos;
        static int contador;

    public:
        bool addQuarto(Quarto);
        bool addPremium(QuartoPremium);
        bool addPcD(QuartoPcD);
        bool addReserva(Reserva);
        void cancelaReserva();
        bool setAndares();
        void defRanking();
        void printQuartos() const;
        void printQuarDesocupados() const;
        void pesquisaQuarto() const;
        int getRanking() const;
        int getAndares() const;
        static void setMaxQuartos();
        static int getPessoas();
        static int getMaxQuartos();
        static int getContador();
};
#endif
