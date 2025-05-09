/* 
 * Feladat:
 *
 * A program generál egy véletlen egész számot 1 és 100 között, majd a felhasználó addig tippelhet, amíg el nem találja. A program minden próbálkozás után visszajelzést ad:
 *   - "Túl nagy", ha a tipp nagyobb a keresett számnál,
 *   - "Túl kicsi", ha a tipp kisebb,
 *   - "Talált!", ha eltalálta a számot.
 * Ehhez írjon egy `int check_guess(const int guess, const int target)` szignatúrájú függvényt.
 *
 *   A játék megszakítható a 0 bevitelével.
 */

 #include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Konstansok: játéktartomány és debug mód
#define DEBUG 1   // Ha 1, akkor kiírja a véletlenszámot (teszteléshez)
#define MIN 1     // Minimum érték a játékban
#define MAX 100   // Maximum érték a játékban

/* 
 * Függvény: check_guess
 * ----------------------
 * Összehasonlítja a felhasználó tippjét a célértékkel.
 *
 * Paraméterek:
 *   guess  – a felhasználó tippje
 *   target – a generált véletlen szám
 *
 * Visszatérési érték:
 *   1  – ha a tipp túl nagy
 *  -1  – ha a tipp túl kicsi
 *   0  – ha eltalálta a számot
 */
int check_guess(const int guess, const int target) {
    if (guess > target)
        return 1;
    else if (guess < target)
        return -1;
    else
        return 0;
}

int main() {
    // Véletlenszám-generátor inicializálása
    srand(time(NULL));  

    // Véletlen szám generálása MIN és MAX között
    int target = MIN + rand() % MAX;
    
    // A felhasználó tippje
    int guess;  

    // Ha a DEBUG mód be van kapcsolva, kiírjuk a keresett számot
    if (DEBUG) 
        printf("# A keresett szám: %d\n", target);

    // Végtelen ciklus a játékhoz, amíg a felhasználó el nem találja a számot
    while (1) {
        // Tipp bekérése
        printf("Tippelj 1 és 100 között (kilépés: 0): ");
        scanf("%d", &guess);

        // 0 esetén kilépés a játékból
        if (guess == 0) {
            puts("Kár, hogy feladtad!");
            break;
        }

        // Tipp értékelése és visszajelzés
        int result = check_guess(guess, target);

        if (result == 1)
            puts("Túl nagy");
        else if (result == -1)
            puts("Túl kicsi");
        else {
            puts("Talált!");
            
            // Játék vége
            break;  
        }
    }

    return 0;
}