#ifndef CONTROLADORAHISTORIA_H_INCLUDED
#define CONTROLADORAHISTORIA_H_INCLUDED

#include "../Servico/ServicoHistoriaUsuario.h"
#include "../Servico/ServicoProjeto.h"
#include "../Servico/ServicoAutenticacao.h"

/**
 * @brief Classe controladora responsável pela interface de usuário para operações de História de Usuário.
 *
 * Esta classe pertence à camada de Apresentação e atua como intermediária entre as entradas do terminal e
 * as lógicas de negócio. Ela gerencia o menu específico para o escopo de requisitos funcionais (Histórias
 * de Usuário), captura as entradas de dados, realiza validações iniciais de formato e aciona os métodos
 * adequados (Criar, Ler, Atualizar, Excluir) na camada de Serviço.
 */
class ControladoraHistoria {
private:
    ServicoHistoriaUsuario* servicoHistoria;   ///< Ponteiro para a interface de serviço que gerencia as regras de negócio das histórias.
    ServicoProjeto* servicoProjeto;            ///< Ponteiro para a interface de serviço de projetos, utilizado para verificação de vínculos.
    ServicoAutenticacao* servicoAutenticacao;  ///< Ponteiro para a interface de autenticação, controlando o nível de acesso do usuário atual.

    /**
     * @brief Renderiza no terminal o menu de opções disponíveis para o gerenciamento de Histórias de Usuário.
     */
    void menuHistoria();

    /**
     * @brief Interface visual que coleta os dados preenchidos pelo usuário para o cadastro de uma nova História de Usuário.
     */
    void criarHistoria();

    /**
     * @brief Solicita o identificador único (Código) e exibe em tela todos os atributos da História de Usuário correspondente.
     */
    void lerHistoria();

    /**
     * @brief Coleta as novas informações fornecidas pelo usuário para atualizar os dados de uma História de Usuário pré-existente.
     */
    void atualizarHistoria();

    /**
     * @brief Solicita o identificador único (Código) e coordena a exclusão de uma História de Usuário do sistema.
     */
    void excluirHistoria();

public:
    /**
     * @brief Construtor da classe que estabelece a injeção de dependência dos componentes da camada de Serviço.
     * * @param servicoHistoria Ponteiro para o módulo responsável pela persistência e regras das histórias.
     * @param servicoProjeto Ponteiro para o módulo responsável pela gestão dos macroescopos (projetos).
     * @param servicoAutenticacao Ponteiro para o módulo que gerencia o login e os papéis dos usuários.
     */
    ControladoraHistoria(
        ServicoHistoriaUsuario* servicoHistoria,
        ServicoProjeto* servicoProjeto,
        ServicoAutenticacao* servicoAutenticacao
    );

    /**
     * @brief Dispara o fluxo principal de execução do controlador, mantendo o usuário no loop do menu até que ele decida voltar.
     */
    void executar();
};

#endif // CONTROLADORAHISTORIA_H_INCLUDED
