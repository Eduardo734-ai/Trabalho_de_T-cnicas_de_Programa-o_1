#ifndef CONTAINERPESSOAS_H_INCLUDED
#define CONTAINERPESSOAS_H_INCLUDED

#include<vector>
#include"entidade/Pessoa.h"
#include"dominio/Email.h"

/**
 * @brief Estrutura de armazenamento em memória para as identidades do sistema (Pessoas).
 * * Implementa um contêiner responsável por gerenciar a persistência temporária dos
 * usuários cadastrados na camada de Serviço. Funciona como um repositório local que
 * facilita operações rápidas de validação de credenciais, checagem de duplicidade de
 * e-mails e controle de acesso antes de executar operações no banco de dados definitivo.
 */
class ContainerPessoas{
    private:
        std::vector<Pessoa> pessoas;

    public:
        /**
         * @brief Inicializa o repositório de usuários em estado vazio.
         */
        ContainerPessoas();

        /**
         * @brief Registra um novo usuário no armazenamento em memória.
         * * @param pessoa Objeto da entidade Pessoa preenchido com dados de identidade e credenciais válidos.
         */
        void inserir(const Pessoa &pessoa);

        /**
         * @brief Recupera os dados completos de um usuário específico armazenado no contêiner.
         * * @param email Identificador único (chave) do usuário a ser localizado.
         * @return Pessoa Retorna a entidade populada com as informações recuperadas da memória.
         * @throw std::invalid_argument Lança exceção caso o e-mail fornecido não corresponda a nenhum usuário no contêiner.
         */
        Pessoa buscar(const Email &email) const;

        /**
         * @brief Remove permanentemente um usuário do repositório em memória, revogando seu acesso.
         * * @param email Identificador único do usuário a ser excluído do cache.
         */
        void remover(const Email &email);

        /**
         * @brief Recupera a totalidade das identidades ativas registradas no contêiner.
         * * @return std::vector<Pessoa> Estrutura vetorial contendo todos os usuários atualmente armazenados na memória.
         */
        std::vector<Pessoa> listar() const;
};

#endif // CONTAINERPESSOAS_H_INCLUDED
