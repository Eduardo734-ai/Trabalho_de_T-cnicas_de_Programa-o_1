#include "../../include/servico/ContainerAssociacaoHistoriaPessoa.h"
#include <stdexcept>

using namespace std;

ContainerAssociacaoHistoriaPessoa::ContainerAssociacaoHistoriaPessoa() {
}

void ContainerAssociacaoHistoriaPessoa::inserir(const AssociacaoHistoriaPessoa &associacao) {
    if(existe(associacao.getCodigoHistoria(), associacao.getEmailPessoa())) {
        throw invalid_argument("Associacao historia-pessoa ja cadastrada.");
    }

    associacoes.push_back(associacao);
}

void ContainerAssociacaoHistoriaPessoa::remover(const Codigo &codigoHistoria, const Email &emailPessoa) {
    int i;

    for (i = 0; i < (int)associacoes.size(); i++) {
        if (associacoes[i].getCodigoHistoria().getValor() == codigoHistoria.getValor() &&
            associacoes[i].getEmailPessoa().getValor() == emailPessoa.getValor()) {
            associacoes.erase(associacoes.begin() + i);
            return;
        }
    }

    throw invalid_argument("Associacao historia-pessoa nao encontrada.");
}

vector<AssociacaoHistoriaPessoa> ContainerAssociacaoHistoriaPessoa::listar() const {
    return associacoes;
}

bool ContainerAssociacaoHistoriaPessoa::existe(const Codigo &codigoHistoria, const Email &emailPessoa) const {
    int i;

    for (i = 0; i < (int)associacoes.size(); i++) {
        if (associacoes[i].getCodigoHistoria().getValor() == codigoHistoria.getValor() &&
            associacoes[i].getEmailPessoa().getValor() == emailPessoa.getValor()) {
            return true;
        }
    }

    return false;
}
