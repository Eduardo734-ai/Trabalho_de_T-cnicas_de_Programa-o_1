#ifndef SERVICOPLANODESPRINT_H_INCLUDED
#define SERVICOPLANODESPRINT_H_INCLUDED

#include <vector>

#include "../interface/IServicoPlanoDeSprint.h"

#include "../banco/RepositorioPlanoDeSprint.h"
#include "../banco/RepositorioAssociacaoHistoriaPlano.h"

#include "ContainerHistoriasUsuario.h"

/**
 * @brief Implementação concreta do serviço de gestão de Planos de Sprint.
 * * Esta classe materializa o contrato definido em IServicoPlanoDeSprint.
 * É responsável por orquestrar a persistência dos ciclos de execução no banco de dados
 * SQLite e gerenciar a alocação de tarefas (Histórias de Usuário) dentro dessas iterações.
 * Utiliza contêineres em memória para otimizar operações locais antes de consolidar
 * as associações físicas.
 */
class ServicoPlanoDeSprint : public IServicoPlanoDeSprint {
private:
    RepositorioPlanoDeSprint repositorioPlano;
    RepositorioAssociacaoHistoriaPlano repositorioAssociacaoHistoriaPlano;

    ContainerHistoriasUsuario containerHistorias;

public:
    /**
     * @brief Inicializa o serviço estabelecendo as conexões com os repositórios de banco de dados.
     */
    ServicoPlanoDeSprint();

    /**
     * @brief Executa a persistência de um novo plano de sprint no banco de dados.
     * * @param plano Objeto contendo os dados validados do ciclo de execução a ser gravado.
     * @throw std::runtime_error Lança exceção em caso de falha na transação do SQLite ou duplicidade de código.
     */
    void criar(const PlanoDeSprint &plano) override;

    /**
     * @brief Consulta o banco de dados para recuperar os dados de um plano de sprint.
     * * @param codigo Identificador único da iteração a ser lida.
     * @return PlanoDeSprint Entidade preenchida com as informações do repositório físico.
     * @throw std::invalid_argument Lança exceção caso o código não seja encontrado.
     */
    PlanoDeSprint ler(const Codigo &codigo) override;

    /**
     * @brief Consolida a atualização das propriedades de um sprint existente no banco de dados.
     * * @param plano Entidade contendo o identificador imutável e os novos dados de capacidade ou objetivo.
     */
    void atualizar(const PlanoDeSprint &plano) override;

    /**
     * @brief Executa a remoção definitiva de um plano de sprint no banco de dados.
     * * @param codigo Identificador único do plano a ser deletado fisicamente.
     */
    void excluir(const Codigo &codigo) override;

    /**
     * @brief Consulta as tabelas de associação para listar todas as tarefas alocadas neste sprint.
     * * @param codigoPlano Identificador único do plano de sprint.
     * @return std::vector<HistoriaUsuario> Lista de entidades recuperadas representando o escopo da iteração.
     */
    std::vector<HistoriaUsuario> listarHistoriasAssociadasPlano(const Codigo &codigoPlano) override;

    /**
     * @brief Cacheia uma história de usuário no contêiner em memória do serviço.
     * * Otimiza o acesso a instâncias de histórias durante operações complexas,
     * como a validação e o somatório de capacidade da sprint, minimizando o tráfego com o banco de dados.
     * * @param historia Objeto da história a ser mantido temporariamente em memória.
     */
    void registrarHistoria(const HistoriaUsuario &historia);

    /**
     * @brief Persiste fisicamente o vínculo de alocação entre uma tarefa e o sprint no banco de dados.
     * * @param codigoHistoria Identificador único da tarefa a ser alocada.
     * @param codigoPlano Identificador único da iteração de destino.
     */
    void associarHistoriaPlano(const Codigo &codigoHistoria, const Codigo &codigoPlano);
};

#endif // SERVICOPLANODESPRINT_H_INCLUDED
