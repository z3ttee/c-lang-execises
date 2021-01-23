#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "sdlinterf.h"

int xPos = 0;
int yPos = 0;
int direction = 0;
int step = 1;
int delay = 100;
int depth = 100;

void zeichne(int depth);

// Farb-Tabelle
const int R[] = {   0,  85, 170, 255, 170,  85,   0,   0,   0 };
const int G[] = { 255, 170,  85,   0,   0,   0,   0,  85, 170 };
const int B[] = {   0,   0,   0,   0,  85, 170, 255, 170,  85 };

int main(int argc, const char *argv[]){
    if (argc != 2) {
        printf("Aufruf: %s rekursionstiefe\n", argv[0]);
        exit(EXIT_FAILURE);
    }
  // Rekursionstiefe
    int depth = atoi(argv[1]);
    if (depth <= 0) {
        printf("%s: Rekursionstiefe muss > 0 sein!\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Berechne schritt = Länge eines Teilstriches
    // Entspricht kürzerer Fenster-Seite pro Rekursionsebene ein mal gedrittelt
    int seite = ((SDL_X_SIZE >= SDL_Y_SIZE) ? SDL_Y_SIZE : SDL_X_SIZE) - 1;
    int potenz = pow(3, depth);
    step = seite / potenz;
    if (step == 0) {
        printf("%s: Rekursionstiefe ist zu hoch!\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Tatsächliche Seitenlänge der Grafik
    seite = step * potenz;
    // Anfangsposition = linke obere Ecke so berechnen,
    // dass die Grafik im Fenster schön zentriert ist
    xPos = (SDL_X_SIZE - seite) / 2;
    yPos = (SDL_Y_SIZE - seite) / 2;

    // absoluter Wert von richtung ist egal
    // nur Rest durch 4 ist wichtig, muss am Anfang 0 = "rechts runter" sein
    // aber richtung darf nicht negativ werden ==> mit großer Zahl anfangen!
    direction = 1000;
    // je größer die Tiefe, umso mehr Teilstriche
    // ==> umso kürzere Verzogerung pro einzelnem Teilstrich
    delay = 1500 / pow(5, depth);

    sdlInit();
    zeichne(depth);

    // "ewig" anzeigen, dabei alle 100 ms auf "beenden" prüfen
    for (;;) { sdlMilliSleep(100); }
    sdlExit();

    exit(EXIT_SUCCESS);
}

void zeichne(int depth) {
    if(depth > 0) {

        zeichne(depth - 1);
        --direction;
        zeichne(depth - 1);
        ++direction;
        zeichne(depth - 1);
        ++direction;
        zeichne(depth - 1);
        ++direction;
        zeichne(depth - 1);
        --direction;
        zeichne(depth - 1);
        --direction;
        zeichne(depth - 1);
        --direction;
        zeichne(depth - 1);
        ++direction;
        zeichne(depth - 1);

    } else {
        int oldX = xPos;
        int oldY = yPos;

        switch(direction % 4) {
            case 0:
                xPos = oldX+step;
                yPos = oldY+step;
                break;
            case 1:
                xPos = oldX+step;
                yPos = oldY-step;
                break;
            case 2:
                xPos = oldX-step;
                yPos = oldY-step;
                break;
            default:
                xPos = oldX-step;
                yPos = oldY+step;
                break;
        }
        int colorIndex = direction % 9;

        sdlDrawLine(oldX, oldY, xPos, yPos, R[colorIndex], G[colorIndex], B[colorIndex]);
        sdlUpdate();
        sdlMilliSleep(delay);
    }
}
