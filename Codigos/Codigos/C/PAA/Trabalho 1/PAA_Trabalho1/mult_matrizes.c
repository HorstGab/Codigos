#include "mult_matrizes.h"

//Aloca memória para a matriz quadrática
//Entrada: ordem da matriz
//Retorno: matriz alocada
//Pré-Condições: nenhuma
//Pós-Condições: memória alocada para a matriz
int **alocaMatriz(int n){
	int i, **m;
	//aloca memória para as linhas
	m = (int **)malloc(n * sizeof(int *));
	for(i = 0; i < n; i++){
		//aloca memória para as colunas
		m[i] = (int *)malloc(n * sizeof(int));
	}
	return m;
}

//Desaloca memória para a matriz quadrática
//Entrada: matriz, ordem da matriz
//Retorno: matriz alocada
//Pré-Condições: nenhuma
//Pós-Condições: memória desalocada
void desalocaMatriz(int **m, int n){
	int i;
	for(i = 0; i < n; i++){
		//desaloca memória para as colunas
		free(m[i]);
	}
	//desaloca memória para as linhas
	free(m);
}

//Faz leitura no arquivo e seta elementos na matriz
//Entrada: ponteiro para o arquivo, matriz, ordem da matriz
//Retorno: nenhum
//Pré-Condições: arquivo aberto, memória da matriz alocada
//Pós-Condições: matriz setada
void lerMatrizArq(FILE *f, int **m, int n){
	int i, j;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			fscanf(f, "%d", &m[i][j]);
		}
	}
}

//Multiplicação de matrizes complexidade normal
//Entrada: matriz a, matriz b, matriz c, ordem das matrizes
//Retorno: nenhum
//Pré-Condições: matrizes com números setados, menis a matriz c
//Pós-Condições: matrizes multiplicadas
void mult_matrizes(int **ma, int **mb, int **mc, int n){
	int i, j, k;
	for (i = 0; i < n; i++){						
		for (j = 0; j < n; j++){ 					
			mc[i][j] = 0; 
			for (k = 0; k < n; k++){ 				
				mc[i][j] += ma[i][k]*mb[k][j];
			}
		} 
	}
}

