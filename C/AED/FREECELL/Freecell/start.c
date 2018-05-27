#include "start.h"

Mesa* Criar_Mesa(){
    Mesa* nova_mesa = (Mesa*)malloc(sizeof(Mesa));
    int i;

    nova_mesa->celula_livre = 4;
    nova_mesa->qnt_pilha_livre = 8;

    for(i = 0; i < 4; i++){
        nova_mesa->pilhas[i] = criar_pilha();
        nova_mesa->pilhas[i+4] = criar_pilha();
        nova_mesa->fundacoes[i] = criar_pilha();
        nova_mesa->celulas[i] = NULL;
    }
    return nova_mesa;
}

Carta* Criar_Carta(int naipe, int valor){
    Carta* nova_carta = (Carta*)malloc(sizeof(Carta));

    nova_carta->naipe = naipe;
    nova_carta->valor = valor;

    return nova_carta;
}

void Criar_Baralho(Carta* cartas[]){
    int naipe, valor;

    for(naipe = 0; naipe < 3; naipe++){
        for(valor = 0; valor < 12; valor++){
            cartas[naipe*13 + valor] = Criar_Carta(naipe, valor);
        }
    }
}

void iniciar_jogo(Mesa* mesa){
    Carta* cartas[52];
    int i;

    Criar_Baralho(cartas);
    Embaralhar(cartas);

    for(i = 0; i < 52; i++){
        mesa->pilhas[i%8] = insere_carta(mesa->pilhas[i%8], cartas[i]);
    }
    mesa->qnt_pilha_livre = 0;
}

void Embaralhar(Carta* cartas[]){
    Carta* aux = NULL;
    int i, ind;

    for(i = 0; i < 52; i++){
        ind = rand() % 52;
        aux = cartas[i];
        cartas[i] = cartas[ind];
        cartas[ind] = aux;
    }
}

