#ifndef CONTAINERPROJETOS_H_INCLUDED
#define CONTAINERPROJETOS_H_INCLUDED

#include<vector>
#include"entidade/Projeto.h"
#include"dominio/Codigo.h"

/**
 * @brief Estrutura de armazenamento em memória para os macroescopos do sistema (Projetos).
 * * Implementa um contêiner responsável por gerenciar a persistência temporária dos
 * projetos de desenvolvimento na camada de Serviço. Atua como um repositório local que
 * facilita operações rápidas de consulta e validação estrutural (como checagem de
 * duplicidade de códigos) antes da consolidação definitiva no banco de dados real.
 */
class ContainerProjetos{
    private:
        std::vector<Projeto> projetos;

    public:
        /**
         * @brief Inicializa o repositório de projetos em estado vazio.
         */
        ContainerProjetos();

        /**
         * @brief Registra um novo macroescopo de desenvolvimento no armazenamento em memória.
         * * @param projeto Objeto da entidade Projeto preenchido com os dados estruturais a serem armazenados.
         */
        void inserir(const Projeto &projeto);

        /**
         * @brief Recupera os dados completos de um projeto específico armazenado no contêiner.
         * * @param codigo Identificador único do macroescopo a ser localizado.
         * @return Projeto Retorna a entidade populada com as informações recuperadas da memória.
         * @throw std::invalid_argument Lança exceção caso o código fornecido não corresponda a nenhum projeto no contêiner.
         */
        Projeto buscar(const Codigo &codigo) const;

        /**
         * @brief Remove permanentemente um projeto do repositório em memória.
         * * @param codigo Identificador único do macroescopo a ser excluído do cache.
         */
        void remover(const Codigo &codigo);

        /**
         * @brief Recupera a totalidade dos projetos ativos registrados no contêiner.
         * * @return std::vector<Projeto> Estrutura vetorial contendo todos os macroescopos atualmente armazenados na memória.
         */
        std::vector<Projeto> listar() const;
};

#endif // CONTAINERPROJETOS_H_INCLUDED
