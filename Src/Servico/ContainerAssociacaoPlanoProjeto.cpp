#include"../../include/servico/ContainerAssociacaoPlanoProjeto.h"
#include<stdexcept>

using namespace std;

ContainerAssociacaoPlanoProjeto::ContainerAssociacaoPlanoProjeto(){
}

void ContainerAssociacaoPlanoProjeto::inserir(const AssociacaoPlanoProjeto &associacao){
    if(existe(associacao.getCodigoPlano(),associacao.getCodigoProjeto())){
        throw invalid_argument("Associacao plano-projeto ja cadastrada.");
    }
    associacoes.push_back(associacao);
}

void ContainerAssociacaoPlanoProjeto::remover(const Codigo &codigoPlano, const Codigo &codigoProjeto){
    int i;

    for(i=0;i<(int)associacoes.size();i++){
        if(associacoes[i].getCodigoPlano().getValor() == codigoPlano.getValor() && associacoes[i].getCodigoProjeto().getValor() == codigoProjeto.getValor()){
            associacoes.erase(associacoes.begin() + i);
            return;
        }
    }
    throw invalid_argument("Associacao plano-projeto nao encontrada.");
}

vector<AssociacaoPlanoProjeto> ContainerAssociacaoPlanoProjeto::listar()const{
    return associacoes;
}

bool ContainerAssociacaoPlanoProjeto::existe(const Codigo &codigoPlano, const Codigo &codigoProjeto) const{
    int i;

    for(i=0;i<(int)associacoes.size();i++){
        if(associacoes[i].getCodigoPlano().getValor() == codigoPlano.getValor() && associacoes[i].getCodigoProjeto().getValor() == codigoProjeto.getValor()){
            return true;
        }
    }
    return false;
}
