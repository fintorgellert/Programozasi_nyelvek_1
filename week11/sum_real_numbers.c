#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximális karakterhossz egy sorhoz
#define MAX 1000  

/*
 * Függvény: sum_of_text
 * --------------------
 * Beolvassa a megadott nevű szövegfájlt (name), és soronként feldolgozza:
 *   1) Eltávolítja a sor végén lévő újsor karaktert ('\n'), ha van.
 *   2) Megkeresi és kicseréli az első előforduló tizedesvesszőt (',') tizedesponttá ('.').
 *   3) A módosított karakterláncot double típusú számmá konvertálja az atof függvénnyel.
 *   4) Hozzáadja az így kapott értéket az összeghez.
 * Visszaadja a teljes összegértéket.
 *
 * Paraméterek:
 *   char *name – a feldolgozandó fájl neve (útvonallal együtt is lehet).
 * Visszatérési érték:
 *   double – a fájlban található számok összege.
 */

double sum_of_text(const char* name)
{
    // Fájl megnyitása olvasásra: "r" mód
    FILE *fp = fopen(name, "r");
    if (fp == NULL) {
        // Ha a fájl nem nyitható meg, hibaüzenet és program leállítása
        fprintf(stderr, "Hiba! A '%s' nevű fájlt nem sikerült megnyitni!\n", name);
        exit(EXIT_FAILURE);
    }

    // Itt tároljuk a beolvasott sorokat
    char sor[MAX]; 
    
    // Itt tartjuk a számok összeadását
    double sum = 0.0;

    // Soronként feldolgozás
    while (fgets(sor, MAX, fp) != NULL) {
        // Sorhossz meghatározása
        int length = strlen(sor);

        // Ha van sorvég-újsor karakter, azt eltávolítjuk
        if (length > 0 && sor[length - 1] == '\n') 
        {
            // Újsor helyett string lezáró karakter
            sor[length - 1] = '\0';  

            // Frissítjük a hossz értékét
            length--;                
        }

        // Első tizedesvessző kicserélése tizedesponttá
        for (int i = 0; i < length; i++) {
            if (sor[i] == ',') 
            {
                // Vessző → pont
                sor[i] = '.';        

                // Csak az első előfordulást kezeljük
                break;               
            }
        }

        // Konvertálás double típusra
        // atof: átadott karakterláncot lebegőpontos számmá alakítja
        double szam = atof(sor);

        // Az aktuális szám hozzáadása az összeghez
        sum += szam;
    }

    // Fájl bezárása, hogy ne legyen memória-/erőforrás-szivárgás
    fclose(fp);

    // Visszatérünk a kiszámolt összeggel
    return sum;
}

int main()
{
    // Feldolgozandó fájl neve (a program könyvtárában legyen)
    char *filename = "doc/real_numbers.txt";

    // A fájl feldolgozása és az eredmény eltárolása
    double result = sum_of_text(filename);

    // Eredmény kiírása:
    //  - '%.20lf' formátum 20 tizedesjegy pontosságot kér a lebegőpontos értékről
    printf("Összeg: %.20lf\n", result);

    // Sikeres futás
    return 0; 
}
