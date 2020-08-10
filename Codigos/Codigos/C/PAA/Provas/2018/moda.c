#include "stdio.h"

//C:\Users\Gabriel\Documents\GitHub\Codigos\C\PAA\Provas\2018

int ocorrencia (int A[], int n, int x){
	int i, p = 0;
	for (i = 0; i < n; i++){
		if (A[i] == x) p++;
	}
	return p;
}
int moda (int A[], int n, int x){

	int i;
	int B[10] = {0};
	for (i = 0; i < n; ++i)
	{
		B[i] = ocorrencia(A,n,A[i]);
	}

	int p = 0;
	int j = 0;
	p = B[0];
	for ( i = 1; i <= n; ++i)
	{
		if (B[i] > p){
			p = B[i];
			j = i + 1;
		}
	}

	if( p == 0) return -1;
	return A[j];
}
int main(int argc, char const *argv[])
{
	int A [10] = {1,1,1,2,3,4,5,7,7};
	printf("Moda  = %d\n", moda(A, 10, 1));
	return 0;
}