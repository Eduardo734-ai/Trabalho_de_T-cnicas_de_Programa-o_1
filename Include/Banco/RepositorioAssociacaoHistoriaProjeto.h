#ifndef REPOSITORIOASSOCIACAOHISTORIAPROJETO_H_INCLUDED
#define REPOSITORIOASSOCIACAOHISTORIAPROJETO_H_INCLUDED

#include <vector>
#include "../associacao/AssociacaoHistoriaProjeto.h"
#include "BancoDados.h"

class RepositorioAssociacaoHistoriaProjeto {
private:
    BancoDados banco;

public:
    RepositorioAssociacaoHistoriaProjeto();

    void inserir(const AssociacaoHistoriaProjeto &associacao);
    void remover(const Codigo &codigoHistoria, const Codigo &codigoProjeto);
    std::vector<AssociacaoHistoriaProjeto> listar();
    bool existe(const Codigo &codigoHistoria, const Codigo &codigoProjeto);
};

#endif // REPOSITORIOASSOCIACAOHISTORIAPROJETO_H_INCLUDED
