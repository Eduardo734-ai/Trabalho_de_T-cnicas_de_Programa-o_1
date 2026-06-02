#ifndef SERVICOHISTORIAUSUARIO_H_INCLUDED
#define SERVICOHISTORIAUSUARIO_H_INCLUDED

#include <vector>

#include "../interface/IServicoHistoriaUsuario.h"

#include "../banco/RepositorioHistoriaUsuario.h"
#include "../banco/RepositorioAssociacaoHistoriaPessoa.h"
#include "../banco/RepositorioAssociacaoHistoriaPlano.h"

#include "ContainerPlanosDeSprint.h"

/**
 * @brief Implementação concreta do serviço de gestão de Histórias de Usuário.
 * * Esta classe materializa o contrato definido em IServicoHistoriaUsuario.
 * É responsável por orquestrar a comunicação entre as regras de negócio e a camada
 * de persistência definitiva (banco de dados SQLite), utilizando instâncias de Repositórios.
 * Também integra contêineres em memória para validações ágeis, como checagem de limites de
 * capacidade de sprints.
 */
class ServicoHistoriaUsuario : public IServicoHistoriaUsuario {
private:
    RepositorioHistoriaUsuario repositorioHistoria;

    RepositorioAssociacaoHistoriaPessoa repositorioAssociacaoHistoriaPessoa;
    RepositorioAssociacaoHistoriaPlano repositorioAssociacaoHistoriaPlano;

    ContainerPlanosDeSprint containerPlanos;

public:
    /**
     * @brief Inicializa o serviço instanciando as conexões com os repositórios de banco de dados.
     */
    ServicoHistoriaUsuario();

    /**
     * @brief Executa a persistência de um novo requisito no banco de dados.
     * * @param historia Objeto contendo os dados validados a serem gravados no SQLite.
     * @throw std::runtime_error Lança exceção em caso de falha na transação do banco de dados.
     */
    void criar(const HistoriaUsuario &historia) override;

    /**
     * @brief Consulta o banco de dados para recuperar os dados completos de uma história.
     * * @param codigo Identificador único da história a ser lida.
     * @return HistoriaUsuario Entidade preenchida com os dados do repositório.
     */
    HistoriaUsuario ler(const Codigo &codigo) override;

    /**
     * @brief Consolida a atualização de um requisito existente no banco de dados.
     * * @param historia Entidade contendo o identificador imutável e os novos dados.
     */
    void atualizar(const HistoriaUsuario &historia) override;

    /**
     * @brief Executa a deleção física ou lógica de um requisito no banco de dados.
     * * @param codigo Identificador da história a ser deletada.
     */
    void excluir(const Codigo &codigo) override;

    /**
     * @brief Persiste no banco de dados o vínculo entre um usuário e uma tarefa.
     * * @param codigoHistoria Identificador da história.
     * @param emailPessoa Identificador do colaborador responsável.
     */
    void associarPessoa(const Codigo &codigoHistoria, const Email &emailPessoa) override;

    /**
     * @brief Remove do banco de dados o vínculo de responsabilidade existente.
     * * @param codigoHistoria Identificador da história.
     * @param emailPessoa Identificador do colaborador a ser desvinculado.
     */
    void removerAssociacaoPessoa(const Codigo &codigoHistoria, const Email &emailPessoa) override;

    /**
     * @brief Realiza a junção de dados (JOIN lógico ou físico) para listar as histórias de um colaborador.
     * * @param emailPessoa Identificador do usuário.
     * @return std::vector<HistoriaUsuario> Lista de entidades recuperadas das tabelas de associação.
     */
    std::vector<HistoriaUsuario> listarHistoriasAssociadasPessoa(const Email &emailPessoa) override;

    /**
     * @brief Concretiza a regra de negócio de transição de escopo (Backlog para Sprint).
     * * Orquestra as operações transacionais necessárias para remover o vínculo genérico de projeto
     * e inserir o vínculo específico de plano de sprint, após validar a capacidade produtiva.
     * * @param codigoHistoria Identificador da história.
     * @param codigoProjeto Identificador do projeto de origem.
     * @param codigoPlano Identificador do plano de sprint de destino.
     */
    void moverParaSprint(const Codigo &codigoHistoria,
                         const Codigo &codigoProjeto,
                         const Codigo &codigoPlano) override;

    /**
     * @brief Executa a transação isolada de mudança de estado da história no banco (ex: A FAZER para FAZENDO).
     * * @param codigoHistoria Identificador da tarefa.
     * @param estado Novo estado do Kanban validado.
     */
    void alterarEstado(const Codigo &codigoHistoria, const Estado &estado) override;

    /**
     * @brief Registra um plano de sprint no contêiner em memória do serviço.
     * * Utilizado como cache local para agilizar a validação matemática de esforço (story points)
     * da sprint sem a necessidade de múltiplas consultas ao banco.
     * * @param plano Objeto do plano de sprint a ser cacheado.
     */
    void registrarPlano(const PlanoDeSprint &plano);

    /**
     * @brief Consulta o repositório para resgatar todas as histórias alocadas em uma sprint.
     * * @param codigoPlano Identificador único do plano de sprint.
     * @return std::vector<HistoriaUsuario> Coleção de histórias alocadas.
     */
    std::vector<HistoriaUsuario> listarHistoriasAssociadasPlano(const Codigo &codigoPlano);

    /**
     * @brief Executa uma atualização granular direta de propriedades na entidade.
     * * Oferece uma sobrecarga otimizada para modificar múltiplos atributos de uma história
     * simultaneamente sem a necessidade de passar o objeto completo.
     * * @param codigo Identificador imutável da tarefa a ser atualizada.
     * @param nome Novo título ou nome.
     * @param papel Novo papel de usuário (Quem).
     * @param acao Nova ação descritiva (O quê).
     * @param valor Novo benefício esperado (Por quê).
     * @param estimativa Novo esforço calculado para a tarefa.
     * @param prioridade Nova classificação de prioridade.
     */
    void atualizarDadosHistoria(const Codigo &codigo,
                                const Nome &nome,
                                const Papel &papel,
                                const Texto &acao,
                                const Texto &valor,
                                const Tempo &estimativa,
                                const Prioridade &prioridade);
};

#endif
