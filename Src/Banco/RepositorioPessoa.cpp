#include "../../include/banco/RepositorioPessoa.h"
#include <iostream>

using namespace std;

RepositorioPessoa::RepositorioPessoa() {
    banco.abrir();
    banco.criarTabelas();
}

void RepositorioPessoa::inserir(const Pessoa &pessoa) {
    sqlite3_stmt *stmt;
    string sql = "INSERT INTO pessoa (email, nome, senha, papel) VALUES (?, ?, ?, ?);";

    int resultado = sqlite3_prepare_v2(banco.getDB(), sql.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        throw invalid_argument("Erro ao preparar insercao de pessoa.");
    }

    sqlite3_bind_text(stmt, 1, pessoa.getEmail().getValor().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, pessoa.getNome().getValor().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, pessoa.getSenha().getValor().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 4, pessoa.getPapel().getValor().c_str(), -1, SQLITE_TRANSIENT);

    resultado = sqlite3_step(stmt);
    sqlite3_finalize(stmt);

    if (resultado != SQLITE_DONE) {
        throw invalid_argument("Pessoa ja cadastrada ou erro ao inserir pessoa.");
    }
}

Pessoa RepositorioPessoa::buscar(const Email &email) {
    sqlite3_stmt *stmt;
    Pessoa pessoa;

    string sql = "SELECT nome, senha, papel FROM pessoa WHERE email = ?;";

    int resultado = sqlite3_prepare_v2(banco.getDB(), sql.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        throw invalid_argument("Erro ao preparar busca de pessoa.");
    }

    sqlite3_bind_text(stmt, 1, email.getValor().c_str(), -1, SQLITE_TRANSIENT);

    resultado = sqlite3_step(stmt);

    if (resultado == SQLITE_ROW) {
        Nome nome;
        Senha senha;
        Papel papel;

        nome.setValor((const char*)sqlite3_column_text(stmt, 0));
        senha.setValor((const char*)sqlite3_column_text(stmt, 1));
        papel.setValor((const char*)sqlite3_column_text(stmt, 2));

        pessoa.setEmail(email);
        pessoa.setNome(nome);
        pessoa.setSenha(senha);
        pessoa.setPapel(papel);

        sqlite3_finalize(stmt);
        return pessoa;
    }

    sqlite3_finalize(stmt);

    throw invalid_argument("Pessoa nao encontrada.");
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
