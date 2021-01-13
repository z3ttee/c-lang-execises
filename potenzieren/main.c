// Potenz zweier ganzer Zahlen (a hoch n)
// Programm-Skelett zur Angabe
//
// Aufruf: power a n
//
// Klaus Kusche, 2010

#include <stdio.h>
// Was steht in der Angabe zu atoi, was an dieser Stelle zu beachten ist?
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    // hat der Aufrufer überhaupt zwei Zahlen angegeben?
    // (damit argv[1] und argv[2] nicht "ins Leere greift")

    // Wenn nein: Fehlermeldung ausgeben, mit Fehlercode aufhören
    if(argc < 3) {
        printf("\nBitte definiere eine Basis und einen Exponenten!\n");
        return 0;
    }

    // argv[1] und argv[2] in Zahlen verwandeln
    // und in zwei dafür angelegten Variablen speichern
    int base = atoi(argv[1]);
    int exponent = atoi(argv[2]);

    // jetzt sollten wir noch prüfen,
    // ob wir es mit mathematisch sinnvollen Eingaben zu tun haben:
    // Bei ganzzahliger Rechnung können wir nur Exponenten >= 0 berechnen
    // Sonst: Fehlermeldung, aufhören!
    // (und "0 hoch 0" sollte auch ausgeschlossen werden, aber das sparen wir uns)
    if(exponent == 0){
        printf("\nDas Ergebnis ist: %d\n", 1);
        return 0;
    } else if(exponent < 0) {
        printf("\nBei ganzzahligen Rechnungen können nur positive Exponenten > 0 berechnet werden.\n");
        return 0;
    }

    // Wir brauchen eine Variable für das Ergebnis
    // im Ergebnis speichern wir als Anfangswert einmal 1,
    // damit wir weiter unten etwas dazumultiplizieren können
    int result = 1;

    // und dann kommt eine Schleife,
    // die von 1 bis zur zweiten Eingabe (einschließlich) zählt
    for(int i = 1; i <= exponent; ++i){
        // in der Schleife multiplizieren wir jedesmal
        // die erste Eingabe zum Ergebnis dazu
        // und speichern das wieder im Ergebnis
        result *= base;
    }

    // nach der Schleife kommt noch die Ausgabe ...
    printf("\nDas Ergebnis ist: %d\n", result);

    // ... und das Programm-Ende
    return 0;
}
