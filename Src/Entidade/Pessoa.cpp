#include"Entidade/Pessoa.h"

void Pessoa::setEmail(Email email){
    this->email = email;
}

Email Pessoa::getEmail() const{
    return email;
}

void Pessoa::setNome(Nome nome){
    this->nome = nome;
}

Nome Pessoa::getNome() const{
    return nome;
}

void Pessoa::setSenha(Senha senha){
    this->senha = senha;
}

Senha Pessoa::getSenha() const{
    return senha;
}

void Pessoa::setPapel(Papel papel){
    this->papel = papel;
}

Papel Pessoa::getPapel() const{
    return papel;
}
