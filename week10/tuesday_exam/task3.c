/*
 * Egy hétre előre generál fiktív időjárási adatokat.
 * Minden naphoz tartozik egy véletlenszerű időjárás-típus és egy hőmérséklet érték (°C-ban).
 * Az időjárás típusa alapján különböző hőmérsékleti tartományból választ értéket.
 * Például: ha "Eső", akkor 0–20 °C közötti hőmérsékletet adunk meg.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef char* string; // új név a char* típusnak – ez olvashatóbbá teszi a kódot

/*
 * Egész számot generál a [min, max] zárt intervallumból
 * BEMENET:
 *   min – intervallum alsó határa
 *   max – intervallum felső határa
 * KIMENET:
 *   Egy véletlen egész szám a megadott tartományból
 * MŰKÖDÉS:
 *   A rand() % (max - min + 1) érték 0 és (max-min) közötti értéket ad.
 *   Ehhez hozzáadjuk a minimum értéket → így kapjuk meg a kívánt tartományt.
 */
int randint(int min, int max) {
    return min + (rand() % (max - min + 1));
}


int main() {
    // Véletlenszám-generátor inicializálása:
    // A srand() függvény inicializálja a rand() által használt algoritmust.
    // Azonos seed mindig azonos véletlenszerű eredményt ad → teszteléshez hasznos.
    srand(2025);

    // A lehetséges időjárási állapotokat tartalmazó tömb
    // (Négyféle állapot: Eső, Felhős, Napsütés, Szél)
    string weathers[] = { "Eső", "Felhős", "Napsütés", "Szél" };
    int size = 4; // hányféle időjárás van

    // Egy ciklus, ami 7 napon keresztül generálja az időjárási adatokat
    for (int i = 0; i < 7; ++i) {

        // Véletlenszerűen kiválasztunk egy időjárás-típust a tömbből
        int rand_weather_id = randint(0, size - 1); // 0 és 3 között
        string weather = weathers[rand_weather_id]; // kiválasztott időjárás

        int celsius; // ide kerül az adott nap hőmérséklete

        /*
         * Az időjárás típusa alapján határozzuk meg a hőmérséklet tartományát
         * majd generálunk egy véletlen értéket abból a tartományból:
         * 
         * Eső: 0 – 20 °C
         * Felhős: -10 – 25 °C
         * Napsütés: 15 – 35 °C
         * Szél: -10 – 30 °C
         */

        if (strcmp(weather, "Eső") == 0) {
            celsius = randint(0, 20);
        } else if (strcmp(weather, "Felhős") == 0) {
            celsius = randint(-10, 25);
        } else if (strcmp(weather, "Napsütés") == 0) {
            celsius = randint(15, 35);
        } else {
            // Alapértelmezett: "Szél" esetén (mivel csak 4 lehetőség van)
            celsius = randint(-10, 30);
        }

        // Kiírjuk az adott nap időjárását a formátumban:
        // Nap <sorszám>: <hőmérséklet> °C, <időjárás-típus>
        printf("Nap %d: %3d °C, %s\n", i + 1, celsius, weather);
    }

    // Sikeres futás esetén visszatérünk 0-val
    return 0;
}
