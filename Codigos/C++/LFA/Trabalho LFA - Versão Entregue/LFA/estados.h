#ifndef ESTADOS_H
#define ESTADOS_H

#include<map>
#include<iostream>
#include<string.h>

using namespace std;

class Estado
{
private:

    string *nome;
    map<char, Estado*> *transicao;

public:

    /**
     * @brief Estado::Estado, inicializa o estado
     * @param nome, nome do estado
     * Pré-condição: nenhuma
     * Pós-condição: estado inicializado
     */
    Estado(string *nome);

    /**
     * @brief Estado::getNome, pega o nome do estado
     * @return nome do estado
     * Pré-condição: nenhuma
     * Pós-condição: nome do estado retornado
     */
    string *getNome();

    /**
     * @brief Estado::adicionarTransicao, adiciona simbolo de estado e os estados que este leva
     * @param simbolo
     * @param destino
     * @return false se a transicao já existe, true caso contrário
     * Pré-condição: nenhuma
     * Pós-condição: transicao adicionada caso ela ainda nao exista
     */
    bool adicionarTransicao(char simbolo, Estado *destino);

    /**
     * @brief Estado::getTransicao
     * @return a transicao
     * Pré-condição: nenhuma
     * Pós-condição: transição retornada
     */
    map<char, Estado *> *getTransicao() const;

    /**
     * @brief fazerTransicao
     * @param simbolo
     * @return posição do simbolo no vetor transição
     * Pré-condição: nenhuma
     * Pós-condição: posição do simbolo na transição retornada
     */
    Estado *fazerTransicao(char simbolo);

    /**
     * @brief Destrutor da classe
     * Pré-condição: nenhuma
     * Pós-condição: classe destruida
     */
    ~Estado();
};

#endif // ESTADOS_H
