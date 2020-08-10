#ifndef MULT_MATRIZES_H
#define MULT_MATRIZES_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Aloca memória para a matriz quadrática
//Entrada: ordem da matriz
//Retorno: matriz alocada
//Pré-Condições: nenhuma
//Pós-Condições: memória alocada para a matriz
int **alocaMatriz(int n);

//Desaloca memória para a matriz quadrática
//Entrada: matriz, ordem da matriz
//Retorno: matriz alocada
//Pré-Condições: nenhuma
//Pós-Condições: memória desalocada
void desalocaMatriz(int **m, int n);

//Faz leitura no arquivo e seta elementos na matriz
//Entrada: ponteiro para o arquivo, matriz, ordem da matriz
//Retorno: nenhum
//Pré-Condições: arquivo aberto, memória da matriz alocada
//Pós-Condições: matriz setada
void lerMatrizArq(FILE *f, int **m, int n);

//Multiplicação de matrizes complexidade normal
//Entrada: matriz a, matriz b, matriz c, ordem das matrizes
//Retorno: nenhum
//Pré-Condições: matrizes com números setados, menis a matriz c
//Pós-Condições: matrizes multiplicadas
void mult_matrizes(int **ma, int **mb, int **mc, int n);

//Multiplicação de matrizes com o algoritmo de Strassen
//Entrada: matriz a, matriz b, matriz c, ordem das matrizes
//Retorno: nenhum
//Pré-Condições: matrizes com números setados, menos a matriz c
//Pós-Condições: matrizes multiplicadas
void alg_Strassen(int **ma, int **mb, int **mc, int n);

//Divide a matriz em partes
//Entrada: matriz principal, matriz menor secundária
//Retorno: nenhum
//Pré-Condições: matrizes não nulos e memória alocada
//Pós-Condições: submatriz criada
void dividir(int **mPrinc, int **mSec, int inicio1, int inicio2, int size);

//Adição de matrizes
//Entrada: matrizes a serem somadas
//Retorno: nenhum
//Pré-Condições: matrizes não nulos e memória alocada
//Pós-Condições: matrizes somada
int **adicao(int **m1, int **m2, int size);

//Subtração de matrizes
//Entrada: matrizes a serem subtraídas
//Retorno: nenhum
//Pré-Condições: matrizes não nulos e memória alocada
//Pós-Condições: matrizes subtraidas
int **subtr(int **m1, int **m2, int size);

//Juntas todas as partes dividias em uma matriz
//Entrada: matriz a ser juntadas, matriz principal
//Retorno: nenhum
//Pré-Condições: matrizes não nulos e memória alocada
//Pós-Condições: submatriz juntada 
void juntar(int **m1, int **mPrinc, int inicio1, int inicio2, int size);

//Faz impressão da matriz
//Entrada: matrizes a ser impressa, ordem
//Retorno: nenhum
//Pré-Condições: matrizes existe e não nulo
//Pós-Condições: matriz impresso
void print(int **m, int n);

//Escolha de qual tipo de multiplicação utilizar
//Faz alocação de memória das matrizes
//Faz leitura de arquivo
//Entrada: nenhum
//Retorno: nenhum
//Pré-Condições: nenhuma
//Pós-Condições: resultado da matriz multiplicada
void mult();

//Escolha entre os dois tipos de programas
//Entrada: nenhum
//Retorno: nenhum
//Pré-Condições: nenhuma
//Pós-Condições: nenhuma
void escolha();

#endif