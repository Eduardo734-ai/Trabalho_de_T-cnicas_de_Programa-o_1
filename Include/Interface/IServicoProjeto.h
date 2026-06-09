#ifndef ISERVICOPROJETO_H_INCLUDED
#define ISERVICOPROJETO_H_INCLUDED

#include<vector>

#include"entidade/Projeto.h"
#include"entidade/HistoriaUsuario.h"
#include"entidade/PlanoDeSprint.h"

#include"dominio/Codigo.h"
#include"dominio/Email.h"

using namespace std;

/**
 * @brief Contrato de delegação de lógica de negócio para a gestão e governança de Projetos.
 *
 * Declara a interface abstrata que define as operações de ciclo de vida do macroescopo
 * corporativo do sistema. Estabelece o ponto de ancoragem para o backlog global (Histórias de Usuário)
 * e para os ciclos temporais de entrega (Planos de Sprint), mediando o vínculo relacional
 * com os usuários cadastrados sem expor as estratégias de persistência em banco de dados.
 */
class IServicoProjeto{
    public:
        /**
         * @brief Registra um novo macroescopo de desenvolvimento no sistema.
         *
         * @param projeto Objeto da entidade Projeto contendo dados estruturais e cronograma validados.
         * @throw std::runtime_error Lança exceção caso ocorra duplicidade de código ou falhas operacionais na persistência.
         */
        virtual void criar(const Projeto &projeto) = 0;

        /**
         * @brief Recupera as especificações cronológicas e de identificação de um empreendimento.
         *
         * @param codigo Identificador único do projeto a ser localizado.
         * @return Projeto Retorna a entidade populada com as informações resgatadas do banco de dados.
         * @throw std::invalid_argument Lança exceção caso o identificador não corresponda a nenhum registro ativo.
         */
        virtual Projeto ler(const Codigo &codigo) = 0;

        /**
         * @brief Modifica as propriedades estruturais e limites de vigência de um escopo ativo.
         *
         * @param projeto Objeto contendo o identificador original do projeto e os novos parâmetros de cronograma ou designação.
         * @throw std::invalid_argument Lança exceção caso o projeto informado não seja encontrado para atualização.
         */
        virtual void atualizar(const Projeto &projeto) = 0;

        /**
         * @brief Remove definitivamente um macroescopo de desenvolvimento do ecossistema do sistema.
         *
         * A execução desta rotina deve tratar em cascata a desvinculação ou a remoção lógica
         * dos planos de sprint e requisitos contidos no escopo deste projeto, mantendo a integridade referencial.
         *
         * @param codigo Identificador único do projeto a ser removido.
         * @throw std::invalid_argument Lança exceção caso o código não seja localizado na base de dados.
         */
        virtual void excluir(const Codigo &codigo) = 0;

        /**
         * @brief Agrupa todos os macroescopos de desenvolvimento vinculados a um usuário específico.
         *
         * @param email Objeto da classe Email que identifica o usuário no sistema.
         * @return vector<Projeto> Vetor contendo a listagem completa de projetos associados à credencial informada.
         */
        virtual vector<Projeto> listarProjetosAssociadosPessoa(const Email &email) = 0;

        /**
         * @brief Recupera o conjunto de requisitos funcionais alocados no backlog de um empreendimento.
         *
         * @param codigoProjeto Identificador único do projeto de interesse.
         * @return vector<HistoriaUsuario> Coleção vetorial de histórias de usuário que compõem o escopo do projeto.
         */
        virtual vector<HistoriaUsuario> listarHistoriasAssociadasProjeto(const Codigo &codigoProjeto) = 0;

        /**
         * @brief Lista os ciclos de execução (sprints) cronologicamente vinculados a um empreendimento.
         *
         * @param codigoProjeto Identificador único do projeto pai.
         * @return vector<PlanoDeSprint> Coleção vetorial com os planos de sprint estruturados para o projeto.
         */
        virtual vector<PlanoDeSprint> listarPlanosAssociadosProjeto(const Codigo &codigoProjeto) = 0;

        /**
         * @brief Destrutor virtual padrão.
         *
         * Assegura o encerramento seguro e a liberação de recursos das classes controladoras que implementam esta interface.
         */
        virtual ~IServicoProjeto(){}
    };

#endif // ISERVICOPROJETO_H_INCLUDED
