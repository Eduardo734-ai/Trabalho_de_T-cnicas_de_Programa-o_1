#include "../../Include/Apresentacao/ControladoraPessoa.h"

#include <iostream>
#include <stdexcept>
#include <limits>

using namespace std;

ControladoraPessoa::ControladoraPessoa(ServicoPessoa* servicoPessoa) {
    this->servicoPessoa = servicoPessoa;
}

void ControladoraPessoa::menuPessoa() {
    cout << endl;
    cout << "===== MENU PESSOA =====" << endl;
    cout << "1 - Criar pessoa" << endl;
    cout << "2 - Ler pessoa" << endl;
    cout << "3 - Atualizar pessoa" << endl;
    cout << "4 - Excluir pessoa" << endl;
    cout << "0 - Voltar" << endl;
    cout << "Opcao: ";
}

void ControladoraPessoa::executar() {
    int opcao;

    do {
        menuPessoa();
        cin >> opcao;

        try {
            switch (opcao) {
                case 1:
                    criarPessoa();
                    break;
                case 2:
                    lerPessoa();
                    break;
                case 3:
                    atualizarPessoa();
                    break;
                case 4:
                    excluirPessoa();
                    break;
                case 0:
                    break;
                default:
                    cout << "Opcao invalida." << endl;
            }
        }
        catch (invalid_argument &erro) {
            cout << "Erro: " << erro.what() << endl;
        }
    } while (opcao != 0);
}

void ControladoraPessoa::criarPessoa() {
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

    servicoPessoa->criar(pessoa);

    cout << "Pessoa criada com sucesso." << endl;
}

void ControladoraPessoa::lerPessoa() {
    Email email;
    string entrada;
    Pessoa pessoa;

    cout << "Email da pessoa: ";
    cin >> entrada;
    email.setValor(entrada);

    pessoa = servicoPessoa->ler(email);

    cout << "Email: " << pessoa.getEmail().getValor() << endl;
    cout << "Nome: " << pessoa.getNome().getValor() << endl;
    cout << "Papel: " << pessoa.getPapel().getValor() << endl;
}

void ControladoraPessoa::atualizarPessoa() {
    Email email;
    Nome nome;
    Senha senha;
    Papel papel;
    Pessoa pessoa;
    string entrada;

    cout << "Email da pessoa: ";
    cin >> entrada;
    email.setValor(entrada);

    cout << "Novo nome: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, entrada);
    nome.setValor(entrada);

    cout << "Nova senha: ";
    cin >> entrada;
    senha.setValor(entrada);

    cout << "Novo papel: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, entrada);
    papel.setValor(entrada);

    pessoa.setEmail(email);
    pessoa.setNome(nome);
    pessoa.setSenha(senha);
    pessoa.setPapel(papel);

    servicoPessoa->atualizar(pessoa);

    cout << "Pessoa atualizada com sucesso." << endl;
}

void ControladoraPessoa::excluirPessoa() {
    Email email;
    string entrada;

    cout << "Email da pessoa: ";
    cin >> entrada;
    email.setValor(entrada);

    servicoPessoa->excluir(email);

    cout << "Pessoa excluida com sucesso." << endl;
}
