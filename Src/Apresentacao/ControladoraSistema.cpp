#include "../../include/apresentacao/ControladoraSistema.h"

#include <iostream>
#include <stdexcept>
#include <vector>
#include <limits>

using namespace std;

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

void ControladoraSistema::menuPessoa() {
    cout << endl;
    cout << "===== MENU PESSOA =====" << endl;
    cout << "1 - Criar pessoa" << endl;
    cout << "2 - Ler pessoa" << endl;
    cout << "3 - Atualizar pessoa" << endl;
    cout << "4 - Excluir pessoa" << endl;
    cout << "0 - Voltar" << endl;
    cout << "Opcao: ";
}

void ControladoraSistema::menuProjeto() {
    cout << endl;
    cout << "===== MENU PROJETO =====" << endl;
    cout << "1 - Criar projeto associado a Mestre Scrum" << endl;
    cout << "2 - Ler projeto" << endl;
    cout << "3 - Atualizar projeto" << endl;
    cout << "4 - Excluir projeto" << endl;
    cout << "0 - Voltar" << endl;
    cout << "Opcao: ";
}

void ControladoraSistema::menuPlano() {
    cout << endl;
    cout << "===== MENU PLANO DE SPRINT =====" << endl;
    cout << "1 - Criar plano associado a projeto" << endl;
    cout << "2 - Ler plano" << endl;
    cout << "3 - Atualizar plano" << endl;
    cout << "4 - Excluir plano" << endl;
    cout << "0 - Voltar" << endl;
    cout << "Opcao: ";
}

void ControladoraSistema::menuHistoria() {
    cout << endl;
    cout << "===== MENU HISTORIA DE USUARIO =====" << endl;
    cout << "1 - Criar historia associada a projeto" << endl;
    cout << "2 - Ler historia" << endl;
    cout << "3 - Atualizar historia" << endl;
    cout << "4 - Excluir historia" << endl;
    cout << "0 - Voltar" << endl;
    cout << "Opcao: ";
}

