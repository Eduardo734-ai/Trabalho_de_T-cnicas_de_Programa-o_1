#ifndef REPOSITORIOASSOCIACAOHISTORIAPLANO_H_INCLUDED
#define REPOSITORIOASSOCIACAOHISTORIAPLANO_H_INCLUDED

#include <vector>
#include "../associacao/AssociacaoHistoriaPlano.h"
#include "BancoDados.h"

/**
 * @brief Classe responsável pela persistência do vínculo entre História de Usuário e Plano de Sprint no banco de dados.
 * * Atua como a camada de acesso a dados (DAO) para a entidade associativa.
 * Na estrutura do banco relacional (SQLite), gerencia a tabela de junção que mapeia
 * a alocação de um requisito funcional (História) dentro de uma iteração específica (Plano).
 * Isola os comandos SQL responsáveis por formar o Sprint Backlog no banco.
 */
class RepositorioAssociacaoHistoriaPlano {
private:
    BancoDados banco;

public:
    /**
     * @brief Inicializa o repositório instanciando a conexão base com o banco de dados.
     */
    RepositorioAssociacaoHistoriaPlano();

    /**
     * @brief Grava a alocação de uma tarefa em um sprint no banco de dados.
     * * Efetua um comando INSERT na tabela associativa, indicando que a história
     * agora faz parte do escopo daquele plano.
     * * @param associacao Objeto da classe de associação contendo os identificadores da história e do plano.
     */
    void inserir(const AssociacaoHistoriaPlano &associacao);

    /**
     * @brief Exclui fisicamente o vínculo entre uma tarefa e um sprint do banco de dados.
     * * Efetua um comando DELETE na tabela associativa, retirando a história do escopo da iteração.
     * * @param codigoHistoria Objeto de domínio representando a chave da tarefa.
     * * @param codigoPlano Objeto de domínio representando a chave do ciclo de execução.
     */
    void remover(const Codigo &codigoHistoria, const Codigo &codigoPlano);

    /**
     * @brief Recupera todas as alocações de sprint registradas no banco de dados.
     * * Efetua um comando SELECT buscando todos os vínculos ativos no sistema.
     * * @return std::vector<AssociacaoHistoriaPlano> Lista contendo todos os objetos de associação encontrados.
     */
    std::vector<AssociacaoHistoriaPlano> listar();

    /**
     * @brief Verifica no banco de dados se uma tarefa já está alocada em um sprint específico.
     * * Utilizado para manter a integridade dos dados, evitando que a mesma história
     * seja inserida duplicadamente no mesmo plano.
     * * @param codigoHistoria Objeto de domínio representando a chave da tarefa.
     * * @param codigoPlano Objeto de domínio representando a chave do ciclo de execução.
     * * @return bool Retorna true se a alocação existir no banco, ou false caso contrário.
     */
    bool existe(const Codigo &codigoHistoria, const Codigo &codigoPlano);
};

#endif // REPOSITORIOASSOCIACAOHISTORIAPLANO_H_INCLUDED
