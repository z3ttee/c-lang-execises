#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, const char *argv[])
{
    if(argc % 2 != 0) {
        printf("\nDu musst eine valide Rechnung eingeben.\n");
        return 0;
    }

    double result = atof(argv[1]);

    for(int i = 2; i < argc; ++i) {
        char mathOperator = argv[i][0];
        ++i;
        double number = atof(argv[i]);

        switch(mathOperator) {
            case 'x':
                result *= number;
                break;
            case '+':
                result += number;
                break;
            case '-':
                result -= number;
                break;
            case '/':
                if(number == 0) {
                    printf("\nDivision durch 0 ist nicht moeglich\n");
                    return 0;
                }
                result /= number;
                break;
            case 'h':
                result = pow(result, number);
                break;
            default:
                printf("\nUnbekannter Operator: %c\n", mathOperator);
                break;

        }
    }

    printf("\nDas Ergebnis ist: %g\n", result);
    return 0;
}
