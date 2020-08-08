#ifndef AUTOMATOS_H
#define AUTOMATOS_H

#include<vector>
#include<string.h>
#include<iostream>
#include"estados.h"

using namespace std;

class Automatos
{
private:

    /**
     * @brief alfabeto, vetor com os simbbolos do alfabeto
     * Pré-condição: nenhuma
     * Pós-condição: Automato criado
     */
    vector<char> *alfabeto;

    /**
     * @brief estados, vetor com os simbolos dos estados
     * Pré-condição: nenhuma
     * Pós-condição: Automato criado
     */
    vector<Estado*> *estados;

    /**
     * @brief estadosfinais, vetor com os simbolos dos estados finais
     * Pré-condição: nenhuma
     * Pós-condição: Automato criado
     */
    vector<Estado*> *estadosfinais;

    /**
     * @brief estadoinicial, vetor com os simolos dos estados iniciais
     * Pré-condição: nenhuma
     * Pós-condição: Automato criado
     */
    Estado *estadoinicial;

public:

    /**
     * @brief Automatos::Automatos, inicializa o automato
     * Pré-condição: nenhuma
     * Pós-condição: Automato criado
     */
    Automatos();

    /**
     * @brief Automatos::encontrarEstado, procura o estado desejado no vetor de estados
     * @param nome, nome do estado que se quer encontrar
     * @return posição do estado no vetor
     * Pré-condição: nenhuma
     * Pós-condição: Estado encontrado
     */
    Estado *encontrarEstado(string *nome);

    /**
     * @brief Automatos::contemSimbolo, verifica se o símbolo está contido no vetor
     * @param simbolo
     * @return true se o vetor contém o símbolo e false caso contrário
     * Pré-condição: nenhuma
     * Pós-condição: nenhuma
     */
    bool contemSimbolo(char simbolo);

    /**
     * @brief Automatos::setInicial, set o estado passado como parametro como inicial
     * @param nome, nome do estado
     * @return false se o estado inical for nulo, e true caso contrário
     * Pré-condição: nenhuma
     * Pós-condição: existencia do estado inicial verificada
     */
    bool setInicial(string *nome);

    /**
     * @brief Automatos::setFinal, seta o estado final
     * @param nome, nome do estado
     * Pré-condição: nenhuma
     * Pós-condição: estado final setado
     */
    void setFinal(Estado *aux);

    /**
     * @brief Automatos::testaFinal, verifica se é estado final
     * @param nome, nome do estado
     * @return true se for estado final e false se não for
     * Pré-condição: nenhuma
     * Pós-condição: nenhuma
     */

    bool testaFinal(string *nome);

    /**
     * @brief Automatos::sequenciaEstado
     * @param palavra, palavra que será testada
     * @param estado, estado que será testado
     * @return true quando chegou ao final
     * Pré-condição: nenhuma
     * Pós-condição: sequencia do estado testada
     */
    int sequenciaEstado(char *palavra, Estado *estado);

    /**
     * @brief Automatos::testaSequencia, testa se sequência é aceita pelo autômato
     * @param palavra, palavra que será testada
     * @return true se a sequencia foi aceita e false se não for
     * Pré-condição: existir uma função que testa a sequencia do estado
     * Pós-condição: sequencia testada
     */
    bool testaSequencia(char *palavra);

    /**
     * @brief Automatos::imprimir, imprimir gramática
     * Pré-condição: existir uma função que imprima cada linha da gramática
     * Pós-condição: gramática impressa
     */
    void imprimir();

    /**
     * @brief Automatos::imprimirLinha
     * @param simbolo, símbolo que represente o não terminal
     * Pré-condição: nenhuma
     * Pós-condição: nenhuma
     */
    void imprimirLinha(map<string *, char> *naoTerminal);

    /**
     * @brief Automatos::setAlfabeto, acrescenta simbolo no alfabeto
     * @param simbolo
     * Pré-condição: nenhuma
     * Pós-condição: simbolo do alfabeto inserido no final do vector
     */
    void setAlfabeto(char *simbolo);

    /**
     * @brief Automatos::setEstado, acrescenta estado
     * @param nome
     * Pré-condição: nenhuma
     * Pós-condição: nome do estado inserido no final do vetor
     */
    void setEstado(string *nome);

    /**
     * @brief Destrutor da classe
     * Pré-condição: nenhuma
     * Pós-condição: classe destruida
     */
    ~Automatos();

};

#endif // AUTOMATOS_H
