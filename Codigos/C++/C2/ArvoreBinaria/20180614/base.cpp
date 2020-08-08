#include "base.h"

#include <iostream>
using namespace std;

#include "lex.h"
#include "numero.h"
#include "soma.h"
#include "subtracao.h"
#include "multiplicacao.h"
#include "divisao.h"

Base::Base() {
    this->valor=0;
    this->dir=0;
    this->esq=0;
}

Base * Base::montaExpressaoPrefix ( char *expressao) {
    start_lex(expressao);

    return montaExpressaoRec() ;
}

Base * Base::montaExpressaoRec ( ) {
    Base *b=0;
    get_next_token ();
    if (Token.classe != EOF) {
        switch ( Token.classe )  {
        case '+': b = new Soma (); break;
        case '-': b = new Subtracao (); break;
        case '*': b = new Multiplicacao (); break;
        case '/': b = new Divisao (); break;
        case IDENTIFIER :
            cout << "IDENTIFIER" << endl; break;
        case INTEGER: return new Numero( Token.repr );
        }

        b->setEsq( montaExpressaoRec () );
        b->setDir( montaExpressaoRec () );
    }
    return b;
}

void Base::setEsq ( Base *esq ) {
    this->esq = esq;
}

void Base::setDir ( Base *dir ) {
    this->dir = dir;
}

void Base::infix () {
    cout << " (" ;
    if (this->esq) esq->infix();
    this->imprimeNome();
    if (this->dir) dir->infix();
    cout << " )";
}

void Base::prefix() {
    this->imprimeNome();
    if (this->esq) esq->prefix();
    if (this->dir) dir->prefix();
}

void Base::posfix() {
    if (this->esq) esq->posfix();
    if (this->dir) dir->posfix();
    this->imprimeNome();
}

Base::~Base () {
    //cout << "Eliminando node" << endl;
    if (this->esq) delete this->esq;
    if (this->dir) delete this->dir;
}
