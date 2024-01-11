# 5.Laboratorijas darba aizstāvēšana, "Skaitļu kopas kārtošana un statistika"

## Darba mērķis:
Pielietojot kādu no kārtošanas algoritmiem, saprast kā izvēlēto algoritmu ieintegrēt c valodas kodā un iegūtās vērtības ievietot gnuplot histogrammā.


## Darba gaita:

1.Izvēlēties un izprast kādu no kārtošanas algoritmiem.

2.Uzrakstīt programmu, lai tā uz ekrāna izvada:

    1.dialogu ar lietotāju simbolu (teksta) rindas iegūšanai
    2.minimālo vērtību (saskaņā ar ASCII skaitļiem)
    3.maksimālo vērtību (saskaņā ar ASCII skaitļiem)
    4.vidējo vērtību (saskaņā ar ASCII skaitļiem)
    5.mediānas vērtību (saskaņā ar ASCII skaitļiem)
    6.modas(u) vērtību(as) (saskaņā ar ASCII skaitļiem)
    7.sakārtoto simbolu rindu vienā rindā un atbilstošus ASCII skaitļus nākamajā rindā
      rindas kārtošana alfabēta secībā - A, B, C, ..., a, b, c, ... (saskaņā ar ASCII skaitļiem)

3.Automātiski aizsūtīt  datus uz gnoplot, lai izveidotu histogrammu.

## Programmas darbības apraksts

Tika izveidotas divas programmas, viena, kurā tiek izpildītas tikai darba gaitas 2. punkta prasības un otra, kas dara visu prasīto. Autors izvēlējās aizstāvēšanā pievienot abu programmu kodus, lai labāk saprastu algoritma pielietošanu un integrāciju kodā.

Programmās tika izmantots "burbuļu" kārtošanas jeb "bubble sorting" algoritms. Šajā algoritmā secīgi salīdzina un samaina "kaimiņu" elementus, līdz visi elementi ir sakārtoti. Savukārt, pirms elementus var sakārtot, tiem ir jānoskaidro "ASCI" vērtība, kas tika izdarīts ar %d formātu, printf funkcija izvada decimālo vērtību (ASCI vērtību).

Nākamais solis ir kārtošana un tas ļoti vienkārši tika izdarīts salīdzinot vērtības:
```
for (int i = 0; i < garums - 1; i++) {
        for (int j = i + 1; j < garums; j++) {
```

