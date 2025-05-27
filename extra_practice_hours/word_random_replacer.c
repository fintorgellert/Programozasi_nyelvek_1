#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// A szócsere valószínűsége (50% eséllyel cserélünk szót)
#define MAX_LINE_LENGTH 1024

// A szócsere valószínűsége (50% eséllyel cserélünk szót)
#define CHANGE_PROBABILITY 0.5

/*
    Ez a tömb tartalmazza azokat a szavakat, amelyekkel a bemeneti szöveg
    szavait véletlenszerűen lecseréljük.
*/
const char *replacement_words[] = {
    "apple", "river", "mountain", "dream", "keyboard",
    "sunset", "forest", "cloud", "pencil", "breeze"};

/*
    Ez a tömb tartalmazza azokat a szavakat, amelyekkel a bemeneti szöveg
    szavait véletlenszerűen lecseréljük.
*/
double fifty_fifty()
{
    return rand() / (double)RAND_MAX;
}

/*
    Ez a függvény visszaad egy véletlenszerű egész számot 0 és (hi-1) között.
    Ezt arra használjuk, hogy kiválasszunk egy szót a csere_szavak tömbből.
*/
int rand_range(int hi)
{
    return rand() % hi;
}

/*
    Ez a függvény dolgozza fel a bemeneti fájl egy sorát:
    - A sort szavakra bontja szóközök mentén.
    - Minden szónál eldönti, hogy lecseréli-e.
    - Ha igen, egy véletlenszerű szót ír ki a csere_szavak tömbből.
    - Ha nem, az eredeti szót írja ki.
    - A szavakat újra összefűzi, szóközökkel elválasztva.
*/
void process_line(char *line, FILE *output)
{
    // Sor szavakra bontása szóköz, tabulátor vagy sortörés mentén
    char *token = strtok(line, " \t\n"); 

    // Addig folytatjuk, amíg van újabb szó
    while (token != NULL)
    {
        if (fifty_fifty() < CHANGE_PROBABILITY)
        {
            // Csere szó kiválasztása véletlenszerűen a replacement_words tömbből
            int rand_idx = rand_range(sizeof(replacement_words) / sizeof(replacement_words[0]));
            fprintf(output, "%s", replacement_words[rand_idx]);
        }
        else
        {
            // Az eredeti szó kiírása változtatás nélkül
            fprintf(output, "%s", token);
        }

        // Következő szó feldolgozása
        token = strtok(NULL, " \t\n");

        // Ha még vannak szavak, szóközt is kiírunk köztük (formázás miatt)
        if (token != NULL)
        {
            fputc(' ', output);
        }
    }

    // A sor végére új sort írunk
    fputc('\n', output);
}

/*
    Ez a függvény olvassa soronként a bemeneti fájlt, és minden sort
    feldolgoz a process_line() segítségével.
*/
void replace_words_in_file(FILE *input, FILE *output)
{
    char line[MAX_LINE_LENGTH];

    // Fájl beolvasása soronként
    while (fgets(line, sizeof(line), input) != NULL)
    {
        process_line(line, output);
    }
}


/*
    A program belépési pontja (main függvény).
    Itt történik:
    - parancssori argumentumok ellenőrzése,
    - fájlok megnyitása,
    - véletlenszám generátor inicializálása,
    - feldolgozás elindítása.
*/
int main(int argc, char *argv[])
{
    // Ellenőrizzük, hogy megadtunk-e pontosan két parancssori argumentumot (bemenet és kimenet)
    if (argc != 3) {
        fputs("Hiba! Nem adtál meg fájlneveket. Használat: ./program input.txt output.txt\n", stderr);
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

    // Véletlenszám generátor inicializálása az aktuális idő alapján
    srand(time(NULL));

    // Fájl feldolgozása
    replace_words_in_file(input, output);

    // Fájlok bezárása
    fclose(input);
    fclose(output);

    return 0;
}
