#ifndef CONTAINERPLANOSDESPRINT_H_INCLUDED
#define CONTAINERPLANOSDESPRINT_H_INCLUDED

#include<vector>
#include<entidade/PlanoDeSprint.h>
#include<dominio/Codigo.h>

class ContainerPlanosDeSprint{
    private:
        std::vector<PlanoDeSprint> planos;
    public:
        ContainerPlanosDeSprint();

        void inserir(const PlanoDeSprint &plano);
        PlanoDeSprint buscar(const Codigo &codigo) const;
        void remover(const Codigo &codigo);
        std::vector<PlanoDeSprint> listar() const;
};

#endif // CONTAINERPLANOSDESPRINT_H_INCLUDED
