#include"dominio/Data.h"
#include<stdexcept>
#include<cctype>

using namespace std;

bool Data::anoBissexto(int ano) const{
    if((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)){
        return true;
    }
    return false;
}

void Data::validar(string valor){
    int dia;
    int mes;
    int ano;
    int diasMes[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if(valor.length() != 10){
        throw invalid_argument("Data invalida.");
    }
    if(valor[2] != '/' || valor[5] != '/'){
        throw invalid_argument("Data invalida.");
    }
    if(!isdigit((unsigned char)valor[0]) || !isdigit((unsigned char)valor[1]) || !isdigit((unsigned char)valor[3]) || !isdigit((unsigned char)valor[4]) || !isdigit((unsigned char)valor[6]) || !isdigit((unsigned char)valor[7]) || !isdigit((unsigned char)valor[8]) || !isdigit((unsigned char)valor[9])){
        throw invalid_argument("Data invalida.");
    }
    dia = (valor[0] - '0')*10+(valor[1] - '0');
    mes = (valor[3] - '0')*10+(valor[4] - '0');
    ano = (valor[6] - '0')*1000+(valor[7] - '0')*100 + (valor[8] - '0')*10+(valor[9] - '0');

    if(ano < 2000 || ano > 2999){
        throw invalid_argument("Data invalida.");
    }
    if(mes < 1 || mes > 12){
        throw invalid_argument("Data invalida.");
    }
    if(anoBissexto(ano)){
        diasMes[1] = 29;
    }
    if(dia < 1 || dia > diasMes[mes - 1]){
        throw invalid_argument("Data invalida.");
    }
}

void Data::setValor(string valor){
    validar(valor);
    this->valor = valor;
}

string Data::getValor() const{
    return valor;
}
