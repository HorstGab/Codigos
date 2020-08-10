#include "pessoa.h"


Pessoa::Pessoa(char* nome, Pessoa* pai, Pessoa* mae){
    this->nome = (char*)malloc(strlen(nome)+1);
    strcpy(this->nome, nome);
    this->pai = NULL;
    this->mae = NULL;
}

Pessoa::Pessoa(char* nome){
    this->nome = (char*)malloc(strlen(nome)+1);
    strcpy(this->nome, nome);
    this->pai = pai;
    this->mae = mae;

}

void mostrar (char *tipo, char *espaco){
    cout << espaco << tipo << this->nome << endl;

    char *e = (char*)malloc(strlen(espaco)+1);
    strcpy (e, espaco);
    strcat(e, "\t");

    if(this->mae){
        this->mae->mostrar("mae: ", e);
    }
    if(this->pai){
        this->pai->mostrar("pai: ", e);
    }

    free(e);
}

char* Pessoa::getnome(){
    return this->nome;
}

Pessoa* Pessoa::getmae(){
    return this->mae;
}

bool Pessoa:: equals(Pessoa* p){
    if(p){
        if(strcmp(this->nome, p->getnome()==0)){
          if(this->mae != NULL && p->getmae() != NULL)
           return (this->mae->equals(p->getmae()));
          if(this->mae == NULL && p->getmae() == NULL)
              return true;
         }
      }
    return false;

}

bool Pessoa::antecessor(Pessoa* p){
    bool b_ret = false;
    if(p){
        if(this->mae){
            if(this->equals(p))
                return true;
            else
                b_ret = mae->antecessor(p);
        }
        if(b_ret) return true;

        if(this->pai({
            if (this->pai->equals(p)){
                b_ret = true;
            }else{
                b_ret = pai->antecessor(p);
            }
        }

    return b_ret;
}


Pessoa::~Pessoa(){
    cout<< "Destruindo Pessoa" << this->nome <<endl;
    free(this->nome);

    if(this->mae) delete this->mae;
    if(this->pai) delete this->pai;
}



