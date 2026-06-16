#include"Associacao/associacaoHistoriaProjeto.h"

void AssociacaoHistoriaProjeto::setCodigoHistoria(const Codigo& codigoHistoria){
    this->codigoHistoria = codigoHistoria;
}

Codigo AssociacaoHistoriaProjeto::getCodigoHistoria() const{
    return codigoHistoria;
}

void AssociacaoHistoriaProjeto::setCodigoProjeto(const Codigo& codigoProjeto){
    this->codigoProjeto = codigoProjeto;
}

Codigo AssociacaoHistoriaProjeto::getCodigoProjeto() const{
    return codigoProjeto;
}
