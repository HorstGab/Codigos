#include "busca_ord.h"


//EXERCICIO 1
int posicao_valor(int vet[], int tam){
	int esq, meio, dir;

	esq = 0;
	dir = tam-1;

	while(esq < dir){
		meio = (esq + dir)/2;
		if(vet[meio] == meio){
			return meio;
		}else{
			if(vet[meio] < meio){
				esq = meio;
			}else{
				dir = meio;
			}
		}
	}

	return -1;
}

//EXERCICIO 3
void selectionSort (int vet[], int tam, int index){
	int min, j;

	//o minimo recebe o indice a ser trocado
	min = index;

	//percorrendo o vetor
	for(j = index + 1; j < tam; ++j){
		//compara se a posicao eh menor que o minimmo
		if(vet[j] < vet[min]){
			//se for atualiza o minimo
			min = j;
		}
	}

	//troca de posicao os elementos do vetor
	swap(vet, min, index);

	//testa se nao eh fim do vetor
	if(index + 1 < tam){
		//se nao for chama recursivamente a funcao atribuindo +1 no indice
		selectionSort(vet, tam, index + 1);
	}
}

void swap(int vet[], int min, int index){
	int x;

	x = vet[index];
	vet[index] = vet[min];
	vet[min] = x;
}

//EXERCICIO 4
void insertionSortList(No* no){
    No* p = no->prox->prox;
    No* q;
    int info;

    while(p->prox != NULL){
        q = p->ant;
        info = p->info;

        while((q != no) && (q->info > info)){
            q->prox->info = q->info;
            q = q->ant;
        }

        q->prox->info = info;
        p = p->prox;
    }
}

//EXERCICIO 5
/*Os algoritmos de ordenacao que sao estaveis:
 * Insertion Sort
 * Merge Sort
 * Bubble Sort

 Os algoritmos de ordenacao que nao sao estaveis:
 * Selection Sort (dependendo do algoritmo)
 * Quick Sort
*/

//EXERCICIO 6
/* A complexidade de tempo do algoritmo Shell Sort eh de O(nlg(n)^2)
 * E tambem sendo considerado nao estavel
*/

//EXERCICIO 7

void selectionSortParcial(int vet[], int tam, int k){
    int i, j, min, x;

    for(i = 0; i < tam - 1; i++){
        if(i <= k){
            min = i;

            for(j = i + 1; j < tam; j++){
                if(vet[j] < vet[min]) min = j;
                x = vet[i];
                vet[i] = vet[min];
                vet[min] = x;
            }
        }else{
            break;
        }
    }
}


