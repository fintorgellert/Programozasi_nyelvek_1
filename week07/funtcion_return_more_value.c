/*
 * Ez a program bemutatja, hogyan lehet több visszatérítési értéket visszaadni pointerek segítségével.
 * A get_primes eljárás két egész számot (prímszámokat) ad vissza, 
 * amelyeket a main függvényben két külön változóban tárolunk.
 */

#include <stdio.h>  

/*
 * Eljárás: get_primes
 * --------------------
 * Célja:
 *   Két prímszámot ad vissza, az elsőt a p1 által mutatott címre, a másodikat a p2 által.
 *
 * Paraméterek:
 *   - p1: Egy pointer, amely az első prímszám (2) tárolására szolgál.
 *   - p2: Egy pointer, amely a második prímszám (3) tárolására szolgál.
 *
 * Működés:
 *   A függvény a pointereken keresztül módosítja a hívó által megadott változókat.
 *   *p1 értéke 2 lesz, *p2 értéke pedig 3.
 */
void get_primes(int *p1, int *p2) {
    // Az első prímszám, 2, eltárolása a p1 által mutatott címre.
    *p1 = 2;  

    // A második prímszám, 3, eltárolása a p2 által mutatott címre.
    *p2 = 3;
}


int main() {
    // Két egész változó deklarálása, melyekbe a get_primes eljárás értékeit fogjuk tárolni.
    int a, b; 

    // Meghívjuk a get_primes eljárást, átadva a változók címét.
    get_primes(&a, &b);

    // Kiírjuk a két változó értékét, a kívánt formátumban: "2, 3".
    printf("%d, %d\n", a, b);

    return 0;  // A program sikeres befejeződése.
}
