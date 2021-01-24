// Rahmenprogramm zum grafischen Sortieren
//
// Aufruf: sort-sdl anzahl
//
// Klaus Kusche, 2020

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "sdlinterf.h"

// Verzögerungen (in Millisekunden) für die Grafik-Anzeige
// ... beim Start
#define START_MS 200
// ... am Ende (bevor das Fenster verschwindet)
#define ENDE_MS 3000
// ... bei jedem Vergleich
#define VERGL_MS 50
// ... bei jeder Vertauschung
#define TAUSCH_MS 100

// die Farbwwerte
const int farbe_normal[] = { 0, 255, 0 };     // normaler Balken
const int farbe_vergl[] = { 255, 255, 0 };    // zu vergleichender Balken
const int farbe_tausch[] = { 255, 0, 255 };   // zu vertauschender Balken
const int farbe_schwarz[] = { 0, 0, 0 };      // schwarz (zum Weglöschen)

// Konstanten (in Pixeln) für das Grafik-Layout
// initialisiert in "main", benutzt in "balken"
// Breite eines Balkens
int breite;
// Eine Höhen-Einheit
int hoehe;
// Linker Rand = Startposition des ersten Balkens in X-Richtung
// (gleicher Rand links & rechts,
// damit die Balken im Fenster schön in der Mitte stehen)
int xstart;

// Zähler für die Vergleiche und Vertauschungen
int vergl = 0;
int vertau = 0;

void selectionSort(int arr[], int anzahl);
void insertionSort(int arr[], int anzahl);
void bubbleSort(int arr[], int anzahl);

// Zeichne den Balken Nummer i in Farbe farbe
void balken(const int arr[], int i, const int farbe[])
{
  int xpos = xstart + i * breite;
  sdlDrawRectFromTo(xpos + 1, SDL_Y_SIZE - 1,
                    xpos + breite - 1, SDL_Y_SIZE - arr[i] * hoehe,
                    farbe[0], farbe[1], farbe[2]);
  sdlUpdate();
}

// Vergleiche mit farbiger Anzeige und Verzögerung:
// Ist das Element an pos1 kleiner als das Element an pos2? (true / false)
// Da wir das Array mit lauter verschiedenen Elementen initialisieren,
// kommt "gleich" nicht vor!
bool kleiner(const int arr[], int pos1, int pos2)
{
  ++vergl;

  balken(arr, pos1, farbe_vergl);
  balken(arr, pos2, farbe_vergl);
  sdlMilliSleep(VERGL_MS);
  balken(arr, pos1, farbe_normal);
  balken(arr, pos2, farbe_normal);

  return (arr[pos1] < arr[pos2]);
}

// Vertausche die Elemente an pos1 und pos2 mit farbiger Anzeige und Verzögerung
void tausche(int arr[], int pos1, int pos2)
{
  ++vertau;

  // zeichne die zu vertauschenden Balken färbig
  balken(arr, pos1, farbe_tausch);
  balken(arr, pos2, farbe_tausch);
  sdlMilliSleep(TAUSCH_MS);

  // zeichne den längeren alten Balken schwarz,
  // weil sonst würde nach dem Tausch beim Überzeichnen mit dem kürzeren Balken
  // oben ein Rest sichtbar bleiben!
  if (arr[pos1] > arr[pos2]) {
    balken(arr, pos1, farbe_schwarz);
  } else {
    balken(arr, pos2, farbe_schwarz);
  }

  // tausche
  int tmp = arr[pos1];
  arr[pos1] = arr[pos2];
  arr[pos2] = tmp;

  // zeichne die vertauschten Balken normal
  balken(arr, pos1, farbe_normal);
  balken(arr, pos2, farbe_normal);
}

// Befülle das Array zufällig mit den Zahlen 1 bis anzahl
// und zeige den Anfangszustand an
void fuelle(int arr[], int anzahl){

  // Befüllen
  for (int i = 0; i < anzahl; ++i) {
    arr[i] = i+1;
  }

  // Zufälliges tauschen der Werte im Array
  for (int i = 0; i < 3000; ++i) {
    int x = rand() % anzahl;
    int y = rand() % anzahl;

    int a = arr[x];
    arr[x] = arr[y];
    arr[y] = a;
  }

  // Anzeigen des Arrays
  for(int i = 0; i < anzahl; ++i) {
    balken(arr, i, farbe_normal);
  }

}

// sortiere das Array
// unter Verwendung von "kleiner" und "tausche"
void sort(int arr[], int anzahl){
    //selectionSort(arr, anzahl);
    //insertionSort(arr, anzahl);
    bubbleSort(arr, anzahl);
}

int main(int argc, const char *argv[])
{
  if (argc != 2) {
    printf("Aufruf: %s anzahl\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  int anzahl = atoi(argv[1]);
  if ((anzahl <= 0) || (anzahl > SDL_X_SIZE / 2) || (anzahl > SDL_Y_SIZE)) {
    printf("%s: Die Anzahl muss größer 0 sein "
          "und in das Grafikfenster passen\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  // Geometrie aus der Anzahl berechnen
  breite = SDL_X_SIZE / anzahl;
  hoehe = SDL_Y_SIZE / anzahl;
  xstart = (SDL_X_SIZE % anzahl) / 2;

  int array[anzahl];

  srand(time(NULL));

  sdlInit();
  sdlSetBlack();

  fuelle(array, anzahl);

  sdlMilliSleep(START_MS);

  sort(array, anzahl);

  printf("%d Vergleiche\n%d Vertauschungen\n", vergl, vertau);

  sdlMilliSleep(ENDE_MS);
  sdlExit();

  exit(EXIT_SUCCESS);
}






void selectionSort(int arr[], int anzahl){
    for(int pos = 0; pos < anzahl-1; ++pos) {
        int minPos = pos;

        for(int k = pos + 1; k < anzahl; ++k){
            if(kleiner(arr, k, minPos)) {
                minPos = k;
            }
        }

        if(minPos != pos) {
            tausche(arr, pos, minPos);
        }
    }
}


void insertionSort(int arr[], int anzahl) {
    for(int pos = 1; pos < anzahl; ++pos) {
        for(int i = pos; i > 0 && !kleiner(arr, i-1, i); --i) {
            tausche(arr, i-1, i);
        }
    }
}

void bubbleSort(int arr[], int anzahl) {
    for(int pos = anzahl - 1; pos > 1; --pos) {
        for(int i = 0; i < pos; ++i) {
            if(kleiner(arr, i + 1, i)) {
                tausche(arr, i, i + 1);
            }
        }
    }
}
