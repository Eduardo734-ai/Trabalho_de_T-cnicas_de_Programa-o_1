#ifndef HISTORIAUSUARIO_H_INCLUDED
#define HISTORIAUSUARIO_H_INCLUDED

#include"dominio/Codigo.h"
#include"dominio/Nome.h"
#include"dominio/Papel.h"
#include"dominio/Texto.h"
#include"dominio/Tempo.h"
#include"dominio/Prioridade.h"
#include"dominio/Estado.h"

class HistoriaUsuario{
    private:
        Codigo codigo;
        Nome nome;
        Papel papel;
        Texto valor;
        Texto acao;
        Tempo estimativa;
        Prioridade prioridade;
        Estado estado;
    public:
        void setCodigo(Codigo codigo);
        Codigo getCodigo() const;

        void setNome(Nome nome);
        Nome getNome() const;

        void setPapel(Papel papel);
        Papel getPapel() const;

        void setAcao(Texto acao);
        Texto getAcao() const;

        void setValor(Texto valor);
        Texto getValor() const;

        void setEstimativa(Tempo estimativa);
        Tempo getEstimativa() const;

        void setPrioridade(Prioridade prioridade);
        Prioridade getPrioridade() const;

        void setEstado(Estado estado);
        Estado getEstado() const;

};

#endif // HISTORIAUSUARIO_H_INCLUDED
