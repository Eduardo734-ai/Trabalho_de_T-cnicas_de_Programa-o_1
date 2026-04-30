#include "../../include/banco/RepositorioHistoriaUsuario.h"
#include <stdexcept>
#include <string>

using namespace std;

RepositorioHistoriaUsuario::RepositorioHistoriaUsuario() {
    banco.abrir();
    banco.criarTabelas();
}

void RepositorioHistoriaUsuario::inserir(const HistoriaUsuario &historia) {
    sqlite3 *db;
    sqlite3_stmt *stmt;
    string sql;
    int resultado;

    db = banco.getDB();

    sql = "INSERT INTO historia_usuario "
          "(codigo, nome, papel, acao, valor, estimativa, prioridade, estado) "
          "VALUES (?, ?, ?, ?, ?, ?, ?, ?);";

    resultado = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        throw invalid_argument("Erro ao preparar insercao de historia.");
    }

    sqlite3_bind_text(stmt, 1, historia.getCodigo().getValor().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, historia.getNome().getValor().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, historia.getPapel().getValor().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 4, historia.getAcao().getValor().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 5, historia.getValor().getValor().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 6, historia.getEstimativa().getValor());
    sqlite3_bind_text(stmt, 7, historia.getPrioridade().getValor().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 8, historia.getEstado().getValor().c_str(), -1, SQLITE_TRANSIENT);

    resultado = sqlite3_step(stmt);

    sqlite3_finalize(stmt);

    if (resultado != SQLITE_DONE) {
        throw invalid_argument("Historia ja cadastrada ou erro ao inserir.");
    }
}

HistoriaUsuario RepositorioHistoriaUsuario::buscar(const Codigo &codigo) {
    sqlite3 *db;
    sqlite3_stmt *stmt;
    string sql;
    int resultado;

    HistoriaUsuario historia;
    Nome nome;
    Papel papel;
    Texto acao;
    Texto valor;
    Tempo estimativa;
    Prioridade prioridade;
    Estado estado;

    db = banco.getDB();

    sql = "SELECT nome, papel, acao, valor, estimativa, prioridade, estado "
          "FROM historia_usuario WHERE codigo = ?;";

    resultado = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        throw invalid_argument("Erro ao preparar busca de historia.");
    }

    sqlite3_bind_text(stmt, 1, codigo.getValor().c_str(), -1, SQLITE_TRANSIENT);

    resultado = sqlite3_step(stmt);

    if (resultado == SQLITE_ROW) {
        nome.setValor((const char*)sqlite3_column_text(stmt, 0));
        papel.setValor((const char*)sqlite3_column_text(stmt, 1));
        acao.setValor((const char*)sqlite3_column_text(stmt, 2));
        valor.setValor((const char*)sqlite3_column_text(stmt, 3));
        estimativa.setValor(sqlite3_column_int(stmt, 4));
        prioridade.setValor((const char*)sqlite3_column_text(stmt, 5));
        estado.setValor((const char*)sqlite3_column_text(stmt, 6));

        historia.setCodigo(codigo);
        historia.setNome(nome);
        historia.setPapel(papel);
        historia.setAcao(acao);
        historia.setValor(valor);
        historia.setEstimativa(estimativa);
        historia.setPrioridade(prioridade);
        historia.setEstado(estado);

        sqlite3_finalize(stmt);
        return historia;
    }

    sqlite3_finalize(stmt);

    throw invalid_argument("Historia nao encontrada.");
}

void RepositorioHistoriaUsuario::atualizar(const HistoriaUsuario &historia) {
    sqlite3 *db;
    sqlite3_stmt *stmt;
    string sql;
    int resultado;

    db = banco.getDB();

    sql = "UPDATE historia_usuario SET "
          "nome = ?, papel = ?, acao = ?, valor = ?, estimativa = ?, prioridade = ?, estado = ? "
          "WHERE codigo = ?;";

    resultado = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        throw invalid_argument("Erro ao preparar atualizacao de historia.");
    }

    sqlite3_bind_text(stmt, 1, historia.getNome().getValor().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, historia.getPapel().getValor().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, historia.getAcao().getValor().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 4, historia.getValor().getValor().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 5, historia.getEstimativa().getValor());
    sqlite3_bind_text(stmt, 6, historia.getPrioridade().getValor().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 7, historia.getEstado().getValor().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 8, historia.getCodigo().getValor().c_str(), -1, SQLITE_TRANSIENT);

    resultado = sqlite3_step(stmt);

    sqlite3_finalize(stmt);

    if (resultado != SQLITE_DONE) {
        throw invalid_argument("Erro ao atualizar historia.");
    }
}

void RepositorioHistoriaUsuario::remover(const Codigo &codigo) {
    sqlite3 *db;
    sqlite3_stmt *stmt;
    string sql;
    int resultado;

    db = banco.getDB();

    sql = "DELETE FROM historia_usuario WHERE codigo = ?;";

    resultado = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);

    if (resultado != SQLITE_OK) {
        throw invalid_argument("Erro ao preparar remocao de historia.");
    }

    sqlite3_bind_text(stmt, 1, codigo.getValor().c_str(), -1, SQLITE_TRANSIENT);

    resultado = sqlite3_step(stmt);

    sqlite3_finalize(stmt);

    if (resultado != SQLITE_DONE) {
        throw invalid_argument("Erro ao remover historia.");
    }
}
