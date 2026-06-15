#ifndef BANCODADOS_H_INCLUDED
#define BANCODADOS_H_INCLUDED

#include "sqlite3.h"

/**
 * @brief Gerenciador central da conexão com o banco de dados SQLite.
 * * Esta classe atua como o motor de persistência de baixo nível do sistema.
 * Ela encapsula a complexidade da API nativa do SQLite (sqlite3), gerenciando
 * o ciclo de vida do arquivo de banco de dados (abertura e fechamento) e
 * garantindo a criação da estrutura física inicial (tabelas) necessária para
 * o funcionamento das demais classes de Repositório.
 */
class BancoDados {
private:
    sqlite3 *db;

public:
    /**
     * @brief Construtor padrão da classe.
     * * Prepara o objeto para iniciar o gerenciamento da conexão,
     * geralmente inicializando o ponteiro interno do banco como seguro (nulo).
     */
    BancoDados();

    /**
     * @brief Destrutor da classe.
     * * Garante a liberação segura dos recursos, invocando o fechamento
     * da conexão com o banco de dados caso ela ainda esteja ativa ao encerrar o escopo.
     */
    ~BancoDados();

    /**
     * @brief Estabelece a conexão física com o arquivo do banco de dados SQLite.
     * * Caso o arquivo do banco não exista no diretório do executável, ele será
     * criado automaticamente por esta função no momento da chamada.
     * @throw std::runtime_error Lança exceção caso ocorra uma falha técnica na abertura ou criação do arquivo.
     */
    void abrir();

    /**
     * @brief Encerra a conexão ativa com o banco de dados.
     * * Efetiva a liberação do arquivo do banco para o sistema operacional
     * e garante a prevenção de vazamentos de memória (memory leaks).
     */
    void fechar();

    /**
     * @brief Executa as instruções SQL de estruturação inicial (DDL - Data Definition Language).
     * * Executa comandos do tipo "CREATE TABLE IF NOT EXISTS", garantindo que todas as
     * tabelas requeridas pelo domínio do projeto existam antes de qualquer inserção ou leitura.
     */
    void criarTabelas();

    /**
     * @brief Fornece acesso ao ponteiro de conexão subjacente.
     * * Permite que as instâncias dos Repositórios (que operam de forma separada)
     * utilizem a mesma via de comunicação estabelecida por este gerenciador para
     * disparar suas queries.
     * * @return sqlite3* Ponteiro nativo da biblioteca C do SQLite.
     */
    sqlite3* getDB();
};

#endif // BANCODADOS_H_INCLUDED
