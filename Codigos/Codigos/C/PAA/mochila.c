#include "mochila.h"

int *valor, *peso, tamanho;

int max(int a, int b){
	return (a > b)? a : b;
}

void imprimir(int m[][50]){
    int i, j;

    for(i = 0; i <= tamanho; i++){
        for(j = 0; j <= 50; j++){
            printf("%d ", m[i][j]);
        }
        printf("\n\n");
    }
}

int knapSackPD (int w){
	int i, j;
	int a, b;
    int K[tamanho+1][w+1];
    int x[tamanho+1];

    for(a = 0; a <= w; a++) {
        K[0][a] = 0;
    }

    for(b = 0; b <= tamanho; b++) {
        K[b][0] = 0;
    }

    for (i = 1; i <= tamanho; i++){
        for(j = 1; j <= w; j++){
            if((peso[i-1] <= j) && (valor[i-1]+K[i-1][j-peso[i-1]] > K[i-1][j])){
                K[i][j] = valor[i-1] + K[i-1][j-peso[i-1]];
            }else{
				K[i][j] = K[i-1][j];
			}
		}
    }
    for(i = 0; i < tamanho; i++) x[i] = 0;

    i = tamanho;
    j = w;
	while(K[i][j] != 0){
		if(K[i][j] == K[i-1][j]){
            i = i-1;
        }else{
            x[i-1] = 1;
            j = j - peso[i-1];
            i = i-1;
		}
	}

    for(a = 0; a < tamanho; a++){
        printf("x[%d] = %d \n", a, x[a]);
    }
    return K[tamanho][w];
}

void loadData(){
	char nome[30];
	int *matrizAux, str, i;
	
	FILE *f;
	printf("Digite o nome do arquivo: ");
	scanf("%[^\n]%*c", &nome);
	tamanho = 10;

	if ((f = fopen(nome, "r")) == NULL){
		printf("Erro ao Abrir o Arquivo\n");
	}else{
		//vetor dinamico
		matrizAux = (int*)malloc(tamanho*sizeof(int));
		for(i = 0; !feof(f); i++){
			if(i + 1 > tamanho){
				tamanho *= 2;
				matrizAux = (int*)realloc (matrizAux, tamanho*sizeof(int));
			}
			fscanf(f, "%d", &str);
			matrizAux[i] = str;
		}
		tamanho = i;
		matrizAux = (int*)realloc(matrizAux, tamanho*sizeof(int));
	}

	//cada vetor é alocado com o tamanho da coluna da matriz 
	tamanho /= 2;
	valor = (int*)malloc(tamanho*sizeof(int));
	peso = (int*)malloc(tamanho*sizeof(int));

	if(valor == NULL || peso == NULL) return;

	//separa os vetores concatenados 
	for(i = 0; i < tamanho; i++){
		valor[i] = matrizAux[2*i];
		peso[i] = matrizAux[2*i+1];
	}

	for(i = 0; i < tamanho; i++){
		printf("%d  %d \n", valor[i], peso[i]);
	}
	free (matrizAux);
	fclose(f);
}