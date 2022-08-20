#include "hotel.h"

//Construtor que ira ler o arquivo das listas.
Hotel::Hotel()
{
    int num, andar, camas, capacidade, wifi, chuveiro, serv, nm_acmp, nm_res;
    string nome,tipo,tipo_quarto;
    float diaria, arcond,TV;
    bool situacao;

    ifstream arquivo_hotel("propHotel.txt", ios::in);

    if(arquivo_hotel.is_open())
    {
        arquivo_hotel >> this->cont_avaliacoes;
        arquivo_hotel >> this->maxQuartos_andares;
        arquivo_hotel >> this->pessoas;
        arquivo_hotel >> this->ranking;

        while(!arquivo_hotel.eof())
        {
            arquivo_hotel >> andar;
            quartos_andar.emplace_back(andar);

        }
    }
    else
    {
        this->cont_avaliacoes = 0;
        this->maxQuartos_andares = 0;
        this->pessoas = 0;
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
        float montante = 0.0;
        int dias = 0;

        while(!arquivo4.eof())
        {
            getline(arquivo4, nome);

            if (arquivo4.eof())
                break;


            arquivo4 >> nm_res;
            arquivo4 >> nm_acmp;
            arquivo4 >> num;

            arquivo4.ignore();
            getline(arquivo4, tipo_quarto);

            arquivo4 >> dias;
            arquivo4 >> montante;
            arquivo4.ignore();

            Reserva reserva(nm_acmp, num, dias, nome, tipo_quarto);

            reserva.set_nmReserva(nm_res);
            reserva.set_montante(montante);
            lista_reservas.emplace_back(reserva);
        }
        arquivo4.close();
    }
}

// define a quantidade de andares/tamanho do vector dos quartos
void Hotel::setAndares(int& andares)
{
    quartos_andar.resize(andares);
}

//Setando o valor maximo de quartos.
void Hotel::setMaxQuartos(int maximo){
    maxQuartos_andares = maximo;
}

// Definicao de ranking.
void Hotel::defRanking(float valor)
{
    this->ranking += valor;
    ++cont_avaliacoes;
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

    if(q.getAndar() > quartos_andar.size()-1 || q.getAndar() < 0 || quartos_andar[q.getAndar()] == maxQuartos_andares)
        return false;

    lista_quarto.emplace_back(q);
    quartos_andar[q.getAndar()]++;

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

    if(q.getAndar() > quartos_andar.size()-1 || q.getAndar() < 0 || quartos_andar[q.getAndar()] == maxQuartos_andares)
        return false;

    lista_premium.emplace_back(q);
    quartos_andar[q.getAndar()]++;

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

    if(q.getAndar() > quartos_andar.size()-1 || q.getAndar() < 0 || quartos_andar[q.getAndar()] == maxQuartos_andares)
        return false;

    lista_PcD.emplace_back(q);
    quartos_andar[q.getAndar()]++;

    return true;
}

bool Hotel::verificaQuarto(int nm, int tipo)
{
    if(tipo == 1)
    {
        for(unsigned u = 0; u < lista_quarto.size(); u++)
            if(lista_quarto[u].getNumero() == nm)
            {
                if(lista_quarto[u].getSituacao())
                    return false;

                pesquisaQuarto(nm);
                return true;
            }
    }

    else if(tipo == 2)
    {
        for(unsigned u = 0; u < lista_premium.size(); u++)
            if(lista_premium[u].getNumero() == nm)
            {
                if(lista_premium[u].getSituacao())
                    return false;

                pesquisaQuarto(nm);
                return true;
            }
    }

    else if(tipo == 3)
    {
        for(unsigned u = 0; u < lista_PcD.size(); u++)
            if(lista_PcD[u].getNumero() == nm)
            {
                if(lista_PcD[u].getSituacao())
                    return false;

                pesquisaQuarto(nm);
                return true;
            }
    }

    return false;
}

