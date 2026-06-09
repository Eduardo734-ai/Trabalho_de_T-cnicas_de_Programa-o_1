#include "Dominio/Senha.h"
#include <stdexcept>
#include <cctype>

using namespace std;

void Senha::validar(string valor) {
    bool temMaiuscula = false;
    bool temMinuscula = false;
    bool temDigito = false;

    if (valor.length() != 6) {
        throw invalid_argument("Senha invalida.");
    }

    for (int i = 0; i < 6; i++) {
        if (!isalpha((unsigned char)valor[i]) && !isdigit((unsigned char)valor[i])) {
            throw invalid_argument("Senha invalida.");
        }

        if (isupper((unsigned char)valor[i])) {
            temMaiuscula = true;
        }

        if (islower((unsigned char)valor[i])) {
            temMinuscula = true;
        }

        if (isdigit((unsigned char)valor[i])) {
            temDigito = true;
        }
    }

    for (int i = 0; i < 5; i++) {
        if (isalpha((unsigned char)valor[i]) && isalpha((unsigned char)valor[i + 1])) {
            throw invalid_argument("Senha invalida.");
        }

        if (isdigit((unsigned char)valor[i]) && isdigit((unsigned char)valor[i + 1])) {
            throw invalid_argument("Senha invalida.");
        }
    }

    if (!temMaiuscula || !temMinuscula || !temDigito) {
        throw invalid_argument("Senha invalida.");
    }
}

void Senha::setValor(string valor) {
    validar(valor);
    this->valor = valor;
}

string Senha::getValor() const {
    return valor;
}
