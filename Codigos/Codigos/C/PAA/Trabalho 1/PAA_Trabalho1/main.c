#include "mult_matrizes.h"
#include "knapsack.h"


//Escolha entre os dois tipos de programas
//Entrada: nenhum
//Retorno: nenhum
//Pré-Condições: nenhuma
//Pós-Condições: nenhuma
void menu(){
    int esc;
    unsigned int W;

	printf(" -------------------------------------\n");
	printf("|        Escolha uma opcao            | \n");
	printf("|                                     | \n");
	printf("|   0 - Sair                          | \n");
	printf("|   1 - Multiplicacao de matrizes     | \n");
	printf("|   2 - Problema da Mochila           | \n");
	printf("|                                     | \n");
	printf("--------------------------------------\n");

	scanf("%d", &esc);
	fflush(stdin);
	while(esc){
		switch(esc){
			case 1:
                mult();
                system("pause");
                break;
			case 2:
                loadData();
                printf("Digite a capacidade da Mochila: ");
                submenu(W);
                system("pause");
			break;
		}

		system("cls");
		printf(" -------------------------------------\n");
		printf("|        Escolha uma opcao            | \n");
		printf("|                                     | \n");
		printf("|   0 - Sair                          | \n");
		printf("|   1 - Multiplicacao de matrizes     | \n");
		printf("|   2 - Problema da Mochila           | \n");
		printf("|                                     | \n");
		printf("--------------------------------------\n");
		scanf("%d", &esc);
		fflush(stdin);
	}
    free(peso);
    free(valor);
}	

int main(){
    menu();
    return 0;
}
