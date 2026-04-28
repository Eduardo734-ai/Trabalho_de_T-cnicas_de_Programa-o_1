#ifndef ASSOCIACAOHISTORIAPLANO_H_INCLUDED
#define ASSOCIACAOHISTORIAPLANO_H_INCLUDED

#include"dominio/Codigo.h"

class AssociacaoHistoriaPlano{
    private:
        Codigo codigoHistoria;
        Codigo codigoPlano;
    public:
        void setCodigoHistoria(Codigo codigoHistoria);
        Codigo getCodigoHistoria() const;

        void setCodigoPlano(Codigo codigoPlano);
        Codigo getCodigoPlano() const;
};

#endif // ASSOCIACAOHISTORIAPLANO_H_INCLUDED
