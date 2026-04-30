#include "../../include/banco/RepositorioPlanoDeSprint.h"
#include <stdexcept>
#include <string>

using namespace std;

RepositorioPlanoDeSprint::RepositorioPlanoDeSprint() {
    banco.abrir();
    banco.criarTabelas();
}

void RepositorioPlanoDeSprint::inserir(const PlanoDeSprint &plano) {
    sqlite3 *db;
    sqlite3_stmt *stmt;
    string sql;
    int resultado;

    db = banco.getDB();

    sql = "INSERT INTO plano_sprint (codigo, nome, data_inicio, data_termino, capacidade) VALUES (?, ?, ?, ?, ?);";

    resultado = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        throw invalid_argument("Erro ao preparar insercao de plano.");
    }

    sqlite3_bind_text(stmt, 1, plano.getCodigo().getValor().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, plano.getNome().getValor().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, plano.getDataInicio().getValor().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 4, plano.getDataTermino().getValor().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 5, plano.getCapacidade().getValor());

    resultado = sqlite3_step(stmt);

    sqlite3_finalize(stmt);

    if (resultado != SQLITE_DONE) {
        throw invalid_argument("Plano ja cadastrado ou erro ao inserir.");
    }
}

PlanoDeSprint RepositorioPlanoDeSprint::buscar(const Codigo &codigo) {
    sqlite3 *db;
    sqlite3_stmt *stmt;
    string sql;
    int resultado;

    PlanoDeSprint plano;
    Nome nome;
    Data inicio;
    Data termino;
    Tempo capacidade;

    db = banco.getDB();

    sql = "SELECT nome, data_inicio, data_termino, capacidade FROM plano_sprint WHERE codigo = ?;";

    resultado = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        throw invalid_argument("Erro ao preparar busca de plano.");
    }

    sqlite3_bind_text(stmt, 1, codigo.getValor().c_str(), -1, SQLITE_TRANSIENT);

    resultado = sqlite3_step(stmt);

    if (resultado == SQLITE_ROW) {
        nome.setValor((const char*)sqlite3_column_text(stmt, 0));
        inicio.setValor((const char*)sqlite3_column_text(stmt, 1));
        termino.setValor((const char*)sqlite3_column_text(stmt, 2));
        capacidade.setValor(sqlite3_column_int(stmt, 3));

        plano.setCodigo(codigo);
        plano.setNome(nome);
        plano.setDataInicio(inicio);
        plano.setDataTermino(termino);
        plano.setCapacidade(capacidade);

        sqlite3_finalize(stmt);
        return plano;
    }

    sqlite3_finalize(stmt);

    throw invalid_argument("Plano nao encontrado.");
}

void RepositorioPlanoDeSprint::atualizar(const PlanoDeSprint &plano) {
    sqlite3 *db;
    sqlite3_stmt *stmt;
    string sql;
    int resultado;

    db = banco.getDB();

    sql = "UPDATE plano_sprint SET nome = ?, data_inicio = ?, data_termino = ?, capacidade = ? WHERE codigo = ?;";

    resultado = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        throw invalid_argument("Erro ao preparar atualizacao.");
    }

    sqlite3_bind_text(stmt, 1, plano.getNome().getValor().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, plano.getDataInicio().getValor().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, plano.getDataTermino().getValor().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 4, plano.getCapacidade().getValor());
    sqlite3_bind_text(stmt, 5, plano.getCodigo().getValor().c_str(), -1, SQLITE_TRANSIENT);

    resultado = sqlite3_step(stmt);

    sqlite3_finalize(stmt);

    if (resultado != SQLITE_DONE) {
        throw invalid_argument("Erro ao atualizar plano.");
    }
}

void RepositorioPlanoDeSprint::remover(const Codigo &codigo) {
    sqlite3 *db;
    sqlite3_stmt *stmt;
    string sql;
    int resultado;

    db = banco.getDB();

    sql = "DELETE FROM plano_sprint WHERE codigo = ?;";

    resultado = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        throw invalid_argument("Erro ao preparar remocao.");
    }

    sqlite3_bind_text(stmt, 1, codigo.getValor().c_str(), -1, SQLITE_TRANSIENT);

    resultado = sqlite3_step(stmt);

    sqlite3_finalize(stmt);

    if (resultado != SQLITE_DONE) {
        throw invalid_argument("Erro ao remover plano.");
    }
}
