#include "../../Include/Apresentacao/ControladoraAssociacoes.h"

#include <iostream>
#include <stdexcept>
#include <vector>
#include <limits>

using namespace std;

ControladoraAssociacoes::ControladoraAssociacoes(
    ServicoAutenticacao* servicoAutenticacao,
    ServicoPessoa* servicoPessoa,
    ServicoProjeto* servicoProjeto,
    ServicoPlanoDeSprint* servicoPlano,
    ServicoHistoriaUsuario* servicoHistoria
) {
    this->servicoAutenticacao = servicoAutenticacao;
    this->servicoPessoa = servicoPessoa;
    this->servicoProjeto = servicoProjeto;
    this->servicoPlano = servicoPlano;
    this->servicoHistoria = servicoHistoria;
}

void ControladoraAssociacoes::menuAssociacoes() {
    cout << endl;
    cout << "===== MENU ASSOCIACOES E LISTAGENS =====" << endl;
    cout << "1 - Associar historia a pessoa" << endl;
    cout << "2 - Remover associacao historia-pessoa" << endl;
    cout << "3 - Listar projetos associados a pessoa" << endl;
    cout << "4 - Listar historias associadas a projeto" << endl;
    cout << "5 - Listar planos associados a projeto" << endl;
    cout << "6 - Listar historias associadas a plano" << endl;
    cout << "7 - Listar historias associadas a pessoa" << endl;
    cout << "8 - Mover historia para sprint" << endl;
    cout << "9 - Remover associacao projeto-pessoa" << endl;
    cout << "0 - Voltar" << endl;
    cout << "Opcao: ";
}

