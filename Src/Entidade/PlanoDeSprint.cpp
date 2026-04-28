#include"entidade/PlanoDeSprint.h"

void PlanoDeSprint::setCodigo(Codigo codigo){
    this->codigo = codigo;
}

Codigo PlanoDeSprint::getCodigo() const{
    return codigo;
}

void PlanoDeSprint::setNome(Nome nome){
    this->nome = nome;
}

Nome PlanoDeSprint::getNome() const{
    return nome;
}

void PlanoDeSprint::setDataInicio(Data dataInicio){
    this->dataInicio = dataInicio;
}

Data PlanoDeSprint::getDataInicio() const{
    return dataInicio;
}

void PlanoDeSprint::setDataTermino(Data dataTermino){
    this->dataTermino = dataTermino;
}

Data PlanoDeSprint::getDataTermino() const{
    return dataTermino;
}

void PlanoDeSprint::setCapacidade(Tempo capacidade){
    this->capacidade = capacidade;
}

Tempo PlanoDeSprint::getCapacidade() const{
    return capacidade;
}
