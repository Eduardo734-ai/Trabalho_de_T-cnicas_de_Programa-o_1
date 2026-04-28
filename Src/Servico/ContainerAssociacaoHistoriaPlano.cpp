#include "../../include/servico/ContainerAssociacaoHistoriaPlano.h"
#include <stdexcept>

using namespace std;

ContainerAssociacaoHistoriaPlano::ContainerAssociacaoHistoriaPlano() {
}

void ContainerAssociacaoHistoriaPlano::inserir(const AssociacaoHistoriaPlano &associacao) {
    if (existe(associacao.getCodigoHistoria(), associacao.getCodigoPlano())) {
        throw invalid_argument("Associacao historia-plano ja cadastrada.");
    }

    associacoes.push_back(associacao);
}

void ContainerAssociacaoHistoriaPlano::remover(const Codigo &codigoHistoria, const Codigo &codigoPlano) {
    int i;

    for (i = 0; i < (int)associacoes.size(); i++) {
        if (associacoes[i].getCodigoHistoria().getValor() == codigoHistoria.getValor() &&
            associacoes[i].getCodigoPlano().getValor() == codigoPlano.getValor()) {
            associacoes.erase(associacoes.begin() + i);
            return;
        }
    }

    throw invalid_argument("Associacao historia-plano nao encontrada.");
}

vector<AssociacaoHistoriaPlano> ContainerAssociacaoHistoriaPlano::listar() const {
    return associacoes;
}

bool ContainerAssociacaoHistoriaPlano::existe(const Codigo &codigoHistoria, const Codigo &codigoPlano) const {
    int i;

    for (i = 0; i < (int)associacoes.size(); i++) {
        if (associacoes[i].getCodigoHistoria().getValor() == codigoHistoria.getValor() &&
            associacoes[i].getCodigoPlano().getValor() == codigoPlano.getValor()) {
            return true;
        }
    }

    return false;
}
