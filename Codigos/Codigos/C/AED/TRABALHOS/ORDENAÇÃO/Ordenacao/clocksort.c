#include "clocksort.h"

/**
 * @brief clockNumerico
 * @param vet
 * @param tam
 * @pre vetor de inteiros preenchido
 * @pre nenhuma
 */
void clockNumerico(int *vet, int tam)
{
    clock_t tempo;
    //aloca o vetor de copia
    int *vetCpy = (int*)malloc(sizeof(int)*tam);

    printf("Comparacao de tempo de cada Algoritmo de Sort!\n\n");

    //copia o vetor original no vetor de copia
    copyVet(vetCpy, vet, tam);
    //pega o clock inicial
    tempo = clock();
        //chama o sort
        InsertionSort(vetCpy, tam);
    //calcula o clock
    printf("InsertionSort: %g segundos \n", ((float)clock()-tempo)/CLOCKS_PER_SEC);

    //copia o vetor original no vetor de copia
    copyVet(vetCpy, vet, tam);
    //pega o clock inicial
    tempo = clock();
        //chama o sort
        SelectionSort(vet, tam);
    //calcula o clock
    printf("SelectionSort: %g segundos \n", ((float)clock()-tempo)/CLOCKS_PER_SEC);

    //copia o vetor original no vetor de copia
    copyVet(vetCpy, vet, tam);
    //pega o clock inicial
    tempo = clock();
        //chama o sort
        MergeSort(vet,0,tam);
    //calcula o clock
    printf("MergeSort: %g segundos \n", ((float)clock()-tempo)/CLOCKS_PER_SEC);

    //copia o vetor original no vetor de copia
    copyVet(vetCpy, vet, tam);
    //pega o clock inicial
    tempo = clock();
        //chama o sort
        HeapSort(vet-1, tam);
    //calcula o clock
    printf("HeapSort: %g segundos \n", ((float)clock()-tempo)/CLOCKS_PER_SEC);

    //copia o vetor original no vetor de copia
    copyVet(vetCpy, vet, tam);
    //pega o clock inicial
    tempo = clock();
        //chama o sort
        QuickSort(vet,0,tam-1);
    //calcula o clock
    printf("QuickSort: %g segundos \n", ((float)clock()-tempo)/CLOCKS_PER_SEC);

    //libera o vetor de copia
    free(vetCpy);
}


/**
 * @brief clockChar
 * @param v
 * @param tam
 * @pre vetor de strings preenchido
 * @pre nenhuma
 */
void clockChar(char **v, int tam)
{
    clock_t tempo;
    //aloca o vetor de copia
    char **vetCpy = (char**)malloc(sizeof(char*)*tam);


    printf("Comparacao de tempo de cada Algoritmo de Sort!\n\n");

    //copia o vetor original no vetor de copia
    copyVetChar(vetCpy, v, tam);
    //pega o clock inicial
    tempo = clock();
        //chama o sort
        InsertionSortChar(v, tam);
    //calcula o clock
    printf("InsertionSort: %g segundos \n", ((float)clock()-tempo)/CLOCKS_PER_SEC);

    //copia o vetor original no vetor de copia
    copyVetChar(vetCpy, v, tam);
    //pega o clock inicial
    tempo = clock();
        //chama o sort
        SelectionSortChar(v, tam);
    //calcula o clock
    printf("SelectionSort: %g segundos \n", ((float)clock()-tempo)/CLOCKS_PER_SEC);

    //copia o vetor original no vetor de copia
    copyVetChar(vetCpy, v, tam);
    //pega o clock inicial
    tempo = clock();
        //chama o sort
        MergeSortChar(v,0,tam);
    //calcula o clock
    printf("MergeSort: %g segundos \n", ((float)clock()-tempo)/CLOCKS_PER_SEC);

    //copia o vetor original no vetor de copia
    copyVetChar(vetCpy, v, tam);
    //pega o clock inicial
    tempo = clock();
        //chama o sort
        HeapSortChar(v-1, tam);
    //calcula o clock
    printf("HeapSort: %g segundos \n", ((float)clock()-tempo)/CLOCKS_PER_SEC);

    //copia o vetor original no vetor de copia
    copyVetChar(vetCpy, v, tam);
    //pega o clock inicial
    tempo = clock();
        //chama o sort
        QuickSortChar(v,0,tam-1);
    //calcula o clock
    printf("QuickSort: %g segundos \n", ((float)clock()-tempo)/CLOCKS_PER_SEC);

    //libera o vetor de copia
    free(vetCpy);
}


/**
 * @brief copyVet
 * @param vetCpy
 * @param vet
 * @param tam
 * @pre nenhuma
 * @pre feita uma copia do vetor original de inteiros
 */
void copyVet(int *vetCpy, int *vet, int tam){
    int i;

    //percorre o vetor copiando o vetor original no vetor copia
    for(i = 0; i < tam; i++){
        vetCpy[i] = vet[i];
    }
}


/**
 * @brief copyVetChar
 * @param vetCpy
 * @param v
 * @param tam
 * @pre nenhuma
 * @pre feita uma copia do vetor original de strings
 */
void copyVetChar(char **vetCpy, char **v, int tam){
    int i;

    //percorre o vetor copiando o vetor original no vetor copia
    for(i = 0; i < tam; i++){
        vetCpy[i] = v[i];
    }
}


/**
 * @brief sortNumerico
 * @param vet
 * @param tam
 * @param ordem
 * @pre nenhuma
 * @post chama o sort  de inteiro respectivo
 */
void sortNumerico(int *vet, int tam, char *ordem)
{
    //compara a string com o nome do sort e chama a respectiva funcao
    if(!strcmp(ordem, "insertionsort")) InsertionSort(vet, tam);
    if(!strcmp(ordem, "selectionsort")) SelectionSort(vet, tam);
    if(!strcmp(ordem, "quicksort")) QuickSort(vet,0,tam-1);
    if(!strcmp(ordem, "mergesort")) MergeSort(vet,0,tam);
    if(!strcmp(ordem, "heapsort")) HeapSort(vet-1, tam);
}


/**
 * @brief sortChar
 * @param v
 * @param tam
 * @param ordem
 * @pre nenhuma
 * @post chama o sort de strings respectivo
 */
void sortChar(char **v, int tam, char *ordem)
{
    //compara a string com o nome do sort e chama a respectiva funcao
    if(!strcmp(ordem, "insertionsort")) InsertionSortChar(v, tam);
    if(!strcmp(ordem, "selectionsort")) SelectionSortChar(v, tam);
    if(!strcmp(ordem, "quicksort")) QuickSortChar(v,0,tam-1);
    if(!strcmp(ordem, "mergesort")) MergeSortChar(v,0,tam);
    if(!strcmp(ordem, "heapsort")) HeapSortChar(v-1, tam);
}
