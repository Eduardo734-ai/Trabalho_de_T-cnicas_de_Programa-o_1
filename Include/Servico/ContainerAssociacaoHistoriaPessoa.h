#ifndef CONTAINERASSOCIACAOHISTORIAPESSOA_H_INCLUDED
#define CONTAINERASSOCIACAOHISTORIAPESSOA_H_INCLUDED

#include<vector>
#include"../associacao/AssociacaoHistoriaPessoa.h"

/**
 * @brief Estrutura de armazenamento em memória para os vínculos de responsabilidade.
 * * Implementa um contêiner (coleção de dados) responsável por persistir temporariamente
 * as relações de atribuição entre as histórias de usuário e os colaboradores (Pessoas).
 * Atua como o repositório de dados local da camada de Serviço para consultas e
 * validações rápidas de dependência antes da persistência definitiva no banco de dados.
 */
class ContainerAssociacaoHistoriaPessoa{
    private:
        std::vector<AssociacaoHistoriaPessoa> associacoes;

    public:
        /**
         * @brief Inicializa o repositório de associações em estado vazio.
         */
        ContainerAssociacaoHistoriaPessoa();

        /**
         * @brief Registra uma nova atribuição de tarefa no contêiner.
         * * @param associacao Objeto contendo os identificadores validados da história e do usuário.
         */
        void inserir(const AssociacaoHistoriaPessoa &associacao);

        /**
         * @brief Remove uma atribuição específica do armazenamento em memória.
         * * @param codigoHistoria Identificador único da tarefa.
         * @param emailPessoa Identificador único do usuário que será desvinculado.
         */
        void remover(const Codigo &codigoHistoria, const Email &emailPessoa);

        /**
         * @brief Recupera a totalidade dos vínculos de responsabilidade ativos no contêiner.
         * * @return std::vector<AssociacaoHistoriaPessoa> Estrutura vetorial contendo todas as associações registradas.
         */
        std::vector<AssociacaoHistoriaPessoa> listar() const;

        /**
         * @brief Verifica a existência de uma atribuição prévia no sistema.
         * * Utilizado por outras classes de serviço para validar regras de negócio,
         * impedindo que um usuário seja atribuído à mesma história mais de uma vez.
         * * @param codigoHistoria Identificador único da tarefa.
         * @param emailPessoa Identificador único do usuário.
         * @return true Caso a pessoa já esteja associada a esta história.
         * @return false Caso a associação não exista no contêiner.
         */
        bool existe(const Codigo &codigoHistoria, const Email &emailPessoa) const;
};

#endif // CONTAINERASSOCIACAOHISTORIAPESSOA_H_INCLUDED
