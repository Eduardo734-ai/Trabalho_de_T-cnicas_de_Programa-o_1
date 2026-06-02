#ifndef CONTAINERHISTORIASUSUARIO_H_INCLUDED
#define CONTAINERHISTORIASUSUARIO_H_INCLUDED

#include<vector>
#include"entidade/HistoriaUsuario.h"
#include"Dominio/Codigo.h"

/**
 * @brief Estrutura de armazenamento em memória para os requisitos funcionais (Histórias de Usuário).
 * * Implementa um contêiner responsável por gerenciar a persistência temporária das
 * histórias de usuário na camada de Serviço. Atua como um cache ou banco de dados local,
 * permitindo operações rápidas de inserção, busca e deleção para facilitar a validação
 * de regras de negócio (como o cálculo de capacidade) antes da consolidação no banco de dados real.
 */
class ContainerHistoriasUsuario {
private:
    std::vector<HistoriaUsuario> historias;

public:
    /**
     * @brief Inicializa o repositório de histórias de usuário em estado vazio.
     */
    ContainerHistoriasUsuario();

    /**
     * @brief Registra um novo requisito funcional no armazenamento em memória.
     * * @param historia Objeto da entidade HistoriaUsuario preenchido com os dados a serem armazenados.
     */
    void inserir(const HistoriaUsuario &historia);

    /**
     * @brief Recupera os dados de uma história de usuário específica armazenada no contêiner.
     * * @param codigo Identificador único da tarefa a ser localizada.
     * @return HistoriaUsuario Retorna a entidade populada com os dados recuperados da memória.
     * @throw std::invalid_argument Lança exceção caso o código fornecido não corresponda a nenhuma história no contêiner.
     */
    HistoriaUsuario buscar(const Codigo &codigo) const;

    /**
     * @brief Remove permanentemente um requisito funcional do repositório em memória.
     * * @param codigo Identificador único da história de usuário a ser excluída do cache.
     */
    void remover(const Codigo &codigo);

    /**
     * @brief Recupera a totalidade das histórias de usuário ativas no contêiner.
     * * @return std::vector<HistoriaUsuario> Estrutura vetorial contendo todas as tarefas atualmente registradas na memória.
     */
    std::vector<HistoriaUsuario> listar() const;
};
#endif // CONTAINERHISTORIASUSUARIO_H_INCLUDED
