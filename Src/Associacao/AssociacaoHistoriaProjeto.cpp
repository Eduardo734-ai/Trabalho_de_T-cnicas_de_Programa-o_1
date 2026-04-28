#include"associacao/associacaoHistoriaProjeto.h"

void AssociacaoHistoriaProjeto::setCodigoHistoria(Codigo codigoHistoria){
    this->codigoHistoria = codigoHistoria;
}

Codigo AssociacaoHistoriaProjeto::getCodigoHistoria() const{
    return codigoHistoria;
}

void AssociacaoHistoriaProjeto::setCodigoProjeto(Codigo codigoProjeto){
    this->codigoProjeto = codigoProjeto;
}

Codigo AssociacaoHistoriaProjeto::getCodigoProjeto() const{
    return codigoProjeto;
}
