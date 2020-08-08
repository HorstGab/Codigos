#include"exercicio1.h"

typedef struct no{
    int info;
    struct no* prox;
}Lista;

Lista* cria_lista(){
    return NULL;
}

int vazia(Lista* l){
    return (l == NULL);
}

Lista* insere(Lista *l, int info){
    Lista* novo = (Lista*) malloc(sizeof(Lista));

        novo->info = info;
        novo->prox = l;

    return novo;
}

Lista* impares(Lista *l){
    Lista* l_impar = cria_lista();
    while(!vazia(l)){
         if(l->info%2 != 0){
           l_impar = insere(l_impar, l->info);
          }
             l = l->prox;
   }
   return l_impar;
}

/*Lista* remove_intervalo(Lista *l, int a, int b){
    Lista* ptr = l;
    if(!vazia(l)){
        if(l->info >= a || l->info <= b){
            ptr = l->prox;
            free(l);
        }
        l = remove_intervalo(l->prox, a, b);
    }
    return l;
}*/

int maximo(Lista* l){
    int max = 0;
    if(vazia(l)) return -1;

    max = maximo(l->prox);
    if(l->info > max){
        return l->info;
    }
    return max;
}

void imprime(Lista* li){
    printf("-> ");

    while(li != NULL){
        printf (" %d-> ", li->info);
        li = li->prox;
    }

    printf("\n");
}
