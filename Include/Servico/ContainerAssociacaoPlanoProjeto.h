#ifndef CONTAINERASSOCIACAOPLANOPROJETO_H_INCLUDED
#define CONTAINERASSOCIACAOPLANOPROJETO_H_INCLUDED

#include<vector>
#include"../associacao/AssociacaoPlanoProjeto.h"

class ContainerAssociacaoPlanoProjeto{
    private:
        std::vector<AssociacaoPlanoProjeto> associacoes;
    public:
        ContainerAssociacaoPlanoProjeto();

        void inserir(const AssociacaoPlanoProjeto &associacao);
        void remover(const Codigo &codigoPlano, const Codigo &codigoProjeto);
        std::vector<AssociacaoPlanoProjeto> listar() const;
        bool existe(const Codigo &codigoPlano,const Codigo &codigoProjeto) const;
};

#endif // CONTAINERASSOCIACAOPLANOPROJETO_H_INCLUDED
