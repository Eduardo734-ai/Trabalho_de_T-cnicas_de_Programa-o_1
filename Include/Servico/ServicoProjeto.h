#ifndef SERVICOPROJETO_H_INCLUDED
#define SERVICOPROJETO_H_INCLUDED

#include <vector>

#include "../interface/IServicoProjeto.h"
#include "../entidade/Pessoa.h"

#include "../banco/RepositorioProjeto.h"
#include "../banco/RepositorioAssociacaoProjetoPessoa.h"
#include "../banco/RepositorioAssociacaoHistoriaProjeto.h"
#include "../banco/RepositorioAssociacaoPlanoProjeto.h"
#include "../banco/RepositorioPlanoDeSprint.h"
#include "../banco/RepositorioHistoriaUsuario.h"

#include "ContainerHistoriasUsuario.h"
#include "ContainerPlanosDeSprint.h"

class ServicoProjeto : public IServicoProjeto {
private:
    RepositorioProjeto repositorioProjeto;
    RepositorioPlanoDeSprint repositorioPlano;
    RepositorioHistoriaUsuario repositorioHistoria;

    RepositorioAssociacaoProjetoPessoa repositorioAssociacaoProjetoPessoa;
    RepositorioAssociacaoHistoriaProjeto repositorioAssociacaoHistoriaProjeto;
    RepositorioAssociacaoPlanoProjeto repositorioAssociacaoPlanoProjeto;

    ContainerHistoriasUsuario containerHistorias;
    ContainerPlanosDeSprint containerPlanos;

public:
    ServicoProjeto();

    void criar(const Projeto &projeto) override;
    Projeto ler(const Codigo &codigo) override;
    void atualizar(const Projeto &projeto) override;
    void excluir(const Codigo &codigo) override;

    void atualizarDadosProjeto(const Codigo &codigo,
                               const Nome &nome,
                               const Data &inicio,
                               const Data &termino);

    void criarAssociadoPessoa(const Projeto &projeto, const Pessoa &pessoa);
    void criarHistoriaAssociadaProjeto(HistoriaUsuario historia, const Codigo &codigoProjeto);
    void criarPlanoAssociadoProjeto(const PlanoDeSprint &plano, const Codigo &codigoProjeto);

    std::vector<Projeto> listarProjetosAssociadosPessoa(const Email &email) override;
    std::vector<HistoriaUsuario> listarHistoriasAssociadasProjeto(const Codigo &codigoProjeto) override;
    std::vector<PlanoDeSprint> listarPlanosAssociadosProjeto(const Codigo &codigoProjeto) override;

    void associarProjetoPessoa(const Codigo &codigoProjeto, const Email &emailPessoa);
    void associarHistoriaProjeto(const Codigo &codigoHistoria, const Codigo &codigoProjeto);
    void associarPlanoProjeto(const Codigo &codigoPlano, const Codigo &codigoProjeto);

    void registrarHistoria(const HistoriaUsuario &historia);
    void registrarPlano(const PlanoDeSprint &plano);
};

#endif // SERVICOPROJETO_H_INCLUDED
