#include "../../include/apresentacao/ControladoraSistema.h"

#include <iostream>
#include <stdexcept>
#include <vector>
#include <limits>

using namespace std;

ControladoraSistema::ControladoraSistema() {
    controladoraPessoa = new ControladoraPessoa(&servicoPessoa);
    controladoraProjeto = new ControladoraProjeto(&servicoProjeto,&servicoPessoa);
    controladoraPlano = new ControladoraPlanoDeSprint(&servicoPlano,&servicoProjeto,&servicoHistoria);
    controladoraHistoria = new ControladoraHistoria(&servicoHistoria,&servicoProjeto,&servicoAutenticacao);
    controladoraAssociacoes = new ControladoraAssociacoes(&servicoAutenticacao,&servicoPessoa,&servicoProjeto,&servicoPlano,&servicoHistoria);
}

ControladoraSistema::~ControladoraSistema() {
    delete controladoraPessoa;
    delete controladoraProjeto;
    delete controladoraPlano;
    delete controladoraHistoria;
    delete controladoraAssociacoes;
}

void ControladoraSistema::menuInicial() {
    cout << endl;
    cout << "===== MENU INICIAL =====" << endl;
    cout << "1 - Cadastrar usuario" << endl;
    cout << "2 - Login" << endl;
    cout << "0 - Sair" << endl;
    cout << "Opcao: ";
}

void ControladoraSistema::menuPrincipal() {
    cout << endl;
    cout << "===== MENU PRINCIPAL =====" << endl;
    cout << "1 - Pessoa" << endl;
    cout << "2 - Projeto" << endl;
    cout << "3 - Plano de Sprint" << endl;
    cout << "4 - Historia de Usuario" << endl;
    cout << "5 - Associacoes e Listagens" << endl;
    cout << "6 - Alterar Estado de Historia" << endl;
    cout << "7 - Logout" << endl;
    cout << "0 - Sair" << endl;
    cout << "Opcao: ";
}

void ControladoraSistema::executarCadastro() {
    Email email;
    Nome nome;
    Senha senha;
    Papel papel;
    Pessoa pessoa;
    string entrada;

    cout << "Email: ";
    cin >> entrada;
    email.setValor(entrada);

    cout << "Nome: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, entrada);
    nome.setValor(entrada);

    cout << "Senha: ";
    cin >> entrada;
    senha.setValor(entrada);

    cout << "Papel (DESENVOLVEDOR / MESTRE SCRUM / PROPRIETARIO DE PRODUTO): ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, entrada);
    papel.setValor(entrada);

    pessoa.setEmail(email);
    pessoa.setNome(nome);
    pessoa.setSenha(senha);
    pessoa.setPapel(papel);

    servicoAutenticacao.cadastrar(pessoa);
    servicoPessoa.criar(pessoa);

    cout << "Usuario cadastrado com sucesso." << endl;
}

void ControladoraSistema::executarLogin() {
    Email email;
    Senha senha;
    string entrada;

    cout << "Email: ";
    cin >> entrada;
    email.setValor(entrada);

    cout << "Senha: ";
    cin >> entrada;
    senha.setValor(entrada);

    servicoAutenticacao.login(email, senha);

    cout << "Login realizado com sucesso." << endl;
}

void ControladoraSistema::executarLogout() {
    servicoAutenticacao.logout();
    cout << "Logout realizado com sucesso." << endl;
}

void ControladoraSistema::executar() {
    int opcao;
    int sair;

    sair = 0;

    while (sair == 0) {
        try {
            if (!servicoAutenticacao.estaAutenticado()) {
                menuInicial();
                cin >> opcao;

                switch (opcao) {
                    case 1:
                        executarCadastro();
                        break;

                    case 2:
                        executarLogin();
                        break;

                    case 0:
                        sair = 1;
                        break;

                    default:
                        cout << "Opcao invalida." << endl;
                }
            }
            else {
                menuPrincipal();
                cin >> opcao;

                switch (opcao) {
                    case 1:
                        controladoraPessoa->executar();
                        break;

                    case 2:
                        controladoraProjeto->executar();
                        break;

                    case 3:
                        controladoraPlano->executar();
                        break;

                    case 4:
                        controladoraHistoria->executar();
                        break;

                    case 5:
                        controladoraAssociacoes->executar();
                        break;

                    case 6:
                        controladoraAssociacoes->executarAlterarEstado();
                        break;

                    case 7:
                        executarLogout();
                        break;

                    case 0:
                        sair = 1;
                        break;

                    default:
                        cout << "Opcao invalida." << endl;
                }
            }
        }
        catch (invalid_argument &erro) {
            cout << "Erro: " << erro.what() << endl;
        }
    }

    cout << "Sistema encerrado." << endl;
}
