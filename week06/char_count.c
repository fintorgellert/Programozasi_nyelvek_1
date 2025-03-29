#include <stdio.h> 
#include "prog1.h"  // Külső fájl, amely a `string` típus definícióját tartalmazza.

/*
 * Függvény: char_count
 * -------------------
 * A függvény megszámolja, hány alkalommal fordul elő egy adott karakter egy adott szövegben.
 *
 * Paraméterek:
 *  - s: A szöveg, amelyben a karaktereket keresünk.
 *  - c: A karakter, amelyet keresünk a szövegben.
 *
 * Visszatérési érték:
 *  - Az adott karakter előfordulásainak száma (egész szám).
 */
int char_count(string s, char c) {
    // Kezdetben a karakterek száma 0.
    int count = 0; 

    // A ciklusváltozó, amely végigmegy a szöveg minden karakterén.
    int i;  

    /*
     * Ciklus, amely végigiterál a szöveg karakterein.
     * A ciklus addig fut, amíg el nem érjük a null terminátort ('\0').
     */ 
    for (i = 0; s[i] != '\0'; ++i) {  
        
        /*
         * Ha a jelenlegi karakter megegyezik a keresett karakterrel,
         * növeljük a count változót, jelezve, hogy találtunk egy előfordulást.
         */
        if (s[i] == c) {
            
            count++;  
        }
    }

    // A függvény visszatér az előfordulások számával.
    return count;  
}

int main() {
    // A szöveg, amelyben keresni fogjuk a karaktert.
    string s = "Geza kek az eg";  
    // A keresett karakter.
    char c = 'e';

    // Meghívjuk a char_count függvényt, hogy megszámoljuk, hány darab 'e' karakter van a szövegben.
    int result = char_count(s, c);
    
    // Kiírjuk az eredményt a képernyőre.
    printf("A(z) \"%s\" szövegben %d darab '%c' karakter van.\n", s, result, c);

    return 0;  // A program sikeresen befejeződött.
}
