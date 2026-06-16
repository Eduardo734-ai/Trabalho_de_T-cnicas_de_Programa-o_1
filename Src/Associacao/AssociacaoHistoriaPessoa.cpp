#include"Associacao/AssociacaoHistoriaPessoa.h"

void AssociacaoHistoriaPessoa::setCodigoHistoria(const Codigo& codigoHistoria){
    this->codigoHistoria = codigoHistoria;
}

Codigo AssociacaoHistoriaPessoa::getCodigoHistoria() const{
    return codigoHistoria;
}

void AssociacaoHistoriaPessoa::setEmailPessoa(const Email& emailPessoa){
    this->emailPessoa = emailPessoa;
}

Email AssociacaoHistoriaPessoa::getEmailPessoa() const{
    return emailPessoa;
}
