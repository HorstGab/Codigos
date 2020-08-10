#include "exercicio3.h"

int main(){
    Lista* li = criar_lista();

    li = insere_cabeca(li,1);
    li = insere_cabeca(li,5);
    li = insere_cabeca(li,0);

    imprime(li);

    li = insere_cauda(li,3);
    li = insere_cauda(li,7);
    li = insere_cauda(li,9);

    imprime(li);

    li = remover(li,1);
    li = remover(li,9);
    li = remover(li,2);

    imprime(li);

    if(vazia(li)){
        printf("EH VAZIA \n");
    }else{
        printf("NAO EH VAZIA \n");
    }

    return 0;
}

