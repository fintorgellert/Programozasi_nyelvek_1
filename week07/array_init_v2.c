#include <stdio.h> 
#include "prog1.h"

/*
 * Függvény: get_int
 * -----------------
 * Célja:
 *   Bekér egy egész számot a felhasználótól a megadott üzenet megjelenítésével.
 *
 * Paraméter:
 *   - prompt: Egy string, amely a felhasználónak megjelenítendő üzenetet tartalmazza.
 *
 * Visszatérési érték:
 *   - A felhasználó által beírt egész szám.
 *
 * Működés:
 *   1. Kiírja a prompt üzenetet a képernyőre.
 *   2. A scanf függvény segítségével beolvassa a felhasználó által megadott egész számot.
 *   3. Visszatér a beolvasott értékkel.
 */
int get_int(string prompt) {
    // A változó, amelybe beolvassuk a felhasználó által megadott egész számot.
    int n; 

    // A prompt üzenet kiírása.
    printf("%s", prompt); 

    // Az egész szám beolvasása a standard bemenetről.
    scanf("%d", &n);       

    // Visszatér a beolvasott egész számmal.
    return n;  
}


int main() {
    // Bekérjük a felhasználótól, hogy hány elemet szeretne a tömbben (a tömb mérete).
    int size = get_int("Szám: ");
    
    // Deklarálunk egy változó hosszúságú tömböt, amely a felhasználó által megadott méretű.
    int array[size];

    // Inicializáljuk a tömb minden elemét 0-ra.
    for (int i = 0; i < size; i++) {
        array[i] = 0;
    }

    // Kiírjuk a tömb elemeit, egyenként, szóközzel elválasztva.
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    // Újsor kiírása a képernyőn, hogy a kimenet rendezett legyen.
    puts("");  

    return 0;  // A program sikeres befejeződését jelzi.
}
