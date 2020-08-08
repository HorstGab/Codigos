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

struct cliente* lerDados(char* nome, int idade, char* endereco, char* cidade, char* CEP, char* telefone,
                         char* CPF);
void printarDados (struct cliente* registro);
FILE* salvarDados (struct cliente* registro, FILE* arquivoSequencial);
int main(void)
{
    struct cliente* registro = lerDados("Gabriel Horst Montoanelli", 20, "Rua Geraldino Manoel (369)", "Foz do Iguacu",
                                        "85853-390", "3523-7438", "369.106.413-89");
    struct cliente* registro1 = lerDados("Iraci Horst", 60, "Rua Geraldino Manoel (369)", "Foz do Iguacu",
                                        "85853-390", "3523-7438", "000.001.005-58");
    struct cliente* registro2 = lerDados("Jose aloizio Montoanelli", 58, "Rua Geraldino Manoel (369)", "Foz do Iguacu",
                                        "85853-390", "3523-7438", "516154,125-58");
    struct cliente* registro3 = lerDados("Carla Horst", 38, "Avenida das cataratas(159)", "Foz do Iguacu",
                                        "85854-120", "3526-7845", "000,004,157-57");
    FILE* arqSequencial = NULL;
    printarDados(registro);
    printarDados(registro1);
    printarDados(registro2);
    printarDados(registro3);

    arqSequencial = salvarDados(registro, arqSequencial);
    fclose(arqSequencial);
    arqSequencial = salvarDados(registro1, arqSequencial);
    fclose(arqSequencial);
    arqSequencial = salvarDados(registro2, arqSequencial);
    fclose(arqSequencial);
    arqSequencial = salvarDados(registro3, arqSequencial);
    fclose(arqSequencial);
    return 0;
}

struct cliente* lerDados (char *nome, int idade, char *endereco, char *cidade, char *CEP, char *telefone, char *CPF){

    struct cliente* novoRegistro = (struct cliente*)malloc(sizeof(struct cliente));

    strcpy(novoRegistro->nome,nome);
    novoRegistro->idade = idade;
    strcpy(novoRegistro->endereco, endereco);
    strcpy(novoRegistro->cidade, cidade);
    strcpy(novoRegistro->CEP, CEP);
    strcpy(novoRegistro->telefone, telefone);
    strcpy(novoRegistro->CPF, CPF);

    return novoRegistro;
}

void printarDados (struct cliente* registro){

    if(registro){
        printf("------------------------------------\n");
        printf("Nome: %s\n", registro->nome);
        printf("Idade: %d\n", registro->idade);
        printf("Endereco: %s\n", registro->endereco);
        printf("Cidade: %s\n", registro->cidade);
        printf("CEP: %s\n", registro->CEP);
        printf("Telefone: %s\n", registro->telefone);
        printf("CPF: %s\n", registro->CPF);
        printf("------------------------------------\n");

    }else{
        printf("Registro vazio!\n");
    }
}

FILE* salvarDados(struct cliente *registro,  FILE* arquivoSequencial){
    arquivoSequencial = fopen("arquivoSequencial.txt", "a+");

    if(arquivoSequencial){

        fprintf(arquivoSequencial,  " %s", registro->nome);
        fprintf(arquivoSequencial,  " %d", registro->idade);
        fprintf(arquivoSequencial,  " %s", registro->endereco);
        fprintf(arquivoSequencial,  " %s", registro->cidade);
        fprintf(arquivoSequencial,  " %s", registro->CEP);
        fprintf(arquivoSequencial,  " %s", registro->telefone);
        fprintf(arquivoSequencial,  " %s\n", registro->CPF);
    }else{
        printf("Erro ao abrir o arquivo sequencial!\n");
    }

    return arquivoSequencial;
}
