#ifndef ASSOCIACAOPLANOPROJETO_H_INCLUDED
#define ASSOCIACAOPLANOPROJETO_H_INCLUDED

#include"dominio/Codigo.h"

class AssociacaoPlanoProjeto{
    private:
        Codigo codigoPlano;
        Codigo codigoProjeto;
    public:
        void setCodigoPlano(Codigo codigoPlano);
        Codigo getCodigoPlano() const;

        void setCodigoProjeto(Codigo codigoProjeto);
        Codigo getCodigoProjeto() const;
};

#endif // ASSOCIACAOPLANOPROJETO_H_INCLUDED
