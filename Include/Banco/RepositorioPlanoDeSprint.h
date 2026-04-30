#ifndef REPOSITORIOPLANODESPRINT_H_INCLUDED
#define REPOSITORIOPLANODESPRINT_H_INCLUDED

#include "../entidade/PlanoDeSprint.h"
#include "../dominio/Codigo.h"
#include "BancoDados.h"

class RepositorioPlanoDeSprint {
private:
    BancoDados banco;

public:
    RepositorioPlanoDeSprint();

    void inserir(const PlanoDeSprint &plano);
    PlanoDeSprint buscar(const Codigo &codigo);
    void atualizar(const PlanoDeSprint &plano);
    void remover(const Codigo &codigo);
};

#endif // REPOSITORIOPLANODESPRINT_H_INCLUDED
