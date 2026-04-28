#ifndef PLANODESPRINT_H_INCLUDED
#define PLANODESPRINT_H_INCLUDED

#include"dominio/Codigo.h"
#include"dominio/Nome.h"
#include"dominio/Data.h"
#include"dominio/Tempo.h"

class PlanoDeSprint{
    private:
        Codigo codigo;
        Nome nome;
        Data dataInicio;
        Data dataTermino;
        Tempo capacidade;
    public:
        void setCodigo(Codigo codigo);
        Codigo getCodigo() const;

        void setNome(Nome nome);
        Nome getNome() const;

        void setDataInicio(Data dataInicio);
        Data getDataInicio() const;

        void setDataTermino(Data dataTermino);
        Data getDataTermino() const;


        void setCapacidade(Tempo capacidade);
        Tempo getCapacidade() const;
};

#endif // PLANODESPRINT_H_INCLUDED
