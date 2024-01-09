# 2.Laboratorijas darba aizstāvēšana, "Skaitliskās metodes; Dihotomijas metode"


## Man piešķirtā funkcija - y(x) = sin(x/2)


## Darba mērķis:
Izpētīt un implementē dihotomijas metodifunkcijai sin(x/2), atrodot funkcijas saknes 
noteiktā diapazonā ar noteiktu precizitāti, izmantojot programmu C valodā.


## Darba gaita:

1.Pēc dotās "Skaitliskās metodes" teorijas, savai funkcijai atrast saknes 
pēc lietotāja noteikta diapazona, ņemot vērā nobīdi un precizitāti pēc ievades.

2.Uzrakstīt programmu, lai tā uz ekrāna izvada:

    1.dialogu ar lietotāju a vērtības iegūšanai
    2.dialogu ar lietotāju b vērtības iegūšanai
    3.dialogu ar lietotāju c vērtības iegūšanai
    4.dialogu ar lietotāju precizitātes vērtības iegūšanai
    5.aprēķināto x vērtību, kas atbilst f(x)=c vienādojumam, x starp a un b
    6.aprēķināto f(x) vērtību šim x
    7.nepieciešamo iterāciju skaitu, lai aprēķinātu šo x vērtību ar uzdoto precizitāti


3.Grafiski parādīt funkciju un funkciju pēc nobīdes ar gnuplot palīdzību

## Risinnāšana un darba izpilde un tās rezultāti:

Kods c valodā (Atrodams: https://github.com/auzinska/RTR105/blob/main/2LD_roots/rob_main.c)
```
c
#include <stdio.h>
#include <math.h>

int main() {
    float a, b, bc, ac, nac, nbc, c, x, delta_x, funkca, funkcb, funkcx;

    printf("Ievadiet funkcijas a vertibu:\n");
    if (scanf("%f", &a) != 1) {
        printf("ERROR: Netika ievadīts skaitlis!\n");
        return 1;
    }

    printf("Ievadiet funkcijas b vertibu:\n");
    if (scanf("%f", &b) != 1) {
        printf("ERROR: Netika ievadīts skaitlis!\n");
        return 1;
    }

    printf("Ievadiet funkciju nobīdes vertibu, kas nobīdīs abas funkciju, jeb c:\n");
    if (scanf("%f", &c) != 1) {
        printf("ERROR: Netika ievadīts skaitlis!\n");
        return 1;
    }

    printf("Ievadiet precizitātes vērtību (vēlams, ka līdz 0.0001):\n");
    if (scanf("%f", &delta_x) != 1) {
        printf("ERROR: Netika ievadīts skaitlis!\n");
        return 1;
    }

    int k = 0;

    funkca = sin(a / 2);
    funkcb = sin(b / 2);
    ac = a - c;
    bc = b - c;

    if (funkca * funkcb > 0) {
        printf("Intervālā [%.2f;%.2f] sin(x/2) funkcijai pēc nobīdes %.2f sakņu nav (vai tajā ir pāru sakņu skaits).\n", a, b, c);
        return 1;
    }

    printf("Intervālā [%.2f;%.2f] sin(x/2) funkcijai pēc nobīdes %.2f ar precizitāti delta_x=%.4f\n", ac, bc, c, delta_x);

    printf("sin(%7.3f)=%7.3f\t\t\t\t", a, sin(a));
    printf("sin(%7.3f)=%7.3f\n", b, sin(b));

    while ((b - a) > delta_x) {
        k++;
        x = (a + b) / 2.0;

        if (funkca * sin(x / 2) > 0)
            a = x;
        else
            b = x;

        printf("%2d. iterācija: sin(%7.3f)=%7.3f\t", k, a, sin(a / 2));
        printf("sin(%7.3f)=%7.3f\t", x, sin(x / 2));
        printf("sin(%7.3f)=%7.3f\n", b, sin(b / 2));
    }

    nac = sin((a - c) / 2);
    nbc = sin((b - c) / 2);

    printf("Sakne atrodas pie x=%.3f, jo sin(x) ir %.3f pēc nobīdes c=%.3f, ir a=%.3f, b=%.3f ar precizitāti delta_x=%.4f\n", x, sin(x / 2), c, nac, nbc, delta_x);

    return 0;
}

```
Piebilde: Kods nav kā Ortusā dotais kods, jo šajā kodā ir savienots galvenās funkcijas kods ar nobīdes kodu vienā. 
Īsāk sakot, divu kodu vietā tika uzrakstīts viens.


Grafiskā attēlošana ar gnuplot (Ir redzami grafiki y = sin(x/2); y = 1; y = sin(x/2)-0.5; y = 0.5 ):

Gnuplot ievade:
```
plot [10:-10] sin(x/2)
replot 1
replot sin(x/2) - 0.5
replot 0.5
```

Grafiks:

![LD2_grafiks](https://github.com/auzinska/RTR105/blob/main/2LD_roots/LD_2_grafiks.png)

## Rezultātu iegūšanas attēlošana:

Sin(x/2) aprēķināšana:

Ievadi argumentu: 5

sin(5/2)=0.60

a0 = 2.5 
S0 = 2.5

a499 = -0.00
S499 = 0.60

a500 = 0.00
S500 = 0.60
```         
         500
        _____
        \            k    2*k+1 
          \      (-1) * x
sin(5/2) = >  _______________________
          /                  2*k+1
        /       (2*k+1)! * 2
        _____
         k=0
```
Rekurences reizinātājs: 
```
        2
       X
________________
        2
  16 * k + 8
```
Rezultāta piemērs (Koda izvade, ja k iet līdz 5 un x = 5)

![teylor_kods_LD1](https://github.com/auzinska/RTR105/assets/50238747/fead361d-c57a-423b-bcc6-357e1c07b8d4)
