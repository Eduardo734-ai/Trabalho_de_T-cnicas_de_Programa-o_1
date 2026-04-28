#ifndef TEXTO_H_INCLUDED
#define TEXTO_H_INCLUDED

#include<string>

using namespace std;

class Texto{
    private:
        string valor;
        void validar(string valor);
    public:
        void setValor(string valor);
        string getValor() const;
};

#endif // TEXTO_H_INCLUDED
