#include "Dominio/Nome.h"
#include<stdexcept>
#include<cctype>

using namespace std;

void Nome::validar(string valor) {
    if (valor.length() == 0 || valor.length() > 10) {
        throw invalid_argument("Nome invalido.");
    }

    if (valor[0] == ' ' || valor[valor.length() - 1] == ' ') {
        throw invalid_argument("Nome invalido.");
    }

    for (int i = 0; i < valor.length(); i++) {
        char atual = valor[i];

        bool letraMaiuscula = atual >= 'A' && atual <= 'Z';
        bool letraMinuscula = atual >= 'a' && atual <= 'z';
        bool espaco = atual == ' ';

        if (!letraMaiuscula && !letraMinuscula && !espaco) {
            throw invalid_argument("Nome invalido.");
        }

        if (espaco) {
            char proximo = valor[i + 1];

            bool proximoLetraMaiuscula = proximo >= 'A' && proximo <= 'Z';
            bool proximoLetraMinuscula = proximo >= 'a' && proximo <= 'z';

            if (!proximoLetraMaiuscula && !proximoLetraMinuscula) {
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
