#ifndef ISERVICOPESSOA_H_INCLUDED
#define ISERVICOPESSOA_H_INCLUDED

#include"entidade/Pessoa.h"
#include"dominio/Email.h"

/**
 * @brief Contrato de delegação de lógica de negócio para a gestão de usuários (Pessoas).
 * * Declara a interface abstrata responsável por definir as operações de ciclo de vida
 * (criação, leitura, atualização e exclusão) das identidades do sistema. Esta interface
 * garante que a camada de Apresentação possa gerenciar os usuários, suas credenciais de
 * acesso e seus papéis (níveis de permissão) sem conhecer os detalhes da implementação do banco de dados.
 */
class IServicoPessoa{
    public:
        /**
         * @brief Registra um novo usuário no sistema.
         * * @param pessoa Objeto da entidade Pessoa preenchido com dados validados (email, nome, senha e papel).
         * @throw std::runtime_error Lança exceção caso já exista um usuário cadastrado com o mesmo email ou ocorra erro de persistência.
         */
        virtual void criar(const Pessoa &pessoa) = 0;

        /**
         * @brief Recupera os dados completos de um usuário cadastrado.
         * * @param email Objeto da classe Email atuando como identificador único (chave primária) do usuário a ser buscado.
         * @return Pessoa Retorna a entidade populada com os dados recuperados do sistema.
         * @throw std::invalid_argument Lança exceção caso o email fornecido não seja encontrado nos registros.
         */
        virtual Pessoa ler(const Email &email) = 0;

        /**
         * @brief Sobrescreve as informações de um usuário já existente.
         * * @param pessoa Objeto contendo o email do usuário original (imutável para a busca) e os novos dados a serem atualizados (como alteração de senha ou papel).
         * @throw std::invalid_argument Lança exceção caso o usuário não exista no sistema.
         */
        virtual void atualizar(const Pessoa &pessoa) = 0;

        /**
         * @brief Remove definitivamente um usuário do sistema e revoga o seu acesso.
         * * @param email Objeto da classe Email atuando como identificador único do usuário a ser deletado.
         * @throw std::invalid_argument Lança exceção caso o email não seja localizado para exclusão.
         */
        virtual void excluir(const Email &email) = 0;

        /**
         * @brief Destrutor virtual padrão.
         * * Garante a destruição correta de objetos derivados através do ponteiro da classe base,
         * prevenindo vazamentos de memória na arquitetura.
         */
        virtual ~IServicoPessoa(){}
};

#endif // ISERVICOPESSOA_H_INCLUDED
