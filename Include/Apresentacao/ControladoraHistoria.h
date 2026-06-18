#ifndef CONTROLADORAHISTORIA_H_INCLUDED
#define CONTROLADORAHISTORIA_H_INCLUDED

#include "../Servico/ServicoHistoriaUsuario.h"
#include "../Servico/ServicoProjeto.h"
#include "../Servico/ServicoAutenticacao.h"

class ControladoraHistoria {
private:
    ServicoHistoriaUsuario* servicoHistoria;
    ServicoProjeto* servicoProjeto;
    ServicoAutenticacao* servicoAutenticacao;

    void menuHistoria();

    void criarHistoria();
    void lerHistoria();
    void atualizarHistoria();
    void excluirHistoria();

public:
    ControladoraHistoria(
        ServicoHistoriaUsuario* servicoHistoria,
        ServicoProjeto* servicoProjeto,
        ServicoAutenticacao* servicoAutenticacao
    );

    void executar();
};

#endif // CONTROLADORAHISTORIA_H_INCLUDED
