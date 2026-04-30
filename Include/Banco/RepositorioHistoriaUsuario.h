#ifndef REPOSITORIOHISTORIAUSUARIO_H_INCLUDED
#define REPOSITORIOHISTORIAUSUARIO_H_INCLUDED

#include "../entidade/HistoriaUsuario.h"
#include "../dominio/Codigo.h"
#include "BancoDados.h"

class RepositorioHistoriaUsuario {
private:
    BancoDados banco;

public:
    RepositorioHistoriaUsuario();

    void inserir(const HistoriaUsuario &historia);
    HistoriaUsuario buscar(const Codigo &codigo);
    void atualizar(const HistoriaUsuario &historia);
    void remover(const Codigo &codigo);
};

#endif // REPOSITORIOHISTORIAUSUARIO_H_INCLUDED
