#ifndef CLOCKSORT
#define CLOCKSORT
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * @brief clockNumerico
 * @param vet
 * @param tam
 * @pre vetor de inteiros preenchido
 * @post nenhuma
 */
void clockNumerico(int *vet, int tam);


/**
 * @brief clockChar
 * @param v
 * @param tam
 * @pre vetor de strings preenchido
 * @post nenhuma
 */
void clockChar(char **v, int tam);


/**
 * @brief copyVet
 * @param vetCpy
 * @param vet
 * @param tam
 * @pre nenhuma
 * @post feita uma copia do vetor original de inteiros
 */
void copyVet(int *vetCpy, int *vet, int tam);


/**
 * @brief copyVetChar
 * @param vetCpy
 * @param v
 * @param tam
 * @pre nenhuma
 * @post feita uma copia do vetor original de strings
 */
void copyVetChar(char **vetCpy, char **v, int tam);


/**
 * @brief sortNumerico
 * @param vet
 * @param tam
 * @param ordem
 * @pre nenhuma
 * @post chama o sort  de inteiro respectivo
 */
void sortNumerico (int *vet, int tam, char* ordem);


/**
 * @brief sortChar
 * @param v
 * @param tam
 * @param ordem
 * @pre nenhuma
 * @post chama o sort de strings respectivo
 */
void sortChar(char **v, int tam, char* ordem);

#endif // CLOCKSORT

