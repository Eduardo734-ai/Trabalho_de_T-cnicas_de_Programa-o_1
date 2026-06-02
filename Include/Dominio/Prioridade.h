#ifndef PRIORIDADE_H_INCLUDED
#define PRIORIDADE_H_INCLUDED

#include<string>

using namespace std;

/**
 * @brief Determina o nível de urgência ou importância de execução de uma tarefa no escopo do projeto.
 *
 * Armazena e valida o grau de relevância associado a uma história de usuário.
 * Para garantir a correta ordenação e priorização do trabalho no modelo Scrum,
 * os valores permitidos são estritamente limitados a "ALTA", "MEDIA" ou "BAIXA".
 */
class Prioridade{
    private:
        string valor;
        void validar(string valor);

    public:
        /**
         * @brief Atribui um novo grau de urgência.
         *
         * Verifica se a string fornecida corresponde a um dos três níveis predefinidos de importância.
         *
         * @param valor String contendo o nível a ser definido ("ALTA", "MEDIA" ou "BAIXA").
         * @throw std::invalid_argument Lança uma exceção caso o valor não corresponda exatamente a uma das prioridades válidas.
         */
        void setValor(string valor);

        /**
         * @brief Recupera o grau de urgência atual.
         *
         * @return string Retorna o nível de importância validado.
         */
        string getValor() const;
};

#endif // PRIORIDADE_H_INCLUDED
