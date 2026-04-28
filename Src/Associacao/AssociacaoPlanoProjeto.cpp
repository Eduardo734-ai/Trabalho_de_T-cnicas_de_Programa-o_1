#include"associacao/AssociacaoPlanoProjeto.h"

void AssociacaoPlanoProjeto::setCodigoPlano(Codigo codigoPlano){
    this->codigoPlano = codigoPlano;
}

Codigo AssociacaoPlanoProjeto::getCodigoPlano() const{
    return codigoPlano;
}

void AssociacaoPlanoProjeto::setCodigoProjeto(Codigo codigoProjeto){
    this->codigoProjeto = codigoProjeto;
}

Codigo AssociacaoPlanoProjeto::getCodigoProjeto() const{
    return codigoProjeto;
}
