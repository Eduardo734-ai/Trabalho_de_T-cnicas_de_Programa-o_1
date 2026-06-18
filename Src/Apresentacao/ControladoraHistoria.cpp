#include "../../Include/Apresentacao/ControladoraHistoria.h"

#include <iostream>
#include <stdexcept>
#include <limits>

using namespace std;

ControladoraHistoria::ControladoraHistoria(
    ServicoHistoriaUsuario* servicoHistoria,
    ServicoProjeto* servicoProjeto,
    ServicoAutenticacao* servicoAutenticacao
) {
    this->servicoHistoria = servicoHistoria;
    this->servicoProjeto = servicoProjeto;
    this->servicoAutenticacao = servicoAutenticacao;
}

void ControladoraHistoria::menuHistoria() {
    cout << endl;
    cout << "===== MENU HISTORIA DE USUARIO =====" << endl;
    cout << "1 - Criar historia associada a projeto" << endl;
    cout << "2 - Ler historia" << endl;
    cout << "3 - Atualizar historia" << endl;
    cout << "4 - Excluir historia" << endl;
    cout << "0 - Voltar" << endl;
    cout << "Opcao: ";
}

void ControladoraHistoria::executar() {
    int opcao;

    do {
        menuHistoria();
        cin >> opcao;

        try {
            switch (opcao) {
                case 1:
                    criarHistoria();
                    break;

                case 2:
                    lerHistoria();
                    break;

                case 3:
                    atualizarHistoria();
                    break;

                case 4:
                    excluirHistoria();
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

void ControladoraHistoria::criarHistoria() {
    servicoAutenticacao->exigirProductOwner();

    Codigo codigo;
    Codigo codigoProjeto;
    Nome nome;
    Papel papel;
    Texto acao;
    Texto valor;
    Tempo estimativa;
    Prioridade prioridade;
    Estado estado;
    HistoriaUsuario historia;
    string entrada;
    int valorInteiro;

    cout << "Codigo da historia: ";
    cin >> entrada;
    codigo.setValor(entrada);

    cout << "Nome da historia: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, entrada);
    nome.setValor(entrada);

    cout << "Papel da historia: ";
    getline(cin, entrada);
    papel.setValor(entrada);

    cout << "Acao: ";
    getline(cin, entrada);
    acao.setValor(entrada);

    cout << "Valor: ";
    getline(cin, entrada);
    valor.setValor(entrada);

    cout << "Estimativa: ";
    cin >> valorInteiro;
    estimativa.setValor(valorInteiro);

    cout << "Prioridade: ";
    cin >> entrada;
    prioridade.setValor(entrada);

    estado.setValor("A FAZER");

    cout << "Codigo do projeto associado: ";
    cin >> entrada;
    codigoProjeto.setValor(entrada);

    historia.setCodigo(codigo);
    historia.setNome(nome);
    historia.setPapel(papel);
    historia.setAcao(acao);
    historia.setValor(valor);
    historia.setEstimativa(estimativa);
    historia.setPrioridade(prioridade);
    historia.setEstado(estado);

    servicoHistoria->criar(historia);
    servicoProjeto->criarHistoriaAssociadaProjeto(historia, codigoProjeto);

    cout << "Historia criada com sucesso." << endl;
}

void ControladoraHistoria::lerHistoria() {
    Codigo codigo;
    HistoriaUsuario historia;
    string entrada;

    cout << "Codigo da historia: ";
    cin >> entrada;
    codigo.setValor(entrada);

    historia = servicoHistoria->ler(codigo);

    cout << "Codigo: " << historia.getCodigo().getValor() << endl;
    cout << "Nome: " << historia.getNome().getValor() << endl;
    cout << "Papel: " << historia.getPapel().getValor() << endl;
    cout << "Acao: " << historia.getAcao().getValor() << endl;
    cout << "Valor: " << historia.getValor().getValor() << endl;
    cout << "Estimativa: " << historia.getEstimativa().getValor() << endl;
    cout << "Prioridade: " << historia.getPrioridade().getValor() << endl;
    cout << "Estado: " << historia.getEstado().getValor() << endl;
}

void ControladoraHistoria::atualizarHistoria() {
    servicoAutenticacao->exigirProductOwner();

    Codigo codigo;
    Nome nome;
    Papel papel;
    Texto acao;
    Texto valor;
    Tempo estimativa;
    Prioridade prioridade;
    Estado estado;
    HistoriaUsuario historiaAtual;
    HistoriaUsuario historiaNova;
    string entrada;
    int valorInteiro;

    cout << "Codigo da historia: ";
    cin >> entrada;
    codigo.setValor(entrada);

    historiaAtual = servicoHistoria->ler(codigo);
    estado = historiaAtual.getEstado();

    cout << "Novo nome: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, entrada);
    nome.setValor(entrada);

    cout << "Novo papel da historia: ";
    getline(cin, entrada);
    papel.setValor(entrada);

    cout << "Nova acao: ";
    getline(cin, entrada);
    acao.setValor(entrada);

    cout << "Novo valor: ";
    getline(cin, entrada);
    valor.setValor(entrada);

    cout << "Nova estimativa: ";
    cin >> valorInteiro;
    estimativa.setValor(valorInteiro);

    cout << "Nova prioridade: ";
    cin >> entrada;
    prioridade.setValor(entrada);

    historiaNova.setCodigo(codigo);
    historiaNova.setNome(nome);
    historiaNova.setPapel(papel);
    historiaNova.setAcao(acao);
    historiaNova.setValor(valor);
    historiaNova.setEstimativa(estimativa);
    historiaNova.setPrioridade(prioridade);
    historiaNova.setEstado(estado);

    servicoHistoria->atualizar(historiaNova);

    cout << "Historia atualizada com sucesso." << endl;
}

void ControladoraHistoria::excluirHistoria() {
    servicoAutenticacao->exigirProductOwner();

    Codigo codigo;
    string entrada;

    cout << "Codigo da historia: ";
    cin >> entrada;
    codigo.setValor(entrada);

    servicoHistoria->excluir(codigo);

    cout << "Historia excluida com sucesso." << endl;
}
