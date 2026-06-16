#ifndef EMAIL_H_INCLUDED
#define EMAIL_H_INCLUDED

#include<string>

using namespace std;

/**
 * @brief Classe de domínio que representa um correio eletrônico.
 *
 * Esta classe é responsável por armazenar e validar o formato de um endereço de email.
 * De acordo com as regras de negócio, o email deve seguir o formato parte-local@domínio.
 *
 * Regras da Parte Local:
 * - Pode conter letras (a-z), dígitos (0-9), pontos (.) ou hifens (-).
 * - Não pode iniciar ou terminar com ponto ou hífen.
 * - Ponto ou hífen deve ser imediatamente seguido por letra(s) ou dígito(s).
 * - Comprimento máximo de 64 caracteres].
 *
 * Regras do Domínio:
 * - Composto por uma ou mais partes separadas por ponto (.)].
 * - Cada parte pode conter letras (a-z), dígitos (0-9) ou hifens (-).
 * - Nenhuma parte pode iniciar ou terminar com hífen.
 * - Comprimento máximo de 255 caracteres.
 */
class Email{
    private:
        string valor;
        void validar(string valor);
        void validarParteLocal(string parteLocal);
        void validarDominio(string dominio);

    public:
        /**
         * @brief Define o valor do email.
         *
         * Recebe uma string e a submete à validação rigorosa de formato para a parte local e para o domínio.
         *
         * @param valor String contendo o endereço de email a ser definido.
         * @throw std::invalid_argument Lança uma exceção caso a string fornecida viole qualquer regra de formatação da parte local ou do domínio.
         */
        void setValor(string valor);

        /**
         * @brief Recupera o valor atual do email.
         *
         * @return string Retorna o endereço de email armazenado.
         */
        string getValor() const;
};

#endif // EMAIL_H_INCLUDED
