#ifndef STRINGUTILS_H
#define STRINGUTILS_H

/*
 * stringutils.h
 * ------------
 * Karakterlánc-összehasonlító és átalakító segédfüggvények fejlécfájlja.
 *
 * Ez a fájl deklarálja a strcmpi függvényt, amely kis- és nagybetű
 * ingyenes összehasonlítást tesz lehetővé.
 *
 * include-guard:
 *   - Megakadályozza, hogy többször
 *     bevonódjon ugyanaz a fejléc, ami linker hibát okozna.
 *
 * Függvény:
 *   int strcmpi(const char* s1, const char* s2);
 *     - Kis- és nagybetű érzéketlen összehasonlítás.
 */

/*
 * strcmpi:
 * --------
 * Kis- és nagybetű-független karakterlánc-összehasonlító függvény.
 * 
 * A függvény visszaadja:
 *   negatív érték, ha s1 < s2 (lexikografikusan)
 *   0, ha s1 == s2
 *   pozitív érték, ha s1 > s2
 *
 * Paraméterek:
 *   s1 - pointer az első összehasonlítandó C-stringre
 *   s2 - pointer a második összehasonlítandó C-stringre
 *
 * Visszatérési érték:
 *   int - összehasonlítás eredménye ugyanúgy, mint a strcmp esetén,
 *         de kis- és nagybetűt nem különbözteti meg.
 */
int strcmpi(const char* s1, const char* s2);

#endif // STRINGUTILS_H
