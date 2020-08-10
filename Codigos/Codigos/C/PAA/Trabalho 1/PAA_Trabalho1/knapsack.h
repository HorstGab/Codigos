#ifndef KNAPSACK
#define KNAPSACK

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


 int *valor, *peso, tamanho, valorMaximo;

//Faz busca por profundidade de todas as possibilidades possiveis
//Entrada: peso e o valor atual, os dois conjuntos de soluções,
//a quantidade de objetos e a capacidade da mochila
//Retorno: nenhum
//Pré-Condições: nenhuma
//Pós-Condições: conjunto solução de objetos escolhidos
void dfs(int pesoAtual, int valorAtual, int x[], int solucao[], int tam, int W);

//Faz as operações do problema da mochila por backtracking
//Entrada: capacidade da mochila e os dois vetores de solução
//Retorno: valor maximo
//Pré-Condições: nenhuma
//Pós-Condições: conjunto solução de objetos escolhidos
int knapSackBacktracking(int W, int x[], int solucao[]);

//Faz as operações do problema da mochila por programação dinamica
//Entrada: capacidade da mochila e o vetor de solução
//Retorno: valor maximo
//Pré-Condições: nenhuma
//Pós-Condições: conjunto solução de objetos escolhidos
int knapSackPD (int w, int x[]);

//Faz leitura de arquivo
//Faz alocação de memória nos respectivos vetores
//Entrada: nenhum
//Retorno: nenhum
//Pré-Condições: nenhuma
//Pós-Condições: dados lidos e salvos na memoria
void loadData();

//Imprime os objetos que fazem parte do conjunto solução
//Entrada: vetor solução
//Retorno: nenhum
//Pré-Condições: nenhuma
//Pós-Condições: nenhuma
void imprimirSolucao(int x[]);

//Escolha de qual tipo de algoritmo para resolução do problema utilizar
//Entrada: capacidade da mochila
//Retorno: nenhum
//Pré-Condições: nenhuma
//Pós-Condições: nenhuma
void submenu(int W);

#endif // KNAPSACK

