#ifndef ERRO_H
#define ERRO_H


#include <exception>

using namespace std;

class DivisaoPorZero {
private:
    const char *message;
public:
    DivisaoPorZero () : message ("Divisao por zero") {}
    const char *what() const { return message; }
};

#endif // ERRO_H
