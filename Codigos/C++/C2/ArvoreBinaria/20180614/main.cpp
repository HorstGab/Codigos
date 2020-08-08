#include <iostream>

using namespace std;

#include "base.h"
#include "erro.h"

int main() {
    char str[100];
    int n;
    cout << "Informe o número de expressoes: ";
    cin >> n;

    for (int i=0; i<n; i++) {
        fflush(stdin);
        fgets(str,100,stdin);
        Base *r = Base::montaExpressaoPrefix( str );
        try {
            cout << r->processa() << endl;
            r->prefix(); cout << endl;
            r->infix(); cout << endl;
            r->posfix(); cout << endl;
        } catch ( DivisaoPorZero ex ) {
            cout << ex.what() << endl;
        }
        delete r;
    }

    return 0;
}
