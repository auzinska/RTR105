# 4.Laboratorijas darba aizstāvēšana, "Skaitliskās metodes; Skaitliskā integrēšana"


## Man piešķirtā funkcija - y(x) = sin(x/2)


## Darba mērķis:

Aprēķināt laukumu grafikam y = sin(x/2) (starp f(x) līknes un x asi) ar integrēšanas metodi trīs veidos (pēc taisnstūra, trapeces un Simpsona metodes).

## Darba gaita:

1.Pēc dotās "Skaitliskās metodes" teorijas, sagatavot formulas visām trim metodēm (taisnstūra, trapeces un Simpsona metodei) un pārrakstīt tās koda veidā.

2.Uzrakstīt programmu, lai tā uz ekrāna izvada:

    1.dialogu ar lietotāju a vērtības iegūšanai
    2.dialogu ar lietotāju b vērtības iegūšanai
    3.dialogu ar lietotāju precizitātes vērtības iegūšanai
    4.laukuma (starp f(x) un x ass) vērtību (aprēķins izmantojot taisnstūru metodi)
    5.laukuma (starp f(x) un x ass) vērtību (aprēķins izmantojot trapeču metodi)
    6.laukuma (starp f(x) un x ass) vērtību (aprēķins izmantojot Simpsona metodi)


3.Pierādīt iegūtos rezultātus ar Wolframalpha grafiku un integrēšanas rezultātiem

## Risināšana

Visu trīs metožu pamatprincips ir sadalīt laukumu starp f(x) līknes un x asi mazākās daļās, izrēķināt to daļu laukumu un tad saskaitīt visu kopā. Piebilde: šis nav perfekts raksturojums.

Taisnstūra metode:

Taisnstūra metodei pielietotā sakarība, kur taisnstūra augstums ir funkcijas vērtība un platums ir intervāla garums:

![image](https://github.com/auzinska/RTR105/assets/50238747/5b178a5a-2f1a-45e9-a25d-01a40c699312)

Trapeču metodei pielietotā sakarība:

![image](https://github.com/auzinska/RTR105/assets/50238747/7c68db0c-3586-4c47-81a6-8c0dd05163dc)

Katram no šiem noteikumiem mēs varam iegūt precīzāku tuvinājumu, sadalot intervālu [a, b] n apakšintervālos. Katram no šiem apakšintervāliem tiek aprēķināts tuvinājums, un visi rezultāti tiek saskaitīti kopā. Šo pieeju sauc par salikto, paplašināto vai iterēto noteikumu. Šajā gadījumā apakšintervāliem ir forma, kur augstums ir noteikts intervāla garums.

Var tikt izmantoti tāda paša garuma apakšintervālus kā h, bet ir iespējams izmantot arī dažāda garuma intervālus, tādējādi pielāgojot pieeju konkrētajiem uzdevuma nosacījumiem, piemēram, kā šis. 

Simpsona metodei pielietotā sakarība:


![image](https://github.com/auzinska/RTR105/assets/50238747/4c10329d-ee2d-4edb-bc70-eda3f23edb00)


Šeit tiek izmantoti daļēji izliektu daudzskaitļu formulu tuvinājumi, lai aprēķinātu noteiktu integrāļa vērtību. Šī metode parasti izmanto pāra skaitu intervālu un izmanto katru divu blakus esošo intervālu, lai aprēķinātu integrāļa vērtību.

## Metožu pielietošana programmā

Kods c valodā (Atrodams: https://github.com/auzinska/RTR105/blob/main/4LD_integrate/inte_main.c)

Kods teksta formātā:
```
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
