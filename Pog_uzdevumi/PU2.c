#include <stdio.h>

int main() {

    unsigned char skaitlis;

    // Ievada naturālu skaitli
    printf("Ievadiet naturālu skaitli: ");
    scanf("%hhu", &skaitlis);


    printf("Binārais kods: ");
    for (int i = 7; i >= 0; i--) {
        unsigned char bitaVertiba = (skaitlis >> i) & 1;
        printf("%d", bitaVertiba);
    }
    
    printf("\n");

    return 0;
}
