#include "../../Include/Apresentacao/ControladoraProjeto.h"

#include <iostream>
#include <stdexcept>
#include <limits>

using namespace std;

ControladoraProjeto::ControladoraProjeto(ServicoProjeto* servicoProjeto, ServicoPessoa* servicoPessoa) {
    this->servicoProjeto = servicoProjeto;
    this->servicoPessoa = servicoPessoa;
}

void ControladoraProjeto::menuProjeto() {
    cout << endl;
    cout << "===== MENU PROJETO =====" << endl;
    cout << "1 - Criar projeto associado a Mestre Scrum" << endl;
    cout << "2 - Ler projeto" << endl;
    cout << "3 - Atualizar projeto" << endl;
    cout << "4 - Excluir projeto" << endl;
    cout << "0 - Voltar" << endl;
    cout << "Opcao: ";
}

void ControladoraProjeto::executar() {
    int opcao;

    do {
        menuProjeto();
        cin >> opcao;

        try {
            switch (opcao) {
                case 1:
                    criarProjeto();
                    break;
                case 2:
                    lerProjeto();
                    break;
                case 3:
                    atualizarProjeto();
                    break;
                case 4:
                    excluirProjeto();
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

void ControladoraProjeto::criarProjeto() {
    Codigo codigo;
    Nome nome;
    Data inicio;
    Data termino;
    Email emailMestre;
    Projeto projeto;
    Pessoa mestre;
    string entrada;

    cout << "Codigo do projeto: ";
    cin >> entrada;
    codigo.setValor(entrada);

    cout << "Nome do projeto: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, entrada);
    nome.setValor(entrada);

    cout << "Data inicio: ";
    cin >> entrada;
    inicio.setValor(entrada);

    cout << "Data termino: ";
    cin >> entrada;
    termino.setValor(entrada);

    cout << "Email do Mestre Scrum: ";
    cin >> entrada;
    emailMestre.setValor(entrada);

    mestre = servicoPessoa->ler(emailMestre);

    projeto.setCodigo(codigo);
    projeto.setNome(nome);
    projeto.setDataInicio(inicio);
    projeto.setDataTermino(termino);

    servicoProjeto->criarAssociadoPessoa(projeto, mestre);

    cout << "Projeto criado com sucesso." << endl;
}

void ControladoraProjeto::lerProjeto() {
    Codigo codigo;
    Projeto projeto;
    string entrada;

    cout << "Codigo do projeto: ";
    cin >> entrada;
    codigo.setValor(entrada);

    projeto = servicoProjeto->ler(codigo);

    cout << "Codigo: " << projeto.getCodigo().getValor() << endl;
    cout << "Nome: " << projeto.getNome().getValor() << endl;
    cout << "Inicio: " << projeto.getDataInicio().getValor() << endl;
    cout << "Termino: " << projeto.getDataTermino().getValor() << endl;
}

void ControladoraProjeto::atualizarProjeto() {
    Codigo codigo;
    Nome nome;
    Data inicio;
    Data termino;
    Projeto projeto;
    string entrada;

    cout << "Codigo do projeto: ";
    cin >> entrada;
    codigo.setValor(entrada);

    cout << "Novo nome: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, entrada);
    nome.setValor(entrada);

    cout << "Nova data inicio: ";
    cin >> entrada;
    inicio.setValor(entrada);

    cout << "Nova data termino: ";
    cin >> entrada;
    termino.setValor(entrada);

    projeto.setCodigo(codigo);
    projeto.setNome(nome);
    projeto.setDataInicio(inicio);
    projeto.setDataTermino(termino);

    servicoProjeto->atualizar(projeto);

    cout << "Projeto atualizado com sucesso." << endl;
}

void ControladoraProjeto::excluirProjeto() {
    Codigo codigo;
    string entrada;

    cout << "Codigo do projeto: ";
    cin >> entrada;
    codigo.setValor(entrada);

    servicoProjeto->excluir(codigo);

    cout << "Projeto excluido com sucesso." << endl;
}
