#ifndef REPOSITORIOPROJETO_H_INCLUDED
#define REPOSITORIOPROJETO_H_INCLUDED

#include "../entidade/Projeto.h"
#include "../dominio/Codigo.h"
#include "BancoDados.h"

/**
 * @brief Classe responsável pela persistência dos Projetos no banco de dados.
 * * Atua como a camada de acesso a dados (Data Access Object - DAO) para a entidade
 * Projeto. Isola os comandos SQL e a comunicação direta com o SQLite do resto
 * do sistema, encapsulando as operações de CRUD (Criar, Ler, Atualizar, Deletar)
 * referentes aos macroescopos (projetos) do sistema.
 */
class RepositorioProjeto {
private:
    BancoDados banco;

public:
    /**
     * @brief Inicializa o repositório instanciando a conexão base com o banco de dados.
     */
    RepositorioProjeto();

    /**
     * @brief Insere um novo registro de Projeto na tabela correspondente do banco.
     * * @param projeto Objeto contendo os dados validados a serem persistidos fisicamente.
     */
    void inserir(const Projeto &projeto);

    /**
     * @brief Consulta o banco de dados para recuperar um Projeto pela sua chave primária.
     * * @param codigo Objeto de domínio representando o identificador único procurado.
     * * @return Projeto Entidade populada com os dados retornados pela query SQL.
     */
    Projeto buscar(const Codigo &codigo);

    /**
     * @brief Exclui fisicamente um registro de Projeto do banco de dados.
     * * @param codigo Objeto de domínio representando a chave primária do macroescopo a ser deletado.
     */
    void remover(const Codigo &codigo);

    /**
     * @brief Atualiza os atributos de um registro de Projeto pré-existente no banco.
     * * @param projeto Entidade contendo o identificador inalterado e os novos valores a serem gravados.
     */
    void atualizar(const Projeto &projeto);
};

#endif // REPOSITORIOPROJETO_H_INCLUDED
