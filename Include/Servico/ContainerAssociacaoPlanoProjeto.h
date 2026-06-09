#ifndef CONTAINERASSOCIACAOPLANOPROJETO_H_INCLUDED
#define CONTAINERASSOCIACAOPLANOPROJETO_H_INCLUDED

#include<vector>
#include"../associacao/AssociacaoPlanoProjeto.h"

/**
 * @brief Estrutura de armazenamento em memória para os vínculos hierárquicos entre sprints e projetos.
 * * Implementa um contêiner responsável por persistir temporariamente as relações de pertencimento
 * dos ciclos de execução (Planos de Sprint) aos seus respectivos macroescopos (Projetos).
 * Esta estrutura garante a integridade estrutural do sistema na camada de Serviço, permitindo
 * a validação de regras de negócio antes da persistência definitiva no banco de dados.
 */
class ContainerAssociacaoPlanoProjeto{
    private:
        std::vector<AssociacaoPlanoProjeto> associacoes;

    public:
        /**
         * @brief Inicializa o repositório de associações estruturais em estado vazio.
         */
        ContainerAssociacaoPlanoProjeto();

        /**
         * @brief Registra a alocação de um ciclo de execução dentro de um projeto específico.
         * * @param associacao Objeto contendo os identificadores validados do plano de sprint e do projeto pai.
         */
        void inserir(const AssociacaoPlanoProjeto &associacao);

        /**
         * @brief Remove o vínculo estrutural entre um plano de sprint e o seu projeto.
         * * Ação acionada pelas regras de negócio quando um plano de sprint é excluído do sistema
         * ou precisa ser desvinculado de um escopo.
         * * @param codigoPlano Identificador único do ciclo de execução a ser desvinculado.
         * @param codigoProjeto Identificador único do macroescopo de origem.
         */
        void remover(const Codigo &codigoPlano, const Codigo &codigoProjeto);

        /**
         * @brief Recupera a totalidade dos vínculos hierárquicos ativos no contêiner.
         * * @return std::vector<AssociacaoPlanoProjeto> Estrutura vetorial contendo todas as associações registradas.
         */
        std::vector<AssociacaoPlanoProjeto> listar() const;

        /**
         * @brief Verifica a existência prévia de um vínculo estrutural no sistema.
         * * Utilizado para garantir que um mesmo plano de sprint não seja cadastrado repetidas vezes
         * sob o mesmo projeto, validando a integridade do escopo.
         * * @param codigoPlano Identificador único do ciclo de execução.
         * @param codigoProjeto Identificador único do projeto.
         * @return true Caso o plano de sprint já pertença a este projeto.
         * @return false Caso o vínculo hierárquico não exista no contêiner em memória.
         */
        bool existe(const Codigo &codigoPlano, const Codigo &codigoProjeto) const;
};

#endif // CONTAINERASSOCIACAOPLANOPROJETO_H_INCLUDED
