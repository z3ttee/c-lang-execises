#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    if(argc < 3){
        printf("\nBitte gib min. zwei Zahlen ein!\n");
        return 0;
    }

    int max = atoi(argv[1]);
    int min = max;
    int maxPos = 1;
    int minPos = 1;

    for(int i = 2; i < argc; ++i) {
        int number = atoi(argv[i]);

        if(number < min) {
            min = number;
            minPos = i;
        }
        if(number > max) {
            max = number;
            maxPos = i;
        }
    }

    if(min == max) {
        printf("\nKein Minimum/Maximum berechenbar: Alle Zahlen sind gleich!\n");
    } else {
        printf("\nDas Minimum ist %d und befindet sich an Position %d\n", min, minPos);
        printf("Das Maxmimum ist %d und befindet sich an Position %d\n", max, maxPos);
    }

    return 0;
}
