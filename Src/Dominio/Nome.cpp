#include "dominio/Nome.h"
#include<stdexcept>
#include<cctype>

using namespace std;

void Nome::validar(string valor){
    int i;

    if(valor.length() == 0 || valor.length() > 10){
        throw invalid_argument("Nome invalido.");
    }
    if(valor[0] == ' ' || valor[valor.length() - 1] == ' '){
        throw invalid_argument("Nome invalido.");
    }
    for(i = 0;i<(int)valor.length();i++){
        if(!isalpha(valor[i]) && valor[i] != ' '){
            throw invalid_argument("Nome invalido.");
        }
        if(valor[i] == ' '){
            if(i+1 >= (int)valor.length() || !isalpha(valor[i+1])){
                throw invalid_argument("Nome invalido.");
            }
        }
    }
}

void Nome::setValor(string valor){
    validar(valor);
    this->valor = valor;
}

string Nome::getValor() const{
        return valor;
}
