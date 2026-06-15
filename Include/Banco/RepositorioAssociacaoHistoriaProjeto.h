#ifndef REPOSITORIOASSOCIACAOHISTORIAPROJETO_H_INCLUDED
#define REPOSITORIOASSOCIACAOHISTORIAPROJETO_H_INCLUDED

#include <vector>
#include "../associacao/AssociacaoHistoriaProjeto.h"
#include "BancoDados.h"

/**
 * @brief Classe responsável pela persistência do vínculo entre História de Usuário e Projeto no banco de dados.
 * * Atua como a camada de acesso a dados (DAO) para a entidade associativa estrutural.
 * Na modelagem relacional (SQLite), gerencia a tabela de junção que define o Product Backlog,
 * ou seja, mapeia o pertencimento de um requisito funcional ao escopo global de um projeto.
 * Isola os comandos SQL de inserção, deleção e busca dessa relação.
 */
class RepositorioAssociacaoHistoriaProjeto {
private:
    BancoDados banco;

public:
    /**
     * @brief Inicializa o repositório instanciando a conexão base com o banco de dados.
     */
    RepositorioAssociacaoHistoriaProjeto();

    /**
     * @brief Grava o vínculo de uma tarefa ao escopo global de um projeto no banco de dados.
     * * Efetua um comando INSERT na tabela associativa, adicionando a história ao Product Backlog.
     * * @param associacao Objeto da classe de associação contendo os identificadores da história e do projeto pai.
     */
    void inserir(const AssociacaoHistoriaProjeto &associacao);

    /**
     * @brief Exclui fisicamente o vínculo entre uma tarefa e um macroescopo do banco de dados.
     * * Efetua um comando DELETE na tabela associativa, desvinculando a história do projeto.
     * * @param codigoHistoria Objeto de domínio representando a chave da tarefa.
     * * @param codigoProjeto Objeto de domínio representando a chave do projeto.
     */
    void remover(const Codigo &codigoHistoria, const Codigo &codigoProjeto);

    /**
     * @brief Recupera todos os vínculos de Product Backlog registrados no banco de dados.
     * * Efetua um comando SELECT buscando todas as associações ativas entre histórias e projetos.
     * * @return std::vector<AssociacaoHistoriaProjeto> Lista contendo todos os objetos de associação encontrados.
     */
    std::vector<AssociacaoHistoriaProjeto> listar();

    /**
     * @brief Verifica no banco de dados se uma tarefa já está vinculada a um projeto específico.
     * * Utilizado para manter a integridade referencial e evitar a inserção duplicada
     * da mesma história no mesmo projeto.
     * * @param codigoHistoria Objeto de domínio representando a chave da tarefa.
     * * @param codigoProjeto Objeto de domínio representando a chave do projeto.
     * * @return bool Retorna true se o vínculo existir no banco, ou false caso contrário.
     */
    bool existe(const Codigo &codigoHistoria, const Codigo &codigoProjeto);
};

#endif // REPOSITORIOASSOCIACAOHISTORIAPROJETO_H_INCLUDED
