#include <stdio.h>
#include <string.h>
#include "prog1.h"  // Külső fájl, amelyben definiálva van a `string` típus.

/* 
 * Függvény: find_char
 * -------------------
 *  Megkeresi egy adott karakter első előfordulását egy stringben.
 *
 *  s: A keresett string.
 *  c: A keresendő karakter.
 *
 *  Visszatérési érték:
 *      - Ha megtalálja a karaktert, visszaadja annak indexét a stringben.
 *      - Ha a karakter nem szerepel a stringben, -1-et ad vissza.
 */
int find_char(string s, const char c) {
    // Bejárjuk a string minden karakterét, amíg el nem érünk a lezáró null karakterig ('\0').
    for (int i = 0; s[i] != '\0'; i++) {
        
        // Ha az aktuális karakter megegyezik a keresett karakterrel, visszatérünk annak indexével.
        if (s[i] == c) {
            return i;
        }
    }

    // Ha nem találtuk meg a karaktert, -1-et adunk vissza.
    return -1;
}

/* 
 * Függvény: contains_char
 * -----------------------
 *  Ellenőrzi, hogy egy adott karakter szerepel-e a stringben.
 *
 *  s: A keresett string.
 *  c: A keresendő karakter.
 *
 *  Visszatérési érték:
 *      - 1 (igaz), ha a karakter szerepel a stringben.
 *      - 0 (hamis), ha a karakter nem szerepel a stringben.
 */
int contains_char(string s, char c) {
    /* 
     * A `find_char` függvény visszatérési értékét vizsgáljuk:
     * - Ha 0 vagy nagyobb értéket ad vissza, akkor a karakter szerepel a stringben.
     * - Ha -1-et ad vissza, akkor a karakter nincs benne a stringben.
     */
    if (find_char(s, c) >= 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    // Egy string inicializálása, amelyben keresni fogunk.
    string s = "hello";

    /*
     * Ellenőrizzük, hogy az 'e' karakter szerepel-e a stringben.
     * A `contains_char` visszatérési értéke alapján kiírjuk a megfelelő üzenetet.
     *
     * A ternary (három operandusú) operátor működése:
     *   - feltétel ? "igaz eset" : "hamis eset"
     *   - Ha a `contains_char(s, 'e')` igaz (1), akkor a kiírás "igen" lesz.
     *   - Ha hamis (0), akkor a kiírás "nem" lesz.
     */
    printf("Karakter benne van: %s\n", contains_char(s, 'e') ? "igen" : "nem");

    // A program sikeresen lefutott, visszatérünk 0-val.
    return 0;
}
