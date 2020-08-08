aula de C2 dia 22/05/18

		Tratamento de excecões
	O Tratamento de excecões pode ser visto como um meio de returnar o controle de uma funcão ou sair de um bloco de codigo. 
Normalmente, quando acontece uma excecão, ela deve ser tratada por um invocador da funcão que gerou a excecão.
	
	Para criar uma excecão: 
	throw "Divisão por zero";

	Como Tratar: 
	#include <exception>

	try{ 
	}catch(exception ex){
		cout << ex.what() << endl;
	}


-------/-------/------/------/-----/------

#include <iostream>
#include <exception>

using namespace std;

class Divisao_por_zero{
private:
	const char* message;
public:
	Divisao_por_zero():message("Divisao por zero"){}
	const char* what () const {return message;}
};


double divide ( int numerador, int denominador){
	if(denominador == 0)
		throw Divisao_por_zero();
	retun (double)numerador/(double)denominador;
}


int main()
{
	int  numerador = 1;
	while( numerador != 0){
		cout << "numerador: ";
		cin >> numerador;

		cout << "denominador: ";
		cin >> denominador;

		try{
			cout << divide(numerador, denominador);
		}catch(Divisao_por_zero ex){
			cout << ex.what() << endl;
		}
	}
	return 0;
}