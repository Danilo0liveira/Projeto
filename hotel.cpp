#include "hotel.h"

//Construtor que ira ler o arquivo das listas.
Hotel::Hotel()
{
    int num, andar, camas, capacidade, wifi, chuveiro, arcond, TV, serv, nm_acmp, nm_res;
    string nome;
    string tipo;
    float diaria = 0.0;
    bool situacao;
    
    ifstream arquivo_hotel("propHotel.txt", ios::in);

    if(arquivo_hotel.is_open())
    {
        arquivo_hotel >> this->cont_avaliacoes;
        arquivo_hotel >> this->contador;
        arquivo_hotel >> this->maxQuartos;
        arquivo_hotel >> this->pessoas;
        arquivo_hotel >> this->andares;
        arquivo_hotel >> this->ranking;
    }
    else
    {
        this->cont_avaliacoes = 0;
        this->contador = 0;
        this->maxQuartos = 0;
        this->pessoas = 0;
        this->andares = 0;
        this->ranking = 0;
    }

    ifstream arquivo;
    arquivo.open("ListaQuartos.txt", ios::in);

    if(arquivo.is_open())
    {
        while(!arquivo.eof())
        {
            arquivo >> num;

            if (arquivo.eof())
				break;

            arquivo >> andar;
            arquivo >> camas;
            arquivo >> capacidade;
            arquivo >> diaria;
            arquivo >> situacao;

            Quarto aux(andar, camas, capacidade, diaria, num);
            aux.setSituacao(situacao);
            lista_quarto.emplace_back(aux);
        }
        arquivo.close();
    }

    ifstream arquivo2("ListaQuartosPremium.txt", ios::in);

    if(arquivo2.is_open()){
        while(!arquivo2.eof()){

            arquivo2 >> num;

            if (arquivo2.eof())
				break;

            arquivo2 >> andar;
            arquivo2 >> camas;
            arquivo2 >> capacidade;
            arquivo2 >> diaria;
            arquivo2 >> situacao;
            arquivo2 >> wifi;
            arquivo2 >> chuveiro;
            arquivo2 >> arcond;
            arquivo2 >> TV;
            arquivo2 >> serv;

            QuartoPremium aux(andar, camas, capacidade, diaria, num);
            aux.setWifi(wifi);
            aux.setChuvelet(chuveiro);
            aux.setArcond(arcond);
            aux.setTv(TV);
            aux.setServico(serv);
            aux.setSituacao(situacao);
            lista_premium.emplace_back(aux);
        }
        arquivo2.close();
    }

    ifstream arquivo3("ListaQuartosPcD.txt", ios::in);
    // arquivo3.open("ListaQuartosPcD.txt", ios::in);

    if(arquivo3.is_open())
    {
        while(!arquivo3.eof())
        {
            getline(arquivo3, tipo);

            if (arquivo3.eof())
				break;

            arquivo3 >> num;
            arquivo3 >> andar;
            arquivo3 >> camas;
            arquivo3 >> capacidade;
            arquivo3 >> diaria;
            arquivo3 >> situacao;
            arquivo3 >> serv;


            QuartoPcD aux(andar, camas, capacidade, diaria, num, tipo, serv);
            aux.setSituacao(situacao);
            lista_PcD.emplace_back(aux);

            arquivo3.ignore();
        }
        arquivo3.close();
    }

    ifstream arquivo4("ListaReservas.txt", ios::in);

    if(arquivo4.is_open())
    {
        while(!arquivo4.eof())
        {
            getline(arquivo4, nome);

            if (arquivo4.eof()) 
                break;

            arquivo4 >> nm_res;
            arquivo4 >> nm_acmp;
            arquivo4 >> num;
            arquivo4.ignore();

            Reserva reserva(nm_acmp, num, nome);
            lista_reservas.emplace_back(reserva);
        }
        arquivo4.close();
    }
}

//Metodos de adicionar os quartos.
bool Hotel::addQuarto(Quarto& q)
{
    for (const auto& quarto : lista_quarto)
    {
        if (q.getNumero() == quarto.getNumero())
            return false;
    }
    for (const auto& quarto : lista_PcD)
    {
        if (q.getNumero() == quarto.getNumero())
            return false;
    }
    for (const auto& quarto : lista_premium)
    {
        if (q.getNumero() == quarto.getNumero())
            return false;
    }

    if(contador == maxQuartos || q.getAndar() > andares || q.getAndar() < 0)
        return false;

    lista_quarto.emplace_back(q);
    contador++;

    return true;
}

