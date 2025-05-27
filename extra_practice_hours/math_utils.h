#ifndef _MATH_UTILS_H
#define _MATH_UTILS_H

/*
    Ez a fejlécfájl (header file) célja, hogy deklaráljon néhány
    egyszerű matematikai műveletet végző függvényt.

    A fejlécfájl azért hasznos, mert segítségével a függvények
    deklarációi (azaz "előzetes bejelentései") külön fájlba kerülhetnek,
    így a program más részeiből is könnyen használhatók lesznek.
*/

/*
    A következő sor biztosítja, hogy a fájl tartalma csak egyszer
    kerüljön be a fordítás során, akkor is, ha több forrásfájl
    (#include) használja ugyanazt a fejlécet.

    #ifndef -> ha még nincs definiálva a _MATH_UTILS_H nevű makró
    #define -> akkor definiáljuk, és betöltjük a fájl tartalmát
    #endif  -> a fájl végén zárjuk le
*/


/* 
    Összeadás művelet
    -----------------
    Ez a függvény két egész számot (int) vár bemenetként, és visszaadja
    azok összegét. 
*/
int add(int a, int b);

/* 
    Kivonás művelet
    ----------------
    Ez a függvény két egész számot vár, és visszaadja a különbségüket.
    (az elsőből kivonja a másodikat)
*/
int subtract(int a, int b);

/*
    Szorzás művelet
    ----------------
    Két egész számot szoroz össze, és visszaadja az eredményt.
*/
int multiply(int a, int b);

/*
    Osztás művelet
    ---------------
    Ez a függvény két egész számot vár bemenetként.
    Az osztás eredményét lebegőpontos számban (float) adja vissza.

    Fontos megjegyezni:
    - Ha `b` értéke 0, akkor a hívó félnek kell kezelnie, mivel
      osztani 0-val nem lehet (hibához vezethet).
*/
float divide(int a, int b);

#endif