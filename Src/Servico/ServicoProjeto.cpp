#include"../../include/servico/ServicoProjeto.h"
#include"../../include/servico/UtilData.h"

#include"../../include/associacao/AssociacaoProjetoPessoa.h"
#include"../../include/associacao/AssociacaoHistoriaProjeto.h"
#include"../../include/associacao/AssociacaoPlanoProjeto.h"

#include"../../include/dominio/Estado.h"

#include<stdexcept>

using namespace std;

ServicoProjeto::ServicoProjeto(){
}

void ServicoProjeto::criar(const Projeto &projeto){
    container.inserir(projeto);
}

Projeto ServicoProjeto::ler(const Codigo &codigo){
    return container.buscar(codigo);
}

void ServicoProjeto::atualizar(const Projeto &projeto){
    container.remover(projeto.getCodigo());
    container.inserir(projeto);
}

void ServicoProjeto::excluir(const Codigo &codigo){
    vector<AssociacaoProjetoPessoa> associacoesPessoa;
    vector<AssociacaoHistoriaProjeto> associacoesHistoria;
    vector<AssociacaoPlanoProjeto> associacoesPlano;
    int i;

    associacoesPessoa = associacoesProjetoPessoa.listar();

    for(i = 0; i < (int)associacoesPessoa.size(); i++){
        if(associacoesPessoa[i].getCodigoProjeto().getValor() == codigo.getValor()){
            throw invalid_argument("Nao e possivel excluir projeto associado a pessoa.");
        }
    }

    associacoesHistoria = associacoesHistoriaProjeto.listar();

    for(i = 0; i < (int)associacoesHistoria.size(); i++){
        if(associacoesHistoria[i].getCodigoProjeto().getValor() == codigo.getValor()){
            throw invalid_argument("Nao e possivel excluir projeto com historias associadas.");
        }
    }

    associacoesPlano = associacoesPlanoProjeto.listar();

    for(i = 0; i < (int)associacoesPlano.size(); i++){
        if(associacoesPlano[i].getCodigoProjeto().getValor() == codigo.getValor()){
            throw invalid_argument("Nao e possivel excluir projeto com planos associados.");
        }
    }

    container.remover(codigo);
}

void ServicoProjeto::atualizarDadosProjeto(const Codigo &codigo, const Nome &nome, const Data &inicio, const Data &termino){
    Projeto projeto;

    projeto = container.buscar(codigo);

    projeto.setNome(nome);
    projeto.setDataInicio(inicio);
    projeto.setDataTermino(termino);

    atualizar(projeto);
}

void ServicoProjeto::registrarHistoria(const HistoriaUsuario &historia){
    containerHistorias.inserir(historia);
}

void ServicoProjeto::registrarPlano(const PlanoDeSprint &plano){
    containerPlanos.inserir(plano);
}

void ServicoProjeto::associarProjetoPessoa(const Codigo &codigoProjeto,const Email &emailPessoa){
    AssociacaoProjetoPessoa associacao;

    container.buscar(codigoProjeto);

    associacao.setCodigoProjeto(codigoProjeto);
    associacao.setEmailPessoa(emailPessoa);

    associacoesProjetoPessoa.inserir(associacao);
}

void ServicoProjeto::associarHistoriaProjeto(const Codigo &codigoHistoria,const Codigo &codigoProjeto){
    AssociacaoHistoriaProjeto associacao;

    container.buscar(codigoProjeto);

    containerHistorias.buscar(codigoHistoria);

    associacao.setCodigoHistoria(codigoHistoria);
    associacao.setCodigoProjeto(codigoProjeto);

    associacoesHistoriaProjeto.inserir(associacao);
}

