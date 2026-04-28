#ifndef ISERVICOPESSOA_H_INCLUDED
#define ISERVICOPESSOA_H_INCLUDED

#include"entidade/Pessoa.h"
#include"dominio/Email.h"


class IServicoPessoa{
    public:
        virtual void criar(const Pessoa &pessoa) = 0;
        virtual Pessoa ler(const Email &email) = 0;
        virtual void atualizar(const Pessoa &pessoa) = 0;
        virtual void excluir(const Email &email) = 0;

        virtual ~IServicoPessoa(){}
};

#endif // ISERVICOPESSOA_H_INCLUDED
