#include<stdio.h>
#include<math.h>

float xi, yi, xf, h;

float f( float x, float y){
    return (- x + y + 2);
}

float rungeKutta4thOrder(){
    float i, k1, k2, k3, k4, k;
    printf("1\n");
    for(i = xi; i < xf; i += h){
        printf("2\n");
        k1 = h * f( xi, yi);
        k2 = h * f( xi + (h/2.0) , yi + k1/2.0 );
        k3 = h * f( xi + (h/2.0) , yi + k2/2.0);
        k4 = h * f( xi + h, yi + k3);
        printf("3\n");
        k = 1/6.0 * (k1 + 2.0*k2 + 2.0*k3 + k4);
        printf("4\n");
        yi = yi + k ;
    }
    return yi;
}

int main(){
    printf("Digite xi:");
    scanf("%f", &xi);
    printf("Digite yi:");
    scanf("%f", &yi);
    printf("Digite xf:");
    scanf("%f", &xf);
    printf("Digite h:");
    scanf("%f", &h);
    printf("r = %.4lf", rungeKutta4thOrder());
    return 0;
}