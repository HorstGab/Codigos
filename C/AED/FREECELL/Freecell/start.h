#ifndef START
#define START

#include<stdio.h>
#include <stdlib.h>
#include "pilhas.h"

//cria a mesa
Mesa* Criar_Mesa();

//cria cada carta do baralho
Carta* Criar_Carta(int naipe, int valor);

//cria o vetor com todas as cartas
void Criar_Baralho(Carta* cartas[]);

//chama as funcões que inicializa o jogo
void iniciar_jogo(Mesa* mesa);

//embaralha as cartas de posicões dentro do vetor
void Embaralhar(Carta* cartas[]);

#endif // START

