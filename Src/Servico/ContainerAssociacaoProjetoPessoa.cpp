#include"../../include/servico/ContainerAssociacaoProjetoPessoa.h"
#include<stdexcept>

using namespace std;

ContainerAssociacaoProjetoPessoa::ContainerAssociacaoProjetoPessoa(){
}

void ContainerAssociacaoProjetoPessoa::inserir(const AssociacaoProjetoPessoa &associacao){
    if(existe(associacao.getCodigoProjeto(),associacao.getEmailPessoa())){
        throw invalid_argument("Associacao projeto-pessoa ja cadastrada.");
    }
    associacoes.push_back(associacao);
}

void ContainerAssociacaoProjetoPessoa::remover(const Codigo &codigoProjeto,const Email &emailPessoa){
    int i;

    for(i = 0;i < (int)associacoes.size(); i++){
        if(associacoes[i].getCodigoProjeto().getValor() == codigoProjeto.getValor() &&
           associacoes[i].getEmailPessoa().getValor() == emailPessoa.getValor()){
            associacoes.erase(associacoes.begin() + 1);
            return;
           }
    }
    throw invalid_argument("Associacao projeto-pessoa nao encontrada.");
}

vector<AssociacaoProjetoPessoa> ContainerAssociacaoProjetoPessoa::listar() const{
    return associacoes;
}

bool ContainerAssociacaoProjetoPessoa::existe(const Codigo &codigoProjeto, const Email &emailPessoa) const{
    int i;

    for(i = 0; i < (int)associacoes.size();i++){
        if(associacoes[i].getCodigoProjeto().getValor() == codigoProjeto.getValor() && associacoes[i].getEmailPessoa().getValor() == emailPessoa.getValor()){
            return true;
        }
    }
    return false;
}
