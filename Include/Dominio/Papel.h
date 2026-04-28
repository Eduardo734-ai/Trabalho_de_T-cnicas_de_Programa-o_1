#ifndef PAPEL_H_INCLUDED
#define PAPEL_H_INCLUDED

#include<string>

using namespace std;

class Papel{
    private:
        string valor;
        void validar(string valor);
    public:
        void setValor(string valor);
        string getValor() const;
};

#endif // PAPEL_H_INCLUDED
