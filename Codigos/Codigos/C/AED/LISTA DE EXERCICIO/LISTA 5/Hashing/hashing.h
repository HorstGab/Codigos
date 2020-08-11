#ifndef HASHING
#define HASHING

#include <stdio.h>
#include <math.h>

#define TAM 143 // tamanho da tabela

typedef int TipoChave;

typedef struct {
    int matricula;
    char nome[50];
} TipoRegistro;

typedef struct {
    TipoChave k; // chave
    TipoRegistro r; // registro armazenado
    int ocupado; // indica se o slot esta ocupado
} slot;

typedef slot TabelaHash[TAM];

void inicializaTabelaHash(TabelaHash T);

void inserir(TabelaHash T, TipoChave k, TipoRegistro r);

//retorna a posicao do registro de chave k na tabela hash T
// ou -1 caso a chave nao esteja presente.
int buscar(TabelaHash T, TipoChave k);

void remover(TabelaHash T, TipoChave k);

int hash(int k);

int hash2(int k);

int hash_Linear(int k, int i);

int hash_Quadratica(int k, int i);

int hash_Multiplicacao(int k);

int posicaoVazia(TabelaHash T, int index);

void show(TabelaHash T);

TipoRegistro obterRegistro(int matricula, char nome[]);

#endif // HASHING

