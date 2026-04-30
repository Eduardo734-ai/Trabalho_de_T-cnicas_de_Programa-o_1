#include "../../include/banco/RepositorioPessoa.h"
#include <iostream>

using namespace std;

RepositorioPessoa::RepositorioPessoa() {
    banco.abrir();
    banco.criarTabelas();
}

void RepositorioPessoa::inserir(const Pessoa &pessoa) {
    sqlite3 *db = banco.getDB();

    string sql = "INSERT INTO pessoa VALUES('" +
                 pessoa.getEmail().getValor() + "','" +
                 pessoa.getNome().getValor() + "','" +
                 pessoa.getSenha().getValor() + "','" +
                 pessoa.getPapel().getValor() + "');";

    char *erro = nullptr;
    sqlite3_exec(db, sql.c_str(), 0, 0, &erro);
}

Pessoa RepositorioPessoa::buscar(const Email &email) {
    sqlite3 *db = banco.getDB();
    Pessoa pessoa;

    string sql = "SELECT * FROM pessoa WHERE email='" +
                 email.getValor() + "';";

    sqlite3_stmt *stmt;

    sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0);

    if (sqlite3_step(stmt) == SQLITE_ROW) {
        Nome nome;
        Senha senha;
        Papel papel;

        nome.setValor((const char*)sqlite3_column_text(stmt, 1));
        senha.setValor((const char*)sqlite3_column_text(stmt, 2));
        papel.setValor((const char*)sqlite3_column_text(stmt, 3));

        pessoa.setEmail(email);
        pessoa.setNome(nome);
        pessoa.setSenha(senha);
        pessoa.setPapel(papel);
    }

    sqlite3_finalize(stmt);

    return pessoa;
}

void RepositorioPessoa::atualizar(const Pessoa &pessoa) {
    sqlite3_stmt *stmt;
    string sql;
    int resultado;

    sql = "UPDATE pessoa SET nome = ?, senha = ?, papel = ? WHERE email = ?;";

    resultado = sqlite3_prepare_v2(banco.getDB(), sql.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        throw invalid_argument("Erro ao preparar atualizacao de pessoa.");
    }

    sqlite3_bind_text(stmt, 1, pessoa.getNome().getValor().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, pessoa.getSenha().getValor().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, pessoa.getPapel().getValor().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 4, pessoa.getEmail().getValor().c_str(), -1, SQLITE_TRANSIENT);

    resultado = sqlite3_step(stmt);
    sqlite3_finalize(stmt);

    if (resultado != SQLITE_DONE) {
        throw invalid_argument("Erro ao atualizar pessoa.");
    }
}

void RepositorioPessoa::remover(const Email &email) {
    sqlite3_stmt *stmt;
    string sql;
    int resultado;

    sql = "DELETE FROM pessoa WHERE email = ?;";

    resultado = sqlite3_prepare_v2(banco.getDB(), sql.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        throw invalid_argument("Erro ao preparar remocao de pessoa.");
    }

    sqlite3_bind_text(stmt, 1, email.getValor().c_str(), -1, SQLITE_TRANSIENT);

    resultado = sqlite3_step(stmt);
    sqlite3_finalize(stmt);

    if (resultado != SQLITE_DONE) {
        throw invalid_argument("Erro ao remover pessoa.");
    }
}
