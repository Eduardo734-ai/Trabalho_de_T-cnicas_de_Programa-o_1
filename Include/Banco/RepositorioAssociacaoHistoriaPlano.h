#ifndef REPOSITORIOASSOCIACAOHISTORIAPLANO_H_INCLUDED
#define REPOSITORIOASSOCIACAOHISTORIAPLANO_H_INCLUDED

#include <vector>
#include "../associacao/AssociacaoHistoriaPlano.h"
#include "BancoDados.h"

class RepositorioAssociacaoHistoriaPlano {
private:
    BancoDados banco;

public:
    RepositorioAssociacaoHistoriaPlano();

    void inserir(const AssociacaoHistoriaPlano &associacao);
    void remover(const Codigo &codigoHistoria, const Codigo &codigoPlano);
    std::vector<AssociacaoHistoriaPlano> listar();
    bool existe(const Codigo &codigoHistoria, const Codigo &codigoPlano);
};

#endif // REPOSITORIOASSOCIACAOHISTORIAPLANO_H_INCLUDED
