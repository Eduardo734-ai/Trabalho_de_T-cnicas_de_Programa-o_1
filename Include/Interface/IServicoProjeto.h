#ifndef ISERVICOPROJETO_H_INCLUDED
#define ISERVICOPROJETO_H_INCLUDED

#include<vector>

#include"entidade/Projeto.h"
#include"entidade/HistoriaUsuario.h"
#include"entidade/PlanoDeSprint.h"

#include"dominio/Codigo.h"
#include"dominio/Email.h"

using namespace std;

class IServicoProjeto{
    public:
        virtual void criar(const Projeto &projeto) = 0;
        virtual Projeto ler(const Codigo &codigo) = 0;
        virtual void atualizar(const Projeto &projeto) = 0;
        virtual void excluir(const Codigo &codigo) = 0;

        virtual vector<Projeto> listarProjetosAssociadosPessoa(const Email &email) = 0;
        virtual vector<HistoriaUsuario> listarHistoriasAssociadasProjeto(const Codigo &codigoProjeto) = 0;
        virtual vector<PlanoDeSprint> listarPlanosAssociadosProjeto(const Codigo &codigoProjeto) = 0;

        virtual ~IServicoProjeto(){}
};

#endif // ISERVICOPROJETO_H_INCLUDED
