#include "automatos.h"

typedef map<string*, char> stringToChar;

/**
 * @brief Automatos::Automatos
 * Pré-condição: nenhuma
 * Pós-condição: Automato criado
 */
Automatos::Automatos()
{
    this->alfabeto = new vector<char>();
    this->estados = new vector<Estado*>();
    this->estadosfinais = new vector<Estado*>();
    this->estadoinicial = NULL;
}

/**
 * @brief Automatos::encontrarEstado
 * @param nome, nome do estado que se quer encontrar
 * @return posição do estado no vetor
 * Pré-condição: nenhuma
 * Pós-condição: Estado encontrado
 */
Estado *Automatos::encontrarEstado(string *nome)
{
    int tam = (int)this->estados->size();

    // loop para percorrer a lista de estado
    for(int i = 0; i < tam; i++){

        // compara cada posição do vetor com a variável nome
        if(!this->estados->at(i)->getNome()->compare(*nome))
            return this->estados->at(i);
    }
    return NULL;
}

/**
 * @brief Automatos::contemSimbolo, verifica se o símbolo está contido no vetor
 * @param simbolo
 * @return true se o vetor contém o símbolo e false caso contrário
 * Pré-condição: nenhuma
 * Pós-condição: nenhuma
 */
bool Automatos::contemSimbolo(char simbolo)
{
    // recebe o tamanho do vetor alfabeto
    int tam = this->alfabeto->size();

    // loop para percorrer o vetor de alfabeto
    for(int i = 0; i < (int)tam; i++){

        // se elemento no índice i for igual à símbolo
        if(this->alfabeto->at(i) == simbolo){

            // se o vetor contém o símbolo
            return true;
        }
    }
    return false;
}

/**
 * @brief Automatos::setInicial, set o estado passado como parametro como inicial
 * @param nome, nome do estado
 * @return false se o estado inical for nulo, e true caso contrário
 * Pré-condição: nenhuma
 * Pós-condição: existencia do estado inicial verificada
 */
bool Automatos::setInicial(string *nome)
{
    // encontrar o estado inicial através do nome passado como parâmetro
    this->estadoinicial = this->encontrarEstado(nome);

    // se o estado inicial for nulo, imprimir mensagem de erro
    if(this->estadoinicial == NULL && this->estadoinicial != 0){

        cerr << "Erro: Estado " << *nome << " nao encontrado" << endl;
        return false;
    }
    return true;
}

/**
 * @brief Automatos::setFinal
 * @param nome do estado
 * Pré-condição: nenhuma
 * Pós-condição: nenhuma
 */
void Automatos::setFinal(Estado *aux)
{
    //adiciona no final do estados final
    this->estadosfinais->push_back(aux);
}

/**
 * @brief Automatos::testaFinal, verifica se é estado final
 * @param nome, nome do estado
 * @return true se for estado final e false se não for
 * Pré-condição: nenhuma
 * Pós-condição: nenhuma
 */
bool Automatos::testaFinal(string *nome)
{
    // recebe o tamanho do vetor de estado finais
    int tam = this->estadosfinais->size();

    // loop para percorrer o vetor de estado finais
    for(int i = 0; i < tam; i++){

        if(*this->estadosfinais->at(i)->getNome() == *nome){
            return true;
        }
    }
    return false;
}

/**
 * @brief Automatos::sequenciaEstado
 * @param palavra, palavra que será testada
 * @param estado, estado que será testado
 * @return true quando chegou ao final
 * Pré-condição: nenhuma
 * Pós-condição: sequencia do estado testada
 */
int Automatos::sequenciaEstado(char *palavra, Estado *estado)
{
    char simbolo = palavra[0];

    // verifica se o estado é nulo
    if(!estado) return 0;

    cout << "[" << *estado->getNome() << "]" << palavra << endl;

    // pergunta se simbolo for igual 0, quer dizer que chegou ao final
    if(!simbolo && this->testaFinal(estado->getNome())) return true;

    // se o símbolo não existe no alfabeto
    if(!this->contemSimbolo(simbolo)) return false;

    return this->sequenciaEstado(palavra + 1, estado->fazerTransicao(simbolo));
}

