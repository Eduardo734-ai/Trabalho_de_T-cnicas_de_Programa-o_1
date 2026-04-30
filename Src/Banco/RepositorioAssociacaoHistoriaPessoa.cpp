#include "../../include/banco/RepositorioAssociacaoHistoriaPessoa.h"
#include <stdexcept>

using namespace std;

RepositorioAssociacaoHistoriaPessoa::RepositorioAssociacaoHistoriaPessoa() {
    banco.abrir();
    banco.criarTabelas();
}

void RepositorioAssociacaoHistoriaPessoa::inserir(const AssociacaoHistoriaPessoa &associacao) {
    sqlite3_stmt *stmt;
    string sql;
    int resultado;

    sql = "INSERT INTO associacao_historia_pessoa (codigo_historia, email_pessoa) VALUES (?, ?);";

    resultado = sqlite3_prepare_v2(banco.getDB(), sql.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        throw invalid_argument("Erro ao preparar associacao historia-pessoa.");
    }

    sqlite3_bind_text(stmt, 1, associacao.getCodigoHistoria().getValor().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, associacao.getEmailPessoa().getValor().c_str(), -1, SQLITE_TRANSIENT);

    resultado = sqlite3_step(stmt);
    sqlite3_finalize(stmt);

    if (resultado != SQLITE_DONE) {
        throw invalid_argument("Associacao historia-pessoa ja cadastrada ou erro ao inserir.");
    }
}

void RepositorioAssociacaoHistoriaPessoa::remover(const Codigo &codigoHistoria, const Email &emailPessoa) {
    sqlite3_stmt *stmt;
    string sql;
    int resultado;

    sql = "DELETE FROM associacao_historia_pessoa WHERE codigo_historia = ? AND email_pessoa = ?;";

    resultado = sqlite3_prepare_v2(banco.getDB(), sql.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        throw invalid_argument("Erro ao preparar remocao historia-pessoa.");
    }

    sqlite3_bind_text(stmt, 1, codigoHistoria.getValor().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, emailPessoa.getValor().c_str(), -1, SQLITE_TRANSIENT);

    resultado = sqlite3_step(stmt);
    sqlite3_finalize(stmt);

    if (resultado != SQLITE_DONE) {
        throw invalid_argument("Erro ao remover associacao historia-pessoa.");
    }
}

vector<AssociacaoHistoriaPessoa> RepositorioAssociacaoHistoriaPessoa::listar() {
    vector<AssociacaoHistoriaPessoa> associacoes;
    sqlite3_stmt *stmt;
    string sql;
    int resultado;

    sql = "SELECT codigo_historia, email_pessoa FROM associacao_historia_pessoa;";

    resultado = sqlite3_prepare_v2(banco.getDB(), sql.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        throw invalid_argument("Erro ao listar associacoes historia-pessoa.");
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        Codigo codigoHistoria;
        Email emailPessoa;
        AssociacaoHistoriaPessoa associacao;

        codigoHistoria.setValor((const char*)sqlite3_column_text(stmt, 0));
        emailPessoa.setValor((const char*)sqlite3_column_text(stmt, 1));

        associacao.setCodigoHistoria(codigoHistoria);
        associacao.setEmailPessoa(emailPessoa);

        associacoes.push_back(associacao);
    }

    sqlite3_finalize(stmt);
    return associacoes;
}

bool RepositorioAssociacaoHistoriaPessoa::existe(const Codigo &codigoHistoria, const Email &emailPessoa) {
    sqlite3_stmt *stmt;
    string sql;
    int resultado;
    bool encontrado;

    encontrado = false;

    sql = "SELECT 1 FROM associacao_historia_pessoa WHERE codigo_historia = ? AND email_pessoa = ?;";

    resultado = sqlite3_prepare_v2(banco.getDB(), sql.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        throw invalid_argument("Erro ao verificar associacao historia-pessoa.");
    }

    sqlite3_bind_text(stmt, 1, codigoHistoria.getValor().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, emailPessoa.getValor().c_str(), -1, SQLITE_TRANSIENT);

    if (sqlite3_step(stmt) == SQLITE_ROW) {
        encontrado = true;
    }

    sqlite3_finalize(stmt);
    return encontrado;
}
