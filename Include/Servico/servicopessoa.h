#ifndef SERVICOPESSOA_H_INCLUDED
#define SERVICOPESSOA_H_INCLUDED

#include"../interface/IservicoPessoa.h"
#include"ContainerPessoas.h"

class ServicoPessoa : public IServicoPessoa{
    private:
        ContainerPessoas container;
    public:
        ServicoPessoa();

        void criar(const Pessoa &pessoa) override;
        Pessoa ler(const Email &email) override;
        void atualizar(const Pessoa &pessoa) override;
        void excluir(const Email &email) override;
};

#endif // SERVICOPESSOA_H_INCLUDED
