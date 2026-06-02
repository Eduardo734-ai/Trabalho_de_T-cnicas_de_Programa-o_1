#ifndef ISERVICOHISTORIAUSUARIO_H_INCLUDED
#define ISERVICOHISTORIAUSUARIO_H_INCLUDED

#include<vector>

#include"entidade/HistoriaUsuario.h"
#include"dominio/Codigo.h"
#include"dominio/Email.h"
#include"dominio/Estado.h"

using namespace std;

/**
 * @brief Contrato de delegação de lógica de negócio para a gestão de Histórias de Usuário.
 * * Declara a interface abstrata que a camada de Apresentação deve consumir para manipular
 * os requisitos funcionais do sistema. Esta interface garante o isolamento entre as camadas,
 * assegurando que todas as regras de negócio (como CRUD, associações e validações de capacidade)
 * sejam processadas pela camada de Serviço correspondente, sem expor a tecnologia de persistência.
 */
class IServicoHistoriaUsuario{
    public:
        /**
         * @brief Registra um novo requisito funcional no sistema.
         * * @param historia Objeto da entidade HistoriaUsuario preenchido com dados validados.
         * @throw std::runtime_error Lança exceção caso já exista uma história com o mesmo código ou ocorra falha na persistência.
         */
        virtual void criar(const HistoriaUsuario &historia) = 0;

        /**
         * @brief Recupera os dados completos de um requisito funcional.
         * * @param codigo Identificador único da história a ser buscada.
         * @return HistoriaUsuario Retorna a entidade populada com os dados recuperados.
         * @throw std::invalid_argument Lança exceção caso o código fornecido não seja encontrado no sistema.
         */
        virtual HistoriaUsuario ler(const Codigo &codigo) = 0;

        /**
         * @brief Sobrescreve as informações de um requisito já existente.
         * * @param historia Objeto contendo o código da história original e os novos dados a serem atualizados.
         * @throw std::invalid_argument Lança exceção caso a história não exista.
         */
        virtual void atualizar(const HistoriaUsuario &historia) = 0;

        /**
         * @brief Remove definitivamente um requisito funcional do sistema.
         * * A exclusão de uma história também deve tratar a remoção de seus vínculos nas tabelas de associação.
         * * @param codigo Identificador único da história a ser deletada.
         * @throw std::invalid_argument Lança exceção caso o código não seja localizado.
         */
        virtual void excluir(const Codigo &codigo) = 0;

        /**
         * @brief Estabelece um vínculo de responsabilidade entre um usuário e uma história.
         * * @param codigoHistoria Identificador da tarefa.
         * @param emailPessoa Identificador (email) do usuário que será associado.
         * @throw std::runtime_error Lança exceção caso a associação já exista ou as entidades não sejam localizadas.
         */
        virtual void associarPessoa(const Codigo &codigoHistoria, const Email &emailPessoa) = 0;

        /**
         * @brief Remove o vínculo de responsabilidade entre um usuário e uma história.
         * * @param codigoHistoria Identificador da tarefa.
         * @param emailPessoa Identificador (email) do usuário.
         * @throw std::invalid_argument Lança exceção caso o vínculo não exista.
         */
        virtual void removerAssociacaoPessoa(const Codigo &codigoHistoria, const Email &emailPessoa) = 0;

        /**
         * @brief Recupera a lista de todos os requisitos funcionais alocados a um usuário específico.
         * * @param emailPessoa Identificador único do usuário.
         * @return vector<HistoriaUsuario> Retorna uma estrutura vetorial contendo todas as histórias vinculadas àquele email.
         */
        virtual vector<HistoriaUsuario> listarHistoriasAssociadasPessoa(const Email &emailPessoa) = 0;

        /**
         * @brief Realiza a transição de uma história do backlog do projeto para um ciclo de execução (sprint).
         * * Executa a regra de negócio de exclusividade: remove o vínculo genérico da história com o projeto e estabelece
         * um novo vínculo específico com o plano de sprint informado, garantindo a restrição de que a soma das estimativas
         * de tempo não exceda a capacidade do sprint de destino.
         * * @param codigoHistoria Identificador da história a ser movida.
         * @param codigoProjeto Identificador do projeto de origem da história.
         * @param codigoPlano Identificador do plano de sprint de destino.
         * @throw std::runtime_error Lança exceção caso a capacidade do sprint seja excedida com esta inserção.
         */
        virtual void moverParaSprint(const Codigo &codigoHistoria, const Codigo &codigoProjeto,const Codigo &codigoPlano) = 0;

        /**
         * @brief Atualiza a fase de progresso de desenvolvimento da história.
         * * @param codigoHistoria Identificador da tarefa.
         * @param estado Objeto da classe Estado contendo a nova situação validada ("A FAZER", "FAZENDO", ou "FEITO").
         * @throw std::invalid_argument Lança exceção caso a história não exista.
         */
        virtual void alterarEstado(const Codigo &codigoHistoria, const Estado &estado) = 0;

        /**
         * @brief Destrutor virtual padrão.
         * * Garante a destruição correta de objetos derivados através do ponteiro da classe base.
         */
        virtual ~IServicoHistoriaUsuario(){}
};

#endif // ISERVICOHISTORIAUSUARIO_H_INCLUDED
