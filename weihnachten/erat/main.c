#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ARRAY_SIZE 10000000

bool numbers[MAX_ARRAY_SIZE];

int main(int argc, const char *argv[])
{
    if(argc < 2) {
        printf("\nDu musst eine Grenze bis %d eingeben.", MAX_ARRAY_SIZE);
        return 0;
    }

    int max = atoi(argv[1]);

    if(max > MAX_ARRAY_SIZE) {
        printf("\nDu musst eine Grenze bis %d eingeben.", MAX_ARRAY_SIZE);
        return 0;
    }

    // Alle Elemente auf true setzen
    for(int i = 0; i < max; ++i) {
        numbers[i] = true;
    }

    // Alle Primzahlen durchgehen, beginne bei 2 (index: 1)
    printf("\nFolgende Zahlen sind Primzahlen innerhalb der Grenze %d:\n\n>> 1\n", max);
    for(int i = 1; i < max; ++i) {
        bool isPrime = numbers[i];
        int number = i+1;

        if(isPrime){
            printf(">> %d\n", number);

            // Streiche alle vielfachen
            // z.B. 2 -> jedes zweite -> i+=2
            // z.B. 4 -> jedes vierte -> i+=4
            for(int k = i; k < max; k+=number) {
                numbers[k] = false;
            }
        }

    }

    return 0;
}
