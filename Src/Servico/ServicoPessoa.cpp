#include "../../include/servico/ServicoPessoa.h"

ServicoPessoa::ServicoPessoa() {
}

void ServicoPessoa::criar(const Pessoa &pessoa) {
    repositorioPessoa.inserir(pessoa);
}

Pessoa ServicoPessoa::ler(const Email &email) {
    return repositorioPessoa.buscar(email);
}

void ServicoPessoa::atualizar(const Pessoa &pessoa) {
    repositorioPessoa.atualizar(pessoa);
}

void ServicoPessoa::excluir(const Email &email) {
    repositorioPessoa.remover(email);
}
