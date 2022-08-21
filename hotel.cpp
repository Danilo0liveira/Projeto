#include "hotel.h"

//Construtor que ira ler o arquivo das listas.
Hotel::Hotel()
{
    int num, andar, camas, capacidade, wifi, chuveiro, serv, nm_acmp, nm_res;
    string nome,tipo,tipo_quarto;
    float diaria, arcond,TV;
    bool situacao;

    // Abre o arquivo que contém os dados armazenados do hotel, caso exista.
    ifstream arquivo_hotel("propHotel.txt", ios::in);

    if(arquivo_hotel.is_open())
    {
        // Lê o arquivo e carrega os atributos do hotel.
        arquivo_hotel >> this->cont_avaliacoes;
        arquivo_hotel >> this->maxQuartos_andares;
        arquivo_hotel >> this->pessoas;
        arquivo_hotel >> this->ranking;

        while(!arquivo_hotel.eof()) 
        {
            /* Enquanto não for o fim do arquivo, adiciona no vector quartos_andar um int que indica 
            a quantidade máxima de quartos em determinado andar */
            arquivo_hotel >> andar;
            quartos_andar.emplace_back(andar); /* O tamanho do vector indica o numero de andares no hotel, e cada index do elemento 
                                                  no vector representa um andar */

        }
    }
    
    else // Caso o arquivo não exista, seta os valores do hotel sendo 0
    {
        this->cont_avaliacoes = 0;
        this->maxQuartos_andares = 0;
        this->pessoas = 0;
        this->ranking = 0;
    }

    // Abre o arquivo com dados de todos os quartos padrão, se ele existir
    ifstream arquivo;
    arquivo.open("ListaQuartos.txt", ios::in);

    if(arquivo.is_open())
    {
        while(!arquivo.eof())
        {
            // Lê o arquivo e carrega os atributos do Quarto.
            arquivo >> num;

            if (arquivo.eof())  // Para o programa caso seja o fim do arquivo, necessário para evitar ler uma linha a mais
				break;

            arquivo >> andar;
            arquivo >> camas;
            arquivo >> capacidade;
            arquivo >> diaria;
            arquivo >> situacao;

            Quarto aux(andar, camas, capacidade, diaria, num); // Cria um objeto de Quarto
            aux.setSituacao(situacao);
            lista_quarto.emplace_back(aux); // Adiciona o quarto no vector com todos os quartos
        }
        arquivo.close();
    }

    // Abre o arquivo com dados de todos os quartos premium, se ele existir
    ifstream arquivo2("ListaQuartosPremium.txt", ios::in);

    if(arquivo2.is_open()){
        while(!arquivo2.eof()){

            // Lê o arquivo e carrega os atributos do Quarto Premium.
            arquivo2 >> num;

            if (arquivo2.eof()) // Para o programa caso seja o fim do arquivo, necessário para evitar ler uma linha a mais
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

            QuartoPremium aux(andar, camas, capacidade, diaria, num); // Cria um objeto de Quarto Premium


            // Configura atributos especializados do Quarto Premium 
            aux.setWifi(wifi);
            aux.setChuvelet(chuveiro);
            aux.setArcond(arcond);
            aux.setTv(TV);
            aux.setServico(serv);
            aux.setSituacao(situacao);

            lista_premium.emplace_back(aux); // Adiciona o quarto no vector com todos os quartos premium
        }
        arquivo2.close();
    }

    // Abre o arquivo com dados de todos os quartos pcd, se ele existir
    ifstream arquivo3("ListaQuartosPcD.txt", ios::in);

    if(arquivo3.is_open())
    {
        while(!arquivo3.eof())
        {
            // Lê o arquivo e carrega os atributos do Quarto Premium.

            getline(arquivo3, tipo);

            if (arquivo3.eof()) // Para o programa caso seja o fim do arquivo, necessário para evitar ler uma linha a mais
				break;

            arquivo3 >> num;
            arquivo3 >> andar;
            arquivo3 >> camas;
            arquivo3 >> capacidade;
            arquivo3 >> diaria;
            arquivo3 >> situacao;
            arquivo3 >> serv;


            QuartoPcD aux(andar, camas, capacidade, diaria, num, tipo, serv); // Cria um objeto de Quarto PcD
            aux.setSituacao(situacao);
            lista_PcD.emplace_back(aux); // Adiciona o quarto no vector com todos os quartos pcd

            arquivo3.ignore();
        }
        arquivo3.close();
    }


    // Abre o arquivo com dados de todas reservas, se ele existir
    ifstream arquivo4("ListaReservas.txt", ios::in);

    if(arquivo4.is_open())
    {
        // inicializa as variáveis de montante e dias
        float montante = 0.0;
        int dias = 0;

        while(!arquivo4.eof())
        {
            // Lê o arquivo e carrega os atributos da Reserva.
            getline(arquivo4, nome);

            if (arquivo4.eof()) // Para o programa caso seja o fim do arquivo, necessário para evitar ler uma linha a mais
                break;


            arquivo4 >> nm_res;
            arquivo4 >> nm_acmp;
            arquivo4 >> num;

            arquivo4.ignore();
            getline(arquivo4, tipo_quarto);

            arquivo4 >> dias;
            arquivo4 >> montante;
            arquivo4.ignore();

            Reserva reserva(nm_acmp, num, dias, nome, tipo_quarto); // Cria um objeto Reserva com os dados carregados

            // Seta atributos mais atributos da reserva
            reserva.set_nmReserva(nm_res);
            reserva.set_montante(montante);
            lista_reservas.emplace_back(reserva); // Adiciona a Reserva carregada na lista de reservas
        }
        arquivo4.close();
    }
}

