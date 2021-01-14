#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sdlinterf.h"

#define UPDATE_DELAY_MS 50
#define MAX_STARS_AMOUNT 91

// Vor aufruf sagen, dass irgendwo die Funktionen existieren
void drawTree(void);
void drawStar(void);
void drawSnow(void);

int main()
{
    srand(time(NULL));
    printf("\n Program started.\n");

    // Öffne Grafikfenster
    sdlInit();

    drawTree();
    drawStar();
    drawSnow();

    // Schließe Grafikfenster zum Programm-Ende
    sdlExit();

    printf("\n Program done.\n");
    return 0;
}

/**
    Tannenbaum malen
*/
void drawTree(void) {
    printf("\n Now drawing tree...\n");
    sdlSetBlack();

    // Mittelpunkt ist immer 400
    const int xM = SDL_X_SIZE / 2; // Bildmitte in X-Richtung

    // Reihe von Ellipsen zeichnen bis yM >= 540
    sdlDrawCirc(xM, SDL_Y_SIZE - 20, 50, 15, 128, 64, 0);
    for(int y = 40; y < SDL_Y_SIZE - 20; y += 50) {
        sdlDrawCirc(xM, y, y / 2, 30, 0, 255, 0);
        sdlUpdate();
        sdlMilliSleep(UPDATE_DELAY_MS);
    }

    printf(" Done. Waiting 3s.\n");
    sdlMilliSleep(3000);
}

/**
    Schnee malen
*/
void drawSnow() {
    printf("\n Now drawing snow...\n");
    sdlSetBlack();

    for(int radius = 10; radius < MAX_STARS_AMOUNT; ++radius) {
        int centerX = rand() % (SDL_X_SIZE - 2 * radius) + radius;
        int centerY = rand() % (SDL_Y_SIZE - 2 * radius) + radius;

        sdlDrawCirc(centerX, centerY, radius, radius/10, radius, radius, 55 + 2 * radius);
        sdlDrawCirc(centerX, centerY, radius/10, radius, radius, radius, 5 + 2 * radius);

        sdlUpdate();
        sdlMilliSleep(UPDATE_DELAY_MS);
    }

    printf(" Done. Waiting 3s.\n");
    sdlMilliSleep(3000);
}

/**
    Stern malen
*/
void drawStar(void) {
    printf("\n Now drawing star...\n");
    sdlSetBlack();

    // Schleifenvariablen deklarieren
    int i;
    int k;

    // Bildschirmmitte berechnen
    const int xM = SDL_X_SIZE / 2; // 400
    const int yM = SDL_Y_SIZE / 2; // 300

    // Pro schleifendurchgang linie zeichnen
    for(i = 5, k = 255; i < 255; i += 10, k -= 10) {
        // 1. Linie
        sdlDrawLine(xM-i, 300, 400, yM - k, i, 255, k);
        sdlUpdate();
        sdlMilliSleep(UPDATE_DELAY_MS);

        // 2. Linie
        sdlDrawLine(xM+i, 300, 400, yM - k, i, 255, k);
        sdlUpdate();
        sdlMilliSleep(UPDATE_DELAY_MS);

        // 3. Linie
        sdlDrawLine(xM-i, 300, 400, yM + k, i, 255, k);
        sdlUpdate();
        sdlMilliSleep(UPDATE_DELAY_MS);

        // 4. Linie
        sdlDrawLine(xM+i, 300, 400, yM + k, i, 255, k);
        sdlUpdate();
        sdlMilliSleep(UPDATE_DELAY_MS);

        // 4. Linie
        sdlDrawLine(xM+i, 300, 400, yM + k, i, 255, k);
        sdlUpdate();
        sdlMilliSleep(UPDATE_DELAY_MS);

        // 5. Linie
        sdlDrawLine(xM-i, yM-i, xM+k, yM - k, i, 0, k);
        sdlUpdate();
        sdlMilliSleep(UPDATE_DELAY_MS);

        // 6. Linie
        sdlDrawLine(xM-i, yM-i, xM-k, yM + k, i, 0, k);
        sdlUpdate();
        sdlMilliSleep(UPDATE_DELAY_MS);

        // 7. Linie
        sdlDrawLine(xM+i, yM+i, xM+k, yM - k, i, 0, k);
        sdlUpdate();
        sdlMilliSleep(UPDATE_DELAY_MS);

        // 8. Linie
        sdlDrawLine(xM+i, yM+i, xM-k, yM + k, i, 0, k);
        sdlUpdate();
        sdlMilliSleep(UPDATE_DELAY_MS);
    }

    // Warte 3 Sekunden
    sdlMilliSleep(3000);

    // Pro schleifendurchgang linie zeichnen
    for(i = 5, k = 255; i < 255; i += 10, k -= 10) {
        // 1. Linie
        sdlDrawLine(xM-i, 300, 400, yM - k, 0, 0, 0);
        sdlUpdate();
        sdlMilliSleep(UPDATE_DELAY_MS);

        // 2. Linie
        sdlDrawLine(xM+i, 300, 400, yM - k, 0, 0, 0);
        sdlUpdate();
        sdlMilliSleep(UPDATE_DELAY_MS);

        // 3. Linie
        sdlDrawLine(xM-i, 300, 400, yM + k, 0, 0, 0);
        sdlUpdate();
        sdlMilliSleep(UPDATE_DELAY_MS);

        // 4. Linie
        sdlDrawLine(xM+i, 300, 400, yM + k, 0, 0, 0);
        sdlUpdate();
        sdlMilliSleep(UPDATE_DELAY_MS);

        // 4. Linie
        sdlDrawLine(xM+i, 300, 400, yM + k, 0, 0, 0);
        sdlUpdate();
        sdlMilliSleep(UPDATE_DELAY_MS);

        // 5. Linie
        sdlDrawLine(xM-i, yM-i, xM+k, yM - k, 0, 0, 0);
        sdlUpdate();
        sdlMilliSleep(UPDATE_DELAY_MS);

        // 6. Linie
        sdlDrawLine(xM-i, yM-i, xM-k, yM + k, 0, 0, 0);
        sdlUpdate();
        sdlMilliSleep(UPDATE_DELAY_MS);

        // 7. Linie
        sdlDrawLine(xM+i, yM+i, xM+k, yM - k, 0, 0, 0);
        sdlUpdate();
        sdlMilliSleep(UPDATE_DELAY_MS);

        // 8. Linie
        sdlDrawLine(xM+i, yM+i, xM-k, yM + k, 0, 0, 0);
        sdlUpdate();
        sdlMilliSleep(UPDATE_DELAY_MS);
    }

    printf(" Done. Waiting 3s.\n");
    sdlMilliSleep(3000);
}
