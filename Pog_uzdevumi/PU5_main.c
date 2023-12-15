#include <stdio.h>
#include <ctype.h>


//Komentārs: Izmantojot ctype es pievienoju "isdigit", lai pārbaudītu, vai vispār ir ievadīts skaitlis. Būtībā padarot programmu muļķu drošu. 


long long faktorials(int skaitlis);

int main() {
    int skaitlis;
    char izvele;
    long long rezultats;


    printf("Ievadiet decimālo skaitli: ");
    if (scanf("%d", &skaitlis) != 1 || getchar() != '\n') {
        printf("Nepareiza ievade. Lūdzu ievadiet derīgu decimālo skaitli.\n");
        return 1;
    }

    printf("Izvēlieties datu tipu (c - char, i - int, l - long long): ");
    if (scanf(" %c", &izvele) != 1 || getchar() != '\n') {
        printf("Nepareiza izvēle. Lūdzu ievadiet 'c', 'i' vai 'l'.\n");
        return 1;
    }

    if (skaitlis < 0) {
        printf("Nepareiza ievade. Lūdzu ievadiet pozitīvu skaitli.\n");
        return 1;
    }

    rezultats = faktorials(skaitlis);

    switch (izvele) {
        case 'c':
            if (rezultats <= (long long)127 && rezultats >= (long long)-128)
                printf("Faktoriāls: %lld\n", rezultats);
            else
                printf("Nepareiza ievade. Ar char datu tipu nav iespējams aprēķināt faktoriālu šim skaitlim.\n");
            break;
        case 'i':
            if (rezultats <= (long long)2147483647 && rezultats >= (long long)-2147483648)
                printf("Faktoriāls: %lld\n", rezultats);
            else
                printf("Nepareiza ievade. Ar int datu tipu nav iespējams aprēķināt faktoriālu šim skaitlim.\n");
            break;
        case 'l':
            printf("Faktoriāls: %lld\n", rezultats);
            break;
        default:
            printf("Nepareiza izvēle. Lūdzu ievadiet 'c', 'i' vai 'l'.\n");
            return 1; 
    }

    return 0;
}

long long faktorials(int skaitlis) {
    long long rezultats = 1;

    for (int i = 1; i <= skaitlis; i++) {
        rezultats *= i;

        if (rezultats < 0) {
            printf("Rezultāts ir pārāk liels. Faktoriālu nevar aprēķināt ar izvēlēto datu tipu.\n");
            return -1; 
        }
    }

    return rezultats;
}
