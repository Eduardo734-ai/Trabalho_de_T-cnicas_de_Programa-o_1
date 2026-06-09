#ifndef CONTAINERASSOCIACAOHISTORIAPROJETO_H_INCLUDED
#define CONTAINERASSOCIACAOHISTORIAPROJETO_H_INCLUDED

#include<vector>
#include"../associacao/AssociacaoHistoriaProjeto.h"

/**
 * @brief Estrutura de armazenamento em memória para os vínculos de backlog de projeto.
 * * Implementa um contêiner responsável por persistir temporariamente as relações que
 * alocam histórias de usuário ao escopo global de um projeto. Esta estrutura atua como
 * o repositório base para a camada de Serviço gerenciar os requisitos antes que eles
 * sejam movidos para iterações específicas (sprints).
 */
class ContainerAssociacaoHistoriaProjeto{
    private:
        std::vector<AssociacaoHistoriaProjeto> associacoes;

    public:
        /**
         * @brief Inicializa o repositório de associações de projeto em estado vazio.
         */
        ContainerAssociacaoHistoriaProjeto();

        /**
         * @brief Registra a alocação de uma história de usuário no escopo de um projeto.
         * * @param associacao Objeto contendo os identificadores validados da história e do macroescopo (projeto).
         */
        void inserir(const AssociacaoHistoriaProjeto &associacao);

        /**
         * @brief Remove o vínculo direto entre uma tarefa e o projeto.
         * * Ação tipicamente acionada pelas regras de negócio quando uma história é excluída
         * ou quando é executada a transição exclusiva de uma tarefa do projeto para um Plano de Sprint.
         * * @param codigoHistoria Identificador único da tarefa a ser desvinculada.
         * @param codigoProjeto Identificador único do projeto de onde a tarefa sairá.
         */
        void remover(const Codigo &codigoHistoria, const Codigo &codigoProjeto);

        /**
         * @brief Recupera a totalidade dos vínculos de backlog globais ativos no contêiner.
         * * @return std::vector<AssociacaoHistoriaProjeto> Estrutura vetorial contendo todas as associações registradas.
         */
        std::vector<AssociacaoHistoriaProjeto> listar() const;

        /**
         * @brief Verifica a existência prévia de uma associação de backlog no sistema.
         * * Utilizado pelas controladoras de serviço para evitar a duplicidade de alocação
         * da mesma história de usuário dentro do mesmo projeto.
         * * @param codigoHistoria Identificador único da tarefa.
         * @param codigoProjeto Identificador único do projeto.
         * @return true Caso a história já pertença ao backlog deste projeto.
         * @return false Caso a associação não exista no contêiner em memória.
         */
        bool existe(const Codigo &codigoHistoria, const Codigo &codigoProjeto) const;
};

#endif // CONTAINERASSOCIACAOHISTORIAPROJETO_H_INCLUDED
