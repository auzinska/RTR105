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

Kods c valodā (Atrodams: https://github.com/auzinska/RTR105/blob/main/3LD_derivative/atv_main.c)

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

    !!piebilde!!: kods strādā tikai tad, ja ievadē decimālskaitļi ir atdalīti tikai ar punktu (piem. 6.28, nevis 6,28)

Rezultāta piemērs (Koda izvade, ja a = 0; b = 6.28 (2* 3.14); precizitāte = 0.001)

![LD3_kodapiemers1](https://github.com/auzinska/RTR105/blob/main/3LD_derivative/LD3_kodapiemers1.png)

derivative.dat fails pēc programmas izpildes:

![LD3_kodapiemers2](https://github.com/auzinska/RTR105/blob/main/3LD_derivative/LD3_kodapiemers2.png)

Grafiskā attēlošana ar gnuplot (Ir redzami grafiki sin(x/2); sin'(x/2) pēc gnuplot; sin'(x/2) pēc analītiskās formas; sin'(x/2) pēc skaitliskās formas; sin''(x/2) pēc analītiskās formas; sin''(x/2) pēc skaitliskās formas;):

Gnuplot ievade:
```
set grid
plot [0:10] sin(x/2)
replot [0:10] cos(x) title "sin'(x/2)"
replot "derivative.dat" every ::1 using 1:3 with lines title "sin'(x/2) (analytical formula)"
replot "derivative.dat" every ::1 using 1:4 with lines title "sin'(x/2) (finite difference)"
replot "derivative.dat" every ::1 using 1:5 with lines title "sin''(x/2) (analytical formula)"
replot "derivative.dat" every ::1 using 1:6 with lines title "sin''(x/2) (finite difference)"
```

Grafiks:

![LD3_LD3_grafiks](https://github.com/auzinska/RTR105/blob/main/3LD_derivative/LD3_grafiks.png)

## Pielikums
1. Gnuplot ievades piemērs. RĪGAS TEHNISKĀs UNIVERSITĀTEs ELEKTRONIKAS UN TELEKOMUNIKĀCIJU FAKULTĀTE
Priekšmeta "Datormācība  e-studiju vietne. Pieejams Ortusā: https://estudijas.rtu.lv/file.php/360800/RTR105_2019_2020_L19_20200118_14_50.pdf .

