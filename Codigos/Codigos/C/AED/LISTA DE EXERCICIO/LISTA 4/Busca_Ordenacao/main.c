#include "busca_ord.h"

void randOrd(int vet[], int tam);
void randDesord(int vet[], int tam);
No *randDesordList(No* no, int tam);

void showArray(int vet[], int tam);
void showList(No* no);

No* insere(No* no, int info);
No* criarLista();

int main(void){

    srand(time(NULL));
    //int vet[16] = {1,2,3,4,5,7,9,10,10,10,10,13,15,17,20,21};
    //int vet[50];
    int tam = 50;
    No* no = criarLista();

    //randOrd(vet, tam);
    //randDesord(vet, tam);

    //showArray(vet, tam);
    //selectionSort(vet, tam, 0);

    //showArray(vet, tam);
    //printf("return = %d\n",posicao_valor(vet, tam));

    //no = insere(no, 5);
    //no = insere(no, 1);
    no = randDesordList(no, tam);
    showList(no);

    insertionSortList(no);
    printf("\n");
    showList(no);

    //selectionSortParcial(vet,tam,25);
    //showArray(vet, tam);
    return 0;
}

No* criarLista(){
    return NULL;
}

void randOrd(int vet[], int tam){
    int i, num;

    for(i = num = 0; i < tam; ++i){
        num += rand()%3;
        vet[i] = num;
    }
}

void randDesord(int vet[], int tam){
    int i, num;

    for(i = num = 0; i < tam; ++i){
        num = rand()%tam*2;
        vet[i] = num;
    }
}

No* randDesordList(No* no, int tam){
    int i, x;

    srand(time(NULL));
    for(i = 0; i < tam; ++i){
        x =  rand()%(tam*2);
        no = insere(no,x);
    }
    return no;
}

void showArray(int vet[], int tam){
    int i;

    for(i = 0; i < tam; ++i){
        printf("vet[%d] = %d\n", i, vet[i]);
    }
    printf("\n\n");
}

void showList(No* no){

    if(no != NULL){
        printf("[%d] \n", no->info);
        showList(no->prox);
    }else{
        printf("[NULO]\n");
    }

}

No* insere(No* no, int info){
    No* novo = (No*)malloc(sizeof(No));
    novo->info = info;

    //se a lista for nula
    if(no == NULL){
        //anterior e proximo apontam pra nulo
        novo->ant = NULL;
        novo->prox = NULL;
    }else{
        //senao o proximo do novo aponta pro no
        novo->prox = no;
        //o anterior do no aponta pro novo
        no->ant = novo;
        //anterior do novo aponta pra null
        novo->ant = NULL;
    }

    //retorna a proxima cabeca
    return novo;
}