// Define a quantidade de andares/tamanho do vector dos quartos
void Hotel::setAndares(int& andares)
{
    quartos_andar.resize(andares);
}

// Setando o valor maximo de quartos.
void Hotel::setMaxQuartos(int maximo){
    maxQuartos_andares = maximo;
}

// Definicao de ranking.
void Hotel::defRanking(float valor)
{
    this->ranking += valor;
    ++cont_avaliacoes;
}

// Metodos de adicionar os quartos.
bool Hotel::addQuarto(Quarto& q) // retorna falso se a operação falhou, e true caso a operação foi um sucesso
{
    // Verifica em cada lista se existe um quarto com mesmo número
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

    // Caso não exista quarto com mesmo número, verifica se o andar inserido foi válido e se o andar não atingiu o máximo de andares
    if(q.getAndar() > quartos_andar.size()-1 || q.getAndar() < 0 || quartos_andar[q.getAndar()] == maxQuartos_andares)
        return false;

    lista_quarto.emplace_back(q); // adiciona o quarto na lista de quartos
    quartos_andar[q.getAndar()]++; // adiciona 1 no número de quartos no determinado andar

    return true;
}

bool Hotel::addPremium(QuartoPremium& q) // retorna falso se a operação falhou, e true caso a operação foi um sucesso
{
    // Verifica em cada lista se existe um quarto com mesmo número
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

    // Caso não exista quarto com mesmo número, verifica se o andar inserido foi válido e se o andar não atingiu o máximo de andares
    if(q.getAndar() > quartos_andar.size()-1 || q.getAndar() < 0 || quartos_andar[q.getAndar()] == maxQuartos_andares)
        return false;

    lista_premium.emplace_back(q);  // adiciona o quarto na lista de quartos
    quartos_andar[q.getAndar()]++;  // adiciona 1 no número de quartos no determinado andar

    return true;
}

bool Hotel::addPcD(QuartoPcD& q) // retorna falso se a operação falhou, e true caso a operação foi um sucesso
{
    // Verifica em cada lista se existe um quarto com mesmo número
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

    // Caso não exista quarto com mesmo número, verifica se o andar inserido foi válido e se o andar não atingiu o máximo de andares
    if(q.getAndar() > quartos_andar.size()-1 || q.getAndar() < 0 || quartos_andar[q.getAndar()] == maxQuartos_andares)
        return false;

    lista_PcD.emplace_back(q);  // adiciona o quarto na lista de quartos
    quartos_andar[q.getAndar()]++;  // adiciona 1 no número de quartos no determinado andar

    return true;
}

// Verificação se o quarto existe e está desocupado.
bool Hotel::verificaQuarto(int nm, int tipo)
{
    if(tipo == 1)
    {
        for(unsigned u = 0; u < lista_quarto.size(); u++)
            if(lista_quarto[u].getNumero() == nm) // Se o caso existir, busca sua situação
            {
                if(lista_quarto[u].getSituacao()) // Se o quarto está ocupado, retorna false
                    return false;

                pesquisaQuarto(nm);
                return true;
            }
    }

    else if(tipo == 2)
    {
        for(unsigned u = 0; u < lista_premium.size(); u++)
            if(lista_premium[u].getNumero() == nm) // Se o caso existir, busca sua situação
            {
                if(lista_premium[u].getSituacao()) // Se o quarto está ocupado, retorna false
                    return false;

                pesquisaQuarto(nm);
                return true;
            }
    }

    else if(tipo == 3)
    {
        for(unsigned u = 0; u < lista_PcD.size(); u++)
            if(lista_PcD[u].getNumero() == nm) // Se o caso existir, busca sua situação
            {
                if(lista_PcD[u].getSituacao()) // Se o quarto está ocupado, retorna false
                    return false;

                pesquisaQuarto(nm);
                return true;
            }
    }

    return false; // Retorna false caso o quarto nao exista
}

// Metodos de modificar os Quartos
bool Hotel::modificaQuarto(int nm, int atrib)
{
    // se atrib = 1 -> modifica a diaria; atrib = 2 -> modifica o numero de camas; atrib = 3 -> modifica a capacidade do quarto.
    switch(atrib)
    {

        // Modifica a diaria
        case 1:
        {
            float diaria;

            while(1)
            {
                cout << "Digite a modificação desejada: ";
                diaria = verificaFloat();

                if(diaria > 0)
                    break;

                cout << "Inválido" << endl;
            }

            for(unsigned u = 0; u < lista_quarto.size(); u++)
                if(lista_quarto[u].getNumero() == nm)
                {
                    lista_quarto[u].setDiaria(diaria);
                    return true;
                }
            break;
        }

        // Modifica a quantidade de camas
        case 2:
        {
            int camas;

            while(1)
            {
                cout << "Digite a modificação desejada: ";
                camas = verificaInt();

                if(camas > 0)
                    break;

                cout << "Inválido" << endl;
            }

            for(unsigned u = 0; u < lista_quarto.size(); u++)
                if(lista_quarto[u].getNumero() == nm)
                {
                    lista_quarto[u].setCamas(camas);
                    return true;
                }
            break;
        }

        // Modifica a capacidade do quarto
        case 3:
        {
            int capacidade;

            while(1)
            {
                cout << "Digite a modificação desejada: ";
                capacidade = verificaInt();

                if(capacidade > 0)
                    break;

                cout << "Inválido" << endl;
            }

            for(unsigned u = 0; u < lista_quarto.size(); u++)
                if(lista_quarto[u].getNumero() == nm)
                {
                    lista_quarto[u].setCapacidade(capacidade);
                    return true;
                }
            break;
        }
    }
    return false;
}

