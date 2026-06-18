#ifndef CONTROLADORAPLANODESPRINT_H_INCLUDED
#define CONTROLADORAPLANODESPRINT_H_INCLUDED

#include "../Servico/ServicoPlanoDeSprint.h"
#include "../Servico/ServicoProjeto.h"
#include "../Servico/ServicoHistoriaUsuario.h"

class ControladoraPlanoDeSprint {
private:
    ServicoPlanoDeSprint* servicoPlano;
    ServicoProjeto* servicoProjeto;
    ServicoHistoriaUsuario* servicoHistoria;

    void menuPlano();

    void criarPlano();
    void lerPlano();
    void atualizarPlano();
    void excluirPlano();

public:
    ControladoraPlanoDeSprint(
        ServicoPlanoDeSprint* servicoPlano,
        ServicoProjeto* servicoProjeto,
        ServicoHistoriaUsuario* servicoHistoria
    );

    void executar();
};

#endif // CONTROLADORAPLANODESPRINT_H_INCLUDED
