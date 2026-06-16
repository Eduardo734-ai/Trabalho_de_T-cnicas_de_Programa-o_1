#include"Dominio/Texto.h"
#include<stdexcept>
#include<cctype>

using namespace std;

void Texto::validar(string valor) {
    if (valor.length() == 0 || valor.length() > 40) {
        throw invalid_argument("Texto invalido.");
    }

    char primeiro = valor[0];
    char ultimo = valor[valor.length() - 1];

    if (primeiro == ',' || primeiro == '.' || primeiro == ' ' ||
        ultimo == ',' || ultimo == '.' || ultimo == ' ') {
        throw invalid_argument("Texto invalido.");
    }

    for (size_t i = 0; i < valor.length(); i++) {
        char atual = valor[i];

        bool letraMaiuscula = atual >= 'A' && atual <= 'Z';
        bool letraMinuscula = atual >= 'a' && atual <= 'z';
        bool digito = atual >= '0' && atual <= '9';
        bool virgula = atual == ',';
        bool ponto = atual == '.';
        bool espaco = atual == ' ';

        if (!letraMaiuscula && !letraMinuscula && !digito && !virgula && !ponto && !espaco) {
            throw invalid_argument("Texto invalido.");
        }

        if (virgula || ponto) {
            char proximo = valor[i + 1];

            if (proximo == ',' || proximo == '.') {
                throw invalid_argument("Texto invalido.");
            }
        }

        if (espaco) {
            char proximo = valor[i + 1];

            bool proximoLetraMaiuscula = proximo >= 'A' && proximo <= 'Z';
            bool proximoLetraMinuscula = proximo >= 'a' && proximo <= 'z';
            bool proximoDigito = proximo >= '0' && proximo <= '9';

            if (!proximoLetraMaiuscula && !proximoLetraMinuscula && !proximoDigito) {
                throw invalid_argument("Texto invalido.");
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