void ControladoraAssociacoes::executar() {
    int opcao;

    do {
        menuAssociacoes();
        cin >> opcao;

        try {
            switch (opcao) {
                case 1:
                    associarHistoriaPessoa();
                    break;
                case 2:
                    removerAssociacaoHistoriaPessoa();
                    break;
                case 3:
                    listarProjetosPessoa();
                    break;
                case 4:
                    listarHistoriasProjeto();
                    break;
                case 5:
                    listarPlanosProjeto();
                    break;
                case 6:
                    listarHistoriasPlano();
                    break;
                case 7:
                    listarHistoriasPessoa();
                    break;
                case 8:
                    moverHistoriaParaSprint();
                    break;
                case 9:
                    removerAssociacaoProjetoPessoa();
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

void ControladoraAssociacoes::executarAlterarEstado() {
    alterarEstadoHistoria();
}

void ControladoraAssociacoes::associarHistoriaPessoa() {
    servicoAutenticacao->exigirMestreScrum();

    Codigo codigoHistoria;
    Email emailPessoa;
    string entrada;

    cout << "Codigo da historia: ";
    cin >> entrada;
    codigoHistoria.setValor(entrada);

    cout << "Email da pessoa: ";
    cin >> entrada;
    emailPessoa.setValor(entrada);

    servicoPessoa->ler(emailPessoa);
    servicoHistoria->associarPessoa(codigoHistoria, emailPessoa);

    cout << "Historia associada a pessoa com sucesso." << endl;
}

void ControladoraAssociacoes::removerAssociacaoHistoriaPessoa() {
    servicoAutenticacao->exigirMestreScrum();

    Codigo codigoHistoria;
    Email emailPessoa;
    string entrada;

    cout << "Codigo da historia: ";
    cin >> entrada;
    codigoHistoria.setValor(entrada);

    cout << "Email da pessoa: ";
    cin >> entrada;
    emailPessoa.setValor(entrada);

    servicoHistoria->removerAssociacaoPessoa(codigoHistoria, emailPessoa);

    cout << "Associacao removida com sucesso." << endl;
}

void ControladoraAssociacoes::listarProjetosPessoa() {
    Email email;
    string entrada;
    vector<Projeto> projetos;

    cout << "Email da pessoa: ";
    cin >> entrada;
    email.setValor(entrada);

    projetos = servicoProjeto->listarProjetosAssociadosPessoa(email);

    cout << "Projetos associados: " << projetos.size() << endl;

    for (int i = 0; i < (int)projetos.size(); i++) {
        cout << "Codigo: " << projetos[i].getCodigo().getValor() << endl;
        cout << "Nome: " << projetos[i].getNome().getValor() << endl;
        cout << "-----" << endl;
    }
}

void ControladoraAssociacoes::listarHistoriasProjeto() {
    Codigo codigoProjeto;
    string entrada;
    vector<HistoriaUsuario> historias;

    cout << "Codigo do projeto: ";
    cin >> entrada;
    codigoProjeto.setValor(entrada);

    historias = servicoProjeto->listarHistoriasAssociadasProjeto(codigoProjeto);

    cout << "Historias associadas: " << historias.size() << endl;

    for (int i = 0; i < (int)historias.size(); i++) {
        cout << "Codigo: " << historias[i].getCodigo().getValor() << endl;
        cout << "Nome: " << historias[i].getNome().getValor() << endl;
        cout << "Estado: " << historias[i].getEstado().getValor() << endl;
        cout << "-----" << endl;
    }
}

void ControladoraAssociacoes::listarPlanosProjeto() {
    Codigo codigoProjeto;
    string entrada;
    vector<PlanoDeSprint> planos;

    cout << "Codigo do projeto: ";
    cin >> entrada;
    codigoProjeto.setValor(entrada);

    planos = servicoProjeto->listarPlanosAssociadosProjeto(codigoProjeto);

    cout << "Planos associados: " << planos.size() << endl;

    for (int i = 0; i < (int)planos.size(); i++) {
        cout << "Codigo: " << planos[i].getCodigo().getValor() << endl;
        cout << "Nome: " << planos[i].getNome().getValor() << endl;
        cout << "Capacidade: " << planos[i].getCapacidade().getValor() << endl;
        cout << "-----" << endl;
    }
}

void ControladoraAssociacoes::listarHistoriasPlano() {
    Codigo codigoPlano;
    string entrada;
    vector<HistoriaUsuario> historias;

    cout << "Codigo do plano: ";
    cin >> entrada;
    codigoPlano.setValor(entrada);

    historias = servicoHistoria->listarHistoriasAssociadasPlano(codigoPlano);

    cout << "Historias associadas ao plano: " << historias.size() << endl;

    for (int i = 0; i < (int)historias.size(); i++) {
        cout << "Codigo: " << historias[i].getCodigo().getValor() << endl;
        cout << "Nome: " << historias[i].getNome().getValor() << endl;
        cout << "Estado: " << historias[i].getEstado().getValor() << endl;
        cout << "-----" << endl;
    }
}

void ControladoraAssociacoes::listarHistoriasPessoa() {
    Email emailPessoa;
    string entrada;
    vector<HistoriaUsuario> historias;

    cout << "Email da pessoa: ";
    cin >> entrada;
    emailPessoa.setValor(entrada);

    historias = servicoHistoria->listarHistoriasAssociadasPessoa(emailPessoa);

    cout << "Historias associadas a pessoa: " << historias.size() << endl;

    for (int i = 0; i < (int)historias.size(); i++) {
        cout << "Codigo: " << historias[i].getCodigo().getValor() << endl;
        cout << "Nome: " << historias[i].getNome().getValor() << endl;
        cout << "Estado: " << historias[i].getEstado().getValor() << endl;
        cout << "-----" << endl;
    }
}

void ControladoraAssociacoes::moverHistoriaParaSprint() {
    servicoAutenticacao->exigirMestreScrum();

    Codigo codigoHistoria;
    Codigo codigoProjeto;
    Codigo codigoPlano;
    string entrada;

    cout << "Codigo da historia: ";
    cin >> entrada;
    codigoHistoria.setValor(entrada);

    cout << "Codigo do projeto: ";
    cin >> entrada;
    codigoProjeto.setValor(entrada);

    cout << "Codigo do plano: ";
    cin >> entrada;
    codigoPlano.setValor(entrada);

    servicoHistoria->moverParaSprint(codigoHistoria, codigoProjeto, codigoPlano);
    servicoPlano->registrarHistoria(servicoHistoria->ler(codigoHistoria));
    servicoPlano->associarHistoriaPlano(codigoHistoria, codigoPlano);

    cout << "Historia movida para sprint com sucesso." << endl;
}

void ControladoraAssociacoes::alterarEstadoHistoria() {
    Codigo codigoHistoria;
    Estado estado;
    string entrada;

    if (!servicoAutenticacao->isMestreScrum() && !servicoAutenticacao->isProductOwner()) {
        throw invalid_argument("Acesso permitido apenas para Mestre Scrum ou Proprietario de Produto.");
    }

    cout << "Codigo da historia: ";
    cin >> entrada;
    codigoHistoria.setValor(entrada);

    cout << "Novo estado (A FAZER / FAZENDO / FEITO): ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, entrada);
    estado.setValor(entrada);

    servicoHistoria->alterarEstado(codigoHistoria, estado);

    cout << "Estado alterado com sucesso." << endl;
}

void ControladoraAssociacoes::removerAssociacaoProjetoPessoa() {
    servicoAutenticacao->exigirProductOwner();

    Codigo codigoProjeto;
    Email emailPessoa;
    string entrada;

    cout << "Codigo do projeto: ";
    cin >> entrada;
    codigoProjeto.setValor(entrada);

    cout << "Email da pessoa: ";
    cin >> entrada;
    emailPessoa.setValor(entrada);

    servicoProjeto->removerAssociacaoProjetoPessoa(codigoProjeto, emailPessoa);

    cout << "Associacao projeto-pessoa removida com sucesso." << endl;
}
