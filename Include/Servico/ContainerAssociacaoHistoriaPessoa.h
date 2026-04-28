#ifndef CONTAINERASSOCIACAOHISTORIAPESSOA_H_INCLUDED
#define CONTAINERASSOCIACAOHISTORIAPESSOA_H_INCLUDED

#include<vector>
#include"../associacao/AssociacaoHistoriaPessoa.h"

class ContainerAssociacaoHistoriaPessoa{
    private:
        std::vector<AssociacaoHistoriaPessoa> associacoes;
    public:
        ContainerAssociacaoHistoriaPessoa();

        void inserir(const AssociacaoHistoriaPessoa &associacao);
        void remover(const Codigo &codigoHistoria, const Email &emailPessoa);
        std::vector<AssociacaoHistoriaPessoa> listar() const;
        bool existe(const Codigo &codigoHistoria, const Email &emailPessoa) const;
};

#endif // CONTAINERASSOCIACAOHISTORIAPESSOA_H_INCLUDED
