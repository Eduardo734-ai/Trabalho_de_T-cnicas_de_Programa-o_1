#ifndef ASSOCIACAOHISTORIAPLANO_H_INCLUDED
#define ASSOCIACAOHISTORIAPLANO_H_INCLUDED

#include "Dominio/Codigo.h"

/**
 * @brief Classe de associação que vincula uma História de Usuário a um Plano de Sprint.
 *
 * Atua como uma entidade associativa no modelo orientado a objetos, representando
 * a alocação de um requisito em um ciclo de execução específico. É essencial para
 * gerenciar o escopo de uma iteração (sprint backlog) e permitir o cálculo da
 * capacidade de esforço exigida pelas regras de negócio.
 */
class AssociacaoHistoriaPlano {
private:
    Codigo codigoHistoria; ///< Objeto de domínio que representa o identificador único da história de usuário.
    Codigo codigoPlano;    ///< Objeto de domínio que representa o identificador único do plano de sprint.

public:
    /**
     * @brief Define o identificador da tarefa que está sendo alocada no sprint.
     * @param codigoHistoria Objeto da classe de domínio Codigo representando a história de usuário.
     */
    void setCodigoHistoria(const Codigo& codigoHistoria);

    /**
     * @brief Recupera o identificador da tarefa associada neste vínculo.
     * @return Codigo Objeto de domínio contendo a chave da história de usuário.
     */
    Codigo getCodigoHistoria() const;

    /**
     * @brief Define o identificador do ciclo de execução (sprint) de destino.
     * @param codigoPlano Objeto da classe de domínio Codigo representando o plano de sprint.
     */
    void setCodigoPlano(const Codigo& codigoPlano);

    /**
     * @brief Recupera o identificador do plano de sprint associado neste vínculo.
     * @return Codigo Objeto de domínio contendo a chave do ciclo de execução.
     */
    Codigo getCodigoPlano() const;
};

#endif // ASSOCIACAOHISTORIAPLANO_H_INCLUDED
