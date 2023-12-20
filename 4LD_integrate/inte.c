#include<stdio.h>
#include<math.h>

//taisnstūra metode

void main(){
    double a=0, b=0, eps = 0;
    //taisnstūra metode
    float h, integr1, integr2, integr3, fa, fb, fa05, fa15; 
    
    printf("Ievadiet a vērtību (vēlams 0): ");
    scanf("%lf", &a);
    printf("Ievadiet b vērtību (vēlams, kaut ko, kas ir robežās no 0 līdz 2*pi): ");
    scanf("%lf", &b);
    printf("Ievadiet precizitātes (eps) vērtību (vēlams 1e-3): ");
    scanf("%lf", &eps);

    int k, n = 2;



    integr2 = (b-a) * (sin(a/2)+sin(b/2))/n;

    integr1 = integr2 * (2 *eps);

    while(fabs(integr2-integr1)>eps){
    n*=2;
    h = (b-a)/n;
    integr1 = integr2;
    integr2=0 ;

    for(k=0;k<n;k++){
        fa = sin(((a+(k+0.5))/2)*h);
        integr2+=h * fa;}
    



printf("Elementu skaits - %d) Integrāļa vērtība:%.4f\n",n, integr2);

}
printf("Integrāļa vērtība ar taisnstūra metodi:%.2f\n",integr2);
//printf("Kāpēc pēc koda abas taisn. un trap. metodes ir vienādas? Jo tika izmantota viena un tā pati metode");

}