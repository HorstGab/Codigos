#include <stdio.h>
#include <stdlib.h>

//---------------------------------LISTA ----------------------------------------------
typedef struct no{
	int info;
	struct no* prox;
}Lista;

int vazia(Lista* l){
	return (l == NULL);
}

Lista* criarNo(int info){
	Lista* novo = malloc(sizeof(Lista));
	novo->info = info;
	novo->prox = NULL;
}

void imprimirLista(Lista* l){
	while(l){
		printf("%d -> ", l->info);
		l = l->prox;
	}
	printf("NULL \n");
}

Lista* insereLista(Lista* l, int info){
	Lista* novo = malloc(sizeof(Lista));
	novo->info = info;
	novo->prox = l;
	return novo;
}

Lista* removerElementoLista(Lista* l, int info){
	Lista* ant = l; //elemento anterior
	Lista* p = l; //elemento a ser removido

	if(!vazia(l)){
		while(p && p->info != info){ //enquanto o no n for nulo e n for o mesmo valor
			ant = p;
			p = p->prox;
		}

		if(p){ //elemento encontrado
			if(p == l){ //se for a cabeca
				l = l->prox;
			}else //remove no meio
				ant->prox = p->prox; //anterior ao elemento recebe o proximo dele
			}else
				printf("elemento n encontrado\n");
	free(p);
	}
	return l;
}

Lista* subtrair(Lista* l1, Lista* l2){
	while(l2){
		l1 = removerElementoLista(l1, l2->info);
		l2 = l2->prox;
	}
	return l1;
}

int somaElemento(Lista* l){
	if(l == NULL) return 0;
	return somaElemento(l->prox) + l->info;
}

Lista* inserir_apos_Lista(Lista* l, int valRef, int info){
	if(!l) return criarNo(info); //se for final encadeia 

	if(l->info != valRef){ //se n for o valor de referencia vai para o proximo no
		l->prox = inserir_apos_Lista(l->prox, valRef, info);
	}else{ //o proximo elemento recebe o novo no
		Lista* aux = l->prox;
		l->prox = criarNo(info);
        l->prox->prox = aux;
	}
	return l;
}

Lista* remove_Enesimo(Lista* l, int n){

	Lista* aux = l;
	if(!vazia(l)){
		int i = 1;
		while(aux){
			if(i == n){
				l = removerElementoLista(l, aux->info);
				break;
			}
			i++;
			aux = aux->prox;
		}
	}
	return l;
}

int conta_ocorrencia(Lista* l, int info){

	if(vazia(l)) return 0;
	if(l->info == info){
		return conta_ocorrencia(l->prox, info) + 1;
	}
	return conta_ocorrencia(l->prox, info);
}

Lista* concatena(Lista* l1, Lista* l2){
	if(!l1) return l2;
	l1->prox = concatena(l1->prox, l2);
	return l1;
}

Lista* intercala(Lista* l1, Lista* l2){
	Lista* l;
	if(vazia(l1)) return concatena(l, l2);
	if(vazia(l2)) return concatena(l, l1);

	l = insereLista(l, l1->info);
	l = insereLista(l, l2->info);

	return intercala(l1->prox, l2->prox);
}
//---------------------------------Lista de Lista ----------------------------------------------

typedef struct matriz{
	Lista* lista;
	struct matriz* next;
}Matriz_Lista;

int vaziaMatrizLista(Matriz_Lista* ml){
	return (ml == NULL);
}

Matriz_Lista* criarMatrizVazia(){
	Matriz_Lista* novo = (Matriz_Lista*)malloc(sizeof(Matriz_Lista));

	novo->lista = NULL;
	novo->next = NULL;

	return novo;
}

Lista* inverte(Lista* l){

	Lista* novo = (Lista*)malloc(sizeof(Lista));

	if(!l) return NULL;

	novo = insereLista(l, l->info);
	l = inverte(l->prox);

	return novo;

}

Matriz_Lista* inverte_internas(Matriz_Lista* ml){

	if(vaziaMatrizLista(ml)) return NULL;

	// Matriz_Lista* novo = (Matriz_Lista*)malloc(sizeof(Matriz_Lista));

	if(!ml->lista){
		ml = inverte_internas(ml->next);
	}else{
		ml->lista = inverte(ml->lista);
		imprimirLista(ml->lista);
	}

	return ml;
}
//---------------------------------FILA ----------------------------------------------

typedef struct {
	Lista* inicio;
	Lista* fim;
}Fila;

int vaziaFila(Fila* f) {
	return (f->inicio == NULL);
}

Fila* cria_fila_vazia() {
	Fila* f = (Fila*) malloc(sizeof(Fila));
	f->inicio = NULL;
	f->fim = NULL;
	return f;
}

void enqueue(Fila* f, int info){

	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info = info;
	novo->prox = NULL;

	if(vaziaFila(f)){
		f->inicio = novo;
	}else{
		f->fim->prox = novo;
	}
	f->fim = novo;
}

void dequeue(Fila* f){

	if(!vaziaFila(f)){
		Lista* aux = f->inicio;
		if(f->inicio == f->fim){
			f->fim = NULL;
		}
		f->inicio = f->inicio->prox;
		free(aux);
	}
}


