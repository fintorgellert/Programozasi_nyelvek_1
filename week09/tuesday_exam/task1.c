#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

typedef char * string;

/*
 * Ez a program a felhasználó által parancssori argumentumként megadott szavakat dolgozza fel.
 * A célja, hogy a szavakban előforduló számjegyeket (0–9) kigyűjtse, majd:
 *    - Kiírja az összes megtalált számjegyet
 *    - Kiszámolja a számjegyek darabszámát
 *    - Kiszámolja azok összegét
 *    - Meghatározza az átlagukat
 */

int main(int argc, string argv[]) {

    // Ellenőrizzük, hogy legalább egy szót megadott-e a felhasználó
    // argv[0] mindig a program neve (pl. "./a.out"), ezért az első tényleges szó az argv[1]
    if (argc < 2) {
        printf("Hiba! Adjon meg legalább egy szót!\n");
        exit(1); // Kilépünk hibakóddal, ha nem adott meg szavakat
    }

    // Változók előkészítése:
    int first = 1;   // Segédváltozó a formázott kiíráshoz (vesszők elkerülésére)
    int count = 0;   // Számjegyek száma
    int sum = 0;     // Számjegyek összege

    // Feldolgozzuk az összes megadott szót (argv[1] … argv[argc-1])
    for (int i = 1; i < argc; ++i) {
        string word = argv[i]; // Az aktuális szó

        // Bejárjuk karakterenként a szót
        for (int j = 0; word[j] != '\0'; ++j) {
            char c = word[j];

            // Megvizsgáljuk, hogy a karakter egy számjegy-e
            if (isdigit(c)) {
                // Ha ez nem az első találat, akkor vesszőt írunk ki előtte
                if (!first)
                    printf(", ");
                else 
                    printf("Talált számjegyek: "); // Első számjegy esetén bevezető szöveg
                
                printf("%c", c); // Kiírjuk a számjegyet

                first = 0;       // Megjelöljük, hogy már volt találat
                count++;         // Számjegy darabszám növelése
                sum += c - '0';  // ASCII-ból számjeggyé alakítás ('0' = 48), majd hozzáadás az összeghez
            }
        }
    }

    // Ha nem találtunk egyetlen számjegyet sem, erről tájékoztatjuk a felhasználót
    if (count == 0) {
        puts("Nincsenek számjegyek a szavakban!");
    } else {
        // Ha találtunk számjegyeket, statisztikát készítünk
        printf("\nDarabszám: %d\n", count);                // Hány számjegy volt
        printf("Összeg: %d\n", sum);                       // Összegük
        printf("Átlag: %.1lf\n", (double) sum / count);    // Átlag (lebegőpontos osztás)
    }

    return 0;
}
