#ifndef SERVICOHISTORIAUSUARIO_H_INCLUDED
#define SERVICOHISTORIAUSUARIO_H_INCLUDED

#include<vector>

#include"../interface/IServicoHistoriaUsuario.h"

#include"ContainerHistoriasUsuario.h"
#include"ContainerPlanosDeSprint.h"
#include"ContainerAssociacaoHistoriaPessoa.h"
#include"ContainerAssociacaoHistoriaPlano.h"


class ServicoHistoriaUsuario : public IServicoHistoriaUsuario{
    private:
        ContainerHistoriasUsuario container;
        ContainerPlanosDeSprint containerPlanos;

        ContainerAssociacaoHistoriaPessoa associacoesHistoriaPessoa;
        ContainerAssociacaoHistoriaPlano associacoesHistoriaPlano;
    public:
        ServicoHistoriaUsuario();

        void criar(const HistoriaUsuario &historia)override;
        HistoriaUsuario ler(const Codigo &codigo)override;
        void atualizar(const HistoriaUsuario &historia)override;
        void excluir(const Codigo &codigo)override;

        void associarPessoa(const Codigo &codigoHistoria,const Email &emailPessoa)override;
        void removerAssociacaoPessoa(const Codigo &codigoHistoria, const Email &emailPessoa)override;
        std::vector<HistoriaUsuario> listarHistoriasAssociadasPessoa(const Email &emailPessoa)override;

        void moverParaSprint(const Codigo &codigoHistoria, const Codigo &codigoProjeto,const Codigo &codigoPlano)override;
        void alterarEstado(const Codigo &codigoHistoria,const Estado &estado)override;

        void registrarPlano(const PlanoDeSprint &plano);
        std::vector<HistoriaUsuario> listarHistoriasAssociadasPlano(const Codigo &codigoPlano);

        void atualizarDadosHistoria(const Codigo &codigo,const Nome &nome,const Papel &papel,const Texto &acao,const Texto &valor,const Tempo &estimativa,const Prioridade &prioridade);

};

#endif // SERVICOHISTORIAUSUARIO_H_INCLUDED
