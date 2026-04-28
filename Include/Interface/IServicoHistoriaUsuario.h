#ifndef ISERVICOHISTORIAUSUARIO_H_INCLUDED
#define ISERVICOHISTORIAUSUARIO_H_INCLUDED

#include<vector>

#include"entidade/HistoriaUsuario.h"
#include"dominio/Codigo.h"
#include"dominio/Email.h"
#include"dominio/Estado.h"

using namespace std;

class IServicoHistoriaUsuario{
    public:
        virtual void criar(const HistoriaUsuario &historia) = 0;
        virtual HistoriaUsuario ler(const Codigo &codigo) = 0;
        virtual void atualizar(const HistoriaUsuario &historia) = 0;
        virtual void excluir(const Codigo &codigo) = 0;

        virtual void associarPessoa(const Codigo &codigoHistoria, const Email &emailPessoa) = 0;
        virtual void removerAssociacaoPessoa(const Codigo &codigoHistoria, const Email &emailPessoa) = 0;
        virtual vector<HistoriaUsuario> listarHistoriasAssociadasPessoa(const Email &emailPessoa) = 0;
        virtual void moverParaSprint(const Codigo &codigoHistoria, const Codigo &codigoProjeto,const Codigo &codigoPlano) = 0;
        virtual void alterarEstado(const Codigo &codigoHistoria, const Estado &estado) = 0;

        virtual ~IServicoHistoriaUsuario(){}
};

#endif // ISERVICOHISTORIAUSUARIO_H_INCLUDED