bool Hotel::modificaQuarto_premium(int nm, int atrib)
{
    /* se atrib = 1 -> modifica a diaria; atrib = 2 -> modifica o numero de camas; atrib = 3 -> modifica a capacidade do quarto.
          atrib = 4 -> modifica o wifi; atrib = 5 -> modifica a quantidade de chuveiros; atrib = 6 -> modifica o serviço de quarto
          atrib = 7 -> modifica o ar condicionado; atrib = 8 -> modifica as polegadas da tv.  */
    switch(atrib)
    {
        // Modifica a diaria
        case 1:
        {
            float diaria;

            while(1)
            {
                cout << "Digite a modificação desejada: ";
                diaria = verificaFloat();

                if(diaria > 0)
                    break;

                cout << "Inválido" << endl;
            }

            for(unsigned u = 0; u < lista_premium.size(); u++)
                if(lista_premium[u].getNumero() == nm)
                {
                    lista_premium[u].setDiaria(diaria);
                    return true;
                }
            break;
        }
        
        // Modifica a quantidade de camas
        case 2:
        {
            int camas;

            while(1)
            {
                cout << "Digite a modificação desejada: ";
                camas = verificaInt();

                if(camas > 0)
                    break;

                cout << "Inválido" << endl;
            }

            for(unsigned u = 0; u < lista_premium.size(); u++)
                if(lista_premium[u].getNumero() == nm)
                {
                    lista_premium[u].setCamas(camas);
                    return true;
                }
            break;
        }

        // Modifica a capacidade do quarto
        case 3:
        {
            int capacidade;

            while(1)
            {
                cout << "Digite a modificação desejada: ";
                capacidade = verificaInt();

                if(capacidade > 0)
                    break;

                cout << "Inválido" << endl;
            }

            for(unsigned u = 0; u < lista_premium.size(); u++)
                if(lista_premium[u].getNumero() == nm)
                {
                    lista_premium[u].setCapacidade(capacidade);
                    return true;
                }
            break;
        }

        // Modifica o wif
        case 4:
        {
            int wifi;

            while(1)
            {
                cout << "Digite a modificação desejada: ";
                wifi = verificaInt();

                if(wifi > 0)
                    break;

                cout << "Inválido" << endl;
            }

            for(unsigned u = 0; u < lista_premium.size(); u++)
                if(lista_premium[u].getNumero() == nm)
                {
                    lista_premium[u].setWifi(wifi);
                    return true;
                }
            break;
        }

        // Modifica a quantidade de chuveiros elétricos
        case 5:
        {
            int chuveiros;

            while(1)
            {
                cout << "Digite a modificação desejada: ";
                chuveiros = verificaInt();

                if(chuveiros > 0)
                    break;

                cout << "Inválido" << endl;
            }

            for(unsigned u = 0; u < lista_premium.size(); u++)
                if(lista_premium[u].getNumero() == nm)
                {
                    lista_premium[u].setChuvelet(chuveiros);
                    return true;
                }
            break;
        }

        // Modifica o serviço de quarto
        case 6:
        {
            int servQuarto;

            while(1)
            {
                cout << "Digite a modificação desejada: ";
                servQuarto = verificaInt();

                if(servQuarto > 0)
                    break;

                cout << "Inválido" << endl;
            }

            for(unsigned u = 0; u < lista_premium.size(); u++)
                if(lista_premium[u].getNumero() == nm)
                {
                    lista_premium[u].setServico(servQuarto);
                    return true;
                }
            break;
        }

        // Modifica os BTUs do ar condicionado
        case 7:
        {
            float arcond;

            while(1)
            {
                cout << "Digite a modificação desejada: ";
                arcond = verificaFloat();

                if(arcond > 0)
                    break;

                cout << "Inválido" << endl;
            }

            for(unsigned u = 0; u < lista_premium.size(); u++)
                if(lista_premium[u].getNumero() == nm)
                {
                    lista_premium[u].setArcond(arcond);
                    return true;
                }
            break;
        }

        // Modifica as polegadas da tv
        case 8:
        {
            float tv;

            while(1)
            {
                cout << "Digite a modificação desejada: ";
                tv = verificaFloat();

                if(tv > 0)
                    break;

                cout << "Inválido" << endl;
            }

            for(unsigned u = 0; u < lista_premium.size(); u++)
                if(lista_premium[u].getNumero() == nm)
                {
                    lista_premium[u].setTv(tv);
                    return true;
                }
            break;
        }
    }
    return false;
}

