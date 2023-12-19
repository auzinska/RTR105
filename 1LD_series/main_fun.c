#include <stdio.h>
#include <math.h>

double mans_sinuss(double x){
    double a, S;
    int k = 0;

    a = (pow(-1,k)*pow(x,2*k+1))/pow(2,2*k+1); 
    S = a;
    
    // 1. Summas izteiksmi ar ASCII simbolu palīdzību
    printf("k=%2d\t%.2f\t%8.2f\t%8.2f\n", k, x, a, S);

    // 2. Funkcijas definīcijas apgabala vērtības teksta komentāra veidā
    printf("Funkcijas definīcijas apgabala vērtības:\n");
    printf("x = %.2f\n", x);
    printf("y = sin(x/2) = %.2f\n", sin(x/2));
    
    while (k < 500){
        k++;
        a = a*((-1)*pow(x,2)/((16*pow(k,2)+8*k)));
        S = S + a;
        
        // 1. Summas izteiksmi ar ASCII simbolu palīdzību
        printf("k=%2d\t%.2f\t%8.2f\t%8.2f\n", k, x, a, S);
    }
    
    // 3. Rekurences funkcionālā reizinātāja izteiksmi ar ASCII simbolu palīdzību
    printf("\nRekurences funkcionālā reizinātāja izteiksmi:\n");
    printf("a_k = a_(k-1) * ((-1) * x^2) / (16k^2 + 8k)\n");

    return S;
}

int main(){
    double x, y, yy;

    // 4. Dialogs ar lietotāju x vērtības iegūšanai
    printf("Ievadiet x vērtību: ");
    scanf("%lf", &x);

    y = sin(x/2);

    // 6. Aprēķinātās summas pēdējā locekļa (piecsimtā locekķa) vērtība
    yy = mans_sinuss(x);
    printf("Aprēķinātās summas pēdējā locekļa vērtība: %.2f\n", yy);

    // 7. Funkcijas vērtību f(x), aprēķins izmantojot Teilora rindas izteiksmi
    printf("\nFunkcijas vērtība izmantojot Teilora rindas izteiksmi: %.2f\n", yy);

    // 8. Funkcijas vērtību f(x), aprēķins izmantojot funkcijas izteiksmi
    printf("Funkcijas vērtība izmantojot sin(x/2): %.2f\n", y);

    return 0;
}
