#include "../../include/servico/ContainerHistoriasUsuario.h"
#include<stdexcept>

using namespace std;

ContainerHistoriasUsuario::ContainerHistoriasUsuario() {
}

void ContainerHistoriasUsuario::inserir(const HistoriaUsuario &historia){
    int i;

    for(i=0;i<(int)historias.size();i++){
        if(historias[i].getCodigo().getValor() == historia.getCodigo().getValor()){
            throw invalid_argument("Historia de usuario ja cadastrada.");
        }
    }
    historias.push_back(historia);
}

HistoriaUsuario ContainerHistoriasUsuario::buscar(const Codigo &codigo)const{
    int i;

    for(i=0;i<(int)historias.size();i++){
        if(historias[i].getCodigo().getValor() == codigo.getValor()){
            return historias[i];
        }
    }
    throw invalid_argument("Historia de usuario nao encontrada.");
}

void ContainerHistoriasUsuario::remover(const Codigo &codigo){
    int i;

    for(i=0;i<(int)historias.size();i++){
        if(historias[i].getCodigo().getValor() == codigo.getValor()){
            historias.erase(historias.begin() + i);
            return;
        }
    }
    throw invalid_argument("Historia de usuario nao encontrada.");
}

vector<HistoriaUsuario> ContainerHistoriasUsuario::listar() const{
    return historias;
}
