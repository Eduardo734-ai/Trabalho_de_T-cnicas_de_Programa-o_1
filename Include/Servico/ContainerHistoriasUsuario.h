#ifndef CONTAINERHISTORIASUSUARIO_H_INCLUDED
#define CONTAINERHISTORIASUSUARIO_H_INCLUDED

#include<vector>
#include"entidade/HistoriaUsuario.h"
#include"Dominio/Codigo.h"

class ContainerHistoriasUsuario {
private:
    std::vector<HistoriaUsuario> historias;

public:
    ContainerHistoriasUsuario();

    void inserir(const HistoriaUsuario &historia);
    HistoriaUsuario buscar(const Codigo &codigo) const;
    void remover(const Codigo &codigo);
    std::vector<HistoriaUsuario> listar() const;
};
#endif // CONTAINERHISTORIASUSUARIO_H_INCLUDED
