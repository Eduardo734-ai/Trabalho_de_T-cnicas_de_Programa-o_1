#ifndef CONTROLADORASISTEMA_H_INCLUDED
#define CONTROLADORASISTEMA_H_INCLUDED

#include "../servico/ServicoAutenticacao.h"
#include "../servico/ServicoPessoa.h"
#include "../servico/ServicoProjeto.h"
#include "../servico/ServicoPlanoDeSprint.h"
#include "../servico/ServicoHistoriaUsuario.h"

#include "Apresentacao/ControladoraPessoa.h"
#include "Apresentacao/ControladoraProjeto.h"
#include "Apresentacao/ControladoraPlanoDeSprint.h"
#include "Apresentacao/ControladoraHistoria.h"
#include "Apresentacao/ControladoraAssociacoes.h"

/**
 * @brief Orquestradora principal da camada de Apresentação (Interface de Usuário).
 * * Atua como o ponto central de interação do sistema. É responsável por instanciar os serviços,
 * renderizar os menus principais no terminal, capturar as entradas do usuário, gerenciar o
 * estado da sessão (login/logout) e delegar a navegação para as sub-controladoras específicas
 * (Pessoa, Projeto, Plano de Sprint, História e Associações). Mantém o ciclo de vida da
 * aplicação ativo através de loops de execução.
 */
class ControladoraSistema {
private:
    // Instâncias concretas da camada de Serviço
    ServicoAutenticacao servicoAutenticacao; ///< Instância do serviço gerenciador de sessões e acessos.
    ServicoPessoa servicoPessoa;             ///< Instância do serviço de regras de negócio para Pessoas.
    ServicoProjeto servicoProjeto;           ///< Instância do serviço de regras de negócio para Projetos.
    ServicoPlanoDeSprint servicoPlano;       ///< Instância do serviço de regras de negócio para Sprints.
    ServicoHistoriaUsuario servicoHistoria;  ///< Instância do serviço de regras de negócio para Histórias.

    // Ponteiros para as sub-controladoras da camada de Apresentação
    ControladoraPessoa* controladoraPessoa;           ///< Delegada para fluxos de interface envolvendo usuários.
    ControladoraProjeto* controladoraProjeto;         ///< Delegada para fluxos de interface envolvendo macroescopos.
    ControladoraPlanoDeSprint* controladoraPlano;     ///< Delegada para fluxos de interface envolvendo ciclos de execução.
    ControladoraHistoria* controladoraHistoria;       ///< Delegada para fluxos de interface envolvendo requisitos.
    ControladoraAssociacoes* controladoraAssociacoes; ///< Delegada para fluxos de vinculação entre as entidades.

    /** * @brief Renderiza o menu de boas-vindas do sistema com as opções de Login, Cadastro ou Sair.
     */
    void menuInicial();

    /** * @brief Renderiza o painel central de navegação pós-autenticação, liberando acesso aos CRUDs baseados no papel do usuário.
     */
    void menuPrincipal();

    /** * @brief Coleta dados de entrada iniciais e aciona o serviço de cadastro para registrar um novo usuário no banco de dados.
     */
    void executarCadastro();

    /** * @brief Coleta credenciais (e-mail e senha) e aciona a validação de sessão no serviço de autenticação.
     */
    void executarLogin();

    /** * @brief Encerra a sessão ativa do usuário atual e o redireciona de volta ao menu inicial.
     */
    void executarLogout();

public:
    /**
     * @brief Construtor padrão da Controladora do Sistema.
     * * Responsável por alocar dinamicamente na memória as sub-controladoras e injetar
     * as dependências dos serviços necessários em cada uma delas.
     */
    ControladoraSistema();

    /**
     * @brief Destrutor da Controladora do Sistema.
     * * Garante a liberação adequada da memória de todos os ponteiros das sub-controladoras
     * instanciadas durante o ciclo de vida da classe.
     */
    ~ControladoraSistema();

    /**
     * @brief Inicia o ciclo de vida da aplicação.
     * * Único método público operacional da classe, acionado diretamente pela função main()
     * para realizar o bootstrap (inicialização) do sistema e prender o usuário no loop de interação.
     */
    void executar();
};

#endif // CONTROLADORASISTEMA_H_INCLUDED
