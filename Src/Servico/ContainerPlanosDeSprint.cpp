#include"../../include/servico/ContainerPlanosDeSprint.h"
#include<stdexcept>

using namespace std;

ContainerPlanosDeSprint::ContainerPlanosDeSprint(){
}

void ContainerPlanosDeSprint::inserir(const PlanoDeSprint &plano){
    int i;
    for(i=0;i<(int)planos.size();i++){
        if(planos[i].getCodigo().getValor() == plano.getCodigo().getValor()){
            throw invalid_argument("Plano de Sprint ja cadastrado.");
        }
    }
    planos.push_back(plano);
}

PlanoDeSprint ContainerPlanosDeSprint::buscar(const Codigo &codigo) const{
    int i;

    for(i=0;i<(int)planos.size();i++){
        if(planos[i].getCodigo().getValor() == codigo.getValor()){
            return planos[i];
        }
    }
    throw invalid_argument("Plano de sprint nao encontrado.");
}

void ContainerPlanosDeSprint::remover(const Codigo &codigo){
    int i;

    for(int i=0;i<(int)planos.size();i++){
        if(planos[i].getCodigo().getValor() == codigo.getValor()){
            planos.erase(planos.begin() + i);
            return;
        }
    }
    throw invalid_argument("Plano de sprint nao encontrado.");
}

vector<PlanoDeSprint> ContainerPlanosDeSprint::listar()const{
    return planos;
}
