#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Funkcija, kas kārto simbolu masīvu alfabētiskā secībā
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
    // Iegūst simbolu rindu no lietotāja
    char rinda[6];  // Ievadīsim precīzi 5 simbolus
    printf("Ievadiet 5 simbolus: ");
    fgets(rinda, sizeof(rinda), stdin);

    // Atrast minimālo, maksimālo un vidējo vērtību ASCII skaitļos
    int min = rinda[0], max = rinda[0], sum = rinda[0];
    for (int i = 1; i < 5; i++) {
        sum += rinda[i];
        if (rinda[i] < min) min = rinda[i];
        if (rinda[i] > max) max = rinda[i];
    }
    double videja = (double)sum / 5;

    // Atrast mediānas vērtību
    karto_alfabeta_seciba(rinda, 5);
    char mediana = rinda[2]; // Atrast vidējo elementu

    // Atrast modas vērtību
    int modes[256] = {0}; // Pieņemsim, ka ASCII simbolu diapazons ir no 0 līdz 255
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

    // Izvada rezultātus
    printf("Minimālā vērtība (ASCII): %d (%c)\n", min, min);
    printf("Maksimālā vērtība (ASCII): %d (%c)\n", max, max);
    printf("Vidējā vērtība (ASCII): %.2f\n", videja);
    printf("Mediānas vērtība (ASCII): %d (%c)\n", mediana, mediana);
    printf("Modas vērtība (ASCII): %d (%c)\n", moda_simbols, moda_simbols);

    // Sakārto simbolu rindu alfabētiskā secībā
    karto_alfabeta_seciba(rinda, 5);
    printf("Sakārtotie simboli: %s\n", rinda);

    return 0;
}