bool Hotel::modificaQuarto_PcD(int nm, int atrib)
{
    /* se atrib = 1 -> modifica a diaria; atrib = 2 -> modifica o numero de camas; atrib = 3 -> modifica a capacidade do quarto.
          atrib = 4 -> modifica o tipo de adaptacao; atrib = 5 -> modifica a serviço de quarto.*/
    switch(atrib)
    {
        // Modifica a diaria
        case 1:
        {
            float diaria;

            while(1)
            {
                cout << "Digite a modificação desejada: ";
                diaria = verificaFloat();

                if(diaria > 0)
                    break;

                cout << "Inválido" << endl;
            }

            for(unsigned u = 0; u < lista_PcD.size(); u++)
                if(lista_PcD[u].getNumero() == nm)
                {
                    lista_PcD[u].setDiaria(diaria);
                    return true;
                }
            break;
        }

        // Modifica a quantidade de camas
        case 2:
        {
            int camas;

            while(1)
            {
                cout << "Digite a modificação desejada: ";
                camas = verificaInt();

                if(camas > 0)
                    break;

                cout << "Inválido" << endl;
            }

            for(unsigned u = 0; u < lista_PcD.size(); u++)
                if(lista_PcD[u].getNumero() == nm)
                {
                    lista_PcD[u].setCamas(camas);
                    return true;
                }
            break;
        }

        // Modifica a capacidade do quarto
        case 3:
        {
            int capacidade;

            while(1)
            {
                cout << "Digite a modificação desejada: ";
                capacidade = verificaInt();

                if(capacidade > 0)
                    break;

                cout << "Inválido" << endl;
            }

            for(unsigned u = 0; u < lista_PcD.size(); u++)
                if(lista_PcD[u].getNumero() == nm)
                {
                    lista_PcD[u].setCapacidade(capacidade);
                    return true;
                }
            break;
        }

        // Modifica o tipo de adaptação do quarto
        case 4:
        {
            string tipoAdaptacao;

            cout << "Digite a modificação desejada: ";
            cin.sync();
            getline(cin, tipoAdaptacao);


            for(unsigned u = 0; u < lista_PcD.size(); u++)
                if(lista_PcD[u].getNumero() == nm)
                {
                    lista_PcD[u].setTipoAdaptacao(tipoAdaptacao);
                    return true;
                }
            break;

        }

        // Modifica o serviço de quarto
        case 5:
        {
            int servQuarto;

            while(1)
            {
                cout << "Digite a modificação desejada: ";
                servQuarto = verificaInt();

                if(servQuarto > 0)
                    break;

                cout << "Inválido" << endl;
            }

            for(unsigned u = 0; u < lista_PcD.size(); u++)
                if(lista_PcD[u].getNumero() == nm)
                {
                    lista_PcD[u].setServicoEspecial(servQuarto);
                    return true;
                }
            break;

        }
    }
    return false;
}

// Metodo de remover quarto, possível apenas se o quarto existir e não estiver ocupado
bool Hotel::rmv_quarto(const int& num_quarto, int tipo) // retorna true caso a operação seja um sucesso, caso contrário, retorna false
{

    // Quarto Padrão
    if (tipo == 1)
    {
        for (unsigned i = 0; i < lista_quarto.size(); ++i)
        {
            if (num_quarto == lista_quarto[i].getNumero() && !lista_quarto[i].getSituacao())
            {
		        lista_quarto.erase(lista_quarto.begin() + i);

                quartos_andar[lista_quarto[i].getAndar()]--;

                return true;
            }
        }
    }

    // Quarto Premium
    else if (tipo == 2)
    {
        for (unsigned i = 0; i < lista_premium.size(); ++i)
        {
            if (num_quarto == lista_premium[i].getNumero() && !lista_premium[i].getSituacao())
            {
		        lista_premium.erase(lista_premium.begin() + i);
                quartos_andar[lista_premium[i].getAndar()]--;

                return true;
            }
        }
    }

    // Quarto PcD
    else
    {
        for (unsigned i = 0; i < lista_PcD.size(); ++i)
        {
            if (num_quarto == lista_PcD[i].getNumero() && !lista_PcD[i].getSituacao())
            {
		        lista_PcD.erase(lista_PcD.begin() + i);
                quartos_andar[lista_PcD[i].getAndar()]--;

                return true;
            }
        }
    }
    return false;
}

