#ifndef SERVICOPESSOA_H_INCLUDED
#define SERVICOPESSOA_H_INCLUDED

#include "../interface/IServicoPessoa.h"
#include "../banco/RepositorioPessoa.h"

/**
 * @brief Implementação concreta do serviço de gestão de identidades (Pessoas).
 * * Esta classe materializa o contrato definido em IServicoPessoa.
 * É responsável por orquestrar as operações de ciclo de vida dos usuários,
 * conectando as regras de negócio à camada de persistência definitiva (banco de dados SQLite)
 * por meio da instância de RepositorioPessoa.
 */
class ServicoPessoa : public IServicoPessoa {
private:
    RepositorioPessoa repositorioPessoa;

public:
    /**
     * @brief Inicializa o serviço instanciando a conexão com o repositório de banco de dados de pessoas.
     */
    ServicoPessoa();

    /**
     * @brief Executa a persistência de um novo usuário no banco de dados.
     * * @param pessoa Objeto contendo os dados validados de identidade e credenciais a serem gravados no SQLite.
     * @throw std::runtime_error Lança exceção em caso de falha na transação do banco ou se o e-mail já existir.
     */
    void criar(const Pessoa &pessoa) override;

    /**
     * @brief Consulta o repositório físico para recuperar os dados completos de um usuário.
     * * @param email Identificador único (chave primária) do usuário a ser lido.
     * @return Pessoa Entidade preenchida com os dados resgatados do banco de dados.
     * @throw std::invalid_argument Lança exceção caso o e-mail não seja localizado no repositório.
     */
    Pessoa ler(const Email &email) override;

    /**
     * @brief Consolida a atualização dos dados de um usuário existente no banco de dados.
     * * @param pessoa Entidade contendo o e-mail imutável e os novos dados a serem sobrescritos (ex: nova senha ou papel).
     * @throw std::invalid_argument Lança exceção caso o registro do usuário não seja encontrado para atualização.
     */
    void atualizar(const Pessoa &pessoa) override;

    /**
     * @brief Executa a deleção definitiva de um usuário no banco de dados.
     * * @param email Identificador único (e-mail) do usuário a ser removido fisicamente do sistema.
     * @throw std::invalid_argument Lança exceção caso o e-mail não seja localizado para a exclusão.
     */
    void excluir(const Email &email) override;
};

#endif // SERVICOPESSOA_H_INCLUDED
