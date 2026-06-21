#ifndef PROJETO_H_INCLUDED
#define PROJETO_H_INCLUDED

#include "Dominio/Codigo.h"
#include "Dominio/Nome.h"
#include "Dominio/Data.h"

/**
 * @brief Iniciativa de alto nível que agrupa e organiza o esforço de desenvolvimento.
 *
 * Centraliza as informações primárias de um empreendimento no sistema, estabelecendo
 * a sua identificação, designação e os limites temporais do seu cronograma (início e término).
 * Como regra de negócio, o intervalo de dias entre as datas de início e término desta entidade
 * atua como um teto, limitando a soma máxima das capacidades de todos os planos de sprint associados a ele.
 */
class Projeto {
private:
    Codigo codigo;       ///< Objeto de domínio que representa o identificador único do projeto.
    Nome nome;           ///< Objeto de domínio que representa o título ou designação textual do projeto.
    Data dataInicio;     ///< Objeto de domínio que representa o marco temporal de início das atividades.
    Data dataTermino;    ///< Objeto de domínio que representa o marco temporal de encerramento das atividades.

public:
    /**
     * @brief Atribui o identificador único do projeto.
     * @param codigo Objeto da classe Codigo contendo o identificador validado.
     */
    void setCodigo(const Codigo& codigo);

    /**
     * @brief Recupera o identificador único do projeto.
     * @return Codigo Retorna o objeto identificador atual.
     */
    Codigo getCodigo() const;

    /**
     * @brief Atribui o título ou designação do empreendimento.
     * @param nome Objeto da classe Nome contendo a identificação textual validada.
     */
    void setNome(const Nome& nome);

    /**
     * @brief Recupera o título ou designação do empreendimento.
     * @return Nome Retorna o objeto de designação atual.
     */
    Nome getNome() const;

    /**
     * @brief Atribui o marco temporal que define o começo das atividades.
     * @param dataInicio Objeto da classe Data contendo o dia, mês e ano validados.
     */
    void setDataInicio(const Data& dataInicio);

    /**
     * @brief Recupera o marco temporal de começo das atividades.
     * @return Data Retorna o objeto de data inicial atual.
     */
    Data getDataInicio() const;

    /**
     * @brief Atribui o marco temporal que define o encerramento das atividades.
     * @param dataTermino Objeto da classe Data contendo o dia, mês e ano validados.
     */
    void setDataTermino(const Data& dataTermino);

    /**
     * @brief Recupera o marco temporal de encerramento das atividades.
     * @return Data Retorna o objeto de data final atual.
     */
    Data getDataTermino() const;
};

#endif // PROJETO_H_INCLUDED
