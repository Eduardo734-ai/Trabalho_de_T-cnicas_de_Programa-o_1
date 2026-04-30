#include "../../include/servico/ServicoPlanoDeSprint.h"

#include "../../include/associacao/AssociacaoHistoriaPlano.h"

#include <stdexcept>

using namespace std;

ServicoPlanoDeSprint::ServicoPlanoDeSprint() {
}

void ServicoPlanoDeSprint::criar(const PlanoDeSprint &plano) {
    repositorioPlano.inserir(plano);
}

PlanoDeSprint ServicoPlanoDeSprint::ler(const Codigo &codigo) {
    return repositorioPlano.buscar(codigo);
}

void ServicoPlanoDeSprint::atualizar(const PlanoDeSprint &plano) {
    repositorioPlano.atualizar(plano);
}

void ServicoPlanoDeSprint::excluir(const Codigo &codigo) {
    repositorioPlano.remover(codigo);
}

void ServicoPlanoDeSprint::registrarHistoria(const HistoriaUsuario &historia) {
    containerHistorias.inserir(historia);
}

void ServicoPlanoDeSprint::associarHistoriaPlano(const Codigo &codigoHistoria, const Codigo &codigoPlano) {
    AssociacaoHistoriaPlano associacao;

    repositorioPlano.buscar(codigoPlano);
    containerHistorias.buscar(codigoHistoria);

    associacao.setCodigoHistoria(codigoHistoria);
    associacao.setCodigoPlano(codigoPlano);

    repositorioAssociacaoHistoriaPlano.inserir(associacao);
}

vector<HistoriaUsuario> ServicoPlanoDeSprint::listarHistoriasAssociadasPlano(const Codigo &codigoPlano) {
    vector<HistoriaUsuario> historias;
    vector<AssociacaoHistoriaPlano> associacoes;
    int i;

    repositorioPlano.buscar(codigoPlano);

    associacoes = repositorioAssociacaoHistoriaPlano.listar();

    for (i = 0; i < (int)associacoes.size(); i++) {
        if (associacoes[i].getCodigoPlano().getValor() == codigoPlano.getValor()) {
            historias.push_back(containerHistorias.buscar(associacoes[i].getCodigoHistoria()));
        }
    }

    return historias;
}
