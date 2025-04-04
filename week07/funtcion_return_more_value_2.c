/*
 * Ez a program bemutatja, hogyan lehet több visszatérítési értéket visszaadni egy függvényből
 * struktúra segítségével. 
 * 
 * A program a PairIntInt struktúrát használja arra, hogy két prímszámot (2 és 3)
 * adjon vissza, majd ezeket az értékeket kiírja a képernyőre.
 */

#include <stdio.h>

/*
 * Típusdefiníció: PairIntInt
 * ---------------------------
 * Ez a struktúra két egész számot tárol együtt.
 *
 * Tagok:
 *   - a: Az első egész szám.
 *   - b: A második egész szám.
 */
typedef struct {
    int a;
    int b;
} PairIntInt;

/*
 * Függvény: get_primes
 * --------------------
 * Célja:
 *    Visszaad egy PairIntInt struktúrát, amely két prímszámot tartalmaz.
 *
 * Működés:
 *    Az itt definiált példa szerint az első két prímszám (2 és 3) kerülnek eltárolásra.
 *
 * Visszatérési érték:
 *    Egy PairIntInt struktúra, ahol:
 *      - pair.a = 2
 *      - pair.b = 3
 */
PairIntInt get_primes() {
    // Inicializáljuk a struktúrát az első két prímszámmal.
    PairIntInt pair = { 2, 3 };  

    // Visszatérünk a pair struktúrával.
    return pair; 
}


int main() {
    // Meghívjuk a get_primes függvényt, és eltároljuk az eredményt.
    PairIntInt result = get_primes();  

    // Kiírjuk a kapott értékeket a struktúrából.
    printf("%d, %d\n", result.a, result.b);

    return 0;  // A program sikeres befejeződése.
}