void ControladoraSistema::menuAssociacoes() {
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
    cout << "0 - Voltar" << endl;
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
                        controlarPessoa();
                        break;

                    case 2:
                        controlarProjeto();
                        break;

                    case 3:
                        controlarPlano();
                        break;

                    case 4:
                        controlarHistoria();
                        break;

                    case 5:
                        controlarAssociacoes();
                        break;

                    case 6:
                        alterarEstadoHistoria();
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

void ControladoraSistema::controlarPessoa() {
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

void ControladoraSistema::controlarProjeto() {
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

void ControladoraSistema::controlarPlano() {
    int opcao;

    do {
        menuPlano();
        cin >> opcao;

        try {
            switch (opcao) {
                case 1:
                    criarPlano();
                    break;

                case 2:
                    lerPlano();
                    break;

                case 3:
                    atualizarPlano();
                    break;

                case 4:
                    excluirPlano();
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

void ControladoraSistema::controlarHistoria() {
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

void ControladoraSistema::controlarAssociacoes() {
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

void ControladoraSistema::criarPessoa() {
    executarCadastro();
}

void ControladoraSistema::lerPessoa() {
    Email email;
    string entrada;
    Pessoa pessoa;

    cout << "Email da pessoa: ";
    cin >> entrada;
    email.setValor(entrada);

    pessoa = servicoPessoa.ler(email);

    cout << "Email: " << pessoa.getEmail().getValor() << endl;
    cout << "Nome: " << pessoa.getNome().getValor() << endl;
    cout << "Papel: " << pessoa.getPapel().getValor() << endl;
}

void ControladoraSistema::atualizarPessoa() {
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

    servicoPessoa.atualizar(pessoa);

    cout << "Pessoa atualizada com sucesso." << endl;
}

void ControladoraSistema::excluirPessoa() {
    Email email;
    string entrada;

    cout << "Email da pessoa: ";
    cin >> entrada;
    email.setValor(entrada);

    servicoPessoa.excluir(email);

    cout << "Pessoa excluida com sucesso." << endl;
}

void ControladoraSistema::criarProjeto() {
    servicoAutenticacao.exigirProductOwner();

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

    mestre = servicoPessoa.ler(emailMestre);

    projeto.setCodigo(codigo);
    projeto.setNome(nome);
    projeto.setDataInicio(inicio);
    projeto.setDataTermino(termino);

    servicoProjeto.criarAssociadoPessoa(projeto, mestre);

    cout << "Projeto criado com sucesso." << endl;
}

void ControladoraSistema::lerProjeto() {
    Codigo codigo;
    Projeto projeto;
    string entrada;

    cout << "Codigo do projeto: ";
    cin >> entrada;
    codigo.setValor(entrada);

    projeto = servicoProjeto.ler(codigo);

    cout << "Codigo: " << projeto.getCodigo().getValor() << endl;
    cout << "Nome: " << projeto.getNome().getValor() << endl;
    cout << "Inicio: " << projeto.getDataInicio().getValor() << endl;
    cout << "Termino: " << projeto.getDataTermino().getValor() << endl;
}

void ControladoraSistema::atualizarProjeto() {
    servicoAutenticacao.exigirProductOwner();

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

    servicoProjeto.atualizar(projeto);

    cout << "Projeto atualizado com sucesso." << endl;
}

void ControladoraSistema::excluirProjeto() {
    servicoAutenticacao.exigirProductOwner();

    Codigo codigo;
    string entrada;

    cout << "Codigo do projeto: ";
    cin >> entrada;
    codigo.setValor(entrada);

    servicoProjeto.excluir(codigo);

    cout << "Projeto excluido com sucesso." << endl;
}

void ControladoraSistema::criarPlano() {
    servicoAutenticacao.exigirMestreScrum();

    Codigo codigo;
    Codigo codigoProjeto;
    Nome nome;
    Data inicio;
    Data termino;
    Tempo capacidade;
    PlanoDeSprint plano;
    string entrada;
    int valorInteiro;

    cout << "Codigo do plano: ";
    cin >> entrada;
    codigo.setValor(entrada);

    cout << "Nome do plano: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, entrada);
    nome.setValor(entrada);

    cout << "Data inicio: ";
    cin >> entrada;
    inicio.setValor(entrada);

    cout << "Data termino: ";
    cin >> entrada;
    termino.setValor(entrada);

    cout << "Capacidade: ";
    cin >> valorInteiro;
    capacidade.setValor(valorInteiro);

    cout << "Codigo do projeto associado: ";
    cin >> entrada;
    codigoProjeto.setValor(entrada);

    plano.setCodigo(codigo);
    plano.setNome(nome);
    plano.setDataInicio(inicio);
    plano.setDataTermino(termino);
    plano.setCapacidade(capacidade);

    servicoPlano.criar(plano);
    servicoProjeto.criarPlanoAssociadoProjeto(plano, codigoProjeto);
    servicoHistoria.registrarPlano(plano);

    cout << "Plano criado com sucesso." << endl;
}

void ControladoraSistema::lerPlano() {
    Codigo codigo;
    PlanoDeSprint plano;
    string entrada;

    cout << "Codigo do plano: ";
    cin >> entrada;
    codigo.setValor(entrada);

    plano = servicoPlano.ler(codigo);

    cout << "Codigo: " << plano.getCodigo().getValor() << endl;
    cout << "Nome: " << plano.getNome().getValor() << endl;
    cout << "Inicio: " << plano.getDataInicio().getValor() << endl;
    cout << "Termino: " << plano.getDataTermino().getValor() << endl;
    cout << "Capacidade: " << plano.getCapacidade().getValor() << endl;
}

void ControladoraSistema::atualizarPlano() {
    servicoAutenticacao.exigirMestreScrum();

    Codigo codigo;
    Nome nome;
    Data inicio;
    Data termino;
    Tempo capacidade;
    PlanoDeSprint plano;
    string entrada;
    int valorInteiro;

    cout << "Codigo do plano: ";
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

    cout << "Nova capacidade: ";
    cin >> valorInteiro;
    capacidade.setValor(valorInteiro);

    plano.setCodigo(codigo);
    plano.setNome(nome);
    plano.setDataInicio(inicio);
    plano.setDataTermino(termino);
    plano.setCapacidade(capacidade);

    servicoPlano.atualizar(plano);

    cout << "Plano atualizado com sucesso." << endl;
}

void ControladoraSistema::excluirPlano() {
    servicoAutenticacao.exigirMestreScrum();

    Codigo codigo;
    string entrada;

    cout << "Codigo do plano: ";
    cin >> entrada;
    codigo.setValor(entrada);

    servicoPlano.excluir(codigo);

    cout << "Plano excluido com sucesso." << endl;
}

void ControladoraSistema::criarHistoria() {
    servicoAutenticacao.exigirProductOwner();

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

    servicoHistoria.criar(historia);
    servicoProjeto.criarHistoriaAssociadaProjeto(historia, codigoProjeto);

    cout << "Historia criada com sucesso." << endl;
}

void ControladoraSistema::lerHistoria() {
    Codigo codigo;
    HistoriaUsuario historia;
    string entrada;

    cout << "Codigo da historia: ";
    cin >> entrada;
    codigo.setValor(entrada);

    historia = servicoHistoria.ler(codigo);

    cout << "Codigo: " << historia.getCodigo().getValor() << endl;
    cout << "Nome: " << historia.getNome().getValor() << endl;
    cout << "Papel: " << historia.getPapel().getValor() << endl;
    cout << "Acao: " << historia.getAcao().getValor() << endl;
    cout << "Valor: " << historia.getValor().getValor() << endl;
    cout << "Estimativa: " << historia.getEstimativa().getValor() << endl;
    cout << "Prioridade: " << historia.getPrioridade().getValor() << endl;
    cout << "Estado: " << historia.getEstado().getValor() << endl;
}

void ControladoraSistema::atualizarHistoria() {
    servicoAutenticacao.exigirProductOwner();

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

    historiaAtual = servicoHistoria.ler(codigo);
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

    servicoHistoria.atualizar(historiaNova);

    cout << "Historia atualizada com sucesso." << endl;
}

void ControladoraSistema::excluirHistoria() {
    servicoAutenticacao.exigirProductOwner();

    Codigo codigo;
    string entrada;

    cout << "Codigo da historia: ";
    cin >> entrada;
    codigo.setValor(entrada);

    servicoHistoria.excluir(codigo);

    cout << "Historia excluida com sucesso." << endl;
}

void ControladoraSistema::associarHistoriaPessoa() {
    servicoAutenticacao.exigirMestreScrum();

    Codigo codigoHistoria;
    Email emailPessoa;
    string entrada;

    cout << "Codigo da historia: ";
    cin >> entrada;
    codigoHistoria.setValor(entrada);

    cout << "Email da pessoa: ";
    cin >> entrada;
    emailPessoa.setValor(entrada);

    servicoPessoa.ler(emailPessoa);
    servicoHistoria.associarPessoa(codigoHistoria, emailPessoa);

    cout << "Historia associada a pessoa com sucesso." << endl;
}

void ControladoraSistema::removerAssociacaoHistoriaPessoa() {
    servicoAutenticacao.exigirMestreScrum();

    Codigo codigoHistoria;
    Email emailPessoa;
    string entrada;

    cout << "Codigo da historia: ";
    cin >> entrada;
    codigoHistoria.setValor(entrada);

    cout << "Email da pessoa: ";
    cin >> entrada;
    emailPessoa.setValor(entrada);

    servicoHistoria.removerAssociacaoPessoa(codigoHistoria, emailPessoa);

    cout << "Associacao removida com sucesso." << endl;
}

void ControladoraSistema::listarProjetosPessoa() {
    Email email;
    string entrada;
    vector<Projeto> projetos;

    cout << "Email da pessoa: ";
    cin >> entrada;
    email.setValor(entrada);

    projetos = servicoProjeto.listarProjetosAssociadosPessoa(email);

    cout << "Projetos associados: " << projetos.size() << endl;

    for (int i = 0; i < (int)projetos.size(); i++) {
        cout << "Codigo: " << projetos[i].getCodigo().getValor() << endl;
        cout << "Nome: " << projetos[i].getNome().getValor() << endl;
        cout << "-----" << endl;
    }
}

void ControladoraSistema::listarHistoriasProjeto() {
    Codigo codigoProjeto;
    string entrada;
    vector<HistoriaUsuario> historias;

    cout << "Codigo do projeto: ";
    cin >> entrada;
    codigoProjeto.setValor(entrada);

    historias = servicoProjeto.listarHistoriasAssociadasProjeto(codigoProjeto);

    cout << "Historias associadas: " << historias.size() << endl;

    for (int i = 0; i < (int)historias.size(); i++) {
        cout << "Codigo: " << historias[i].getCodigo().getValor() << endl;
        cout << "Nome: " << historias[i].getNome().getValor() << endl;
        cout << "Estado: " << historias[i].getEstado().getValor() << endl;
        cout << "-----" << endl;
    }
}

void ControladoraSistema::listarPlanosProjeto() {
    Codigo codigoProjeto;
    string entrada;
    vector<PlanoDeSprint> planos;

    cout << "Codigo do projeto: ";
    cin >> entrada;
    codigoProjeto.setValor(entrada);

    planos = servicoProjeto.listarPlanosAssociadosProjeto(codigoProjeto);

    cout << "Planos associados: " << planos.size() << endl;

    for (int i = 0; i < (int)planos.size(); i++) {
        cout << "Codigo: " << planos[i].getCodigo().getValor() << endl;
        cout << "Nome: " << planos[i].getNome().getValor() << endl;
        cout << "Capacidade: " << planos[i].getCapacidade().getValor() << endl;
        cout << "-----" << endl;
    }
}

void ControladoraSistema::listarHistoriasPlano() {
    Codigo codigoPlano;
    string entrada;
    vector<HistoriaUsuario> historias;

    cout << "Codigo do plano: ";
    cin >> entrada;
    codigoPlano.setValor(entrada);

    historias = servicoHistoria.listarHistoriasAssociadasPlano(codigoPlano);

    cout << "Historias associadas ao plano: " << historias.size() << endl;

    for (int i = 0; i < (int)historias.size(); i++) {
        cout << "Codigo: " << historias[i].getCodigo().getValor() << endl;
        cout << "Nome: " << historias[i].getNome().getValor() << endl;
        cout << "Estado: " << historias[i].getEstado().getValor() << endl;
        cout << "-----" << endl;
    }
}

void ControladoraSistema::listarHistoriasPessoa() {
    Email emailPessoa;
    string entrada;
    vector<HistoriaUsuario> historias;

    cout << "Email da pessoa: ";
    cin >> entrada;
    emailPessoa.setValor(entrada);

    historias = servicoHistoria.listarHistoriasAssociadasPessoa(emailPessoa);

    cout << "Historias associadas a pessoa: " << historias.size() << endl;

    for (int i = 0; i < (int)historias.size(); i++) {
        cout << "Codigo: " << historias[i].getCodigo().getValor() << endl;
        cout << "Nome: " << historias[i].getNome().getValor() << endl;
        cout << "Estado: " << historias[i].getEstado().getValor() << endl;
        cout << "-----" << endl;
    }
}

void ControladoraSistema::moverHistoriaParaSprint() {
    servicoAutenticacao.exigirMestreScrum();

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

    servicoHistoria.moverParaSprint(codigoHistoria, codigoProjeto, codigoPlano);
    servicoPlano.registrarHistoria(servicoHistoria.ler(codigoHistoria));
    servicoPlano.associarHistoriaPlano(codigoHistoria, codigoPlano);

    cout << "Historia movida para sprint com sucesso." << endl;
}

void ControladoraSistema::alterarEstadoHistoria() {
    Codigo codigoHistoria;
    Estado estado;
    string entrada;

    if (!servicoAutenticacao.isMestreScrum() && !servicoAutenticacao.isProductOwner()) {
        throw invalid_argument("Acesso permitido apenas para Mestre Scrum ou Proprietario de Produto.");
    }

    cout << "Codigo da historia: ";
    cin >> entrada;
    codigoHistoria.setValor(entrada);

    cout << "Novo estado (A FAZER / FAZENDO / FEITO): ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, entrada);
    estado.setValor(entrada);

    servicoHistoria.alterarEstado(codigoHistoria, estado);

    cout << "Estado alterado com sucesso." << endl;
}
