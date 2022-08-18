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
    vector<int> quartos_andar;//lista para controlar o numero máximo de quartos por andar.

    //Os atributos utilizados para o quarto.
    float ranking;  //Ranking do hotel.
    int pessoas;    //Numero de pessoas no hotel.
    int maxQuartos_andares; //Numero maximo de quartos por andares no hotel.
    int cont_avaliacoes; //Contador de avaliações

public:
    Hotel();//Construtor que ira ler o arquivo das listas.
    void setAndares(int&);//Adicionar valor aos andares do hotel.
    void setMaxQuartos(int);//Setando o valor maximo de quartos.
    void defRanking(float);//Definicao de ranking.
    bool addQuarto(Quarto&); //Metodos de adicionar os quartos.
    bool addPremium(QuartoPremium&);
    bool addPcD(QuartoPcD&);
    bool verificaQuarto(int, int);//Verificação se o quarto é existente e desocupado.
    bool modificaQuarto(int, int);//Metodos modifica quarto.
    bool modificaQuarto_premium(int, int);
    bool modificaQuarto_PcD(int, int);
    bool rmv_quarto(const int&, int);
    bool addReserva(Reserva&);
    float pesquisaMontante(int);
    bool removerReserva(int);//Metodo de cancelar os reservas.
    void printQuartos() const;//Exibir todos os quartos.
    void printQuarDesocupados() const;//Exibir apenas os quartos desocupados.
    void printQuarOcupados() const;//Exibir apenas os quartos desocupados.
    void printReservas() const;
    bool pesquisaQuarto(int) const;//Pesquisa um dos quartos.
    float getRanking() const;
    int getAndares() const;//Retorna o numero de andares.
    int get_contAva() const;
    int getPessoas() const;//Retornando o numero de pessoa-s.
    int getMaxQuartos() const;//Retornando o numero maximo de quartos.
    void gravaListas();//Gravando as listas num arquivo.
    ~Hotel();//Destrutor que ira chamar o metodo de gravar.
};
#endif
