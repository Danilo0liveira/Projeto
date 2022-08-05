#include <iostream>
#include <string>

using namespace std;

#include "quarto.cpp"
#include "QuartoPcD.cpp"

int main()
{
    QuartoPcD quarto_pcd1(1, 2, 4, 8.9, 123, "teste", 5);

    // quarto_pcd1.setTipoAdaptacao("teste");
    // quarto_pcd1.setServicoEspecial(5);
    quarto_pcd1.setSituacao(true);

    cout << "Segue as atribuicoes realizadas da maneira correta" << endl;
    cout << "Andar: " << quarto_pcd1.getAndar() << endl;
    cout << "Camas: " << quarto_pcd1.getCamas() << endl;
    cout << "Capacidade: " << quarto_pcd1.getCapacidade() << endl;
    cout << "Diaria: " << quarto_pcd1.getDiaria() << endl;
    cout << "Numero: " << quarto_pcd1.getNumero() << endl;
    cout << "Tipo de adaptacao: " << quarto_pcd1.getTipoAdaptacao() << endl;
    cout << "Servico especial: " << quarto_pcd1.getServ() << endl;
    cout << "Situacao: " << quarto_pcd1.getSituacao() << endl;
    
    return 0;
}
