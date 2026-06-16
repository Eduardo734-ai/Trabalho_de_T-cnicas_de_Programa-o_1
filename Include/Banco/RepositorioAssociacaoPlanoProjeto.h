#ifndef REPOSITORIOASSOCIACAOPLANOPROJETO_H_INCLUDED
#define REPOSITORIOASSOCIACAOPLANOPROJETO_H_INCLUDED

#include <vector>
#include "../associacao/AssociacaoPlanoProjeto.h"
#include "BancoDados.h"

/**
 * @brief Classe responsável pela persistência do vínculo entre Plano de Sprint e Projeto no banco de dados.
 * * Atua como a camada de acesso a dados (DAO) para a entidade associativa hierárquica.
 * Na estrutura do banco relacional (SQLite), gerencia a tabela de junção que garante
 * que múltiplos ciclos de execução (Sprints) pertençam a um macroescopo (Projeto).
 * Isola os comandos SQL de inserção, deleção e busca dessa relação.
 */
class RepositorioAssociacaoPlanoProjeto {
private:
    BancoDados banco;

public:
    /**
     * @brief Inicializa o repositório instanciando a conexão base com o banco de dados.
     */
    RepositorioAssociacaoPlanoProjeto();

    /**
     * @brief Grava o vínculo hierárquico de um sprint a um projeto no banco de dados.
     * * Efetua um comando INSERT na tabela associativa, registrando a qual projeto o plano pertence.
     * * @param associacao Objeto da classe de associação contendo os identificadores do plano e do projeto.
     */
    void inserir(const AssociacaoPlanoProjeto &associacao);

    /**
     * @brief Exclui fisicamente o vínculo entre um sprint e um projeto do banco de dados.
     * * Efetua um comando DELETE na tabela associativa.
     * * @param codigoPlano Objeto de domínio representando a chave do ciclo de execução.
     * * @param codigoProjeto Objeto de domínio representando a chave do projeto pai.
     */
    void remover(const Codigo &codigoPlano, const Codigo &codigoProjeto);

    /**
     * @brief Recupera todos os vínculos hierárquicos registrados no banco de dados.
     * * Efetua um comando SELECT buscando todas as associações ativas entre planos e projetos.
     * * @return std::vector<AssociacaoPlanoProjeto> Lista contendo todos os objetos de associação encontrados.
     */
    std::vector<AssociacaoPlanoProjeto> listar();

    /**
     * @brief Verifica no banco de dados se um sprint já está vinculado a um projeto específico.
     * * Utilizado para manter a integridade dos dados e evitar duplicação do mesmo vínculo.
     * * @param codigoPlano Objeto de domínio representando a chave do ciclo de execução.
     * * @param codigoProjeto Objeto de domínio representando a chave do projeto pai.
     * * @return bool Retorna true se a associação existir no banco, ou false caso contrário.
     */
    bool existe(const Codigo &codigoPlano, const Codigo &codigoProjeto);
};

#endif // REPOSITORIOASSOCIACAOPLANOPROJETO_H_INCLUDED
