#include "dominio/Tempo.h"
#include<stdexcept>

using namespace std;

void Tempo::validar(int valor){
    if(valor < 1 || valor > 365){
        throw invalid_argument("Tempo invalido.");
    }
}

void Tempo::setValor(int valor){
    validar(valor);
    this->valor = valor;
}

int Tempo::getValor() const{
    return valor;
}
