#include <stdio.h>
#include <math.h>

double mans_sinuss(double x){
    double a, S;
    int k = 0;

    a = (pow(-1,k)*pow(x,2*k+1))/pow(2,2*k+1); 
    S = a;
    printf("%.2f\t%8.2f\t%8.2f\n",x,a,S);

    while (k < 500){
        k++;
        a = a*(-1)*pow(x,2)/((16*pow(k,2)+8*k));
        S = S + a;
        printf("%.2f\t%8.2f\t%8.2f\n",x,a,S);
    }
    return S;
}

int main(){

    double x = 27,y,yy;
    y = sin(x/2);

    printf("Standarta funkcija- Y=sin(%.2f)=%.2f\n",x,y);

    yy = mans_sinuss(x);
    printf("lietojamā funkcija- y=mans_sinuss(%.2f)=%.2f\n",x,yy);
    
    return 0;

}