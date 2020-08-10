#ifndef AVL_H
#define AVL_H


class AVL {
private:
    int n;
    AVL *esq;
    AVL *dir;

    AVL( int n);
public:
    static void insere ( AVL **r, int n );
    void mostrar();
    ~AVL();
};

#endif // AVL_H
