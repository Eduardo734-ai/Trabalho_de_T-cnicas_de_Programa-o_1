#include"../../include/servico/ContainerProjetos.h"
#include<stdexcept>

using namespace std;

ContainerProjetos::ContainerProjetos(){
}

void ContainerProjetos::inserir(const Projeto &projeto){
    int i;

    for(i=0;i<(int)projetos.size();i++){
        if(projetos[i].getCodigo().getValor() == projeto.getCodigo().getValor()){
            throw invalid_argument("Projeto ja cadastrado.");
        }
    }
    projetos.push_back(projeto);
}

Projeto ContainerProjetos::buscar(const Codigo &codigo) const{
    int i;

    for(i=0;i<(int)projetos.size();i++){
        if(projetos[i].getCodigo().getValor() == codigo.getValor()){
            return projetos[i];
        }
    }
    throw invalid_argument("Projeto nao encontrado.");
}

void ContainerProjetos::remover(const Codigo &codigo){
    int i;

    for(i=0;i<(int)projetos.size();i++){
        if(projetos[i].getCodigo().getValor() == codigo.getValor()){
            projetos.erase(projetos.begin() + i);
            return;
        }
    }
    throw invalid_argument("Projeto nao encontrado.");
}

vector<Projeto> ContainerProjetos::listar() const{
    return projetos;
}
