#ifndef ASSOCIACAOHISTORIAPESSOA_H_INCLUDED
#define ASSOCIACAOHISTORIAPESSOA_H_INCLUDED

#include"dominio/Codigo.h"
#include"dominio/Email.h"

class AssociacaoHistoriaPessoa{
    private:
        Codigo codigoHistoria;
        Email emailPessoa;
    public:
        void setCodigoHistoria(Codigo codigoHistoria);
        Codigo getCodigoHistoria() const;

        void setEmailPessoa(Email emailPessoa);
        Email getEmailPessoa() const;
};

#endif // ASSOCIACAOHISTORIAPESSOA_H_INCLUDED
