#ifndef TEMPO_H_INCLUDED
#define TEMPO_H_INCLUDED

/**
 * @brief Quantificação de esforço, duração ou capacidade alocada para o planejamento das atividades.
 *
 * Armazena e valida uma medida quantitativa (utilizada para representar a estimativa de uma história de usuário ou a capacidade de um plano de sprint).
 * Para garantir o dimensionamento adequado dentro dos limites do sistema, o valor deve ser
 * um número inteiro compreendido no intervalo fechado de 1 a 365.
 */
class Tempo{
    private:
        int valor;
        void validar(int valor);

    public:
        /**
         * @brief Atribui uma nova quantificação de esforço ou duração.
         *
         * Verifica se o número inteiro fornecido está dentro do limite aceitável definido pelo sistema.
         *
         * @param valor Inteiro contendo a medida a ser definida (de 1 a 365).
         * @throw std::invalid_argument Lança uma exceção caso o valor seja menor que 1 ou maior que 365.
         */
        void setValor(int valor);

        /**
         * @brief Recupera a quantificação de esforço ou duração atual.
         *
         * @return int Retorna a medida validada.
         */
        int getValor() const;
};

#endif // TEMPO_H_INCLUDED
