#ifndef CONTROLADORAPLANODESPRINT_H_INCLUDED
#define CONTROLADORAPLANODESPRINT_H_INCLUDED

#include "../Servico/ServicoPlanoDeSprint.h"
#include "../Servico/ServicoProjeto.h"
#include "../Servico/ServicoHistoriaUsuario.h"

/**
 * @brief Classe controladora responsável pela interface de usuário para operações de Plano de Sprint.
 *
 * Esta classe pertence à camada de Apresentação e atua como intermediária entre as interações no terminal e
 * as lógicas de negócio dos ciclos de execução do framework Scrum. Ela gerencia o menu específico para a
 * entidade PlanoDeSprint, captura as entradas de dados, realiza validações iniciais e repassa os comandos
 * de CRUD (Criar, Ler, Atualizar, Excluir) para os serviços correspondentes.
 */
class ControladoraPlanoDeSprint {
private:
    ServicoPlanoDeSprint* servicoPlano;      ///< Ponteiro para a interface de serviço que gerencia as regras de negócio dos Sprints.
    ServicoProjeto* servicoProjeto;          ///< Ponteiro para a interface de serviço de projetos, utilizado para validações de escopo.
    ServicoHistoriaUsuario* servicoHistoria; ///< Ponteiro para a interface de serviço de histórias, utilizado para checar capacidades e estimativas.

    /**
     * @brief Renderiza no terminal o menu de opções disponíveis para o gerenciamento de Planos de Sprint.
     */
    void menuPlano();

    /**
     * @brief Interface visual que coleta os dados preenchidos pelo usuário para o cadastro de um novo Plano de Sprint.
     */
    void criarPlano();

    /**
     * @brief Solicita o identificador único (Código) e exibe em tela todos os atributos do Plano de Sprint correspondente.
     */
    void lerPlano();

    /**
     * @brief Coleta as novas informações fornecidas pelo usuário para atualizar os dados de um Plano de Sprint pré-existente.
     */
    void atualizarPlano();

    /**
     * @brief Solicita o identificador único (Código) e coordena a exclusão de um Plano de Sprint do sistema.
     */
    void excluirPlano();

public:
    /**
     * @brief Construtor da classe que estabelece a injeção de dependência dos componentes da camada de Serviço.
     * * @param servicoPlano Ponteiro para o módulo responsável pela persistência e regras dos planos de sprint.
     * @param servicoProjeto Ponteiro para o módulo responsável pela gestão dos macroescopos (projetos).
     * @param servicoHistoria Ponteiro para o módulo de histórias, necessário para validações cruzadas de capacidade.
     */
    ControladoraPlanoDeSprint(
        ServicoPlanoDeSprint* servicoPlano,
        ServicoProjeto* servicoProjeto,
        ServicoHistoriaUsuario* servicoHistoria
    );

    /**
     * @brief Dispara o fluxo principal de execução do controlador, mantendo o usuário no loop do menu interativo.
     */
    void executar();
};

#endif // CONTROLADORAPLANODESPRINT_H_INCLUDED
