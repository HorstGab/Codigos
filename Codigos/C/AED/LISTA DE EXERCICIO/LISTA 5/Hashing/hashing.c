#include "hashing.h"

int hash(int k){
    return k%TAM;
}

int hash2(int k){
    return (k%(TAM-1))+1;
}

int hash_Linear(int k, int i){
    return (k+i)%TAM;
}

int hash_Quadratica(int k, int i){
    return (k + 2*i + 5*i*i)%TAM;
}

int hash_Multiplicacao(int k){
    double A = (sqrt(5)-1)/2;
    return (int)TAM *(fmod(k*A, 1));
}

int posicaoVazia(TabelaHash T, int index){
    return T[index].ocupado == 0;
}

void show(TabelaHash T){
    int i;

    for(i = 0; i < TAM; i++){
        printf("[%d]\n",i);
        printf("Matricula: %d \n", T[i].r.matricula);
        printf("Nome: %s \n", T[i].r.nome);
        printf("Chave: %d \n\n", T[i].k);
    }
}

TipoRegistro obterRegistro(int matricula, char nome[]){

    TipoRegistro T;
    int i;

    T.matricula = matricula;
    for(i = 0; i < 50; i++){
        T.nome[i] = nome[i];
    }
    return T;
}

void inicializaTabelaHash(TabelaHash T){
    int i;

    for(i = 0; i < TAM; i++){
        T[i].r.matricula = 0;
        T[i].r.nome[0] = '\0';
        T[i].k = 0;
        T[i].ocupado = 0;
    }
}

void inserir(TabelaHash T, TipoChave k, TipoRegistro r){
    int i;
    for(i = 0; i < TAM; i++){
        int j = hash_Quadratica(k, i);
        if(posicaoVazia(T, j)){
            T[j].k = k;
            T[j].r = r;
            T[j].ocupado = 1;
            return;
        }
    }
}

int buscar(TabelaHash T, TipoChave k){
    int i;
    for(i = 0; i < TAM; i++){
        int j = hash_Quadratica(k, i);
        if(!posicaoVazia(T, j)){
            if(T[j].r.matricula == k){
                return j;
            }
        }
    }
    return -1;
}

void remover(TabelaHash T, TipoChave k){
    int i = buscar(T,k);

    if(T[i].r.matricula == k){
        T[i].ocupado = 0;
        T[i].k = 0;
        T[i].r.matricula = 0;
        T[i].r.nome[0] = '\0';
    }
}
