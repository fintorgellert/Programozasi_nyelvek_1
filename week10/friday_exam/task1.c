/*
 * Ez a program két egész számot vár a parancssorból: egy alapot (base) 
 * és egy kitevőt (exponent). Ezek segítségével kiszámítja a hatványozás eredményét,
 * vagyis base ^ exponent értékét. 
 * 
 * A program külön kezeli a:
 *  - pozitív kitevőt (pl. 2^3 = 8),
 *  - nulla kitevőt (bármely szám nulladik hatványa 1),
 *  - negatív kitevőt (pl. 2^-2 = 0.25).
 * 
 * A program egy saját `my_pow()` nevű függvényt használ a hatványozásra,
 * nem a math.h könyvtár beépített `pow()` függvényét.
 */

#include <stdio.h>
#include <stdlib.h>

typedef char * string;

/* Hatványozó függvény
 * -------------------
 *
 * Bemenet:
 *   - int base: az alap, amit hatványozni szeretnénk (pl. 2)
 *   - int exponent: a kitevő, amire az alapot emeljük (pl. 3 vagy -2)
 * 
 * Kimenet:
 *   - double: a base ^ exponent kiszámított értéke (pl. 8 vagy 0.25)
 * 
 * Működés:
 *   - Ha a kitevő pozitív, akkor a számot önmagával megszorozzuk exponent-szer.
 *   - Ha a kitevő nulla, akkor 1-et adunk vissza (kivéve 0^0 esetét).
 *   - Ha a kitevő negatív, akkor az 1/base értékét szorozzuk exponent-szer.
 * 
 * Megjegyzés:
 *   - A `double` visszatérési érték lehetővé teszi a tizedes eredményeket is (negatív kitevő esetén).
 */

 double my_pow(int base, int exponent) {
    // Az eredmény változó, amit majd módosítunk
    double n = base;  

    // Különleges eset: 0^0 nem definiált, ezért visszatérünk 0-val
    if (base == 0 && exponent == 0)
        return 0;

    // Ha pozitív a kitevő (pl. 2^4), akkor base * base * ... * base (exponent-szer)
    if (exponent > 0) {
        for (int i = 0; i < exponent - 1; ++i) {
            n *= base;
        }
    }

    // Ha negatív a kitevő (pl. 2^-2), akkor 1 / (base * base ...)
    else if (exponent < 0) {
        for (int i = 0; i >= exponent; --i) {
            n /= base;
        }
    }

    // Ha a kitevő 0 (és nem 0^0), akkor az eredmény 1
    else {
        return 1;
    }

    // visszatérünk a kiszámolt hatványértékkel
    return n; 
}

int main(int argc, string argv[]) {
    // Átalakítjuk az 1. argumentumot egésszé
    int base = atoi(argv[1]);      

    // Átalakítjuk a 2. argumentumot egésszé
    int exponent = atoi(argv[2]); 

    // Meghívjuk a saját hatványozó függvényünket
    double result = my_pow(base, exponent);  

    if (exponent < 0)
        // Ha negatív a kitevő: 3 tizedesjeggyel írjuk ki
        printf("Eredmeny: %.3lf\n", result); 
    else
        // Ha pozitív vagy 0: egész számként írjuk ki
        printf("Eredmeny: %.0lf\n", result);
        
    return 0;  // A program sikeresen lefutott
}
    

