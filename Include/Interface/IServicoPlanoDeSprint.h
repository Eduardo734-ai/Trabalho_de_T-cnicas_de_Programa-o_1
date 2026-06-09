#ifndef ISERVICOPLANODESPRINT_H_INCLUDED
#define ISERVICOPLANODESPRINT_H_INCLUDED

#include<vector>

#include"entidade/PlanoDeSprint.h"
#include"entidade/HistoriaUsuario.h"
#include"dominio/Codigo.h"

using namespace std;

/**
 * @brief Contrato de delegação de lógica de negócio para a gestão de Planos de Sprint.
 * * Declara a interface abstrata responsável por definir as operações de ciclo de vida
 * (criação, leitura, atualização e exclusão) das iterações de trabalho do projeto.
 * Esta interface garante o isolamento arquitetural, assegurando que a camada de Apresentação
 * possa manipular os ciclos de execução sem se acoplar aos detalhes de armazenamento no banco de dados.
 */
class IServicoPlanoDeSprint{
    public:
        /**
         * @brief Registra um novo ciclo de execução no sistema.
         * * @param plano Objeto da entidade PlanoDeSprint preenchido com dados validados (código, objetivo e capacidade).
         * @throw std::runtime_error Lança exceção caso já exista um plano cadastrado com o mesmo código ou ocorra erro de persistência.
         */
        virtual void criar(const PlanoDeSprint &plano) = 0;

        /**
         * @brief Recupera os dados completos de um plano de sprint cadastrado.
         * * @param codigo Identificador único do ciclo de execução a ser buscado.
         * @return PlanoDeSprint Retorna a entidade populada com os dados recuperados do sistema.
         * @throw std::invalid_argument Lança exceção caso o código fornecido não seja encontrado nos registros.
         */
        virtual PlanoDeSprint ler(const Codigo &codigo) = 0;

        /**
         * @brief Sobrescreve as informações de um plano de sprint já existente.
         * * @param plano Objeto contendo o código do plano original e os novos dados a serem atualizados (objetivo ou capacidade).
         * @throw std::invalid_argument Lança exceção caso o plano de sprint não exista no sistema.
         */
        virtual void atualizar(const PlanoDeSprint &plano) = 0;

        /**
         * @brief Remove definitivamente um plano de sprint do sistema.
         * * A exclusão de um plano deve tratar a remoção de seus vínculos nas tabelas de associação,
         * garantindo a integridade referencial com as histórias de usuário.
         * * @param codigo Identificador único do plano a ser deletado.
         * @throw std::invalid_argument Lança exceção caso o código não seja localizado para exclusão.
         */
        virtual void excluir(const Codigo &codigo) = 0;

        /**
         * @brief Recupera a lista de todas as histórias de usuário associadas a um plano de sprint específico.
         * * @param codigoPlano Identificador único do plano de sprint.
         * @return vector<HistoriaUsuario> Retorna uma estrutura vetorial contendo todas as histórias contidas neste ciclo.
         */
        virtual vector<HistoriaUsuario> listarHistoriasAssociadasPlano(const Codigo &codigoPlano) = 0;

        /**
         * @brief Destrutor virtual padrão.
         * * Garante a destruição correta de objetos derivados através do ponteiro da classe base.
         */
        virtual ~IServicoPlanoDeSprint(){}
};

#endif // ISERVICOPLANODESPRINT_H_INCLUDED
