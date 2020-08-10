#ifndef START
#define START

#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pilhas.h"

//cria a mesa
/**
 * @brief Criar_Mesa
 * @param nenhum
 * @return nova mesa
 * @pre-condicao nenhuma
 * @pos-condicao mesa criada
 */
Mesa* Criar_Mesa();

//cria cada carta do baralho
/**
 * @brief Criar_Carta
 * @param naipe
 * @param valor
 * @return nova carta
 * @pre-condicao nenhuma
 * @pos-condicao carta criada
 */
Carta* Criar_Carta(int naipe, int valor);

//cria o vetor com todas as cartas
/**
 * @brief Criar_Baralho
 * @param cartas
 * @return nenhuma
 * @pre-condicao nenhuma
 * @pos-condicao baralho com as 52 cartas criada
 */
void Criar_Baralho(Carta* cartas[]);

//inicializa o jogo
/**
 * @brief iniciar_jogo
 * @param mesa
 * @return nenhum
 * @pre-condicao nenhuma
 * @pos-condicao cartas inseridas na mesa
 */
void iniciar_jogo(Mesa* mesa);

//embaralha as cartas de posicões dentro do vetor
/**
 * @brief Embaralhar
 * @param cartas
 * @return nenhum
 * @pre-condicao nenhuma
 * @pos-condicao vetor de cartas embaralhado
 */
void Embaralhar(Carta* cartas[]);

#endif // START

