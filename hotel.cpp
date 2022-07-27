#include "hotel.h"
Hotel::Hotel(){
    int num, andar, camas, capacidade, wifi, chuveiro, arcond, TV, serv, acompanhantes, numReserva;
    string tipo, nome;
    float diaria;
    bool situacao;

    ifstream arquivo;
    arquivo.open("ListaQuartos.txt", ios::in);

    if(arquivo.is_open()){
        while(!arquivo.eof()){

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
        }

        arquivo.close();
    }

    ifstream arquivo2;
    arquivo2.open("ListaQuartosPremium.txt", ios::in);

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

            QuartoPremium aux(andar, camas, capacidade, diaria, numero);
            aux.setWifi(wifi);
            aux.setC_El(chuveiro);
            aux.setAR_CND(arcond);
            aux.setTV(TV);
            aux.setServico(serv);
            aux.setSituacao(situacao);
        }

        arquivo2.close();
    }

    ifstream arquivo3;
    arquivo3.open("ListaQuartosPcD.txt", ios::in);

    if(arquivo3.is_open()){
        while(!arquivo3.eof()){

            arquivo3 >> num;

            if (arquivo.eof())
				break;

            arquivo3 >> andar;
            arquivo3 >> camas;
            arquivo3 >> capacidade;
            arquivo3 >> diaria;
            arquivo3 >> situacao;
            arquivo3.ignore();
            getline(arquivo3, tipo);
            arquivo3.ignore();
            arquivo3 >> serv;

            QuartoPcD aux(num, andar, camas, capacidade, diaria, tipo, serv);
            aux.setSituacao(situacao);
        }

        arquivo3.close();
    }

    ifstream arquivo4;
    arquivo4.open("ListaReservas.txt", ios::in);

    if(arquivo4.is_open()){
        while(!arquivo4.eof()){

            arquivo4 << numReserva;
            arquivo4.ignore();
            getline(arquivo4, nome);
            arquivo4.ignore();
            arquivo4 << acompanhantes;
            arquivo4 << num;

            Reserva aux();
        }

        arquivo4.close();
    }

}

bool Hotel::addQuarto(Quarto q){
    for(unsigned u = 0; u < lista_quarto.size(); u++)
            if(q.getNumero() == lista_quarto[u].getNumero)
                return false;

    if(contador == maxQuartos){
        return false;
    }

    else{
        if(q.getAndar() > getAndares() || q.getAndar() < getAndares())
            return false;

        else{
            lista_quartos.emplace_back(q);

            contador++;

            return true;
        }
    }
}

bool Hotel::addPremium(QuartoPremium q){
    for(unsigned u = 0; u < lista_premium.size(); u++)
            if(q.getNumero() == lista_premium[u].getNumero)
                return false;

    if(contador == maxQuartos){
        return false;
    }

    else{
        if(q.getAndar() > getAndares() || q.getAndar() < getAndares())
            return false;

        else{
            lista_premium.emplace_back(q);

            contador++;

            return true;
        }
    }
}

bool Hotel::addPcD(QuartoPcD q){
    for(unsigned u = 0; u < lista_PcD.size(); u++)
            if(q.getNumero() == lista_PcD[u].getNumero)
                return false;

    if(contador == maxQuartos){
        return false;
    }

    else{
        if(q.getAndar() > getAndares() || q.getAndar() < getAndares())
            return false;

        else{
            lista_PcD.emplace_back(q);

            contador++;

            return true;
        }
    }
}

bool Hotel::addReserva(Reserva r){
    for(unsigned u = 0; u < lista_reservas.size(); u++)
        if(r.get_nmquarto() == lista_reservas[u].get_nmquarto())
            return false;

    lista_reservas.emplace_back(r);

    for(unsigned u = 0; u < lista_quarto.size; u++){
        if(lista_quarto[u].getNumero() == r.get_nmquarto())
            lista_quarto[u].setSituacao(true);
    }

    for(unsigned u = 0; u < lista_premium.size; u++){
        if(lista_premium[u].getNumero() == r.get_nmquarto())
            lista_premium[u].setSituacao(true);
    }

    for(unsigned u = 0; u < lista_PcD.size; u++){
        if(lista_PcD[u].getNumero() == r.get_nmquarto())
            lista_PcD[u].setSituacao(true);
    }

}

