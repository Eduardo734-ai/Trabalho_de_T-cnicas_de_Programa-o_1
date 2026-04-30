#include "../../include/banco/RepositorioAssociacaoProjetoPessoa.h"
#include <stdexcept>

using namespace std;

RepositorioAssociacaoProjetoPessoa::RepositorioAssociacaoProjetoPessoa() {
    banco.abrir();
    banco.criarTabelas();
}

void RepositorioAssociacaoProjetoPessoa::inserir(const AssociacaoProjetoPessoa &associacao) {
    sqlite3_stmt *stmt;
    string sql;
    int resultado;

    sql = "INSERT INTO associacao_projeto_pessoa (codigo_projeto, email_pessoa) VALUES (?, ?);";

    resultado = sqlite3_prepare_v2(banco.getDB(), sql.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        throw invalid_argument("Erro ao preparar associacao projeto-pessoa.");
    }

    sqlite3_bind_text(stmt, 1, associacao.getCodigoProjeto().getValor().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, associacao.getEmailPessoa().getValor().c_str(), -1, SQLITE_TRANSIENT);

    resultado = sqlite3_step(stmt);
    sqlite3_finalize(stmt);

    if (resultado != SQLITE_DONE) {
        throw invalid_argument("Associacao projeto-pessoa ja cadastrada ou erro ao inserir.");
    }
}

void RepositorioAssociacaoProjetoPessoa::remover(const Codigo &codigoProjeto, const Email &emailPessoa) {
    sqlite3_stmt *stmt;
    string sql;
    int resultado;

    sql = "DELETE FROM associacao_projeto_pessoa WHERE codigo_projeto = ? AND email_pessoa = ?;";

    resultado = sqlite3_prepare_v2(banco.getDB(), sql.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        throw invalid_argument("Erro ao preparar remocao projeto-pessoa.");
    }

    sqlite3_bind_text(stmt, 1, codigoProjeto.getValor().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, emailPessoa.getValor().c_str(), -1, SQLITE_TRANSIENT);

    resultado = sqlite3_step(stmt);
    sqlite3_finalize(stmt);

    if (resultado != SQLITE_DONE) {
        throw invalid_argument("Erro ao remover associacao projeto-pessoa.");
    }
}

vector<AssociacaoProjetoPessoa> RepositorioAssociacaoProjetoPessoa::listar() {
    vector<AssociacaoProjetoPessoa> associacoes;
    sqlite3_stmt *stmt;
    string sql;
    int resultado;

    sql = "SELECT codigo_projeto, email_pessoa FROM associacao_projeto_pessoa;";

    resultado = sqlite3_prepare_v2(banco.getDB(), sql.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        throw invalid_argument("Erro ao listar associacoes projeto-pessoa.");
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        Codigo codigoProjeto;
        Email emailPessoa;
        AssociacaoProjetoPessoa associacao;

        codigoProjeto.setValor((const char*)sqlite3_column_text(stmt, 0));
        emailPessoa.setValor((const char*)sqlite3_column_text(stmt, 1));

        associacao.setCodigoProjeto(codigoProjeto);
        associacao.setEmailPessoa(emailPessoa);

        associacoes.push_back(associacao);
    }

    sqlite3_finalize(stmt);
    return associacoes;
}

bool RepositorioAssociacaoProjetoPessoa::existe(const Codigo &codigoProjeto, const Email &emailPessoa) {
    sqlite3_stmt *stmt;
    string sql;
    int resultado;
    bool encontrado;

    encontrado = false;

    sql = "SELECT 1 FROM associacao_projeto_pessoa WHERE codigo_projeto = ? AND email_pessoa = ?;";

    resultado = sqlite3_prepare_v2(banco.getDB(), sql.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        throw invalid_argument("Erro ao verificar associacao projeto-pessoa.");
    }

    sqlite3_bind_text(stmt, 1, codigoProjeto.getValor().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, emailPessoa.getValor().c_str(), -1, SQLITE_TRANSIENT);

    if (sqlite3_step(stmt) == SQLITE_ROW) {
        encontrado = true;
    }

    sqlite3_finalize(stmt);
    return encontrado;
}
