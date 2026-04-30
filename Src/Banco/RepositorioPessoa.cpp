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
