/* fopen example */
#include <stdio.h>
int main ()


{
  FILE * pFile;
  char c;
  pFile = fopen ("fopen.txt","w+");
  if (pFile!=NULL)
  {
    printf ("norāde uz failu- %p\n",pFile);
    scanf("%c",&c);
    fputs ("Papildinatais teksts:\n",pFile);
    fclose (pFile);
  }

  else
  {
    fputs("fopen- failu nav izdevies atvērt ERROR404\n",stderr);
  }
  return 0;
}

