#ifndef UTILDATA_H_INCLUDED
#define UTILDATA_H_INCLUDED

#include"../dominio/Data.h"

/**
 * @brief Classe utilitária para manipulação e cálculo de intervalos temporais.
 * * Implementa um conjunto de métodos estáticos responsáveis por realizar operações
 * matemáticas sobre objetos da classe de domínio Data. Como é uma classe utilitária (stateless),
 * não necessita ser instanciada para que suas funções sejam utilizadas pelas camadas de Serviço ou Apresentação.
 */
class UtilData{
    private:
        /**
         * @brief Extrai o valor numérico do dia de um objeto Data.
         * * @param data Objeto Data validado.
         * @return int Valor inteiro correspondente ao dia.
         */
        static int obterDia(const Data &data);

        /**
         * @brief Extrai o valor numérico do mês de um objeto Data.
         * * @param data Objeto Data validado.
         * @return int Valor inteiro correspondente ao mês.
         */
        static int obterMes(const Data &data);

        /**
         * @brief Extrai o valor numérico do ano de um objeto Data.
         * * @param data Objeto Data validado.
         * @return int Valor inteiro correspondente ao ano.
         */
        static int obterAno(const Data &data);

        /**
         * @brief Verifica se um determinado ano é bissexto.
         * * Aplica as regras matemáticas do calendário gregoriano para validação de anos bissextos,
         * impactando diretamente o cálculo de dias no mês de fevereiro.
         * * @param ano Valor inteiro representando o ano.
         * @return true Caso o ano seja bissexto.
         * @return false Caso o ano não seja bissexto.
         */
        static bool anoBissexto(int ano);

        /**
         * @brief Determina a quantidade máxima de dias em um mês específico de um dado ano.
         * * Considera as variações e regras de calendário, incluindo anos bissextos.
         * * @param mes Valor numérico do mês (1 a 12).
         * @param ano Valor numérico do ano.
         * @return int Quantidade de dias daquele mês.
         */
        static int diasNoMes(int mes,int ano);

        /**
         * @brief Converte uma data estruturada para um número absoluto de dias transcorridos.
         * * Facilita operações matemáticas complexas, convertendo uma estrutura de calendário
         * (dia/mês/ano) em uma base linear comum para realizar subtrações ou adições.
         * * @param data Objeto Data a ser convertido.
         * @return int Total numérico de dias absolutos.
         */
        static int converterParaDias(const Data &data);

    public:
        /**
         * @brief Calcula a diferença absoluta em dias entre dois marcos temporais.
         * * Utilizado amplamente pelo sistema para validações de regras de negócio que envolvem prazos,
         * como calcular a duração total de um Plano de Sprint ou a vigência de um Projeto.
         * * @param inicio Objeto Data representando a data inicial (limite inferior).
         * @param termino Objeto Data representando a data final (limite superior).
         * @return int Diferença algébrica quantificada em dias entre o início e o término.
         */
        static int calcularDiferencaDias(const Data &inicio,const Data &termino);
};

#endif // UTILDATA_H_INCLUDED
