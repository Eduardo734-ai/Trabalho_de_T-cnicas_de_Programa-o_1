#ifndef ASSOCIACAOHISTORIAPROJETO_H_INCLUDED
#define ASSOCIACAOHISTORIAPROJETO_H_INCLUDED

#include "Dominio/Codigo.h"

/**
 * @brief Classe de associação que vincula uma História de Usuário a um Projeto.
 *
 * Atua como uma entidade associativa no modelo orientado a objetos, representando
 * o pertencimento de um requisito funcional ao escopo global de um projeto (Product Backlog).
 * É a estrutura base que garante que todas as tarefas, mesmo as não alocadas em sprints,
 * permaneçam rastreáveis dentro do seu respectivo macroescopo.
 */
class AssociacaoHistoriaProjeto {
private:
    Codigo codigoHistoria; ///< Objeto de domínio que representa o identificador único da história de usuário.
    Codigo codigoProjeto;  ///< Objeto de domínio que representa o identificador único do projeto pai.

public:
    /**
     * @brief Define o identificador da tarefa que está sendo vinculada ao projeto.
     * @param codigoHistoria Objeto da classe de domínio Codigo representando a história de usuário.
     */
    void setCodigoHistoria(const Codigo& codigoHistoria);

    /**
     * @brief Recupera o identificador da tarefa associada neste vínculo global.
     * @return Codigo Objeto de domínio contendo a chave da história de usuário.
     */
    Codigo getCodigoHistoria() const;

    /**
     * @brief Define o identificador do projeto (macroescopo) de destino.
     * @param codigoProjeto Objeto da classe de domínio Codigo representando o projeto pai.
     */
    void setCodigoProjeto(const Codigo& codigoProjeto);

    /**
     * @brief Recupera o identificador do projeto associado neste vínculo.
     * @return Codigo Objeto de domínio contendo a chave do macroescopo.
     */
    Codigo getCodigoProjeto() const;
};

#endif // ASSOCIACAOHISTORIAPROJETO_H_INCLUDED
