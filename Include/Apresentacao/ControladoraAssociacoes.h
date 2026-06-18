#ifndef CONTROLADORAASSOCIACOES_H_INCLUDED
#define CONTROLADORAASSOCIACOES_H_INCLUDED

#include "../Servico/ServicoAutenticacao.h"
#include "../Servico/ServicoPessoa.h"
#include "../Servico/ServicoProjeto.h"
#include "../Servico/ServicoPlanoDeSprint.h"
#include "../Servico/ServicoHistoriaUsuario.h"

class ControladoraAssociacoes {
private:
    ServicoAutenticacao* servicoAutenticacao;
    ServicoPessoa* servicoPessoa;
    ServicoProjeto* servicoProjeto;
    ServicoPlanoDeSprint* servicoPlano;
    ServicoHistoriaUsuario* servicoHistoria;

    void menuAssociacoes();

    void associarHistoriaPessoa();
    void removerAssociacaoHistoriaPessoa();
    void listarProjetosPessoa();
    void listarHistoriasProjeto();
    void listarPlanosProjeto();
    void listarHistoriasPlano();
    void listarHistoriasPessoa();
    void moverHistoriaParaSprint();
    void alterarEstadoHistoria();

public:
    ControladoraAssociacoes(
        ServicoAutenticacao* servicoAutenticacao,
        ServicoPessoa* servicoPessoa,
        ServicoProjeto* servicoProjeto,
        ServicoPlanoDeSprint* servicoPlano,
        ServicoHistoriaUsuario* servicoHistoria
    );

    void executar();
    void executarAlterarEstado();
};

#endif // CONTROLADORAASSOCIACOES_H_INCLUDED