//Multiplicação de matrizes com o algoritmo de Strassen
//Entrada: matriz a, matriz b, matriz c, ordem das matrizes
//Retorno: nenhum
//Pré-Condições: matrizes com números setados, menos a matriz c
//Pós-Condições: matrizes multiplicadas
void alg_Strassen(int **ma, int **mb, int **mc, int n){
	//caso base, quando a matriz for de ordem 1
	if (n == 1){
		mc[0][0] = ma[0][0]*mb[0][0];
	}
	else{
		int size = n/2;

		//aloca memória para todas as subdivisões
		int **a11 = alocaMatriz(size);
		int **a12 = alocaMatriz(size);
		int **a21 = alocaMatriz(size);
		int **a22 = alocaMatriz(size);
		int **b11 = alocaMatriz(size);
		int **b12 = alocaMatriz(size);
		int **b21 = alocaMatriz(size);
		int **b22 = alocaMatriz(size);

		//aloca memória para matrizes utilizadas nas cadeias de 7 multiplicações de matrizes a serem realizadas
		int **m1 = alocaMatriz(size);
		int **m2 = alocaMatriz(size);	
		int **m3 = alocaMatriz(size);
		int **m4 = alocaMatriz(size);
		int **m5 = alocaMatriz(size);
		int **m6 = alocaMatriz(size);
		int **m7 = alocaMatriz(size);

		//divide a matriz a em partes iguais
		dividir(ma, a11, 0, 0, size);
		dividir(ma, a12, 0, size, size);
		dividir(ma, a21, size, 0, size);
		dividir(ma, a22, size, size, size);
		//divide a matriz b em partes iguais
		dividir(mb, b11, 0, 0, size);
		dividir(mb, b12, 0, size, size);
		dividir(mb, b21, size, 0, size);
		dividir(mb, b22, size, size, size);

		//m1 = (a11+a22)(b11+b22)
		int **temp1 = adicao(a11, a22, size);
		int **temp2 = adicao(b11, b22, size);
		alg_Strassen(temp1, temp2, m1, size);
		desalocaMatriz(temp1, size);
		desalocaMatriz(temp2, size);

		//m2 = (a21+a22)b11
		int **temp3 = adicao(a21, a22, size);
		alg_Strassen(temp3, b11, m2, size);
		desalocaMatriz(temp3, size);
		
		//m3 = a11(b12-b22)
		int **temp4 = subtr(b12,b22, size);
		alg_Strassen(a11, temp4, m3, size);
		desalocaMatriz(temp4, size);

		//m4 = a22(b21-b11)
		int **temp5 = subtr(b21, b11, size);
		alg_Strassen(a22, temp5, m4, size);
		desalocaMatriz(temp5, size);

		//m5 = (a11+a12)b22
		int **temp6 = adicao(a11, a12, size);
		alg_Strassen(temp6, b22, m5, size);
		desalocaMatriz(temp6, size);

        //m6 = (a21-a11)(b11+b12)
		int **temp7 = subtr(a21, a11, size);
		int **temp8 = adicao(b11, b12, size);
		alg_Strassen(temp7, temp8, m6, size);
		desalocaMatriz(temp7, size);
		desalocaMatriz(temp8, size);

        //m7 = (a12-a22)(a21+a22)
		int **temp9 = subtr(a12, a22, size);
		int **temp10 = adicao(b21, b22, size);
		alg_Strassen(temp9, temp10, m7, size);
		desalocaMatriz(temp9, size);		
		desalocaMatriz(temp10, size);

		//Primeira parte da matriz produto de duas matrizes
		int **temp11 = adicao(m1, m4, size);
		int **temp12 = subtr(temp11, m5, size);
		int **c11 = adicao(temp12, m7, size);
		desalocaMatriz(temp11, size);		
		desalocaMatriz(temp12, size);

		//Segundo parte
		int **c12 = adicao(m3, m5, size);

		//Terceiro parte
		int **c21 = adicao(m2, m4, size);
		
		//Ultima parte
		int **temp13 = adicao(m1, m3, size);
		int **temp14 = subtr(temp13, m2, size);
		int **c22 = adicao(temp14, m6, size);		
		desalocaMatriz(temp13, size);
		desalocaMatriz(temp14, size);

		//Junção de todas as partes em uma matriz
		juntar(c11, mc, 0, 0, size);
		juntar(c12, mc, 0, size, size);
		juntar(c21, mc, size, 0, size);
		juntar(c22, mc, size, size, size);

		desalocaMatriz(m1, size);
		desalocaMatriz(m2, size);
		desalocaMatriz(m3, size);
		desalocaMatriz(m4, size);
		desalocaMatriz(m5, size);
		desalocaMatriz(m6, size);
		desalocaMatriz(m7, size);

		desalocaMatriz(c11, size);
		desalocaMatriz(c12, size);
		desalocaMatriz(c21, size);
		desalocaMatriz(c22, size);

		desalocaMatriz(a11, size);
		desalocaMatriz(a12, size);
		desalocaMatriz(a21, size);
		desalocaMatriz(a22, size);

		desalocaMatriz(b11, size);
		desalocaMatriz(b12, size);
		desalocaMatriz(b21, size);
		desalocaMatriz(b22, size);
	}
}

//Divide a matriz em partes
//Entrada: matriz principal, matriz menor secundária
//Retorno: nenhum
//Pré-Condições: matrizes não nulos e memória alocada
//Pós-Condições: submatriz criada
void dividir(int **mPrinc, int **mSec, int inicio1, int inicio2, int size){
	int i1, i2, j1, j2;
	for (i1 = 0, i2 = inicio1; i1 < size; i1++, i2++){
		for (j1 = 0, j2 = inicio2; j1 < size; j1++, j2++){
			mSec[i1][j1] = mPrinc[i2][j2];
		}
	}
}

//Adição de matrizes
//Entrada: matrizes a serem somadas
//Retorno: nenhum
//Pré-Condições: matrizes não nulos e memória alocada
//Pós-Condições: matrizes somadas
int **adicao(int **m1, int **m2, int size){
	int **mAux = alocaMatriz(size);
	int i, j;
	for(i = 0; i < size; i++){
		for(j = 0; j < size; j++){
			mAux[i][j] = m1[i][j] + m2[i][j];	
		}
	}
	return mAux;
}

