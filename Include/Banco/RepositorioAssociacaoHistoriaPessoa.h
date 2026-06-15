#ifndef REPOSITORIOASSOCIACAOHISTORIAPESSOA_H_INCLUDED
#define REPOSITORIOASSOCIACAOHISTORIAPESSOA_H_INCLUDED

#include <vector>
#include "../associacao/AssociacaoHistoriaPessoa.h"
#include "BancoDados.h"

/**
 * @brief Classe responsável pela persistência do vínculo entre História de Usuário e Pessoa no banco de dados.
 * * Atua como a camada de acesso a dados (DAO) para a entidade associativa.
 * Na estrutura do banco relacional (SQLite), gerencia a tabela de junção que mapeia
 * qual colaborador (Pessoa) é responsável por desenvolver qual requisito (História).
 * Isola os comandos SQL de inserção, deleção e busca dessa relação.
 */
class RepositorioAssociacaoHistoriaPessoa {
private:
    BancoDados banco;

public:
    /**
     * @brief Inicializa o repositório instanciando a conexão base com o banco de dados.
     */
    RepositorioAssociacaoHistoriaPessoa();

    /**
     * @brief Grava um novo vínculo de responsabilidade no banco de dados.
     * * Efetua um comando INSERT na tabela associativa.
     * * @param associacao Objeto da classe de associação contendo os identificadores da história e do responsável.
     */
    void inserir(const AssociacaoHistoriaPessoa &associacao);

    /**
     * @brief Exclui fisicamente o vínculo entre uma tarefa e um colaborador do banco de dados.
     * * Efetua um comando DELETE na tabela associativa, desvinculando o usuário da tarefa.
     * * @param codigoHistoria Objeto de domínio representando a chave da tarefa.
     * * @param emailPessoa Objeto de domínio representando a chave do colaborador.
     */
    void remover(const Codigo &codigoHistoria, const Email &emailPessoa);

    /**
     * @brief Recupera todos os vínculos registrados no banco de dados.
     * * Efetua um comando SELECT buscando todas as atribuições ativas no sistema.
     * * @return std::vector<AssociacaoHistoriaPessoa> Lista contendo todos os objetos de associação encontrados.
     */
    std::vector<AssociacaoHistoriaPessoa> listar();

    /**
     * @brief Verifica no banco de dados se um vínculo específico já está cadastrado.
     * * Utilizado para evitar duplicação de atribuições (evitar que a mesma pessoa
     * seja alocada duas vezes para a mesma história).
     * * @param codigoHistoria Objeto de domínio representando a chave da tarefa.
     * * @param emailPessoa Objeto de domínio representando a chave do colaborador.
     * * @return bool Retorna true se o vínculo existir no banco, ou false caso contrário.
     */
    bool existe(const Codigo &codigoHistoria, const Email &emailPessoa);
};

#endif // REPOSITORIOASSOCIACAOHISTORIAPESSOA_H_INCLUDED
