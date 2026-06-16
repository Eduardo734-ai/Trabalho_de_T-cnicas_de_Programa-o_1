#include"Associacao/AssociacaoHistoriaPlano.h"

void AssociacaoHistoriaPlano::setCodigoHistoria(const Codigo& codigoHistoria){
    this->codigoHistoria = codigoHistoria;
}

Codigo AssociacaoHistoriaPlano::getCodigoHistoria() const{
    return codigoHistoria;
}

void AssociacaoHistoriaPlano::setCodigoPlano(const Codigo& codigoPlano){
    this->codigoPlano = codigoPlano;
}

Codigo AssociacaoHistoriaPlano::getCodigoPlano() const{
    return codigoPlano;
}
