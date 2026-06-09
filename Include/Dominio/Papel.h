#ifndef PAPEL_H_INCLUDED
#define PAPEL_H_INCLUDED

#include<string>

using namespace std;

/**
 * @brief Especifica a função de atuação e as responsabilidades de um usuário dentro de um projeto.
 *
 * Armazena e valida o nível de permissão e o cargo que uma pessoa exerce no fluxo de trabalho.
 * Para manter a conformidade com o arcabouço Scrum adotado no sistema, os valores permitidos são
 * estritamente restritos a "DESENVOLVEDOR", "MESTRE SCRUM" ou "PROPRIETARIO DE PRODUTO".
 */
class Papel{
    private:
        string valor;
        void validar(string valor);

    public:
        /**
         * @brief Atribui uma nova função de atuação.
         *
         * Verifica se a string fornecida corresponde a um dos três cargos predefinidos pelo sistema.
         *
         * @param valor String contendo a função a ser definida ("DESENVOLVEDOR", "MESTRE SCRUM" ou "PROPRIETARIO DE PRODUTO").
         * @throw std::invalid_argument Lança uma exceção caso o valor não corresponda exatamente a uma das atuações válidas.
         */
        void setValor(string valor);

        /**
         * @brief Recupera a função de atuação atual.
         *
         * @return string Retorna o cargo validado.
         */
        string getValor() const;
};

#endif // PAPEL_H_INCLUDED
