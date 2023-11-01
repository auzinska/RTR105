/* fwrite example : write buffer */
#include <stdio.h>

int main ()
{
  FILE * pFile;
  char buffer[] = { 0x78 , 0x79 , 0x7a };
  pFile = fopen ("myfile.bin", "wb");
//  fwrite (buffer , sizeof(char), sizeof(buffer), pFile);
  fwrite (buffer , sizeof(int), sizeof(buffer)/sizeof(int), pFile);


  fclose (pFile);
  return 0;
}
