#ifndef CONTROLADORAPROJETO_H_INCLUDED
#define CONTROLADORAPROJETO_H_INCLUDED

#include "../Servico/ServicoProjeto.h"
#include "../Servico/ServicoPessoa.h"

class ControladoraProjeto {
private:
    ServicoProjeto* servicoProjeto;
    ServicoPessoa* servicoPessoa;

    void menuProjeto();

    void criarProjeto();
    void lerProjeto();
    void atualizarProjeto();
    void excluirProjeto();

public:
    ControladoraProjeto(ServicoProjeto* servicoProjeto, ServicoPessoa* servicoPessoa);

    void executar();
};

#endif // CONTROLADORAPROJETO_H_INCLUDED
