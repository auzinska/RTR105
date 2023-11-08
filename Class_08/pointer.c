#include <stdio.h>


int main()
{
     char a = 'A';
     int b = 5;
     double c = 3.6;

     printf("sideof funkcijas a rezultāta izmērs: %lu\n", sizeof(sizeof(a)));
     printf("sideof funkcijas b rezultāta izmērs: %lu\n", sizeof(sizeof(b)));
     printf("sideof funkcijas c rezultāta izmērs: %lu\n\n", sizeof(sizeof(c)));

     printf("a mainīgā adrese - %p\n", &a);
     printf("a mainīgā adreses izmers - %lu\n",sizeof(&a));
     printf("vērtība pēc šīs adreses - %d\n",*(&a));
     printf("vērtības izmērs baitos pēc adreses -  %lu\n\n", sizeof(*(&a)));

     printf("b mainīgā adrese - %p\n", &b);
     printf("b mainīgā adreses izmers - %lu\n",sizeof(&b));
     printf("vērtība pēc šīs adreses - %d\n",*(&b));
     printf("vērtības izmērs baitos pēc adreses -  %lu\n\n", sizeof(*(&b)));

     printf("c mainīgā adrese - %p\n", &c);
     printf("c mainīgā adreses izmers - %lu\n",sizeof(&c));
     printf("vērtība pēc šīs adreses - %.1f\n",*(&c));
     printf("vērtības izmērs baitos pēc adreses -  %lu\n\n", sizeof(*(&c)));

     return 0;


}
