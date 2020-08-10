#include "stdio.h"
#include "stdlib.h"
#include "ctype.h"
#include "string.h"

int lerArquivo();
FILE* openFile(char* fileName);
char **lerEntrada(FILE* file);

int main(int argc, char const *argv[])
{
	lerArquivo();
	return 0;
}

int lerArquivo (){

	//leitura do nome do arquivo
	char* fileName = (char*)malloc(sizeof(char)*100);
	printf("Digite o nome do Arquivo: ");
	scanf("%[^\n]%*c", fileName);
	
	//abrir arquivo
	FILE* file = openFile(fileName);

	char** instrucoes = lerEntrada(file);

	printf("%s\n", instrucoes[0]);

	fclose(file);
	free(fileName);
	return 1;
}

FILE* openFile(char* fileName){
	printf("%s\n", fileName);
	FILE* file;
	if(!(file = fopen(fileName, "r+"))){
		printf("Erro na abertura do arquivo!");
		return NULL;
	}
	return file;
}

char **lerEntrada(FILE* file)
{
    char str[512];
    char** vetAux;
    int i, tam = 10;

        //aloca a matriz
        vetAux = (char**)malloc(tam*sizeof(char*));

        //enquanto não for final de arquivo
        for(i = 0; !feof(file); ++i){
        	printf("%d\n", i);
            //se chegar no final da capacidade da matriz
            if(i+1 > tam){
                //dobra o tamanho
                tam *= 2;
                //e realoca
                vetAux = (char**)realloc(vetAux, tam*sizeof(char*));
                printf("dobrou\n");
            }
            //le a cadeia de char do arquivo na string auxiliar
            fscanf(file, "s", str);
            //copia a string auxiliar para a matriz
            vetAux[i] = strcpy(malloc(sizeof(char)*strlen(str)+1), str);

        }

        //tamanho recebe o numero de iteracoes
        (tam) = i;
        //realoca com o tamanho final
        vetAux = (char**)realloc(vetAux,(tam)*sizeof(char*));
    

    //fecha o arquivo
    fclose(file);
    //retorna a matriz;
    return vetAux;
}