bool Hotel::modificaQuarto(int nm, int atrib)
{
    switch(atrib)
    {
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
    switch(atrib)
    {
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
    switch(atrib)
    {
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

bool Hotel::rmv_quarto(const int& num_quarto, int tipo)
{
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

bool Hotel::addReserva(Reserva& r)
{
    int nm_res = 66666 + (rand() % 6666) + (rand() % 6666);

    while(1)
    {
        bool aux = false;

        for(const auto& reserva : lista_reservas)
        {
            if(r.get_nmquarto() == reserva.get_nmquarto())
                return false;

            if (nm_res == reserva.get_nmReserva())
            {
                while(nm_res == reserva.get_nmReserva())
                    nm_res = 66666 + (rand() % 6666) + (rand() % 6666);
                aux = true;
            }
        }
        if(!aux)
            break;
    }
    r.set_nmReserva(nm_res);

    // mudando a situação do quarto
    if(r.get_tipoQuarto() == "Quarto")
    {
        for(unsigned u = 0; u < lista_quarto.size(); u++){
            if(lista_quarto[u].getNumero() == r.get_nmquarto())
            {
                if(r.get_nmAc() > lista_quarto[u].getCapacidade())
                    return false;

                lista_quarto[u].setSituacao(true);

                r.set_montante(r.getdias() * lista_quarto[u].getDiaria());
                lista_reservas.emplace_back(r);

                this->pessoas += r.get_nmAc();

                return true;
            }
        }
    }
    else if(r.get_tipoQuarto() == "Quarto Premium")
    {
        for(unsigned u = 0; u < lista_premium.size(); u++){
            if(lista_premium[u].getNumero() == r.get_nmquarto())
            {
                if(r.get_nmAc() > lista_premium[u].getCapacidade())
                    return false;

                lista_premium[u].setSituacao(true);

                r.set_montante(r.getdias() * lista_premium[u].getDiaria());
                lista_reservas.emplace_back(r);

                this->pessoas += r.get_nmAc();

                return true;
            }
        }
    }
    else
    {
        for(unsigned u = 0; u < lista_PcD.size(); u++){
            if(lista_PcD[u].getNumero() == r.get_nmquarto())
            {
                if(r.get_nmAc() > lista_PcD[u].getCapacidade())
                    return false;

                lista_PcD[u].setSituacao(true);

                r.set_montante(r.getdias() * lista_premium[u].getDiaria());
                lista_reservas.emplace_back(r);

                this->pessoas += r.get_nmAc();

                return true;
            }
        }
    }
    return false;
}

float Hotel::pesquisaMontante(int nm_reserva)
{
    for(unsigned u = 0; u < lista_reservas.size(); u++)
        if(nm_reserva == lista_reservas[u].get_nmReserva())
            return lista_reservas[u].getmontante();

    return 0.0;
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

            pessoas -= lista_reservas[i].get_nmAc();

            lista_reservas.erase(lista_reservas.begin() + i);

            if (tipo_quarto == "Quarto")
            {
                for (unsigned u = 0; u < lista_quarto.size(); ++u)
                {
                    if (numero_quarto == lista_quarto[u].getNumero())
                    {
                        lista_quarto[u].setSituacao(false);
                        return true;
                    }
                }
            }
            else if (tipo_quarto == "Quarto Premium")
            {
                for (unsigned u = 0; u < lista_premium.size(); ++u)
                {
                    if (numero_quarto == lista_premium[u].getNumero())
                    {
                        lista_premium[u].setSituacao(false);
                        return true;
                    }
                }
            }
            else
            {
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
    if(lista_PcD.empty() && lista_quarto.empty() && lista_premium.empty())
        cout << "Não há quartos no hotel!" << endl;
    else if(lista_PcD.size() + lista_quarto.size() + lista_premium.size() == lista_reservas.size())
        cout << "Não há quartos disponíveis" << endl;
    else
    {
        bool cont_1 = true, cont_2 = true;

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
    if(lista_PcD.empty() && lista_quarto.empty() && lista_premium.empty())
        cout << "Não há quartos no hotel!" << endl;
    else if(lista_reservas.empty())
        cout << "Não há quartos reservados" << endl;
    else
    {
        bool cont_1, cont_2;

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

void Hotel::printReservas() const
{
    if(lista_reservas.empty())
        cout << "Lista esta vazia!" << endl;

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

float Hotel::getRanking() const
{
    return ranking / cont_avaliacoes;
}

//Retorna o numero de andares.
int Hotel::getAndares() const
{
    return quartos_andar.size();
}

int Hotel::get_contAva() const
{
    return cont_avaliacoes;
}

//Retornando o numero de pessoas.
int Hotel::getPessoas() const
{
    return pessoas;
}

//Retornando o numero maximo de quartos.
int Hotel::getMaxQuartos() const
{
    return maxQuartos_andares;
}

//Gravando as listas num arquivo.
void Hotel::gravaListas(){

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
