#ifndef SENHA_H_INCLUDED
#define SENHA_H_INCLUDED

#include<string>

using namespace std;

class Senha{
    private:
        string valor;
        void validar(string valor);
    public:
        void setValor(string valor);
        string getValor() const;
};

#endif // SENHA_H_INCLUDED
