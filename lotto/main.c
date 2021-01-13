#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define LOTTO_NUMBER_MAX 49
#define NUMBER_DRAWS 6

int main(int argc, const char *argv[])
{
    // Erzeuge random werte
    srand(time(NULL));

    // Lege das array an
    bool arr[LOTTO_NUMBER_MAX];

    // Setze alle werte auf false
    for(int i = 0; i < LOTTO_NUMBER_MAX; ++i) {
        arr[i] = false;
    }

    // Ziehung
    for(int i = 0; i < NUMBER_DRAWS; ++i) {
        int z;

        do {
            z = rand() % LOTTO_NUMBER_MAX;
        } while (arr[z]);

        arr[z] = true;
    }

    // Gezogene Zahlen ausgeben, true bedeutet Ziehung
    printf("\nDas sind die Lottozahlen:\n");
    for(int i = 0; i < LOTTO_NUMBER_MAX; ++i) {

        if(arr[i]) {
            printf(">> %d\n", i+1);
        }
    }
    return 0;
}