//---------------------------------PILHA ----------------------------------------------

typedef struct {
	struct no* topo;
}Pilha;

Pilha* CriarPilha(){
	Pilha* aux = (Pilha*)malloc(sizeof(Pilha));
	aux->topo = NULL;
	return aux;
}

void push(Pilha* p, int info){

	struct no* novo = (struct no*)malloc(sizeof(struct no));
	novo->info = info;
	novo->prox = p->topo;
	p->topo = novo;
}

void pop(Pilha* p){

	if(!p) return;
	if(!p->topo) p->topo = NULL;
	p->topo = p->topo->prox;
}

//---------------------------------Lista Duplamente encadeada----------------------------------------------

struct _no{
	int info;
	struct _no* ant;
	struct _no* prox;
};

typedef struct{
	struct _no* inicio;
	struct _no* fim;
}_Lista;

int vaziaD(_Lista* l){
	return (l->inicio == NULL);
}

_Lista* criarListaDupla(){
	_Lista* aux = (_Lista*)malloc(sizeof(_Lista));
	aux->inicio = NULL;
	aux->fim = NULL;
	return aux;
}

void insereListaDupla(_Lista* l, int info){
	struct _no* aux = (struct _no*)malloc(sizeof(struct _no));
	aux->info = info;
	aux->prox = l->inicio;
	aux->ant = NULL;
	l->inicio->ant = aux;

	l->inicio = aux;


}

void imprimirListaDupla(struct _no* l){
	if(!l){
		printf("NULL\n");
		return;
	}

	printf("%d <-> ", l->info);
	imprimirListaDupla(l->prox);
}

int main(int argc, char const *argv[])
{
	Lista* l = NULL;

	l = insereLista(l, 2);
	l = insereLista(l, 7);
	l = insereLista(l, 5);
	l = insereLista(l, 7);
	l = insereLista(l, 11);
	l = insereLista(l, 13);
	l = insereLista(l, 17);
	imprimirLista(l);

	Lista* l2 = NULL;
	l2 = insereLista(l2, 0);
	l2 = insereLista(l2, 1);
	l2 = insereLista(l2, 2);
	l2 = insereLista(l2, 3);
	l2 = insereLista(l2, 4);
	l2 = insereLista(l2, 5);
	l2 = insereLista(l2, 6);
	l2 = insereLista(l2, 7);
	l2 = insereLista(l2, 8);
	l2 = insereLista(l2, 9);
	l2 = insereLista(l2, 10);
	l2 = insereLista(l2, 11);
	l2 = insereLista(l2, 12);
	l2 = insereLista(l2, 13);
	l2 = insereLista(l2, 14);
	l2 = insereLista(l2, 15);
	l2 = insereLista(l2, 16);
	l2 = insereLista(l2, 17);
	l2 = insereLista(l2, 18);
	l2 = insereLista(l2, 19);
	l2 = insereLista(l2, 20);
	imprimirLista(l2);


	printf("\n\nExercicio 1\n");
	l2 = subtrair(l2, l);
	imprimirLista(l2);

	printf("\n\nExercicio 2\n");
	printf("L = %d\n", somaElemento(l));
	printf("L2 = %d\n", somaElemento(l2));

	printf("\n\nExercicio 3\n");
	l = inserir_apos_Lista(l, 1, 0);
	imprimirLista(l);

	printf("\n\nExercicio 4\n");
	Fila* f = cria_fila_vazia();

	enqueue(f, 0);
	enqueue(f, 1);
	enqueue(f, 2);
	enqueue(f, 3);
	enqueue(f, 4);
	enqueue(f, 5);
	enqueue(f, 6);
	imprimirLista(f->inicio);

	dequeue(f);
	dequeue(f);
	imprimirLista(f->inicio);

	printf("\n\nExercicio 5\n");
	Matriz_Lista* ml = criarMatrizVazia();


	printf("\nExercicio1 prova 2\n");

	imprimirLista(l);
	l = remove_Enesimo(l, 5);
	imprimirLista(l);
	
	printf("\nExercicio 2 prova 2\n");
	printf("ocorrencia - %d\n", conta_ocorrencia(l, 7));


	printf("\nExercicio 3 prova 2\n");
	imprimirLista(l);
	imprimirLista(l2);
	Lista* novalista = intercala(l, l2);
	imprimirLista(novalista);


	printf("\nExercicio 4 prova 2\n");
	Pilha* p = CriarPilha();

	push(p, 0);
	push(p, 2);
	push(p, 3);
	printf("debug\n");
	imprimirLista(p->topo);

	pop(p);
	imprimirLista(p->topo);

	printf("\nExercicio 5 prova 2\n");
	_Lista* _l = criarListaDupla();
	imprimirListaDupla(_l->inicio);

	insereListaDupla(_l, 0);
	insereListaDupla(_l, 2);
	insereListaDupla(_l, 5);
	insereListaDupla(_l, 8);
	imprimirListaDupla(_l->inicio);

	return 0;
}