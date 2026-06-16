#include"Entidade/HistoriaUsuario.h"

void HistoriaUsuario::setCodigo(const Codigo& codigo){
    this->codigo = codigo;
}

Codigo HistoriaUsuario::getCodigo() const{
    return codigo;
}

void HistoriaUsuario::setNome(const Nome& nome){
    this->nome = nome;
}

Nome HistoriaUsuario::getNome() const{
    return nome;
}

void HistoriaUsuario::setPapel(const Papel& papel){
    this->papel = papel;
}

Papel HistoriaUsuario::getPapel() const{
    return papel;
}

void HistoriaUsuario::setAcao(const Texto& acao){
    this->acao = acao;
}

Texto HistoriaUsuario::getAcao() const{
    return acao;
}

void HistoriaUsuario::setValor(const Texto& valor){
    this->valor = valor;
}

Texto HistoriaUsuario::getValor() const{
    return valor;
}

void HistoriaUsuario::setEstimativa(const Tempo& estimativa){
    this->estimativa = estimativa;
}

Tempo HistoriaUsuario::getEstimativa() const{
    return estimativa;
}

void HistoriaUsuario::setPrioridade(const Prioridade& prioridade){
    this->prioridade = prioridade;
}

Prioridade HistoriaUsuario::getPrioridade() const{
    return prioridade;
}

void HistoriaUsuario::setEstado(const Estado& estado){
    this->estado = estado;
}

Estado HistoriaUsuario::getEstado() const{
    return estado;
}
