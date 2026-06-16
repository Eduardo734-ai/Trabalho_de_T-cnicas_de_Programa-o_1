#include"Associacao/AssociacaoProjetoPessoa.h"

void AssociacaoProjetoPessoa::setCodigoProjeto(const Codigo& codigoProjeto){
    this->codigoProjeto = codigoProjeto;
}

Codigo AssociacaoProjetoPessoa::getCodigoProjeto() const{
    return codigoProjeto;
}

void AssociacaoProjetoPessoa::setEmailPessoa(const Email& emailPessoa){
    this->emailPessoa = emailPessoa;
}

Email AssociacaoProjetoPessoa::getEmailPessoa() const{
    return emailPessoa;
}
