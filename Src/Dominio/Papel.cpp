#include "dominio/Papel.h"
#include<stdexcept>

using namespace std;

void Papel::validar(string valor){
    if(valor != "DESENVOLVEDOR" && valor != "MESTRE SCRUM" && valor != "PROPRIETARIO DE PRODUTO"){
        throw invalid_argument("Papel invalido.");
    }
}

void Papel::setValor(string valor){
    validar(valor);
    this->valor = valor;
}

string Papel::getValor() const{
    return valor;
}
