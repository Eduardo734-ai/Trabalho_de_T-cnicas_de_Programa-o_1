#ifndef CONTROLADORAPROJETO_H_INCLUDED
#define CONTROLADORAPROJETO_H_INCLUDED

#include "../Servico/ServicoProjeto.h"
#include "../Servico/ServicoPessoa.h"

/**
 * @brief Classe controladora responsável pela interface de usuário para operações de Projeto.
 *
 * Esta classe pertence à camada de Apresentação e atua como intermediária entre as interações no terminal e
 * as lógicas de negócio dos macroescopos do sistema. Ela gerencia o menu específico para a entidade
 * Projeto, captura as entradas de dados, realiza validações iniciais de formato e repassa os comandos
 * de CRUD (Criar, Ler, Atualizar, Excluir) para a camada de Serviço responsável.
 */
class ControladoraProjeto {
private:
    ServicoProjeto* servicoProjeto; ///< Ponteiro para a interface de serviço que gerencia as regras de negócio dos projetos.
    ServicoPessoa* servicoPessoa;   ///< Ponteiro para a interface de serviço de usuários, utilizado para validar vínculos de papéis (ex: Mestre Scrum).

    /**
     * @brief Renderiza no terminal o menu de opções disponíveis para o gerenciamento de Projetos.
     */
    void menuProjeto();

    /**
     * @brief Interface visual que coleta os dados preenchidos pelo usuário para o cadastro de um novo Projeto.
     */
    void criarProjeto();

    /**
     * @brief Solicita o identificador único (Código) e exibe em tela todos os atributos do Projeto correspondente.
     */
    void lerProjeto();

    /**
     * @brief Coleta as novas informações fornecidas pelo usuário para atualizar os dados de um Projeto pré-existente.
     */
    void atualizarProjeto();

    /**
     * @brief Solicita o identificador único (Código) e coordena a exclusão de um Projeto do sistema.
     */
    void excluirProjeto();

public:
    /**
     * @brief Construtor da classe que estabelece a injeção de dependência dos componentes da camada de Serviço.
     * @param servicoProjeto Ponteiro para o módulo responsável pela persistência e regras dos projetos.
     * @param servicoPessoa Ponteiro para o módulo de pessoas, necessário para associar responsabilidades no ato da criação.
     */
    ControladoraProjeto(ServicoProjeto* servicoProjeto, ServicoPessoa* servicoPessoa);

    /**
     * @brief Dispara o fluxo principal de execução do controlador, mantendo o usuário no loop do menu interativo.
     */
    void executar();
};

#endif // CONTROLADORAPROJETO_H_INCLUDED
