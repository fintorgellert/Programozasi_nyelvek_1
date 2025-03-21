#include <stdio.h>
#include <string.h>   // String kezelési függvényekhez (pl. strlen).
#include "prog1.h"    // Külső könyvtár, amely tartalmazza a `string` típust és a `get_string` függvényt.

/*
 * Függvény: is_palindrome
 * ------------------------
 * A függvény megvizsgálja, hogy a bemeneti string palindrom-e, 
 * azaz előre és hátra olvasva ugyanazt a szót adja-e.
 * 
 * Paraméterek: 
 *  - string s: A bemeneti string, amelyet ellenőrizni szeretnénk.
 * 
 * Visszatérési érték:
 *  - 1: Ha a string palindrom (ugyanaz előről és hátulról olvasva).
 *  - 0: Ha a string nem palindrom (nem ugyanaz előről és hátulról olvasva).
 */
int is_palindrome(string s)
{
    /*
     * i és j indexek inicializálása:
     * i az elejétől, j a végétől indul, és közelítenek egymáshoz.
     */ 
    int i = 0, j = strlen(s) - 1;
    
    /*
     * Ciklus, amely mindaddig fut, amíg i kisebb mint j.
     * Ez biztosítja, hogy minden karakter párt összehasonlítunk.
     */
    while (i < j)                   
    {
        /* 
         * Ha az i-edik és a j-edik karakter nem egyezik,
         * akkor a string nem palindrom, visszatérünk 0-val.
         */
        if (s[i] != s[j]) {
            return 0;
        }

        // i növelése, j csökkentése, tehát a következő karakterek összehasonlítása.
        i++; 
        j--;
    }

    /*
     * Ha a ciklus végigfutott és nem találtunk eltérést,
     * akkor a string palindrom, visszatérünk 1-tel.
     */
    return 1;                       
}

int main() 
{
    // Kérünk egy szöveget a felhasználótól.
    string s = get_string("Text: ");  

    // Meghívjuk az is_palindrome függvényt a felhasználó által megadott stringgel.
    int result = is_palindrome(s);    

    /*
     * Kiírjuk, hogy a string palindrom-e.
     * Az `is_palindrome` eredménye alapján kiírásra kerül:
     *  - "igen" ha 1-t ad vissza (a string palindrom),
     *  - "nem" ha 0-t ad vissza (a string nem palindrom).
     */
    printf("%s palindrom: %s\n", s, result ? "igen" : "nem");

    return 0;  // A program sikeresen lefutott.
}
