#ifndef BANCODADOS_H_INCLUDED
#define BANCODADOS_H_INCLUDED

#include "sqlite3.h"

class BancoDados {
private:
    sqlite3 *db;

public:
    BancoDados();
    ~BancoDados();

    void abrir();
    void fechar();
    void criarTabelas();

    sqlite3* getDB();
};

#endif // BANCODADOS_H_INCLUDED
