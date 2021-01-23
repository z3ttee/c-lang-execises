// Hilbert-Kurve (Angabe: Hauptprogramm zum Erweitern)
//
// Aufruf: hilbert rek_tiefe
//
// Klaus Kusche, 2012

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "sdlinterf.h"

int xPos, yPos; // aktuelle x- und y-Position, in Pixel (0/0 = links oben)
int richtung;   // aktuelle Richtung, wichtig ist der Rest bei Division durch 4:
                // 0 ... rechts (+x), 1 ... rauf (-y),
                // 2 ... links (-x), 3 ... runter (+y)
int schritt;    // Wie viele Pixel ist ein Teilstrich in x- und y-Richtung lang?
int verz;       // Verz�gerung nach jedem Schritt, in Millisekunden

// Farb-Tabelle
const int R[] = {   0,  85, 170, 255, 170,  85,   0,   0,   0 };
const int G[] = { 255, 170,  85,   0,   0,   0,   0,  85, 170 };
const int B[] = {   0,   0,   0,   0,  85, 170, 255, 170,  85 };

// Hier fehlen die Funktionen zeichne, lr und rl
// Zeichne einfachen Strich
void strich(void);
// Links-rechts- / Rechts-links-Kombination mit Rekursion der Tiefe "tiefe"
void lr(int tiefe);
void rl(int tiefe);

int main(int argc, const char *argv[])
{
  if (argc != 2) {
    printf("Aufruf: %s rekursionstiefe\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  // Rekursionstiefe
  int tiefe = atoi(argv[1]);
  if (tiefe <= 0) {
    printf("%s: Rekursionstiefe muss > 0 sein!\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Berechne schritt = L�nge eines Teilstriches
  // Entspricht k�rzerer Fenster-Seite pro Rekursionsebene ein mal halbiert
  int seite = ((SDL_X_SIZE >= SDL_Y_SIZE) ? SDL_Y_SIZE : SDL_X_SIZE) - 1;
  int potenz = pow(2, tiefe);
  schritt = seite / potenz;
  if (schritt == 0) {
    printf("%s: Rekursionstiefe ist zu hoch!\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Tats�chliche Seitenl�nge der Grafik
  seite = schritt * (potenz - 1);
  // Anfangsposition = linke obere Ecke so berechnen,
  // dass die Grafik im Fenster sch�n zentriert ist
  xPos = (SDL_X_SIZE - seite) / 2;
  yPos = (SDL_Y_SIZE - seite) / 2;

  // absoluter Wert von richtung ist egal
  // nur Rest durch 4 ist wichtig, muss am Anfang 0 = "rechts runter" sein
  // aber richtung darf nicht negativ werden ==> mit gro�er Zahl anfangen!
  richtung = 1000;
  // je gr��er die Tiefe, umso mehr Teilstriche
  // ==> umso k�rzere Verzogerung pro einzelnem Teilstrich
  verz = 1500 / pow(3, tiefe);

  sdlInit();
  lr(tiefe);
  // "ewig" anzeigen, dabei alle 100 ms auf "beenden" pr�fen
  for (;;) { sdlMilliSleep(100); }
  sdlExit();

  exit(EXIT_SUCCESS);
}

void strich(void) {
    int xAlt = xPos;
    int yAlt = yPos;

    switch(richtung % 4) {
        case 0:
            xPos += schritt;
            break;
        case 1:
            yPos -= schritt;
            break;
        case 2:
            xPos -= schritt;
            break;
        default:
            yPos += schritt;
            break;
    }

    // Farbindex = Richtung modulo Anzahl der Farben
    int farbe = richtung % (sizeof(R) / sizeof(R[0]));
    sdlDrawLine(xAlt, yAlt, xPos, yPos, R[farbe], G[farbe], B[farbe]);
    sdlUpdate();
    sdlMilliSleep(verz);
}

void lr(int tiefe) {
    if(tiefe == 0) {
        return;
    }

    --richtung;
    rl(tiefe - 1);
    strich();

    ++richtung;
    lr(tiefe - 1);
    strich();
    lr(tiefe - 1);

    ++richtung;
    strich();
    rl(tiefe - 1);
    --richtung;
}

void rl(int tiefe) {
    if(tiefe == 0) {
        return;
    }

    //+LS-RSR-SL+
    ++richtung;
    lr(tiefe - 1);
    strich();

    --richtung;
    rl(tiefe - 1);
    strich();
    rl(tiefe - 1);

    --richtung;
    strich();
    lr(tiefe - 1);

    ++richtung;
}
