#include "../../include/servico/UtilData.h"
#include <stdexcept>

using namespace std;

int UtilData::obterDia(const Data &data) {
    string valor;

    valor = data.getValor();

    return (valor[0] - '0') * 10 + (valor[1] - '0');
}

int UtilData::obterMes(const Data &data) {
    string valor;

    valor = data.getValor();

    return (valor[3] - '0') * 10 + (valor[4] - '0');
}

int UtilData::obterAno(const Data &data) {
    string valor;

    valor = data.getValor();

    return (valor[6] - '0') * 1000 +
           (valor[7] - '0') * 100 +
           (valor[8] - '0') * 10 +
           (valor[9] - '0');
}

bool UtilData::anoBissexto(int ano) {
    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
        return true;
    }

    return false;
}

int UtilData::diasNoMes(int mes, int ano) {
    int diasMes[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if (mes == 2 && anoBissexto(ano)) {
        return 29;
    }

    return diasMes[mes - 1];
}

int UtilData::converterParaDias(const Data &data) {
    int dia;
    int mes;
    int ano;
    int total;
    int i;

    dia = obterDia(data);
    mes = obterMes(data);
    ano = obterAno(data);

    total = 0;

    for (i = 2000; i < ano; i++) {
        if (anoBissexto(i)) {
            total = total + 366;
        }
        else {
            total = total + 365;
        }
    }

    for (i = 1; i < mes; i++) {
        total = total + diasNoMes(i, ano);
    }

    total = total + dia;

    return total;
}

int UtilData::calcularDiferencaDias(const Data &inicio, const Data &termino) {
    int diasInicio;
    int diasTermino;
    int diferenca;

    diasInicio = converterParaDias(inicio);
    diasTermino = converterParaDias(termino);

    diferenca = diasTermino - diasInicio;

    if (diferenca < 0) {
        throw invalid_argument("Data de termino anterior a data de inicio.");
    }

    return diferenca;
}
