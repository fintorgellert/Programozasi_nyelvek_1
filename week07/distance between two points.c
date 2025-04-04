#include <stdio.h>   // A bemeneti és kimeneti műveletekhez szükséges könyvtár.
#include <stdlib.h>  // Az abs() függvényhez, amely a számok abszolút értékét számolja.
#include <math.h>    // A sqrt() függvényhez, amely a négyzetgyök számításhoz szükséges.

/*
 * Típusdefiníció: Point
 * ----------------------
 * Egy pontot reprezentál a síkon, amely két egész koordinátával rendelkezik:
 *  - x: A pont vízszintes koordinátája.
 *  - y: A pont függőleges koordinátája.
 */
typedef struct {
    int x;
    int y;
} Point;

/*
 * Függvény: distance
 * ------------------
 * Célja:
 *    Kiszámolja két pont (p1 és p2) közötti távolságot a síkon.
 *
 * Paraméterek:
 *    - p1: Az első pont, amely a Point típusú struktúrában van tárolva.
 *    - p2: A második pont, amely szintén a Point struktúrában van tárolva.
 *
 * Visszatérési érték:
 *    - A két pont közötti távolság (double), amelyet a Pitagorasz-tétel alapján számolunk ki.
 *
 * Működés:
 *    1. Számolja a két pont x és y koordinátái közötti különbséget abszolút értékben.
 *    2. A négyzetgyök függvény segítségével kiszámolja a két különbség négyzetösszegének négyzetgyökét.
 *       Ez a két pont közötti távolságot adja meg.
 */
double distance(Point p1, Point p2)
{
    // Kiszámolja az x koordináták közötti abszolút különbséget.
    int a = abs(p1.x - p2.x);  

    // Kiszámolja az y koordináták közötti abszolút különbséget.
    int b = abs(p1.y - p2.y);  

    // A Pitagorasz-tétel alkalmazása: a^2 + b^2, majd ennek négyzetgyöke a két pont közötti távolság.
    return sqrt((a * a) + (b * b));
}


int main()
{
    // Két pont definiálása a síkon:
    // Az 'a' pont koordinátái: x = 1, y = 2.
    Point a = { 1, 2 };  

    // A 'b' pont koordinátái: x = 6, y = 5.
    Point b = { 6, 5 }; 

    // A distance függvény meghívása a két pont távolságának kiszámítására, majd az eredmény kiírása.
    printf("A két pont közti távolság: %lf\n", distance(a, b));

    return 0;  // A program sikeres befejeződését jelzi.
}
