#ifndef HISTORIAUSUARIO_H_INCLUDED
#define HISTORIAUSUARIO_H_INCLUDED

#include"Dominio/Codigo.h"
#include"Dominio/Nome.h"
#include"Dominio/Papel.h"
#include"Dominio/Texto.h"
#include"Dominio/Tempo.h"
#include"Dominio/Prioridade.h"
#include"Dominio/Estado.h"

/**
 * @brief Requisito funcional do sistema descrito sob a perspectiva de quem o utilizará no fluxo Scrum.
 *
 * Centraliza as informações de uma funcionalidade desejada, estruturando as regras de negócio ao
 * responder quem precisa (papel), o que precisa ser feito (ação) e o motivo (valor). Além da especificação,
 * esta entidade agrega os metadados de acompanhamento da tarefa, como seu identificador, esforço estimado,
 * relevância no escopo e atual fase de desenvolvimento.
 */
class HistoriaUsuario{
    private:
        Codigo codigo;
        Nome nome; // Atua como o título da história de usuário
        Papel papel;
        Texto valor;
        Texto acao;
        Tempo estimativa;
        Prioridade prioridade;
        Estado estado;

    public:
        /**
         * @brief Atribui o identificador único da história.
         *
         * @param codigo Objeto da classe Codigo contendo o identificador previamente validado.
         */
        void setCodigo(const Codigo& codigo);

        /**
         * @brief Recupera o identificador único da história.
         *
         * @return Codigo Retorna o objeto identificador atual.
         */
        Codigo getCodigo() const;

        /**
         * @brief Atribui o título descritivo da história.
         *
         * @param nome Objeto da classe Nome contendo a designação validada.
         */
        void setNome(const Nome& nome);

        /**
         * @brief Recupera o título descritivo da história.
         *
         * @return Nome Retorna o objeto de designação atual.
         */
        Nome getNome() const;

        /**
         * @brief Atribui a função de quem necessita da funcionalidade.
         *
         * @param papel Objeto da classe Papel contendo a função de atuação validada (o "quem").
         */
        void setPapel(const Papel& papel);

        /**
         * @brief Recupera a função do solicitante.
         *
         * @return Papel Retorna o objeto de atuação atual.
         */
        Papel getPapel() const;

        /**
         * @brief Atribui a funcionalidade ou atividade desejada.
         *
         * @param acao Objeto da classe Texto contendo a descrição da ação validada (o "o que").
         */
        void setAcao(const Texto& acao);

        /**
         * @brief Recupera a funcionalidade ou atividade desejada.
         *
         * @return Texto Retorna o objeto de ação atual.
         */
        Texto getAcao() const;

        /**
         * @brief Atribui o benefício de negócio esperado com a conclusão da história.
         *
         * @param valor Objeto da classe Texto contendo a justificativa validada (o "por que").
         */
        void setValor(const Texto& valor);

        /**
         * @brief Recupera o benefício de negócio esperado.
         *
         * @return Texto Retorna o objeto de justificativa atual.
         */
        Texto getValor() const;

        /**
         * @brief Atribui a quantificação de esforço ou duração esperada.
         *
         * @param estimativa Objeto da classe Tempo contendo a medida de esforço validada.
         */
        void setEstimativa(const Tempo& estimativa);

        /**
         * @brief Recupera a quantificação de esforço ou duração esperada.
         *
         * @return Tempo Retorna o objeto de esforço atual.
         */
        Tempo getEstimativa() const;

        /**
         * @brief Atribui o nível de urgência para a execução.
         *
         * @param prioridade Objeto da classe Prioridade contendo o grau de importância validado.
         */
        void setPrioridade(const Prioridade& prioridade);

        /**
         * @brief Recupera o nível de urgência para a execução.
         *
         * @return Prioridade Retorna o objeto de importância atual.
         */
        Prioridade getPrioridade() const;

        /**
         * @brief Atribui a situação de progresso atual da funcionalidade.
         *
         * @param estado Objeto da classe Estado contendo a fase de desenvolvimento validada.
         */
        void setEstado(const Estado& estado);

        /**
         * @brief Recupera a situação de progresso atual.
         *
         * @return Estado Retorna o objeto de fase de desenvolvimento atual.
         */
        Estado getEstado() const;
};

#endif // HISTORIAUSUARIO_H_INCLUDED
