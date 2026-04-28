#ifndef CONTAINERASSOCIACAOPROJETOPESSOA_H_INCLUDED
#define CONTAINERASSOCIACAOPROJETOPESSOA_H_INCLUDED

#include<vector>
#include"../associacao/AssociacaoProjetoPessoa.h"

class ContainerAssociacaoProjetoPessoa{
    private:
      std::vector<AssociacaoProjetoPessoa> associacoes;
    public:
        ContainerAssociacaoProjetoPessoa();

        void inserir(const AssociacaoProjetoPessoa &associacao);
        void remover(const Codigo &codigoProjeto, const Email &emailPessoa);
        std::vector<AssociacaoProjetoPessoa> listar() const;
        bool existe(const Codigo &codigoProjeto,const Email &emailPessoa) const;
};

#endif // CONTAINERASSOCIACAOPROJETOPESSOA_H_INCLUDED
