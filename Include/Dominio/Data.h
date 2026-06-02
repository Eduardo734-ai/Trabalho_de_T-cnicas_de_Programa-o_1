#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED

#include<string>

using namespace std;

/**
 * @brief Classe de domínio que representa o valor de uma indicação precisa de um momento no calendário (dia, mês, ano).
 *
 * Esta classe é responsável por armazenar e validar o formato de uma data no sistema.
 * De acordo com as regras de negócio, uma data válida deve seguir o formato DIA/MÊS/ANO,
 * onde o dia é um número de 1 a 31, o mês é um número de 01 a 12, e o ano está entre 2000 e 2999.
 * A validação também deve garantir que a data seja válida considerando anos bissextos.
 */
class Data{
    private:
        string valor;
        void validar(string valor);
        bool anoBissexto(int ano) const;

    public:
        /**
         * @brief Define o valor da data.
         *
         * Recebe uma string e a submete à validação de formato e de regras de calendário.
         *
         * @param valor String contendo a data a ser definida no formato estipulado.
         * @throw std::invalid_argument Lança uma exceção caso a string fornecida não atenda ao formato válido ou represente uma data inexistente no calendário.
         */
        void setValor(string valor);

        /**
         * @brief Recupera o valor atual da data.
         *
         * @return string Retorna a data armazenada.
         */
        string getValor() const;

};

#endif // DATA_H_INCLUDED
