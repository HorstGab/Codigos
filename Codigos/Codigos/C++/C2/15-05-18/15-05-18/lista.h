#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <stdlib.h>

using namespace std;

template <class T>
class Lista {
private:
    class Node{
    private:
        T* t;
        Node *next; //< jasjaklsjs
    public:
        Node( const T& t, Node *next=NULL) {
            this->t = new T(t);
            this->next = next;
        }

        void  show() {
            cout << getT() << endl;
            if (next) next->show();

        }

        void  insereFinal (Node *node) {
            if (next)
                next->insereFinal(node);
            else
                next = node;
        }

        Node* insereOrdenado( Node* node) {
            if ( this->getT() > node->getT()) {
                node->setNext(this);
                return node;
            }else{
                if(next){
                    next = next->insereOrdenado( node);
                }else{
                    next = node;
                }
                return this;
            }
        }

        void setNext(Node *node) {
            this->next = node;
        }

        T &getT() {
            return (*this->t);
        }

        ~Node() {
            //cout << "Destruindo node " << getT() << endl;
            delete t;
            if (next) {
                delete next;
            }
        }
    };

    Node *H;
public:
    /**
     * @brief Lista
     */
    Lista() {
        this->H = NULL;
    }

    /**
     * @brief Lista
     * @param info
     */
    Lista(T info) {
        this->H = new Node(info);
    }

    void InsereFinal( const T &t){
        if(H == NULL){
            H = new Node(t);
        }else{
            H->insereFinal(new Node(t));
        }
    }

    void Mostra(){
        if (H) {
            H->show();
        }
    }

    void InsereInicio(const T  &t){
        H = new Node(t, H);
    }

    void InsereOrdenado(const T & t){
        if(H != NULL){
            //H->insereOrdenado(&H,new Node(t));
            H = H->insereOrdenado(new Node(t));
        } else {
            H = new Node(t);
        }
    }

    void InsereOrdenado(T * t){
        if(H != NULL){
            H->insereOrdenado(&H,new Node(t));
            //H = H->insereOrdenado(new Node(info));
        } else {
            H = new Node(t);
        }
    }
    ~Lista() {
        cout << "Destruindo a lista" << endl;
        if (H) delete H;
    }
};


#endif // LISTA_H
