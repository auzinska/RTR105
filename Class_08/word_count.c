#include <stdio.h>
#include <stdbool.h>

//tiek noteikts vārdu skaits, kuros burtu daudzums ir =< 5


//šeit tiek pateikts, ka isLetter(char c) ir "patiess" konkrētos diapazonos
bool isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int main() {
    char input[100];
    printf("Ievad teikum: ");
    fgets(input, sizeof(input), stdin);

    int wordCount = 0;
    int letterCount = 0;
    bool insideWord = false;

    for (int i = 0; input[i] != '\0'; i++) {
        if (isLetter(input[i])) {
            letterCount++;
            if (!insideWord) {
                insideWord = true;
            }
        } else {
            if (insideWord && letterCount >= 5) {
                wordCount++;
            }
            insideWord = false;
            letterCount = 0;
        }
    }

    if (insideWord && letterCount >= 5) {
        wordCount++;
    }

    printf("Vārdu skaits, kas lielaki vai vienādi par 5 burtiem...cerams: %d\n", wordCount);
    return 0;
}
