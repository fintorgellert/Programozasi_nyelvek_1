#include <stdio.h>    // A szükséges fejlécek a bemeneti és kimeneti műveletekhez.
#include <string.h>   // A stringekkel kapcsolatos műveletekhez szükséges függvények (pl. strlen).
#include "prog1.h"    // Külső fájl, amely a `string` típus definícióját tartalmazza.

/*
 * Függvény: match_ends
 * ----------------------
 * Ez a függvény megszámolja, hány olyan szó található a tömbben, 
 * amelynek az első és az utolsó karaktere megegyezik.
 * 
 * Paraméterek:
 *  - size: Az argumentumként kapott tömb mérete. Ez azt jelenti, hogy hány szó található a tömbben.
 *  - tomb[]: A karakterláncokat tartalmazó tömb, amelyet vizsgálunk.
 * 
 * Visszatérési érték:
 *  - Az a szám, amely megmutatja, hány szó felel meg a feltételnek (melyek első és utolsó karaktere megegyezik).
 */
int match_ends(int size, string tomb[]) {
    // A számláló változó, amelyet a megfelelő szavak számának nyomon követésére használunk.
    int count = 0;  

    // Ciklus, amely végigiterál a tömb minden elemén.
    for (int i = 0; i < size; ++i) {  
        // Az aktuális szó eltárolása egy helyi változóba.
        string s = tomb[i];  

        /* 
         * Ellenőrizzük a következőket:
         *  - A szó legalább két karakter hosszú legyen (strlen(s) >= 2),
         *  - Az első és az utolsó karaktere megegyezzen (s[0] == s[strlen(s) - 1]).
         * Ha mindkét feltétel igaz, akkor növeljük a `count` változót.
         */
        if ((strlen(s) >= 2) && (s[0] == s[strlen(s) - 1])) {
            // Ha a szó megfelel a feltételnek, növeljük a számlálót.
            count++;  
        }
    }

    // Visszatérünk a megfelelő szavak számával.
    return count;  
}

int main() {
    // A tömb, amely a vizsgálandó szavakat tartalmazza.
    string tomb[10] = { "level", "apple", "radar", "table", "civic", "chair", "deified", "window", "refer", "music" };
    
    // A tömb méretének tárolása.
    int size  = 10;  

    /* 
     * Meghívjuk a `match_ends` függvényt, amely visszaadja a szavak számát,
     * ahol az első és az utolsó betű megegyezik.
     * Az eredményt kiírjuk a konzolra.
     */
    printf("%d db szó van, mely kezdő és utolsó betűje megegyezik\n", match_ends(size, tomb));

    return 0;  // A program sikeresen befejeződött.
}
