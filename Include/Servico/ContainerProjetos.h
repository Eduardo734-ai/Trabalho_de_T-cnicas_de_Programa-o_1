#ifndef CONTAINERPROJETOS_H_INCLUDED
#define CONTAINERPROJETOS_H_INCLUDED

#include<vector>
#include"entidade/Projeto.h"
#include"dominio/Codigo.h"

class ContainerProjetos{
    private:
        std::vector<Projeto> projetos;
    public:
        ContainerProjetos();

        void inserir(const Projeto &projeto);
        Projeto buscar(const Codigo &codigo) const;
        void remover(const Codigo &codigo);
        std::vector<Projeto> listar() const;
};

#endif // CONTAINERPROJETOS_H_INCLUDED
