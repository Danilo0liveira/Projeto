#include <iostream>//Incluindo as bibliotecas na nossa main.
#include <locale.h>
#include <ostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include <clocale>

using namespace std;

#include "quarto.cpp"//Incluindo as classes utilizadas para o programa.
#include "QuartoPcD.cpp"
#include "quartopremium.cpp"
#include "reserva.cpp"
#include "hotel.cpp"

void menufuncionario();//Protótipo das funções utilizadas na main.
void menucliente();

int main()
{
    setlocale(LC_ALL, "portuguese");//Para utilizar a linguagem de português.
    Hotel hotel;

    if(!hotel.getAndares())//Verificação inicial se o hotel ja foi criado anteriormente ou não.
    {
        unsigned andares, maxQuartos_andares;//Criadas variáveis para armazenar valores do hotel.

        cout << "Primeira vez aqui ?\nDefina as propriedades do hotel" << endl;
        cout << "Defina a quantidade de andares: ";
        
        //Definindo valores para andares e o numero maximo de quartos por andar.
        while(1)
        {
            cout << "Defina a quantidade de andares: ";
            cin >> andares;

            if(andares >= 0)
                break;

            cout << "Numero inválido" << endl;
        }
        
        while(1)
        {
            cout << "\nDefina a quantidade máxima de quartos por andar: ";
            cin >> maxQuartos_andares;

            if(maxQuartos_andares >= 0)
                break;

            cout << "Numero inválido" << endl;
        }

        hotel.setMaxQuartos(maxQuartos_andares);
        hotel.setAndares(andares);//Setando os valores adquiridos no hotel.

    }

    cout << "\t\tBem-vindo" << endl;//Inicio em si do programa.

    unsigned op;

   while(1)
   {
        cout << "Entrar como:" << endl//Login para escolher qual o usuário, funcionário ou cliente?
            << "(1) Funcionário" << endl
            << "(2) Cliente" << endl
            << "(0) Sair" << endl
            << ">> ";
        cin >> op;

        switch(op)
        {
            case 0:
                return 0;

            // menu funcionário
            case 1:
            {
                while(1)
                {

                    string alo;
                    cout << "Insira a senha: " << endl;//Verificação da senha.
                    cin.sync();
                    cin >> alo;

                    if(alo != "admin")
                        cout << "Senha incorreta\n" << endl;

                    else
                    {
                        while(1)
                        {

                            unsigned op;

                            menufuncionario();//Chamamento da funcao menu funcionário com suas opções.
                            cin >> op;

                            switch(op)
                            {
                                case 0://Realiza a saida do programa.
                                    return 0;
                                case 1://Adiciona quartos no hotel.
                                {
                                    unsigned op = 0;

                                    cout << "Escolha uma opcao" << endl
                                        << "(1) adicionar quarto padrão" << endl
                                        << "(2) adicionar quarto premium" << endl
                                        << "(3) adicionar quarto PcD" << endl
                                        << ">> ";
                                    cin >> op;

                                    if(op < 1 || op > 3)
                                    {
                                        cout << "Opcao invalida" << endl;
                                        break;
                                    }

                                    int andar, numero, camas, capacidade;
                                    float diaria;

                                    while(1)//Recebendo variáveis comuns aos tres tipos de quartos.
                                    {
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

                                        if(andar > 0 && numero > 0 && capacidade > 0 && camas > 0 && diaria > 0)
                                            break;

                                        cout << "Dado(s) inválido(s), informe novamente!" << endl;
                                    }

                                    switch(op)
                                    {
                                        case 1://Adicionando quarto simples.
                                        {
                                            Quarto quarto(andar, camas, capacidade, diaria, numero);
                                            if(!hotel.addQuarto(quarto))
                                            {
                                                cout << "Nao foi possivel adicionar o quarto" << endl;
                                                break;
                                            }

                                            cout << "Sucesso!" << endl;

                                            break;
                                        }
                                        case 2://Adicionando quarto premium.
                                        {
                                            int wifi, chuv, arcond, TV, servico;

                                            while(1)
                                            {

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

                                                if(wifi > 0 && chuv > 0 && arcond > 0 && TV > 0 && servico > 0)
                                                    break;

                                                cout << "Dado(s) inválido(s), informe novamente!" << endl;
                                            }


                                            QuartoPremium quarto_plus(andar, camas, capacidade, diaria, numero);

                                            quarto_plus.setWifi(wifi);
                                            quarto_plus.setChuvelet(chuv);
                                            quarto_plus.setArcond(arcond);
                                            quarto_plus.setTv(TV);
                                            quarto_plus.setServico(servico);

                                            if(!hotel.addPremium(quarto_plus))
                                            {
                                                cout << "Nao foi possivel adicionar o quarto" << endl;
                                                break;
                                            }

                                            cout << "Sucesso!" << endl;

                                            break;
                                        }
                                        case 3://Adicionando o quarto PcD.
                                        {
                                            int qnt;
                                            string tipo;

                                            cout << "Digite o tipo de adaptação: ";
                                            cin.sync();
                                            getline(cin, tipo);

                                            while(1)
                                            {
                                                cout << "Digite a quantidade de funcionários:  ";
                                                cin >> qnt;

                                                if(qnt > 0)
                                                    break;

                                                cout << "Dado(s) inválido(s), informe novamente!" << endl;
                                            }

                                            QuartoPcD quarto_pcd(andar, camas, capacidade, diaria, numero, tipo, qnt);

                                            if(!hotel.addPcD(quarto_pcd))
                                            {
                                                cout << "Nao foi possivel adicionar o quarto" << endl;
                                                break;
                                            }
                                            cout << "Sucesso!" << endl;

                                            break;
                                        }
                                    }
                                    break;
                                }
                                case 2://Remoção de quartos.
                                {
                                    int tipo, numero;

                                    cout << "Digite o número do quarto: ";
                                    cin >> numero;

                                    cout << "Digite o tipo do quarto: " << endl
                                        << "(1) remover quarto padrão" << endl
                                        << "(2) remover quarto premium" << endl
                                        << "(3) remover quarto pcd" << endl;
                                    cin >> tipo;

                                    if(tipo < 1 || tipo > 3)
                                    {
                                        cout << "Opcao invalida" << endl;
                                        break;
                                    }


                                    if (!hotel.rmv_quarto(numero, tipo))
                                    {
                                        cout << "Não foi possível encontrar o quarto!" << endl;
                                        break;
                                    }

                                    cout << "Sucesso!" << endl;
                                    break;
                                }
                                case 3://Removendo uma das reservas.
                                {
                                    int numero;

                                    cout << "Informe o número da reserva: " << endl;
                                    cin >> numero;

                                    if(!hotel.removerReserva(numero))
                                    {
                                        cout << "Não foi possível encontrar a reserva!" << endl;
                                        break;
                                    }

                                    cout << "Sucesso!" << endl;
                                    break;
                                }
                                case 4://Exibindo todos os quartos.
                                {
                                    hotel.printQuartos();
                                    break;
                                }
                                case 5://Exibindo todas as reservas.
                                {
                                    hotel.printReservas();
                                    break;
                                }
                                case 6://Pesquisando um quarto.
                                {
                                    int numero;

                                    cout << "Digite o numero do quarto a ser pesquisado: ";
                                    cin >> numero;

                                    hotel.pesquisaQuarto(numero);
                                    break;
                                }
                                default:
                                    cout << "Opção inválida" << endl;
                            }
                        }
                    }
                }
                break;
            }
            // menu cliente
            case 2:
            {

                while (1)
                {
                    unsigned op;

                    menucliente();

                    cin >> op;

                    switch (op)
                    {
                    case 0:
                        return 0;

                    case 1: // Fazer reserva
                    {
                        // cria e pega o valor de variáveis p/ reserva
                        int acompanhantes, num_quarto, dias;
                        string nome, tipo_quarto;
                        
                        cout << "Digite o número de acompanhantes: ";
                        cin >> acompanhantes;
                        
                        cout << "Digite o número do quarto: ";
                        cin >> num_quarto;
                        
                        cout << "Digite o número de dias: ";
                        cin >> dias;
                        
                        cout << "Digite o seu nome: ";
                        getline(cin >> ws, nome);
                        
                        cout << "Digite o tipo de quarto: ";
                        getline(cin >> ws, tipo_quarto);

                        // cria o objeto Reserva
                        Reserva reserva(acompanhantes, num_quarto, dias, nome, tipo_quarto);

                        // adiciona a reserva ao hotel
                        if(hotel.addReserva(reserva)){
                            cout << "Reserva feita com sucesso!" << endl
                                << "O número da sua reserva é " << reserva.get_nmReserva() << endl ;
                            break;
                        }
                        cout << "Reserva não realizada." << endl;
                        break;
                    }
                    case 2: // Check out 
                    {
                        int num_quarto;
                        float avaliacao = -1; // inicializando avaliacao

                        // Pega o número do quarto
                        cout << "Digite o número da reserva: " << endl;
                        cin >> num_quarto;

                        // Remove a reserva, se encontrada no sistema
                        if(!hotel.removerReserva(num_quarto))
                        {
                            cout << "A reserva não foi encontrada." << endl;
                            break;
                        }

                        // Avaliação do hotel pelo cliente
                        cout << "Antes de ir, poderia deixar uma avaliação de 0 a 5 para o hotel?" << endl
                            << "Sendo 0 - Muito Ruim e 5 - Muito bom " << endl;
                            
                            while ((avaliacao < 0 || avaliacao > 5))
                            {
                            cout << ">> ";
                            cin >> avaliacao;
                            }

                        // Altera o ranking do hotel
                        hotel.defRanking(avaliacao);
                            

                        cout << "Check out realizado com sucesso!" << endl 
                            << "Obrigado, volte sempre!" << endl;
                        break;
                    }
                    case 3: // Cancelar reserva
                    {   
                        int num_quarto;

                        // Pega o número do quarto
                        cout << "Digite o número da reserva: " << endl;
                        cin >> num_quarto;

                        if(!hotel.removerReserva(num_quarto))
                        {
                            cout << "A reserva não foi encontrada." << endl;
                            break;
                        }

                        cout << "Reserva cancelada com sucesso!" << endl;
                        break;
                    }
                    case 4: // Printar lista de quartos desocupados
                    {
                        hotel.printQuarDesocupados();
                        break;
                    }
                    case 5: // Pesquisar quarto
                    {
                        int numero;

                        cout << "Digite o numero do quarto a ser pesquisado: ";
                        cin >> numero;

                        hotel.pesquisaQuarto(numero);
                        break;
                    }
                    default:
                    cout << "Opcao incorreta" << endl
                        << "Informe novamente" << endl;
                        break;
                    }
                }
                

                break;
            }
            default:
            {
                cout << "Opcao incorreta" << endl
                << "Informe novamente" << endl;
            }
        }
    }
    return 0;
}

void menufuncionario()//Funções que armazenam os menus cliente e funcionário.
{
    cout << "Menu funcionario" << endl
        << "(1) Adicionar quarto" << endl
        << "(2) Remover quarto" << endl
        << "(3) Remover reserva" << endl
        << "(4) Printar lista de quartos" << endl
        << "(5) Printar lista de reservas" << endl
        << "(6) Pesquisar quarto" << endl
        << "(0) Finalizar" << endl
        << ">> ";
}

void menucliente()
{
    cout << "Menu cliente"<< endl
        << "(1) Fazer reserva" << endl
        << "(2) Check out" << endl
        << "(3) Cancelar reserva" << endl
        << "(4) Printar lista de quartos desocupados" << endl
        << "(5) Pesquisar quarto" << endl
        << "(0) Finalizar" << endl 
        << ">> ";
}
