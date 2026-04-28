#ifndef CONTAINERPESSOAS_H_INCLUDED
#define CONTAINERPESSOAS_H_INCLUDED

#include<vector>
#include"entidade/Pessoa.h"
#include"dominio/Email.h"

class ContainerPessoas{
    private:
        std::vector<Pessoa> pessoas;
    public:
        ContainerPessoas();

        void inserir(const Pessoa &pessoa);
        Pessoa buscar(const Email &email) const;
        void remover(const Email &email);
        std::vector<Pessoa> listar() const;
};

#endif // CONTAINERPESSOAS_H_INCLUDED
