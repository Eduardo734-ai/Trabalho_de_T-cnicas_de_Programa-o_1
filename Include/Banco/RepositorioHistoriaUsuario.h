#ifndef REPOSITORIOHISTORIAUSUARIO_H_INCLUDED
#define REPOSITORIOHISTORIAUSUARIO_H_INCLUDED

#include "../entidade/HistoriaUsuario.h"
#include "../dominio/Codigo.h"
#include "BancoDados.h"

/**
 * @brief Classe responsável pela persistência das Histórias de Usuário no banco de dados.
 * * Atua como a camada de acesso a dados (Data Access Object - DAO) para a entidade
 * HistoriaUsuario. Isola os comandos SQL e a comunicação direta com o SQLite do resto
 * do sistema, permitindo que a camada de Serviço apenas chame métodos de alto nível
 * para operações de CRUD (Criar, Ler, Atualizar, Deletar) sem conhecer a tecnologia
 * de persistência subjacente.
 */
class RepositorioHistoriaUsuario {
private:
    BancoDados banco;

public:
    /**
     * @brief Inicializa o repositório instanciando a conexão base com o banco de dados.
     */
    RepositorioHistoriaUsuario();

    /**
     * @brief Insere um novo registro de História de Usuário na tabela correspondente do banco.
     * * @param historia Objeto contendo os dados validados a serem persistidos fisicamente.
     */
    void inserir(const HistoriaUsuario &historia);

    /**
     * @brief Consulta o banco de dados para recuperar uma História de Usuário pela sua chave primária.
     * * @param codigo Objeto de domínio representando o identificador único procurado.
     * * @return HistoriaUsuario Entidade populada com os dados retornados pela query SQL.
     */
    HistoriaUsuario buscar(const Codigo &codigo);

    /**
     * @brief Atualiza os atributos de um registro de História de Usuário pré-existente no banco.
     * * @param historia Entidade contendo o identificador inalterado e os novos valores a serem gravados.
     */
    void atualizar(const HistoriaUsuario &historia);

    /**
     * @brief Exclui fisicamente um registro de História de Usuário do banco de dados.
     * * @param codigo Objeto de domínio representando a chave primária da linha a ser deletada.
     */
    void remover(const Codigo &codigo);
};

#endif // REPOSITORIOHISTORIAUSUARIO_H_INCLUDED
