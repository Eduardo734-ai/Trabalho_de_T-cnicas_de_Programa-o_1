#include"associacao/AssociacaoProjetoPessoa.h"

void AssociacaoProjetoPessoa::setCodigoProjeto(Codigo codigoProjeto){
    this->codigoProjeto = codigoProjeto;
}

Codigo AssociacaoProjetoPessoa::getCodigoProjeto() const{
    return codigoProjeto;
}

void AssociacaoProjetoPessoa::setEmailPessoa(Email emailPessoa){
    this->emailPessoa = emailPessoa;
}

Email AssociacaoProjetoPessoa::getEmailPessoa() const{
    return emailPessoa;
}
