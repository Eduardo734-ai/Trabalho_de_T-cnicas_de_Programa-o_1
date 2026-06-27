#ifndef CONTROLADORAASSOCIACOES_H_INCLUDED
#define CONTROLADORAASSOCIACOES_H_INCLUDED

#include "../Servico/ServicoAutenticacao.h"
#include "../Servico/ServicoPessoa.h"
#include "../Servico/ServicoProjeto.h"
#include "../Servico/ServicoPlanoDeSprint.h"
#include "../Servico/ServicoHistoriaUsuario.h"

/**
 * @brief Classe controladora responsável pela interface de usuário na camada de Apresentação para operações de associação.
 *
 * Esta classe gerencia a navegação de menus e a captura de dados via terminal para estabelecer, remover
 * ou listar os vínculos complexos e cardinalidades entre as entidades centrais do sistema (Pessoas, Projetos,
 * Planos de Sprint e Histórias de Usuário). Ela valida os formatos iniciais e coordena as chamadas correspondentes
 * na camada de Serviço para manter a integridade das regras do framework Scrum.
 */
class ControladoraAssociacoes {
private:
    ServicoAutenticacao* servicoAutenticacao; ///< Ponteiro para o componente de controle de sessão e autenticação.
    ServicoPessoa* servicoPessoa;             ///< Ponteiro para o componente de regras de negócio de usuários.
    ServicoProjeto* servicoProjeto;           ///< Ponteiro para o componente de regras de negócio de macroescopos.
    ServicoPlanoDeSprint* servicoPlano;       ///< Ponteiro para o componente de regras de negócio de ciclos de execução.
    ServicoHistoriaUsuario* servicoHistoria;   ///< Ponteiro para o componente de regras de negócio de requisitos (Histórias).


    /**
     * @brief Renderiza no terminal o menu principal dedicado às operações de vinculação, alocação e listagens associativas.
     */
    void menuAssociacoes();

    /**
     * @brief Interface que gerencia a entrada de dados para vincular a responsabilidade de uma História de Usuário a uma Pessoa.
     */
    void associarHistoriaPessoa();

    /**
     * @brief Interface que gerencia a entrada de dados para romper o vínculo de responsabilidade entre uma História de Usuário e uma Pessoa.
     */
    void removerAssociacaoHistoriaPessoa();

    /**
     * @brief Solicita o identificador do usuário e apresenta a listagem de todos os Projetos aos quais a Pessoa está associada.
     */

    void removerAssociacaoProjetoPessoa();


    void listarProjetosPessoa();

    /**
     * @brief Solicita o identificador do projeto e apresenta todas as Histórias de Usuário que compõem o seu Product Backlog global.
     */
    void listarHistoriasProjeto();

    /**
     * @brief Solicita o identificador do projeto e apresenta a lista de todos os Planos de Sprint que pertencem àquele macroescopo.
     */
    void listarPlanosProjeto();

    /**
     * @brief Apresenta as Histórias de Usuário alocadas no escopo de um Plano de Sprint específico (Sprint Backlog).
     */
    void listarHistoriasPlano();

    /**
     * @brief Apresenta todas as Histórias de Usuário que estão sob a responsabilidade e execução de um colaborador específico.
     */
    void listarHistoriasPessoa();

    /**
     * @brief Interface para transferir ou alocar uma História de Usuário do escopo geral do Projeto para um Plano de Sprint ativo.
     */
    void moverHistoriaParaSprint();

    /**
     * @brief Interface visual que permite a alteração controlada do estágio de desenvolvimento (Estado) de uma História de Usuário.
     */
    void alterarEstadoHistoria();

public:
    /**
     * @brief Construtor da classe controladora que estabelece a injeção de dependência de todos os serviços necessários.
     * * @param servicoAutenticacao Abstração do serviço de controle de acessos e login.
     * @param servicoPessoa Abstração do serviço de gerenciamento de usuários.
     * @param servicoProjeto Abstração do serviço de gerenciamento de escopos de projetos.
     * @param servicoPlano Abstração do serviço de gerenciamento de ciclos de sprints.
     * @param servicoHistoria Abstração do serviço de gerenciamento de requisitos.
     */
    ControladoraAssociacoes(
        ServicoAutenticacao* servicoAutenticacao,
        ServicoPessoa* servicoPessoa,
        ServicoProjeto* servicoProjeto,
        ServicoPlanoDeSprint* servicoPlano,
        ServicoHistoriaUsuario* servicoHistoria
    );

    /**
     * @brief Dispara o fluxo de controle principal da interface de associações, exibindo o menu interativo e capturando as opções.
     */
    void executar();

    /**
     * @brief Ponto de entrada alternativo para acionar diretamente o fluxo isolado de modificação de estado de progresso de uma tarefa.
     */
    void executarAlterarEstado();
};

#endif // CONTROLADORAASSOCIACOES_H_INCLUDED
