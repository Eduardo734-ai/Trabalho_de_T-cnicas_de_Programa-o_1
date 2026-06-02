#ifndef TEXTO_H_INCLUDED
#define TEXTO_H_INCLUDED

#include<string>

using namespace std;

/**
 * @brief Conjunto descritivo utilizado para detalhar informações textuais no escopo do projeto.
 *
 * Armazena e valida sequências de caracteres que descrevem elementos estruturais do sistema (como títulos, objetivos, ações e valores de negócios).
 * Para garantir a padronização e evitar textos mal formatados, a string deve obedecer a um conjunto rigoroso de regras:
 * - O comprimento máximo é limitado a 40 caracteres.
 * - Os caracteres permitidos incluem exclusivamente letras (a-z ou A-Z), dígitos (0-9), vírgula, ponto ou espaço em branco.
 * - Restrições de pontuação: uma vírgula não pode ser imediatamente seguida por outra vírgula ou por um ponto. O mesmo vale para o ponto, que não pode ser seguido por vírgula ou outro ponto.
 * - Restrição de espaçamento: um espaço em branco deve ser obrigatoriamente seguido por uma letra ou um dígito.
 * - Restrição de bordas: o primeiro e o último caractere da sequência não podem ser, em hipótese alguma, vírgula, ponto ou espaço em branco.
 */
class Texto{
    private:
        string valor;
        void validar(string valor);

    public:
        /**
         * @brief Atribui uma nova sequência descritiva de caracteres.
         *
         * Submete a string fornecida a todas as validações de caracteres permitidos, limites de tamanho, posicionamento de pontuação e de espaçamento.
         *
         * @param valor String contendo o texto a ser definido.
         * @throw std::invalid_argument Lança uma exceção caso o texto fornecido viole qualquer uma das exigências de formatação estrutural descritas.
         */
        void setValor(string valor);

        /**
         * @brief Recupera a sequência descritiva atual.
         *
         * @return string Retorna o texto validado.
         */
        string getValor() const;
};

#endif // TEXTO_H_INCLUDED
