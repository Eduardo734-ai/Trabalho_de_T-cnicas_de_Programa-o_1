#include"Associacao/AssociacaoPlanoProjeto.h"

void AssociacaoPlanoProjeto::setCodigoPlano(const Codigo& codigoPlano){
    this->codigoPlano = codigoPlano;
}

Codigo AssociacaoPlanoProjeto::getCodigoPlano() const{
    return codigoPlano;
}

void AssociacaoPlanoProjeto::setCodigoProjeto(const Codigo& codigoProjeto){
    this->codigoProjeto = codigoProjeto;
}

Codigo AssociacaoPlanoProjeto::getCodigoProjeto() const{
    return codigoProjeto;
}
