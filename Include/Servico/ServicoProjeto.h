#ifndef SERVICOPROJETO_H_INCLUDED
#define SERVICOPROJETO_H_INCLUDED

#include <vector>

#include "../interface/IServicoProjeto.h"
#include "../entidade/Pessoa.h"

#include "../banco/RepositorioProjeto.h"
#include "../banco/RepositorioAssociacaoProjetoPessoa.h"
#include "../banco/RepositorioAssociacaoHistoriaProjeto.h"
#include "../banco/RepositorioAssociacaoPlanoProjeto.h"
#include "../banco/RepositorioPlanoDeSprint.h"
#include "../banco/RepositorioHistoriaUsuario.h"

#include "ContainerHistoriasUsuario.h"
#include "ContainerPlanosDeSprint.h"

/**
 * @brief Implementação concreta do serviço de gestão e governança de Projetos.
 *
 * Esta classe materializa o contrato definido em IServicoProjeto e atua como a
 * orquestradora principal da camada de Serviço. É responsável por integrar múltiplos
 * repositórios do SQLite para persistir a hierarquia do sistema (Projetos, Sprints e Backlog)
 * e gerenciar o controle de acesso das equipes (Pessoas). Utiliza contêineres em memória
 * para otimização do acesso a dados locais durante o processamento das regras de negócio.
 */
class ServicoProjeto : public IServicoProjeto {
private:
    RepositorioProjeto repositorioProjeto;
    RepositorioPlanoDeSprint repositorioPlano;
    RepositorioHistoriaUsuario repositorioHistoria;

    RepositorioAssociacaoProjetoPessoa repositorioAssociacaoProjetoPessoa;
    RepositorioAssociacaoHistoriaProjeto repositorioAssociacaoHistoriaProjeto;
    RepositorioAssociacaoPlanoProjeto repositorioAssociacaoPlanoProjeto;

    ContainerHistoriasUsuario containerHistorias;
    ContainerPlanosDeSprint containerPlanos;

public:
    /**
     * @brief Inicializa o serviço estabelecendo as conexões com todos os repositórios físicos e contêineres locais.
     */
    ServicoProjeto();

    /**
     * @brief Executa a persistência de um novo macroescopo no banco de dados.
     * @param projeto Objeto contendo os dados validados do projeto a ser gravado.
     * @throw std::runtime_error Lança exceção em caso de falha transacional ou duplicidade.
     */
    void criar(const Projeto &projeto) override;

    /**
     * @brief Consulta o repositório físico para recuperar a estrutura completa de um projeto.
     * @param codigo Identificador único do projeto a ser localizado.
     * @return Projeto Entidade preenchida com as informações do banco de dados.
     */
    Projeto ler(const Codigo &codigo) override;

    /**
     * @brief Consolida a atualização da entidade Projeto inteira no repositório.
     * @param projeto Entidade contendo o identificador original e os novos atributos.
     */
    void atualizar(const Projeto &projeto) override;

    /**
     * @brief Executa a remoção física de um projeto, acionando a deleção em cascata de suas associações.
     * @param codigo Identificador do projeto a ser excluído.
     */
    void excluir(const Codigo &codigo) override;

    /**
     * @brief Executa uma atualização granular direta das propriedades do projeto.
     * * Permite modificar parâmetros estruturais e cronograma sem a necessidade de instanciar a entidade inteira.
     * * @param codigo Identificador imutável do projeto.
     * @param nome Novo título do empreendimento.
     * @param inicio Nova data de vigência inicial.
     * @param termino Nova data de vigência final.
     */
    void atualizarDadosProjeto(const Codigo &codigo,
                               const Nome &nome,
                               const Data &inicio,
                               const Data &termino);

    /**
     * @brief Transação composta: Cria um projeto e simultaneamente aloca um colaborador inicial.
     * * Essencial para fluxos onde o criador do projeto (ex: Mestre Scrum) já deve ser inserido automaticamente na equipe.
     * * @param projeto Nova entidade de projeto.
     * @param pessoa Colaborador a ser associado como membro fundador.
     */
    void criarAssociadoPessoa(const Projeto &projeto, const Pessoa &pessoa);

