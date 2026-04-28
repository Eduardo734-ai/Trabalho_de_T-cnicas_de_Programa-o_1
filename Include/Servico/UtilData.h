#ifndef UTILDATA_H_INCLUDED
#define UTILDATA_H_INCLUDED

#include"../dominio/Data.h"

class UtilData{
    private:
        static int obterDia(const Data &data);
        static int obterMes(const Data &data);
        static int obterAno(const Data &data);
        static bool anoBissexto(int ano);
        static int diasNoMes(int mes,int ano);
        static int converterParaDias(const Data &data);
    public:
        static int calcularDiferencaDias(const Data &inicio,const Data &termino);
};

#endif // UTILDATA_H_INCLUDED
