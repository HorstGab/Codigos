#ifndef PILHAS_H
#define PILHAS_H

#include "main.h"

//cria uma pilha vazia
Pilha* criar_pilha();

//insere as cartas na mesa
Pilha* insere_carta(Pilha* pilha, Carta* carta);

// cria um novo no
No* criar_no(Carta* carta);

//remove um elemento da pilha
No *pop(Pilha *pilha);


#endif // PILHAS_H