bool Hotel::cancelaReserva(int n){
    for(unsigned u = 0; u < lista_reservas.size(); u++){
        if(n == lista_reservas[u].get_numReserva()){
            for(unsigned u = 0; u < lista_quarto.size; u++){
                if(lista_quarto[u].getNumero() == lista_reservas[u].get_nmquarto())
                    lista_quarto[u].setSituacao(false);
            }

            for(unsigned u = 0; u < lista_premium.size; u++){
                if(lista_premium[u].getNumero() == r.get_nmquarto())
                    lista_premium[u].setSituacao(false);
            }

            for(unsigned u = 0; u < lista_PcD.size; u++){
                if(lista_PcD[u].getNumero() == r.get_nmquarto())
                    lista_PcD[u].setSituacao(false);
            }

            lista_reservas.erase(lista_reservas.begin + u);

            return true;
        }
    }
    return false;
}

void Hotel::setAndares(int a){
    andares = a;
}

void Hotel::defRanking(){

}

void Hotel::printQuartos(){
    if(contador == 0)
        cout << "Nao ha quartos no hotel!" << endl;

    else{
        for(unsigned u = 0; u < lista_quarto.size(); u++){
            cout << "Quartos padroes: "<< endl << "Numero: " << lista_quarto[u].getNumero()
            << endl << "Andar: " << lista_quarto[u].getAndar() << endl << "Camas: " << lista_quarto[u].getCamas()
            << endl << "Capacidade: " << lista_quarto[u].getCapacidade() << endl << "Diaria: "
            << lista_quarto[u].getDiaria() << endl;

            if(lista_quarto[u].getSituacao == true)
                cout << "Situacao: ocupado" << endl << endl;

            else
                cout << "Situacao: desocupado" << endl << endl;
        }

        for(unsigned u = 0; u < lista_premium.size(); u++){
            cout << "Quartos premium: "<< endl << "Numero: " << lista_premium[u].getNumero()
            << endl << "Andar: " << lista_premium[u].getAndar() << endl << "Camas: " << lista_premium[u].getCamas()
            << endl << "Capacidade: " << lista_premium[u].getCapacidade() << endl << "Diaria: "
            << lista_premium[u].getDiaria() << endl << "Wifi: " << lista_premium[u].getWifi() << " mbps" << endl
            << "Chuveiro Eletricos: " << lista_premium[u].getChuveiroeletrico() << " chuveiros" << endl
            << "Ar Condicionado: " << lista_premium[u].getArcondicionado << " BTUs" << endl << "TV: "
            << lista_PcD[u].getTV() << " polegadas" << endl << "Servico de quarto: "
            << lista_premium[u].getServicosdequarto() << " funcionarios" << endl;

            if(lista_PcD[u].getSituacao == true)
                cout << "Situacao: ocupado" << endl << endl;

            else
                cout << "Situacao: desocupado" << endl << endl;
        }

        for(unsigned u = 0; u < lista_PcD.size(); u++){
            cout << "Quartos padroes: "<< endl << "Numero: " << lista_PcD[u].getNumero()
            << endl << "Andar: " << lista_PcD[u].getAndar() << endl << "Camas: " << lista_PcD[u].getCamas()
            << endl << "Capacidade: " << lista_PcD[u].getCapacidade() << endl << "Diaria: "
            << lista_PcD[u].getDiaria() << endl << "Tipo adaptacao: " << lista_PcD[u].getTipo() << endl
            << "Servicos especiais: " << lista_PcD[u].getServ() << " funcionarios" << endl;

            if(lista_PcD[u].getSituacao == true)
                cout << "Situacao: ocupado" << endl << endl;

            else
                cout << "Situacao: desocupado" << endl << endl;
        }
    }
}

