#include <stdio.h>
#define int64 long long int

int x,y,z;

//neg DST // DST = -DST

int main(int argc, char const *argv[])
{
	//y = 10*x;
	asm(".intel_systax noprefix \n\
		mov eax, x 				\n\
		lea eax, [eax + eax*4]	\n\
		lea eax, [eax + eax]	\n\
		mov y, eax				\n\
		att_syntax");
	return 0;
}