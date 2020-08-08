    
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void imprimir(int **matriz, int ordem, char *nome){
	FILE *f;
	int i, j;

	if((f = fopen (nome, "w")) == NULL){
		printf("Erro na Abertura do Arquivo\n");
	}else{
		fprintf(f, "%d \n", ordem);
		for(i = 0; i < ordem; i++){
			for(j = 0; j < ordem; j++){
				fprintf(f, "%d ", matriz[i][j]);				
				fprintf(f, "%d ", matriz[i][j]*2);
			}
		}
	}
	fclose(f);
}

int main(int argc, char const *argv[]){
	char nome[30];
	int ordem;

	printf("Digite a ordem dos vetores: ");
	scanf("%d", &ordem);
	getchar();

	printf("Digite o nome do arquivo: ");
	scanf("%[^\n]%*c", &nome);

	int **matriz = (int**)malloc(ordem*sizeof(int*));
	int i, j;

	for(i = 0; i < ordem; i++){
		matriz[i] = (int*)malloc(ordem*sizeof(int));
	}

	srand(time(NULL));
	for(i = 0; i < ordem; i++){
		for(j = 0; j < ordem; j++){
			matriz[i][j] = rand()%1000;
		}
	}

	imprimir(matriz, ordem, nome);

	return 0;
}