#ifndef ASSOCIACAOPROJETOPESSOA_H_INCLUDED
#define ASSOCIACAOPROJETOPESSOA_H_INCLUDED

#include"dominio/Codigo.h"
#include"dominio/Email.h"

/**
 * @brief Classe de associação que vincula um Projeto a um Colaborador (Pessoa).
 * * Atua como uma entidade associativa no modelo orientado a objetos, representando
 * a alocação de um usuário na equipe de um empreendimento. É a estrutura fundamental
 * para a governança e o controle de acesso do sistema, determinando quais membros
 * possuem permissão para visualizar e interagir com cada projeto.
 */
class AssociacaoProjetoPessoa{
    private:
        Codigo codigoProjeto;
        Email emailPessoa;

    public:
        /**
         * @brief Define o identificador do projeto que receberá o colaborador.
         * * @param codigoProjeto Objeto da classe de domínio Codigo representando o macroescopo.
         */
        void setCodigoProjeto(Codigo codigoProjeto);

        /**
         * @brief Recupera o identificador do projeto associado neste vínculo de equipe.
         * * @return Codigo Objeto de domínio contendo a chave do macroescopo.
         */
        Codigo getCodigoProjeto() const;

        /**
         * @brief Define o identificador do usuário a ser integrado à equipe do projeto.
         * * @param emailPessoa Objeto da classe de domínio Email representando o colaborador.
         */
        void setEmailPessoa(Email emailPessoa);

        /**
         * @brief Recupera o identificador do colaborador associado a este projeto.
         * * @return Email Objeto de domínio contendo a chave do usuário da equipe.
         */
        Email getEmailPessoa() const;
};

#endif // ASSOCIACAOPROJETOPESSOA_H_INCLUDED
