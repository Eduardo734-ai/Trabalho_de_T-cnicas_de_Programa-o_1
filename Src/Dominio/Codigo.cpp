#include "dominio/Codigo.h"
#include<stdexcept>
#include<cctype>

using namespace std;

void Codigo::validar(string valor){
    int i;

    if(valor.length() != 5){
            throw invalid_argument("Codigo invalido.");
    }
    if(!isupper(valor[0]) || !isupper(valor[1])){
        throw invalid_argument("Codigo invalido.");
    }
    for(i=2;i<5;i++){
        if(!isdigit(valor[i])){
            throw invalid_argument("Codigo invalido.");
        }
    }
}

void Codigo::setValor(string valor){
    validar(valor);
    this->valor = valor;
}

string Codigo::getValor() const{
    return valor;
}
