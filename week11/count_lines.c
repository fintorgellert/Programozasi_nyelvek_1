#include <stdio.h>
#include <stdlib.h>

// Egy sor maximális hossza
#define MAX_LINE_LENGTH 1000  

/*
 * Függvény: get_number_of_lines
 * -----------------------------
 * Egy adott nevű szöveges fájlban megszámolja, hány sora van.
 *
 * Paraméter:
 *   filename – a beolvasandó fájl neve (útvonallal együtt, ha szükséges)
 * Visszatérési érték:
 *   A fájlban található sorok száma.
 * Hibakezelés:
 *   Ha a fájl nem nyitható meg, hibaüzenetet ír a standard hibakimenetre, és kilép.
 */
int get_number_of_lines(const char *filename) {
    // Fájl megnyitása olvasásra
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        // Hiba esetén kiírjuk, melyik fájl nem nyílt meg, és kilépünk
        fprintf(stderr, "Hiba! A '%s' nevű fájlt nem sikerült megnyitni!\n", filename);
        exit(1);
    }

    // Soronkénti beolvasáshoz használt bájt­tömb
    char buffer[MAX_LINE_LENGTH];  

     // A sorok számlálására szolgáló változó
    int line_count = 0;           

    // Amíg tudunk sort beolvasni a fájlból, növeljük a számlálót
    while (fgets(buffer, MAX_LINE_LENGTH, fp) != NULL) {
        line_count++;
    }

    // Fájl bezárása
    fclose(fp);  

    return line_count;
}

int main(int argc, char* argv[]) {
    // Ellenőrizzük, hogy pontosan egy argumentumot (fájlnév) adtak-e meg
    if (argc != 2) {
        // Ha nem, kiírjuk a használati utasítást és kilépünk
        fprintf(stderr, "Hiba! Adja meg egy szöveges állomány nevét!\n");
        exit(2);
    }

    // A felhasználó által megadott fájlnév
    const char *filename = argv[1];     
    
    // Sorok számlálása 
    int total_lines = get_number_of_lines(filename);  

    // Eredmény kiírása a standard kimenetre
    printf("%d\n", total_lines);

    return 0;  // Sikeres futás
}
