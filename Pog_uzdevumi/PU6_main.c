#include <stdio.h>

//Bez argumentiem un bez return
void printHello() {
    printf("Labdien, lietotāj!!!\n");
}

//Ar argumentiem un bez return
void printMessage(char message[]) {
    printf("Ziņojums: %s\n", message);
}

//Bez argumentiem un ar return
int generateRandomNumber() {
    return rand() % 100; 
}

//Ar argumentiem un ar return
int addNumbers(int a, int b) {
    return a + b;
}

int main() {
    //Funkcijas izsauksana
    printHello();

    char message[] = "Ziņojums no funkcijas!";
    printMessage(message);

    int randomNumber = generateRandomNumber();
    printf("Šī vakara loto skaitlis: %d\n", randomNumber);

    int sum = addNumbers(5, 7);
    printf("Summa no kaut kādiem skaitļiem: %d\n", sum);

    return 0;
}
