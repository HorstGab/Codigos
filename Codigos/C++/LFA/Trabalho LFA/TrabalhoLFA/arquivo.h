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
    static void lerAlfabeto(Automatos *automato, FILE *arq);
    static void lerEstado (Automatos *automato, FILE *arq);
    static void lerEstadoFinal(Automatos *automato, FILE *arq);
    static void lerEstadoInicial(Automatos *automato, FILE *arq);
    static void lerTransicao(Automatos *automato, FILE *arq);
    static void inicializarAutomato(Automatos *automato, const char *nomeArquivo);
};

#endif // ARQUIVO_H

