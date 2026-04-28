#include "dominio/Prioridade.h"
#include<stdexcept>

using namespace std;

void Prioridade::validar(string valor){
    if(valor != "ALTA" && valor != "MEDIA" && valor != "BAIXA"){
        throw invalid_argument("Prioridade invalida.");
    }
}

void Prioridade::setValor(string valor){
    validar(valor);
    this->valor = valor;
}

string Prioridade::getValor() const{
    return valor;
}
