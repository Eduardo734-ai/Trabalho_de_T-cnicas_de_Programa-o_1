#include "../../include/banco/RepositorioAssociacaoHistoriaPlano.h"
#include <stdexcept>

using namespace std;

RepositorioAssociacaoHistoriaPlano::RepositorioAssociacaoHistoriaPlano() {
    banco.abrir();
    banco.criarTabelas();
}

void RepositorioAssociacaoHistoriaPlano::inserir(const AssociacaoHistoriaPlano &associacao) {
    sqlite3_stmt *stmt;
    string sql;
    int resultado;

    sql = "INSERT INTO associacao_historia_plano (codigo_historia, codigo_plano) VALUES (?, ?);";

    resultado = sqlite3_prepare_v2(banco.getDB(), sql.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        throw invalid_argument("Erro ao preparar associacao historia-plano.");
    }

    sqlite3_bind_text(stmt, 1, associacao.getCodigoHistoria().getValor().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, associacao.getCodigoPlano().getValor().c_str(), -1, SQLITE_TRANSIENT);

    resultado = sqlite3_step(stmt);
    sqlite3_finalize(stmt);

    if (resultado != SQLITE_DONE) {
        throw invalid_argument("Associacao historia-plano ja cadastrada ou erro ao inserir.");
    }
}

void RepositorioAssociacaoHistoriaPlano::remover(const Codigo &codigoHistoria, const Codigo &codigoPlano) {
    sqlite3_stmt *stmt;
    string sql;
    int resultado;

    sql = "DELETE FROM associacao_historia_plano WHERE codigo_historia = ? AND codigo_plano = ?;";

    resultado = sqlite3_prepare_v2(banco.getDB(), sql.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        throw invalid_argument("Erro ao preparar remocao historia-plano.");
    }

    sqlite3_bind_text(stmt, 1, codigoHistoria.getValor().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, codigoPlano.getValor().c_str(), -1, SQLITE_TRANSIENT);

    resultado = sqlite3_step(stmt);
    sqlite3_finalize(stmt);

    if (resultado != SQLITE_DONE) {
        throw invalid_argument("Erro ao remover associacao historia-plano.");
    }
}

vector<AssociacaoHistoriaPlano> RepositorioAssociacaoHistoriaPlano::listar() {
    vector<AssociacaoHistoriaPlano> associacoes;
    sqlite3_stmt *stmt;
    string sql;
    int resultado;

    sql = "SELECT codigo_historia, codigo_plano FROM associacao_historia_plano;";

    resultado = sqlite3_prepare_v2(banco.getDB(), sql.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        throw invalid_argument("Erro ao listar associacoes historia-plano.");
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        Codigo codigoHistoria;
        Codigo codigoPlano;
        AssociacaoHistoriaPlano associacao;

        codigoHistoria.setValor((const char*)sqlite3_column_text(stmt, 0));
        codigoPlano.setValor((const char*)sqlite3_column_text(stmt, 1));

        associacao.setCodigoHistoria(codigoHistoria);
        associacao.setCodigoPlano(codigoPlano);

        associacoes.push_back(associacao);
    }

    sqlite3_finalize(stmt);
    return associacoes;
}

bool RepositorioAssociacaoHistoriaPlano::existe(const Codigo &codigoHistoria, const Codigo &codigoPlano) {
    sqlite3_stmt *stmt;
    string sql;
    int resultado;
    bool encontrado;

    encontrado = false;

    sql = "SELECT 1 FROM associacao_historia_plano WHERE codigo_historia = ? AND codigo_plano = ?;";

    resultado = sqlite3_prepare_v2(banco.getDB(), sql.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        throw invalid_argument("Erro ao verificar associacao historia-plano.");
    }

    sqlite3_bind_text(stmt, 1, codigoHistoria.getValor().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, codigoPlano.getValor().c_str(), -1, SQLITE_TRANSIENT);

    if (sqlite3_step(stmt) == SQLITE_ROW) {
        encontrado = true;
    }

    sqlite3_finalize(stmt);
    return encontrado;
}
