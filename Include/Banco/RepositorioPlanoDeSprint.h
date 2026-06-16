#ifndef REPOSITORIOPLANODESPRINT_H_INCLUDED
#define REPOSITORIOPLANODESPRINT_H_INCLUDED

#include "../entidade/PlanoDeSprint.h"
#include "../dominio/Codigo.h"
#include "BancoDados.h"

/**
 * @brief Classe responsável pela persistência dos Planos de Sprint no banco de dados.
 * * Atua como a camada de acesso a dados (Data Access Object - DAO) para a entidade
 * PlanoDeSprint. Isola os comandos SQL e a comunicação direta com o SQLite do resto
 * do sistema, encapsulando as operações de CRUD (Criar, Ler, Atualizar, Deletar)
 * referentes aos ciclos de execução (sprints) do projeto.
 */
class RepositorioPlanoDeSprint {
private:
    BancoDados banco;

public:
    /**
     * @brief Inicializa o repositório instanciando a conexão base com o banco de dados.
     */
    RepositorioPlanoDeSprint();

    /**
     * @brief Insere um novo registro de Plano de Sprint na tabela correspondente do banco.
     * * @param plano Objeto contendo os dados validados a serem persistidos fisicamente.
     */
    void inserir(const PlanoDeSprint &plano);

    /**
     * @brief Consulta o banco de dados para recuperar um Plano de Sprint pela sua chave primária.
     * * @param codigo Objeto de domínio representando o identificador único procurado.
     * * @return PlanoDeSprint Entidade populada com os dados retornados pela query SQL.
     */
    PlanoDeSprint buscar(const Codigo &codigo);

    /**
     * @brief Atualiza os atributos de um registro de Plano de Sprint pré-existente no banco.
     * * @param plano Entidade contendo o identificador inalterado e os novos valores a serem gravados.
     */
    void atualizar(const PlanoDeSprint &plano);

    /**
     * @brief Exclui fisicamente um registro de Plano de Sprint do banco de dados.
     * * @param codigo Objeto de domínio representando a chave primária do ciclo a ser deletado.
     */
    void remover(const Codigo &codigo);
};

#endif // REPOSITORIOPLANODESPRINT_H_INCLUDED
