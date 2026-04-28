#include"associacao/AssociacaoHistoriaPessoa.h"

void AssociacaoHistoriaPessoa::setCodigoHistoria(Codigo codigoHistoria){
    this->codigoHistoria = codigoHistoria;
}

Codigo AssociacaoHistoriaPessoa::getCodigoHistoria() const{
    return codigoHistoria;
}

void AssociacaoHistoriaPessoa::setEmailPessoa(Email emailPessoa){
    this->emailPessoa = emailPessoa;
}

Email AssociacaoHistoriaPessoa::getEmailPessoa() const{
    return emailPessoa;
}
