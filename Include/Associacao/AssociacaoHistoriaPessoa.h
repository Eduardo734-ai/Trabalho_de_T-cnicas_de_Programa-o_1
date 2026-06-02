#ifndef ASSOCIACAOHISTORIAPESSOA_H_INCLUDED
#define ASSOCIACAOHISTORIAPESSOA_H_INCLUDED

#include"dominio/Codigo.h"
#include"dominio/Email.h"

/**
 * @brief Classe de associação que vincula uma História de Usuário a um Colaborador (Pessoa).
 * * Atua como uma entidade associativa no modelo orientado a objetos, mapeando a
 * relação de atribuição e responsabilidade entre uma tarefa estrutural e o usuário
 * encarregado de desenvolvê-la. É fundamental para o sistema rastrear e listar
 * os afazeres de cada membro da equipe.
 */
class AssociacaoHistoriaPessoa{
    private:
        Codigo codigoHistoria;
        Email emailPessoa;

    public:
        /**
         * @brief Define o identificador da tarefa que está sendo atribuída.
         * * @param codigoHistoria Objeto da classe de domínio Codigo representando a história de usuário.
         */
        void setCodigoHistoria(Codigo codigoHistoria);

        /**
         * @brief Recupera o identificador da tarefa associada neste vínculo.
         * * @return Codigo Objeto de domínio contendo a chave da história de usuário.
         */
        Codigo getCodigoHistoria() const;

        /**
         * @brief Define o identificador do colaborador que assumirá a tarefa.
         * * @param emailPessoa Objeto da classe de domínio Email representando o usuário responsável.
         */
        void setEmailPessoa(Email emailPessoa);

        /**
         * @brief Recupera o identificador do colaborador vinculado a esta tarefa.
         * * @return Email Objeto de domínio contendo a chave do usuário responsável.
         */
        Email getEmailPessoa() const;
};

#endif // ASSOCIACAOHISTORIAPESSOA_H_INCLUDED
