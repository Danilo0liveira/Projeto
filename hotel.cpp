#include "hotel.h"
Hotel::Hotel(){
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
    for(unsigned u = 0; u < lista_reservas.size(); u++){
            if(r.get_numReserva() == lista_reservas[u].get_numReserva())
                return false;

            else if(r.get_nmquarto() == lista_reservas[u].get_nmquarto())
                return false;
    }

    lista_reservas.emplace_back(r);
}

bool Hotel::cancelaReserva(int n){
    for(unsigned u = 0; u < lista_reservas.size(); u++){
        if(n == lista_reservas[u].get_numReserva()){
            lista_reservas.erase(lista_reservas.begin + u);

            return true;
        }

        else
            return false;
    }
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

Hotel::~Hotel(){
}
