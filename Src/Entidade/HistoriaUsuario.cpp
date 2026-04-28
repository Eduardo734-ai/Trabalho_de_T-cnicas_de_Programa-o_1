#include"entidade/HistoriaUsuario.h"

void HistoriaUsuario::setCodigo(Codigo codigo){
    this->codigo = codigo;
}

Codigo HistoriaUsuario::getCodigo() const{
    return codigo;
}

void HistoriaUsuario::setNome(Nome nome){
    this->nome = nome;
}

Nome HistoriaUsuario::getNome() const{
    return nome;
}

void HistoriaUsuario::setPapel(Papel papel){
    this->papel = papel;
}

Papel HistoriaUsuario::getPapel() const{
    return papel;
}

void HistoriaUsuario::setAcao(Texto acao){
    this->acao = acao;
}

Texto HistoriaUsuario::getAcao() const{
    return acao;
}

void HistoriaUsuario::setValor(Texto valor){
    this->valor = valor;
}

Texto HistoriaUsuario::getValor() const{
    return valor;
}

void HistoriaUsuario::setEstimativa(Tempo estimativa){
    this->estimativa = estimativa;
}

Tempo HistoriaUsuario::getEstimativa() const{
    return estimativa;
}

void HistoriaUsuario::setPrioridade(Prioridade prioridade){
    this->prioridade = prioridade;
}

Prioridade HistoriaUsuario::getPrioridade() const{
    return prioridade;
}

void HistoriaUsuario::setEstado(Estado estado){
    this->estado = estado;
}

Estado HistoriaUsuario::getEstado() const{
    return estado;
}
