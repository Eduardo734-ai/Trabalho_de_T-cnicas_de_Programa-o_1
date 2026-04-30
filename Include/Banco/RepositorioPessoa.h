#ifndef REPOSITORIOPESSOA_H_INCLUDED
#define REPOSITORIOPESSOA_H_INCLUDED

#include "../entidade/Pessoa.h"
#include "../dominio/Email.h"
#include "BancoDados.h"

class RepositorioPessoa {
private:
    BancoDados banco;

public:
    RepositorioPessoa();

    void inserir(const Pessoa &pessoa);
    Pessoa buscar(const Email &email);
    void atualizar(const Pessoa &pessoa);
    void remover(const Email &email);
};

#endif // REPOSITORIOPESSOA_H_INCLUDED
