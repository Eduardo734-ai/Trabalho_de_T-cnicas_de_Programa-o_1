#include"dominio/Email.h"
#include<stdexcept>
#include<cctype>

using namespace std;

void Email::validarParteLocal(string parteLocal){
    int i;

    if(parteLocal.length() == 0 || parteLocal.length() > 64){
        throw invalid_argument ("Email invalido.");
    }
    if(parteLocal[0] == '.' || parteLocal[0] == '-' ||
        parteLocal[parteLocal.length() - 1] == '.' ||
        parteLocal[parteLocal.length() - 1] == '-'){
        throw invalid_argument("Email invalido.");
    }
    for(i=0;i<(int)parteLocal.length();i++){
        char c = parteLocal[i];
        if(!(c >= 'a' || c <= 'z') && !isdigit((unsigned char)c) && c != '.' && c != '-'){
            throw invalid_argument("Email invalido.");
        }
        if((c == '.' || c == '-') && i < (int)parteLocal.length() - 1){
            char prox = parteLocal[i+1];
            if(!(prox >= 'a' || prox <= 'z') && !isdigit((unsigned char)prox)){
                throw invalid_argument("Email invalido.");
            }
        }
    }
}

void Email::validarDominio(string dominio){
    int i;
    int inicioParte;
    int tamanhoParte;

    if(dominio.length() == 0 || dominio.length() > 255){
        throw invalid_argument("Email invalido.");
    }
    if(dominio[0] == '.' || dominio[dominio.length() - 1] == '.'){
        throw invalid_argument("Email invalido.");
    }

    inicioParte = 0;

    for(i = 0; i <=(int)dominio.length();i++){
        if(i == (int)dominio.length() || dominio[i] == '.'){
            tamanhoParte = i-inicioParte;

            if(tamanhoParte <= 0){
                throw invalid_argument("Email invalido.");
            }
            if(dominio[inicioParte] == '-' || dominio[i-1] == '-'){
                throw invalid_argument("Email invalido");
            }
            for(int j = inicioParte;j<i;j++){
                char c;
                if(!(c >= 'a' || c <= 'z') && !isdigit((unsigned char)c) && c != '-'){

                }
            }
            inicioParte = i+1;
        }
    }
}

void Email::validar(string valor){
    int posArroba;
    string parteLocal;
    string dominio;

    posArroba = valor.find('@');

    if(posArroba == string::npos){
        throw invalid_argument("Email invalido." );
    }
    if(valor.find('@',posArroba + 1) != string::npos){
        throw invalid_argument("Email invalido.");
    }
    parteLocal = valor.substr(0,posArroba);
    dominio = valor.substr(posArroba+1);

    validarParteLocal(parteLocal);
    validarDominio(dominio);
}

void Email::setValor(string valor){
    validar(valor);
    this->valor = valor;
}

string Email::getValor() const{
    return valor;
}
