#ifndef Hotel_H
#define Hotel_H

//Criacao da classe hotel, que ira ser o nosso "estoque"
class Hotel{
    private:
        vector<Quarto> lista_quarto;//Lista de quartos simples.
        vector<QuartoPremium> lista_premium;//Lista de quartos premiums.
        vector<QuartoPcD> lista_PcD;//Listas de quartos PcD.
        vector<Reserva> lista_reservas;//Listas de reservas.

        //Os atributos utilizados para o quarto.
        int ranking;//Ranking do hotel.
        int andares;//Andares possiveis no hotel.
        int pessoas;//Numero de pessoas no hotel.
        int maxQuartos;//Numero maximo de quartos no hotel.
        int contador;//Numero atual de quartos no hotel.

    public:
        Hotel();//Construtor que ira ler o arquivo das listas.
        bool addQuarto(Quarto);//Metodos de adicionar os quartos.
        bool addPremium(QuartoPremium);
        bool addPcD(QuartoPcD);
        bool addReserva(Reserva);
        bool cancelaReserva(int);//Metodo de cancelar os reservas.
        void setAndares(int);//Adicionar valor aos andares do hotel.
        void defRanking();//Definicao de ranking.
        void printQuartos() const;//Exibir todos os quartos.
        void printQuarDesocupados() const;//Exibir apenas os quartos desocupados.
        void pesquisaQuarto(int) const;//Pesquisa um dos quartos.
        int getRanking() const;//Retorna ranking do hotel inteiro.
        int getAndares() const;//Retorna o numero de andares.
        void setMaxQuartos(int);//Setando o valor maximo de quartos.
        void defPessoas();//Definindo o numero de pessoas no hotel.
        int getPessoas();//Retornando o numero de pessoas.
        int getMaxQuartos();//Retornando o numero maximo de quartos.
        int getContador();//Retornando o numero atual de quartos.
        void gravaListas();//Gravando as listas num arquivo.
        ~Hotel();//Destrutor que ira chamar o metodo de gravar.
};
#endif
