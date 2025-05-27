#include <stdio.h>           // Betöltjük a standard input/output könyvtárat a printf használatához.
#include "math_utils.h"      // Betöltjük a saját készítésű fejlécfájlt, ahol a matematikai függvényeket deklaráltuk.

/*
    A main() függvény az a belépési pont (entry point), ahol a program végrehajtása elkezdődik.
*/
int main()
{
    // Két egész szám definiálása, ezekkel fogunk műveleteket végezni.
    int a = 10;
    int b = 5;

    /*
        Az alábbi sorok mindegyike meghívja a saját matematikai művelet-függvényeinket
        és kiírja az eredményt a képernyőre.
    */

    /*
     * add(a, b): két szám összeadása.
     *
     * Várható eredmény: 10 + 5 = 15
     */ 
    printf("Összeg: %d\n", add(a, b));           

    /* 
     * subtract(a, b): két szám kivonása.
     *
     * Várható eredmény: 10 - 5 = 5
     */
    printf("Különbség: %d\n", subtract(a, b));      

    /*
     * multiply(a, b): két szám szorzása.
     *
     * Várható eredmény: 10 * 5 = 50
     */ 
    printf("Szorzat: %d\n", multiply(a, b));     

    /*
     * divide(a, b): két szám osztása. 
     *
     * Fontos, hogy itt float típusú eredményt várunk,
     * ezért a formátum specifikátor: %.2f 
     * 
     * Várható eredmény: 10 / 5 = 2.00
     */
    printf("Osztás: %.2f\n", divide(a, b));        

    // Program vége, visszatérünk 0-val, jelezve hogy nem történt hiba.
    return 0;  
}
