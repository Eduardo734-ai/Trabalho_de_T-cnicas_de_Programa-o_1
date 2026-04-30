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

    char *erro = nullptr;

    sqlite3_exec(db, sqlPessoa, 0, 0, &erro);
}
