#ifndef PROJETO_H_INCLUDED
#define PROJETO_H_INCLUDED

#include"dominio/Codigo.h"
#include"dominio/Nome.h"
#include"dominio/Data.h"

class Projeto{
    private:
        Codigo codigo;
        Nome nome;
        Data dataInicio;
        Data dataTermino;
    public:
        void setCodigo(Codigo codigo);
        Codigo getCodigo() const;

        void setNome(Nome nome);
        Nome getNome() const;

        void setDataInicio(Data dataInicio);
        Data getDataInicio() const;

        void setDataTermino(Data dataTermino);
        Data getDataTermino() const;
};

#endif // PROJETO_H_INCLUDED
