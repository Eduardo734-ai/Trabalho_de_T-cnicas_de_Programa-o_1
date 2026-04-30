#include "../../include/banco/RepositorioAssociacaoPlanoProjeto.h"
#include <stdexcept>

using namespace std;

RepositorioAssociacaoPlanoProjeto::RepositorioAssociacaoPlanoProjeto() {
    banco.abrir();
    banco.criarTabelas();
}

void RepositorioAssociacaoPlanoProjeto::inserir(const AssociacaoPlanoProjeto &associacao) {
    sqlite3_stmt *stmt;
    string sql;
    int resultado;

    sql = "INSERT INTO associacao_plano_projeto (codigo_plano, codigo_projeto) VALUES (?, ?);";

    resultado = sqlite3_prepare_v2(banco.getDB(), sql.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        throw invalid_argument("Erro ao preparar associacao plano-projeto.");
    }

    sqlite3_bind_text(stmt, 1, associacao.getCodigoPlano().getValor().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, associacao.getCodigoProjeto().getValor().c_str(), -1, SQLITE_TRANSIENT);

    resultado = sqlite3_step(stmt);
    sqlite3_finalize(stmt);

    if (resultado != SQLITE_DONE) {
        throw invalid_argument("Associacao plano-projeto ja cadastrada ou erro ao inserir.");
    }
}

void RepositorioAssociacaoPlanoProjeto::remover(const Codigo &codigoPlano, const Codigo &codigoProjeto) {
    sqlite3_stmt *stmt;
    string sql;
    int resultado;

    sql = "DELETE FROM associacao_plano_projeto WHERE codigo_plano = ? AND codigo_projeto = ?;";

    resultado = sqlite3_prepare_v2(banco.getDB(), sql.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        throw invalid_argument("Erro ao preparar remocao plano-projeto.");
    }

    sqlite3_bind_text(stmt, 1, codigoPlano.getValor().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, codigoProjeto.getValor().c_str(), -1, SQLITE_TRANSIENT);

    resultado = sqlite3_step(stmt);
    sqlite3_finalize(stmt);

    if (resultado != SQLITE_DONE) {
        throw invalid_argument("Erro ao remover associacao plano-projeto.");
    }
}

vector<AssociacaoPlanoProjeto> RepositorioAssociacaoPlanoProjeto::listar() {
    vector<AssociacaoPlanoProjeto> associacoes;
    sqlite3_stmt *stmt;
    string sql;
    int resultado;

    sql = "SELECT codigo_plano, codigo_projeto FROM associacao_plano_projeto;";

    resultado = sqlite3_prepare_v2(banco.getDB(), sql.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        throw invalid_argument("Erro ao listar associacoes plano-projeto.");
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        Codigo codigoPlano;
        Codigo codigoProjeto;
        AssociacaoPlanoProjeto associacao;

        codigoPlano.setValor((const char*)sqlite3_column_text(stmt, 0));
        codigoProjeto.setValor((const char*)sqlite3_column_text(stmt, 1));

        associacao.setCodigoPlano(codigoPlano);
        associacao.setCodigoProjeto(codigoProjeto);

        associacoes.push_back(associacao);
    }

    sqlite3_finalize(stmt);
    return associacoes;
}

bool RepositorioAssociacaoPlanoProjeto::existe(const Codigo &codigoPlano, const Codigo &codigoProjeto) {
    sqlite3_stmt *stmt;
    string sql;
    int resultado;
    bool encontrado;

    encontrado = false;

    sql = "SELECT 1 FROM associacao_plano_projeto WHERE codigo_plano = ? AND codigo_projeto = ?;";

    resultado = sqlite3_prepare_v2(banco.getDB(), sql.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        throw invalid_argument("Erro ao verificar associacao plano-projeto.");
    }

    sqlite3_bind_text(stmt, 1, codigoPlano.getValor().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, codigoProjeto.getValor().c_str(), -1, SQLITE_TRANSIENT);

    if (sqlite3_step(stmt) == SQLITE_ROW) {
        encontrado = true;
    }

    sqlite3_finalize(stmt);
    return encontrado;
}
