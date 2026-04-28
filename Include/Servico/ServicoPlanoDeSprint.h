#ifndef SERVICOPLANODESPRINT_H_INCLUDED
#define SERVICOPLANODESPRINT_H_INCLUDED

#include<vector>

#include"../interface/IServicoPlanoDeSprint.h"
#include"ContainerPlanosDeSprint.h"
#include"ContainerHistoriasUsuario.h"
#include"ContainerAssociacaoHistoriaPlano.h"

class ServicoPlanoDeSprint : public IServicoPlanoDeSprint{
    private:
        ContainerPlanosDeSprint container;
        ContainerHistoriasUsuario containerHistorias;
        ContainerAssociacaoHistoriaPlano associacoesHistoriaPlano;
    public:
        ServicoPlanoDeSprint();

        void criar(const PlanoDeSprint &plano)override;
        PlanoDeSprint ler(const Codigo &codigo)override;
        void atualizar(const PlanoDeSprint &plano)override;
        void excluir(const Codigo &codigo)override;

        std::vector<HistoriaUsuario> listarHistoriasAssociadasPlano(const Codigo &codigoPlano)override;

        void registrarHistoria(const HistoriaUsuario &historia);
        void associarHistoriaPlano(const Codigo &codigoHistoria, const Codigo &codigoPlano);
};

#endif // SERVICOPLANODESPRINT_H_INCLUDED
