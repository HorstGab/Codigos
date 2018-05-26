#ifndef PESSOA_H
#define PESSOA_H


class Pessoa{
protected:
    friend ostream &operator<< (ostream &output, Pessoa &p);
    int idpessoa;
    char* nome;
public:
    Pessoa(int idpessoa, char* nome);
};

#endif // PESSOA_H
