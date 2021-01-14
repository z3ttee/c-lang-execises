#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    if(argc == 1){
        printf("Bitte gib min. eine Zahle ein.");
        return 0;
    }

    for(int i = 1; i < argc; ++i){
        int sum = 0;

        for(int pos = 0; argv[i][pos] != '\0'; ++pos) {
            char currentChar = argv[i][pos];

            if((currentChar >= '0') && (currentChar <= '9')) {
                sum = sum*16+(currentChar-'0');
            } else if((currentChar >= 'A') && (currentChar <= 'F')) {
                sum = sum*16+(currentChar-'A'+10);
            } else if((currentChar >= 'a') && (currentChar <= 'f')) {
                sum = sum*16+(currentChar-'a'+10);
            } else {
                printf("Ungueltiges Zeichen: %c", currentChar);
                return 0;
            }
        }

        printf("Die Dezimalzahl von %s lautet: %d", argv[i], sum);
    }

    return 0;
}
