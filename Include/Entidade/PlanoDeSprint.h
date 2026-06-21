#ifndef PLANODESPRINT_H_INCLUDED
#define PLANODESPRINT_H_INCLUDED

#include "Dominio/Codigo.h"
#include "Dominio/Nome.h"
#include "Dominio/Data.h"
#include "Dominio/Tempo.h"

/**
 * @brief Estrutura temporal que define um ciclo de execução dentro do projeto.
 *
 * Centraliza os dados de planejamento de uma iteração de trabalho (sprint),
 * estabelecendo a sua identificação, período de vigência e o limite de esforço
 * (capacidade) que a equipe pode absorver durante a sua execução no fluxo Scrum.
 */
class PlanoDeSprint {
private:
    Codigo codigo;       ///< Objeto de domínio que representa o identificador único do plano de sprint.
    Nome nome;           ///< Objeto de domínio que representa o título ou designação textual do plano.
    Data dataInicio;     ///< Objeto de domínio que representa o marco temporal de começo da iteração.
    Data dataTermino;    ///< Objeto de domínio que representa o marco temporal de encerramento da iteração.
    Tempo capacidade;    ///< Objeto de domínio que quantifica o limite de esforço absorvível pela equipe no ciclo.

public:
    /**
     * @brief Atribui o identificador único do plano de sprint.
     * @param codigo Objeto da classe Codigo contendo o identificador validado.
     */
    void setCodigo(const Codigo& codigo);

    /**
     * @brief Recupera o identificador único do plano de sprint.
     * @return Codigo Retorna o objeto identificador atual.
     */
    Codigo getCodigo() const;

    /**
     * @brief Atribui o título ou designação do plano.
     * @param nome Objeto da classe Nome contendo a identificação textual validada.
     */
    void setNome(const Nome& nome);

    /**
     * @brief Recupera o título ou designação do plano.
     * @return Nome Retorna o objeto de designação atual.
     */
    Nome getNome() const;

    /**
     * @brief Atribui o marco temporal de começo da iteração.
     * @param dataInicio Objeto da classe Data contendo o dia, mês e ano validados.
     */
    void setDataInicio(const Data& dataInicio);

    /**
     * @brief Recupera o marco temporal de começo da iteração.
     * @return Data Retorna o objeto de data inicial atual.
     */
    Data getDataInicio() const;

    /**
     * @brief Atribui o marco temporal de encerramento da iteração.
     * @param dataTermino Objeto da classe Data contendo o dia, mês e ano validados.
     */
    void setDataTermino(const Data& dataTermino);

    /**
     * @brief Recupera o marco temporal de encerramento da iteração.
     * @return Data Retorna o objeto de data final atual.
     */
    Data getDataTermino() const;

    /**
     * @brief Atribui o limite de esforço que a equipe pode absorver no ciclo.
     * * A soma das estimativas das histórias de usuário associadas não pode ultrapassar este valor.
     * * @param capacidade Objeto da classe Tempo contendo a medida quantitativa validada.
     */
    void setCapacidade(const Tempo& capacidade);

    /**
     * @brief Recupera o limite de esforço suportado no ciclo.
     * @return Tempo Retorna o objeto de capacidade atual.
     */
    Tempo getCapacidade() const;
};

#endif // PLANODESPRINT_H_INCLUDED
