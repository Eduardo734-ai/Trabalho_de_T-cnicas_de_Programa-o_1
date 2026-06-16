#include"Entidade/Projeto.h"

void Projeto::setCodigo(const Codigo& codigo){
    this->codigo = codigo;
}

Codigo Projeto::getCodigo() const{
    return codigo;
}

void Projeto::setNome(const Nome& nome){
    this->nome = nome;
}

Nome Projeto::getNome() const{
    return nome;
}

void Projeto::setDataInicio(const Data& dataInicio){
    this->dataInicio = dataInicio;
}

Data Projeto::getDataInicio() const{
    return dataInicio;
}

void Projeto::setDataTermino(const Data& dataTermino){
    this->dataTermino = dataTermino;
}

Data Projeto::getDataTermino() const{
    return dataTermino;
}
