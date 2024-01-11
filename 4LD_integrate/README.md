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


//kods ir muļķu drošs :)

double taisnstura_metode(double a, double b, int n) {
    double h = (b - a) / n;
    double integr = 0;

    for (int k = 0; k < n; k++) {
        integr += h * sin((a + (k + 0.5) * h) / 2);
    }

    return integr;
}

double trapeces_metode(double a, double b, int n) {
    double h = (b - a) / n;
    double integr = 0;

    for (int k = 1; k < n; k++) {
        integr += h * sin((a + k * h) / 2);
    }

    integr += (h / 2) * (sin(a / 2) + sin(b / 2));

    return integr;
}

double simpsona_metode(double a, double b, int n) {
    double h = (b - a) / n;
    double integr = 0;

    for (int k = 0; k < n; k++) {
        integr += (h / 6) * (sin((a + k * h) / 2) + 4 * sin((a + (k + 0.5) * h) / 2) + sin((a + (k + 1) * h) / 2));
    }

    return integr;
}

int main() {
    double a, b, eps;

    printf("Ievadiet a vērtību (vēlams 0): ");
    if (scanf("%lf", &a) != 1) {
        printf("ERROR: Ievadiet skaitli!\n");
        return 1;
    }

    printf("Ievadiet b vērtību (vēlams, kaut ko, kas ir robežās no 0 līdz 2*pi): ");
    if (scanf("%lf", &b) != 1) {
        printf("ERROR: Ievadiet skaitli!\n");
        return 1;
    }

    printf("Ievadiet precizitātes (eps) vērtību (vēlams 1e-6): ");
    if (scanf("%lf", &eps) != 1) {
        printf("ERROR: Ievadiet skaitli!\n");
        return 1;
    }

    if (eps <= 0) {
        printf("ERROR: Precizitātei jābūt pozitīvai!\n");
        return 1;
    }

    int n = 2;
    double integr_taisnstura, integr_trapeces, integr_simpsona;

    // Taisnstūra metode
    integr_taisnstura = taisnstura_metode(a, b, n);
    while (1) {
        n *= 2;
        double integr_taisnstura_new = taisnstura_metode(a, b, n);
        if (fabs(integr_taisnstura_new - integr_taisnstura) < eps) {
            integr_taisnstura = integr_taisnstura_new;
            break;
        }
        integr_taisnstura = integr_taisnstura_new;
    }
    printf("Elementu skaits - %d) Integrāļa vērtība ar taisnstūra metodi: %.6f\n", n, integr_taisnstura);

    // Trapeces metode
    n = 2;
    integr_trapeces = trapeces_metode(a, b, n);
    while (1) {
        n *= 2;
        double integr_trapeces_new = trapeces_metode(a, b, n);
        if (fabs(integr_trapeces_new - integr_trapeces) < eps) {
            integr_trapeces = integr_trapeces_new;
            break;
        }
        integr_trapeces = integr_trapeces_new;
    }
    printf("Elementu skaits - %d) Integrāļa vērtība ar trapeces metodi: %.6f\n", n, integr_trapeces);

    // Simpsona metode
    n = 2;
    integr_simpsona = simpsona_metode(a, b, n);
    while (1) {
        n *= 2;
        double integr_simpsona_new = simpsona_metode(a, b, n);
        if (fabs(integr_simpsona_new - integr_simpsona) < eps) {
            integr_simpsona = integr_simpsona_new;
            break;
        }
        integr_simpsona = integr_simpsona_new;
    }
    printf("Elementu skaits - %d) Integrāļa vērtība ar Simpsona metodi: %.6f\n", n, integr_simpsona);

    return 0;
}
```
Programma no lietotāja skatapunkta (ievade: a = 0; b = 6.28 (2*3.14); precizitāte = 0.000001):

Piebilde: lai rezultāti būtu precīzi, precizitātei ir jābūt vismaz 1e-6. Kā arī kods strādās tikai vienīgi tad, ja ievadē decimālskaitļi ir pierakstīti ar punktu, nevis ar komatu (piem. 6.28, nevis 6,28)

![LD4_Kodapiemers1](https://github.com/auzinska/RTR105/blob/main/4LD_integrate/LD4_kodapiemers1.png)

## Rezultātu pierādīšana ar Wolpramalpha

Wolfram alpha rezultāti, ja a = 0, b = 2*pi

![int_b=2pi](https://github.com/auzinska/RTR105/blob/main/4LD_integrate/int_b%3Dpi2.png)

Wolfram alpha rezultāti, ja a = 0, b = 4*pi

![int_b=4pi](https://github.com/auzinska/RTR105/blob/main/4LD_integrate/int_b%3D4pi.png)

Rezultātu analīze: Rezuultāti sakrīt ar programmā izvadīto, ja skaitļus noapaļo līdz simtdaļām, jo pagaidām pēc noklusējuma programmas izvadē ir skaitļi līdz miljondaļai aiz komata, lai rezultāti būtu maksimāli precīzi. Ņemot šo vērā, precizitātei arī ir jāsakrīt ar vienu miljono daļu.

