#include <stdio.h>
#include <math.h>

double taisnstura_metode(double a, double b, int n) {
    double h = (b - a) / n;
    double integr = 0;

    for (int k = 0; k < n; k++) {
        integr += h * sin((a + (k + 0.5) * h) / 2);
    }

    return integr;
}

double trapeces_metode(double a, double b, int n) {
    double h = (b - a) / n;
    double integr = 0;

    for (int k = 1; k < n; k++) {
        integr += h * sin((a + k * h) / 2);
    }

    integr += (h / 2) * (sin(a / 2) + sin(b / 2));

    return integr;
}

double simpsona_metode(double a, double b, int n) {
    double h = (b - a) / n;
    double integr = 0;

    for (int k = 0; k < n; k++) {
        integr += (h / 6) * (sin((a + k * h) / 2) + 4 * sin((a + (k + 0.5) * h) / 2) + sin((a + (k + 1) * h) / 2));
    }

    return integr;
}

int main() {
    double a, b, eps;
    printf("Ievadiet a vērtību (vēlams 0): ");
    scanf("%lf", &a);
    printf("Ievadiet b vērtību (vēlams, kaut ko, kas ir robežās no 0 līdz 2*pi): ");
    scanf("%lf", &b);
    printf("Ievadiet precizitātes (eps) vērtību (vēlams 1e-6): ");
    scanf("%lf", &eps);

    int n = 2;
    double integr_taisnstura, integr_trapeces, integr_simpsona;

    // Taisnstūra metode
    integr_taisnstura = taisnstura_metode(a, b, n);
    while (1) {
        n *= 2;
        double integr_taisnstura_new = taisnstura_metode(a, b, n);
        if (fabs(integr_taisnstura_new - integr_taisnstura) < eps) {
            integr_taisnstura = integr_taisnstura_new;
            break;
        }
        integr_taisnstura = integr_taisnstura_new;
    }

    // Trapeces metode
    n = 2;
    integr_trapeces = trapeces_metode(a, b, n);
    while (1) {
        n *= 2;
        double integr_trapeces_new = trapeces_metode(a, b, n);
        if (fabs(integr_trapeces_new - integr_trapeces) < eps) {
            integr_trapeces = integr_trapeces_new;
            break;
        }
        integr_trapeces = integr_trapeces_new;
    }

    // Simpsona metode
    n = 2;
    integr_simpsona = simpsona_metode(a, b, n);
    while (1) {
        n *= 2;
        double integr_simpsona_new = simpsona_metode(a, b, n);
        if (fabs(integr_simpsona_new - integr_simpsona) < eps) {
            integr_simpsona = integr_simpsona_new;
            break;
        }
        integr_simpsona = integr_simpsona_new;
    }

    printf("Integrāļa vērtība ar taisnstūra metodi: %.6f\n", integr_taisnstura);
    printf("Integrāļa vērtība ar trapeces metodi: %.6f\n", integr_trapeces);
    printf("Integrāļa vērtība ar Simpsona metodi: %.6f\n", integr_simpsona);

    return 0;
}
