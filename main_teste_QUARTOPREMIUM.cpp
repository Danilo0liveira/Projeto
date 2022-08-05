#include <iostream>
#include <string>

using namespace std;

#include "quarto.cpp"
#include "quartopremium.cpp"

//verificação da funcionalidade dos métodos da classe 'QuartoPremium'

int main()
{
    //criação do objeto 'quarto_plus' do tipo 'QuartoPremium'
    QuartoPremium quarto_plus(1,2,3,4.5,5);

    // métodos sets para os atributos pertecentes ao private da classe
    quarto_plus.setArcond(3);
    quarto_plus.setChuvelet(5);
    quarto_plus.setServico(33);
    quarto_plus.setTv(39);
    quarto_plus.setWifi(5);
    quarto_plus.setSituacao(1);

    // Mostra ao usuário as atribuições realizada anteriormente
    cout << "Segue as atribuicoes realizadas da maneira correta" << endl;
    cout << "Andar: " << quarto_plus.getAndar() << endl;
    cout << "Camas: " << quarto_plus.getCamas() << endl;
    cout << "Capacidade: " << quarto_plus.getCapacidade() << endl;
    cout << "Diaria: " << quarto_plus.getDiaria() << endl;
    cout << "Numero : " << quarto_plus.getNumero() << endl;
    cout << "Ar condicionado: " << quarto_plus.getArcond() << endl;
    cout << "Chuveiro eletrico: " << quarto_plus.getChuvelet() << endl;
    cout << "Servico: " << quarto_plus.getServico() << endl;
    cout << "Tv: " << quarto_plus.getTv() << endl;
    cout << "Wifi: " << quarto_plus.getWifi() << endl;
    cout << "Situacao: " << quarto_plus.getSituacao() << endl;
} 