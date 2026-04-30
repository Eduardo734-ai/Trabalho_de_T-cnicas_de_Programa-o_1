#include "../../include/banco/BancoDados.h"
#include <iostream>

using namespace std;

BancoDados::BancoDados() {
    db = nullptr;
}

BancoDados::~BancoDados() {
    fechar();
}

void BancoDados::abrir() {
    if (sqlite3_open("sistema.db", &db)) {
        cout << "Erro ao abrir banco." << endl;
    }
}

void BancoDados::fechar() {
    if (db) {
        sqlite3_close(db);
    }
}

sqlite3* BancoDados::getDB() {
    return db;
}

void BancoDados::criarTabelas() {
    const char *sqlPessoa =
        "CREATE TABLE IF NOT EXISTS pessoa ("
        "email TEXT PRIMARY KEY,"
        "nome TEXT,"
        "senha TEXT,"
        "papel TEXT);";

    const char *sqlProjeto =
        "CREATE TABLE IF NOT EXISTS projeto ("
        "codigo TEXT PRIMARY KEY,"
        "nome TEXT,"
        "data_inicio TEXT,"
        "data_termino TEXT);";

    const char *sqlPlanoSprint =
        "CREATE TABLE IF NOT EXISTS plano_sprint ("
        "codigo TEXT PRIMARY KEY,"
        "nome TEXT,"
        "data_inicio TEXT,"
        "data_termino TEXT,"
        "capacidade INTEGER);";

    const char *sqlHistoriaUsuario =
        "CREATE TABLE IF NOT EXISTS historia_usuario ("
        "codigo TEXT PRIMARY KEY,"
        "nome TEXT,"
        "papel TEXT,"
        "acao TEXT,"
        "valor TEXT,"
        "estimativa INTEGER,"
        "prioridade TEXT,"
        "estado TEXT);";

    const char *sqlAssociacaoProjetoPessoa =
        "CREATE TABLE IF NOT EXISTS associacao_projeto_pessoa ("
        "codigo_projeto TEXT,"
        "email_pessoa TEXT,"
        "PRIMARY KEY (codigo_projeto, email_pessoa));";

    const char *sqlAssociacaoHistoriaProjeto =
        "CREATE TABLE IF NOT EXISTS associacao_historia_projeto ("
        "codigo_historia TEXT,"
        "codigo_projeto TEXT,"
        "PRIMARY KEY (codigo_historia, codigo_projeto));";

    const char *sqlAssociacaoPlanoProjeto =
        "CREATE TABLE IF NOT EXISTS associacao_plano_projeto ("
        "codigo_plano TEXT,"
        "codigo_projeto TEXT,"
        "PRIMARY KEY (codigo_plano, codigo_projeto));";

    const char *sqlAssociacaoHistoriaPessoa =
        "CREATE TABLE IF NOT EXISTS associacao_historia_pessoa ("
        "codigo_historia TEXT,"
        "email_pessoa TEXT,"
        "PRIMARY KEY (codigo_historia, email_pessoa));";

    const char *sqlAssociacaoHistoriaPlano =
        "CREATE TABLE IF NOT EXISTS associacao_historia_plano ("
        "codigo_historia TEXT,"
        "codigo_plano TEXT,"
        "PRIMARY KEY (codigo_historia, codigo_plano));";

    char *erro = nullptr;

    sqlite3_exec(db, sqlPessoa, 0, 0, &erro);
    sqlite3_exec(db, sqlProjeto, 0, 0, &erro);
    sqlite3_exec(db, sqlPlanoSprint, 0, 0, &erro);
    sqlite3_exec(db, sqlHistoriaUsuario, 0, 0, &erro);

    sqlite3_exec(db, sqlAssociacaoProjetoPessoa, 0, 0, &erro);
    sqlite3_exec(db, sqlAssociacaoHistoriaProjeto, 0, 0, &erro);
    sqlite3_exec(db, sqlAssociacaoPlanoProjeto, 0, 0, &erro);
    sqlite3_exec(db, sqlAssociacaoHistoriaPessoa, 0, 0, &erro);
    sqlite3_exec(db, sqlAssociacaoHistoriaPlano, 0, 0, &erro);
}