Tad var samainīt elementus ar vietām:
```
void karto_alfabeta_seciba(char *simboli, int garums) {
    for (int i = 0; i < garums - 1; i++) {
        for (int j = i + 1; j < garums; j++) {
            if (simboli[i] > simboli[j]) {
                // Samaina vietām, ja nepieciešams
                char temp = simboli[i];
                simboli[i] = simboli[j];
                simboli[j] = temp;
```
Šī risinājuma pilnais kods c valodā (atrodams github: https://github.com/auzinska/RTR105/blob/main/5LD_sorting_statistics/sort.c):

```
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Kārtošana
void karto_alfabeta_seciba(char *simboli, int garums) {
    for (int i = 0; i < garums - 1; i++) {
        for (int j = i + 1; j < garums; j++) {
            if (simboli[i] > simboli[j]) {
                // Samaina vietām, ja nepieciešams
                char temp = simboli[i];
                simboli[i] = simboli[j];
                simboli[j] = temp;
            }
        }
    }
}

int main() {
    // ieevade
    char rinda[6];  // Ievadīsim precīzi 5 simbolus
    printf("Ievadiet 5 simbolus: ");
    fgets(rinda, sizeof(rinda), stdin);

    // Min MAX
    int min = rinda[0], max = rinda[0], sum = rinda[0];
    for (int i = 1; i < 5; i++) {
        sum += rinda[i];
        if (rinda[i] < min) min = rinda[i];
        if (rinda[i] > max) max = rinda[i];
    }
    double videja = (double)sum / 5;

    // mediānaa
    karto_alfabeta_seciba(rinda, 5);
    char mediana = rinda[2];

    // moda
    int modes[256] = {0}; // Lai nav liekas galvas sāpes, pieņemsim, ka ASCII simbolu diapazons ir no 0 līdz 255
    for (int i = 0; i < 5; i++) {
        modes[rinda[i]]++;
    }
    int moda = 0;
    char moda_simbols;
    for (int i = 0; i < 256; i++) {
        if (modes[i] > moda) {
            moda = modes[i];
            moda_simbols = (char)i;
        }
    }

    // rez
    printf("Minimālā vērtība (ASCII): %d (%c)\n", min, min);
    printf("Maksimālā vērtība (ASCII): %d (%c)\n", max, max);
    printf("Vidējā vērtība (ASCII): %.2f\n", videja);
    printf("Mediānas vērtība (ASCII): %d (%c)\n", mediana, mediana);
    printf("Modas vērtība (ASCII): %d (%c)\n", moda_simbols, moda_simbols);

    // alfabēta secībā kārto
    karto_alfabeta_seciba(rinda, 5);
    printf("Sakārtotie simboli: %s\n", rinda);

    return 0;
}

```

Programmas darbība no lietotāja puses(1.ievade: 53421; 2.ievade: a5b2c; 3.ievade: .5a,"):

![LD5_kodapiemers](https://github.com/auzinska/RTR105/blob/main/5LD_sorting_statistics/LD5_kodapiemers.png)



Risinājuma kods, kur iegūtās vērtības tiek automātiski sūtītas uz gnuplot (atrodams github: https://github.com/auzinska/RTR105/blob/main/5LD_sorting_statistics/sort_gnup.c):

```
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Kārtošana
void karto_alfabeta_seciba(char *simboli, int garums) {
    for (int i = 0; i < garums - 1; i++) {
        for (int j = i + 1; j < garums; j++) {
            if (simboli[i] > simboli[j]) {
                // sakārto nākamajam burbulim
                char temp = simboli[i];
                simboli[i] = simboli[j];
                simboli[j] = temp;
            }
        }
    }
}

int main() {
    // Iievade
    char rinda[6];
    printf("Ievadiet 5 simbolus: ");
    fgets(rinda, sizeof(rinda), stdin);

    // Min MAX
    int min = rinda[0], max = rinda[0], sum = rinda[0];
    for (int i = 1; i < 5; i++) {
        sum += rinda[i];
        if (rinda[i] < min) min = rinda[i];
        if (rinda[i] > max) max = rinda[i];
    }
    double videja = (double)sum / 5;

    // mediana
    karto_alfabeta_seciba(rinda, 5);
    char mediana = rinda[2]; 

    // moda
    int modes[256] = {0}; // :D Lai nav lieki jāuztraucās, pieņemsim, ka ASCII simbolu diapazons ir no 0 līdz 255
    for (int i = 0; i < 5; i++) {
        modes[rinda[i]]++;
    }
    int moda = 0;
    char moda_simbols;
    for (int i = 0; i < 256; i++) {
        if (modes[i] > moda) {
            moda = modes[i];
            moda_simbols = (char)i;
        }
    }

    //rezultāti
    printf("Minimālā vērtība (ASCII): %d (%c)\n", min, min);
    printf("Maksimālā vērtība (ASCII): %d (%c)\n", max, max);
    printf("Vidējā vērtība (ASCII): %.2f\n", videja);
    printf("Mediānas vērtība (ASCII): %d (%c)\n", mediana, mediana);
    printf("Modas vērtība (ASCII): %d (%c)\n", moda_simbols, moda_simbols);

    // kārto alfabētiskā secībā
    karto_alfabeta_seciba(rinda, 5);
    printf("Sakārtotie simboli: %s\n", rinda);

    // sūta uz gnuplot, lai taisa histogrammu 
        FILE *gnuplotPipe = popen("gnuplot -persistent", "w");
    if (gnuplotPipe != NULL) {
        fprintf(gnuplotPipe, "set boxwidth 0.5\n");
        fprintf(gnuplotPipe, "set style fill solid\n");
        fprintf(gnuplotPipe, "plot '-' using 1:2 with boxes\n");

        for (int i = 0; i < 5; i++) {
            fprintf(gnuplotPipe, "%d %d\n", rinda[i], 1); // Katram simbolam pievieno 1
        }

        fprintf(gnuplotPipe, "e\n");
        fclose(gnuplotPipe);
    } else {
        printf("Kļūda: Nevarēja sākt Gnuplot procesu.\n");
    }

    return 0;
}

```

Programmas darbība no lietotāja puses ar automātisko gnuplot ievadi (ievade: 115ab):

![LD5_Kodapiemers_ar_gnuplot_pats_kods](https://github.com/auzinska/RTR105/blob/main/5LD_sorting_statistics/LD5_Kodapiemers_ar_gnuplot_pats_kods.png)

Gnuplot (Histogrammā tiek parādīts elementu skaits atkarībā no tā atrašanās vietas asci secībā (no 0-255)):

![LD5_GNUPLOT](https://github.com/auzinska/RTR105/blob/main/5LD_sorting_statistics/LD5_GNUPLOT.png)