    /**
     * @brief Transação composta: Registra uma nova tarefa e já a insere no backlog global do projeto.
     * @param historia Nova entidade de requisito funcional.
     * @param codigoProjeto Identificador do macroescopo de destino.
     */
    void criarHistoriaAssociadaProjeto(HistoriaUsuario historia, const Codigo &codigoProjeto);

    /**
     * @brief Transação composta: Registra um novo ciclo de execução e o subordina hierarquicamente a um projeto.
     * @param plano Nova entidade de sprint.
     * @param codigoProjeto Identificador do macroescopo pai.
     */
    void criarPlanoAssociadoProjeto(const PlanoDeSprint &plano, const Codigo &codigoProjeto);

    /**
     * @brief Agrupa os macroescopos vinculados a um usuário consultando as tabelas de associação físicas.
     * @param email Identificador único do usuário.
     * @return std::vector<Projeto> Lista de projetos que o usuário possui acesso.
     */
    std::vector<Projeto> listarProjetosAssociadosPessoa(const Email &email) override;

    /**
     * @brief Resgata todas as histórias de usuário que compõem o backlog ativo do projeto.
     * @param codigoProjeto Identificador único do escopo.
     * @return std::vector<HistoriaUsuario> Lista de tarefas alocadas globalmente ao projeto.
     */
    std::vector<HistoriaUsuario> listarHistoriasAssociadasProjeto(const Codigo &codigoProjeto) override;

    /**
     * @brief Lista todos os ciclos de execução (Sprints) que pertencem estruturalmente ao projeto.
     * @param codigoProjeto Identificador único do escopo pai.
     * @return std::vector<PlanoDeSprint> Lista cronológica de iterações do projeto.
     */
    std::vector<PlanoDeSprint> listarPlanosAssociadosProjeto(const Codigo &codigoProjeto) override;

    /**
     * @brief Persiste o vínculo direto de acesso/permissão entre um usuário e um projeto.
     * @param codigoProjeto Identificador único do projeto.
     * @param emailPessoa Identificador do colaborador.
     */
    void associarProjetoPessoa(const Codigo &codigoProjeto, const Email &emailPessoa);

    /**
     * @brief Remove fisicamente o vínculo de colaboração/acesso entre um usuário e um projeto.
     * @param codigoProjeto Identificador único do macroescopo.
     * @param emailPessoa Identificador do colaborador a ser desvinculado da equipe.
     */
    void removerAssociacaoProjetoPessoa(const Codigo &codigoProjeto, const Email &emailPessoa);

    /**
     * @brief Persiste a alocação de uma tarefa existente no backlog do escopo global de um projeto.
     * @param codigoHistoria Identificador da tarefa.
     * @param codigoProjeto Identificador do projeto.
     */
    void associarHistoriaProjeto(const Codigo &codigoHistoria, const Codigo &codigoProjeto);

    /**
     * @brief Persiste a subordinação de uma sprint pré-existente à estrutura de um projeto.
     * @param codigoPlano Identificador da iteração.
     * @param codigoProjeto Identificador do projeto pai.
     */
    void associarPlanoProjeto(const Codigo &codigoPlano, const Codigo &codigoProjeto);

    /**
     * @brief Adiciona uma história de usuário ao cache em memória do serviço para validações rápidas.
     * @param historia Objeto de requisito funcional.
     */
    void registrarHistoria(const HistoriaUsuario &historia);

    /**
     * @brief Adiciona um plano de sprint ao cache em memória do serviço para otimização de consultas de capacidade.
     * @param plano Objeto de ciclo de execução.
     */
    void registrarPlano(const PlanoDeSprint &plano);
};

#endif // SERVICOPROJETO_H_INCLUDED
