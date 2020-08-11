#include "hashing.h"

int main(void){

    //TabelaHash T;
    //TipoRegistro r;



    /*inicializaTabelaHash(T);
    r = obterRegistro(365, "Gabriel Horst Montoanelli");
    inserir(T, 365, r);

    r = obterRegistro(365, "Iraci Horst");
    inserir(T, 365, r);

    r = obterRegistro(365, "Carla Horst");
    inserir(T, 365, r);
    show(T);

    printf("Posicao: %d\n\n\n", buscar(T, 165));
    printf("-----------------------------\n");

    //remover(T, 475);
    //show(T);*/
    int i;
    for(i = 31; i <= 35; i++){
        printf("H(%d) = %d\n", i, hash_Multiplicacao(i));
    }

    printf("-----------------------------\n");

    for(i = 0; i < TAM*2; i++){
        printf("H(%d) = %d\n", i, hash(i));
    }
    return 0;
}

