#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximális sorhossz: ennyi karakter fér el egy beolvasott sorban
#define MAX_LEN 200  

/*
 * Függvény: filter_numbers
 * ------------------------
 * Egy bemenetként megadott fájlból soronként olvas stringeket, 
 * melyeket lebegőpontos számmá (double) alakít. 
 * Csak az 0.5-nél nagyobb értékeket tárolja egy tömbben.
 *
 * Paraméterek:
 *   in_file : FILE* típus, mutató a már megnyitott bemeneti fájlhoz
 *   values  : double tömb, ide kerülnek a 0.5-nél nagyobb számok
 * Visszatérési érték:
 *   int – az output tömbben tárolt számok darabszáma
 *
 * Részletes működés:
 * 1. Soronként olvasunk egy-egy karakterláncot a fgets() segítségével.
 * 2. A beolvasott sor végéről eltávolítjuk az újsor karaktert ('\n'), mert
 *    az atof() nem képes azt kezelni, és rossz értéket adhat vissza.
 * 3. A line stringet double-é konvertáljuk az atof() függvénnyel.
 * 4. Ha a konvertált szám > 0.5, akkor betesszük a values tömbbe
 *    és növeljük a számlálót.
 * 5. A ciklus addig folytatódik, amíg van mit olvasni a fájlból.
 */
int filter_numbers(FILE *in_file, double values[]) {
    puts("# 0.5-nél nagyobb számok szűrése...");
    char line[MAX_LEN];
    
    // Hány számot szűrtünk ki eddig
    int count = 0;  

    while (fgets(line, MAX_LEN, in_file) != NULL) {
        // Újsor eltávolítása a line végéről (strlen-1 indexen van)
        line[strlen(line) - 1] = '\0';

        // Átalakítás stringről double-re
        double num = atof(line);

        // Szűrőfeltétel alkalmazása: csak 0.5-nél nagyobb számok
        if (num > 0.5) 
        {
            // érték eltárolása
            values[count] = num;  
            
            // számláló növelése
            count++;              
        }
    }

    // Visszatérünk a kimeneti tömbbe került elemek darabszámával
    return count;
}

/*
 * Függvény: write_numbers_to_file
 * -------------------------------
 * A megadott double tömb értékeit kiírja egy fájlba, egy számot egy sorba,
 * 20 tizedesjegy pontossággal.
 *
 * Paraméterek:
 *   out_file : FILE* típus, mutató a már megnyitott kimeneti fájlhoz
 *   values   : double tömb, ami a kiírandó számokat tartalmazza
 *   count    : int, a tömbben érvényes elemek száma
 *
 * Részletes működés:
 * - Egyszerű for-ciklussal végigmegyünk a 0-tól count-1-ig terjedő indexeken.
 * - Minden értéket fprintf()-el kiírunk, pontosan 20 tizedesjegyet megadva.
 */
void write_numbers_to_file(FILE *out_file, double values[], int count) {
    puts("# Szűrt számok kiírása out.txt-be...");

    for (int i = 0; i < count; i++) {
        fprintf(out_file, "%.20lf\n", values[i]);
    }
}

int main() {
    // Fájlnév változók – könnyen cserélhetők szükség szerint
    const char* input_filename  = "doc/in.txt";
    const char* output_filename = "doc/out.txt";

    /* 
     * Szűrt értékek tárolására szolgáló tömb
     * Maximális méretnek MAX_LEN-et választjuk, de lehet akár kisebb vagy nagyobb 
     */
    double values[MAX_LEN];

    // Hány értéket szűrtünk ki (ez kerül kiírásra utólag)
    int filtered_count;

    // Bemeneti fájl megnyitása
    FILE *fp_in = fopen(input_filename, "r");
    if (fp_in == NULL) {
        // Hibakezelés: ha nem nyílik meg, errormessage írunk, és exit(1)
        fprintf(stderr, "Hiba! A '%s' fájlt nem sikerült megnyitni!\n", input_filename);
        exit(1);
    }
    puts("# in.txt sikeresen megnyitva");

    /*
     * Számok szűrése

     * A filter_numbers függvény beolvassa a fájlt, kiszűri 0.5-nél nagyobb értékeket,
     * és visszaadja, hány elemet tárolt el a values tömbbe.
     */
    filtered_count = filter_numbers(fp_in, values);
    puts("# Szűrés vége");

    // Fájl bezárása, mert már nincs szükségünk rá
    fclose(fp_in);

    // Kimeneti fájl megnyitása
    FILE *fp_out = fopen(output_filename, "w");
    if (fp_out == NULL) {
        fprintf(stderr, "Hiba! A '%s' fájlt nem sikerült megnyitni írásra!\n", output_filename);
        exit(2);
    }

    // Szűrt számok kiírása
    write_numbers_to_file(fp_out, values, filtered_count);

    // Kimeneti fájl bezárása
    fclose(fp_out);
    puts("# out.txt sikeresen bezárva");

    // Összegzés a felhasználónak
    printf("# out.txt-be kiírt számok mennyisége: %d db\n", filtered_count);

    return 0;  // Program sikeres lezárása
}
