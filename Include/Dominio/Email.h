#ifndef EMAIL_H_INCLUDED
#define EMAIL_H_INCLUDED

#include<string>

using namespace std;

class Email{
    private:
        string valor;
        void validar(string valor);
        void validarParteLocal(string parteLocal);
        void validarDominio(string dominio);
    public:
        void setValor(string valor);
        string getValor() const;
};

#endif // EMAIL_H_INCLUDED
