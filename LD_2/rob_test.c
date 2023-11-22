#include<stdio.h>
#include<math.h>
#define PI M_PI


float modified_sin(float x, float A){
    return sin(x/2)-A;
}
//x/2
void main(){
    float a,x,delta_x,b,y,A,f;
    a = 0;
    b = 2*3.14159265358979323846;
    f = x/2;

    printf("Ievadi A vērtību vienādojumam (sin(x/2)=A\n)");
    scanf("%f",&A);
    f = a;

    delta_x = 0.1;
    printf("\tx\ty\n");
    while(f<b){
        printf("%10.1f%10.1f\n",f,modified_sin(x,A));
        f += delta_x;
    }
}