/**
 * @brief Automatos::testaSequencia, testa se sequência é aceita pelo autômato
 * @param palavra, palavra que será testada
 * @return true se a sequencia foi aceita e false se não for
 * Pré-condição: existir uma função que testa a sequencia do estado
 * Pós-condição: sequencia testada
 */
bool Automatos::testaSequencia(char *palavra)
{
    // testa se sequência é aceita pelo autômato
    if(this->sequenciaEstado(palavra, this->estadoinicial)){
        cout << "ACEITA" << endl;
        return true;
    }

    cout << "REJEITA" << endl;
    return false;
}

/**
 * @brief Automatos::imprimir, imprimir gramática
 * Pré-condição: existir uma função que imprima cada linha da gramática
 * Pós-condição: gramática impressa
 */
void Automatos::imprimir()
{
    int tam, j;
    int i = 0;

    // para descrever variável não terminal
    map<string*, char> *aux = new map<string*, char>();

    // se estado inicial não existe
    if(!this->estadoinicial){
        cerr << "Estado inicial inexistente." << endl;
        return;
    }


    //vincula/insere no nome do estado inicial a letra 'S'
    aux->insert(pair<string*, char>(this->estadoinicial->getNome(), 'S'));

    //tamanho do vetor de estado
    tam = this->estados->size();

    //loop para percorrer o vetor de estados
    for(j = 0; j < tam; j++){

        // compara se cada posição do vetor é diferente do estado inicial
        if(*this->estados->at(j)->getNome() != *this->estadoinicial->getNome()){

            // vincula o primeiro estado não-terminal com 'A' e a cada iteração percorre uma letra no alfabeto
            aux->insert(pair<string*, char>(this->estados->at(j)->getNome(), 'A'+i++));
        }
    }

    // imprime cada linha do estado não-terminal
    this->imprimirLinha(aux);

    // libera a variável auxiliar
    delete aux;
}

/**
 * @brief Automatos::imprimirLinha
 * @param simbolo, símbolo que represente o não terminal
 * Pré-condição: nenhuma
 * Pós-condição: nenhuma
 */
void Automatos::imprimirLinha(stringToChar *simbolo)
{
    // variável auxiliar para representar estado de transição
    map<char, Estado*> *transicao = NULL;
    map<char, Estado*>::iterator j;
    stringToChar::iterator i;

    for(i = simbolo->begin(); i != simbolo->end(); ++i){

        string *nome = i->first;
        Estado *estado = this->encontrarEstado(nome);
        transicao = estado->getTransicao();

        cout << i->second  << "->";

        // loop que percorre um vetor de estado, que percorre o estado de transição enquanto ele não chegar ao fim
        for(j = transicao->begin(); j != transicao->end(); ){

            cout << " " << j->first << (simbolo->at(estado->fazerTransicao(j->first)->getNome())) << " ";

            // a cada iteração de j, verificar se é diferente do final do estado transição e imprimir:
            if(++j != transicao->end()){
                cout << "|";
            }
        }

        // quando chegar ao fim, imprimir:
        if(this->testaFinal(estado->getNome())) cout << "| @";

        cout << endl;
    }
}

/**
 * @brief Automatos::setAlfabeto
 * @param simbolo
 * Pré-condição: nenhuma
 * Pós-condição: simbolo do alfabeto inserido no final do vector
 */
void Automatos::setAlfabeto(char *simbolo){
    //simbolo inserido no final do vetor
    this->alfabeto->push_back(*simbolo);
}

/**
 * @brief Automatos::setEstado
 * @param nome
 * Pré-condição: nenhuma
 * Pós-condição: nome do estado inserido no final do vetor
 */
void Automatos::setEstado(string *nome){
    //estado inserido no final do vetor
    this->estados->push_back(new Estado(nome));
}
