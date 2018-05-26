#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*int main1()
{
	int x = 7;
	int y = 11;
	int * ptr;
	x += 2;
	ptr = NULL;
	ptr = malloc(sizeof(int));
	printf("%d\n", ptr);
	ptr = &x;
	*ptr += y;
	free (ptr);
	ptr = NULL;
	return 0;
}*/

int main(int argc, char const *argv[])
{
	char ch = 'a';
	char str1[10] = "frase dentro de programa na linguagem C";
	char str2[10];
	char str3[10] = "abcdef";
	char *str4;
	char *str5;
	str2 = str1;
	str4 = str3;
	strcpy(str5, str3);
	char* str6 = malloc(sizeof(char)*10);
	str3[1] = ch;
	strcpy(str6, str3);
	free(str6);
	return 0;
}