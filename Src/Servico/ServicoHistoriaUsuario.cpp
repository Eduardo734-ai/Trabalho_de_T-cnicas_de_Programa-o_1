#include"../../include/servico/ServicoHistoriaUsuario.h"

#include"../../include/associacao/AssociacaoHistoriaPessoa.h"
#include"../../include/associacao/AssociacaoHistoriaPlano.h"

#include<stdexcept>

using namespace std;

ServicoHistoriaUsuario::ServicoHistoriaUsuario(){
}

void ServicoHistoriaUsuario::criar(const HistoriaUsuario &historia){
    container.inserir(historia);
}

HistoriaUsuario ServicoHistoriaUsuario::ler(const Codigo &codigo){
    return container.buscar(codigo);
}

void ServicoHistoriaUsuario::atualizar(const HistoriaUsuario &historia){
    container.remover(historia.getCodigo());
    container.inserir(historia);
}

void ServicoHistoriaUsuario::excluir(const Codigo &codigo){
    vector<AssociacaoHistoriaPessoa> associacoesPessoa;
    vector<AssociacaoHistoriaPlano> associacoesPlano;
    int i;

    associacoesPessoa = associacoesHistoriaPessoa.listar();

    for(i = 0; i < (int)associacoesPessoa.size(); i++){
        if(associacoesPessoa[i].getCodigoHistoria().getValor() == codigo.getValor()){
            throw invalid_argument("Nao e possivel excluir historia associada a pessoa.");
        }
    }

    associacoesPlano = associacoesHistoriaPlano.listar();

    for(i = 0; i < (int)associacoesPlano.size(); i++){
        if(associacoesPlano[i].getCodigoHistoria().getValor() == codigo.getValor()){
            throw invalid_argument("Nao e possivel excluir historia associada a plano de sprint.");
        }
    }

    container.remover(codigo);
}

void ServicoHistoriaUsuario::atualizarDadosHistoria(const Codigo &codigo,const Nome &nome,const Papel &papel,const Texto &acao,const Texto &valor,const Tempo &estimativa,const Prioridade &prioridade){
    HistoriaUsuario historia;

    historia = container.buscar(codigo);

    historia.setNome(nome);
    historia.setPapel(papel);
    historia.setAcao(acao);
    historia.setValor(valor);
    historia.setEstimativa(estimativa);
    historia.setPrioridade(prioridade);

    atualizar(historia);
}

void ServicoHistoriaUsuario::registrarPlano(const PlanoDeSprint &plano) {
    containerPlanos.inserir(plano);
}

void ServicoHistoriaUsuario::associarPessoa(const Codigo &codigoHistoria,const Email &emailPessoa){
    AssociacaoHistoriaPessoa associacao;

    container.buscar(codigoHistoria);

    associacao.setCodigoHistoria(codigoHistoria);
    associacao.setEmailPessoa(emailPessoa);

    associacoesHistoriaPessoa.inserir(associacao);
}

void ServicoHistoriaUsuario::removerAssociacaoPessoa(const Codigo &codigoHistoria, const Email &emailPessoa) {
    container.buscar(codigoHistoria);

    associacoesHistoriaPessoa.remover(codigoHistoria,emailPessoa);
}

vector<HistoriaUsuario> ServicoHistoriaUsuario::listarHistoriasAssociadasPessoa(const Email &emailPessoa) {
    vector<HistoriaUsuario> historias;
    vector<AssociacaoHistoriaPessoa> associacoes;

    int i;

    for(i=0;(int)associacoes.size();i++){
        if(associacoes[i].getEmailPessoa().getValor() == emailPessoa.getValor()){
            historias.push_back(container.buscar(associacoes[i].getCodigoHistoria()));
        }
    }
    return historias;
}

vector<HistoriaUsuario> ServicoHistoriaUsuario::listarHistoriasAssociadasPlano(const Codigo &codigoPlano) {
    vector<HistoriaUsuario> historias;
    vector<AssociacaoHistoriaPlano> associacoes;
    int i;

    associacoes = associacoesHistoriaPlano.listar();

    for (i = 0; i < (int)associacoes.size(); i++) {
        if (associacoes[i].getCodigoPlano().getValor() == codigoPlano.getValor()) {
            historias.push_back(container.buscar(associacoes[i].getCodigoHistoria()));
        }
    }

    return historias;
}

void ServicoHistoriaUsuario::moverParaSprint(const Codigo &codigoHistoria,
                                             const Codigo &codigoProjeto,
                                             const Codigo &codigoPlano) {
    HistoriaUsuario historia;
    PlanoDeSprint plano;
    vector<HistoriaUsuario> historiasDoPlano;
    AssociacaoHistoriaPlano associacao;

    int somaEstimativas;
    int i;

    historia = container.buscar(codigoHistoria);
    plano = containerPlanos.buscar(codigoPlano);

    historiasDoPlano = listarHistoriasAssociadasPlano(codigoPlano);

    somaEstimativas = 0;

    for (i = 0; i < (int)historiasDoPlano.size(); i++) {
        somaEstimativas = somaEstimativas + historiasDoPlano[i].getEstimativa().getValor();
    }

    somaEstimativas = somaEstimativas + historia.getEstimativa().getValor();

    if (somaEstimativas > plano.getCapacidade().getValor()) {
        throw invalid_argument("Soma das estimativas excede a capacidade do plano de sprint.");
    }

    associacao.setCodigoHistoria(codigoHistoria);
    associacao.setCodigoPlano(codigoPlano);

    associacoesHistoriaPlano.inserir(associacao);
}

void ServicoHistoriaUsuario::alterarEstado(const Codigo &codigoHistoria, const Estado &estado) {
    HistoriaUsuario historia;

    historia = container.buscar(codigoHistoria);
    historia.setEstado(estado);

    atualizar(historia);
}