// Metodo para adicionar reserva no hotel
bool Hotel::addReserva(Reserva& r)
{
    // Gera número aleatório para reserva
    int nm_res = 66666 + (rand() % 6666) + (rand() % 6666);

    while(1)
    {
        bool aux = false; // booleano usado pra sair do loop

        for(const auto& reserva : lista_reservas)
        {
            if(r.get_nmquarto() == reserva.get_nmquarto()) // verifica se o quarto ja foi reservado
                return false;

            if (nm_res == reserva.get_nmReserva()) // verifica se o número de reserva já existe
            {
                while(nm_res == reserva.get_nmReserva())
                    nm_res = 66666 + (rand() % 6666) + (rand() % 6666); // cria um novo numero de reserva caso já exista
                aux = true;
            }
        }
        if(!aux) // aux só é false quando todas as verificações acima ocorrerem com sucesso, logo, !aux -> true
            break;
    }
    r.set_nmReserva(nm_res); // seta o numero da reserva no objeto Reserva

    // Mudando a situação do Quarto
    if(r.get_tipoQuarto() == "Quarto")
    {
        for(unsigned u = 0; u < lista_quarto.size(); u++){
            if(lista_quarto[u].getNumero() == r.get_nmquarto())
            {
                if(r.get_nmAc() > lista_quarto[u].getCapacidade())
                    return false;

                lista_quarto[u].setSituacao(true);

                r.set_montante(r.getdias() * lista_quarto[u].getDiaria()); // calcula o montante da reserva
                lista_reservas.emplace_back(r); // adiciona a reserva na lista de reserva

                this->pessoas += r.get_nmAc(); // aumenta o número de pessoas no hotel

                return true;
            }
        }
    }

    // Muda a situação do quarto Premium
    else if(r.get_tipoQuarto() == "Quarto Premium")
    {
        for(unsigned u = 0; u < lista_premium.size(); u++){
            if(lista_premium[u].getNumero() == r.get_nmquarto())
            {
                if(r.get_nmAc() > lista_premium[u].getCapacidade())
                    return false;

                lista_premium[u].setSituacao(true);

                r.set_montante(r.getdias() * lista_premium[u].getDiaria()); // calcula o montante da reserva
                lista_reservas.emplace_back(r); // adiciona a reserva na lista de reserva

                this->pessoas += r.get_nmAc(); // aumenta o número de pessoas no hotel

                return true;
            }
        }
    }

    // Mudando a situação do Quarto PcD
    else
    {
        for(unsigned u = 0; u < lista_PcD.size(); u++){
            if(lista_PcD[u].getNumero() == r.get_nmquarto())
            {
                if(r.get_nmAc() > lista_PcD[u].getCapacidade())
                    return false;

                lista_PcD[u].setSituacao(true);

                r.set_montante(r.getdias() * lista_premium[u].getDiaria()); // calcula o montante da reserva
                lista_reservas.emplace_back(r); // adiciona a reserva na lista de reserva

                this->pessoas += r.get_nmAc(); // aumenta o número de pessoas no hotel

                return true;
            }
        }
    }
    return false;
}

// Retorna o montante da reserva pesquisada
float Hotel::pesquisaMontante(int nm_reserva)
{
    for(unsigned u = 0; u < lista_reservas.size(); u++)
        if(nm_reserva == lista_reservas[u].get_nmReserva()) // Busca a reserva passad 
            return lista_reservas[u].getmontante(); // Retorna o montante da reserva

    return 0.0; // Caso nao encontrado a reserva, retorna 0 de montante
}

//Metodo para remover a reserva.
bool Hotel::removerReserva(int numero_res)
{
    for(unsigned i = 0; i < lista_reservas.size(); ++i)
    {
        if(numero_res == lista_reservas[i].get_nmReserva())
        {
            int numero_quarto = lista_reservas[i].get_nmquarto();
            string tipo_quarto = lista_reservas[i].get_tipoQuarto();

            pessoas -= lista_reservas[i].get_nmAc(); // Diminui o número de pessoas no Hotel

            lista_reservas.erase(lista_reservas.begin() + i); // Apaga a reserva da lista

            // Muda a situação do Quarto, se reservado
            if (tipo_quarto == "Quarto")
            {
                for (unsigned u = 0; u < lista_quarto.size(); ++u)
                {
                    if (numero_quarto == lista_quarto[u].getNumero())
                    {
                        lista_quarto[u].setSituacao(false); // seta a situação do quarto para false (desocupado)
                        return true;
                    }
                }
            }
            // Muda a situação do Quarto Premium, se reservado
            else if (tipo_quarto == "Quarto Premium")
            {
                for (unsigned u = 0; u < lista_premium.size(); ++u)
                {
                    if (numero_quarto == lista_premium[u].getNumero())
                    {
                        lista_premium[u].setSituacao(false); // seta a situação do quarto para false (desocupado)
                        return true;
                    }
                }
            }
            // Muda a situação do Quarto PcD, se reservado
            else
            {
                for (unsigned u = 0; u < lista_PcD.size(); ++u)
                {
                    if (numero_quarto == lista_PcD[u].getNumero())
                    {
                        lista_PcD[u].setSituacao(false); // seta a situação do quarto para false (desocupado)
                        return true;
                    }
                }
            }
        }
    }
    return false;
}



