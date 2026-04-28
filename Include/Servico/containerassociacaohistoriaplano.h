#ifndef CONTAINERASSOCIACAOHISTORIAPLANO_H_INCLUDED
#define CONTAINERASSOCIACAOHISTORIAPLANO_H_INCLUDED

#include<vector>
#include"../associacao/AssociacaoHistoriaPlano.h"

class ContainerAssociacaoHistoriaPlano{
    private:
        std::vector<AssociacaoHistoriaPlano> associacoes;
    public:
        ContainerAssociacaoHistoriaPlano();

        void inserir(const AssociacaoHistoriaPlano &associacao);
        void remover(const Codigo &codigoHistoria, const Codigo &codigoPlano);
        std::vector<AssociacaoHistoriaPlano> listar() const;
        bool existe(const Codigo &codigoHistoria, const Codigo &codigoPlano) const;
};

#endif // CONTAINERASSOCIACAOHISTORIAPLANO_H_INCLUDED