void Hotel::printQuarDesocupados(){
    if(contador == 0)
        cout << "Nao ha quartos no hotel!" << endl;

    else{

        for(unsigned u = 0; u < lista_quarto.size(); u++){
            if(lista_quarto[u].getSituacao() == false){
                cout << "Quartos padroes: "<< endl << "Numero: " << lista_quarto[u].getNumero()
                << endl << "Andar: " << lista_quarto[u].getAndar() << endl << "Camas: " << lista_quarto[u].getCamas()
                << endl << "Capacidade: " << lista_quarto[u].getCapacidade() << endl << "Diaria: "
                << lista_quarto[u].getDiaria() << endl << endl;
            }
        }

        for(unsigned u = 0; u < lista_premium.size(); u++){
            if(lista_premium[u].getSituacao() == false){
                cout << "Quartos premium: "<< endl << "Numero: " << lista_premium[u].getNumero()
                << endl << "Andar: " << lista_premium[u].getAndar() << endl << "Camas: " << lista_premium[u].getCamas()
                << endl << "Capacidade: " << lista_premium[u].getCapacidade() << endl << "Diaria: "
                << lista_premium[u].getDiaria() << endl << "Wifi: " << lista_premium[u].getWifi() << " mbps" << endl
                << "Chuveiro Eletricos: " << lista_premium[u].getChuveiroeletrico() << " chuveiros" << endl
                << "Ar Condicionado: " << lista_premium[u].getArcondicionado() << " BTUs" << endl << "TV: "
                << lista_premium[u].getTV() << " polegadas" << endl << "Servico de quarto: "
                << lista_premium[u].getServicosdequarto() << " funcionarios" << endl;
            }
        }

        for(unsigned u = 0; u < lista_PcD.size(); u++){
            if(lista_PcD[u].getSituacao() == false){
                cout << "Quartos padroes: "<< endl << "Numero: " << lista_PcD[u].getNumero()
                << endl << "Andar: " << lista_PcD[u].getAndar() << endl << "Camas: " << lista_PcD[u].getCamas()
                << endl << "Capacidade: " << lista_PcD[u].getCapacidade() << endl << "Diaria: "
                << lista_PcD[u].getDiaria() << endl << "Tipo adaptacao: " << lista_PcD[u].getTipo() << endl
                << "Servicos especiais: " << lista_PcD[u].getServ() << " funcionarios" << endl;
            }
        }
    }
}

void Hotel::pesquisaQuarto(int numero){
    for(unsigned u = 0; u < lista_quarto.size(); u++){
        if(numero == lista_quarto[u].getNumero()){
            cout << "Numero: " << lista_quarto[u].getNumero()
            << endl << "Andar: " << lista_quarto[u].getAndar() << endl << "Camas: " << lista_quarto[u].getCamas()
            << endl << "Capacidade: " << lista_quarto[u].getCapacidade() << endl << "Diaria: "
            << lista_quarto[u].getDiaria() << endl;

            if(lista_quarto[u].getSituacao == true)
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
            << "Chuveiro Eletricos: " << lista_premium[u].getChuveiroeletrico() << " chuveiros" << endl
            << "Ar Condicionado: " << lista_premium[u].getArcondicionado << " BTUs" << endl << "TV: "
            << lista_PcD[u].getTV() << " polegadas" << endl << "Servico de quarto: "
            << lista_premium[u].getServicosdequarto() << " funcionarios" << endl;

            if(lista_PcD[u].getSituacao == true)
                cout << "Situacao: ocupado" << endl << endl;

            else
                cout << "Situacao: desocupado" << endl << endl;
        }

    }

    for(unsigned u = 0; u < lista_PcD.size(); u++){
        if(numero == lista_PcD[u].getNumero()){
            cout << "Quartos padroes: "<< endl << "Numero: " << lista_PcD[u].getNumero()
            << endl << "Andar: " << lista_PcD[u].getAndar() << endl << "Camas: " << lista_PcD[u].getCamas()
            << endl << "Capacidade: " << lista_PcD[u].getCapacidade() << endl << "Diaria: "
            << lista_PcD[u].getDiaria() << endl << "Tipo adaptacao: " << lista_PcD[u].getTipo() << endl
            << "Servicos especiais: " << lista_PcD[u].getServ() << " funcionarios" << endl;

            if(lista_PcD[u].getSituacao == true)
                cout << "Situacao: ocupado" << endl << endl;

            else
                cout << "Situacao: desocupado" << endl << endl;
        }
    }
}

