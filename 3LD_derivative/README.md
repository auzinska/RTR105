# 3.Laboratorijas darba aizstāvēšana, "Skaitliskās metodes; Skaitliskā diferencēšana"


## Man piešķirtā funkcija - y(x) = sin(x/2)


## Darba mērķis:
Iegūt un izpētīt piešķirtās funkcijas diferenciāli, atvasinājumu un otrās pakāpes atvasinājumu,
izdarīt to divos  veidos un grafiski salīdzināt.

## Darba gaita:

1.Pēc dotās "Skaitliskās metodes" teorijas, aprēķināt f(x) dotajai funkcijai, atvasināt to.

2.Uzrakstīt programmu, lai tā uz ekrāna izvada:

    1.dialogu ar lietotāju a vērtības iegūšanai
    2.dialogu ar lietotāju b vērtības iegūšanai
    3.dialogu ar lietotāju precizitātes vērtības iegūšanai
    4.f(x) vērtības, x no a līdz b (aprēķināt, attēlot un saglabāt derivative .dat failā)
    5.f’(x) vērtības, x no a līdz b (aprēķināt, attēlot un saglabāt derivative .dat failā;
        izmantot atvasinājuma analītisko formulu)
    6.f’(x) vērtības, x no a līdz b (aprēķināt, attēlot un saglabāt derivative .dat failā;
        izmantot skaitlisko atvasinājumu - diferencēšana un priekšu)
    7.f”(x) vērtības, x no a līdz b (aprēķināt, attēlot un saglabāt derivative .dat failā;
        izmantot atvasinājuma analītisko formulu)
    8.f”(x) vērtības, x no a līdz b (aprēķināt, attēlot un saglabāt derivative .dat failā;
        izmantot skaitlisko atvasinājumu - diferencēšana un priekšu)


3.Grafiski parādīt funkcijas izmainīšanos ar gnuplot palīdzību

## Programmas darbība

Kods c valodā (Atrodams: https://github.com/auzinska/RTR105/blob/main/LD3_derivative/atv_main.c)

Kods teksta formā:

```
#include <stdio.h>
#include <math.h>

int main()
{
    FILE *pFile;
    float a, b, x, delta_x, sin_prim, delta_y, dub_y;

    // lietotāja ievade
    printf("Ievadiet skaitlisku a vērtību (piem. 0): ");
    if (scanf("%f", &a) != 1)
    {
        printf("Nepareiza ievade. Ievadiet skaitli.\n");
        return 1; // Beidz programmu ar kļūdas kodu
    }

    printf("Ievadiet skaitlisku b vērtību (piem. 6.28): ");
    if (scanf("%f", &b) != 1)
    {
        printf("Nepareiza ievade. Ievadiet skaitli.\n");
        return 1; // Beidz programmu ar kļūdas kodu
    }

    // Iegūst precizitātes no lietotāja
    printf("Ievadiet precizitātes vērtību (līdz 0.0001): ");
    if (scanf("%f", &delta_x) != 1 || delta_x <= 0)
    {
        printf("Nepareiza ievade. Ievadiet pozitīvu skaitli lielāku par 0.\n");
        return 1; // Beidz programmu ar kļūdas kodu
    }

    // Atvēr failu
    pFile = fopen("derivative.dat", "w");
    if (pFile == NULL)
    {
        printf("Nevar atvērt failu derivative.dat.\n");
        return 1; // Beidz programmu ar kļūdas kodu
    }

    // header failā
    fprintf(pFile, "\tx\t\tsin(x/2)\t\tsin\'(x/2)\t\tdelta_y\t\tdub_y\n");

    x = a;
    while (x < b)
    {
        // Atvasinājuma analītiskais aprēķins
        sin_prim = cos(x/2);

        // Atvasinājuma skaitliskais aprēķins
        delta_y = ((sin((x + delta_x) / 2) - sin(x / 2)) / (delta_x / 2));
        dub_y = (delta_y / sin(x/2)) * delta_x;

        // dati uz failu
        fprintf(pFile, "%12.2f\t%12.2f\t%20.2f\t%20.2f\t%20.2f\n", x, sin(x/2), sin_prim, delta_y, dub_y);

        x += delta_x;
    }

    // Aizver failu
    fclose(pFile);

    return 0;
}

```

Koda darbība no lietotāja puses:

![LD3_kodapiemers1](https://github.com/auzinska/RTR105/blob/main/3LD_derivative/LD3_kodapiemers1.png)

derivative.dat fails pēc programmas izpildes:

![LD3_kodapiemers2](https://github.com/auzinska/RTR105/blob/main/3LD_derivative/LD3_kodapiemers2.png)

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
