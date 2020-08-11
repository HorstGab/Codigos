#include "main.h"

/**
 * @brief main
 * @param nenhum
 * @return 0 caso ocorreu sucesso
 * @pre nenhuma
 * @post nenhuma
 */
int main(int argc, char const *argv[])
{
    int tam = 10;
    int *vet = NULL;
    char **v = NULL;
    Arg cmd = inicializar(cmd);

    //se possui argumentos
    if(argc > 1){

        //le os argumentos na struct
        cmdMain(argv, &cmd);
        //gerencia os comandos
        cmdOrdenacao(&vet, v, &tam, cmd);
    }

    return 0;
}

/**
 * @brief inicializar
 * @param cmd
 * @return struct zerada
 * @pre nenhuma
 * @post nenhuma
 */
Arg inicializar(Arg cmd)
{
    //seta os atributos com 0
    cmd.tipo[0] = '\0';
    cmd.qnt = 0;
    cmd.ordem[0] = '\0';
    cmd.input[0] = '\0';
    cmd.output[0] = '\0';
    return cmd;
}

/**
 * @brief isN
 * @param tipo
 * @return 1 se for N e 0 caso ocntrario
 * @pre nenhuma
 * @post nenhuma
 */
int isN(char *tipo)
{
    //retorna verdadeiro se for N ou n
    return (!strcmp(tipo, "N") || !strcmp(tipo, "n"));
}


/**
 * @brief isC
 * @param tipo
 * @return 1 se for C e 0 caso ocntrario
 * @pre nenhuma
 * @post nenhuma
 */
int isC(char *tipo)
{
    //retorna verdadeiro se for C ou c
    return (!strcmp(tipo, "C")||!strcmp(tipo, "c"));
}


/**
 * @brief cmdMain
 * @param argv
 * @param cmd
 * @pre  nenhuma
 * @post struct preenchida
 */
void cmdMain(const char *argv[], Arg *cmd)
{
    //copia o argumento 2 para a struct
    strcpy(cmd->tipo, argv[1]);

    //testa o tipo
    //se for N
    if(isN(cmd->tipo)){

        //o segundo argumento recebe um numero
        cmd->qnt = atoi(argv[2]);

    }else{

        //senao recebe o arquivo de entrada
        strcpy(cmd->input, argv[2]);
    }

    //se tiver o 3 e 4 argumento
    if(argv[3] && argv[4]){

        //copia na struct
        strcpy(cmd->ordem, argv[3]);
        strcpy(cmd->output, argv[4]);
    }
}


/**
 * @brief cmdOrdenacao
 * @param vet
 * @param v
 * @param tam
 * @param cmd
 * @pre nenhuma
 * @post nenhuma
 */
void cmdOrdenacao(int **vet, char **v, int *tam, Arg cmd)
{

    //se for N
    if(isN(cmd.tipo)){
        //recebe o valor de tamanho
        *tam = cmd.qnt;
        //faz um random
        Rand(vet, *tam);
        //se tiver arquivo de saida e sort
        if(cmd.output[0] && cmd.ordem[0]){
            //ordena e escreve no arquivo de saida
           sortNumerico(*vet, *tam, cmd.ordem);
           escreveSaidaInt(*vet, *tam, cmd.output);
        }else{
            //senao testa o tempo de todos os sorts
            clockNumerico(*vet, *tam);
        }
    }

    //se for C
    if(isC(cmd.tipo)){
        //se existir arquivo de saida e sort
        //le o vetor de strings
        v = lerEntrada(tam, cmd.input);
        if(cmd.output[0]&&cmd.ordem){

            //ordena o vetor
            sortChar(v, *tam, cmd.ordem);
            //escreve no arquivo de saida
            escreverSaidaChar(v, *tam, cmd.output);

        }else{
            //senao testa o tempo de todos os sorts
            clockChar(v, *tam);
        }
    }
    //libera o vetor
    free(vet);
    free(v);

}


/**
 * @brief Rand
 * @param vet
 * @param tam
 * @pre nenhuma
 * @post vetor preenchido com valores aleatorios
 */
void Rand(int **vet, int tam)
{
    int i;
    srand(time(NULL));

    //aloca o vetor
    (*vet) = (int*)malloc((tam)*sizeof(int));

    //atribui os valores do vetor com rand
    for(i = 0; i < tam; i++){
        (*vet)[i] = rand();
    }
}


/**
 * @brief escreveSaidaInt
 * @param vet
 * @param tam
 * @param output
 * @pre nenhuma
 * @post vetor escrito no arquivo
 */
void escreveSaidaInt(int *vet, int tam, char *output)
{
    FILE* file;
    int i;

    //abre o arquivo para escrita
    if((file = fopen(output, "w+"))){
        //percorre o vetor
        for(i = 0; i < tam; i++){
            //e escreve no arquivo
            fprintf(file, "vetor[%d] = %d\n", i, vet[i]);
        }
    }else{
        //senao mostra uma mensagem de erro
        printf("%s\n", strerror(errno));
    }

    //fecha o arquivo
    fclose(file);
}



/**
 * @brief lerEntrada
 * @param tam
 * @param input
 * @return matriz preenchida
 * @pre nenhuma
 * @post nenhuma
 */
char **lerEntrada(int *tam, char *input)
{
    FILE* file;
    char str[256];
    char** vetAux;
    int i;

    //abre o arquivo para leitura
    if((file = fopen(input, "r+"))){
        //aloca a matriz
        vetAux = (char**)malloc((*tam)*sizeof(char*));

        //enquanto não for final de arquivo
        for(i = 0; !feof(file); ++i){
            //se chegar no final da capacidade da matriz
            if(i+1 > *tam){
                //dobra o tamanho
                *tam *= 2;
                //e realoca
                vetAux = (char**)realloc(vetAux, (*tam)*sizeof(char*));
            }
            //le a cadeia de char do arquivo na string auxiliar
            fscanf(file, " %s", str);
            //copia a string auxiliar para a matriz
            vetAux[i] = strcpy(malloc(sizeof(char)*strlen(str)+1), str);

        }

        //tamanho recebe o numero de iteracoes
        (*tam) = i;
        //realoca com o tamanho final
        vetAux = (char**)realloc(vetAux,(*tam)*sizeof(char*));
    }else{
        //se nao abrir de uma mensagem de erro
        printf("%s\n", strerror(errno));
    }

    //fecha o arquivo
    fclose(file);
    //retorna a matriz;
    return vetAux;
}


/**
 * @brief escreverSaidaChar
 * @param v
 * @param tam
 * @param output
 * @pre nenhuma
 * @post vetor escrito no arquivo
 */
void escreverSaidaChar(char *v[], int tam, char *output)
{
    FILE* file;
    int i;

    //abre o arquivo para escrita
    if((file = fopen(output, "w+"))){
        //percorre o vetor
        for(i = 0; i < tam; i++){
            //e escreve no arquivo
            fprintf(file, "%s\n", v[i]);
        }
    }else{
        //senao mostra uma mensagem de erro
        printf("%s\n", strerror(errno));
    }

    //fecha o arquivo
    fclose(file);
}








