#include <iostream>
#include <locale.h>
#include <ostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include <locale>

using namespace std;

#include "quarto.cpp"
#include "QuartoPcD.cpp"
#include "quartopremium.cpp"
#include "reserva.cpp"
#include "hotel.cpp"

void menufunciomario();
void menucliente();

int main()
{
    setlocale(LC_ALL, "portuguese");
    Hotel hotel;

    if(!hotel.getAndares())
    {
        unsigned andares, maxQuartos_andares;

        cout << "Primeira vez aqui ?\nDefina as propriedades do hotel" << endl;
        cout << "Defina a quantidade de andares: ";

        cin >> andares; //fazer verificação
        cout << "\nDefina a quantidade máxima por andar: ";
        cin >> maxQuartos_andares; //fazer verificação
        hotel.setMaxQuartos(maxQuartos_andares);
        hotel.setAndares(andares);

    }

    cout << "\t\tBem-vindo" << endl;

    unsigned op;

    cout << "Entrar como:" << endl
        << "(1) Fumcionario" << endl
        << "(2) Cliente" << endl
        << ">> ";
    cin >> op;

    switch(op)
    {
        case 1:
        {
            string alo;
            cout << "Insira a senha: " << endl;
            cin.sync();
            cin >> alo;

            if(alo == "admin")
            {
                int op;

                menufunciomario();  
                cin >> op;        

                switch(op)
                {
                    case 0:
                        return 0;
                    case 1:
                    {
                        unsigned op = 0;

                        cout << "Escolha uma opcao" << endl
                             << "(1) adicioanr quarto padrão" << endl
                             << "(2) adicionar quarto premium" << endl
                             << "(3) adicionar quarto PcD" << endl
                             << ">> ";
                        cin >> op;

                        int andar, numero, camas, capacidade;
                        float diaria;

                        cout << "Digite o andar: ";
                        cin >> andar;

                        cout << "Digite o número: ";
                        cin >> numero;
                            
                        cout << "Digite a capacidade: ";
                        cin >> capacidade;

                        cout << "Digite a quantidade de camas: ";
                        cin >> camas;

                        cout << "Digite a diária: ";
                        cin >> diaria;

                        switch(op)
                        {
                            case 1:
                            {
                                Quarto quarto(andar, camas, capacidade, diaria, numero);
                                hotel.addQuarto(quarto);

                                break;
                            }
                            case 2:
                            {
                                int wifi, chuv, arcond, TV, servico;

                                cout << "Digite a velocidade wifi: ";
                                cin >> wifi;
                                cout << "Quantidade de chuveiros elétricos: ";
                                cin >> chuv;
                                cout << "Digite a potência do ar-condicionado: ";
                                cin >> arcond;
                                cout << "Digite a quantidade de polegadas da TV:  ";
                                cin >> TV;
                                cout << "Digite a quantidade de funcionários:  ";
                                cin >> servico;

                                QuartoPremium quarto_plus(andar, camas, capacidade, diaria, numero);

                                quarto_plus.setWifi(wifi);
                                quarto_plus.setChuvelet(chuv);
                                quarto_plus.setArcond(arcond);
                                quarto_plus.setTv(TV);
                                quarto_plus.setServico(servico);

                                if(!hotel.addPremium(quarto_plus))
                                    cout << "erro" << endl;

                                break;
                            }
                            case 3:
                            {
                                int qnt;
                                string tipo;

                                cout << "Digite o tipo de adaptação: ";
                                cin.sync();
                                getline(cin, tipo);
                                
                                cout << "Digite a quantidade de funcionários:  ";
                                cin >> qnt;

                                QuartoPcD quarto_pcd(andar, camas, capacidade, diaria, numero, tipo, qnt);

                                if(!hotel.addPcD(quarto_pcd))
                                    cout << "erro" << endl;

                                break;
                            }
                            default:
                                cout << "Opcao errada burro do caraloh" << endl;
                        }
                        break;
                    }
                    case 2:
                    {
                        int tipo, numero;

                        cout << "Digite o número do quarto: ";
                        cin >> numero;

                        cout << "Digite o tipo do quarto: "
                             << "(1) remover quarto padrão" << endl
                             << "(2) remover quarto premium" << endl
                             << "(3) remover quarto pcd" << endl;
                        cin >> tipo;

                        if (!hotel.rmv_quarto(numero, tipo))
                            cout << "Não foi possível encontrar o quarto!" << endl;

                        break;
                    }
                    case 3:
                    {
                        int numbiro;

                        cout << "Informe o número da reserva: " << endl;
                        cin >> numbiro;

                        if(!hotel.removerReserva(numbiro))
                            cout << "Erro!" << endl;

                        break;
                    }
                    case 4:
                    {
                        hotel.printQuartos();
                        break;
                    }
                    case 5:
                    {
                        hotel.printReservas();
                        break;
                    }
                    case 6:
                    {
                        int numbiro;

                        cout << "Digite o numero do quarto a ser qpesuiado: ";
                        cin >> numbiro;

                        hotel.pesquisaQuarto(numbiro);
                        break;
                    }
                }
            }
            break;
        }
        case 2:
        {
            cout << "cliente";
            menucliente();

        }
        default:
            cout << "Opcao errada burro do caralho";
    }

    return 0;
}

void menufunciomario()
{
    cout << "Menu fumcionario" << endl
        << "(1) adicionar quarto" << endl
        << "(2) remover quarto" << endl
        << "(3) remover reserva" << endl
        << "(4) printar lista de quartos" << endl
        << "(5) printar lista de reservas" << endl
        << "(6) pesquisar quarto" << endl
        << "(0) finalizar" << endl
        << ">> ";
}

void menucliente()
{
    cout << "Menum cliente";
}