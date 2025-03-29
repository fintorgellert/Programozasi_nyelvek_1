#include <stdio.h>      // A szükséges fejlécek a bemeneti és kimeneti műveletekhez, pl. printf.
#include <stdlib.h>     // A `atoi` függvényhez szükséges, amely a karakterláncot egész számra alakítja.
#include "prog1.h"      // Külső fájl, amely a `string` típus definícióját tartalmazza.

/*
 * Program leírás:
 * ---------------
 * Ez a program két egész számot vár a parancssori argumentumokként,
 * és kiírja ezek összegét.
 *
 * A bemeneti paraméterek:
 *  - argc: Az argumentumok számát tárolja (a program neve is argumentumnak számít).
 *  - argv[]: A karakterláncokat tartalmazó tömb, amely a parancssorból átadott argumentumokat tartalmazza.
 *    Az argv[0] mindig a program neve, az argv[1] és argv[2] pedig a két szám, amelyeket össze szeretnénk adni.
 */
int main(int argc, string argv[]) {
    // Ha a paraméterek száma nem pontosan 3 (program neve + 2 szám), akkor hibaüzenetet írunk ki.
    if (argc != 3) {
        // Hibaüzenet kiírása.
        puts("Hiba! Maximum két paraméter adható meg!");   

        // A program hibakóddal való leállítása, ha nem megfelelő számú paraméter van.
        exit(3);  
    }

    /*
     * A `atoi` függvénnyel a parancssori argumentumokat egész számokká alakítjuk.
     * Az `atoi` (ASCII to integer) függvény a karakterláncot (string) egész számmá konvertálja.
     */

    // Az első paramétert egész számmá alakítjuk és eltároljuk az `a` változóban.
    int a = atoi(argv[1]);  

    // A második paramétert egész számmá alakítjuk és eltároljuk a `b` változóban.
    int b = atoi(argv[2]);  

    // Kiírjuk az összegüket a két számnak.
    printf("%d\n", a + b);

    return 0;  // A program sikeresen befejeződött.
}
