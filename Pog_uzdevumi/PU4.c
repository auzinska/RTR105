#include <stdio.h>
#include <ctype.h>

//Komentārs: Izmantojot ctype es pievienoju "isdigit", lai pārbaudītu, vai vispār ir ievadīts skaitlis. Būtībā padarot programmu muļķu drošu. 

int main() {
    long long skaitlis;
    char izvele;
    long long faktorials = 1;

    printf("Ievadiet decimālo skaitli: ");
    if (scanf("%lld", &skaitlis) != 1 || getchar() != '\n') {
        printf("Nepareiza ievade. Lūdzu ievadiet decimālo skaitli. :)\n");
        return 1;
    }


    printf("Izvēlieties datu tipu (c - char, i - int, l - long long): ");
    if (scanf(" %c", &izvele) != 1 || getchar() != '\n') {
        printf("Nepareiza izvēle. Lūdzu ievadiet 'c', 'i' vai 'l'. :)\n");
        return 1;
    }


    if (skaitlis < 0) {
        printf("Nepareiza ievade. Lūdzu ievadiet pozitīvu skaitli. :)\n");
        return 1;
    }


    while (skaitlis > 0) {
        faktorials *= skaitlis;
        skaitlis--;
    }


    switch (izvele) {
        case 'c':
            if (faktorials <= (long long)127 && faktorials >= (long long)-128)
                printf("Faktoriāls: %lld\n", faktorials);
            else
                printf("Nepareiza ievade. Ar char datu tipu nav iespējams aprēķināt faktoriālu šim skaitlim. :)\n");
            break;
        case 'i':
            if (faktorials <= (long long)2147483647 && faktorials >= (long long)-2147483648)
                printf("Faktoriāls: %lld\n", faktorials);
            else
                printf("Nepareiza ievade. Ar int datu tipu nav iespējams aprēķināt faktoriālu šim skaitlim. :)\n");
            break;
        case 'l':
            printf("Faktoriāls: %lld\n", faktorials);
            break;
        default:
            printf("Nepareiza izvēle. Lūdzu ievadiet 'c', 'i' vai 'l'.\n");
            return 1; 
    }

    return 0;
}
