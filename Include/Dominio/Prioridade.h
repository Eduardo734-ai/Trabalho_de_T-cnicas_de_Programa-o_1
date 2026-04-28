#ifndef PRIORIDADE_H_INCLUDED
#define PRIORIDADE_H_INCLUDED

#include<string>

using namespace std;

class Prioridade{
    private:
        string valor;
        void validar(string valor);
    public:
        void setValor(string valor);
        string getValor() const;
};

#endif // PRIORIDADE_H_INCLUDED
