#ifndef MODELMEDICO_H
#define MODELMEDICO_H

typedef struct {
    int codigo;
    char* nome;
    char sexo;
    char* CPF;
    int CRM;
    char* especialidade;
    char* RG;
    char* telefone;
    char* celular;
    char* email;
    char* endereco;
    char* dataNasc;
}registro;

#endif // MODELMEDICO_H

