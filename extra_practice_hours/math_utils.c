#include "math_utils.h"   // A saját fejlécfájlunk, amelyben deklaráltuk a függvényeket.

/*
    Összeadás függvény
    ------------------
    Ez a függvény két egész számot vár bemenetként (a és b),
    majd visszaadja azok összegét.
*/
int add(int a, int b)
{
    // Összeadjuk a két bemeneti számot és visszatérünk az eredménnyel.
    return a + b;  
}

/*
    Kivonás függvény
    ----------------
    Ez a függvény visszaadja két szám különbségét (a - b).
*/
int subtract(int a, int b)
{
    // Az első számból kivonjuk a másodikat.
    return a - b; 
}

/*
    Szorzás függvény
    ----------------
    A két számot összeszorozza, majd visszaadja az eredményt.
*/
int multiply(int a, int b)
{
    // Szorzás végrehajtása.
    return a * b;  
}

/*
    Osztás függvény
    ---------------
    Ez a függvény két egész számot oszt egymással.

    Figyelem:
    - Mivel egész számokat osztunk, de a visszatérési típus float,
      ezért a bemeneteket explicit módon float-tá konvertáljuk.
    - Ez lehetővé teszi a tört eredmény visszaadását (pl. 5 / 2 = 2.5).
    - A hívó fél felelőssége, hogy ne adjon meg 0 értéket osztónak (b),
      mivel osztani 0-val hibás művelet lenne!
*/
float divide(int a, int b) 
{
    // Átalakítás float típusra, majd osztás
    return (float)a / (float)b;  
}
