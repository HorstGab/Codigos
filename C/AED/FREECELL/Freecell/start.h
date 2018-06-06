#ifndef START
#define START

#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pilhas.h"

//cria a mesa
/**
 * @brief Criar_Mesa
 * @return
 */
Mesa* Criar_Mesa();

//cria cada carta do baralho
/**
 * @brief Criar_Carta
 * @param naipe
 * @param valor
 * @return
 */
Carta* Criar_Carta(int naipe, int valor);

//cria o vetor com todas as cartas
/**
 * @brief Criar_Baralho
 * @param cartas
 */
void Criar_Baralho(Carta* cartas[]);

//chama as funcões que inicializa o jogo
/**
 * @brief iniciar_jogo
 * @param mesa
 */
void iniciar_jogo(Mesa* mesa);

//embaralha as cartas de posicões dentro do vetor
/**
 * @brief Embaralhar
 * @param cartas
 */
void Embaralhar(Carta* cartas[]);

#endif // START

