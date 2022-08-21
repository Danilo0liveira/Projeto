#ifndef Hotel_H
#define Hotel_H

//Criacao da classe hotel, que ira ser o nosso "estoque"
class Hotel
{
private:
    vector<Quarto> lista_quarto; // Lista de quartos padrão.
    vector<QuartoPremium> lista_premium; // Lista de quartos premiums.
    vector<QuartoPcD> lista_PcD; // Listas de quartos PcD.
    vector<Reserva> lista_reservas; // Listas de reservas.
    vector<int> quartos_andar; // Lista para controlar o numero máximo de quartos por andar.

    // Os atributos utilizados para o quarto.
    float ranking;  // Ranking do hotel.
    int pessoas;    // Numero de pessoas no hotel.
    int maxQuartos_andares; // Numero maximo de quartos por andares no hotel.
    int cont_avaliacoes; // Contador de avaliações

public:
    Hotel(); // Construtor que ira ler o arquivo das listas.
    void setAndares(int&); // Adicionar valor aos andares do hotel.
    void setMaxQuartos(int); // Setando o valor maximo de quartos.
    void defRanking(float); // Definicao de ranking.

    // Gerenciamento dos quartos

        // Metodos de adicionar os quartos.
    bool addQuarto(Quarto&); 
    bool addPremium(QuartoPremium&);
    bool addPcD(QuartoPcD&);

        // Verifica se o quarto existe e está desocupado.
    bool verificaQuarto(int, int);

        // Metodos modifica e remove quarto.
    bool modificaQuarto(int, int);
    bool modificaQuarto_premium(int, int);
    bool modificaQuarto_PcD(int, int);
    bool rmv_quarto(const int&, int); // Remove o quarto e recebe como argumento o número e tipo do quarto.

    // Gerenciamento das reservas
    bool addReserva(Reserva&);
    float pesquisaMontante(int); // Retorna o montante de uma dada reserva
    bool removerReserva(int); // Metodo de cancelar os reservas.

    // Prints
    void printQuartos() const; // Exibir todos os quartos.
    void printQuarDesocupados() const; // Exibir apenas os quartos desocupados.
    void printQuarOcupados() const; // Exibir apenas os quartos desocupados.
    void printReservas() const;
    bool pesquisaQuarto(int) const; // Pesquisa um dos quartos.

    // Métodos relacionados ao Hotel em si
    float getRanking() const;
    int getAndares() const; // Retorna o numero de andares.
    int get_contAva() const; // Retorna o contador de avaliações do hotel
    int getPessoas() const; // Retornando o numero de pessoa-s.
    int getMaxQuartos() const; // Retornando o numero maximo de quartos.
    void gravaListas(); // Gravando as listas num arquivo.
    ~Hotel(); // Destrutor que ira chamar o metodo de gravar.
};
#endif
