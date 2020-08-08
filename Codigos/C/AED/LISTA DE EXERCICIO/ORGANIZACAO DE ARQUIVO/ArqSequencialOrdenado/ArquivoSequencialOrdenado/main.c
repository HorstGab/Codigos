#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct cliente {
    char nome[50];
    int idade;
    char endereco[100];
    char cidade[50];
    char CEP[11];
    char telefone[11];
    char CPF[20];
};

struct transacao{
    char opeFlag;
    struct cliente* dados;
};

struct transacao* lerDados(char* nome, int idade, char* endereco, char* cidade, char* CEP, char* telefone,
                         char* CPF);
struct transacao* ordena(FILE* arquivo, char *fileName);
void printarDados (struct transacao *registro);
FILE* salvarDados (struct transacao *registro, FILE* arquivo, char* fileName);
void merge(char **vet, int inicio, int meio, int fim);
void Intercala(char* array ,int e, int m, int d);
void MergeSortChar(char **vet, int inicio, int fim);


int main(void)
{
    struct transacao* registro = lerDados("Gabriel Horst Montoanelli", 20, "Rua Geraldino Manoel (369)", "Foz do Iguacu",
                                        "85853-390", "3523-7438", "369.106.413-89");
    struct transacao* registro1 = lerDados("Iraci Horst", 60, "Rua Geraldino Manoel (369)", "Foz do Iguacu",
                                        "85853-390", "3523-7438", "000.001.005-58");
    struct transacao* registro2 = lerDados("Jose aloizio Montoanelli", 58, "Rua Geraldino Manoel (369)", "Foz do Iguacu",
                                        "85853-390", "3523-7438", "516.154.125-58");
    struct transacao* registro3 = lerDados("Carla Horst", 38, "Avenida das cataratas(159)", "Foz do Iguacu",
                                        "85854-120", "3526-7845", "000.004.157-57");
    FILE* arqMestre = NULL;
    FILE* arqTransacao = NULL;
    printarDados(registro);
    printarDados(registro1);
    printarDados(registro2);
    printarDados(registro3);

    arqTransacao = salvarDados(registro, arqTransacao, "arqTransacao.txt");
    arqTransacao = salvarDados(registro1, arqTransacao, "arqTransacao.txt");
    arqTransacao = salvarDados(registro2, arqTransacao, "arqTransacao.txt");
    arqTransacao = salvarDados(registro3, arqTransacao, "arqTransacao.txt");
    fclose(arqTransacao);
    return 0;
}

struct transacao *lerDados(char *nome, int idade, char *endereco, char *cidade, char *CEP, char *telefone,
                          char *CPF){

    struct transacao* novoRegistro = (struct transacao*)malloc(sizeof(struct transacao));
    novoRegistro->dados = (struct cliente*)malloc(sizeof(struct cliente));

    strcpy(novoRegistro->dados->nome,nome);
    novoRegistro->dados->idade = idade;
    strcpy(novoRegistro->dados->endereco, endereco);
    strcpy(novoRegistro->dados->cidade, cidade);
    strcpy(novoRegistro->dados->CEP, CEP);
    strcpy(novoRegistro->dados->telefone, telefone);
    strcpy(novoRegistro->dados->CPF, CPF);
    novoRegistro->opeFlag = 'I';

    return novoRegistro;
}

void printarDados (struct transacao* registro){

    if(registro){
        printf("------------------------------------\n");
        printf("Nome: %s\n", registro->dados->nome);
        printf("------------------------------------\n");
        printf("Idade: %d\n", registro->dados->idade);
        printf("Endereco: %s\n", registro->dados->endereco);
        printf("Cidade: %s\n", registro->dados->cidade);
        printf("CEP: %s\n", registro->dados->CEP);
        printf("Telefone: %s\n", registro->dados->telefone);
        printf("CPF: %s\n", registro->dados->CPF);
        printf("Flag: %c\n",  registro->opeFlag);
        printf("------------------------------------\n");

    }else{
        printf("Registro vazio!\n");
    }
}

FILE* salvarDados(struct transacao *registro,  FILE* arquivo, char* fileName){
    arquivo = fopen(fileName, "a+");

    if(arquivo){

        fprintf(arquivo,  " %s |", registro->dados->nome);
        fprintf(arquivo,  " %d |", registro->dados->idade);
        fprintf(arquivo,  " %s |", registro->dados->endereco);
        fprintf(arquivo,  " %s |", registro->dados->cidade);
        fprintf(arquivo,  " %s |", registro->dados->CEP);
        fprintf(arquivo,  " %s |", registro->dados->telefone);
        fprintf(arquivo,  " %s |", registro->dados->CPF);
        fprintf(arquivo,  " %c\n", registro->opeFlag);
    }else{
        printf("Erro ao abrir o arquivo!\n");
    }

    return arquivo;
}

struct transacao* ordena(FILE *arquivo, char* fileName){
    arquivo = fopen(fileName, "r+");

    struct transacao **dados = (struct transacao**)malloc(sizeof(struct transacao*));
    int i = 0;
    if(f){
        while(!feof(arquivo)){
            dados = (struct transacao*)malloc(sizeof(struct transacao));
            fscanf("%s | %d | %s |  %s |  %s |  %s |  %s | %c\n",
                   dados[i]->dados->nome,
                   dados[i]->dados->idade,
                   dados[i]->dados->endereco,
                   dados[i]->dados->cidade,
                   dados[i]->dados->CEP,
                   dados[i]->dados->telefone,
                   dados[i]->dados->CPF,
                   dados[i]->opeFlag);
            i++;
        }
    }else{
        printf("Erro ao abrir o arquivo!\n");
    }

//    MergeSortChar(,0,i);

}

void merge(char **vet, int inicio, int meio, int fim){
    int esq, m, k = 0;
        char **aux;

        //aloca o auxili
        aux = (char**)malloc((fim-inicio)*sizeof(char*));
        esq = inicio;
        m = meio;

        //enquanto esquerda for menor que o meio e o meio menor que o fim
        while(esq < meio && m < fim){

            // comparar se vet[esq] eh menor ou igual a vet[m]
            if(strcmp(vet[esq],vet[m]) <= 0)
                aux[k++] = vet[esq++];
            else
                aux[k++]=vet[m++];
        }

        //enquanto esquerda for menor que o meio
        while(esq < meio) aux[k++] = vet[esq++];
        //enquanto o meio for menor que
        while(m < fim) aux[k++] =vet[m++];

        for(esq = inicio; esq < fim; esq++){
            vet[esq] = aux[esq-inicio];
        }

        //libera o auxiliar
        free(aux);
}

void MergeSortChar(char **vet, int inicio, int fim)
{
    //se inicio for menor que o final
    if(inicio < fim - 1){
        //pega o meio do vetor
        int meio = (inicio + fim)/2;

        MergeSortChar(vet, inicio, meio);
        MergeSortChar(vet, meio, fim);
        MergeChar(vet, inicio, meio, fim);
    }
}
