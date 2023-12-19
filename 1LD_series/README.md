1.Laboratorijas darba aizstāvēšana, "Skaitliskās metodes; Teilora rinda"

Man piešķirtā funkcija - y(x) = sin(x/2)

Darba gaita:
1.Pēc dotās "Skaitliskās metodes" teorijas, izveidot savai funkcijai 
aproksimāciju ar summu un to saīsināt pēc sakarības, Ak = R * Ak-1

2.Uzrakstīt programmu, lai tā uz ekrāna izvada:
    1.Summas izteiksmi ar ASCII simbolu palīdzību;
    2.Funkcijas definīcijas apgabala vērtības teksta komentāra veidā;
    3.Rekurences funkcionālā reizinātāja izteiksmi ar ASCII simbolu palīdzību (ASCII zīmēšāna);
    4.Dialogu ar lietotāju x vērtības iegūšanai;
    5.Aprēķinātās summas iepriekšpēdējā locekļa vērtību;
    6.Aprēķinātās summas pēdējā locekļa (piecsimtā locekķa) vērtību;
    7.Funkcijas vērtību f(x), aprēķins izmantojot Teilora rindas izteiksmi;
    8.Funkcijas vērtību f(x), aprēķins izmantojot funkcijas izteiksmi.

3.Kods c valodā (Atrodams: https://github.com/auzinska/RTR105/blob/main/1LD_series/main_fun.c)
```
c
#include <stdio.h>
#include <math.h>

double mans_sinuss(double x){
    double a, S;
    int k = 0;

    a = (pow(-1,k)*pow(x,2*k+1))/pow(2,2*k+1); 
    S = a;
    
    //Summas izteiksme
    printf("k=%2d\t%.2f\t%8.2f\t%8.2f\n", k, x, a, S);

    //Funkcijas definīcijas apgabala vērtības
    printf("Funkcijas definīcijas apgabala vērtības:\n");
    printf("x = %.2f\n", x);
    printf("y = sin(x/2) = %.2f\n", sin(x/2));
    
    while (k < 500){
        k++;
        a = a*((-1)*pow(x,2)/((16*pow(k,2)+8*k)));
        S = S + a;
        
        //Summas izteiksme atkal
        printf("k=%2d\t%.2f\t%8.2f\t%8.2f\n", k, x, a, S);
    }
    
    // 3. Rekurences funkcionālā reizinātāja izteiksmi ar ASCII simbolu palīdzību
    printf("\nRekurences funkcionālā reizinātāja izteiksmi:\n");
    printf("a_k = a_(k-1) * ((-1) * x^2) / (16k^2 + 8k)\n");

    return S;
    }

    int main(){
        double x, y, yy;

    printf("Ievadiet x vērtību: ");
    scanf("%lf", &x);

    y = sin(x/2);

   
    //Aprēķinātās summas pēdējā locekļa (piecsimtā locekķa) vērtība
    yy = mans_sinuss(x);
    printf("Aprēķinātās summas pēdējā locekļa vērtība: %.2f\n", yy);

    printf("\nFunkcijas vērtība izmantojot Teilora rindas izteiksmi: %.2f\n", yy);

    printf("Funkcijas vērtība izmantojot sin(x/2): %.2f\n", y);

    return 0;
}
```


Aproksimācijas ar summu saīsināšana:

![Trylor_LD1 jpg](https://github.com/auzinska/RTR105/assets/50238747/1bd3626f-4daf-432d-bf3a-470b0a266c2d)

Koda izvade, ja k iet līdz 5

![teylor_kods_LD1](https://github.com/auzinska/RTR105/assets/50238747/fead361d-c57a-423b-bcc6-357e1c07b8d4)