bool Hotel::addPremium(QuartoPremium& q)
{
    for (const auto& quarto : lista_quarto)
    {
        if (q.getNumero() == quarto.getNumero())
            return false;
    }
    for (const auto& quarto : lista_PcD)
    {
        if (q.getNumero() == quarto.getNumero())
            return false;
    }
    for (const auto& quarto : lista_premium)
    {
        if (q.getNumero() == quarto.getNumero())
            return false;
    }

    if(contador == maxQuartos || q.getAndar() > andares || q.getAndar() < 0)
        return false;

    lista_premium.emplace_back(q);
    contador++;

    return true;
}
bool Hotel::addPcD(QuartoPcD& q)
{
    for (auto& quarto : lista_quarto)
    {
        if (q.getNumero() == quarto.getNumero())
            return false;
    }
    for (auto& quarto : lista_PcD)
    {
        if (q.getNumero() == quarto.getNumero())
            return false;
    }
    for (auto& quarto : lista_premium)
    {
        if (q.getNumero() == quarto.getNumero())
            return false;
    }

    if(contador == maxQuartos || q.getAndar() > andares || q.getAndar() < 0)
        return false;

    lista_PcD.emplace_back(q);
    contador++;

    return true;
}

bool Hotel::addReserva(Reserva& r)
{
    for(unsigned u = 0; u < lista_reservas.size(); u++)
        if(r.get_nmquarto() == lista_reservas[u].get_nmquarto())
            return false;
            
    for(unsigned u = 0; u < lista_quarto.size(); u++){
        if(lista_quarto[u].getNumero() == r.get_nmquarto())
        {
            lista_quarto[u].setSituacao(true);
            lista_reservas.emplace_back(r);

            this->pessoas += r.get_nmAc();

            return true;
        }
    }

    for(unsigned u = 0; u < lista_premium.size(); u++){
        if(lista_premium[u].getNumero() == r.get_nmquarto())
        {
            lista_premium[u].setSituacao(true);
            lista_reservas.emplace_back(r);

            this->pessoas += r.get_nmAc();

            return true;
        }
    }

    for(unsigned u = 0; u < lista_PcD.size(); u++){
        if(lista_PcD[u].getNumero() == r.get_nmquarto())
        {
            lista_PcD[u].setSituacao(true);
            lista_reservas.emplace_back(r);

            this->pessoas += r.get_nmAc();

            return true;
        }
    }
    return false;
}

//informar tipo do quarto ?
bool Hotel::removerReserva(int numero_res)
{
    for (unsigned i = 0; i < lista_reservas.size(); ++i)
    {
        if (numero_res == lista_reservas[i].get_nmReserva())
        {
            int numero_quarto = lista_reservas[i].get_nmquarto();
            lista_reservas.erase(lista_reservas.begin() + i);
            pessoas -= lista_reservas[i].get_nmAc();

            for (unsigned u = 0; u < lista_quarto.size(); ++u)
            {
                if (numero_quarto == lista_quarto[u].getNumero())
                {
                    lista_quarto[u].setSituacao(false);
                    return true;
                }
            }
            for (unsigned u = 0; u < lista_premium.size(); ++u)
            {
                if (numero_quarto == lista_premium[u].getNumero())
                {
                    lista_premium[u].setSituacao(false);
                    return true;
                }
            }
            for (unsigned u = 0; u < lista_PcD.size(); ++u)
            {
                if (numero_quarto == lista_PcD[u].getNumero())
                {
                    lista_PcD[u].setSituacao(false);
                    return true;
                }
            }
        }
    }
    return false;
}

bool Hotel::rmv_quarto(const int& num_quarto, int tipo)
{
    if (tipo == 1)
    {
        for (unsigned i = 0; i < lista_quarto.size(); ++i)
        {
            if (num_quarto == lista_quarto[i].getNumero() && !lista_quarto[i].getSituacao())
            {
                lista_quarto.erase(lista_quarto.begin() + i);
                return true;
            }
        }
    }
    else if (tipo == 2)
    {
        for (unsigned i = 0; i < lista_premium.size(); ++i)
        {
            if (num_quarto == lista_premium[i].getNumero() && !lista_premium[i].getSituacao())
            {
                lista_premium.erase(lista_premium.begin() + i);
                --contador;
                return true;
            }
        }
    }
    else
    {
        for (unsigned i = 0; i < lista_PcD.size(); ++i)
        {
            if (num_quarto == lista_PcD[i].getNumero() && !lista_PcD[i].getSituacao())
            {
                lista_PcD.erase(lista_PcD.begin() + i);
                --contador;
                return true;
            }
        }
    }
    return false;
}

