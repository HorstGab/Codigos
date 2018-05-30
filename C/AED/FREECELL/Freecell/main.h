#ifndef CARTAS_H
#define CARTAS_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


#include "start.h"
#include "comandos.h"
#include "pilhas.h"

#define MAX 100

void mostrar_mesa(Mesa* mesa);

void mostrar_carta(Carta* carta);

void mostrar_celulas(Mesa* mesa);

void mostrar_fundacao(Mesa* mesa);

void mostrar_marcas();

#endif // CARTAS_H

