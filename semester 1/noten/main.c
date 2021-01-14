#include <stdio.h>
#include <stdlib.h>

#define MAX_MARKS 5
#define LINE_LEN 80

int main(int argc, const char *argv[])
{
    if(argc < 1) {
        printf("\nBitte gib mindestens eine Note ein!\n");
        return 0;
    }

    int marksArr[MAX_MARKS] = { 0 };

    for(int i = 1; i < argc; ++i) {
        int mark = atoi(argv[i]);
        if(mark < 1 || mark > 5) {
            printf("\n%d ist keine gueltige Note!\n", mark);
            return 0;
        } else {
            marksArr[mark-1] = marksArr[mark-1]+1;
        }
    }

    int maxAmount = 0;
    for(int i = 0; i < MAX_MARKS; ++i) {
        int amount = marksArr[i];
        if(maxAmount < amount) {
            maxAmount = amount;
        }
    }

    double lenFactor = LINE_LEN/maxAmount;

    for(int k = 0; k < MAX_MARKS; ++k) {

        int amount = marksArr[k];
        int balken = lenFactor*amount;
        int mark = k+1;

        printf("Note %d: | %4d | ", mark, amount);
        for(int n = 0; n < balken; ++n) {
            printf("=");
        }
        printf("\n");
    }

    return 0;
}
