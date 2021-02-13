# Aufgabenbeschreibung
“Würfle” (d.h. berechne mit rand eine “zufällige” Zahl zwischen 1 und 6) immer wieder,
bis du zwei Mal nacheinander eine n Sechs er gewürfelt hast. Zähle dabei die Würfe mit.
Gib bei jedem einzelnen Wurf aus, der wievielte Versuch es war und welche Zahl geworfen wurde. Das Programm liest keine Eingabe und keine Werte von der Befehlszeile. <br>
Achtung:
* Es soll in jedem Durchgang nur eine Zahl gewürfelt werden, und zwar so lange,
bis in zwei aufeinanderfolgenden Durchgängen ein Sechser gewürfelt wurde.
Das ist etwas anderes, als in jedem Durchgang zwei Zahlen auf einmal zu würfeln,
bis beide gleichzeitig Sechser sind!<br>
<b>Tipp</b>: Es gibt zwei verschiedene Lösungsideen:<br><br>
  1. Du kannst zusätzlich zur Variablen für den aktuellen Wurf noch eine zweite für den vorigen Wurf verwenden Speichere dir jedesmal, bevor du einen neuen Wurf berechnest, den bisher aktuellen Wurf als vorigen Wurf! Wiederhole das, bis der aktuelle und der vorige Wurf beide Sechser sind (denke nach, wie man zwei Vergleiche in einer einzigen Schleifenbedingung macht!). Pass auf, dass deinem Programm keine falschen, zufälligen “Glückstreffer” schon beim ersten Wurf passieren (was ist der vorige Wurf am Anfang?)!<br><br>
  2. Verwende eine Variable, die die Anzahl der aktuell aufeinanderfolgenden Sechser zählt: 
     * Bei einem Sechser wird die Anzahl um 1 erhöht
     * Bei jedem anderen Wurf wird die Anzahl auf 0 zurückgesetzt.
  3. Wiederhole das, bis die Anzahl 2 ist. <br><br>
* Dein Programm soll bei jedem Programmlauf andere Zahlen würfeln. Erinnere dich an <b>rand</b> und <b>srand</b>.
<br><br>

# Zusatzaufgabe
* Ermittle 100 000 Mal nacheinander so wie oben, wie viele Versuche du brauchst, bis du 2 Sechser hast, und gib die durchschnittliche, <b>minimale</b> und <b>maximale</b> Anzahl
der Versuche aus. Der Durchschnitt soll eine Kommazahl sein!
Die Ausgabe der einzelnen Würfe und Versuche lässt du in diesem Fall besser weg! Nach zwei Sechsern wird neu begonnen,
d.h. ein dritter Sechser unmittelbar danach zählt nicht nochmals als zwei Sechser!
<br><br>

#### Quelle:
[https://computerix.info/dhge-prog-c/sechser.pdf](https://computerix.info/dhge-prog-c/sechser.pdf)