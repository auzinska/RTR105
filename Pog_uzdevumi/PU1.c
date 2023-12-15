#include <stdio.h>
#include <stdlib.h>

int main() {

    int pirmaisSkaitlis, otraisSkaitlis, rezultats;

    printf("Ievadiet pirmo skaitli: ");
    scanf("%d", &pirmaisSkaitlis);

    printf("Ievadiet otro skaitli: ");
    scanf("%d", &otraisSkaitlis);

    rezultats = pirmaisSkaitlis * otraisSkaitlis;
    printf("Reizināšanas rezultāts: %d\n", rezultats);

    return 0;
}