//Adicionar valor aos andares do hotel.
void Hotel::setAndares(int a){
    andares = a;
}

// Definicao de ranking.
void Hotel::defRanking(float valor)
{
    this->ranking += valor;
    ++cont_avaliacoes;
}

//Exibir todos os quartos.
void Hotel::printQuartos() const
{
    if(contador == 0)
        cout << "Nao ha quartos no hotel!" << endl;

    else{
        for(unsigned u = 0; u < lista_quarto.size(); u++){
            cout << "Quartos padroes: "<< endl << "Numero: " << lista_quarto[u].getNumero()
            << endl << "Andar: " << lista_quarto[u].getAndar() << endl << "Camas: " << lista_quarto[u].getCamas()
            << endl << "Capacidade: " << lista_quarto[u].getCapacidade() << endl << "Diaria: "
            << lista_quarto[u].getDiaria() << endl;

            if(lista_quarto[u].getSituacao())
                cout << "Situacao: ocupado" << endl << endl;
            else
                cout << "Situacao: desocupado" << endl << endl;
        }

        for(unsigned u = 0; u < lista_premium.size(); u++){
            cout << "Quartos premium: "<< endl << "Numero: " << lista_premium[u].getNumero()
            << endl << "Andar: " << lista_premium[u].getAndar() << endl << "Camas: " << lista_premium[u].getCamas()
            << endl << "Capacidade: " << lista_premium[u].getCapacidade() << endl << "Diaria: "
            << lista_premium[u].getDiaria() << endl << "Wifi: " << lista_premium[u].getWifi() << " mbps" << endl
            << "Chuveiro Eletricos: " << lista_premium[u].getChuvelet() << " chuveiros" << endl
            << "Ar Condicionado: " << lista_premium[u].getArcond() << " BTUs" << endl << "TV: "
            << lista_premium[u].getTv() << " polegadas" << endl << "Servico de quarto: "
            << lista_premium[u].getServico() << " funcionarios" << endl;

            if(lista_premium[u].getSituacao())
                cout << "Situacao: ocupado" << endl << endl;
            else
                cout << "Situacao: desocupado" << endl << endl;
        }

        for(unsigned u = 0; u < lista_PcD.size(); u++){
            cout << "Quartos PcD: "<< endl << "Numero: " << lista_PcD[u].getNumero()
            << endl << "Andar: " << lista_PcD[u].getAndar() << endl << "Camas: " << lista_PcD[u].getCamas()
            << endl << "Capacidade: " << lista_PcD[u].getCapacidade() << endl << "Diaria: "
            << lista_PcD[u].getDiaria() << endl << "Tipo adaptacao: " << lista_PcD[u].getTipoAdaptacao() << endl
            << "Servicos especiais: " << lista_PcD[u].getServ() << " funcionarios" << endl;

            if(lista_PcD[u].getSituacao())
                cout << "Situacao: ocupado" << endl << endl;
            else
                cout << "Situacao: desocupado" << endl << endl;
        }
    }
}

//Exibir apenas os quartos desocupados.
void Hotel::printQuarDesocupados() const
{
    if(contador == 0)
        cout << "Nao ha quartos no hotel!" << endl;

    else{

        for(unsigned u = 0; u < lista_quarto.size(); u++){
            if(!lista_quarto[u].getSituacao())
            {
                cout << "Quartos padroes: "<< endl << "Numero: " << lista_quarto[u].getNumero()
                << endl << "Andar: " << lista_quarto[u].getAndar() << endl << "Camas: " << lista_quarto[u].getCamas()
                << endl << "Capacidade: " << lista_quarto[u].getCapacidade() << endl << "Diaria: "
                << lista_quarto[u].getDiaria() << endl << endl;
            }
        }

        for(unsigned u = 0; u < lista_premium.size(); u++){
            if(!lista_premium[u].getSituacao())
            {
                cout << "Quartos premium: "<< endl << "Numero: " << lista_premium[u].getNumero()
                << endl << "Andar: " << lista_premium[u].getAndar() << endl << "Camas: " << lista_premium[u].getCamas()
                << endl << "Capacidade: " << lista_premium[u].getCapacidade() << endl << "Diaria: "
                << lista_premium[u].getDiaria() << endl << "Wifi: " << lista_premium[u].getWifi() << " mbps" << endl
                << "Chuveiro Eletricos: " << lista_premium[u].getChuvelet() << " chuveiros" << endl
                << "Ar Condicionado: " << lista_premium[u].getArcond() << " BTUs" << endl << "TV: "
                << lista_premium[u].getTv() << " polegadas" << endl << "Servico de quarto: "
                << lista_premium[u].getServico() << " funcionarios" << endl;
            }
        }

        for(unsigned u = 0; u < lista_PcD.size(); u++){
            if(!lista_PcD[u].getSituacao())
            {
                cout << "Quartos PCD: "<< endl << "Numero: " << lista_PcD[u].getNumero()
                << endl << "Andar: " << lista_PcD[u].getAndar() << endl << "Camas: " << lista_PcD[u].getCamas()
                << endl << "Capacidade: " << lista_PcD[u].getCapacidade() << endl << "Diaria: "
                << lista_PcD[u].getDiaria() << endl << "Tipo adaptacao: " << lista_PcD[u].getTipoAdaptacao() << endl
                << "Servicos especiais: " << lista_PcD[u].getServ() << " funcionarios" << endl;
            }
        }
    }
}

