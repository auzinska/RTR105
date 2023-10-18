#include <stdio.h>

int main(void)
 {
 int i; /*diskrētā mainīgā deklerēšana - noteikta izmēra atbilstosi datu tipam atmiņas apgabalā
       tipam -int => 4 bytes, lai uzzinatu ...
	atmiņas apgabala sasaisyšana ar norādīto identifikātoru
	NB! vertība
	 */
 printf("i mainīgā izmērs baitos(simbols): %ls\n",sizeof(i));
 printf("i mainīgā atrašanas vieta atmiņa(adrese jeb norāde): %p\n", i);


 printf("i mainīgā vērtiba uzreiz bez deklerēšanas(simbols): %c\n", i);
 printf("i mainīgā vērtiba uzreiz bez deklerēšanas(dec): %d\n", i);
 printf("i mainīgā vērtiba uzreiz bez deklerēšanas(oct): %#o\n", i);
 printf("i mainīgā vērtiba uzreiz bez deklerēšanas(hex): %x\n", i);
 printf("i mainīgā vērtiba uzreiz bez deklerēšanas(real): %f\n", i);
 printf("i mainīgā vērtiba uzreiz bez deklerēšanas(real): %e\n", i);


 printf("\n");
	/*
	mainīgā loma ir mainīties a



*/
 i = 25;
  printf("i mainīgā izmērs baitos(simbols): %ls\n",sizeof(i));
 printf("i mainīgā atrašanas vieta atmiņa(adrese jeb norāde): %p\n", &i);


 printf("i mainīgā vērtiba uzreiz pēc deklerēšanas(simbols): %c\n", i);
 printf("i mainīgā vērtiba uzreiz pec deklerēšanas(dec): %d\n", i);
 printf("i mainīgā vērtiba uzreiz pēc deklerēšanas(oct): %#o\n", i);
 printf("i mainīgā vērtiba uzreiz pēc deklerēšanas(hex): %x\n", i);
 printf("i mainīgā vērtiba uzreiz pēc deklerēšanas(real): %f\n", i);
 printf("i mainīgā vērtiba uzreiz pec deklerēšanas(real): %e\n", i);

 char c1 = 'A', c2 = 0x100;
 float f1 = 0.0456, f2 = 1.896e2;
 double d1, d2;

 printf("i mainīgā vērtiba uzreiz pēc deklerēšanas(simbols): %c\n", f1);
 printf("i mainīgā vērtiba uzreiz pec deklerēšanas(dec): %d\n", f1);
 printf("i mainīgā vērtiba uzreiz pēc deklerēšanas(oct): %#o\n", f1);
 printf("i mainīgā vērtiba uzreiz pēc deklerēšanas(hex): %x\n", f1);
 printf("i mainīgā vērtiba uzreiz pēc deklerēšanas(real): %f\n", f1);
 printf("i mainīgā vērtiba uzreiz pec deklerēšanas(real): %e\n", f1);


 printf("i mainīgā izmērs baitos(simbols): %ls\n",sizeof(c1));
 printf("i mainīgā atrašanas vieta atmiņa(adrese jeb norāde): %p\n", &c1);
 printf("i mainīgā izmērs baitos(simbols): %ls\n",sizeof(c2));
 printf("i mainīgā atrašanas vieta atmiņa(adrese jeb norāde): %p\n", &c2);
 printf("i mainīgā izmērs baitos(simbols): %ls\n",sizeof(f1));
 printf("i mainīgā atrašanas vieta atmiņa(adrese jeb norāde): %p\n", &f1);
 printf("i mainīgā izmērs baitos(simbols): %ls\n",sizeof(f2));
 printf("i mainīgā atrašanas vieta atmiņa(adrese jeb norāde): %p\n", &f2);
 printf("i mainīgā izmērs baitos(simbols): %ls\n",sizeof(d1));
 printf("i mainīgā atrašanas vieta atmiņa(adrese jeb norāde): %p\n", &d1);
 printf("i mainīgā izmērs baitos(simbols): %ls\n",sizeof(d2));
 printf("i mainīgā atrašanas vieta atmiņa(adrese jeb norāde): %p\n", &d2);

 printf("\n")

 float f3 = f1; //NB! mainīgā vērtības kopēšana
 printf("f1 mainīgā izmērs baitos(simbols): %ls\n",sizeof(f1));
 printf("f1 mainīgā atrašanas vieta atmiņa(adrese jeb norāde): %p\n", &f1);
 printf("f1 mainīgā vērtiba uzreiz pec deklerēšanas(real): %e\n", f1);

 printf("f3 mainīgā izmērs baitos(simbols): %ls\n",sizeof(f3));
 printf("f3 mainīgā atrašanas vieta atmiņa(adrese jeb norāde): %p\n", &f3);
 printf("f3 mainīgā vērtiba uzreiz pec deklerēšanas(real): %e\n", f3);

 int *i_adrese = &i;

 printf("i_adreses mainīgā izmērs baitos(simbols): %ls\n",sizeof(*i_adrese));
 printf("i_adreses mainīgā atrašanas vieta atmiņa(adrese jeb norāde): %p\n", *i_adrese);

 float *i_adrese_2 = *i_adrese;

 printf("i_adreses mainīgā izmērs baitos(simbols): %ls\n",sizeof(*i_adrese_2));
 printf("i_adreses mainīgā atrašanas vieta atmiņa(adrese jeb norāde): %p\n", *i_adrese_2);


 return 0;

}
