#ifndef REPOSITORIOASSOCIACAOPLANOPROJETO_H_INCLUDED
#define REPOSITORIOASSOCIACAOPLANOPROJETO_H_INCLUDED

#include <vector>
#include "../associacao/AssociacaoPlanoProjeto.h"
#include "BancoDados.h"

class RepositorioAssociacaoPlanoProjeto {
private:
    BancoDados banco;

public:
    RepositorioAssociacaoPlanoProjeto();

    void inserir(const AssociacaoPlanoProjeto &associacao);
    void remover(const Codigo &codigoPlano, const Codigo &codigoProjeto);
    std::vector<AssociacaoPlanoProjeto> listar();
    bool existe(const Codigo &codigoPlano, const Codigo &codigoProjeto);
};


#endif // REPOSITORIOASSOCIACAOPLANOPROJETO_H_INCLUDED
