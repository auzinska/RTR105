#include <stdio.h>
#include <math.h>

int main()
{
    FILE *pFile;
    float a, b, x, delta_x, sin_prim, delta_y, dub_y;

    // lietotāja ievade
    printf("Ievadiet skaitlisku a vērtību (piem. 0): ");
    if (scanf("%f", &a) != 1)
    {
        printf("Nepareiza ievade. Ievadiet skaitli.\n");
        return 1; // Beidz programmu ar kļūdas kodu
    }

    printf("Ievadiet skaitlisku b vērtību (piem. 6.28): ");
    if (scanf("%f", &b) != 1)
    {
        printf("Nepareiza ievade. Ievadiet skaitli.\n");
        return 1; // Beidz programmu ar kļūdas kodu
    }

    // Iegūst precizitātes no lietotāja
    printf("Ievadiet precizitātes vērtību (līdz 0.0001): ");
    if (scanf("%f", &delta_x) != 1 || delta_x <= 0)
    {
        printf("Nepareiza ievade. Ievadiet pozitīvu skaitli lielāku par 0.\n");
        return 1; // Beidz programmu ar kļūdas kodu
    }

    // Atvēr failu
    pFile = fopen("derivative.dat", "w");
    if (pFile == NULL)
    {
        printf("Nevar atvērt failu derivative.dat.\n");
        return 1; // Beidz programmu ar kļūdas kodu
    }

    // header failā
    fprintf(pFile, "\tx\t\tsin(x/2)\t\tsin\'(x/2)\t\tdelta_y\t\tdub_y\n");

    x = a;
    while (x < b)
    {
        // Atvasinājuma analītiskais aprēķins
        sin_prim = cos(x/2);

        // Atvasinājuma skaitliskais aprēķins
        delta_y = ((sin((x + delta_x) / 2) - sin(x / 2)) / (delta_x / 2));
        dub_y = (delta_y / sin(x/2)) * delta_x;

        // dati uz failu
        fprintf(pFile, "%12.2f\t%12.2f\t%20.2f\t%20.2f\t%20.2f\n", x, sin(x/2), sin_prim, delta_y, dub_y);

        x += delta_x;
    }

    // Aizver failu
    fclose(pFile);

    return 0;
}
