#include <stdio.h>
#include <stdlib.h>


void menu();
void lerGauss(int **A, int *b, int *n);
void gauss(int **A, int *b, int n);

int main(void)
{



    menu();

    return 0;
}

void menu(){
    int op;


    printf("\t\t\t\t----------------------------------------\n");
    printf("\t\t\t\t|                                      |\n");
    printf("\t\t\t\t|    Resolucao de Sistemas Lineares    |\n");
    printf("\t\t\t\t|                                      |\n");
    printf("\t\t\t\t|                                      |\n");
    printf("\t\t\t\t----------------------------------------\n");

    printf("\t\t\t\t 1. Eliminacao de Gauss\n");
    printf("\t\t\t\t 2. Fatoracao LU\n");
    printf("\t\t\t\t 3. Fatoracao de Cholesky\n");
    printf("\t\t\t\t 4. Gauss-Jacobi\n");
    printf("\t\t\t\t 5. Gauss-Seidel\n");
    printf("\t\t\t\t 6. Sair\n");

    printf("\t\t\t\t    ");
    scanf("%d", &op);

    system("CLS");

    int **A = (int**)malloc(sizeof(int*));
    int *b = (int*)malloc(sizeof(int));
    int n;

    switch (op) {
    case 1:
        gauss(A, b, n);
        lerGauss(A, b, &n);
        break;
    case 2:
//        fatoracaoLU();
        break;
    case 3:
//        cholesky();
        break;
    case 4:
//        gaussJacobi();
        break;
    case 5:
//        gaussSeidel();
        break;
    default:
        break;
    }
}

void gauss(int **A, int *b, int n){
    int k, i, j;
    int pivo;

    for(k = 1; k < n - 1; k++){
        for(i = k +1; i == n; i++){
            pivo = (A[i][k]/A[k][k]);
            A[i][k] = 0;
            for(j = k + 1; j == n; j++){
                A[i][j] = A[i][j] - (pivo*A[k][j]);
                b[i] = b[i] - (pivo*b[k]);
            }
        }
    }
}

void lerGauss(int **A, int *b, int *n){
    int i, j;

    printf("Tamanho da Matriz: ");
    scanf("%d", n);
    printf("Digite a matriz: ");
    for(i = 0; i < *n; i++){
        for(j = 0; j < *n; j++){
            scanf("%d", &A[i][j]);
        }
    }

    printf("Digite o vetor: ");
    for(i = 0; i < *n; i++){
        scanf("%d", &b[i]);
    }
}
