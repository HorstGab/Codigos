#ifndef ARQUIVOINVERTIDO_H
#define ARQUIVOINVERTIDO_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	///numero do arquivo
    int arquivo;
    ///quantidade de palavras
    int quantidadePalavras;
    ///posicao do registro
    int posicao;
    ///posicao do proximo registro
    int proxPosicao;
}arqInv;

typedef struct{
	///posicao do topo
    int topPosicao;
}headerArqInv;

/**
 * cria o header para o arquivo invertido,
 * @param file, arquivo a ser manipulado
 * Pre-condicao: funcao auxiliar writeHeaderArquivoInvertido
 * Pos-condicao: nenhuma
 */
void criarHeaderArquivoInvertido(FILE* file);

/**
 * crir o Arquivo Invertido, e inicializa os campos
 * @return o novo arquivo invertido criado
 * Pre-condicao: nenhuma
 * Pos-condicao: nenhuma
 */
arqInv* criarArquivoInvertido();

/**
 * escreve o cabeçalho no Arquivo Invertido
 * @param file, arquivo que vai escrever
 * @param header, cabeçalho
 * Pre-condicao: nenhuma
 * Pos-condicao: nenhuma
 */
void writeHeaderArquivoInvertido(FILE* file, headerArqInv* header);

/**
 * escreve Arquivo Invertido
 * @param file, arquivo a ser manipulado
 * @param header, cabeçalho
 * @param arq, nome do arquivo invertido
 * @return posicao
 * Pre-condicao: nenhuma
 * Pos-condicao: nenhuma
 */
int writeArquivoInvertido(FILE* file, headerArqInv* header, arqInv* arq);

/**
 * le o inicio (cabecalho) do Arquivo Invertido
 * @param file, arquivo que vai ser lido
 * @return o inicio do arquivo
 * Pre-condicao: nenhuma
 * Pos-condicao: nenhuma
 */
headerArqInv* readHeaderArquivoInvertido(FILE* file);

/**
 * le Arquivo Invertido
 * @param file, arquivo que vai ser lido
 * @param posicao, posicao do arquivo
 * @return o arquvo lido
 * Pre-condicao: nenhuma
 * Pos-condicao: nenhuma
 */
arqInv* readArquivoInvertido(FILE *file, int posicao);

/**
 * imprime o inicio do arquivo
 * @param header, cabecalho
 * Pre-condicao: nenhuma
 * Pos-condicao: nenhuma
 */
void showheader(headerArqInv* header);

/**
 * imprime o Arquivo Inverso
 * @param arq, arquivo inverso a que sera impresso
 * Pre-condicao: nenhuma
 * Pos-condicao: nenhuma
 */
void showArquivoInverso(arqInv* arq);


#endif // ARQUIVOINVERTIDO_H


