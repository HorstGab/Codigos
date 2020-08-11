#ifndef NUMERO
#define NUMERO

#include <iostream>
using namespace std;

class numero{
private:
	int n;
	numero *esq;
	numero *dir;
public:
	numero();

	static void insere (numero **r);
	void mostrar();
	~numero();
	
};

#endif //NUMERO