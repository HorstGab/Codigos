#include <stdio.h>

int main(int argc, char const *argv[]){

	char s[256];
	int c;

	printf("endereco %c", ? strchr(s,c): NULL);
	return 0;
}

char* strchr(char* s, int c){

	for(i = 0; s[i]; i++){
		if(s[i] == c){
			return &s[i];
		}
	}
}