//Subtração de matrizes
//Entrada: matrizes a serem subtraídas
//Retorno: nenhum
//Pré-Condições: matrizes não nulos e memória alocada
//Pós-Condições: matrizes subtraidas
int **subtr(int **m1, int **m2, int size){
	int **mAux = alocaMatriz(size);
	int i, j;
	for (i = 0; i < size; i++){
		for (j = 0; j < size; j++){
			mAux[i][j] = m1[i][j] - m2[i][j];
		}
	}
	return mAux;
}

//Juntas todas as partes dividias em uma matriz
//Entrada: matriz a ser juntadas, matriz principal
//Retorno: nenhum
//Pré-Condições: matrizes não nulos e memória alocada
//Pós-Condições: submatriz juntada 
void juntar(int **m1, int **mPrinc, int inicio1, int inicio2, int size){
	int i1, i2, j1, j2;
	for (i1 = 0, i2 = inicio1; i1 < size; i1++, i2++){
		for (j1 = 0, j2 = inicio2; j1 < size; j1++, j2++){
			mPrinc[i2][j2] = m1[i1][j1];
		}
	}
}

//Faz impressão da matriz
//Entrada: matrizes a ser impressa, ordem
//Retorno: nenhum
//Pré-Condições: matrizes existe e não nulo
//Pós-Condições: matriz impresso
void print(int **m, int n){
	int i, j;
	for (i = 0; i < n; i++){ 									
		for (j = 0; j < n; j++){ 				
			printf("%d ", m[i][j]); 		
		}
		printf("\n");
	} 
}

//Escolha de qual tipo de multiplicação utilizar
//Faz alocação de memória das matrizes
//Faz leitura de arquivo
//Entrada: nenhum
//Retorno: nenhum
//Pré-Condições: nenhuma
//Pós-Condições: resultado da matriz multiplicada
void mult(){
	char nome[30];
    int n, **ma, **mb, **mc, esc;
	clock_t start, end;

	FILE *f;
	printf("Digite o nome do arquivo: ");
	scanf("%[^\n]%*c", &nome);
	fflush(stdin);

	if ((f = fopen(nome, "r")) == NULL){
		printf("Erro ao Abrir o Arquivo!\n");
		system("pause");
	}
	else{
		fscanf(f, "%d", &n);

		ma = alocaMatriz(n);
		mb = alocaMatriz(n);
		mc = alocaMatriz(n);

		lerMatrizArq(f, ma, n);
		lerMatrizArq(f, mb, n);
	}

	system("cls");

	printf(" -------------------------------------\n");
	printf("|        Escolha uma opcao            | \n");
	printf("|                                     | \n");
	printf("|   0 - Tela inicial                  | \n");
	printf("|   1 - Multiplicacao de matrizes     | \n");
	printf("|   2 - Algoritmo de Straussen        | \n");
	printf("|                                     | \n");
	printf(" -------------------------------------\n");

	scanf("%d", &esc);
	while(esc){
		switch(esc){
			case 1:
            printf("Iniciando produto de matrizes ... \n");
            printf("Ordem da matriz = %d\n", n);
			start = clock();
			mult_matrizes(ma, mb, mc, n);
			end = clock();
			printf("Tempo:%lf\n",((double)(end - start)) / CLOCKS_PER_SEC);
			print(mc, n);
			system("pause");
			break;
			case 2:
            printf("Iniciando algoritmo de strassen ... \n");
            printf("Ordem da matriz = %d\n", n);
			start = clock();
			alg_Strassen(ma, mb, mc, n);
			end = clock();
			printf("Tempo:%lf\n",((double)(end - start)) / CLOCKS_PER_SEC);
			print(mc, n);
			system("pause");
			break;
			case 0:
            menu();
			break;
		}

		system("cls");
		printf(" -------------------------------------\n");
		printf("|        Escolha uma opcao            | \n");
		printf("|                                     | \n");
		printf("|   0 - Tela inicial                  | \n");
		printf("|   1 - Multiplicacao de matrizes     | \n");
		printf("|   2 - Algoritmo de Straussen        | \n");
		printf("|                                     | \n");
		printf(" -------------------------------------\n");
		
		scanf("%d", &esc);
		fflush(stdin);
	}

	free(ma);
	free(mb);
	free(mc);

	fclose(f);
}
