#include"dominio/Texto.h"
#include<stdexcept>
#include<cctype>

using namespace std;

void Texto::validar(string valor){
    int i;
    char atual;
    char proximo;

    if(valor.length() == 0 || valor.length() > 40){
        throw invalid_argument("Texto invalido.");
    }
    if(valor[0] == ' ' || valor[0] == ',' || valor[0] == '.'){
        throw invalid_argument("Texto invalido.");
    }
    if(valor[valor.length()-1] == ' ' || valor[valor.length()-1] == ',' || valor[valor.length()-1] == '.'){
        throw invalid_argument("Texto invalido.");
    }

    for(i=0;i<(int)valor.length();i++){
        atual = valor[i];

        if(!isalpha(atual) && !isdigit(atual) && atual != ' ' && atual != ',' && atual != '.'){
            throw invalid_argument("Texto invalido.");
        }
        if(i < (int)valor.length() - 1){
            proximo = valor[i+1];
            if(atual == ','){
                if(proximo == ',' || proximo == '.'){
                    throw invalid_argument("Texto invalido.");
                }
            }
            if(atual == '.'){
                if(proximo == ',' || proximo == '.'){
                    throw invalid_argument("Texto invalido.");
                }
            }
            if(atual == ' '){
                if(!isalpha(proximo) && !isdigit(proximo)){
                    throw invalid_argument("Texto invalido.");
                }
            }
        }
    }
}

void Texto::setValor(string valor){
    validar(valor);
    this->valor = valor;
}

string Texto::getValor() const{
    return valor;
}
