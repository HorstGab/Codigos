#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
	char str[100];
	int qualidade=0, ma=0, mi=0, num=0, esp=0, i;
	gets(str);
	if((strlen(str))>= 8)
		qualidade+=20;
	for(i=0; str[i]; i++){ //enquanto não for \0 nesse str[i]
		if(islower(str[i]))
			mi++;
		else{
			if(isupper(str[i]))
				ma++;
			else
				if(isdigit(str[i]))
					num++;
				else
					if(!isalnum(str[i]))
						esp++;
		}
	}
	if(mi>0)
		qualidade+=20;
	if(ma>0)
		qualidade+=20;
	if(num>0)
		qualidade+=20;
	if(esp>0)
		qualidade+=20;
	printf("Qualidade de senha = %d", qualidade);
	return 0;
}