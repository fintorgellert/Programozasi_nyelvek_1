#include <stdio.h>      // Fájlkezeléshez és kiíráshoz szükséges könyvtár
#include <stdlib.h>     // Hibakezeléshez és kilépéshez szükséges (exit, malloc stb.)
#include <string.h>     // Szövegkezeléshez (pl. strtok, strlen)

// A beolvasott sor maximális hossza
#define MAX_LINE_BUF_LENGTH 128

// A szóelválasztó karakterek felsorolása (szóköz, tab, soremelés, írásjelek)
#define DELIMETERS " \t\n,.:;!?"

int main(int argc, char *argv[])
{
    /*
     * Ellenőrizzük, hogy pontosan két parancssori argumentumot kaptunk-e:
     * az első a bemeneti fájl neve, a második a kimeneti fájlé.
     * Ha nem, akkor hibát írunk ki és kilépünk.
     */
    if ( argc != 3 )
    {
        fprintf(stderr, "Nem megfelelő számú argumentum!\n");
        exit(1);
    }

    // Megnyitjuk a bemeneti fájlt olvasásra
    FILE *input = fopen(argv[1], "r");

    // Ha nem sikerült megnyitni a fájlt
    if (input == NULL) {
        perror("Hiba, a bemeneti fájl megnyitása során.");

        // Megszakítjuk a programot hiba esetén
        exit(2); 
    }

    // Megnyitjuk a kimeneti fájlt írásra
    FILE *output = fopen(argv[2], "w");

    // Ha nem sikerült megnyitni a fájlt
    if (output == NULL) {
        perror("Hiba, a kimeneti fájl megnyitása során.");

        // Bemeneti fájlt bezárjuk, ha már megnyitottuk
        fclose(input);  
        exit(2);
    }

    // Soronként olvassuk a bemeneti fájlt
    char line_buffer[MAX_LINE_BUF_LENGTH];
    
    while ( fgets(line_buffer, MAX_LINE_BUF_LENGTH, input) != NULL )
    {
        /*
         * A fgets beolvassa az új sor jelet is ('\n'), amit eltávolítunk.
         * Megkeressük a sor végét, és az utolsó karaktert nullára állítjuk.
         */
        line_buffer[strlen(line_buffer) - 1] = '\0';

        /*
         * A sor feldarabolása tokenekre (szavakra) a megadott elválasztó karakterek mentén.
         * A strtok első hívása után a következő hívás NULL-lal történik a folytatás érdekében.
         */
        char *tok = strtok(line_buffer, DELIMETERS);

        // Amíg van újabb token, írjuk ki a kimeneti fájlba egy új sorba
        while ( tok != NULL )
        {
            // Szó kiírása új sorba
            fprintf(output, "%s\n", tok);  

            // Következő token
            tok = strtok(NULL, DELIMETERS); 
        }
    }

    // Fájlok bezárása
    fclose(input);
    fclose(output);

    return 0;
}
