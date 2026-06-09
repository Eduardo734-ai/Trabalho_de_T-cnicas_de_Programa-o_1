#include "Dominio/Email.h"
#include <stdexcept>
#include <cctype>

using namespace std;

void Email::validarParteLocal(string parteLocal) {
    if (parteLocal.length() == 0 || parteLocal.length() > 64) {
        throw invalid_argument("Email invalido.");
    }

    if (parteLocal[0] == '.' || parteLocal[0] == '-' ||
        parteLocal[parteLocal.length() - 1] == '.' ||
        parteLocal[parteLocal.length() - 1] == '-') {
        throw invalid_argument("Email invalido.");
    }

    for (int i = 0; i < (int)parteLocal.length(); i++) {
        char c = parteLocal[i];

        bool letra = (c >= 'a' && c <= 'z');
        bool digito = isdigit((unsigned char)c);
        bool simbolo = (c == '.' || c == '-');

        if (!letra && !digito && !simbolo) {
            throw invalid_argument("Email invalido.");
        }

        if ((c == '.' || c == '-') && i < (int)parteLocal.length() - 1) {
            char prox = parteLocal[i + 1];

            bool proxLetra = (prox >= 'a' && prox <= 'z');
            bool proxDigito = isdigit((unsigned char)prox);

            if (!proxLetra && !proxDigito) {
                throw invalid_argument("Email invalido.");
            }
        }
    }
}

void Email::validarDominio(string dominio) {
    if (dominio.length() == 0 || dominio.length() > 255) {
        throw invalid_argument("Email invalido.");
    }

    if (dominio[0] == '.' || dominio[dominio.length() - 1] == '.') {
        throw invalid_argument("Email invalido.");
    }

    int inicioParte = 0;

    for (int i = 0; i <= (int)dominio.length(); i++) {
        if (i == (int)dominio.length() || dominio[i] == '.') {
            int tamanhoParte = i - inicioParte;

            if (tamanhoParte <= 0) {
                throw invalid_argument("Email invalido.");
            }

            if (dominio[inicioParte] == '-' || dominio[i - 1] == '-') {
                throw invalid_argument("Email invalido.");
            }

            for (int j = inicioParte; j < i; j++) {
                char c = dominio[j];

                bool letra = (c >= 'a' && c <= 'z');
                bool digito = isdigit((unsigned char)c);
                bool hifen = (c == '-');

                if (!letra && !digito && !hifen) {
                    throw invalid_argument("Email invalido.");
                }
            }

            inicioParte = i + 1;
        }
    }
}

void Email::validar(string valor) {
    int posArroba = valor.find('@');

    if (posArroba == string::npos) {
        throw invalid_argument("Email invalido.");
    }

    if (valor.find('@', posArroba + 1) != string::npos) {
        throw invalid_argument("Email invalido.");
    }

    string parteLocal = valor.substr(0, posArroba);
    string dominio = valor.substr(posArroba + 1);

    validarParteLocal(parteLocal);
    validarDominio(dominio);
}

void Email::setValor(string valor) {
    validar(valor);
    this->valor = valor;
}

string Email::getValor() const {
    return valor;
}
