#include"Entidade/PlanoDeSprint.h"

void PlanoDeSprint::setCodigo(const Codigo& codigo){
    this->codigo = codigo;
}

Codigo PlanoDeSprint::getCodigo() const{
    return codigo;
}

void PlanoDeSprint::setNome(const Nome& nome){
    this->nome = nome;
}

Nome PlanoDeSprint::getNome() const{
    return nome;
}

void PlanoDeSprint::setDataInicio(const Data& dataInicio){
    this->dataInicio = dataInicio;
}

Data PlanoDeSprint::getDataInicio() const{
    return dataInicio;
}

void PlanoDeSprint::setDataTermino(const Data& dataTermino){
    this->dataTermino = dataTermino;
}

Data PlanoDeSprint::getDataTermino() const{
    return dataTermino;
}

void PlanoDeSprint::setCapacidade(const Tempo& capacidade){
    this->capacidade = capacidade;
}

Tempo PlanoDeSprint::getCapacidade() const{
    return capacidade;
}
