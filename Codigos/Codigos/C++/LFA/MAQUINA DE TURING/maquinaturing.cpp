#include "maquinaturing.h"

#include<string.h>

maquinaTuring::maquinaTuring()
{
	this->estados = new vector<Estado*>();
	this->alfabeto = new vector<char>();
	this->estadoInicial = NULL;
}

Estado *maquinaTuring::adicionarEstado(string *nome)
{
	// Testa se o estado ja exite no automato
	if(this->encontrarEstado(nome) != NULL){
		cerr << "Erro: Estado " << *nome << " ja existe no automato." << endl;
	}

	// caso nao exista, criar novo estado e inserir no final
	this->estados->push_back(new Estado(nome));

	return this->encontrarEstado(nome);
}

Estado *maquinaTuring::encontrarEstado(string *nome)
{
	int tam = (int)this->estados->size();

	// loop para percorrer a lista de estado
	for(int i = 0; i < tam; i++){

		// compara cada posicao do vetor com a variavel nome
		if(!this->estados->at(i)->getNome()->compare(*nome))
			return this->estados->at(i);
	}
	return NULL;
}

void maquinaTuring::setEstadoInicial()
{
	string str = string("q0");
	this->estadoInicial = this->encontrarEstado(&str);
}

/**
 * @brief adicionarSimbolo, adiciona o simbolo no vetor de alfabeto
 * @param simbolo
 * Pre-condiao: nenhuma
 * Pos-condicao: O simbolo adicionado
 */
void maquinaTuring::adicionarSimbolo(char simbolo)
{
	// se o simbolo ja existe
	if(this->contemSimbolo(simbolo)){

		cerr << "Simbolo " << simbolo << " ja existente." << endl;
	}

	// se o simbolo nao existe, adicionar no final do vector
	this->alfabeto->push_back(simbolo);
}

/**
 * @brief maquinaTuring::novoSimbolo, adiciona novo Simbolo no Alfbeto
 * @param simbolo, simbolo a ser adicionado
 */
void maquinaTuring::novoSimbolo(char simbolo){
	if(!this->contemSimbolo(simbolo)){
		this->alfabeto->push_back(simbolo);
	} else {
		cerr << "Simbolo " << simbolo << " ja existente." << endl;
	}
}

/**
 * @brief contemSimbolo, verifica se o si�mbolo esta contido no vetor
 * @param simbolo, simbolo a ser comparado
 * @return true se o vetor contem o simbolo e false caso contrario
 * Pre-condicao: nenhuma
 * Pos-condicao: nenhuma
 */
bool maquinaTuring::contemSimbolo(char simbolo)
{
	// recebe o tamanho do vetor alfabeto
	int tam = this->alfabeto->size();

	// loop para percorrer o vetor de alfabeto
	for(int i = 0; i < (int)tam; i++){

		// se elemento no índice i for igual �  símbolo
		if(this->alfabeto->at(i) == simbolo){

			// se o vetor contém o símbolo
			return true;
		}
	}
	return false;
}

void maquinaTuring::criarTransicao(string *nomeOrigem, char simboloLido, string *nomeDestino, char simboloEscrito, int direcao)
{
	Estado *origem = this->encontrarEstado(nomeOrigem);
	Estado *destino = this->encontrarEstado(nomeDestino);

	if(origem && destino && this->contemSimbolo(simboloLido) && this->contemSimbolo(simboloEscrito) && movimentoValido(direcao)){
		origem->adicionarTransicao(simboloLido, simboloEscrito, destino, direcao);
	}else{
		cout << "Nao foi possivel adicionar a transicao" << endl;
	}
}

bool maquinaTuring::movimentoValido(int direcao)
{
	return direcao == 1 || direcao == -1;
}

void maquinaTuring::testaSequencia(string *sequencia)
{
	if(this->testeSequenciaDoEstado( sequencia, 1, this->estadoInicial)){
		cout << "ACEITA" <<endl;
	} else {
		cout << "REJEITA" << endl;
	}
}

bool maquinaTuring::testeSequenciaDoEstado(string *sequencia, int posicao, Estado *estadoAtual)
{
	Transicao *transicao;
	char simbolo = 0;

	if(estadoAtual == NULL)
		return false;
	simbolo = (*sequencia)[posicao];

	cout << sequencia->substr(0, posicao) << "[" << *estadoAtual->getNome() << "]" << sequencia->substr(posicao) << endl;

	if(!this->contemSimbolo(simbolo)) return false;

	transicao = estadoAtual->getTransicao(simbolo);

	if(transicao == NULL){
		return estadoAtual->final;
	}

    (*sequencia)[posicao] = transicao->simboloEsc;
	return this->testeSequenciaDoEstado(sequencia, posicao + transicao->direcao, transicao->estado);
}


