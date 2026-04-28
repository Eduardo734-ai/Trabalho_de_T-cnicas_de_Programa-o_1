#ifndef PESSOA_H_INCLUDED
#define PESSOA_H_INCLUDED

#include"dominio/Email.h"
#include"dominio/Nome.h"
#include"dominio/Senha.h"
#include"dominio/Papel.h"

class Pessoa{
    private:
        Email email;
        Nome nome;
        Senha senha;
        Papel papel;
    public:
        void setEmail(Email email);
        Email getEmail() const;

        void setNome(Nome nome);
        Nome getNome() const;

        void setSenha(Senha senha);
        Senha getSenha() const;

        void setPapel(Papel papel);
        Papel getPapel() const;
};

#endif // PESSOA_H_INCLUDED
