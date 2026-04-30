#ifndef SERVICOPESSOA_H_INCLUDED
#define SERVICOPESSOA_H_INCLUDED


#include "../interface/IServicoPessoa.h"
#include "../banco/RepositorioPessoa.h"

class ServicoPessoa : public IServicoPessoa {
private:
    RepositorioPessoa repositorioPessoa;

public:
    ServicoPessoa();

    void criar(const Pessoa &pessoa) override;
    Pessoa ler(const Email &email) override;
    void atualizar(const Pessoa &pessoa) override;
    void excluir(const Email &email) override;
};

#endif // SERVICOPESSOA_H_INCLUDED