//Pesquisa um dos quartos. //adicionar tipo do quarto a ser pesquisado!
void Hotel::pesquisaQuarto(int numero) const
{
    for(unsigned u = 0; u < lista_quarto.size(); u++){
        if(numero == lista_quarto[u].getNumero()){
            cout << "Numero: " << lista_quarto[u].getNumero()
            << endl << "Andar: " << lista_quarto[u].getAndar() << endl << "Camas: " << lista_quarto[u].getCamas()
            << endl << "Capacidade: " << lista_quarto[u].getCapacidade() << endl << "Diaria: "
            << lista_quarto[u].getDiaria() << endl;

            if(lista_quarto[u].getSituacao() == true)
                cout << "Situacao: ocupado" << endl << endl;

            else
                cout << "Situacao: desocupado" << endl << endl;
        }
    }

    for(unsigned u = 0; u < lista_premium.size(); u++){
        if(numero == lista_premium[u].getNumero()){
            cout << "Numero: " << lista_premium[u].getNumero()
            << endl << "Andar: " << lista_premium[u].getAndar() << endl << "Camas: " << lista_premium[u].getCamas()
            << endl << "Capacidade: " << lista_premium[u].getCapacidade() << endl << "Diaria: "
            << lista_premium[u].getDiaria() << endl << "Wifi: " << lista_premium[u].getWifi() << " mbps" << endl
            << "Chuveiro Eletricos: " << lista_premium[u].getChuvelet() << " chuveiros" << endl
            << "Ar Condicionado: " << lista_premium[u].getArcond() << " BTUs" << endl << "TV: "
            << lista_premium[u].getTv() << " polegadas" << endl << "Servico de quarto: "
            << lista_premium[u].getServico() << " funcionarios" << endl;

            if(lista_PcD[u].getSituacao())
                cout << "Situacao: ocupado" << endl << endl;
            else
                cout << "Situacao: desocupado" << endl << endl;
        }

    }

    for(unsigned u = 0; u < lista_PcD.size(); u++){
        if(numero == lista_PcD[u].getNumero())
        {
            cout << "Quartos padroes: "<< endl << "Numero: " << lista_PcD[u].getNumero()
            << endl << "Andar: " << lista_PcD[u].getAndar() << endl << "Camas: " << lista_PcD[u].getCamas()
            << endl << "Capacidade: " << lista_PcD[u].getCapacidade() << endl << "Diaria: "
            << lista_PcD[u].getDiaria() << endl << "Tipo adaptacao: " << lista_PcD[u].getTipoAdaptacao() << endl
            << "Servicos especiais: " << lista_PcD[u].getServ() << " funcionarios" << endl;

            if(lista_PcD[u].getSituacao())
                cout << "Situacao: ocupado" << endl << endl;
            else
                cout << "Situacao: desocupado" << endl << endl;
        }
    }
}

void Hotel::printReservas() const
{
    for(const auto& res : lista_reservas)
    {
        cout << "Numero da reserva: " << res.get_nmReserva()
        << endl << "Numero de acompanhanetes: " << res.get_nmAc()
        << endl << "Numero do quarto: " << res.get_nmquarto()
        << endl << "Nome do cliente: " << res.get_nome() << "\n\n";
    }
}

//Retorna ranking do hotel inteiro.
float Hotel::getRanking() const
{
    return ranking;
}

//Retorna o numero de andares.
int Hotel::getAndares() const
{
    return andares;
}

