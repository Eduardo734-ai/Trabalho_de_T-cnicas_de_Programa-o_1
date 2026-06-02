#ifndef CONTAINERASSOCIACAOHISTORIAPLANO_H_INCLUDED
#define CONTAINERASSOCIACAOHISTORIAPLANO_H_INCLUDED

#include<vector>
#include"../associacao/AssociacaoHistoriaPlano.h"

/**
 * @brief Estrutura de armazenamento em memória para os vínculos de alocação em sprints.
 * * Implementa um contêiner responsável por persistir temporariamente as relações que
 * alocam histórias de usuário dentro de ciclos de execução (Planos de Sprint).
 * Esta estrutura é fundamental para a camada de Serviço consultar e validar a
 * regra de negócio de exclusividade (se a história já está no sprint) e para o
 * cálculo da capacidade total de esforço antes da persistência definitiva.
 */
class ContainerAssociacaoHistoriaPlano{
    private:
        std::vector<AssociacaoHistoriaPlano> associacoes;

    public:
        /**
         * @brief Inicializa o repositório de associações de sprint em estado vazio.
         */
        ContainerAssociacaoHistoriaPlano();

        /**
         * @brief Registra a alocação de uma história de usuário em um plano de sprint no contêiner.
         * * @param associacao Objeto contendo os identificadores validados da história e do ciclo de execução.
         */
        void inserir(const AssociacaoHistoriaPlano &associacao);

        /**
         * @brief Remove o vínculo de alocação entre uma tarefa e um ciclo de execução específico.
         * * @param codigoHistoria Identificador único da tarefa a ser removida do sprint.
         * @param codigoPlano Identificador único do plano de sprint de onde a tarefa sairá.
         */
        void remover(const Codigo &codigoHistoria, const Codigo &codigoPlano);

        /**
         * @brief Recupera a totalidade dos vínculos de alocação de sprint ativos no contêiner.
         * * @return std::vector<AssociacaoHistoriaPlano> Estrutura vetorial contendo todas as associações registradas.
         */
        std::vector<AssociacaoHistoriaPlano> listar() const;

        /**
         * @brief Verifica a existência prévia de uma alocação específica no sistema.
         * * Utilizado pelas controladoras de serviço para evitar duplicação de vínculos
         * e garantir a integridade das validações de regras de negócio.
         * * @param codigoHistoria Identificador único da tarefa.
         * @param codigoPlano Identificador único do plano de sprint.
         * @return true Caso a história já esteja vinculada a este plano de sprint.
         * @return false Caso a associação não exista no contêiner em memória.
         */
        bool existe(const Codigo &codigoHistoria, const Codigo &codigoPlano) const;
};

#endif // CONTAINERASSOCIACAOHISTORIAPLANO_H_INCLUDED
