#include "../../include/banco/RepositorioAssociacaoHistoriaProjeto.h"
#include <stdexcept>

using namespace std;

RepositorioAssociacaoHistoriaProjeto::RepositorioAssociacaoHistoriaProjeto() {
    banco.abrir();
    banco.criarTabelas();
}

void RepositorioAssociacaoHistoriaProjeto::inserir(const AssociacaoHistoriaProjeto &associacao) {
    sqlite3_stmt *stmt;
    string sql;
    int resultado;

    sql = "INSERT INTO associacao_historia_projeto (codigo_historia, codigo_projeto) VALUES (?, ?);";

    resultado = sqlite3_prepare_v2(banco.getDB(), sql.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        throw invalid_argument("Erro ao preparar associacao historia-projeto.");
    }

    sqlite3_bind_text(stmt, 1, associacao.getCodigoHistoria().getValor().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, associacao.getCodigoProjeto().getValor().c_str(), -1, SQLITE_TRANSIENT);

    resultado = sqlite3_step(stmt);
    sqlite3_finalize(stmt);

    if (resultado != SQLITE_DONE) {
        throw invalid_argument("Associacao historia-projeto ja cadastrada ou erro ao inserir.");
    }
}

void RepositorioAssociacaoHistoriaProjeto::remover(const Codigo &codigoHistoria, const Codigo &codigoProjeto) {
    sqlite3_stmt *stmt;
    string sql;
    int resultado;

    sql = "DELETE FROM associacao_historia_projeto WHERE codigo_historia = ? AND codigo_projeto = ?;";

    resultado = sqlite3_prepare_v2(banco.getDB(), sql.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        throw invalid_argument("Erro ao preparar remocao historia-projeto.");
    }

    sqlite3_bind_text(stmt, 1, codigoHistoria.getValor().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, codigoProjeto.getValor().c_str(), -1, SQLITE_TRANSIENT);

    resultado = sqlite3_step(stmt);
    sqlite3_finalize(stmt);

    if (resultado != SQLITE_DONE) {
        throw invalid_argument("Erro ao remover associacao historia-projeto.");
    }
}

vector<AssociacaoHistoriaProjeto> RepositorioAssociacaoHistoriaProjeto::listar() {
    vector<AssociacaoHistoriaProjeto> associacoes;
    sqlite3_stmt *stmt;
    string sql;
    int resultado;

    sql = "SELECT codigo_historia, codigo_projeto FROM associacao_historia_projeto;";

    resultado = sqlite3_prepare_v2(banco.getDB(), sql.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        throw invalid_argument("Erro ao listar associacoes historia-projeto.");
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        Codigo codigoHistoria;
        Codigo codigoProjeto;
        AssociacaoHistoriaProjeto associacao;

        codigoHistoria.setValor((const char*)sqlite3_column_text(stmt, 0));
        codigoProjeto.setValor((const char*)sqlite3_column_text(stmt, 1));

        associacao.setCodigoHistoria(codigoHistoria);
        associacao.setCodigoProjeto(codigoProjeto);

        associacoes.push_back(associacao);
    }

    sqlite3_finalize(stmt);
    return associacoes;
}

bool RepositorioAssociacaoHistoriaProjeto::existe(const Codigo &codigoHistoria, const Codigo &codigoProjeto) {
    sqlite3_stmt *stmt;
    string sql;
    int resultado;
    bool encontrado;

    encontrado = false;

    sql = "SELECT 1 FROM associacao_historia_projeto WHERE codigo_historia = ? AND codigo_projeto = ?;";

    resultado = sqlite3_prepare_v2(banco.getDB(), sql.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        throw invalid_argument("Erro ao verificar associacao historia-projeto.");
    }

    sqlite3_bind_text(stmt, 1, codigoHistoria.getValor().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, codigoProjeto.getValor().c_str(), -1, SQLITE_TRANSIENT);

    if (sqlite3_step(stmt) == SQLITE_ROW) {
        encontrado = true;
    }

    sqlite3_finalize(stmt);
    return encontrado;
}
