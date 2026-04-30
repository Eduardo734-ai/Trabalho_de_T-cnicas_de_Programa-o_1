#include "../../include/banco/RepositorioProjeto.h"
#include <stdexcept>
#include <string>

using namespace std;

RepositorioProjeto::RepositorioProjeto() {
    banco.abrir();
    banco.criarTabelas();
}

void RepositorioProjeto::inserir(const Projeto &projeto) {
    sqlite3 *db;
    sqlite3_stmt *stmt;
    string sql;
    int resultado;

    db = banco.getDB();

    sql = "INSERT INTO projeto (codigo, nome, data_inicio, data_termino) VALUES (?, ?, ?, ?);";

    resultado = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        throw invalid_argument("Erro ao preparar insercao de projeto.");
    }

    sqlite3_bind_text(stmt, 1, projeto.getCodigo().getValor().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, projeto.getNome().getValor().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, projeto.getDataInicio().getValor().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 4, projeto.getDataTermino().getValor().c_str(), -1, SQLITE_TRANSIENT);

    resultado = sqlite3_step(stmt);

    sqlite3_finalize(stmt);

    if (resultado != SQLITE_DONE) {
        throw invalid_argument("Projeto ja cadastrado ou erro ao inserir projeto.");
    }
}

Projeto RepositorioProjeto::buscar(const Codigo &codigo) {
    sqlite3 *db;
    sqlite3_stmt *stmt;
    string sql;
    int resultado;

    Projeto projeto;
    Nome nome;
    Data dataInicio;
    Data dataTermino;

    db = banco.getDB();

    sql = "SELECT nome, data_inicio, data_termino FROM projeto WHERE codigo = ?;";

    resultado = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        throw invalid_argument("Erro ao preparar busca de projeto.");
    }

    sqlite3_bind_text(stmt, 1, codigo.getValor().c_str(), -1, SQLITE_TRANSIENT);

    resultado = sqlite3_step(stmt);

    if (resultado == SQLITE_ROW) {
        nome.setValor((const char*)sqlite3_column_text(stmt, 0));
        dataInicio.setValor((const char*)sqlite3_column_text(stmt, 1));
        dataTermino.setValor((const char*)sqlite3_column_text(stmt, 2));

        projeto.setCodigo(codigo);
        projeto.setNome(nome);
        projeto.setDataInicio(dataInicio);
        projeto.setDataTermino(dataTermino);

        sqlite3_finalize(stmt);
        return projeto;
    }

    sqlite3_finalize(stmt);

    throw invalid_argument("Projeto nao encontrado.");
}

void RepositorioProjeto::remover(const Codigo &codigo) {
    sqlite3 *db;
    sqlite3_stmt *stmt;
    string sql;
    int resultado;

    db = banco.getDB();

    sql = "DELETE FROM projeto WHERE codigo = ?;";

    resultado = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        throw invalid_argument("Erro ao preparar remocao de projeto.");
    }

    sqlite3_bind_text(stmt, 1, codigo.getValor().c_str(), -1, SQLITE_TRANSIENT);

    resultado = sqlite3_step(stmt);

    sqlite3_finalize(stmt);

    if (resultado != SQLITE_DONE) {
        throw invalid_argument("Erro ao remover projeto.");
    }
}

void RepositorioProjeto::atualizar(const Projeto &projeto) {
    sqlite3 *db;
    sqlite3_stmt *stmt;
    string sql;
    int resultado;

    db = banco.getDB();

    sql = "UPDATE projeto SET nome = ?, data_inicio = ?, data_termino = ? WHERE codigo = ?;";

    resultado = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        throw invalid_argument("Erro ao preparar atualizacao de projeto.");
    }

    sqlite3_bind_text(stmt, 1, projeto.getNome().getValor().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, projeto.getDataInicio().getValor().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, projeto.getDataTermino().getValor().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 4, projeto.getCodigo().getValor().c_str(), -1, SQLITE_TRANSIENT);

    resultado = sqlite3_step(stmt);

    sqlite3_finalize(stmt);

    if (resultado != SQLITE_DONE) {
        throw invalid_argument("Erro ao atualizar projeto.");
    }
}
