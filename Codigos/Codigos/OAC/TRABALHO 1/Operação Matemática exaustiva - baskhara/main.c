#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char const *argv[])
{

	int n, i;
	double delta, a, b, c, x1, x2;

	printf("Informe o numero de vezes que a operacao vai ser executada: ");
	scanf("%d", &n);

	scanf("%lf%lf%lf", &a, &b, &c);

	for (i = 0; i < n; ++i)
	{
		delta = (b*b)-(4*a*c);
		if(delta < 0 || a == 0){
			printf("impossivel calcular\n"); break;
		}else{
			delta = sqrt(delta);
			x1 = (-b+delta)/(2*a);
			x2 = (-b-delta)/(2*a);
		}

		printf("x1 = %g e x2 = %g \n", x1, x2);
	}
	return 0;
}