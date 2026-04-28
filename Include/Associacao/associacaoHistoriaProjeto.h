#ifndef ASSOCIACAOHISTORIAPROJETO_H_INCLUDED
#define ASSOCIACAOHISTORIAPROJETO_H_INCLUDED

#include"dominio/Codigo.h"

class AssociacaoHistoriaProjeto{
    private:
        Codigo codigoHistoria;
        Codigo codigoProjeto;
    public:
        void setCodigoHistoria(Codigo codigoHistoria);
        Codigo getCodigoHistoria() const;

        void setCodigoProjeto(Codigo codigoProjeto);
        Codigo getCodigoProjeto() const;
};

#endif // ASSOCIACAOHISTORIAPROJETO_H_INCLUDED
