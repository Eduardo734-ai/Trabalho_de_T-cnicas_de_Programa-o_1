#include "../../Include/Apresentacao/ControladoraPlanoDeSprint.h"

#include <iostream>
#include <stdexcept>
#include <limits>

using namespace std;

ControladoraPlanoDeSprint::ControladoraPlanoDeSprint(
    ServicoPlanoDeSprint* servicoPlano,
    ServicoProjeto* servicoProjeto,
    ServicoHistoriaUsuario* servicoHistoria
) {
    this->servicoPlano = servicoPlano;
    this->servicoProjeto = servicoProjeto;
    this->servicoHistoria = servicoHistoria;
}

void ControladoraPlanoDeSprint::menuPlano() {
    cout << endl;
    cout << "===== MENU PLANO DE SPRINT =====" << endl;
    cout << "1 - Criar plano associado a projeto" << endl;
    cout << "2 - Ler plano" << endl;
    cout << "3 - Atualizar plano" << endl;
    cout << "4 - Excluir plano" << endl;
    cout << "0 - Voltar" << endl;
    cout << "Opcao: ";
}

void ControladoraPlanoDeSprint::executar() {
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

void ControladoraPlanoDeSprint::criarPlano() {
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

    /*
        Primeiro cria o plano, porque a função criarPlanoAssociadoProjeto
        procura o plano no banco/repositório antes de associar.
    */
    servicoPlano->criar(plano);

    try {
        /*
            Agora tenta associar o plano ao projeto.

            Se a regra de negócio falhar, por exemplo:
            "Soma das capacidades dos planos excede a duracao do projeto",
            o catch remove o plano que acabou de ser criado.
        */
        servicoProjeto->criarPlanoAssociadoProjeto(plano, codigoProjeto);

        /*
            Só registra no serviço de histórias depois que a associação
            com o projeto deu certo.
        */
        servicoHistoria->registrarPlano(plano);

        cout << "Plano criado com sucesso." << endl;
    }
    catch (invalid_argument &erro) {
        /*
            Desfaz o cadastro do plano para ele não ficar salvo no banco
            quando a associação falhar.
        */
        servicoPlano->excluir(codigo);

        throw;
    }
}

void ControladoraPlanoDeSprint::lerPlano() {
    Codigo codigo;
    PlanoDeSprint plano;
    string entrada;

    cout << "Codigo do plano: ";
    cin >> entrada;
    codigo.setValor(entrada);

    plano = servicoPlano->ler(codigo);

    cout << "Codigo: " << plano.getCodigo().getValor() << endl;
    cout << "Nome: " << plano.getNome().getValor() << endl;
    cout << "Inicio: " << plano.getDataInicio().getValor() << endl;
    cout << "Termino: " << plano.getDataTermino().getValor() << endl;
    cout << "Capacidade: " << plano.getCapacidade().getValor() << endl;
}

void ControladoraPlanoDeSprint::atualizarPlano() {
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

    servicoPlano->atualizar(plano);

    cout << "Plano atualizado com sucesso." << endl;
}

void ControladoraPlanoDeSprint::excluirPlano() {
    Codigo codigo;
    string entrada;

    cout << "Codigo do plano: ";
    cin >> entrada;
    codigo.setValor(entrada);

    servicoPlano->excluir(codigo);

    cout << "Plano excluido com sucesso." << endl;
}
