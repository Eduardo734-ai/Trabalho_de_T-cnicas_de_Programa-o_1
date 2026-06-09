#ifndef NOME_H_INCLUDED
#define NOME_H_INCLUDED

#include<string>

using namespace std;

/**
 * @brief Designação de identificação pessoal utilizada para reconhecer os usuários no sistema.
 *
 * Armazena e valida a cadeia de caracteres que compõe a identificação de um indivíduo.
 * As regras de formatação exigem que o texto tenha no máximo 10 caracteres, compostos apenas por
 * letras maiúsculas (A-Z), minúsculas (a-z) ou espaços em branco.
 * Para garantir uma formatação limpa, não é permitido iniciar ou terminar com espaços,
 * e qualquer espaço em branco interno deve ser obrigatoriamente seguido por uma letra.
 */
class Nome{
    private:
        string valor;
        void validar(string valor);

    public:
        /**
         * @brief Atribui uma nova identificação textual.
         *
         * Submete a string fornecida às regras de validação de comprimento e disposição de caracteres.
         *
         * @param valor String contendo a designação pessoal a ser definida.
         * @throw std::invalid_argument Lança uma exceção caso o texto ultrapasse 10 caracteres, contenha símbolos não permitidos ou possua espaços mal posicionados.
         */
        void setValor(string valor);

        /**
         * @brief Recupera a identificação textual atual.
         *
         * @return string Retorna a designação pessoal validada.
         */
        string getValor() const;
};

#endif // NOME_H_INCLUDED