// Exibir todos os quartos.
void Hotel::printQuartos() const
{
    if(lista_PcD.empty() && lista_quarto.empty() && lista_premium.empty())
        cout << "Nao ha quartos no hotel!" << endl;
    else
    {
        // Printa Quartos Padrão
        cout << "Quarto padrão" << endl;
        cout << setfill('=') << setw(41) << "=" << endl;

        for(unsigned u = 0; u < lista_quarto.size(); u++)
        {
            cout << "Numero: " << lista_quarto[u].getNumero()
            << endl << "Andar: " << lista_quarto[u].getAndar() << endl << "Camas: " << lista_quarto[u].getCamas()
            << endl << "Capacidade: " << lista_quarto[u].getCapacidade() << endl << "Diaria: R$"
            << lista_quarto[u].getDiaria() << endl;

            if(lista_quarto[u].getSituacao())
                cout << "Situacao: ocupado" << endl;
            else
                cout << "Situacao: desocupado" << endl;
            cout << setfill('-') << setw(41) << "-" << endl;
        }

        if(!lista_quarto.empty())
            system("pause");

        system("cls");

        // Printa Quartos Premium
        cout << "Quarto Premium" << endl;
        cout << setfill('=') << setw(41) << "=" << endl;

        for(unsigned u = 0; u < lista_premium.size(); u++){
            cout << "Numero: " << lista_premium[u].getNumero()
            << endl << "Andar: " << lista_premium[u].getAndar() << endl << "Camas: " << lista_premium[u].getCamas()
            << endl << "Capacidade: " << lista_premium[u].getCapacidade() << endl << "Diaria: R$"
            << lista_premium[u].getDiaria() << endl << "Wifi: " << lista_premium[u].getWifi() << " mbps" << endl
            << "Chuveiro Eletricos: " << lista_premium[u].getChuvelet() << " chuveiros" << endl
            << "Ar Condicionado: " << lista_premium[u].getArcond() << " BTUs" << endl << "TV: "
            << lista_premium[u].getTv() << " polegadas" << endl << "Servico de quarto: "
            << lista_premium[u].getServico() << " funcionarios" << endl;

            if(lista_premium[u].getSituacao())
                cout << "Situacao: ocupado" << endl;
            else
                cout << "Situacao: desocupado" << endl;
            cout << setfill('-') << setw(41) << "-" << endl;
        }

        if(!lista_premium.empty())
            system("pause");

        system("cls");

        // Printa Quartos PcD
        cout << "Quarto PcD" << endl;
        cout << setfill('=') << setw(41) << "=" << endl;

        for(unsigned u = 0; u < lista_PcD.size(); u++){
            cout << endl << "Numero: " << lista_PcD[u].getNumero()
            << endl << "Andar: " << lista_PcD[u].getAndar() << endl << "Camas: " << lista_PcD[u].getCamas()
            << endl << "Capacidade: " << lista_PcD[u].getCapacidade() << endl << "Diaria: R$"
            << lista_PcD[u].getDiaria() << endl << "Tipo adaptacao: " << lista_PcD[u].getTipoAdaptacao() << endl
            << "Servicos especiais: " << lista_PcD[u].getServ() << " funcionarios" << endl;

            if(lista_PcD[u].getSituacao())
                cout << "Situacao: ocupado" << endl;
            else
                cout << "Situacao: desocupado" << endl;
            cout << setfill('-') << setw(41) << "-" << endl;
        }
    }
}

//Exibir apenas os quartos desocupados.
void Hotel::printQuarDesocupados() const
{
    if(lista_PcD.empty() && lista_quarto.empty() && lista_premium.empty()) // Verifica se há quartos no hotel
        cout << "Não há quartos no hotel!" << endl;
    else if(lista_PcD.size() + lista_quarto.size() + lista_premium.size() == lista_reservas.size()) // Verifica se há quartos desocupados no hotel
        cout << "Não há quartos disponíveis" << endl;
    else
    {
        bool cont_1 = true, cont_2 = true;

        // Printa Quartos Padrão Desocupados
        cout << "Quarto Padrão" << endl;
        cout << setfill('=') << setw(41) << "=" << endl;

        for(unsigned u = 0; u < lista_quarto.size(); u++){
            if(!lista_quarto[u].getSituacao())
            {
                cout << endl << "Numero: " << lista_quarto[u].getNumero()
                << endl << "Andar: " << lista_quarto[u].getAndar() << endl << "Camas: " << lista_quarto[u].getCamas()
                << endl << "Capacidade: " << lista_quarto[u].getCapacidade() << endl << "Diaria: R$"
                << lista_quarto[u].getDiaria() << endl;
                cout << setfill('-') << setw(41) << "-" << endl;

                cont_1 = false;
            }
        }

        if(!cont_1)
            system("pause");

        system("cls");

        // Printa Quartos Premium Desocupados
        cout << "Quarto Premium" << endl;
        cout << setfill('=') << setw(41) << "=" << endl;

        for(unsigned u = 0; u < lista_premium.size(); u++){
            if(!lista_premium[u].getSituacao())
            {
                cout << endl << "Numero: " << lista_premium[u].getNumero()
                << endl << "Andar: " << lista_premium[u].getAndar() << endl << "Camas: " << lista_premium[u].getCamas()
                << endl << "Capacidade: " << lista_premium[u].getCapacidade() << endl << "Diaria: R$"
                << lista_premium[u].getDiaria() << endl << "Wifi: " << lista_premium[u].getWifi() << " mbps" << endl
                << "Chuveiro Eletricos: " << lista_premium[u].getChuvelet() << " chuveiros" << endl
                << "Ar Condicionado: " << lista_premium[u].getArcond() << " BTUs" << endl << "TV: "
                << lista_premium[u].getTv() << " polegadas" << endl << "Servico de quarto: "
                << lista_premium[u].getServico() << " funcionarios" << endl;
                cout << setfill('-') << setw(41) << "-" << endl;

                cont_2 = false;
            }
        }

        if(!cont_2)
            system("pause");

        system("cls");

        // Printa Quartos PcD Desocupados
        cout << "Quarto PcD" << endl;
        cout << setfill('=') << setw(41) << "=" << endl;

        for(unsigned u = 0; u < lista_PcD.size(); u++){
            if(!lista_PcD[u].getSituacao())
            {
                cout << endl << "Numero: " << lista_PcD[u].getNumero()
                << endl << "Andar: " << lista_PcD[u].getAndar() << endl << "Camas: " << lista_PcD[u].getCamas()
                << endl << "Capacidade: " << lista_PcD[u].getCapacidade() << endl << "Diaria: R$"
                << lista_PcD[u].getDiaria() << endl << "Tipo adaptacao: " << lista_PcD[u].getTipoAdaptacao() << endl
                << "Servicos especiais: " << lista_PcD[u].getServ() << " funcionarios" << endl;
                cout << setfill('-') << setw(41) << "-" << endl;
            }
        }
    }
}

