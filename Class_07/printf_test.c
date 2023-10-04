/* scanf example */
#include <stdio.h>

int main ()
{
  char str [80];
  int i;

  printf ("Ievadiet vārdu: ");
  scanf ("%79s",str);  
  printf ("Ievadiet vecumu: ");
  scanf ("%d",&i);
  printf ("Sveicinati! %s, Jusu vecums:  %d \n",str,i);  
  return 0;
}
