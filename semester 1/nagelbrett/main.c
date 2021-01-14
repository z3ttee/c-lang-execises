#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, const char *argv[])
{
    srand(time(NULL));

    if(argc < 3) {
        printf("Gib die Anzahl der Reihen und die Anzahl der Kügeln an!");
        return 0;
    }

    int rows = atoi(argv[1]);
    int marbles = atoi(argv[2]);
    int bowlsSize = rows;

    if(rows < 0 || marbles < 0) {
        printf("Negative Werte sind nicht erlaubt!");
        return 0;
    }

    int bowls[bowlsSize];
    for(int i = 0; i < bowlsSize; ++i) {
        bowls[i] = 0;
    }

    // Jede Kugel simulieren
    for(int i = 0; i < marbles; ++i) {
        int stepsRight = 0;

        for(int k = 0; k < rows; ++k) {
            int random = rand() % 2;
            if(random == 1) ++stepsRight;
        }

        bowls[stepsRight] = bowls[stepsRight]+1;
    }

    for(int i = 0; i < bowlsSize; ++i) {
        printf("%d. Schale: %d Kugeln\n", i+1, bowls[i]);
    }

    return 0;
}