// Exibir apenas os quartos ocupados.
void Hotel::printQuarOcupados() const
{
    if(lista_PcD.empty() && lista_quarto.empty() && lista_premium.empty()) // Verifica se há quartos no hotel
        cout << "Não há quartos no hotel!" << endl;
    else if(lista_reservas.empty()) // Verifica se a lista de reservas está vazia
        cout << "Não há quartos reservados" << endl;
    else
    {
        bool cont_1, cont_2;

        // Printa Quartos Padrão Ocupados
        cout << "Quarto Padrão" << endl;
        cout << setfill('=') << setw(41) << "=" << endl;

        for(unsigned u = 0; u < lista_quarto.size(); u++){
            if(lista_quarto[u].getSituacao())
            {
                cout << endl << "Numero: " << lista_quarto[u].getNumero()
                << endl << "Andar: " << lista_quarto[u].getAndar() << endl << "Camas: " << lista_quarto[u].getCamas()
                << endl << "Capacidade: " << lista_quarto[u].getCapacidade() << endl << "Diaria: R$"
                << lista_quarto[u].getDiaria() << endl;
                cout << setfill('-') << setw(41) << "-" << endl;

                cont_1 = false;
            }
        }

        if(!cont_1)
            system("pause");

        system("cls");

        // Printa Quartos Premium Ocupados
        cout << "Quarto Premium" << endl;
        cout << setfill('=') << setw(41) << "=" << endl;

        for(unsigned u = 0; u < lista_premium.size(); u++){
            if(lista_premium[u].getSituacao())
            {
                cout << endl << "Numero: " << lista_premium[u].getNumero()
                << endl << "Andar: " << lista_premium[u].getAndar() << endl << "Camas: " << lista_premium[u].getCamas()
                << endl << "Capacidade: " << lista_premium[u].getCapacidade() << endl << "Diaria: R$"
                << lista_premium[u].getDiaria() << endl << "Wifi: " << lista_premium[u].getWifi() << " mbps" << endl
                << "Chuveiro Eletricos: " << lista_premium[u].getChuvelet() << " chuveiros" << endl
                << "Ar Condicionado: " << lista_premium[u].getArcond() << " BTUs" << endl << "TV: "
                << lista_premium[u].getTv() << " polegadas" << endl << "Servico de quarto: "
                << lista_premium[u].getServico() << " funcionarios" << endl;
                cout << setfill('-') << setw(41) << "-" << endl;

                cont_2 = false;
            }
        }

        if(!cont_2)
            system("pause");

        system("cls");

        // Printa Quartos PcD Ocupados
        cout << "Quarto PcD" << endl;
        cout << setfill('=') << setw(41) << "=" << endl;

        for(unsigned u = 0; u < lista_PcD.size(); u++){
            if(lista_PcD[u].getSituacao())
            {
                cout << endl << "Numero: " << lista_PcD[u].getNumero()
                << endl << "Andar: " << lista_PcD[u].getAndar() << endl << "Camas: " << lista_PcD[u].getCamas()
                << endl << "Capacidade: " << lista_PcD[u].getCapacidade() << endl << "Diaria: R$"
                << lista_PcD[u].getDiaria() << endl << "Tipo adaptacao: " << lista_PcD[u].getTipoAdaptacao() << endl
                << "Servicos especiais: " << lista_PcD[u].getServ() << " funcionarios" << endl;
                cout << setfill('-') << setw(41) << "-" << endl;
            }
        }
    }
}

// Exibe as reservas
void Hotel::printReservas() const
{
    if(lista_reservas.empty()) // Verifica se a lista de reservas está vazia
        cout << "Lista esta vazia!" << endl;

    // Printa as reservas
    for(const auto& res : lista_reservas)
    {
        cout << "Numero da reserva: " << res.get_nmReserva()
        << endl << "Numero de acompanhantes: " << res.get_nmAc()
        << endl << "Numero do quarto: " << res.get_nmquarto()
        << endl << "Nome do cliente: " << res.get_nome()
        << endl << "Dias: " << res.getdias()
        << endl << "Tipo de Quarto: " << res.get_tipoQuarto()
        << endl << "Montante a ser pago: " << res.getmontante()<<"\n\n";
    }
}

