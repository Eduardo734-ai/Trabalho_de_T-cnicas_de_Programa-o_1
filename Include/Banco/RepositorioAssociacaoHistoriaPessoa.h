#ifndef REPOSITORIOASSOCIACAOHISTORIAPESSOA_H_INCLUDED
#define REPOSITORIOASSOCIACAOHISTORIAPESSOA_H_INCLUDED

#include <vector>
#include "../associacao/AssociacaoHistoriaPessoa.h"
#include "BancoDados.h"

class RepositorioAssociacaoHistoriaPessoa {
private:
    BancoDados banco;

public:
    RepositorioAssociacaoHistoriaPessoa();

    void inserir(const AssociacaoHistoriaPessoa &associacao);
    void remover(const Codigo &codigoHistoria, const Email &emailPessoa);
    std::vector<AssociacaoHistoriaPessoa> listar();
    bool existe(const Codigo &codigoHistoria, const Email &emailPessoa);
};

#endif // REPOSITORIOASSOCIACAOHISTORIAPESSOA_H_INCLUDED
