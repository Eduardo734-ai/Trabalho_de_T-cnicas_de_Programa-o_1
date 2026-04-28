#ifndef CONTROLADORASISTEMA_H_INCLUDED
#define CONTROLADORASISTEMA_H_INCLUDED

#include "../servico/ServicoAutenticacao.h"
#include "../servico/ServicoPessoa.h"
#include "../servico/ServicoProjeto.h"
#include "../servico/ServicoPlanoDeSprint.h"
#include "../servico/ServicoHistoriaUsuario.h"

class ControladoraSistema {
private:
    ServicoAutenticacao servicoAutenticacao;
    ServicoPessoa servicoPessoa;
    ServicoProjeto servicoProjeto;
    ServicoPlanoDeSprint servicoPlano;
    ServicoHistoriaUsuario servicoHistoria;

    void menuInicial();
    void menuPrincipal();
    void menuPessoa();
    void menuProjeto();
    void menuPlano();
    void menuHistoria();
    void menuAssociacoes();

    void executarCadastro();
    void executarLogin();
    void executarLogout();

    void controlarPessoa();
    void controlarProjeto();
    void controlarPlano();
    void controlarHistoria();
    void controlarAssociacoes();

    void criarPessoa();
    void lerPessoa();
    void atualizarPessoa();
    void excluirPessoa();

    void criarProjeto();
    void lerProjeto();
    void atualizarProjeto();
    void excluirProjeto();

    void criarPlano();
    void lerPlano();
    void atualizarPlano();
    void excluirPlano();

    void criarHistoria();
    void lerHistoria();
    void atualizarHistoria();
    void excluirHistoria();

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
    void executar();
};

#endif // CONTROLADORASISTEMA_H_INCLUDED
