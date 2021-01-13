#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, const char *argv[])
{
    if(argc < 2){
        printf("\n%s: Bitte gib eine Zahl ein!\n", argv[0]);
        return 0;
    }

    double number = atof(argv[1]);

    if(number < 0) {
        printf("\n%s: Eine negative Zahl hat keine Wurzel!\n", argv[0]);
        return 0;
    }

    double w = number;  // Näherungswert w
    int steps = 0;

    while (fabs(w * w - number) >= number * 1e-15) {
        w = (w + number / w) / 2;
        ++steps;

        printf("%d. Schritt: %.15g\n", steps, w);
    }

    printf("\n\nDie Berechnung benötigte insgesamt %d Naeherungsschritte zur Berechnung.\n", steps);
    printf("Die Wurzel aus %g ist: %.15g\n", number, w);
    printf("Zum Vergleich, Ergebnis der eingebauten Wurzel: %.15g", sqrt(number));
    return 0;
}
