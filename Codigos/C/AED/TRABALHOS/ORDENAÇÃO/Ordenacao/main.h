#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "sort.h"
#include "clocksort.h"

typedef struct arg {
    //tipo de comando
    char tipo[1];
    //tamanho do vetor
    int qnt;
    //tipo de ordenacao
    char ordem[20];
    //arquivo de entrada
    char input[50];
    //arquuivo de saida
    char output[50];
}Arg;

/**
 * @brief inicializar
 * @param cmd
 * @return struct zerada
 * @pre nenhuma
 * @post nenhuma
 */
Arg inicializar(Arg cmd);

/**
 * @brief isN
 * @param tipo
 * @return 1 se for N e 0 caso ocntrario
 * @pre nenhuma
 * @post nenhuma
 */
int isN (char *tipo);


/**
 * @brief isC
 * @param tipo
 * @return 1 se for C e 0 caso ocntrario
 * @pre nenhuma
 * @post nenhuma
 */
int isC (char *tipo);


/**
 * @brief cmdMain
 * @param argv
 * @param cmd
 * @pre nenhuma
 * @post struct preenchida
 */
void cmdMain(char const *argv[], Arg *cmd);


/**
 * @brief cmdOrdenacao
 * @param vet
 * @param v
 * @param tam
 * @param cmd
 * @pre nenhuma
 * @post nenhuma
 */
void cmdOrdenacao(int **vet, char **v, int *tam, Arg cmd);


/**
 * @brief lerEntrada
 * @param tam
 * @param input
 * @return matriz preenchida
 * @pre nenhuma
 * @post nenhuma
 */
char** lerEntrada(int *tam, char* input);


/**
 * @brief Rand
 * @param vet
 * @param tam
 * @pre nenhuma
 * @post vetor preenchido com valores aleatorios
 */
void Rand(int **vet, int tam);


/**
 * @brief escreveSaidaInt
 * @param vet
 * @param tam
 * @param output
 * @pre nenhuma
 * @post vetor escrito no arquivo
 */
void escreveSaidaInt(int *vet, int tam, char* output);


/**
 * @brief escreverSaidaChar
 * @param v
 * @param tam
 * @param output
 * @pre nenhuma
 * @post vetor escrito no arquivo
 */
void escreverSaidaChar(char **v, int tam, char* output);

#endif // MAIN_H