void ServicoProjeto::associarPlanoProjeto(const Codigo &codigoPlano,const Codigo &codigoProjeto){
    AssociacaoPlanoProjeto associacao;

    container.buscar(codigoProjeto);

    containerPlanos.buscar(codigoPlano);

    associacao.setCodigoPlano(codigoPlano);
    associacao.setCodigoProjeto(codigoProjeto);

    associacoesPlanoProjeto.inserir(associacao);
}

void ServicoProjeto::criarAssociadoPessoa(const Projeto &projeto,const Pessoa &pessoa){
    if(pessoa.getPapel().getValor() != "MESTRE SCRUM"){
        throw invalid_argument("Projeto deve ser associado a um mestre Scrum.");
    }
    criar(projeto);

    associarProjetoPessoa(projeto.getCodigo(),pessoa.getEmail());
}

void ServicoProjeto::criarHistoriaAssociadaProjeto(HistoriaUsuario historia,const Codigo &codigoProjeto){
    Estado estadoInicial;

    container.buscar(codigoProjeto);

    estadoInicial.setValor("A FAZER");
    historia.setEstado(estadoInicial);

    registrarHistoria(historia);
    associarHistoriaProjeto(historia.getCodigo(),codigoProjeto);
}

void ServicoProjeto::criarPlanoAssociadoProjeto(const PlanoDeSprint &plano, const Codigo &codigoProjeto) {
    Projeto projeto;
    vector<PlanoDeSprint> planos;
    int duracaoProjeto;
    int somaCapacidades;
    int i;

    projeto = container.buscar(codigoProjeto);

    duracaoProjeto = UtilData::calcularDiferencaDias(
        projeto.getDataInicio(),
        projeto.getDataTermino()
    );

    planos = listarPlanosAssociadosProjeto(codigoProjeto);

    somaCapacidades = 0;

    for (i = 0; i < (int)planos.size(); i++) {
        somaCapacidades = somaCapacidades + planos[i].getCapacidade().getValor();
    }

    somaCapacidades = somaCapacidades + plano.getCapacidade().getValor();

    if (somaCapacidades > duracaoProjeto) {
        throw invalid_argument("Soma das capacidades dos planos excede a duracao do projeto.");
    }

    registrarPlano(plano);
    associarPlanoProjeto(plano.getCodigo(), codigoProjeto);
}

vector<Projeto> ServicoProjeto::listarProjetosAssociadosPessoa(const Email &email) {
    vector<Projeto> projetos;
    vector<AssociacaoProjetoPessoa> associacoes;

    associacoes = associacoesProjetoPessoa.listar();

    for (int i = 0; i < (int)associacoes.size(); i++) {
        if (associacoes[i].getEmailPessoa().getValor() == email.getValor()) {
            projetos.push_back(container.buscar(associacoes[i].getCodigoProjeto()));
        }
    }

    return projetos;
}

vector<HistoriaUsuario> ServicoProjeto::listarHistoriasAssociadasProjeto(const Codigo &codigoProjeto){
    vector<HistoriaUsuario> historias;
    vector<AssociacaoHistoriaProjeto> associacoes;
    int i;

    associacoes = associacoesHistoriaProjeto.listar();

    for (i=0;i<(int)associacoes.size();i++) {
        if (associacoes[i].getCodigoProjeto().getValor() == codigoProjeto.getValor()) {
            historias.push_back(containerHistorias.buscar(associacoes[i].getCodigoHistoria()));
        }
    }
    return historias;
}

vector<PlanoDeSprint> ServicoProjeto::listarPlanosAssociadosProjeto(const Codigo &codigoProjeto){
    vector<PlanoDeSprint> planos;
    vector<AssociacaoPlanoProjeto> associacoes;
    int i;

    associacoes = associacoesPlanoProjeto.listar();
    for (i = 0; i < (int)associacoes.size(); i++) {
        if (associacoes[i].getCodigoProjeto().getValor() == codigoProjeto.getValor()) {
            planos.push_back(containerPlanos.buscar(associacoes[i].getCodigoPlano()));
        }
    }
    return planos;
}
