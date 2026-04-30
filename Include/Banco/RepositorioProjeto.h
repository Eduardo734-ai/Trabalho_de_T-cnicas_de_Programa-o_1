#ifndef REPOSITORIOPROJETO_H_INCLUDED
#define REPOSITORIOPROJETO_H_INCLUDED

#include "../entidade/Projeto.h"
#include "../dominio/Codigo.h"
#include "BancoDados.h"

class RepositorioProjeto {
private:
    BancoDados banco;

public:
    RepositorioProjeto();

    void inserir(const Projeto &projeto);
    Projeto buscar(const Codigo &codigo);
    void remover(const Codigo &codigo);
    void atualizar(const Projeto &projeto);
};

#endif // REPOSITORIOPROJETO_H_INCLUDED
