#include <stdio.h>
#define N 3


int main(void)
 {
 //int N; NB! nedrīksti mainīt
 //N = 10; NEDRĪKST!


 int i = 0;
 printf("i mainīgā sākuma vērtība: %d\n", i);

 i = i + 1; // te ir DIVAS operācijas- piešķiršana un saskaitīšana
	    // saskaitīšanai ir lielākā prioritāte => tā tiks izpildīta pirmā
	    //izpildīta pirmā un tad + operācijas tiks iefietots
	    //atmiņā (vieta, uz kuru norāda identifikātors pa kreisi)
 if(i<=N)
 {
 printf("i mainīgā nākamā vērtība - %d (un tā ir mazāka par %d)\n",i,N);
 }
 else
 {
 printf("i mainīgā nākamā vērtība ir kļuvusi par %d\n",N);
 printf("Viss, skaīšanu apturam!\n");
 return 0;
 }

 if(i<=N)
 {
 printf("i mainīgā nākamā vērtība - %d (un tā ir mazāka par %d)\n",i,N);
 }
 else
 { 
 printf("i mainīgā nākamā vērtība ir kļuvusi par %d\n",N);
 printf("Viss, skaīšanu apturam!\n");
 return 0;
 }

 if(i<=N)
 {
 printf("i mainīgā nākamā vērtība - %d (un tā ir mazāka par %d)\n",i,N);
 }
 else
 { 
 printf("i mainīgā nākamā vērtība ir kļuvusi par %d\n",N);
 printf("Viss, skaīšanu apturam!\n");
 return 0;
 }

 if(i<=N)
 {
 printf("i mainīgā nākamā vērtība - %d (un tā ir mazāka par %d)\n",i,N);
 }
 else
 { 
 printf("i mainīgā nākamā vērtība ir kļuvusi par %d\n",N);
 printf("Viss, skaīšanu apturam!\n");
 return 0;
 }

 if(i<=N)
 {
 printf("i mainīgā nākamā vērtība - %d (un tā ir mazāka par %d)\n",i,N);
 }
 else
 { 
 printf("i mainīgā nākamā vērtība ir kļuvusi par %d\n",N);
 printf("Viss, skaīšanu apturam!\n");
 return 0;
 }

 if(i<=N)
 {
 printf("i mainīgā nākamā vērtība - %d (un tā ir mazāka par %d)\n",i,N);
 }
 else
 { 
 printf("i mainīgā nākamā vērtība ir kļuvusi par %d\n",N);
 printf("Viss, skaīšanu apturam!\n");
 return 0;
 }
return 0;
 }
