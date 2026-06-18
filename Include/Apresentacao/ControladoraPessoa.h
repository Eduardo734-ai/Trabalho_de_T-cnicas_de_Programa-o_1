#ifndef CONTROLADORAPESSOA_H_INCLUDED
#define CONTROLADORAPESSOA_H_INCLUDED

#include "../Servico/ServicoPessoa.h"

class ControladoraPessoa {
private:
    ServicoPessoa* servicoPessoa;

    void menuPessoa();

    void criarPessoa();
    void lerPessoa();
    void atualizarPessoa();
    void excluirPessoa();

public:
    ControladoraPessoa(ServicoPessoa* servicoPessoa);

    void executar();
};

#endif // CONTROLADORAPESSOA_H_INCLUDED
