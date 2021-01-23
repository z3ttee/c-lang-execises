#include <stdio.h>
#include <stdlib.h>

unsigned int binom(int n, int k);

int functionCalls = 0;

int main(int argc, const char *argv[])
{
    if(argc < 3){
        printf("\nBitte gib n und k ein!\n");
        return 0;
    }

    int n = atoi(argv[1]);
    int k = atoi(argv[2]);

    int result = binom(n, k);

    printf("\nDas Ergebnis ist: %d\n", result);
    printf("Die Funktion wurde insgesamt %d-mal aufgerufen\n", functionCalls);
    return 0;
}

unsigned int binom(int n, int k) {
    ++functionCalls;

    if(k > n) {
        return 0;
    }

    if(k == 0 || k == n) {
        return 1;
    }

    return binom(n-1, k-1)+binom(n-1,k);
}
