#include <stdio.h>
#include <math.h>
#include <string.h>

int Crescente(int n);
int Decrescente(int n);
int Somatorio(int n);
int superFatorial(int n);
int fatorial (int n);
int fatorialExp(int n);
int catalao(int n);
int palindromo(char str[]);


int main(int argc, char const *argv[])
{
	int n;
	char str[128];

	scanf("%d", &n);
	scanf("%[^\n]%*c", str);

	Crescente(n);
	printf("\n");

	Decrescente(n);
	printf("\n");

	printf("SOMA: %d\n", Somatorio(n));
	printf("SUPERFATORIAL: %d\n", superFatorial(n));
	printf("FATORIAL EXPONENCIAL: %d\n", fatorialExp(n));
	printf("catalao: %d\n", catalao(n));

	printf("Minha string: %s", str);
	//palindromo(str);

	return 0;
}

int Crescente (int n){

	if(n >= 0){
		Crescente(n-1);
		printf("INTEIRO: %d\n", n);
		return 0; 
	}else
		return 0;
}

int Decrescente(int n){

	if(n >= 0){
		printf("INTEIRO: %d\n", n);
		Decrescente(n-1);
		return 0; 
	}else
		return 0;
}

int Somatorio( int n){
	int soma = 0;

	if(n >= 0){
		return Somatorio(n-1) + n;
	}else
		return 0;
}

int fatorial (int n){

    if(n > 0)
        return fatorial(n-1) * n;
    else
        return 1;
}

int superFatorial( int n){

	if(n < 2) 
		return n;
	if(n >= 3)
		return superFatorial(n-1) * fatorial(n);
}

int fatorialExp(int n){

	if(n < 1){
		return 1;
	}
	return pow(n, fatorialExp(n-1));
}

int catalao(int n){

	if(n > 0)
		return (((2*(2*n-1.0))/(n+1))*catalao(n-1));
	else
		return 1;
}

int palindromo(char str[]){
	char inversa[128];

	while(str != '\0'){
		//inverte(inversa, str);
	}

	if(strcmp(str, inversa))
		return printf("EH PALINDROMO\n");
	else
		return printf("NAO EH PALINDROMO\n");

}
