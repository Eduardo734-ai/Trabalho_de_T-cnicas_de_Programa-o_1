#ifndef CONTROLADORASISTEMA_H_INCLUDED
#define CONTROLADORASISTEMA_H_INCLUDED

#include "../servico/ServicoAutenticacao.h"
#include "../servico/ServicoPessoa.h"
#include "../servico/ServicoProjeto.h"
#include "../servico/ServicoPlanoDeSprint.h"
#include "../servico/ServicoHistoriaUsuario.h"

/**
 * @brief Orquestradora principal da camada de Apresentação (Interface de Usuário).
 * * Atua como o ponto central de interação do sistema. É responsável por renderizar
 * os menus no terminal, capturar as entradas do usuário, tratar erros de interface
 * e delegar o processamento das regras de negócio para as respectivas classes da
 * camada de Serviço. Mantém o ciclo de vida da aplicação ativo através de loops de execução.
 */
class ControladoraSistema {
private:
    ServicoAutenticacao servicoAutenticacao;
    ServicoPessoa servicoPessoa;
    ServicoProjeto servicoProjeto;
    ServicoPlanoDeSprint servicoPlano;
    ServicoHistoriaUsuario servicoHistoria;

    /** @brief Renderiza o menu de boas-vindas (Login/Cadastro/Sair). */
    void menuInicial();
    /** @brief Renderiza o painel central de navegação pós-autenticação. */
    void menuPrincipal();
    /** @brief Renderiza as opções de gestão de usuários (Pessoas). */
    void menuPessoa();
    /** @brief Renderiza as opções de gestão de macroescopos (Projetos). */
    void menuProjeto();
    /** @brief Renderiza as opções de gestão de iterações (Planos de Sprint). */
    void menuPlano();
    /** @brief Renderiza as opções de gestão de requisitos (Histórias de Usuário). */
    void menuHistoria();
    /** @brief Renderiza as opções de gestão de vínculos estruturais e de equipe. */
    void menuAssociacoes();

    /** @brief Coleta dados de entrada e aciona o serviço de cadastro de novo usuário. */
    void executarCadastro();
    /** @brief Coleta credenciais e aciona a validação de sessão no serviço de autenticação. */
    void executarLogin();
    /** @brief Encerra a sessão ativa do usuário e retorna ao menu inicial. */
    void executarLogout();

    /** @brief Gerencia o fluxo da tela do submenu de Pessoas. */
    void controlarPessoa();
    /** @brief Gerencia o fluxo da tela do submenu de Projetos. */
    void controlarProjeto();
    /** @brief Gerencia o fluxo da tela do submenu de Planos de Sprint. */
    void controlarPlano();
    /** @brief Gerencia o fluxo da tela do submenu de Histórias de Usuário. */
    void controlarHistoria();
    /** @brief Gerencia o fluxo da tela do submenu de Associações e Relatórios. */
    void controlarAssociacoes();

    /** @brief Fluxo de UI para coletar dados e solicitar a criação de uma Pessoa. */
    void criarPessoa();
    /** @brief Fluxo de UI para buscar e exibir os dados de uma Pessoa. */
    void lerPessoa();
    /** @brief Fluxo de UI para coletar novos dados e solicitar a atualização de uma Pessoa. */
    void atualizarPessoa();
    /** @brief Fluxo de UI para confirmar e solicitar a deleção de uma Pessoa. */
    void excluirPessoa();

    /** @brief Fluxo de UI para criar um Projeto. */
    void criarProjeto();
    /** @brief Fluxo de UI para buscar e exibir os dados de um Projeto. */
    void lerProjeto();
    /** @brief Fluxo de UI para atualizar os dados de um Projeto. */
    void atualizarProjeto();
    /** @brief Fluxo de UI para deletar um Projeto. */
    void excluirProjeto();

    /** @brief Fluxo de UI para criar um Plano de Sprint. */
    void criarPlano();
    /** @brief Fluxo de UI para buscar e exibir os dados de um Plano de Sprint. */
    void lerPlano();
    /** @brief Fluxo de UI para atualizar os dados de um Plano de Sprint. */
    void atualizarPlano();
    /** @brief Fluxo de UI para deletar um Plano de Sprint. */
    void excluirPlano();

    /** @brief Fluxo de UI para criar uma História de Usuário. */
    void criarHistoria();
    /** @brief Fluxo de UI para buscar e exibir os dados de uma História de Usuário. */
    void lerHistoria();
    /** @brief Fluxo de UI para atualizar os dados de uma História de Usuário. */
    void atualizarHistoria();
    /** @brief Fluxo de UI para deletar uma História de Usuário. */
    void excluirHistoria();

    /** @brief Fluxo de UI para vincular um colaborador a uma tarefa. */
    void associarHistoriaPessoa();
    /** @brief Fluxo de UI para desvincular um colaborador de uma tarefa. */
    void removerAssociacaoHistoriaPessoa();
    /** @brief Exibe na tela todos os projetos aos quais o usuário atual tem acesso. */
    void listarProjetosPessoa();
    /** @brief Exibe na tela todo o backlog (histórias) pertencente a um projeto. */
    void listarHistoriasProjeto();
    /** @brief Exibe na tela todos os ciclos de execução (sprints) de um projeto. */
    void listarPlanosProjeto();
    /** @brief Exibe na tela as tarefas alocadas em um sprint específico. */
    void listarHistoriasPlano();
    /** @brief Exibe na tela todas as tarefas sob responsabilidade de um usuário. */
    void listarHistoriasPessoa();
    /** @brief Fluxo de UI para realizar a transição de uma história do Backlog para uma Sprint. */
    void moverHistoriaParaSprint();
    /** @brief Fluxo de UI para avançar ou retroceder o status de uma tarefa no Kanban (A FAZER, FAZENDO, FEITO). */
    void alterarEstadoHistoria();

public:
    /**
     * @brief Inicia o ciclo de vida da aplicação.
     * * Único método público da classe, acionado pela função main() para realizar o
     * bootstrap (inicialização) do sistema e carregar a primeira tela de interação.
     */
    void executar();
};

#endif // CONTROLADORASISTEMA_H_INCLUDED
