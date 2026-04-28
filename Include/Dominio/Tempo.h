#ifndef TEMPO_H_INCLUDED
#define TEMPO_H_INCLUDED

class Tempo{
    private:
        int valor;
        void validar(int valor);
    public:
        void setValor(int valor);
        int getValor() const;
};

#endif // TEMPO_H_INCLUDED
