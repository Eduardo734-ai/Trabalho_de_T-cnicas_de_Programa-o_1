#ifndef ESTADO_H_INCLUDED
#define ESTADO_H_INCLUDED

#include<string>

using namespace std;

class Estado{
    private:
        string valor;
        void validar(string valor);
    public:
        void setValor(string valor);
        string getValor() const;
};

#endif
