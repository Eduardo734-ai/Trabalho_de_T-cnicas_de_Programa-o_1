#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED

#include<string>

using namespace std;

class Data{
    private:
        string valor;
        void validar(string valor);
        bool anoBissexto(int ano) const;
    public:
        void setValor(string valor);
        string getValor() const;

};

#endif // DATA_H_INCLUDED
