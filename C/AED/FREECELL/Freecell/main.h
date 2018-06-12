#ifndef CARTAS_H
#define CARTAS_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


#include "start.h"
#include "comandos.h"
#include "pilhas.h"

#define MAX 100

//printa o estado da mesa atual
/**
 * @brief mostrar_mesa
 * @param mesa
 * @return nenhum
 * @pre condicao nenhum
 * @pos condicao nenhum
 */
void mostrar_mesa(Mesa* mesa);

//printa a carta
/**
 * @brief mostrar_carta
 * @param carta
 * @return nenhum
 * @pre condicao nenhum
 * @pos condicao nenhum
 */
void mostrar_carta(Carta* carta);

//printa as celulas
/**
 * @brief mostrar_celulas
 * @param mesa
 * @return nenhum
 * @pre condicao nenhum
 * @pos condicao nenhum
 */
void mostrar_celulas(Mesa* mesa);

//printa as fundacoes
/**
 * @brief mostrar_fundacao
 * @param mesa
 * @return nenhum
 * @pre condicao nenhum
 * @pos condicao nenhum
 */
void mostrar_fundacao(Mesa* mesa);

//printa as referencias
/**
 * @brief mostrar_marcas
 * @param nenhum
 * @return nenhum
 * @pre condicao nenhum
 * @pos condicao nenhum
 */
void mostrar_marcas();

#endif // CARTAS_H