int Hotel::getRanking(){
    return ranking;
}

int Hotel::getAndares(){
    return andares;
}

void Hotel::setMaxQuartos(int maximo){
    maxQuartos = maximo;
}

void Hotel::defPessoas(){
    for(unsigned u = 0; u < lista_reservas.size(); u++)
        pessoas = pessoas + lista_reservas[u].getAcompanhantes();
}

int Hotel::getPessoas(){
    return pessoas;
}

int Hotel::getMaxQuartos(){
    return maxQuartos;
}

int getContador(){
    return contador;
}

void Hotel::gravaListas(){

    ofstream arquivo;
    arquivo.open("ListaQuartos.txt", ios::trunc);

    if(arquivo.is_open()){
        for(unsigned u; u < lista_quarto.size(); u++){
            arquivo << lista_quarto.[u].getNumero() << endl;
            arquivo << lista_quarto.[u].getAndar() << endl;
            arquivo << lista_quarto.[u].getCamas() << endl;
            arquivo << lista_quarto.[u].getCapacidade() << endl;
            arquivo << lista_quarto.[u].getDiaria() << endl;
            arquivo << lista_quarto.[u].getSituacao() << endl;
        }
        arquivo.close();
    }

    else
		cout<<"Nao foi possivel abrir o arquivo"<<endl;

    ofstream arquivo2;
    arquivo.open("ListaQuartosPremium.txt", ios::trunc);

    if(arquivo2.is_open()){
        for(unsigned u; u < lista_premium.size(); u++){
            arquivo2 << lista_premium.[u].getNumero() << endl;
            arquivo2 << lista_premium.[u].getAndar() << endl;
            arquivo2 << lista_premium.[u].getCamas() << endl;
            arquivo2 << lista_premium.[u].getCapacidade() << endl;
            arquivo2 << lista_premium.[u].getDiaria() << endl;
            arquivo2 << lista_premium.[u].getSituacao() << endl;
            arquivo2 << lista_premium.[u].getWifi() << endl;
            arquivo2 << lista_premium.[u].getChuveiroeletrico() << endl;
            arquivo2 << lista_premium.[u].getArcondicionado() << endl;
            arquivo2 << lista_premium.[u].getTV() << endl;
            arquivo2 << lista_premium.[u].getServicodequarto() << endl;
        }
        arquivo2.close();
    }

    else
		cout<<"Nao foi possivel abrir o arquivo"<<endl;

    ofstream arquivo3;
    arquivo.open("ListaQuartosPcD.txt", ios::trunc);

    if(arquivo3.is_open()){
        for(unsigned u; u < lista_PcD.size(); u++){
            arquivo3 << lista_PcD.[u].getNumero() << endl;
            arquivo3 << lista_PcD.[u].getAndar() << endl;
            arquivo3 << lista_PcD.[u].getCamas() << endl;
            arquivo3 << lista_PcD.[u].getCapacidade() << endl;
            arquivo3 << lista_PcD.[u].getDiaria() << endl;
            arquivo3 << lista_PcD.[u].getSituacao() << endl;
            arquivo3 << lista_PcD.[u].getTipo() << endl;
            arquivo3 << lista_PcD.[u].getServ() << endl;
        }
        arquivo3.close();
    }

    else
		cout<<"Nao foi possivel abrir o arquivo"<<endl;

    ofstream arquivo4;
    arquivo4.open("ListaReservas.txt", ios::trunc);

    if(arquivo4.is_open()){
        for(unsigned u; u < lista_reservas.size(); u++){
            arquivo4 << lista_reservas.[u].get_nmReserva() << endl;
            arquivo4 << lista_reservas.[u].get_nome() << endl;
            arquivo4 << lista_reservas.[u].getAcompanhantes() << endl;
            arquivo4 << lista_reservas.[u].get_nmquarto() << endl;
        }
        arquivo4.close();
    }

    else
		cout<<"Nao foi possivel abrir o arquivo"<<endl;

}

Hotel::~Hotel(){
    gravaListas();
}
