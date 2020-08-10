#include <stdio.h>
#include <stdlib.h>

struct no{
	int info;
	struct no* prox;
};
typedef struct no* Lista;

struct no_arv{
	int info;
	struct no_arv* esq;
	struct no_arv* dir;
};
typedef struct no_arv* Arvore;

typedef struct _no{
	Arvore node;
	struct _no* prox;
}TreeList;

typedef struct {
	TreeList* inicio;
	TreeList* fim;
}Fila;

int vazia(Arvore r){
	return (r == NULL);
}

void enqueue(Fila* f, Arvore info){

	TreeList* novo = (TreeList*)malloc(sizeof(TreeList));
	novo->node = info;
	novo->prox = NULL;

	if(f->inicio == NULL){
		f->inicio = novo;
	}else{
		f->fim->prox = novo;
	}
	f->fim = novo;
}

Arvore dequeue(Fila* f){
	TreeList* aux;
	if(f->inicio){
		aux = f->inicio;
		if(f->inicio == f->fim){ //se só tem um elemento
			f->inicio = f->fim = NULL;
		}else{
			f->inicio = f->inicio->prox;
		}
	}
	return aux->node;
}

Arvore insere_Arvore_Binaria(Arvore r, int x){

    if(vazia(r)){
        r = (Arvore)malloc(sizeof(struct no_arv));
        r->dir = NULL;
        r->esq = NULL;
        r->info = x;
    }else{
        if(x < r->info){
            r->esq = insere_Arvore_Binaria(r->esq, x);
        }else{
            r->dir = insere_Arvore_Binaria(r->dir, x);
        }
    }
    return r;
}

Lista insereLista(Lista l, int info){
	Lista novo = (Lista)malloc(sizeof(struct no));
	novo->info = info;
	novo->prox = l;
	return novo;
}

Lista concatena (Lista l1, Lista l2){
	if(!l1) return l2;
	l1->prox = concatena(l1->prox, l2);
	return l1;
}
Lista impares (Arvore r){

	if(vazia(r)) return NULL;
	Lista l1 = impares(r->esq);
	Lista l2 = impares(r->dir);

	if(r->info%2){
		return  concatena(l1, insereLista(l2, r->info));
	}else{
		return concatena(l1, l2);
	}
}

int somarMenores(Arvore r, int x){
	if(vazia(r)) return 0;
	if(r->info < x){
		return r->info + somarMenores(r->esq, x) + somarMenores(r->dir, x);
	}else{
		return somarMenores(r->esq, x);
	}
}


void imprimir (Arvore r){

	
	Fila* f = malloc(sizeof(Fila));
	f->inicio = f->fim = NULL;
	
	if(!vazia(r)){
		enqueue(f, r);
		Arvore nl = malloc(sizeof(struct no_arv));
		nl->info = -1;
		nl->dir = NULL;
		nl->esq = NULL;
		enqueue(f, nl);
	}

	while(f->inicio != NULL){
		Arvore aux = dequeue(f);
		if(aux->esq) enqueue(f, aux->esq);
		if(aux->dir) enqueue(f, aux->dir);
		if(aux->info != -1){
			printf("[%d] ", aux->info);
		}else{
			printf("\n");
		}
	}
	free(f);
}

void imprimirArvore(Arvore r){
	if(!vazia(r)){
		imprimirArvore(r->esq);
		printf("[%d]\n", r->info);
		imprimirArvore(r->dir);
	}
}

void imprimirLista(Lista l){
	if(l == NULL){
		printf("NULL\n");
		return;
	}
	printf("%d -> ", l->info);
	imprimirLista(l->prox);
}

int eh_max_heap(int v[], int m){
	int i = 1;
	while(i < m){
		if(i <= m){
			if(v[i] >= v[2*i]){
				if((2*i+1) <= m){
					if(v[i] >= v[2*i+1]){
						i++;
					}else return 0;
				}else return 1;
			}else return 0;
		}else return 1;
	}
}

int main(int argc, char const *argv[])
{
	Arvore r = NULL;

	r = insere_Arvore_Binaria(r, 11);
	r = insere_Arvore_Binaria(r, 13);
	r = insere_Arvore_Binaria(r, 7);
	r = insere_Arvore_Binaria(r, 14);
	r = insere_Arvore_Binaria(r, 2);
	r = insere_Arvore_Binaria(r, 8);
	r = insere_Arvore_Binaria(r, 22);
	imprimirArvore(r);

	Lista impar = impares(r);
	imprimirLista(impar);

	printf("%d\n", somarMenores(r, 5));

	imprimir(r);

	printf("\n");
	int vet[] = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1};

	if(eh_max_heap(vet, 7)){
		printf("SIM\n");
	}else{
		printf("NAO\n");
	}

	return 0;
}