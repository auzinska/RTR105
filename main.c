#include "foo.h"

int main(void)
{
    //char *name_main = "bar";
    char name_main[] = "bar";
    printf("name_main atrašanās vietas atmiņā: %p\n", name_main);
    printf("name_main vērtība prims foo izpildīšanas : %s\n", name_main);
    
    int id_main = 42;
    printf("name_main atrašanās vietas atmiņā: %p\n", name_main);
    printf("name_main vērtība pirms foo izpildīšanas : %d\n\n", name_main);

    //foo(42, "bar" )

    printf("/nname_main atrašanās vietas atmiņā: %p\n", name_main);
    printf("id_main vērtība pēc foo izpildīšanas : %s\n", name_main);

    foo(id_main, name_main);
    printf("/nname_main atrašanās vietas atmiņā: %p\n", name_main);
    printf("id_main vērtība pēc foo izpildīšanas : %d\n\n", name_main);

    return 0;
}
