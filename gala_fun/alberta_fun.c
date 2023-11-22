#include <stdio.h>
#include <math.h>

double mans_sinuss(double x){
    double a, S;
    int k = 0;

    a = (pow(x,k))/k; 
    S = a;
    printf("%.2f\t%8.2f\t%8.2f\n",x,a,S);

    while (k < 500){
        k++;
        a = a*(pow(x,k))/k;
        S = S + a;
        printf("%.2f\t%8.2f\t%8.2f\n",x,a,S);
    }
    return S;
}

int main(){

    double x = 5,y,yy;
    y = sin(exp(x));

    yy = mans_sinuss(x);
    printf("lietojamā funkcija- y=mana_fun(%.2f)=%.2f\n",x,yy);
    printf("Standarta funkcija- Y=exp(x)(%.2f)=%.2f\n",x,y);
    return 0;

}