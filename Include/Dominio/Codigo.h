#ifndef CODIGO_H_INCLUDED
#define CODIGO_H_INCLUDED

#include<string>

using namespace std;

class Codigo{
    private:
        string valor;
        void validar(string valor);
    public:
        void setValor(string valor);
        string getValor() const;
};

#endif
