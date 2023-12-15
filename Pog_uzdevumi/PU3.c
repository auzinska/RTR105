#include <stdio.h>
#include <ctype.h>


//kods ir  "Muļķu drošs", attiecīgi, kodā tiek pārbaudīts, vai vispār tiek ievadīti burti. Savukārt, pie dažādām ievadēm ir neprecizitātes, piem cba + a = aab (nezinu kāpēc)

int main() {
    char burts1, burts2, burts3;
    char izvele;


    printf("Ievadiet trīs burtus: ");
    if (scanf(" %c %c %c", &burts1, &burts2, &burts3) != 3 || !isalpha(burts1) || !isalpha(burts2) || !isalpha(burts3)) {
        printf("Nepareiza ievade. Lūdzu ievadiet trīs burtus.\n");
        return 1;
    }


    printf("Izvēlieties kārtošanas secību (a - alfabētiski, p - prētēji): ");
    if (scanf(" %c", &izvele) != 1) {
        printf("Nepareiza ievade. Lūdzu ievadiet 'a' vai 'p'.\n");
        return 1;
    }


    printf("Sakārtotie burti: ");
    if (izvele == 'a' || izvele == 'A') {
        printf("%c %c %c\n", (burts1 < burts2 ? (burts1 < burts3 ? burts1 : burts3) : (burts2 < burts3 ? burts2 : burts3)),
                              (burts1 < burts2 ? (burts2 < burts3 ? burts2 : burts3) : (burts1 < burts3 ? burts1 : burts3)),
                              (burts1 < burts2 ? (burts1 < burts3 ? burts3 : burts1) : (burts2 < burts3 ? burts3 : burts2)));
    } else if (izvele == 'p' || izvele == 'P') {
        printf("%c %c %c\n", (burts1 > burts2 ? (burts1 > burts3 ? burts1 : burts3) : (burts2 > burts3 ? burts2 : burts3)),
                              (burts1 > burts2 ? (burts2 > burts3 ? burts2 : burts3) : (burts1 > burts3 ? burts1 : burts3)),
                              (burts1 > burts2 ? (burts1 > burts3 ? burts3 : burts1) : (burts2 > burts3 ? burts3 : burts2)));
    } else {
        printf("Nepareiza izvēle. Lūdzu ievadiet 'a' vai 'p'.\n");
        return 1;
    }

    return 0;
}
