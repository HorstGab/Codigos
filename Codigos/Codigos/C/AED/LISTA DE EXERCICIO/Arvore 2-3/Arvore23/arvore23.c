#include "arvore23.h"

int vazia (arvore23 r){

    if(r == NULL){
        return 1;
    }else
        return 0;
}

arvore23 busca(arvore23 r, int chave){

    if(vazia(r)) return NULL;

    if(r->chave_esq == chave) return r;

    if(r->n == 2 && r->chave_dir == chave) return r;

    if(chave < r->chave_esq){
        return busca(r->esq, chave);
    }else if (r->n == 1){
        return busca(r->meio, chave);
    }else if (chave < r->chave_dir){
        return busca(r->meio, chave);
    }else{
        return busca(r->dir, chave);
    }
}

arvore23 inserir(arvore23 r, int chave){
    if(vazia(r)) {// caso base especial: a arvore e vazia
        return criaNo23(chave,0,NULL,NULL,NULL,1);
    }
    else {
        int chave_promovida;
        arvore23 aux = inserir_aux(r,chave,&chave_promovida);
        if(!vazia(aux)) // cria nova raiz
            return criaNo23(chave_promovida, 0,r,aux,NULL,1);
        else // raiz n~ao se altera
            return r;
    }
}

arvore23 inserir_aux (arvore23 r, int chave, int *chave_promovida){
    if(eh_folha(r)){ // caso base: esta em uma folha
        if(r->n == 1) {
            adicionaChave(r,chave,NULL);
            return NULL;
        }
        else return split(r, chave, NULL, chave_promovida);
    }
    else { // precisa descer
        arvore23 paux;
        int ch_aux;
        if (chave < r->chave_esq)
            paux = inserir_aux(r->esq, chave, &ch_aux);
        else if ((r->n == 1) || (chave < r->chave_dir))
            paux = inserir_aux( r->meio, chave, &ch_aux);
        else
            paux = inserir_aux(r->dir, chave, &ch_aux);
        if (paux == NULL) // nao promoveu
            return NULL;
        if (r->n == 1){
            adicionaChave(r, ch_aux, paux);
            return NULL;
        }
        else // precisa fazer split
            return split(r, ch_aux, paux,chave_promovida);
    }
}


arvore23 split (arvore23 p, int chave, arvore23 subarvore, int *chave_promovida){
    arvore23 paux;
    if (chave > p->chave_dir) { // chave ficara mais a direita
        *chave_promovida = p->chave_dir; // promove a antiga maior
        paux = p->dir;
        p->dir = NULL; // elimina o terceiro filho
        p->n = 1; // atualiza o numero de chaves
        return criaNo23(chave, 0, paux, subarvore, NULL, 1);
    }
    if (chave >= p->chave_esq){ // chave esta no meio
        *chave_promovida = chave; // continua sendo promovida
        paux = p->dir;
        p->dir = NULL;
        p->n = 1;
        return criaNo23(p->chave_dir, 0, subarvore, paux, NULL,1);
    }
    // chave ficara mais a esquerda
    *chave_promovida = p->chave_esq;
    // primeiro cria o no a direita
    paux = criaNo23(p->chave_dir, 0, p->meio, p->dir, NULL,1);
    p->chave_esq = chave; // atualiza o no a esquerda
    p->n = 1;
    p->dir = NULL;
    p->meio = subarvore;
    return paux;
}

void adicionaChave(arvore23 r, int chave, arvore23 p) {
    if(r->chave_esq < chave) {
        r->chave_dir = chave;
        r->dir = p;
    }
    else {
        r->chave_dir = r->chave_esq;
        r->chave_esq = chave;
        r->dir = r->meio;
        r->meio = p;
    }
    r->n = 2;
}

int eh_folha(arvore23 r){
    if(r != NULL){
        if((r->esq == NULL)&& (r->meio == NULL)&& (r->dir == NULL)){
            return 1;
        }
    }
    return 0;
}

arvore23 criaNo23(int chave_esq, int chave_dir, arvore23 esq, arvore23 meio, arvore23 dir, int n){

    arvore23 r = (arvore23)malloc(sizeof(struct no23));

    r->chave_esq = chave_esq;
    r->chave_dir = chave_dir;
    r->esq = esq;
    r->meio = meio;
    r->dir = dir;
    r->n = n;

    return r;
}

void mostraArvore(arvore23 a) {

    if (a != NULL){
    printf("<%d | %d", a->chave_esq, a->chave_dir);
    mostraArvore (a->esq);
    mostraArvore (a->meio);
    mostraArvore (a->dir);
    printf("> ");
    }
}

int minimo(arvore23 r){
    if(vazia(r)){
        return -1;
    }else{
        if(eh_folha(r)){
            return r->chave_esq;
        }else{
            return minimo(r->esq);
        }
    }
}

int maximo(arvore23 r){
    if(vazia(r)) return -1;
    else{
        if(eh_folha(r)){
            if(r->chave_dir){
                return r->chave_dir;
            }else{
                return r->chave_esq;
            }

        }else{
            if(vazia(r->dir)){
                return maximo(r->meio);
            }else
                return maximo(r->dir);
        }
    }
}

int conta_nos(arvore23 r){
    if(vazia(r)) return 0;
    else{
        return conta_nos(r->esq) + conta_nos(r->meio) + conta_nos(r->dir) + 1;
    }
}

void in_ordem(arvore23 r){
    if(vazia(r)) return;
    in_ordem(r->esq);
    printf("< %d >\n", r->chave_esq);
    in_ordem(r->meio);
    printf("< %d >\n", r->chave_dir);
    in_ordem(r->dir);

}
