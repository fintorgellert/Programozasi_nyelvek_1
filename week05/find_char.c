#include <stdio.h>
#include "prog1.h"  // Külső fájl, amelyben definiálva van a `string` típus.

/*
 * Függvény: find_char
 * --------------------
 * Megkeresi egy adott karakter első előfordulását egy stringben.
 *
 * Paraméterek:
 *  - s: A keresett string
 *  - c: A keresendő karakter
 *
 * Visszatérési érték:
 *  - Ha a karakter megtalálható, akkor annak indexét adja vissza.
 *  - Ha a karakter nem található meg, akkor -1-et ad vissza.
 */
int find_char(string s, const char c)
{
    // Végigiterálunk a string összes karakterén
    for (int i = 0; s[i] != '\0'; i++)
    {
        // Ha a karakter egyezik a keresett karakterrel, akkor visszaadjuk az indexét
        if (s[i] == c) {
            return i;  
        }
    }

    // Ha nem található meg a karakter, visszaadjuk a -1-et
    return -1;
}

int main()
{
    // Egy string változó inicializálása
    string s = "hello";

    /*
     * Meghívjuk a find_char függvényt az 'e' karakterrel, 
     * majd kiírjuk, hogy melyik indexen található meg.
     */
    printf("A karakter a(z) %d. helyen található!\n", find_char(s, 'e'));

    return 0;  // A program sikeresen lefutott
}
