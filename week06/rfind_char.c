#include <stdio.h>   
#include <string.h>   // A stringekkel kapcsolatos műveletekhez szükséges függvények (pl. strlen).
#include "prog1.h"    // Külső fájl, amely a `string` típus definícióját tartalmazza.

/*
 * Függvény: rfind_char
 * ---------------------
 * Ez a függvény a karakterláncban megkeresi a megadott karaktert,
 * és visszaadja az utolsó előfordulásának indexét, ha a karakter megtalálható.
 * Ha a keresett karakter nem található, a függvény -1-et ad vissza.
 * 
 * Paraméterek:
 *  - s: A karakterlánc (string), amiben keresünk.
 *  - find_c: A keresett karakter (char), amit az `s` karakterláncban szeretnénk megtalálni.
 * 
 * Visszatérési érték:
 *  - Ha a keresett karakter megtalálható, akkor annak indexét adja vissza.
 *  - Ha a karakter nem található, akkor -1-et ad vissza.
 */
int rfind_char(string s, char find_c) {
    /*
     * A ciklus a karakterlánc végétől (utolsó karaktertől) indítja a keresést.
     * Az index csökkentésével lépünk visszafelé a karakterláncban.
     */
    for (int i = strlen(s) - 1; i >= 0; i--) {  
        // Ha megtaláljuk a keresett karaktert, akkor annak indexét visszaadjuk.
        if (s[i] == find_c) {
            // A megtalált karakter helyét adja vissza.
            return i;  
        }
    }

    // Ha a keresett karakter nem található a karakterláncban, -1-et adunk vissza.
    return -1;
}

int main() {
    // Szöveg, amelyben keresni fogjuk a megadott karaktert.
    string s = "Programozasi nyelvek";

    /*
     * Meghívjuk a `rfind_char` függvényt, hogy megtaláljuk az 'a' karakter utolsó előfordulásának helyét.
     * Az eredményt a `printf` segítségével kiírjuk a konzolra.
     */
    int result = rfind_char(s, 'a');

    // Kiírjuk az eredményt: a karakter találati helyét vagy -1-et, ha nem található.
    if (result != -1) {
        // Ha megtaláltuk a karaktert, akkor kiírjuk annak indexét.
        printf("A karakter '%c' az index %d helyen talalhato a karakterláncban.\n", 'a', result);
    } else {
        // Ha nem találtuk meg, akkor jelezzük, hogy a karakter nem található.
        printf("A karakter '%c' nem talalhato a karakterláncban.\n", 'a');
    }

    return 0;  // A program sikeresen befejeződött.
}
