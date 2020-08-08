#include <stdio.h>
#include <stdlib.h>

#define ORDEM 5

struct no{
	int numChaves;
	int chave[ORDEM];
	struct no* filho[ORDEM+1];
};
typedef struct no* arvoreB;

int vazia(arvoreB r){
    return(r == NULL);
}

int overflow(arvoreB r){
	return (r->numChaves == ORDEM);
}

int buscaPos(arvoreB r, int info, int* pos) {
    for((*pos) = 0; (*pos) < r->numChaves; (*pos)++)
        if(info == r->chave[(*pos)]){
            return 1; 
        }else{
			if(info < r->chave[(*pos)]){
            	break; 
			}
		}
    return 0; 
}


void adicionaDireita(arvoreB r, int pos, int k, arvoreB p){
    int i;
    for(i=r->numChaves; i>pos; i--){
        r->chave[i] = r->chave[i-1];
        r->filho[i+1] = r->filho[i];
    }
    r->chave[pos] = k;
    r->filho[pos+1] = p;
    r->numChaves++;
}



int eh_folha(arvoreB r) {
    return (r->filho[0] == NULL);
}


arvoreB split(arvoreB x, int * m) {
    arvoreB y = (arvoreB)malloc(sizeof(struct no));
    int q = x->numChaves / 2;

    y->numChaves = x->numChaves - q - 1;
    x->numChaves = q;
    (*m) = x->chave[q];

    y->filho[0] = x->filho[q+1];

    int i;
    for(i = 0; i < y->numChaves; i++){
    	y->chave[i] = x->chave[q+i+1];
    	y->filho[i+1] = x->filho[q+i+2];
    }
    return y;
}

void insere_aux(arvoreB r, int info){
    int pos;
    if(!buscaPos(r,info, &pos)){ // chave n~ao esta no no r
        if(eh_folha(r)) {
            adicionaDireita(r,pos,info,NULL);
        }
        else {
            insere_aux(r->filho[pos],info);
            if(overflow(r->filho[pos])){
                int m; // valor da chave mediana
                arvoreB aux = split(r->filho[pos],&m);
                adicionaDireita(r,pos,m,aux);
            }
        }
    }
}

// Insere uma chave na arvore B fazendo split da raiz se necessario
// retorna a nova raiz
arvoreB insere(arvoreB r, int info){
    if(vazia(r)) {
        r = malloc(sizeof(struct no));
        r->chave[0] = info;
        r->filho[0] = NULL;
        r->numChaves = 1;
    }
    else {
        insere_aux(r,info);
        if(overflow(r)){
            int m;
            arvoreB x = split(r,&m);
            arvoreB novaRaiz = malloc(sizeof(struct no));
            novaRaiz->chave[0] = m;
            novaRaiz->filho[0] = r;
            novaRaiz->filho[1] = x;
            novaRaiz->numChaves = 1;
            return novaRaiz;
        }
    }
    return r;
}

void imprimir(arvoreB r){
	if(r == NULL){
		printf("\n");
		return;
	}
	int i;
	for(i = 0; i < r->numChaves; i++){
		imprimir(r->filho[i]);
		printf("[%d]\n", r->chave[i]);
	}
	imprimir(r->filho[r->numChaves]);
}

int somaIntervalos(arvoreB r, int a, int b){
	if(r == NULL) return 0;
	if(r->chave[0] > b) return somaIntervalos(r->filho[0], a, b);
	if(r->chave[r->numChaves - 1] < a) return somaIntervalos(r->filho[r->numChaves], a, b);
	
	int i, soma = 0;
	for(i = 0; i < r->numChaves; i++){
		if(r->chave[i] >= a && r->chave[i] <= b){
			soma += r->chave[i] + somaIntervalos(r->filho[i], a, b);
		}
	}

	soma += somaIntervalos(r->filho[i], a, b);
	return soma;
}


int main(int argc, char const *argv[])
{
	arvoreB r = NULL;

	r = insere(r, 1);
	r = insere(r, 2);
	r = insere(r, 3);
	r = insere(r, 4);
	r = insere(r, 5);
	r = insere(r, 6);
	r = insere(r, 7);
	r = insere(r, 8);

	imprimir(r);

	printf("[%d,%d] = %d\n", 3, 7, somaIntervalos(r, 3, 7));
	return 0;
}