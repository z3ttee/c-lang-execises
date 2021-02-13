#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, const char *argv[])
{
    srand(time(NULL));

    int currentNumber = 0;
    int lastNumber;
    int tries = 0;

    do {
        lastNumber = currentNumber;
        currentNumber = rand() % 6 + 1;
        ++tries;
        printf("%3d. Wurf: %d\n", tries, currentNumber);
    } while(!((lastNumber == 6) && (currentNumber == 6)));

    printf("\n Du hast nach %d Versuchen zwei 6er hintereinander gewürfelt!\n", tries);
    return 0;
}
