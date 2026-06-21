#ifndef ASSOCIACAOPLANOPROJETO_H_INCLUDED
#define ASSOCIACAOPLANOPROJETO_H_INCLUDED

#include "Dominio/Codigo.h"

/**
 * @brief Classe de associação que vincula um Plano de Sprint a um Projeto.
 *
 * Atua como uma entidade associativa no modelo orientado a objetos, estabelecendo
 * a relação hierárquica de contenção onde um macroescopo (Projeto) possui múltiplos
 * ciclos de execução (Sprints). É fundamental para garantir a integridade estrutural
 * e a organização cronológica do sistema.
 */
class AssociacaoPlanoProjeto {
private:
    Codigo codigoPlano;   ///< Objeto de domínio que representa o identificador único do plano de sprint.
    Codigo codigoProjeto; ///< Objeto de domínio que representa o identificador único do projeto pai.

public:
    /**
     * @brief Define o identificador do ciclo de execução (sprint) a ser vinculado.
     * @param codigoPlano Objeto da classe de domínio Codigo representando o plano de sprint.
     */
    void setCodigoPlano(const Codigo& codigoPlano);

    /**
     * @brief Recupera o identificador do plano de sprint associado neste vínculo.
     * @return Codigo Objeto de domínio contendo a chave do ciclo de execução.
     */
    Codigo getCodigoPlano() const;

    /**
     * @brief Define o identificador do projeto (macroescopo) pai.
     * @param codigoProjeto Objeto da classe de domínio Codigo representando o projeto detentor do sprint.
     */
    void setCodigoProjeto(const Codigo& codigoProjeto);

    /**
     * @brief Recupera o identificador do projeto hierarquicamente superior neste vínculo.
     * @return Codigo Objeto de domínio contendo a chave do macroescopo.
     */
    Codigo getCodigoProjeto() const;
};

#endif // ASSOCIACAOPLANOPROJETO_H_INCLUDED
