#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

class data{
private:
    int dia;
    int mes;
    int ano;
public:
    data();
    data(int dia, int mes, int ano);

    int getDia();
    int getMes();
    int getAno();

    void setDia(int dia);
    void setMes(int mes);
    void setAno(int ano);

    void diferenca(data *Data);
    bool bissexto(data *Data);

    ~data();
};

#endif // DATA_H
