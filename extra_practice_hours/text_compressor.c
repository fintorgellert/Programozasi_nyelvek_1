#include <stdio.h>      // Fájlműveletekhez: fopen, fclose, fprintf, fputs, fgets stb.
#include <stdlib.h>     // Általános segédfüggvényekhez: rand, srand, exit stb.
#include <string.h>     // Sztringműveletekhez: pl. strlen
#include <time.h>       // Időkezeléshez: time() a véletlenszám-generáláshoz
#include <ctype.h>      // Karaktervizsgálathoz: isspace()

// Egy sor maximális hossza, amit beolvasunk (buffer méret)
#define MAX_LINE_LENGTH 1024

// A törlés valószínűsége (30%)
#define DELETE_PROBABILITY 0.3

// Ez a függvény eldönti, hogy megtartsunk-e egy karaktert vagy sem.
// Ha a generált véletlenszám >= 0.3, akkor megtartjuk.
int should_keep_char() {
    return (rand() / (double)RAND_MAX) >= DELETE_PROBABILITY;
}

// Ez a függvény dolgozza fel a fájl egy sorát.
// Bejárja karakterenként a sort, és ha nem szóköz, akkor 30% eséllyel törli.
void process_line(const char* line, FILE *output) {
    for (int i = 0; line[i] != '\0'; i++) {
        // A szóközöket (pl. space, tab, newline) sosem töröljük
        if (isspace(line[i])) {
            // Szóköz kiírása a kimeneti fájlba
            fputc(line[i], output); 
            continue;
        }

        // Ha úgy döntöttünk, hogy megtartjuk a karaktert, kiírjuk
        if (should_keep_char()) {
            fputc(line[i], output);
        }

        // Ellenkező esetben (random alapján) a karaktert egyszerűen "eldobjuk"
    }
}

// Ez a függvény olvassa soronként a bemeneti fájlt, és feldolgozza soronként
void compress_file(FILE *input, FILE *output) {
    char line[MAX_LINE_LENGTH];

    // Addig olvasunk, amíg van sor a fájlban
    while (fgets(line, sizeof(line), input) != NULL) {
        process_line(line, output);
    }
}

// A program belépési pontja
int main(int argc, char* argv[]) {
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

    // Véletlenszám-generátor inicializálása (egyszeri érték a rendszeridőből)
    srand(time(NULL));

    // A tömörítés (karakterek részleges eltávolítása) végrehajtása
    compress_file(input, output);

    // Fájlok lezárása
    fclose(input);
    fclose(output);

    return 0;
}
