#ifndef NOME_H_INCLUDED
#define NOME_H_INCLUDED

#include<string>

using namespace std;

class Nome{
    private:
        string valor;
        void validar(string valor);
    public:
        void setValor(string valor);
        string getValor() const;
};

#endif // NOME_H_INCLUDED
