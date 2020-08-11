#ifndef ARQUIVO_H
#define ARQUIVO_H

#include<iostream>
#include<vector>
#include"automatos.h"
#include"estados.h"

using namespace std;

class Arquivo
{
public:

    /**
     * @brief lerAlfabeto, le o alfabeto
     * @param automato
     * @param arq
     * Pré-condição: automato e arquivo existente
     * Pós-condição: alfabeto lido
     */
    static void lerAlfabeto(Automatos *automato, FILE *arq);

    /**
     * @brief lerEstado, le os estados
     * @param automato
     * @param arq
     * Pré-condição: automato e arquivo existente
     * Pós-condição: estado lido
     */
    static void lerEstado (Automatos *automato, FILE *arq);

    /**
     * @brief lerEstadoFinal, le o estado final
     * @param automato
     * @param arq
     * Pré-condição: arquivo e automato existente
     * Pós-condição: estado lido
     */
    static void lerEstadoFinal(Automatos *automato, FILE *arq);

    /**
     * @brief lerEstadoInicial, le o estado inicial
     * @param automato
     * @param arq
     * Pré-condição: automato e arquivo existente
     * Pós-condição: estados iniciais lidos
     */
    static void lerEstadoInicial(Automatos *automato, FILE *arq);

    /**
     * @brief lerTransicao, le as trasições
     * @param automato
     * @param arq
     * Pré-condição: arquivo e automato existente
     * Pós-condição: trasições lidas e salvas
     */
    static void lerTransicao(Automatos *automato, FILE *arq);

    /**
     * @brief inicializarAutomato, abre o arquivo e le todos os dados que compõe o automato
     * @param automato
     * @param nomeArquivo
     * Pré-condição: automato e arquivo existente
     * Pós-condição: arquivo aberto sem erros e automato setado
     */
    static void inicializarAutomato(Automatos *automato, const char *nomeArquivo);
};

#endif // ARQUIVO_H

