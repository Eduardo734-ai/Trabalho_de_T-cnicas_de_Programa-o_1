#ifndef REPOSITORIOPESSOA_H_INCLUDED
#define REPOSITORIOPESSOA_H_INCLUDED

#include "../entidade/Pessoa.h"
#include "BancoDados.h"

class RepositorioPessoa {
private:
    BancoDados banco;

public:
    RepositorioPessoa();

    void inserir(const Pessoa &pessoa);
    Pessoa buscar(const Email &email);
};

#endif // REPOSITORIOPESSOA_H_INCLUDED
