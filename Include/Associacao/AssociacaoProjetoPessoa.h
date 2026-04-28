#ifndef ASSOCIACAOPROJETOPESSOA_H_INCLUDED
#define ASSOCIACAOPROJETOPESSOA_H_INCLUDED

#include"dominio/Codigo.h"
#include"dominio/Email.h"

class AssociacaoProjetoPessoa{
    private:
        Codigo codigoProjeto;
        Email emailPessoa;
    public:
        void setCodigoProjeto(Codigo codigoProjeto);
        Codigo getCodigoProjeto() const;

        void setEmailPessoa(Email emailPessoa);
        Email getEmailPessoa() const;
};

#endif // ASSOCIACAOPROJETOPESSOA_H_INCLUDED
