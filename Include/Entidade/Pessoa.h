#ifndef PESSOA_H_INCLUDED
#define PESSOA_H_INCLUDED

#include"dominio/Email.h"
#include"dominio/Nome.h"
#include"dominio/Senha.h"
#include"dominio/Papel.h"

/**
 * @brief Entidade que representa um usuário registrado no sistema.
 *
 * Centraliza as informações de identificação, credenciais de acesso e nível de permissão
 * de um indivíduo envolvido no projeto. No contexto do sistema, os dados desta entidade
 * são os pilares para a autenticação segura do usuário (através de email e senha) e para
 * determinar quais ações e serviços ele está autorizado a executar no fluxo Scrum (através de seu papel).
 */
class Pessoa{
    private:
        Email email;
        Nome nome;
        Senha senha;
        Papel papel;

    public:
        /**
         * @brief Atribui o endereço eletrônico do usuário.
         *
         * O email atua como o identificador único (chave primária) da pessoa no sistema.
         *
         * @param email Objeto da classe Email contendo o endereço previamente validado.
         */
        void setEmail(Email email);

        /**
         * @brief Recupera o endereço eletrônico do usuário.
         *
         * @return Email Retorna o objeto de email atual.
         */
        Email getEmail() const;

        /**
         * @brief Atribui a designação de identificação do usuário.
         *
         * @param nome Objeto da classe Nome contendo a identificação textual validada.
         */
        void setNome(Nome nome);

        /**
         * @brief Recupera a designação de identificação do usuário.
         *
         * @return Nome Retorna o objeto de identificação atual.
         */
        Nome getNome() const;

        /**
         * @brief Atribui a credencial de segurança do usuário.
         *
         * Esta credencial será exigida, em conjunto com o email, durante o processo de autenticação.
         *
         * @param senha Objeto da classe Senha contendo a credencial validada.
         */
        void setSenha(Senha senha);

        /**
         * @brief Recupera a credencial de segurança do usuário.
         *
         * @return Senha Retorna o objeto contendo a credencial atual.
         */
        Senha getSenha() const;

        /**
         * @brief Atribui a função de atuação do usuário no projeto.
         *
         * O papel define o nível de privilégio e restringe o acesso aos serviços do sistema.
         *
         * @param papel Objeto da classe Papel contendo o cargo validado.
         */
        void setPapel(Papel papel);

        /**
         * @brief Recupera a função de atuação do usuário.
         *
         * @return Papel Retorna o objeto contendo o cargo atual.
         */
        Papel getPapel() const;
};

#endif // PESSOA_H_INCLUDED