//Setando o valor maximo de quartos.
void Hotel::setMaxQuartos(int maximo){
    maxQuartos = maximo;
}

//Retornando o numero de pessoas.
int Hotel::getPessoas() const
{
    return pessoas;
}

//Retornando o numero maximo de quartos.
int Hotel::getMaxQuartos() const
{
    return maxQuartos;
}

//Retornando o numero atual de quartos.
int Hotel::getContador() const
{
    return contador;
}

int Hotel::get_contAva() const
{
    return cont_avaliacoes;
}

//Gravando as listas num arquivo.
void Hotel::gravaListas(){

    ofstream arquivo("ListaQuartos.txt", ios::trunc);
    // arquivo.open("ListaQuartos.txt");

    if(arquivo.is_open())
    {
        for(unsigned u = 0; u < lista_quarto.size(); u++)
        {
            arquivo << lista_quarto[u].getNumero() << endl;
            arquivo << lista_quarto[u].getAndar() << endl;
            arquivo << lista_quarto[u].getCamas() << endl;
            arquivo << lista_quarto[u].getCapacidade() << endl;
            arquivo << lista_quarto[u].getDiaria() << endl;
            arquivo << lista_quarto[u].getSituacao() << endl;
        }
        arquivo.close();
    }

    // else
	// 	cout<<"Nao foi possivel abrir o arquivo"<<endl;

    ofstream arquivo2;
    arquivo2.open("ListaQuartosPremium.txt", ios::trunc);

    if(arquivo2.is_open()){
        for(unsigned u = 0; u < lista_premium.size(); u++){
            arquivo2 << lista_premium[u].getNumero() << endl;
            arquivo2 << lista_premium[u].getAndar() << endl;
            arquivo2 << lista_premium[u].getCamas() << endl;
            arquivo2 << lista_premium[u].getCapacidade() << endl;
            arquivo2 << lista_premium[u].getDiaria() << endl;
            arquivo2 << lista_premium[u].getSituacao() << endl;
            arquivo2 << lista_premium[u].getWifi() << endl;
            arquivo2 << lista_premium[u].getChuvelet() << endl;
            arquivo2 << lista_premium[u].getArcond() << endl;
            arquivo2 << lista_premium[u].getTv() << endl;
            arquivo2 << lista_premium[u].getServico() << endl;
        }
        arquivo2.close();
    }

    // else
	// 	cout<<"Nao foi possivel abrir o arquivo"<<endl;

    ofstream arquivo3("ListaQuartosPcD.txt", ios::trunc);
    // arquivo3.open("ListaQuartosPcD.txt", ios::trunc);
    
    if(arquivo3.is_open())
    {
        for(unsigned u = 0; u < lista_PcD.size(); u++)
        {
            arquivo3 << lista_PcD[u].getTipoAdaptacao() << endl;
            arquivo3 << lista_PcD[u].getNumero() << endl;
            arquivo3 << lista_PcD[u].getAndar() << endl;
            arquivo3 << lista_PcD[u].getCamas() << endl;
            arquivo3 << lista_PcD[u].getCapacidade() << endl;
            arquivo3 << lista_PcD[u].getDiaria() << endl;
            arquivo3 << lista_PcD[u].getSituacao() << endl;
            arquivo3 << lista_PcD[u].getServ() << endl;
        }
        arquivo3.close();
    }

    // else
	// 	cout<<"Nao foi possivel abrir o arquivo"<<endl;

    ofstream arquivo4("ListaReservas.txt", ios::trunc);

    if(arquivo4.is_open())
    {
        for (const auto& reserva : lista_reservas)
        {
            arquivo4 << reserva.get_nome() << std::endl;
            arquivo4 << reserva.get_nmReserva() << std::endl;
            arquivo4 << reserva.get_nmAc() << std::endl;
            arquivo4 << reserva.get_nmquarto() << std::endl;
        }
        arquivo4.close();
    }

    // else
	// 	cout<<"Nao foi possivel abrir o arquivo"<<endl;

    ofstream arquivo_hotel("propHotel.txt");

    if(arquivo_hotel.is_open())
    {
        arquivo_hotel << this->cont_avaliacoes << std::endl;
        arquivo_hotel << this->contador << std::endl;
        arquivo_hotel << this->maxQuartos << std::endl;
        arquivo_hotel << this->pessoas << std::endl;
        arquivo_hotel << this->andares << std::endl;
        arquivo_hotel << this->ranking << std::endl;
    }
}

//Destrutor que ira chamar o metodo de gravar.
Hotel::~Hotel(){
    gravaListas();
}
