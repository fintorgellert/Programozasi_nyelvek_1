/* 
 * Feladat:
 *
 * A pangramma olyan mondat, amely tartalmazza az angol ábécé minden betűjét legalább egyszer. Például:
 *    "The quick brown fox jumps over the lazy dog."
 *
 * Ez a C program parancssori argumentumból (argv[1]) kap egy szöveget, és megvizsgálja, hogy pangramma-e. Az eredményt kiírja:
 *    - Ha igen: "Pangramma."
 *    - Ha nem: "Nem pangramma."
 *
 * Továbbá kiírja azt is, hány különböző betű szerepel a 26-ból.
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 26  // Az angol ábécé betűinek száma

/* 
 * Függvény: count
 * --------------
 * Megszámolja, hogy hány darab nem nulla érték van
 * egy adott tömbben. (Pl. hány betű szerepelt.)
 */
int count(const int n, const int array[]) {
    int cnt = 0;

    for (int i = 0; i < n; ++i) {
        // Ha az adott betű előfordult
        if (array[i])   
            ++cnt;
    }

    return cnt;
}

int main(int argc, char* argv[]) {
    // A programnak szüksége van 1 darab parancssori argumentumra
    if (argc != 2) {
        printf("Használat: %s <szöveg>\n", argv[0]);
        return 1;
    }

    // A vizsgálandó szöveg
    char* text = argv[1]; 

    // === 1. MEGOLDÁS: bitmaszkos tömbbel ===
    
    // Minden betűhöz egy 0/1 érték
    int abc[SIZE] = { 0 };  

    // Végigmegyünk a szöveg karakterein
    for (int i = 0; text[i] != '\0'; ++i) {
        char c = text[i];

        // Csak betűk érdekelnek
        if (isalpha(c)) { 
            // a=0, b=1, ..., z=25
            int idx = tolower(c) - 'a'; 
            
            // Jelöljük, hogy ez a betű már szerepelt
            abc[idx] = 1;  
        }
    }

    // Megszámoljuk, hány különböző betűt találtunk
    int cnt = count(SIZE, abc);


    // === 2. MEGOLDÁS: betűnként keresés ===
    /*
    int cnt = 0;

    for (char i = 'a'; i < 'a' + SIZE; ++i) {
        for (int j = 0; text[j] != '\0'; ++j) {
            if (i == tolower(text[j])) 
            {
                cnt++; 
                
                // Ne számoljuk kétszer ugyanazt a betűt
                break;
            }
        }
    }
    */

    // Eredmény kiírása
    if (cnt != SIZE) 
        puts("Nem pangramma.");
    else
        puts("Pangramma.");

    printf("%d-ból %d betűt tartalmaz.\n", SIZE, cnt);

    return 0;
}
