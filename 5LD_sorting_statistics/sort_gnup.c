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
