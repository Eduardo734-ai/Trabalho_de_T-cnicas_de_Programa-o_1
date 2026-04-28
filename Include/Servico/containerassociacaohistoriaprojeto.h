#ifndef CONTAINERASSOCIACAOHISTORIAPROJETO_H_INCLUDED
#define CONTAINERASSOCIACAOHISTORIAPROJETO_H_INCLUDED

#include<vector>
#include"../associacao/AssociacaoHistoriaProjeto.h"

class ContainerAssociacaoHistoriaProjeto{
    private:
        std::vector<AssociacaoHistoriaProjeto> associacoes;
    public:
        ContainerAssociacaoHistoriaProjeto();

        void inserir(const AssociacaoHistoriaProjeto &associacao);
        void remover(const Codigo &codigoHistoria, const Codigo &codigoProjeto);
        std::vector<AssociacaoHistoriaProjeto> listar() const;
        bool existe(const Codigo &codigoHistoria, const Codigo &codigoProjeto) const;
};

#endif // CONTAINERASSOCIACAOHISTORIAPROJETO_H_INCLUDED
