#include "estados.h"

/**
 * @brief Estado::Estado, inicializa o estado
 * @param nome, nome do estado
 * Pré-condição: nenhuma
 * Pós-condição: estado inicializado
 */
Estado::Estado(string *nome)
{
    this->transicao = new map<char, Estado*>();
    this->nome = nome;
}

/**
 * @brief Estado::getNome
 * @return nome do estado
 * Pré-condição: nenhuma
 * Pós-condição: nenhuma
 */
string *Estado::getNome()
{
    return nome;
}

/**
 * @brief Estado::getTransicao
 * @return a transicao
 * Pré-condição: nenhuma
 * Pós-condição: nenhuma
 */
map<char, Estado *> *Estado::getTransicao() const
{
    return transicao;
}

/**
 * @brief Estado::adicionarTransicao
 * @param simbolo
 * @param destino
 * @return false se a transicao já existe, true caso contrário
 * Pré-condição: nenhuma
 * Pós-condição: transicao adicionada caso ela ainda nao exista
 */
bool Estado::adicionarTransicao(char simbolo, Estado *destino)
{
    // verificar se o símbolo existe e a transição ainda não chegou ao fim
    if(transicao->find(simbolo) != transicao->end()){

        cerr << "Ja existe uma transicao com este simbolo " << simbolo << endl;
        return false;
    }

    // caso o simbolo nao existir: adicionar no vetor de transição
    this->transicao->insert(pair<char, Estado*>(simbolo, destino));
    return true;
}

/**
 * @brief Estado::fazerTransicao
 * @param simbolo
 * @return posição do simbolo no vetor transição
 */
Estado *Estado::fazerTransicao(char simbolo)
{
    if(this->transicao->find(simbolo) != this->transicao->end()){

        return this->transicao->at(simbolo);
    }
    return NULL;
}

