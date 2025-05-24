#ifndef STRINGUTILS_H
#define STRINGUTILS_H

/*
 * Ez a fejlécfájl (header file) deklarálja azokat a segédfüggvényeket,
 * amelyek stringek (karakterláncok) kezelésére szolgálnak.
 * 
 * A fejlécfájl célja, hogy a benne deklarált függvényeket más fájlokból is
 * elérhetővé tegye anélkül, hogy azok újra lennének definiálva.
 * 
 * A #ifndef – #define – #endif blokk biztosítja, hogy a fájl tartalma csak
 * egyszer kerüljön befordításra, még akkor is, ha többször van beillesztve
 * egy programban. Ez az ún. "include guard" technika.
 */

/*
 * strcmpi
 * -------
 * Kis- és nagybetű érzéketlen összehasonlítás két karakterlánc között.
 * 
 * A működés lényege: először mindkét stringet kisbetűsítjük (úgynevezett
 * normalizálás), majd ezután egy szokásos strcmp hívással hasonlítjuk össze.
 * 
 * Paraméterek:
 *   - s1: első string (const char* típus, tehát nem módosítható)
 *   - s2: második string (szintén const char*)
 * 
 * Visszatérési érték:
 *   - negatív szám, ha s1 < s2
 *   - 0, ha s1 == s2
 *   - pozitív szám, ha s1 > s2
 */
int strcmpi(const char* s1, const char* s2);

/*
 * capitalize
 * ----------
 * Ez a függvény egy új karakterláncot ad vissza, amelyben az első betű
 * nagybetű, a többi kisbetű (pl. "jANos" → "Janos").
 * 
 * A függvény dinamikus memóriakezelést használ: a visszatérő érték egy
 * újonnan lefoglalt memóriaterületre mutató pointer. Ez azt jelenti, hogy a
 * függvény által visszaadott karakterláncot a hívó félnek kell majd 
 * felszabadítania a `free()` függvény segítségével.
 * 
 * Paraméter:
 *   - text: az eredeti karakterlánc (const char* – nem módosítható)
 * 
 * Visszatérési érték:
 *   - új karakterlánc, amely a formázott (capitalize-ált) változatot tartalmazza
 *   - NULL, ha a bemenet NULL vagy memóriafoglalás sikertelen volt
 */
char* capitalize(const char* text);

#endif  // STRINGUTILS_H