//Pesquisa um dos quartos. //adicionar tipo do quarto a ser pesquisado!
bool Hotel::pesquisaQuarto(int numero) const
{
    // Pesquisa por quarto padrão e printa o quarto, se encontrado
    for(unsigned u = 0; u < lista_quarto.size(); u++){
        if(numero == lista_quarto[u].getNumero()){
            cout << "Quarto padrão" << endl << "Numero: " << lista_quarto[u].getNumero()
            << endl << "Andar: " << lista_quarto[u].getAndar() << endl << "Camas: " << lista_quarto[u].getCamas()
            << endl << "Capacidade: " << lista_quarto[u].getCapacidade() << endl << "Diaria: R$"
            << lista_quarto[u].getDiaria() << endl;

            if(lista_quarto[u].getSituacao())
                cout << "Situacao: ocupado" << endl << endl;

            else
                cout << "Situacao: desocupado" << endl << endl;

	        return true;
        }
    }

    // Pesquisa por quarto premium e printa o quarto, se encontrado
    for(unsigned u = 0; u < lista_premium.size(); u++){
        if(numero == lista_premium[u].getNumero()){
            cout << "Quarto premium" << endl << "Numero: " << lista_premium[u].getNumero()
            << endl << "Andar: " << lista_premium[u].getAndar() << endl << "Camas: " << lista_premium[u].getCamas()
            << endl << "Capacidade: " << lista_premium[u].getCapacidade() << endl << "Diaria: R$"
            << lista_premium[u].getDiaria() << endl << "Wifi: " << lista_premium[u].getWifi() << " mbps" << endl
            << "Chuveiro Eletricos: " << lista_premium[u].getChuvelet() << " chuveiros" << endl
            << "Ar Condicionado: " << lista_premium[u].getArcond() << " BTUs" << endl << "TV: "
            << lista_premium[u].getTv() << " polegadas" << endl << "Servico de quarto: "
            << lista_premium[u].getServico() << " funcionarios" << endl;

            if(lista_premium[u].getSituacao())
                cout << "Situacao: ocupado" << endl << endl;
            else
                cout << "Situacao: desocupado" << endl << endl;

	        return true;
        }

    }

    // Pesquisa por quarto pcd e printa o quarto, se encontrado
    for(unsigned u = 0; u < lista_PcD.size(); u++){
        if(numero == lista_PcD[u].getNumero())
        {
            cout << "Quarto PcD" << endl << "Numero: " << lista_PcD[u].getNumero()
            << endl << "Andar: " << lista_PcD[u].getAndar() << endl << "Camas: " << lista_PcD[u].getCamas()
            << endl << "Capacidade: " << lista_PcD[u].getCapacidade() << endl << "Diaria: R$"
            << lista_PcD[u].getDiaria() << endl << "Tipo adaptacao: " << lista_PcD[u].getTipoAdaptacao() << endl
            << "Servicos especiais: " << lista_PcD[u].getServ() << " funcionarios" << endl;

            if(lista_PcD[u].getSituacao())
                cout << "Situacao: ocupado" << endl << endl;
            else
                cout << "Situacao: desocupado" << endl << endl;

	        return true;
        }
    }

    cout << "Quarto nao encontrado!" << endl;

    return false;
}

// Retorna o ranking do hotel
float Hotel::getRanking() const
{
    return ranking / cont_avaliacoes;
}

// Retorna o numero de andares.
int Hotel::getAndares() const
{
    return quartos_andar.size();
}

// Retorna o contador de avaliações do hotel
int Hotel::get_contAva() const
{
    return cont_avaliacoes;
}

// Retornando o numero de pessoas.
int Hotel::getPessoas() const
{
    return pessoas;
}

// Retornando o numero maximo de quartos.
int Hotel::getMaxQuartos() const
{
    return maxQuartos_andares;
}

// Gravando as listas num arquivo.
void Hotel::gravaListas(){

    //Abre o arquivo dos quartos padrão para gravar dados nele
    ofstream arquivo("ListaQuartos.txt", ios::trunc);

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

    //Abre o arquivo dos quartos premium para gravar dados nele
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

    //Abre o arquivo dos quartos pcd para gravar dados nele
    ofstream arquivo3("ListaQuartosPcD.txt", ios::trunc);

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

    //Abre o arquivo das reservas para gravar dados nele
    ofstream arquivo4("ListaReservas.txt", ios::trunc);

    if(arquivo4.is_open())
    {
        for (const auto& reserva : lista_reservas)
        {
            arquivo4 << reserva.get_nome() << endl;
            arquivo4 << reserva.get_nmReserva() << endl;
            arquivo4 << reserva.get_nmAc() << endl;
            arquivo4 << reserva.get_nmquarto() << endl;
            arquivo4 << reserva.get_tipoQuarto() << endl;
            arquivo4 << reserva.getdias() << endl;
            arquivo4 << reserva.getmontante() << endl;

        }
        arquivo4.close();
    }

    //Abre o arquivo do Hotel para gravar dados nele
    ofstream arquivo_hotel("propHotel.txt");

    if(arquivo_hotel.is_open())
    {
        arquivo_hotel << this->cont_avaliacoes << endl;
        arquivo_hotel << this->maxQuartos_andares << endl;
        arquivo_hotel << this->pessoas << endl;
        arquivo_hotel << this->ranking << endl;

        for(unsigned u = 0; u < quartos_andar.size(); u++)
        {
            arquivo_hotel << quartos_andar[u];

            if(u < quartos_andar.size() - 1)
                arquivo_hotel << endl;
        }

    }
}

//Destrutor que ira chamar o metodo de gravar.
Hotel::~Hotel(){
    gravaListas();
}
