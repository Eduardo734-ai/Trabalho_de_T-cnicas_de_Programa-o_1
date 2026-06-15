#ifndef REPOSITORIOASSOCIACAOPROJETOPESSOA_H_INCLUDED
#define REPOSITORIOASSOCIACAOPROJETOPESSOA_H_INCLUDED

#include <vector>
#include "../associacao/AssociacaoProjetoPessoa.h"
#include "BancoDados.h"

/**
 * @brief Classe responsável pela persistência do vínculo entre Projeto e Colaborador (Pessoa) no banco de dados.
 * * Atua como a camada de acesso a dados (DAO) para a entidade associativa de governança.
 * Na estrutura do banco relacional (SQLite), gerencia a tabela de junção que determina
 * a alocação de usuários nas equipes dos empreendimentos. É fundamental para o controle
 * de acesso, garantindo que as permissões e o histórico de participação sejam salvos fisicamente.
 */
class RepositorioAssociacaoProjetoPessoa {
private:
    BancoDados banco;

public:
    /**
     * @brief Inicializa o repositório instanciando a conexão base com o banco de dados.
     */
    RepositorioAssociacaoProjetoPessoa();

    /**
     * @brief Grava a alocação de um usuário na equipe de um projeto no banco de dados.
     * * Efetua um comando INSERT na tabela associativa, concedendo ao colaborador
     * o vínculo com o macroescopo.
     * * @param associacao Objeto da classe de associação contendo os identificadores do projeto e do usuário.
     */
    void inserir(const AssociacaoProjetoPessoa &associacao);

    /**
     * @brief Exclui fisicamente o vínculo entre um projeto e um colaborador do banco de dados.
     * * Efetua um comando DELETE na tabela associativa, removendo o usuário da equipe do projeto.
     * * @param codigoProjeto Objeto de domínio representando a chave do macroescopo.
     * * @param emailPessoa Objeto de domínio representando a chave do usuário (email).
     */
    void remover(const Codigo &codigoProjeto, const Email &emailPessoa);

    /**
     * @brief Recupera todas as alocações de equipes registradas no banco de dados.
     * * Efetua um comando SELECT buscando todos os vínculos ativos entre projetos e pessoas no sistema.
     * * @return std::vector<AssociacaoProjetoPessoa> Lista contendo todos os objetos de associação encontrados.
     */
    std::vector<AssociacaoProjetoPessoa> listar();

    /**
     * @brief Verifica no banco de dados se um colaborador já faz parte da equipe de um projeto específico.
     * * Utilizado para manter a integridade referencial e evitar a inserção duplicada
     * do mesmo usuário na mesma equipe.
     * * @param codigoProjeto Objeto de domínio representando a chave do macroescopo.
     * * @param emailPessoa Objeto de domínio representando a chave do usuário.
     * * @return bool Retorna true se a alocação existir no banco, ou false caso contrário.
     */
    bool existe(const Codigo &codigoProjeto, const Email &emailPessoa);
};

#endif // REPOSITORIOASSOCIACAOPROJETOPESSOA_H_INCLUDED
