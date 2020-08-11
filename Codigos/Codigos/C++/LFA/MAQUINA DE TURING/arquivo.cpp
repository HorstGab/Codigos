#include "arquivo.h"

Arquivo::Arquivo(char const *str)
{
	this->arquivo = fopen(str, "r+");

	if( this->arquivo == NULL){
		cerr << "Erro na abertura do arquivo!" << endl;
	}

	this->maqT = new maquinaTuring();
}

void Arquivo::leQuantidadeEstados(FILE *arq) {
	int i, quant = 0;
	char str[64];

   fscanf(arq, "Q=%d", &quant);

	printf("quant = %d\n", quant);

   for(i = 0; i < quant; ++i) {
	   sprintf(str, "q%d", i);
	   this->maqT->adicionarEstado(new string(str));
   }
}

void Arquivo::lerEstadosFinais(FILE *arq)
{
	char estadoStr[MAX] = {0}, aux[MAX] = {0};
	int i, n;

	fscanf(arq, " F = { %[^}]} ", estadoStr);

	for(i = n = 0; i < (int)strlen(estadoStr); i += n){
		sscanf(estadoStr + i, "%[^,],", &aux);
		n = strlen(aux)+1;

		string *nomeEstado = new string(aux);
		Estado *estadoEncontrado = this->maqT->encontrarEstado(nomeEstado);

		estadoEncontrado->final = true;

		delete nomeEstado;
	}

}

void Arquivo::lerAlfabeto(FILE *arq)
{
	char strAux[MAX] = {0}, simbolo;
	int i, n;

	fscanf(arq, " alfabeto = {%[^}]} ", strAux);

	for(i = n = 0; i < (int)strlen(strAux); i += n){

		sscanf(strAux + i, "%c ,%n", &simbolo, &n);
		this->maqT->adicionarSimbolo(simbolo);
	}
}

void Arquivo::lerTransicao(FILE *arq)
{
	char estadoOrigem[MAX] = {0}, estadoDestino[MAX] = {0};
	char simboloLeitura = 0, simboloEscrita = 0, direcao = 0;

	// enquanto nao chegar no final do arquivo
	while(!feof(arq)){
		fscanf(arq, " ( %[^,], %c ) = ( %[^,], %c , %c ) ", (char*)estadoOrigem, &simboloLeitura, (char*)estadoDestino, &simboloEscrita, &direcao);

		string *nomeestadoOrigem = new string(estadoOrigem);
		string *nomeEstadoDestino = new string(estadoDestino);

		if(direcao == 'D') direcao = 1;
		if(direcao == 'E') direcao = -1;

		this->maqT->criarTransicao(nomeestadoOrigem, simboloLeitura, nomeEstadoDestino, simboloEscrita, direcao);
	}
}


maquinaTuring *Arquivo::inicializarMaquina()
{
	this->maqT = new maquinaTuring();


	this->leQuantidadeEstados(this->arquivo);


	// le os estados finais do arquivo
	this->lerEstadosFinais(this->arquivo);

	this->lerAlfabeto(this->arquivo);
	this->maqT->novoSimbolo('*');
	this->maqT->novoSimbolo('$');

	while(!feof(arquivo)){
		this->lerTransicao(this->arquivo);
	}

	this->maqT->setEstadoInicial();

	return this->maqT;
}
