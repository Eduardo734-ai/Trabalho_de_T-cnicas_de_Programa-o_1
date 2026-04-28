#ifndef SERVICOPROJETO_H_INCLUDED
#define SERVICOPROJETO_H_INCLUDED

#include<vector>

#include"../interface/IServicoProjeto.h"
#include"../entidade/Pessoa.h"

#include"ContainerProjetos.h"
#include"ContainerHistoriasUsuario.h"
#include"ContainerPlanosDeSprint.h"

#include"ContainerAssociacaoProjetoPessoa.h"
#include"ContainerAssociacaoHistoriaProjeto.h"
#include"ContainerAssociacaoPlanoProjeto.h"


class ServicoProjeto : public IServicoProjeto{
    private:
        ContainerProjetos container;
        ContainerHistoriasUsuario containerHistorias;
        ContainerPlanosDeSprint containerPlanos;

        ContainerAssociacaoProjetoPessoa associacoesProjetoPessoa;
        ContainerAssociacaoHistoriaProjeto associacoesHistoriaProjeto;
        ContainerAssociacaoPlanoProjeto associacoesPlanoProjeto;

    public:
        ServicoProjeto();

        void criar(const Projeto &projeto)override;
        Projeto ler(const Codigo &codigo)override;
        void atualizar(const Projeto &projeto)override;
        void excluir(const Codigo &codigo)override;

        void atualizarDadosProjeto(const Codigo &codigo, const Nome &nome, const Data &inicio, const Data &termino);
        void criarAssociadoPessoa(const Projeto &projeto,const Pessoa &pessoa);
        void criarHistoriaAssociadaProjeto(HistoriaUsuario historia,const Codigo &codigoProjeto);
        void criarPlanoAssociadoProjeto(const PlanoDeSprint &plano,const Codigo &codigoProjeto);


        std::vector<Projeto> listarProjetosAssociadosPessoa(const Email &email)override;
        std::vector<HistoriaUsuario>listarHistoriasAssociadasProjeto(const Codigo &codigoProjeto)override;
        std::vector<PlanoDeSprint>listarPlanosAssociadosProjeto(const Codigo &codigoProjeto)override;

        void associarProjetoPessoa(const Codigo &codigoProjeto,const Email &emailPessoa);
        void associarHistoriaProjeto(const Codigo &codigoHistoria,const Codigo &codigoProjeto);
        void associarPlanoProjeto(const Codigo &codigoPlano,const Codigo &codigoProjeto);

        void registrarHistoria(const HistoriaUsuario &historia);
        void registrarPlano(const PlanoDeSprint &plano);
};

#endif // SERVICOPROJETO_H_INCLUDED
