#include <stdio.h>

void converteBinario(int bin[],int num);
void mostrar (int bin[]);

int main(int argc, char const *argv[]){
	int num = 0;
	int bin[32] = {0};

	scanf("%d", &num);
	while(num != -1){
		converteBinario(bin, num);
		mostrar(bin);
		scanf("%d", &num);
	}
	return 0;
}

void converteBinario(int bin[],int num){
	int i;

	for(i = 0; i < 32; i++){
		bin[i] = num%2;
		num = num/2;
	}
}

void mostrar (int bin[]){
	int i;
	int aux = 0;

	for(i = 32; i >= 0; --i){
		printf("%d", bin[i]);
		if(bin[i] == 1) aux++;
	}

	printf(" = [%d]\n\n", aux);
}

