#include <stdio.h>

int strlen(char* s);
void mostrar(int i);

int main(int argc, char const *argv[]){
	int i;
	char s[256];

	scanf("%[^\n]%*c", s);
	i = strlen(s);
	mostrar(i);
	return 0;
}

int strlen(char* s){
	int i;
	for(i = 0; s[i]; ++i);
	return i;
}

void mostrar(int i){
	printf("\nstring possui %d caracteres!!\n", i);
}