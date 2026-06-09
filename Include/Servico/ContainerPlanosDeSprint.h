#ifndef CONTAINERPLANOSDESPRINT_H_INCLUDED
#define CONTAINERPLANOSDESPRINT_H_INCLUDED

#include<vector>
#include<entidade/PlanoDeSprint.h>
#include<dominio/Codigo.h>

/**
 * @brief Estrutura de armazenamento em memória para os ciclos de execução (Planos de Sprint).
 * * Implementa um contêiner responsável por gerenciar a persistência temporária das
 * iterações de projeto na camada de Serviço. Atua como um repositório local que
 * facilita operações rápidas de consulta e modificação, sendo essencial para a
 * validação de regras de negócio, como o limite de capacidade produtiva, antes da
 * consolidação definitiva no banco de dados.
 */
class ContainerPlanosDeSprint{
    private:
        std::vector<PlanoDeSprint> planos;

    public:
        /**
         * @brief Inicializa o repositório de planos de sprint em estado vazio.
         */
        ContainerPlanosDeSprint();

        /**
         * @brief Registra um novo ciclo de execução no armazenamento em memória.
         * * @param plano Objeto da entidade PlanoDeSprint preenchido com os dados a serem armazenados.
         */
        void inserir(const PlanoDeSprint &plano);

        /**
         * @brief Recupera os dados de um plano de sprint específico armazenado no contêiner.
         * * @param codigo Identificador único da iteração a ser localizada.
         * @return PlanoDeSprint Retorna a entidade populada com as informações recuperadas da memória.
         * @throw std::invalid_argument Lança exceção caso o código fornecido não corresponda a nenhum plano no contêiner.
         */
        PlanoDeSprint buscar(const Codigo &codigo) const;

        /**
         * @brief Remove permanentemente um ciclo de execução do repositório em memória.
         * * @param codigo Identificador único do plano de sprint a ser excluído do cache.
         */
        void remover(const Codigo &codigo);

        /**
         * @brief Recupera a totalidade dos ciclos de execução ativos registrados no contêiner.
         * * @return std::vector<PlanoDeSprint> Estrutura vetorial contendo todos os planos atualmente armazenados na memória.
         */
        std::vector<PlanoDeSprint> listar() const;
};

#endif // CONTAINERPLANOSDESPRINT_H_INCLUDED
