#include"../../include/servico/ContainerAssociacaoHistoriaProjeto.h"
#include<stdexcept>

using namespace std;

ContainerAssociacaoHistoriaProjeto::ContainerAssociacaoHistoriaProjeto(){
}

void ContainerAssociacaoHistoriaProjeto::inserir(const AssociacaoHistoriaProjeto &associacao){
    if(existe(associacao.getCodigoHistoria(),associacao.getCodigoProjeto())){
        throw invalid_argument("Associacao historia-projeto ja cadastrada.");
    }
    associacoes.push_back(associacao);
}

void ContainerAssociacaoHistoriaProjeto::remover(const Codigo &codigoHistoria,const Codigo &codigoProjeto){
    int i;

    for(i=0;(int)associacoes.size();i++){
        if(associacoes[i].getCodigoHistoria().getValor() == codigoHistoria.getValor() && associacoes[i].getCodigoProjeto().getValor() == codigoProjeto.getValor()){
            associacoes.erase(associacoes.begin() + i);
            return;
        }
    }
    throw invalid_argument("Associacao historia-projeto nao encontrada.");
}

vector<AssociacaoHistoriaProjeto> ContainerAssociacaoHistoriaProjeto::listar() const{
    return associacoes;
}

bool ContainerAssociacaoHistoriaProjeto::existe(const Codigo &codigoHistoria,const Codigo &codigoProjeto) const{
    int i;

    for(i=0;i<(int)associacoes.size();i++){
        if(associacoes[i].getCodigoHistoria().getValor() == codigoHistoria.getValor() && associacoes[i].getCodigoProjeto().getValor() == codigoProjeto.getValor()){
            return true;
        }
    }
    return false;
}
