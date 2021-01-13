#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    if(argc < 2){
        printf("\nBitte gib eine Zahl ein!\n");
        return 0;
    }

    int number = abs(atoi(argv[1]));
    int sum = 0;

    while(number > 0) {
        sum += number % 10;
        number /= 10;
    }

    printf("\nDie Quersumme lautet: %d\n", sum);

    while((sum/10) > 0) {
        number = sum;
        sum = 0;

        while(number > 0) {
            sum += number % 10;
            number /= 10;
        }

        printf("\nDie wiederholte Quersumme lautet: %d\n", sum);
    }

    return 0;
}
