#ifndef SERVICOAUTENTICACAO_H_INCLUDED
#define SERVICOAUTENTICACAO_H_INCLUDED

#include "../entidade/Pessoa.h"
#include "../dominio/Email.h"
#include "../dominio/Senha.h"
#include "../banco/RepositorioPessoa.h"

#include "ContainerPessoas.h"

/**
 * @brief Serviço de gestão de identidade, sessão e controle de acesso.
 * * Implementa a lógica de negócio concreta para a autenticação de usuários e a
 * verificação de permissões baseada nos papéis do framework Scrum (Mestre Scrum,
 * Product Owner e Desenvolvedor). Esta classe atua como um guardião central do sistema,
 * mantendo o estado do usuário ativo em memória e garantindo que operações restritas
 * só sejam executadas pelas credenciais adequadas.
 */
class ServicoAutenticacao {
private:
    RepositorioPessoa repositorio;
    Pessoa usuarioLogado;
    bool autenticado;

public:
    /**
     * @brief Inicializa o serviço de autenticação com a sessão inativa (deslogado).
     */
    ServicoAutenticacao();

    /**
     * @brief Registra as credenciais de um novo usuário no sistema.
     * * @param pessoa Objeto da entidade Pessoa contendo os dados de identidade a serem persistidos.
     * @throw std::runtime_error Lança exceção caso o e-mail já esteja cadastrado no repositório.
     */
    void cadastrar(const Pessoa &pessoa);

    /**
     * @brief Valida as credenciais de acesso e inicia uma nova sessão de usuário.
     * * Compara os dados fornecidos com os registros de persistência. Se validados,
     * atualiza o estado interno da classe para manter o contexto do usuário logado.
     * * @param email Identificador único do usuário.
     * @param senha Credencial de segurança associada ao e-mail.
     * @return true Caso as credenciais sejam válidas e a sessão seja iniciada com sucesso.
     * @return false Caso as credenciais sejam inválidas ou não encontradas.
     */
    bool login(const Email &email, const Senha &senha);

    /**
     * @brief Encerra a sessão ativa, limpando o contexto do usuário logado da memória.
     */
    void logout();

    /**
     * @brief Verifica o estado atual da sessão no sistema.
     * * @return true Caso exista um usuário com login ativo no momento.
     * @return false Caso o sistema esteja aguardando autenticação.
     */
    bool estaAutenticado() const;

    /**
     * @brief Recupera a entidade representativa do usuário que detém a sessão atual.
     * * @return Pessoa Objeto contendo os dados completos do usuário logado.
     * @throw std::logic_error Lança exceção caso o método seja chamado sem um usuário autenticado.
     */
    Pessoa getUsuarioLogado() const;

    /**
     * @brief Verifica se o usuário ativo possui a permissão de "Mestre Scrum".
     * * @return true Caso o papel do usuário corresponda à permissão verificada.
     */
    bool isMestreScrum() const;

    /**
     * @brief Verifica se o usuário ativo possui a permissão de "Product Owner".
     * * @return true Caso o papel do usuário corresponda à permissão verificada.
     */
    bool isProductOwner() const;

    /**
     * @brief Verifica se o usuário ativo possui a permissão de "Desenvolvedor".
     * * @return true Caso o papel do usuário corresponda à permissão verificada.
     */
    bool isDesenvolvedor() const;

    /**
     * @brief Cláusula de guarda que impõe a permissão de "Mestre Scrum" para o fluxo atual.
     * * Utilizada antes de executar operações críticas exclusivas deste papel.
     * * @throw std::runtime_error Lança exceção bloqueando a operação caso o usuário não tenha a permissão exigida.
     */
    void exigirMestreScrum() const;

    /**
     * @brief Cláusula de guarda que impõe a permissão de "Product Owner" para o fluxo atual.
     * * Utilizada antes de executar operações críticas exclusivas deste papel.
     * * @throw std::runtime_error Lança exceção bloqueando a operação caso o usuário não tenha a permissão exigida.
     */
    void exigirProductOwner() const;

    /**
     * @brief Cláusula de guarda que impõe a permissão de "Desenvolvedor" para o fluxo atual.
     * * Utilizada antes de executar operações críticas exclusivas deste papel.
     * * @throw std::runtime_error Lança exceção bloqueando a operação caso o usuário não tenha a permissão exigida.
     */
    void exigirDesenvolvedor() const;
};

#endif // SERVICOAUTENTICACAO_H_INCLUDED
