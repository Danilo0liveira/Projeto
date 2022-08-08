#ifndef Hotel_H
#define Hotel_H

//Criacao da classe hotel, que ira ser o nosso "estoque"
class Hotel
{
private:
    vector<Quarto> lista_quarto; // Lista de quartos simples.
    vector<QuartoPremium> lista_premium; // Lista de quartos premiums.
    vector<QuartoPcD> lista_PcD; // Listas de quartos PcD.
    vector<Reserva> lista_reservas; // Listas de reservas.
    
    //Os atributos utilizados para o quarto.
    float ranking;//Ranking do hotel.
    int andares;//Andares possiveis no hotel.
    int pessoas;//Numero de pessoas no hotel. //valores devem estar no construtor
    int maxQuartos;//Numero maximo de quartos no hotel.
    int contador;//Numero atual de quartos no hotel.
    int cont_avaliacoes;
    vector<int> quartos_andar;//lista para controlar o numero máximo de quartos por andar.

public:
    Hotel();//Construtor que ira ler o arquivo das listas. 
    bool addQuarto(Quarto&); //Metodos de adicionar os quartos.
    bool addPremium(QuartoPremium&);
    bool addPcD(QuartoPcD&);
    bool addReserva(Reserva&);
    bool rmv_quarto(const int&, int);
    bool removerReserva(int);//Metodo de cancelar os reservas.
    void setAndares(int);//Adicionar valor aos andares do hotel.
    void defRanking(float);//Definicao de ranking.
    void printQuartos() const;//Exibir todos os quartos.
    void printQuarDesocupados() const;//Exibir apenas os quartos desocupados.
    void printReservas() const;
    void pesquisaQuarto(int) const;//Pesquisa um dos quartos.
    float getRanking() const;//Retorna ranking do hotel inteiro.
    int getAndares() const;//Retorna o numero de andares.
    int get_contAva() const;
    void setMaxQuartos(int);//Setando o valor maximo de quartos.
    int getPessoas() const;//Retornando o numero de pessoas.
    int getMaxQuartos() const;//Retornando o numero maximo de quartos.
    int getContador() const;//Retornando o numero atual de quartos.
    void gravaListas();//Gravando as listas num arquivo.
    ~Hotel();//Destrutor que ira chamar o metodo de gravar.
};
#endif
