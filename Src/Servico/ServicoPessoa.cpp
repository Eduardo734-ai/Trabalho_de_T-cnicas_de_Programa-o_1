#include"../../include/servico/ServicoPessoa.h"
#include<stdexcept>

using namespace std;

ServicoPessoa::ServicoPessoa(){
}

void ServicoPessoa::criar(const Pessoa &pessoa){
    container.inserir(pessoa);
}

Pessoa ServicoPessoa::ler(const Email &email){
    return container.buscar(email);
}

void ServicoPessoa::atualizar(const Pessoa &pessoa){
    container.remover(pessoa.getEmail());
    container.inserir(pessoa);
}

void ServicoPessoa::excluir(const Email &email){
    container.remover(email);
}
