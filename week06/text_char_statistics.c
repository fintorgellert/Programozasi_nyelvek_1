/*
 * Ez a program egyetlen parancssori argumentumként kapott szöveg karaktereit elemzi és kategorizálja.
 * Megszámolja a következő karaktertípusokat:
 *  - Kisbetűk (`a-z`)
 *  - Nagybetűk (`A-Z`)
 *  - Számjegyek (`0-9`)
 *  - Egyéb (extra) karakterek (pl. `@`, `#`, `!`, stb.), kivéve a szóközöket.
 *
 * Használat:
 * ----------
 * A programot a következő módon kell futtatni:
 * 
 *      ./text_char_statistics 'Hello, World!123'
 *
 * Kimenet:
 * --------
 * Ha a felhasználó megad egy megfelelő szöveget, a program kiírja az egyes karaktertípusok számát:
 *
 *      Kisbetűk száma: 8
 *      Nagybetűk száma: 2
 *      Számok száma: 3
 *      Extra karakterek száma: 2
 *
 * Fontos megjegyzés:
 * ------------------
 * - Ha a felhasználó nem ad meg pontosan egy szöveget argumentumként, a program hibaüzenetet ír ki és kilép.
 */

#include <stdio.h>      // Szokásos bemeneti és kimeneti műveletek (pl. printf, puts).
#include <ctype.h>      // A karaktertípusokat vizsgáló függvényekhez (pl. islower, isupper, isdigit, isblank).
#include <stdlib.h>     // A `exit` függvényhez, amely hiba esetén kilépteti a programot.
#include "prog1.h"      // Külső fájl, amely a `string` típus definícióját tartalmazza.

int main(int argc, string argv[]) {
    // Ellenőrizzük, hogy a felhasználó pontosan egy szöveget adott-e meg parancssori argumentumként.
    if (argc != 2)
    {
        // Hibaüzenet kiírása
        puts("Hiba! Adj meg egy egyetlen szöveget!"); 

        // Hibás használat esetén kilépünk a programból egy nem nulla visszatérési értékkel.  
        exit(1);                                       
    }
    
    // Az argumentumból átvesszük a beírt szöveget egy változóba.
    string text = argv[1];
    
    // Számlálók inicializálása minden karaktertípushoz.
    int lower = 0, upper = 0, digit = 0, extra = 0;
    
    // A ciklus végigmegy az összes karakteren a szövegben, amíg el nem ér a lezáró nullához (`\0`).
    for (int i = 0; text[i] != '\0'; ++i) 
    {
        // Az aktuális karakter eltárolása.
        char c = text[i];  

        // Ha kisbetű (`a-z`), növeljük a `lower` számlálót.
        if (islower(c)) 
            lower++;
         
        // Ha nagybetű (`A-Z`), növeljük az `upper` számlálót.
        else if (isupper(c))
            upper++;

        
        // Ha szám (`0-9`), növeljük a `digit` számlálót.
        else if (isdigit(c))  
            digit++;

        // Ha egyik sem, és nem szóköz, akkor extra karakter.
        else if (!isblank(c))  
            extra++;
    }

    // Eredmények kiírása a képernyőre.
    printf("Kisbetűk száma: %d\n", lower);
    printf("Nagybetűk száma: %d\n", upper);
    printf("Számok száma: %d\n", digit);
    printf("Extra karakterek száma: %d\n", extra);

    return 0;  // A program sikeresen lefutott.
}
