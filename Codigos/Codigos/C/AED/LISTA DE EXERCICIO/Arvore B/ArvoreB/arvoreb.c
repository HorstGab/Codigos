#include "arvoreb.h"


// Insere uma chave na arvore B fazendo split da raiz se necessario
// retorna a nova raiz
arvoreB* insere(arvoreB* r, int info){
    if(vazia(r)) {
        r = malloc(sizeof(arvoreB));
        r->chave[0] = info;
        r->filho[0] = NULL;
        r->numChaves = 1;
    }
    else {
        insere_aux(r,info);
        if(overflow(r)){
            int m;
            arvoreB* x = split(r,&m);
            arvoreB* novaRaiz = malloc(sizeof(arvoreB));
            novaRaiz->chave[0] = m;
            novaRaiz->filho[0] = r;
            novaRaiz->filho[1] = x;
            novaRaiz->numChaves = 1;
            return novaRaiz;
        }
    }
    return r;
}

void insere_aux(arvoreB* r, int info){
    int pos;
    if(!buscaPos(r,info, &pos)){ // chave n~ao esta no no r
        if(eh_folha(r)) {
            adicionaDireita(r,pos,info,NULL);
        }
        else {
            insere_aux(r->filho[pos],info);
            if(overflow(r->filho[pos])){
                int m; // valor da chave mediana
                arvoreB* aux = split(r->filho[pos],&m);
                adicionaDireita(r,pos,m,aux);
            }
        }
    }
}

void adicionaDireita(arvoreB* r, int pos, int k, arvoreB* p){
    int i;
    for(i=r->numChaves; i>pos; i--){
        r->chave[i] = r->chave[i-1];
        r->filho[i+1] = r->filho[i];
    }
    r->chave[pos] = k;
    r->filho[pos+1] = p;
    r->numChaves++;
}

// busca a posic~ao em que a chave info esta ou estaria em um no
// retorna 1 se a chave esta presente ou 0 caso contrario
int buscaPos(arvoreB* r, int info, int * pos) {
    for((*pos)=0; (*pos) < r->numChaves; (*pos)++)
        if(info == r->chave[(*pos)])
            return 1; // chave ja esta na arvore
        else if(info < r->chave[(*pos)])
            break; // info pode estar na subarvore filho[*pos]
    return 0; // chave n~ao esta neste no
}


int eh_folha(arvoreB* r) {
    return (r->filho[0] == NULL);
}

//Quebra o no x (com overflow) e retorna o no criado e chave m que
// deve ser promovida
arvoreB* split(arvoreB* x, int * m) {
    arvoreB* y = (arvoreB*) malloc(sizeof(arvoreB));
    int q = x->numChaves/2;
    y->numChaves = x->numChaves - q - 1;
    x->numChaves = q;
    *m = x->chave[q]; // chave mediana
    int i = 0;
    y->filho[0] = x->filho[q+1];
    for(i = 0; i < y->numChaves; i++){
        y->chave[i] = x->chave[q+i+1];
        y->filho[i+1] = x->filho[q+i+2];
    }
    return y;
}

int vazia(arvoreB *r){
    if(r == NULL) return 1;
    else{
        return 0;
    }
}

int maximo(arvoreB *r){
    int resultado = -1;
    arvoreB* aux = r;

    if(vazia(r)) return -1;

   if(r->numChaves){
       while(aux->filho[aux->numChaves]){
           aux = aux->filho[aux->numChaves];
       }
       resultado = aux->chave[aux->numChaves -1];
   }
   return resultado;
}

int minimo (arvoreB *r){
    int resultado = -1;
    arvoreB* aux = r;

    if(r->numChaves){
        while(aux->filho[0]){
            aux = aux->filho[0];
        }
        resultado = aux->chave[0];
    }
    return resultado;
}

int contaNosMinChaves(arvoreB *r) {
    int i, aux;

    if(vazia(r)) return 0;

    for(i = aux = 0; i < ORDEM; ++i) {
        aux += contaNosMinChaves(r->filho[i]);
    }

    if(r->numChaves == ORDEM/2) ++aux;

    return aux;
}
