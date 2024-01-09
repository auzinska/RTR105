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
