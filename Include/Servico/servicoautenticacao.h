#ifndef SERVICOAUTENTICACAO_H_INCLUDED
#define SERVICOAUTENTICACAO_H_INCLUDED

#include "../entidade/Pessoa.h"
#include "../dominio/Email.h"
#include "../dominio/Senha.h"

#include "ContainerPessoas.h"

class ServicoAutenticacao {
private:
    ContainerPessoas containerPessoas;
    Pessoa usuarioLogado;
    bool autenticado;

public:
    ServicoAutenticacao();

    void cadastrar(const Pessoa &pessoa);
    bool login(const Email &email, const Senha &senha);
    void logout();

    bool estaAutenticado() const;
    Pessoa getUsuarioLogado() const;

    bool isMestreScrum() const;
    bool isProductOwner() const;
    bool isDesenvolvedor() const;

    void exigirMestreScrum() const;
    void exigirProductOwner() const;
    void exigirDesenvolvedor() const;
};

#endif // SERVICOAUTENTICACAO_H_INCLUDED
