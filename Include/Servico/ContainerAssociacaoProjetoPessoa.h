#ifndef CONTAINERASSOCIACAOPROJETOPESSOA_H_INCLUDED
#define CONTAINERASSOCIACAOPROJETOPESSOA_H_INCLUDED

#include<vector>
#include"../associacao/AssociacaoProjetoPessoa.h"

/**
 * @brief Estrutura de armazenamento em memória para os vínculos de equipe e governança de projetos.
 * * Implementa um contêiner responsável por persistir temporariamente as relações de alocação
 * entre os colaboradores (Pessoas) e os macroescopos (Projetos). Esta estrutura é essencial para
 * a camada de Serviço validar o controle de acesso, determinando quais usuários têm permissão para
 * atuar e visualizar quais empreendimentos antes de consultar ou atualizar o banco de dados definitivo.
 */
class ContainerAssociacaoProjetoPessoa{
    private:
      std::vector<AssociacaoProjetoPessoa> associacoes;

    public:
        /**
         * @brief Inicializa o repositório de associações de equipe em estado vazio.
         */
        ContainerAssociacaoProjetoPessoa();

        /**
         * @brief Registra a alocação de um usuário na equipe de um projeto específico.
         * * @param associacao Objeto contendo os identificadores validados do projeto e do usuário.
         */
        void inserir(const AssociacaoProjetoPessoa &associacao);

        /**
         * @brief Remove o vínculo de colaboração entre um usuário e um projeto.
         * * Ação tipicamente acionada quando um membro da equipe é removido do escopo do projeto
         * ou quando o próprio projeto é encerrado/excluído.
         * * @param codigoProjeto Identificador único do projeto.
         * @param emailPessoa Identificador único do usuário a ser desvinculado da equipe.
         */
        void remover(const Codigo &codigoProjeto, const Email &emailPessoa);

        /**
         * @brief Recupera a totalidade dos vínculos de equipe ativos no contêiner.
         * * @return std::vector<AssociacaoProjetoPessoa> Estrutura vetorial contendo todas as associações de colaboradores a projetos.
         */
        std::vector<AssociacaoProjetoPessoa> listar() const;

        /**
         * @brief Verifica se um usuário específico já faz parte da equipe de um projeto.
         * * Utilizado pelas controladoras de serviço para validar regras de negócio, como
         * impedir a duplicação na alocação de membros ou checar permissões de edição.
         * * @param codigoProjeto Identificador único do projeto.
         * @param emailPessoa Identificador único do usuário.
         * @return true Caso o colaborador já esteja vinculado a este projeto.
         * @return false Caso a associação de equipe não exista no contêiner em memória.
         */
        bool existe(const Codigo &codigoProjeto,const Email &emailPessoa) const;
};

#endif // CONTAINERASSOCIACAOPROJETOPESSOA_H_INCLUDED
