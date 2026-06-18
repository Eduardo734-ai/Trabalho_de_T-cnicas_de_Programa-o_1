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

    ControladoraPessoa* controladoraPessoa;
    ControladoraProjeto* controladoraProjeto;
    ControladoraPlanoDeSprint* controladoraPlano;
    ControladoraHistoria* controladoraHistoria;
    ControladoraAssociacoes* controladoraAssociacoes;

    /** @brief Renderiza o menu de boas-vindas (Login/Cadastro/Sair). */
    void menuInicial();
    /** @brief Renderiza o painel central de navegação pós-autenticação. */
    void menuPrincipal();
    /** @brief Renderiza as opções de gestão de usuários (Pessoas). */

    /** @brief Coleta dados de entrada e aciona o serviço de cadastro de novo usuário. */
    void executarCadastro();
    /** @brief Coleta credenciais e aciona a validação de sessão no serviço de autenticação. */
    void executarLogin();
    /** @brief Encerra a sessão ativa do usuário e retorna ao menu inicial. */
    void executarLogout();

public:
    /**
     * @brief Inicia o ciclo de vida da aplicação.
     * * Único método público da classe, acionado pela função main() para realizar o
     * bootstrap (inicialização) do sistema e carregar a primeira tela de interação.
     */
    void executar();

    ControladoraSistema();
    ~ControladoraSistema();
};

#endif // CONTROLADORASISTEMA_H_INCLUDED
