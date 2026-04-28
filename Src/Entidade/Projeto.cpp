#include"entidade/Projeto.h"

void Projeto::setCodigo(Codigo codigo){
    this->codigo = codigo;
}

Codigo Projeto::getCodigo() const{
    return codigo;
}

void Projeto::setNome(Nome nome){
    this->nome = nome;
}

Nome Projeto::getNome() const{
    return nome;
}

void Projeto::setDataInicio(Data dataInicio){
    this->dataInicio = dataInicio;
}

Data Projeto::getDataInicio() const{
    return dataInicio;
}

void Projeto::setDataTermino(Data dataTermino){
    this->dataTermino = dataTermino;
}

Data Projeto::getDataTermino() const{
    return dataTermino;
}
