/*
 * Ez a program egy karakteres "rajzot" hoz létre a konzolra. A téglalap mérete 
 * véletlenszerűen generált (mind a sorok, mind az oszlopok száma 5 és 15 közé esik). 
 * A téglalap keretét '#' karakterek adják, a belsejét '.' karakterek töltik ki, 
 * és minden sorban egy véletlenszerű pozícióban elhelyez egy speciális karaktert 
 * a következő készletből: { '@', '&', '?', '!', '%', '=', '+', '*' }.
 */

#include <stdio.h>   
#include <stdlib.h> 


// Állandók definiálása
// SIZE: a speciális karaktereket tartalmazó tömb mérete
// MIN/MAX: a generálható méretek intervalluma (sor/oszlop)
#define SIZE 8
#define MIN 5
#define MAX 15

// Egész szám véletlenszerű generálása egy zárt [min, max] intervallumból
int rand_int(int min, int max) {
    return min + rand() % (max - min + 1);
}

int main()
{
    // Véletlenszám generátor inicializálása
    // A srand(2025) gondoskodik róla, hogy minden programfutás ugyanazokat a véletlenszámokat adja vissza (teszteléshez hasznos)
    srand(2025);

    // Véletlenszerű méretek generálása: n sor, m oszlop
    int n = rand_int(MIN, MAX);  // sorok száma
    int m = rand_int(MIN, MAX);  // oszlopok száma

    // Karakterek tömbje, melyek közül minden sorba egy véletlen kerül
    char elements[SIZE] = { '@', '&', '?', '!', '%', '=', '+', '*' };

    // A generált méretek kiírása a felhasználónak
    printf("Generált méret: %d x %d\n\n", n, m);

    // Soronként kirajzoljuk a téglalapot kerettel
    // A keret miatt n+2 sort és m+2 oszlopot rajzolunk (0-tól n+1-ig és 0-tól m+1-ig)
    for (int i = 0; i <= n + 1; ++i)
    {
        // Minden sorban választunk egy véletlenszerű pozíciót (1 és m között), ahova speciális karakter kerül
        int rand_pos = rand_int(1, m);

        // Kiválasztunk egy véletlenszerű karaktert az elements tömbből
        int rand_index = rand_int(0, SIZE - 1);
        char rand_element = elements[rand_index];

        // Oszloponként haladva kirajzoljuk a sor aktuális karaktereit
        for (int j = 0; j <= m + 1; ++j) {
            if (i == 0 || i == n + 1 || j == 0 || j == m + 1) {
                // Ha a sor vagy az oszlop az első vagy utolsó, akkor a keret része – ezt '#' karakter jelöli
                putchar('#');
            } else if (rand_pos == j) {
                // Ha az aktuális oszlop a véletlenszerűen kiválasztott pozíció, akkor egy speciális karakter kerül ide
                putchar(rand_element);
            } else {
                // Egyébként a belső rész üresnek számít, így pont karaktert írunk
                putchar('.');
            }
        }

        // Sor vége – új sort kezdünk
        puts("");
    }

    return 0;
}
