# RTR105

Studiju kursa datorzinībāš (pamatkurss) elektroniskā kade

## pirmās nodarbības atziņas

**Bold** un __Bold__

*Italic* un _Italic_

~~Nosvītrots~~

***Bold un irtalic***

<sub>Subskribēts?</sub>

>citāts; *Citāts un italic;* **citāts un BOLD;** ***citāts un abi***
1. Uzskaite
   - Noskaite
     - Atskaite?
>[!NOTE]
>Trakas lietas, idk

<!-- Neredzams komentārs -->

# 2. lekcija
man ls

<sub>ls -l</sub> 

#<sub>ls -l -t</sub>

<sub>home/user = ~</sub>

<sub>mkdir = uztaisa mapi</sub>

<sub>rmdir = izdzēst mapi</sub>

<sub>echo 12345 > a.txt txt faila izveide/papildinājums</sub>

<sub>hexdump -C a.txt parāda vērtības hexdec veidā</sub>

<sub>cat a.txt ir lasīt</sub>

<sub>echo 123123123 >> a.txt papildina iepriekšējo</sub>

<sub>man echo=manual</sub>

<sub>history > history_20230913_class_02.txt</sub>

<sub>find ./myfolder -mindepth 1 ! -regex '^./myfolder/test2\(/.*\)?' -delete</sub>   

<sub>rm -d -- *[!0-9]</sub>

<sub> mv hihi.dat ~/DEF/ vai ./DEF/ MOVE UZ FOLDER</sub>

<sub>mv DEF/hihi.dat DEF/hihihi.exe</sub>

<sub>rm -r DEF</sub>


<sub>
diff history_20230913_class_02.txt history_20230913_class_03.txt > template.txt
cat template.txt 
</sub>

## Komandas
<sub>nano mana_komanda_1.sh (aver teksta redaktoru scripta shell valodā)</sub>

<sub>script =! kods</sub>

<sub>#!/bin/bash  vai  bin/python for ez </sub>

<sub>
#!/bin/bash </sub>

<sub>
cd </sub>

<sub>mkdir ABC</sub>

<sub>
echo "123456" > a.txt
</sub>

<sub>
mv a.txt ABC/b.txt
</sub>

<sub>
echo "789" >> ABC/b.txt
</sub>

<sub>
cat ABC/b.txt
</sub>

<sub>
echo "manas 1.komandas izpilde ir pabeigta"
</sub>

<sub>chmod 754 mana_komanda_1 (nomaina ties\ibas caur bin kodu 111 101 100</sub>

3.Lekcija

<sub>git clone https://github.com/auzinska/RTR105</sub>

<sub>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</sub>

<sub>rm -rf RTR105</sub>

<sub> history | grep clone</sub>



<sub>user@epk428-4:~/RTR105/Class_05$ nano second.c 
user@epk428-4:~/RTR105/Class_05$ ls -lt
total 28
-rw-rw-r-- 1 user user    57 Sep 27 09:18 second.c
-rwxrwxr-x 1 user user 16696 Sep 27 09:17 a.out
-rw-rw-r-- 1 user user    96 Sep 27 09:03 first.c
user@epk428-4:~/RTR105/Class_05$ nano second.c 
user@epk428-4:~/RTR105/Class_05$ gcc second.c 
user@epk428-4:~/RTR105/Class_05$ ./a.out
Hello World!user@epk428-4:~/RTR105/Class_05$ 
</sub>

<sub>
#include <stdio.h>

int main()

 {

 printf("Hello World!\n");
 printf("\a");

 return 0;
 }

</sub>

<sub>history -a</sub>
<sub>user@epk428-4:~/RTR105/Class_05$ gcc -E second.c > second.i
</sub>
<sub>

Variables c valodā

#include <studio.h>

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

 return 0;
 
 }


</sub>

<sub>
Ir nepieciešamības:
   Pildīt vai nepildīt koda kādu daļu

   Atkārtot secīgi pildīt 
</sub>



#include <stdio.h>
#include <stdbool.h>

bool isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int main() {
    char input[100];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    int wordCount = 0;
    int letterCount = 0;
    bool insideWord = false;

    for (int i = 0; input[i] != '\0'; i++) {
        if (isLetter(input[i])) {
            letterCount++;
            if (!insideWord) {
                insideWord = true;
            }
        } else {
            if (insideWord && letterCount >= 5) {
                wordCount++;
            }
            insideWord = false;
            letterCount = 0;
        }
    }

    if (insideWord && letterCount >= 5) {
        wordCount++;
    }

    printf("Number of words with 5 or more letters without spaces: %d\n", wordCount);
    return 0;
}

