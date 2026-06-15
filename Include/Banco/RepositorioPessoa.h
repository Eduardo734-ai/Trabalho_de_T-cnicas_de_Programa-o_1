#ifndef REPOSITORIOPESSOA_H_INCLUDED
#define REPOSITORIOPESSOA_H_INCLUDED

#include "../entidade/Pessoa.h"
#include "../dominio/Email.h"
#include "BancoDados.h"

/**
 * @brief Classe responsável pela persistência das instâncias de Pessoa no banco de dados.
 * * Atua como a camada de acesso a dados (Data Access Object - DAO) para a entidade
 * Pessoa. Encapsula os comandos SQL necessários para realizar as operações de
 * CRUD (Criar, Ler, Atualizar, Deletar) dos usuários do sistema no SQLite,
 * isolando a lógica de banco de dados da camada de Serviço.
 */
class RepositorioPessoa {
private:
    BancoDados banco;

public:
    /**
     * @brief Inicializa o repositório instanciando a conexão base com o banco de dados.
     */
    RepositorioPessoa();

    /**
     * @brief Insere um novo registro de Pessoa na tabela correspondente do banco.
     * * @param pessoa Objeto contendo os dados validados (nome, email, senha, papel) a serem persistidos fisicamente.
     */
    void inserir(const Pessoa &pessoa);

    /**
     * @brief Consulta o banco de dados para recuperar uma Pessoa pela sua chave primária.
     * * @param email Objeto de domínio representando o identificador único (e-mail) procurado.
     * * @return Pessoa Entidade populada com os dados retornados pela query SQL.
     */
    Pessoa buscar(const Email &email);

    /**
     * @brief Atualiza os atributos de um registro de Pessoa pré-existente no banco.
     * * @param pessoa Entidade contendo a chave primária inalterada e os novos valores a serem gravados.
     */
    void atualizar(const Pessoa &pessoa);

    /**
     * @brief Exclui fisicamente um registro de Pessoa do banco de dados.
     * * @param email Objeto de domínio representando a chave primária do usuário a ser deletado.
     */
    void remover(const Email &email);
};

#endif // REPOSITORIOPESSOA_H_INCLUDED
