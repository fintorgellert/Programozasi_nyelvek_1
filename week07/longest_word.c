#include <stdio.h>    // Standard I/O könyvtár, szükséges a bemenetek és kimenetek kezeléséhez.
#include <string.h>   // A stringek kezeléséhez szükséges függvényeket tartalmazza (pl. strlen, strcmp).

// A beolvasandó szövegek maximális hossza
#define SIZE 1024     

/*
 * Ez a program szavakat kér be a felhasználótól, egészen addig, amíg a felhasználó '*' karaktert nem ad meg.
 * A program megszámolja, hány szót adott meg, és meghatározza a leghosszabb szó hosszát.
 *
 * Használat:
 *  A felhasználó szavakat ad meg a programnak. Ha a szó '*' (csak egy csillag) formátumú,
 *  akkor a program befejezi a bevitelét, és kiírja:
 *      - A bevitt szavak számát.
 *      - A leghosszabb szó karakterhosszát.
 */

int main() {
    // Karaktertömb, amelybe a felhasználó által bevitt szó kerül.
    char text[SIZE];   

    // A leghosszabb szó hosszának tárolása. 
    int longest = 0;    

    // A bevitt szavak számának tárolása.
    int cnt = 0;       

    // Kiírunk egy üzenetet, amely elmagyarázza a felhasználónak, hogyan kell használni a programot.
    puts("Adj meg szavakat '*' végjelig!");

    // Végtelen ciklus, amely addig fut, amíg a felhasználó '*' jelet nem ad meg.
    while (1) {
        // Kéri a felhasználót, hogy adjon meg egy szót.
        printf("Szó: ");  

        // A fgets beolvassa a szó szövegét, legfeljebb SIZE karaktert.
        fgets(text, SIZE, stdin);

        /*
         * A fgets függvény beolvas egy új sort is ('\n') a bemenet végén,
         * ezért ezt a karaktert eltávolítjuk a stringből azzal, hogy az utolsó karaktert '\0'-ra cseréljük.
         * 
         * Fontos: Feltételezzük, hogy a felhasználó mindenképp beír legalább egy karaktert.
         */
        text[strlen(text) - 1] = '\0';

        // Ha a bevitt szó "*" (csak egy csillag), akkor kilépünk a ciklusból.
        if (strcmp(text, "*") == 0) {
             // Új sort írunk ki a formázás érdekében.
            puts(""); 
            break;
        }

        // Növeljük a bevitt szavak számát.
        cnt++;  

        // Ellenőrizzük, hogy a bevitt szó hossza nagyobb-e a jelenleg tárolt leghosszabb szó hosszánál.
        if (strlen(text) > longest) {
            // Frissítjük a leghosszabb szó hosszát.
            longest = strlen(text);  
        }
    }
    
    // Kiírjuk az eredményeket: hány szót adott meg a felhasználó és a leghosszabb szó karakterhossza.
    printf("%d db szót adtál meg. A leghosszabb szó %d karakterből áll.\n", cnt, longest);

    return 0;  // A program sikeresen befejeződött.
}
