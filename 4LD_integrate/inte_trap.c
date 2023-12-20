#include<stdio.h>
#include<math.h>

//taisnstūra metode

void main(){
    double a=0, b=0, eps = 0;
    //taisnstūra metode
    float h, integr1=0, integr2, integr3, fa, fb, fa05, fa15; 

    printf("Ievadiet a vērtību (vēlams 0): ");
    scanf("%lf", &a);
    printf("Ievadiet b vērtību (vēlams, kaut ko, kas ir robežās no 0 līdz 2*pi): ");
    scanf("%lf", &b);
    printf("Ievadiet precizitātes (eps) vērtību (vēlams 1e-3): ");
    scanf("%lf", &eps);

    int k, n = 2;

    integr2 = (b-a) * (sin(a/2)+sin(b/2))/n;

    while(fabs(integr2-integr1)>eps){
    n*=2;
    h = (b-a)/n;
    integr1 = integr2;
    integr2=0 ;
    for(k=0;k<n;k++)
        integr2+=h * sin(((a+(k+0.5))/2)*h);
    }
/*
    fa = sin(a/2);
    fb = sin(b/2);
    fa05 = sin(((a+(k+0.5))/2)*h);
    fa15 = sin(((a+(k+1.5))/2)*h);d

    while(fabs(integr3-integr1)>eps){
    n*=2;
    h = (b-a)/n;
    integr1 = integr3;
    integr2=0 ;
    for(k=0;k<n;k++)
        integr3+= (h * fa05) + (h * fa15);
    }
*/


printf("Integrāļa vērtība ar taisnstūra metodi:% 2f\n",integr2);
//printf("Integrāļa vērtība ar trapeces metodi:% 2f\n",integr3);


}