#include"../../include/servico/ContainerPessoas.h"
#include<stdexcept>

using namespace std;

ContainerPessoas::ContainerPessoas(){

}

void ContainerPessoas::inserir(const Pessoa &pessoa){
    int i;

    for(i=0;i<(int)pessoas.size();i++){
        if(pessoas[i].getEmail().getValor() == pessoa.getEmail().getValor()){
            throw invalid_argument("Pessoa ja cadastrada.");
        }
    }
    pessoas.push_back(pessoa);
}

Pessoa ContainerPessoas::buscar(const Email &email) const{
    int i;

    for(i=0;i<(int)pessoas.size();i++){
        if(pessoas[i].getEmail().getValor() == email.getValor()){
           return pessoas[i];
        }
    }
    throw invalid_argument("Pessoa nao encontrada");
}

void ContainerPessoas::remover(const Email &email){
    int i;

    for(i=0;i<(int)pessoas.size();i++){
        if(pessoas[i].getEmail().getValor() == email.getValor()){
            pessoas.erase(pessoas.begin() + i);
            return;
        }
    }
    throw invalid_argument("Pessoa nao encontrada.");
}

vector<Pessoa> ContainerPessoas::listar() const{
    return pessoas;
}
