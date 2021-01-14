// Unser drittes Programm: Hallo mit Ausgabe eines oder mehrerer Namen
//
// Aufruf: hello3 name1 name2 ...
//
// Klaus Kusche, 2010

#include <stdio.h>

int main(int argc, const char *argv[])
{
    if (argc == 1) {
        printf("Hallo, ich bin \"%s\"! Wer bist du?\n", argv[0]);
    } else if (argc > 10) {
        printf("Hallo an alle!");
    } else {
        // Wie in Aufgabe verlangt
        for (int i = 1; i < argc; ++i) {

            if(i == 1) {
                printf("Hallo, %s, du bist Erster!\n", argv[i]);
            } else {
                printf("Hallo, %s, %d. Platz\n", argv[i], i);
            }
        }

        // Erweiterung, Liste in umgekehrter Reihenfolge ausgeben
        printf("\nUnd jetzt in umgekehrter Reihenfolge!\n\n");

        for (int i = (argc-1); i > 0; --i) {
            if(i == argc-1) {
                printf("Hallo, %s, du bist Erster!\n", argv[i]);
            } else {
                printf("Hallo, %s, %d. Platz\n", argv[i], argc-i);
            }
        }

        // Alle namen in einer reihe ausgeben
        printf("\nUnd jetzt alle in einer Reihe!\n\n");
        for (int i = 1; i < argc; ++i) {
            if(i == 1) {
                printf("Hallo, %s", argv[i]);           // Beim ersten Hallo, name
                if(i == argc-1) printf("!");            // wenn gleichzeitig letzte, ausgabe von !
            } else if(i == argc-1) {
                printf(" und %s !\n", argv[i]);         // Nach dem letzen ! und neue Zeile
            } else {
                printf(", %s", argv[i]);                // Ausgabe ,name
            }
        }

        printf("\n\nIhr seid insgesamt %d Leute.\n", (argc-1));
    }

    return 0;
}
