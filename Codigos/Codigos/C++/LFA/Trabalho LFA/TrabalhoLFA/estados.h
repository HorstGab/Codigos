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
     * @brief Estado::getNome
     * @return nome do estado
     * Pré-condição: nenhuma
     * Pós-condição: nenhuma
     */
    string *getNome();

    /**
     * @brief Estado::adicionarTransicao
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
     * Pós-condição: nenhuma
     */
    map<char, Estado *> *getTransicao() const;

    // recebe um simbolo e retorna o estado destino se a transição existe
    Estado *fazerTransicao(char simbolo);
    //

    ~Estado();
};

#endif // ESTADOS_H
