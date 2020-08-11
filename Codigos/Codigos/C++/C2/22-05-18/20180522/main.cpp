#include <iostream>

#include <exception>

using namespace std;

class DivisaoPorZero {
private:
    const char *message;
public:
    DivisaoPorZero () : message ("Divisao por zero") {}
    const char *what() const { return message; }
};

double divide ( int numerador, int denominador ) {
    if (denominador==0)
        throw DivisaoPorZero();

    return (double)numerador/(double)denominador;
}



int main( )
{
    int numerador=1, denominador;
    while (numerador!=0) {
        cout << "Numerador: ";
        cin >> numerador;

        cout << "Denominador: ";
        cin >> denominador;

        try {
            cout << divide(numerador, denominador) << endl;
        } catch ( DivisaoPorZero ex ) {
           cout << ex.what() << endl;
        }
    }




    return 0;
}
