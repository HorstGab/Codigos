#include "exercicio4.h"

int main(void){

    Lista* li = cria_lista();

    li = insere(li,1);
    li = insere(li,5);

    imprime(li);

    //li = remover(li, 1);

    //imprime(li);

    if(vazia(li)){
            printf("EH VAZIA \n");
        }else{
            printf("NAO EH VAZIA \n");
        }

    return 0;
}

