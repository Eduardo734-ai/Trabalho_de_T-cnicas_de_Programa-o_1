#ifndef REPOSITORIOASSOCIACAOPROJETOPESSOA_H_INCLUDED
#define REPOSITORIOASSOCIACAOPROJETOPESSOA_H_INCLUDED


#include <vector>
#include "../associacao/AssociacaoProjetoPessoa.h"
#include "BancoDados.h"

class RepositorioAssociacaoProjetoPessoa {
private:
    BancoDados banco;

public:
    RepositorioAssociacaoProjetoPessoa();

    void inserir(const AssociacaoProjetoPessoa &associacao);
    void remover(const Codigo &codigoProjeto, const Email &emailPessoa);
    std::vector<AssociacaoProjetoPessoa> listar();
    bool existe(const Codigo &codigoProjeto, const Email &emailPessoa);
};

#endif // REPOSITORIOASSOCIACAOPROJETOPESSOA_H_INCLUDED
