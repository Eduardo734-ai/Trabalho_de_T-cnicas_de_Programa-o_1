#include"associacao/AssociacaoHistoriaPlano.h"

void AssociacaoHistoriaPlano::setCodigoHistoria(Codigo codigoHistoria){
    this->codigoHistoria = codigoHistoria;
}

Codigo AssociacaoHistoriaPlano::getCodigoHistoria() const{
    return codigoHistoria;
}

void AssociacaoHistoriaPlano::setCodigoPlano(Codigo codigoPlano){
    this->codigoPlano = codigoPlano;
}

Codigo AssociacaoHistoriaPlano::getCodigoPlano() const{
    return codigoPlano;
}
