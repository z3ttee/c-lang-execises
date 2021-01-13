#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    if(argc < 2) {
        printf("\nBitte gib eine Zahl ein!\n");
        return 0;
    }

    int n = atoi(argv[1]);

    if(n == 0 || n == 1) {
        printf("\n%d\n", n);
        return 0;
    }

    for(int teiler = 2; n > 1; ++teiler) {
        int numberOfDivisions = 0;

        while(n % teiler == 0){
            ++numberOfDivisions;
            n /= teiler;
        }

        if(numberOfDivisions > 1) {
            printf("%d^%d ", teiler, numberOfDivisions);
        } else if(numberOfDivisions != 0) {
            printf("%d ", teiler);
        }

    }

    return 0;
}
