#ifndef ISERVICOPLANODESPRINT_H_INCLUDED
#define ISERVICOPLANODESPRINT_H_INCLUDED

#include<vector>

#include"entidade/PlanoDeSprint.h"
#include"entidade/HistoriaUsuario.h"
#include"dominio/Codigo.h"

using namespace std;

class IServicoPlanoDeSprint{
    public:
        virtual void criar(const PlanoDeSprint &plano) = 0;
        virtual PlanoDeSprint ler(const Codigo &codigo) = 0;
        virtual void atualizar(const PlanoDeSprint &plano) = 0;
        virtual void excluir(const Codigo &codigo) = 0;

        virtual vector<HistoriaUsuario> listarHistoriasAssociadasPlano(const Codigo &codigoPlano) = 0;

        virtual ~IServicoPlanoDeSprint(){}
};

#endif // ISERVICOPLANODESPRINT_H_INCLUDED
