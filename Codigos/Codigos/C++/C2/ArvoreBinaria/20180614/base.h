#ifndef BASE_H
#define BASE_H


class Base {
protected:
    double valor;
    Base *esq;
    Base *dir;

    Base( ) ;

private:
    static Base * montaExpressaoRec ( );
    void setEsq ( Base *esq );
    void setDir ( Base *dir );

public:
    static Base * montaExpressaoPrefix ( char *expressao );
    virtual void imprimeNome() = 0;
    virtual double processa () = 0;
    virtual void infix (); // in orden
    virtual void prefix();
    virtual void posfix();

    virtual ~Base();

};

#endif // BASE_H


