#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    if(argc < 3){
        printf("\nBitte gib zwei Zahlen an!\n");
        return 0;
    }

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int r = 0;

    int zahler = a;
    int nenner = b;

    if(nenner == 0){
        printf("\nEine Zahl kann nicht durch 0 geteilt werden!\n");
        return 0;
    }

    // Absolutwerte bilden
    a = abs(a);
    b = abs(b);

    while(b != 0) {
        r = a % b;
        a = b;
        b = r;
    }

    zahler /= a;
    nenner /= a;

    // Wenn der nenner negativ, multipliziere bruch mit -1
    if(nenner < 0) {
        nenner *= -1;
        zahler *= -1;
    }

    printf("\nDer gesuchte ggT ist: %d\n", a);

    if(nenner == 1) {
        printf("Der gekuerzte Bruch ist: %d\n", zahler);
    } else {
        printf("Der gekuerzte Bruch ist: %d/%d\n", zahler, nenner);
    }

    return 0;
}
