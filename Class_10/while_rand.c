#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main(void)
 {
 int flag = 1, counter = 0;
 int gadiijuma_skaitlju_generatora_grauds;

 gadiijuma_skaitlju_generatora_grauds = time(NULL); //laiks sekuindes kopš 01.01.1970._
 srand(gadiijuma_skaitlju_generatora_grauds);

 printf("Laiks sek kopš 01.01.1970. 00:00 - %d\n", gadiijuma_skaitlju_generatora_grauds);

 while(flag)
 {
  counter++;
  flag = rand();
 }

 printf("counter = %d (pēc cikla)\n",counter);
 return 0;
}
