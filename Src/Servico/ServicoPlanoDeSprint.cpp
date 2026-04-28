#include"../../include/servico/ServicoPlanoDeSprint.h"
#include"../../include/associacao/AssociacaoHistoriaPlano.h"
#include<stdexcept>

using namespace std;

ServicoPlanoDeSprint::ServicoPlanoDeSprint(){
}

void ServicoPlanoDeSprint::criar(const PlanoDeSprint &plano){
    container.inserir(plano);
}

PlanoDeSprint ServicoPlanoDeSprint::ler(const Codigo &codigo){
    return container.buscar(codigo);
}

void ServicoPlanoDeSprint::atualizar(const PlanoDeSprint &plano){
    container.remover(plano.getCodigo());
    container.inserir(plano);
}

void ServicoPlanoDeSprint::excluir(const Codigo &codigo){
    container.remover(codigo);
}

void ServicoPlanoDeSprint::registrarHistoria(const HistoriaUsuario &historia){
    containerHistorias.inserir(historia);
}

void ServicoPlanoDeSprint::associarHistoriaPlano(const Codigo &codigoHistoria, const Codigo &codigoPlano) {
    AssociacaoHistoriaPlano associacao;

    associacao.setCodigoHistoria(codigoHistoria);
    associacao.setCodigoPlano(codigoPlano);

    associacoesHistoriaPlano.inserir(associacao);
}

vector<HistoriaUsuario>ServicoPlanoDeSprint::listarHistoriasAssociadasPlano(const Codigo &codigoPlano){
    vector<HistoriaUsuario> historias;
    vector<AssociacaoHistoriaPlano> associacoes;
    int i;

    associacoes = associacoesHistoriaPlano.listar();

    for (i = 0; i < (int)associacoes.size(); i++) {
        if (associacoes[i].getCodigoPlano().getValor() == codigoPlano.getValor()) {
            historias.push_back(containerHistorias.buscar(associacoes[i].getCodigoHistoria()));
        }
    }
    return historias;
}
