#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Ez a program bemutatja, hogyan generáljunk véletlenszámokat egy adott intervallumban.
 * A generált számok a `min` és `max` közötti egész számok lesznek.
 * 
 * A véletlenszámok generálása a következő kifejezéssel történik:
 * min + rand() % (max - min + 1)
 * 
 * A kifejezés célja, hogy a `rand()` által generált számot egy meghatározott intervallumba (min, max) helyezze el.
 * 
 * 
 * Miért szükséges a `min + rand() % (max - min + 1)` kifejezés?
 *
 * 1. A `rand()` függvény egy véletlenszámot generál, amely 0 és `RAND_MAX` között lehet.
 *    Az alapértelmezett generált számok tehát 0 és `RAND_MAX` közötti egész számok, de nekünk egy szűkebb tartományra van szükségünk.
 *    Az `rand()` kimenetét modulo (`%`) művelettel korlátozzuk.
 *
 * 2. A `%` operátor azt jelenti, hogy a `rand()` visszaadott számot egy adott intervallumra szűrjük. 
 *    A `rand() % N` kifejezés a 0 és N-1 közötti számokat generálja.
 *    Ha például a `max - min + 1` érték 6, akkor a `rand() % 6` kifejezés 0 és 5 között adhat vissza értéket.
 * 
 * 3. A `min` hozzáadása biztosítja, hogy a generált szám ne 0 és `max - min` között legyen, hanem az intervallumban, ami `min` és `max` között található.
 *    Ez azt jelenti, hogy egy 0-5 közötti számot (amelyet a `rand() % (max - min + 1)` generál) hozzáadunk a `min` értékhez,
 *    így biztosítva, hogy a generált szám `min` és `max` között legyen.
 *    
 *    Ha például `min = 5` és `max = 10`, akkor a következő történik:
 *    1. `rand() % 6` generál egy számot 0 és 5 között.
 *    2. A `min + (rand() % 6)` a generált számhoz hozzáadja a 5-öt, így az eredmény 5 és 10 között lesz.
 *    
 * Tehát a `min + rand() % (max - min + 1)` biztosítja, hogy a végeredmény az általunk kívánt intervallumban legyen.
 */

int randint(int min, int max) {  
    return min + (rand() % (max - min + 1));
}

int main() {
    // Véletlenszám-generátor inicializálása a jelenlegi idő alapján (aktuális másodperc)
    srand(time(NULL));

    printf("==== Véletlenszám-generálás példák ====\n\n");

    // 1. Teljes rand() értéktartomány (általában 0..32767)
    // Itt nem használjuk a randint-et, mivel nem adunk meg intervallumot
    printf("1. Alap rand() hívás: %d\n", rand());

    // 2. Véletlen szám 0 és 9 között (egyetlen számjegy)
    // 0 és 9 közötti számot generálunk
    printf("2. Egyjegyű szám [0-9]: %d\n", randint(0, 9));

    // 3. Véletlen szám 1 és 6 között (mint dobókocka)
    // 1 és 6 közötti számot generálunk, mintha dobókockát dobnánk
    printf("3. Dobókocka eredmény [1-6]: %d\n", randint(1, 6));

    // 4. Véletlen szám -10 és +10 között (negatív és pozitív is lehet)
    // A szám -10 és 10 közötti intervallumban lesz
    printf("4. Véletlenszám [-10, 10]: %d\n", randint(-10, 10));

    // 5. Véletlenszám nagy intervallumból: [100, 1000]
    // A generált szám 100 és 1000 között lesz
    printf("5. Szám [100, 1000] közül: %d\n", randint(100, 1000));

    // 6. Több szám generálása ciklusban egy intervallumból
    printf("\n6. 10 véletlen szám [1-100] között:\n");
    for (int i = 0; i < 10; ++i) {
        // Véletlenszámok generálása 1 és 100 között
        printf("%d ", randint(1, 100));
    }
    printf("\n");

    // 7. Lebegőpontos véletlenszám 0.0 és 1.0 között (normál random)
    // Itt nem tudjuk használni a randint-et, mert lebegőpontos számra van szükség.
    double f = (double) rand() / RAND_MAX;
    printf("\n7. Véletlenszám [0.0 - 1.0] (lebegőpontos): %.4f\n", f);

    // 8. Lebegőpontos véletlenszám egy intervallumból (pl. [5.0, 10.0])
    // Ezt a randint-tel nem tudjuk helyettesíteni, de az alábbi képlettel generálunk egy lebegőpontos számot.
    double min = 5.0, max = 10.0;
    double r = min + ((double) rand() / RAND_MAX) * (max - min);
    printf("8. Véletlenszám [5.0 - 10.0]: %.4f\n", r);
    
    return 0;
}
