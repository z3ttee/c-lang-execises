#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    if(argc < 2) {
        printf("\nDu musst die Anzahl Zeilen angeben!\n");
        return 0;
    }

    int rows = atoi(argv[1]);

    if(rows < 1) {
        printf("\nBitte gib eine Zahl größer als 1 an!\n");
        return 0;
    }

    // Array anlegen
    int pascal[rows][rows];

    // Spalte 0: Alle Zeilen auf 1 setzen
    for(int z = 0; z < rows; ++z) {
        pascal[z][0] = 1;
    }

    // Alle Spalten (außer 0) werden in Zeile 0 auf Wert 0 gesetzt
    for(int s = 1; s < rows; ++s) {
        pascal[0][s] = 0;
    }

    // Vorherige Zeile, gleiche Spalte + Vorherige Zeile, linke spalte
    for(int z = 1; z < rows; ++z) {
        for(int s = 1; s < rows; ++s) {
            pascal[z][s] = pascal[z - 1][s] + pascal[z - 1][s - 1];
        }
    }

    // Array ausgeben
    printf("\n");
    for(int z = 0; z < rows; ++z) {
        for(int s = 0; s < rows; ++s) {
            int number = pascal[z][s];

            if(number != 0) {
                printf("%5d", pascal[z][s]);
            }
        }

        printf("\n");
    }
    return 0;
}
