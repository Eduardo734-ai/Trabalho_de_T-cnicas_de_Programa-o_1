#ifndef ESTADO_H_INCLUDED
#define ESTADO_H_INCLUDED

#include<string>

using namespace std;

/**
 * @brief Define a situação atual de progresso de uma história de usuário dentro do fluxo de trabalho.
 *
 * Armazena e valida a fase em que uma tarefa se encontra no ciclo de desenvolvimento.
 * Para manter a consistência com o modelo Scrum exigido, os valores permitidos são
 * estritamente restritos a "A FAZER", "FAZENDO" ou "FEITO"[cite: 1].
 */
class Estado{
    private:
        string valor;
        void validar(string valor);

    public:
        /**
         * @brief Atribui uma nova situação de progresso.
         *
         * Verifica se a string fornecida corresponde a uma das fases de desenvolvimento permitidas pelo sistema.
         *
         * @param valor String contendo a fase a ser definida ("A FAZER", "FAZENDO" ou "FEITO").
         * @throw std::invalid_argument Lança uma exceção caso o valor não corresponda exatamente a uma das três situações válidas.
         */
        void setValor(string valor);

        /**
         * @brief Recupera a situação de progresso atual.
         *
         * @return string Retorna a fase de desenvolvimento validada.
         */
        string getValor() const;
};

#endif
