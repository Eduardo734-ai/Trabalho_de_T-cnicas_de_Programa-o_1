#ifndef CONTROLADORAPESSOA_H_INCLUDED
#define CONTROLADORAPESSOA_H_INCLUDED

#include "../Servico/ServicoPessoa.h"

/**
 * @brief Classe controladora responsável pela interface de usuário para operações de Pessoa.
 *
 * Esta classe pertence à camada de Apresentação e atua como intermediária entre as entradas do terminal e
 * as lógicas de negócio relacionadas aos usuários do sistema. Ela gerencia o menu específico para a entidade
 * Pessoa, captura as entradas de dados, realiza validações iniciais de formato e aciona os métodos
 * correspondentes (Criar, Ler, Atualizar, Excluir) na camada de Serviço.
 */
class ControladoraPessoa {
private:
    ServicoPessoa* servicoPessoa; ///< Ponteiro para a interface de serviço que gerencia as regras de negócio de usuários.

    /**
     * @brief Renderiza no terminal o menu de opções disponíveis para o gerenciamento de Pessoas.
     */
    void menuPessoa();

    /**
     * @brief Interface visual que coleta os dados preenchidos pelo usuário para o cadastro de uma nova Pessoa.
     */
    void criarPessoa();

    /**
     * @brief Solicita o identificador único (e-mail) e exibe em tela todos os atributos da Pessoa correspondente.
     */
    void lerPessoa();

    /**
     * @brief Coleta as novas informações fornecidas pelo usuário para atualizar os dados de uma Pessoa pré-existente.
     */
    void atualizarPessoa();

    /**
     * @brief Solicita o identificador único (e-mail) e coordena a exclusão de uma Pessoa do sistema.
     */
    void excluirPessoa();

public:
    /**
     * @brief Construtor da classe que estabelece a injeção de dependência da camada de Serviço.
     * * @param servicoPessoa Ponteiro para o módulo responsável pela persistência e regras de negócio das pessoas.
     */
    ControladoraPessoa(ServicoPessoa* servicoPessoa);

    /**
     * @brief Dispara o fluxo principal de execução do controlador, mantendo o usuário no loop do menu interativo.
     */
    void executar();
};

#endif // CONTROLADORAPESSOA_H_INCLUDED
