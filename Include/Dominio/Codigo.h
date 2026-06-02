#ifndef CODIGO_H_INCLUDED
#define CODIGO_H_INCLUDED

#include<string>

using namespace std;

/**
 * @brief Classe de domínio que representa um conjunto de sinais, regras ou símbolos utilizados para representar informações.
 *
 * Esta classe é responsável por armazenar e validar o formato de um código no sistema.
 * De acordo com as regras de negócio, um código válido deve possuir exatamente 5 caracteres,
 * sendo os dois primeiros letras maiúsculas (A-Z) e os três últimos dígitos (0-9).
 */
class Codigo{
    private:
        string valor;
        void validar(string valor);

    public:
        /**
         * @brief Define o valor do código.
         *
         * Recebe uma string e a submete à validação de formato.
         *
         * @param valor String contendo o código a ser definido.
         * @throw std::invalid_argument Lança uma exceção caso a string fornecida não atenda ao formato válido (2 letras maiúsculas seguidas por 3 dígitos).
         */
        void setValor(string valor);

        /**
         * @brief Recupera o valor atual do código.
         *
         * @return string Retorna o código armazenado.
         */
        string getValor() const;
};

#endif
