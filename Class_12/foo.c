#include "foo.h"    /* Always include the header file that declares something
                     * in the C file that defines it. This makes sure that the
                     * declaration and definition are always in-sync.  Put this
                     * header first in foo.c to ensure the header is self-contained.
#include <string.h>
  
                   */

#include <string.h>
#include <stdio.h>
 /**
 * This is the function definition.
 * It is the actual body of the function which was declared elsewhere.
 */
void foo(int id, char *name)
{
    fprintf(stderr, "foo(%d, \"%s\");\n", id, name);
    /* This will print how foo was called to stderr - standard error.
     * e.g., foo(42, "Hi!") will print `foo(42, "Hi!")`
     */
    printf("name atrašanās vieta atmiņa: %p\n",name);
    printf("name vērtiba: %s\n",name);
    printf("name adreses atrašanās vieta atmiņa: %p\n",&name);
//no foo funkcijas ^ >
    printf("id atrašan/ās vieta atmiņa: %p\n",&id);
    printf("id vērtiba: %d\n",id);


    //name = "car" //NB! tā tas ar simbolu masivu nestrādā
    strcpy(name, "car");
    //strmcpy
    //memcpy < tikai shie strada
    id = 50;

}
