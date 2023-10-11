#include <stdio.h>
#define N 10
#define X 7

int main(void)
 {
 //int N; NB! nedrīksti mainīt
 //N = 10; NEDRĪKST!


 int i = 0;
 printf("i mainīgā sākuma vērtība: %d\n", i);

 i = i + 1;

 while(i<=N)//10 <= 10 rezultats ir 1 decimali, bet citās prog valodās ir true vai false
  {
  printf("(%d.) i mainīgā nākamā vērtība - %d (un tā ir mazāka par %d)\n",i,i,N);
  i = i + 1; //NB! obligāti jāmaina i vērtība, lai nav mūžīgais cikls!!!!!!
  if(i == X)
   {
   printf("X vērtība ir trāpijusies, viss, aprēķinu iozbeidzām!\n");
   break;
   }

 }
 printf("(%d.) i mainīgā nākamā vērtība ir kļuvusi par %d\n",N);
 printf("Viss, skaīšanu apturam!\n");


return 0;
 }
