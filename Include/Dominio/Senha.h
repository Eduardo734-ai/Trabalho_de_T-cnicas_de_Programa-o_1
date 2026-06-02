#ifndef SENHA_H_INCLUDED
#define SENHA_H_INCLUDED

#include<string>

using namespace std;

/**
 * @brief Credencial de segurança utilizada para autenticação e proteção do acesso de um usuário ao sistema.
 *
 * Armazena e valida o segredo de acesso de uma conta. Para garantir a segurança e seguir as
 * diretrizes do projeto, o formato exigido deve obedecer estritamente a todas as seguintes regras:
 * - Deve conter exatamente 6 caracteres.
 * - Os caracteres permitidos são apenas letras (a-z ou A-Z) e dígitos (0-9).
 * - Padrão de alternância obrigatório: uma letra nunca pode ser seguida por outra letra, e um dígito nunca pode ser seguido por outro dígito.
 * - Deve possuir obrigatoriamente pelo menos uma letra minúscula (a-z), pelo menos uma letra maiúscula (A-Z) e pelo menos um dígito (0-9).
 */
class Senha{
    private:
        string valor;
        void validar(string valor);

    public:
        /**
         * @brief Atribui uma nova credencial de acesso.
         *
         * Submete a string fornecida à bateria de validação de comprimento, composição de caracteres e regras de alternância.
         *
         * @param valor String contendo a credencial a ser definida.
         * @throw std::invalid_argument Lança uma exceção caso a senha viole qualquer uma das exigências de formatação (tamanho, caracteres inválidos ou falta de alternância/variedade).
         */
        void setValor(string valor);

        /**
         * @brief Recupera a credencial de acesso atual.
         *
         * @return string Retorna a senha validada.
         */
        string getValor() const;
};

#endif // SENHA_H_INCLUDED
