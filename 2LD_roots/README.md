# 2.Laboratorijas darba aizstāvēšana, "Skaitliskās metodes; Dihotomijas metode"


## Man piešķirtā funkcija - y(x) = sin(x/2)


## Darba mērķis:
Izpētīt un implementē dihotomijas metodifunkcijai sin(x/2), atrodot funkcijas saknes 
noteiktā diapazonā ar noteiktu precizitāti, izmantojot programmu C valodā.


## Darba gaita:

1.Pēc dotās "Skaitliskās metodes" teorijas, savai funkcijai atrast saknes 
pēc lietotāja noteikta diapazona, ņemot vērā nobīdi un precizitāti pēc ievades.

2.Uzrakstīt programmu, lai tā uz ekrāna izvada:

    1.dialogu ar lietotāju a vērtības iegūšanai
    2.dialogu ar lietotāju b vērtības iegūšanai
    3.dialogu ar lietotāju c vērtības iegūšanai
    4.dialogu ar lietotāju precizitātes vērtības iegūšanai
    5.aprēķināto x vērtību, kas atbilst f(x)=c vienādojumam, x starp a un b
    6.aprēķināto f(x) vērtību šim x
    7.nepieciešamo iterāciju skaitu, lai aprēķinātu šo x vērtību ar uzdoto precizitāti


3.Grafiski parādīt funkciju un funkciju pēc nobīdes ar gnuplot palīdzību

## Risinnāšana un darba izpilde un tās rezultāti:

Rekurences reizinājuma iegūšana:

![Trylor_LD1 jpg](https://github.com/auzinska/RTR105/assets/50238747/1bd3626f-4daf-432d-bf3a-470b0a266c2d)

Kods c valodā (Atrodams: https://github.com/auzinska/RTR105/blob/main/1LD_series/main_fun.c)
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



Grafiskā attēlošana ar gnuplot (Ir redzami grafiki sin(x/2); S0; S1; S2; S3):

Gnuplot ievade:
```
a0(x) = (pow(-1,0)*pow(x,2*0+1))/pow(2,2*0+1)*(-1) * pow(x,2)/((16*pow(0,2)+8*0))
a1(x) = (pow(-1,1)*pow(x,2*1+1))/pow(2,2*1+1)*(-1) * pow(x,2)/((16*pow(1,2)+8*1))
a2(x) = (pow(-1,2)*pow(x,2*2+1))/pow(2,2*2+1)*(-1) * pow(x,2)/((16*pow(2,2)+8*2))
a3(x) = (pow(-1,3)*pow(x,2*3+1))/pow(2,2*3+1)*(-1) * pow(x,2)/((16*pow(3,2)+8*3))

s0(x) = a0(x)
s1(x) = a0(x) + a1(x)
s2(x) = a0(x) + a1(x) + a2(x)
s3(x) = a0(x) + a1(x) + a2(x) + a3(x)
```

Grafiks:

![LD1_main_grafiks](https://github.com/auzinska/RTR105/assets/50238747/55ca2afb-8dcd-4d8e-b8ab-011ff96bcfa3)

## Rezultātu iegūšanas attēlošana:

Sin(x/2) aprēķināšana:

Ievadi argumentu: 5

sin(5/2)=0.60

a0 = 2.5 
S0 = 2.5

a499 = -0.00
S499 = 0.60

a500 = 0.00
S500 = 0.60
```         
         500
        _____
        \            k    2*k+1 
          \      (-1) * x
sin(5/2) = >  _______________________
          /                  2*k+1
        /       (2*k+1)! * 2
        _____
         k=0
```
Rekurences reizinātājs: 
```
        2
       X
________________
        2
  16 * k + 8
```
Rezultāta piemērs (Koda izvade, ja k iet līdz 5 un x = 5)

![teylor_kods_LD1](https://github.com/auzinska/RTR105/assets/50238747/fead361d-c57a-423b-bcc6-357e1c07b8d4)
