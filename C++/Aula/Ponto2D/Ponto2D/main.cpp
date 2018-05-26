#include <iostream>

using namespace std;

#include "ponto2d.h"
#include "reta.h"
int main()
{
   Reta *r1 =
   ponto2d *p1 = new ponto2d(10,10);
   ponto2d *p2 = p1->clone();

   p2 -> move();

   cout << "Iguais: " << p1->equals(p2) << endl;

   delete p1;
   delete p2;

    return 0;
}


