#include "../../include/servico/ServicoAutenticacao.h"
#include <stdexcept>

using namespace std;

ServicoAutenticacao::ServicoAutenticacao() {
    autenticado = false;
}

void ServicoAutenticacao::cadastrar(const Pessoa &pessoa) {
    containerPessoas.inserir(pessoa);
}

bool ServicoAutenticacao::login(const Email &email, const Senha &senha) {
    Pessoa pessoa;

    pessoa = containerPessoas.buscar(email);

    if (pessoa.getSenha().getValor() != senha.getValor()) {
        throw invalid_argument("Senha incorreta.");
    }

    usuarioLogado = pessoa;
    autenticado = true;

    return true;
}

void ServicoAutenticacao::logout() {
    autenticado = false;
}

bool ServicoAutenticacao::estaAutenticado() const {
    return autenticado;
}

Pessoa ServicoAutenticacao::getUsuarioLogado() const {
    if (!autenticado) {
        throw invalid_argument("Nenhum usuario autenticado.");
    }

    return usuarioLogado;
}

bool ServicoAutenticacao::isMestreScrum() const {
    if (!autenticado) {
        throw invalid_argument("Nenhum usuario autenticado.");
    }

    return usuarioLogado.getPapel().getValor() == "MESTRE SCRUM";
}

bool ServicoAutenticacao::isProductOwner() const {
    if (!autenticado) {
        throw invalid_argument("Nenhum usuario autenticado.");
    }

    return usuarioLogado.getPapel().getValor() == "PROPRIETARIO DE PRODUTO";
}

bool ServicoAutenticacao::isDesenvolvedor() const {
    if (!autenticado) {
        throw invalid_argument("Nenhum usuario autenticado.");
    }

    return usuarioLogado.getPapel().getValor() == "DESENVOLVEDOR";
}

void ServicoAutenticacao::exigirMestreScrum() const {
    if (!isMestreScrum()) {
        throw invalid_argument("Acesso permitido apenas para Mestre Scrum.");
    }
}

void ServicoAutenticacao::exigirProductOwner() const {
    if (!isProductOwner()) {
        throw invalid_argument("Acesso permitido apenas para Proprietario de Produto.");
    }
}

void ServicoAutenticacao::exigirDesenvolvedor() const {
    if (!isDesenvolvedor()) {
        throw invalid_argument("Acesso permitido apenas para Desenvolvedor.");
    }
}
