#ifndef SORT_H
#define SORT_H

#include "main.h"

/**
 * @brief InsertionSort
 * @param vet
 * @param n
 * @pre nenhuma
 * @post vetor ordenado
 */
void InsertionSort(int *vet, int n);


/**
 * @brief InsertionSortChar
 * @param vet, vetor que sera ordenado
 * @param tamanho, tamanho do vetor
 * @pre nenhuma
 * @post vetor ordenado
 * Modo: Baseado na ideia de colocar cada elemento na posição
 * correta em relação aos seus antecessores
 */
void InsertionSortChar(char **vet, int tamanho);


/**
 * @brief SelectionSort
 * @param vet
 * @param n
 * @pre nenhuma
 * @post vetor ordenado
 */
void SelectionSort(int *vet, int n);


/**
 * @brief SelectionSortChar
 * @param vet, vetor que sera ordenado
 * @param tamanho, tamanho do vetor
 * @pre nenhuma
 * @post vetor ordenado
 * Modo: Baseado na ideia de escolher o menor elemento do vetor,
 * depois o segundo menor, e assim por diante.
 */
void SelectionSortChar(char **vet, int tamanho);


/**
 * @brief QuickSort
 * @param vet
 * @param e
 * @param d
 * @pre nenhuma
 * @post vetor ordenado
 */
void QuickSort(int *vet, int e, int d);


/**
 * @brief QuickSortChar
 * @param vet, vetor que sera ordenado
 * @param inicio, ini­cio do vetor
 * @param fim, final do vetor
 * @pre nenhuma
 * @post vetor ordenado
 * Baseado na ideia de escolher um elemento x do vetor, denominado pivo, e separar os
 * demais em duas partes: os menores ou iguais a x e os maiores que x.
 */
void QuickSortChar(char **vet, int inicio, int fim);


/**
 * @brief MergeSort
 * @param vet
 * @param e
 * @param d
 * @pre nenhuma
 * @post vetor ordenado
 */
void MergeSort(int *vet, int e, int d);


/**
 * @brief MergeSortChar
 * @param vet, vetor que serÃ¡ ordenado
 * @param inicio, inÃ­cio do vetor
 * @param fim, final do vetor
 * @pre funcao auxiliar MergeChar();
 * @post vetor ordenado
 * Baseado na ideia de ordenar cada metade do vetor separadamente e depois fazer
 * a intercalação dos subvetores ordenados para obter o vetor totalmente ordenado.
 */
void MergeSortChar(char **vet, int inicio, int fim);


/**
 * @brief intercala
 * @param vet
 * @param e
 * @param m
 * @param d
 * @pre nenhuma
 * @post separa o vetor
 */
void intercala(int *vet,int e, int m, int d);


/**
 * @brief MergeChar
 * @param vet, vetor que sera ordenado
 * @param inicio, inicio do vetor
 * @param meio, meio do vetor
 * @param fim, final do vetor
 * @pre nenhuma
 * @post separa o vetor
 */
void MergeChar(char **vet, int inicio, int meio, int fim);


/**
 * @brief HeapSort
 * @param vet
 * @param n
 * @pre nenhuma
 * @post ordena o vetor
 */
void HeapSort(int *vet, int n);


/**
 * @brief HeapSortChar
 * @param vet, vetor a ser ordenado
 * @param tamanho, tamanho do vetor
 * @pre funcoes auxiliares inserirHeapSortChar(); e sacodeHeap();
 * @post vetor ordenado
 * Baseado na construcao de um heap e sucessivas trocas
 * com o elemento da primeira posicao
 */
void HeapSortChar(char **vet, int tamanho);


/**
 * @brief insereHeap
 * @param vet
 * @param m
 * @pre nenhuma
 * @post vetor com uma posicao trocada
 */
void insereHeap(int *vet, int m);


/**
 * @brief inserirHeapSortChar
 * @param vet, vetor a ser ordenado
 * @param tamanho, tamanho do vetor
 * @pre nenhuma
 * @post vetor com uma posicao trocada
 */
void inserirHeapSortChar(char **vet, int tamanho);


/**
 * @brief sacodeHeap
 * @param vet
 * @param m
 * @pre nenhuma
 * @post
 */
void sacodeHeap(int *vet, int m);


/**
 * @brief sacodeHeap
 * @param vet, vetor a ser ordenado
 * @param tamanho, tamanho do vetor
 * @pre nenhuma
 */
void sacodeHeapChar(char **vet, int tamanho);


/**
 * @brief troca
 * @param vet, vetor
 * @param a, variavel que vai trocar de valor com b
 * @param b, variavel que vai trocar de valor com a
 * @pre nenhuma
 * @post troca dois indices de posicao
 */
void troca(char **vet, int a, int b);


/**
 * @brief separaString
 * @param vet
 * @param inicio
 * @param fim
 * @return
 */
int separaString(char **vet, int inicio, int fim);

#endif // SORT_H

