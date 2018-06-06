#ifndef CARTAS_H
#define CARTAS_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


#include "start.h"
#include "comandos.h"
#include "pilhas.h"

#define MAX 100

/**
 * @brief mostrar_mesa
 * @param mesa
 */
void mostrar_mesa(Mesa* mesa);


/**
 * @brief mostrar_carta
 * @param carta
 */
void mostrar_carta(Carta* carta);

/**
 * @brief mostrar_celulas
 * @param mesa
 */
void mostrar_celulas(Mesa* mesa);

/**
 * @brief mostrar_fundacao
 * @param mesa
 */
void mostrar_fundacao(Mesa* mesa);

/**
 * @brief mostrar_marcas
 */
void mostrar_marcas();

#endif // CARTAS_H

