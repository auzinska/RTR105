#undef __STRICT_ANSI__

#include <stdio.h>
#include <math.h>

int main()
{
    FILE *pFile;
    float a = 0., b = 2 * M_PI, x, delta_x = 1.e-2, sin_prim, delta_y, dub_y, dub_x;
    // floaty;
    pFile = fopen("derivative.dat", "w");
    // printf("\tx\t\tsin(x)\t\tsin\'(x)\n");
    fprintf(pFile, "\tx\t\tsin(x)\t\tsin\'(x)\tdelta_y\tdub_x\n");
    x = a;
    while (x < b)
    {
        sin_prim = (sin(x + delta_x) - ((sin(x + delta_x) - sin(x))) / delta_x);
        delta_y = (sin(x + delta_x) - (sin(x + delta_x) - sin_prim)) / delta_x;

        dub_x = ;
        dub_y = delta_y / sin_prim;
        // y=sin(x);
        // printf("%10.2f\t%10.2f\t%10.2f\n",x,sin(x),(sin(x+delta_x)-sin(x))/delta_x);
        fprintf(pFile, "%10.2f\t%10.2f\t%10.2f\t%10.2f\t%10.2f\n", x, sin(x), sin_prim, delta_y, dub_y);
        // printf(”%10.2f\t%10.2f\n”,x,y);
        x += delta_x; // x=x+delta_x;

        //delta_y

    }
    fclose(pFile);
    return 0;
}