#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <ctime> // usando em função srand 
#include <clocale> // usado para usar caracteres da lingua portuguesa
#include <sstream> // usado para stringstream

using namespace std;

// Função para verificação de resposta do usuário
int verificaInt(); // garante que o usuário envia um int como input
float verificaFloat();  // garante que o usuário envia um float como input


// Inclusão de classes
#include "quarto.cpp"
#include "QuartoPcD.cpp"
#include "quartopremium.cpp"
#include "reserva.cpp"
#include "hotel.cpp"

// Protótipo de funções de menu
void menufuncionario();
void menucliente();
void menuquartos();
void menuinicial(Hotel&);

int main()
{

    // função relacionada à geração randômica de números de reservas
    srand((unsigned) time(0));

    // Permite o uso de caracteres da língua portuguesa 
    setlocale(LC_ALL, "portuguese");

    // Cria o objeto Hotel
    Hotel hotel;

    if(!hotel.getAndares()) // Se o hotel não tiver andares, não foi inicializado ainda.
    {
        // Começa o processo de configuração do Hotel
        int andares, maxQuartos_andares;

        cout << "Primeira vez aqui ?\nDefina as propriedades do hotel" << endl;

        // Configura atributos do hotel
        while(1)
        {

            cout << "Defina a quantidade de andares: ";
            andares = verificaInt();

            cout << "Defina a quantidade máxima de quartos por andar: ";
            maxQuartos_andares = verificaInt();

            if(andares > 0 && maxQuartos_andares > 0) // Verifica se dados passados fazem sentido
                break;

            cout << "Dado(s) inválido(s), informe novamente!" << endl;

            system("pause");
            system("cls");
        }
        system("cls");

        // Termina a configuração do Hotel setando os dados
        hotel.setMaxQuartos(maxQuartos_andares);
        hotel.setAndares(andares);

    }
    unsigned op;

    while(1)
    {
        menuinicial(hotel); // Função que printa o menu inicial do Hotel
        op = verificaInt();

        switch(op)
        {
            case 0:
                return 0;
            // menu funcionário
            case 1:
            {
                while(1)
                {
                    // Verifica a senha do funcionário
                    string senha;

                    system("cls");

                    cout << "Insira a senha: " << endl;
                    cout << setfill('-') << setw(41) << "-" << endl;
                    cin.sync();
                    cin >> senha;

                    if(senha != "admin")
                        cout << "Senha incorreta!\n" << endl;
                    else
                    {
                        // Entra no menu do funcionário
                        unsigned op;
                        while(1)
                        {
                            system("cls");

                            menufuncionario(); // Função que printa o menu do funcionário
                            op = verificaInt();

                            if (op == 9) // Caso 9 -> Retornar ao menu do Hotel
                                break;

                            switch(op)
                            {
                                // Caso 0 -> Encerra o programa
                                case 0:
                                    return 0;

                                // Caso 1 -> Adicionar Quartos
                                case 1:
                                {
                                    unsigned op = 0;

                                    system("cls");

                                    cout << "Escolha um tipo de quarto para adicionar" << endl;
                                    menuquartos(); // Função que printa o menu de tipos de quartos
                                    op = verificaInt();
                                    cout << setfill('-') << setw(41) << "-" << endl;

                                    if(op < 1 || op > 3) // Verifica se uma opcão válida foi inserida
                                    {
                                        cout << "Opcao invalida" << endl;
                                        break;
                                    }

                                    // Inicializa variáveis do quarto
                                    int andar, numero, camas, capacidade;
                                    float diaria;

                                    while(1)
                                    {
                                        cout << "Digite o andar: ";
                                        andar = verificaInt();

                                        cout << "Digite o número: ";
                                        numero = verificaInt();

                                        cout << "Digite a capacidade: ";
                                        capacidade = verificaInt();

                                        cout << "Digite a quantidade de camas: ";
                                        camas = verificaInt();

                                        cout << "Digite a diária: ";
                                        diaria = verificaFloat();

                                        // Verifica se os dados inseridos são válidos
                                        if(andar >= 0 && numero > 0 && capacidade > 0 && camas > 0 && diaria > 0)
                                            break;

                                        cout << "Dado(s) inválido(s), informe novamente!" << endl;
                                    }
                                    switch(op)
                                    {
                                        // Inserir Quarto Padrão
                                        case 1:
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

                                        // Inserir Quarto Premium
                                        case 2:
                                        {
                                            int wifi, chuv, servico;
                                            float arcond, TV;

                                            while(1)
                                            {

                                                cout << "Digite a velocidade wifi(em Mb/s): ";
                                                wifi = verificaInt();
                                                cout << "Quantidade de chuveiros elétricos: ";
                                                chuv = verificaInt();
                                                cout << "Digite a potência do ar-condicionado: ";
                                                arcond = verificaFloat();
                                                cout << "Digite a quantidade de polegadas da TV:  ";
                                                TV = verificaFloat();
                                                cout << "Digite a quantidade de funcionários:  ";
                                                servico = verificaInt();

                                                // Verifica se os dados inseridos são válidos
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

                                        // Inserir Quarto PcD
                                        case 3:
                                        {
                                            int qnt;
                                            string tipo;

                                            cout << "Digite o tipo de adaptação: ";
                                            cin.sync();
                                            getline(cin, tipo);

                                            while(1)
                                            {
                                                cout << "Digite a quantidade de funcionários:  ";
                                                qnt = verificaInt();

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

                                // Caso 2 -> Remover Quarto
                                case 2:
                                {
                                    // Inicializa variáveis necessárias para identificar quarto a ser removido
                                    int tipo, numero;

                                    system("cls");

                                    cout << "Removendo quarto" << endl;
                                    cout << "Digite o tipo do quarto a ser removido" << endl;
                                    menuquartos();
                                    tipo = verificaInt();

                                    // Verifica se os dados inseridos são válidos
                                    if(op < 1 || op > 3)
                                    {
                                        cout << "Opcao invalida" << endl;
                                        break;
                                    }

                                    cout << "\nDigite o número do quarto: ";
                                    numero = verificaInt();


                                    // Verifica e comunica que remoção de quarto foi um sucesso ou não
                                    if (!hotel.rmv_quarto(numero, tipo))
                                    {
                                        cout << "Não foi possível remover o quarto!" << endl;
                                        break;
                                    }
                                    cout << "Sucesso!" << endl;
                                    break;
                                }
                                
                                // Caso 3 -> Remover reserva
                                case 3:
                                {
                                    // Inicializa variável necessária para remoção de reserva
                                    int numero;

                                    system("cls");

                                    cout << "Removendo reserva" << endl;
                                    cout << setfill('=') << setw(41) << "=" << endl;
                                    cout << "Informe o número da reserva: " << endl;
                                    numero = verificaInt();

                                    // Verifica e comunica se remoção de reserva foi um sucesso ou não
                                    if(!hotel.removerReserva(numero))
                                    {
                                        cout << "Não foi possível encontrar a reserva!" << endl;
                                        break;
                                    }

                                    cout << "Sucesso!" << endl;
                                    break;
                                }

                                // Caso 4 -> Printar lista de quartos
                                case 4:
                                {
                                    system("cls");
                                    hotel.printQuartos(); // Função que retorna a lista completa de quartos
                                    break;
                                }

                                // Caso 5 -> Printar lista de quartos ocupados
                                case 5:
                                {
                                    system("cls");
                                    cout << "Quartos ocupados" << endl;
                                    cout << setfill('=') << setw(41) << "=" << endl;
                                    hotel.printQuarOcupados(); // Função que retorna a lista completa de quartos ocupados
                                    break;
                                }

                                // Caso 6 -> Printar lista de reservas
                                case 6:
                                {
                                    system("cls");
                                    cout << "Lista de reservas" << endl;
                                    cout << setfill('=') << setw(41) << "=" << endl;
                                    hotel.printReservas(); // Função que retorna a lista completa de reservas
                                    break;
                                }

                                // Caso -> Pesquisar quarto 
                                case 7:
                                {
                                    // Inicializa variável necessária para encontrar quarto
                                    int numero;

                                    system("cls");

                                    cout << "Pesquisando quarto" << endl;
                                    cout << setfill('=') << setw(41) << "=" << endl;
                                    cout << "Digite o numero do quarto a ser pesquisado: ";
                                    numero = verificaInt();

                                    hotel.pesquisaQuarto(numero); // Printa na tela o quarto pesquisado
                                    break;
                                }

                                // Caso 8 -> Modificar quarto
                                case 8:
                                {
                                    // Inicializa variáveis necessárias para encontrar quarto a ser modificado
                                    int nm, tipo;
                                    int atrib;

                                    system("cls");
                                    
                                    cout << "Digite o tipo de quarto a ser modificado: " << endl;
                                    menuquartos();
                                    tipo = verificaInt();

                                    cout << setfill('-') << setw(41) << "-" << endl;

                                    // Verifica se os dados inseridos são válidos
                                    if(tipo < 1 || tipo > 3)
                                    {
                                        cout << "Opcao invalida" << endl;
                                        break;
                                    }

                                    cout << "Digite o numero do quarto a ser modificado: ";
                                    nm = verificaInt();

                                    // Verifica se o quarto não foi encontrado ou se está ocupado
                                    if(!hotel.verificaQuarto(nm, tipo))
                                    {
                                        cout << "Quarto ocupado ou não encontrado!" << endl;
                                        break;
                                    }

                                    // Modifica Quarto Padrão
                                    if(tipo == 1)
                                    {
                                        cout <<"Digite qual atributo voce deseja modificar:" << endl
                                        << "1 - diaria" << endl << "2 - camas" << endl << "3 - capacidade" << endl;
                                        atrib = verificaInt();

                                        // Verifica se os dados inseridos são válidos
                                        if(atrib < 1 || atrib > 4)
                                        {
                                            cout << "Numero inválido" << endl;
                                            break;
                                        }

                                        // Verifica e comunica se a modificação foi realizada com sucesso ou não
                                        if(!hotel.modificaQuarto(nm,atrib))
                                        {
                                            cout << "Modificação não realizada" << endl;

                                            break;
                                        }
                                        cout << "Modificação realizada" << endl;
                                        break;
                                    }

                                    // Modifica Quarto Premium
                                    if(tipo == 2)
                                    {
                                        cout <<"Digite qual atributo voce deseja modificar:" << endl
                                        << "1 - diaria" << endl << "2 - camas" << endl << "3 - capacidade" << endl
                                        << "4 - wifi" << endl << "5 - chuveiros" << endl << "6 - Funcionarios no serviço de quarto"
                                        << endl << "7 - potencia do arcondicionado" << endl << "8 - polegadas de televisão" << endl;
                                        atrib = verificaInt();

                                        // Verifica se os dados inseridos são válidos
                                        if(atrib < 1 || atrib > 8)
                                        {
                                            cout << "Numero inválido" << endl;
                                            break;
                                        }

                                        // Verifica e comunica se a modificação foi realizada com sucesso ou não
                                        if(!hotel.modificaQuarto_premium(nm,atrib))
                                        {
                                            cout << "Modificação não realizada" << endl;

                                            break;
                                        }
                                        cout << "Modificação realizada" << endl;
                                        break;
                                    }

                                    // Modifica Quarto PcD
                                    if(tipo == 3)
                                    {
                                        cout <<"Digite qual atributo voce deseja modificar:" << endl
                                        << "1 - diaria" << endl << "2 - camas" << endl << "3 - capacidade" << endl
                                        << "4 - Tipo de Adaptação" << endl << "5 - Funcionarios no serviço de quarto" << endl;
                                        atrib = verificaInt();

                                        // Verifica se os dados inseridos são válidos
                                        if(atrib < 1 || atrib > 5)
                                        {
                                            cout << "Numero inválido" << endl;
                                            break;
                                        }

                                        // Verifica e comunica se a modificação foi realizada com sucesso ou não
                                        if(!hotel.modificaQuarto_PcD(nm,atrib))
                                        {
                                            cout << "Modificação não realizada" << endl;

                                            break;
                                        }
                                        cout << "Modificação realizada" << endl;
                                        break;
                                    }
                                }

                                // Opção inválida
                                default:
                                    cout << "Opção inválida" << endl;
                            }
                            system("pause");
                        }
                        if (op == 9)
                            break;
                    }
                    system("pause");
                }
                break;
            }
            // menu cliente
            case 2:
            {
                while (1)
                {
                    system("cls");
                    unsigned op;

                    // Printa o menu do cliente
                    menucliente();
                    op = verificaInt();

                    // Caso 5 -> Retorna ao menu do Hotel
                    if (op == 5)
                        break;

                    switch (op)
                    {
                    
                    // Caso 0 -> Encerra o programa
                    case 0:
                        return 0;

                    case 1: // Fazer reserva
                    {
                        // cria e pega o valor de variáveis p/ reserva
                        int op;
                        int acompanhantes, num_quarto, dias;
                        string nome, tipo_quarto;

                        while(1)
                        {
                            system("cls");

                            cout << "Realizando reserva" << endl;
                            cout << setfill('=') << setw(41) << "=" << endl;

                            cout << "Digite o número de acompanhantes: ";
                            acompanhantes = verificaInt();

                            cout << "Digite o número do quarto: ";
                            num_quarto = verificaInt();

                            cout << "Digite o número de dias: ";
                            dias = verificaInt();

                            // Verifica se as entradas foram válidas
                            if(acompanhantes > 0 && num_quarto > 0 && dias > 0)
                                break;

                            cout << "Dado(s) inválido(s), informe novamente!" << endl;
                            system("pause");
                        }

                        cout << "Digite o seu nome: ";
                        getline(cin >> ws, nome);

                        cout << "Digite o tipo de quarto " << endl;
                        // Printa o menu de tipos de quartos a serem escolhidos
                        menuquartos();
                        op = verificaInt();

                        if(op == 1)
                            tipo_quarto = "Quarto";
                        else if(op == 2)
                            tipo_quarto = "Quarto Premium";
                        else if(op == 3)
                            tipo_quarto = "Quarto PcD";
                        else
                        {
                            cout << "Opção inválida!" << endl;
                            break;
                        }

                        // cria o objeto Reserva
                        Reserva reserva(acompanhantes, num_quarto, dias, nome, tipo_quarto);

                        // adiciona a reserva ao hotel
                        if(hotel.addReserva(reserva)){
                            cout << "Reserva feita com sucesso!" << endl
                                << setfill('-') << setw(41) << "-" << endl
                                << "O número da sua reserva é " << reserva.get_nmReserva() << endl
                                << "Montante a ser pago: R$ " << reserva.getmontante() << endl;
                            break;
                        }
                        cout << "Reserva não realizada." << endl;
                        break;
                    }
                    case 2: // Pagamento de reserva.
                    {
                        int num_reserva;
                        float avaliacao = -1; // inicializando avaliacao

                        system("cls");

                        cout << "Realizando Finalização e pagamento da Reserva" << endl;
                        cout << setfill('=') << setw(41) << "=" << endl;

                        // Pega o número do quarto
                        cout << "Digite o número da reserva: " << endl;
                        num_reserva = verificaInt();

                        cout << "O montante a ser pago por essa reserva(em R$): " << hotel.pesquisaMontante(num_reserva) << endl;

                        // Remove a reserva, se encontrada no sistema
                        if(!hotel.removerReserva(num_reserva))
                        {
                            cout << "A reserva não foi encontrada." << endl;
                            break;
                        }

                        cout << "Reserva finalizada com sucesso!" << endl;

                        // Avaliação do hotel pelo cliente
                        cout << "Antes de ir, poderia deixar uma avaliação de 0 a 5 para o hotel?" << endl
                            << "Sendo 0 - Muito Ruim e 5 - Muito bom " << endl;

                        cout << ">> ";
                        cin >> avaliacao;

                        // Verifica se as entradas foram válidas
                        while ((avaliacao < 0 || avaliacao > 5))
                        {
                            cout << "Dado(s) inválido(s), por favor inserir novamente >> ";
                            cin >> avaliacao;
                        }

                        // Altera o ranking do hotel
                        hotel.defRanking(avaliacao);


                        cout << "Avaliação realizada com sucesso!" << endl
                            << "Obrigado, volte sempre!" << endl;
                        break;
                    }

                    case 3: // Printar lista de quartos desocupados
                    {
                        system("cls");

                        hotel.printQuarDesocupados(); // Printa os quartos disponíveis para reserva
                        break;
                    }
                    case 4: // Pesquisar quarto
                    {
                        int numero;

                        system("cls");

                        cout << "Pesquisando quarto" << endl;
                        cout << setfill('=') << setw(41) << "=" << endl;

                        cout << "Digite o numero do quarto a ser pesquisado: ";
                        numero = verificaInt();

                        hotel.pesquisaQuarto(numero); // Pesquisa um quarto específico
                        break;
                    }
                    default:
                        cout << "Opcao incorreta" << endl
                            << "Informe novamente" << endl;
                    }
                    system("pause");
                    if (op == 5) // Retorna ao menu do hotel (principal)
                        break;
                }
                break;
            }
            default:
            {
                cout << "Opcao incorreta" << endl
                << "Informe novamente" << endl;
            }
            system("pause");
        }
    }
    return 0;
}

void menuinicial(Hotel& hotel) // Função que printa o menu inicial do Hotel
{
    // stream de string que terá a avaliação total do hotel
    stringstream strstream;

    system("cls");

    if(!hotel.get_contAva())
        strstream << "sem availações";
    else
        strstream << hotel.getRanking();

    // Apresentação do Hotel com formatação
    cout << setfill('=') << setw(41) << "=" << endl;
    cout << setfill(' ') << setw(16) << " " << "Bem-vindo" << endl;
    cout << setfill(' ') << setw(14) << " " << "Hotel OgaVirt" << endl;

    cout << setprecision(2);
    (strstream.str().size() > 10) ?
    cout << setfill(' ') << setw(6) << " " << "Avaliação: " << strstream.str() << endl
    :
    cout << setfill(' ') << setw(12) << " " << "Avaliação:  " << strstream.str() << endl;
    cout << setfill(' ') << setw(14) << " " << "Hóspedes:  " << hotel.getPessoas() << endl;
    cout << setfill('=') << setw(41) << "=" << endl;

    // Menu de opções
    cout << "Entrar como:" << endl
        << "(1) Funcionário" << endl
        << "(2) Cliente" << endl
        << "(0) Sair" << endl
        << ">> ";
}

void menufuncionario() // Função que printa o menu do funcionário
{
    cout << setfill('=') << setw(41) << "=" << endl;
    cout << setfill(' ') << setw(12) << " " << "Menu funcionário" << endl;
    cout << setfill('=') << setw(41) << "=" << endl;
    cout << "(1) Adicionar quarto" << endl
         << "(2) Remover quarto" << endl
         << "(3) Remover reserva" << endl
         << "(4) Printar lista de quartos" << endl
         << "(5) Printar lista de quartos ocupados" << endl
         << "(6) Printar lista de reservas" << endl
         << "(7) Pesquisar quarto" << endl
         << "(8) Modifica quarto" << endl
         << "(9) Retornar ao menu principal" << endl
         << "(0) Finalizar" << endl
         << ">> ";
}

void menucliente() // Função que printa o menu do cliente
{
    cout << setfill('=') << setw(41) << "=" << endl;
    cout << setfill(' ') << setw(15) << " " << "Menu cliente"<< endl;
    cout << setfill('=') << setw(41) << "=" << endl;
    cout  << "(1) Fazer reserva" << endl
        << "(2) Pagamento de reserva" << endl
        << "(3) Printar lista de quartos disponíveis" << endl
        << "(4) Pesquisar quarto" << endl
        << "(5) Retornar ao menu principal" << endl
        << "(0) Finalizar" << endl
        << ">> ";
}

void menuquartos() // Função que printa o menu de escolha de tipo de quartos
{
    cout << setfill('-') << setw(41) << "-" << endl;
    cout << "(1) Quarto Padrão" << endl
         << "(2) Quarto Premium" << endl
         << "(3) Quarto PcD" << endl
         << ">> ";
}

int verificaInt(){ // verifica se um número é int
    int op; char ch;
    while(1){
        cin >> op;
        cin.get(ch);
        if(cin.fail()){ // verifica se houve algum erro no cin. exemplo: inserir um 'a' no lugar de um número
            cout << "Opcao invalida! Por favor, insira uma opcao certa" << endl
            << ">> ";
            cin.clear(); // limpa o buffer
            cin.sync();
            continue; // continua o programa
        } else if(ch != '\n' && ch != ' '){ // verifica se há algum caracter junto ao numero, tornando-o inválido. exemplo: 12asd
            cout << "Opcao invalida! Por favor, insira uma opcao certa" << endl
            << ">> ";
            cin.clear(); // limpa o buffer
            cin.sync();
            continue; // continua o programa
        }
        else {
            break;
        }
    }
    return op;
}

float verificaFloat(){ // verifica se um número é float
    float op; char ch;
    while(1){
        cin >> op;
        cin.get(ch);
        if(cin.fail()){ // verifica se houve algum erro no cin. exemplo: inserir um 'a' no lugar de um número
            cout << "Opcao invalida! Por favor, insira uma opcao certa" << endl
            << ">> ";
            cin.clear(); // limpa o buffer
            cin.sync();
            continue; // continua o programa

        }else if(ch != '\n' && ch != ' '){ // verifica se há algum caracter junto ao numero, tornando-o inválido. exemplo: 12.54asd
            cout << "Opcao invalida! Por favor, insira uma opcao certa" << endl
            << ">> ";
            cin.clear(); // limpa o buffer
            cin.sync();
            continue; // continua o programa
        }
        else
            break;
    }
    return op;
}
