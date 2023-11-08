#include <stdio.h>
#include <string.h>

int main(){

     char input[100];
     printf("Ievadi teikumu: ");
     fgets(input, sizeof(input), stdin);

     int sk = 0;
     for (int i = 0; input[i]!= '\0'; i++){

          if (input[i] != ' ' && input[i] != '\n'){
               sk++;
               }
     }
     printf("Burtu skaits teikumā, neskaitot atstarpes: %d\n", sk);

     return 0;

 }


