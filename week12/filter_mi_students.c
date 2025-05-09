#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES      100    // Maximum beolvasható sor
#define MAX_LINE_LEN   256    // Egy sor maximális hossza karakterekben
#define MAX_NAME_LEN   50     // Név maximális hossza

/*
 * Függvény: load_mi_names
 * -----------------------
 * Beolvassa a megadott CSV fájl sorait, és kigyűjti az "mi" szakos hallgatók neveit.
 *
 * Paraméterek:
 *   filename    – a bemeneti CSV fájl neve
 *   out_names   – kétdimenziós karaktertömb, ide kerülnek a talált nevek
 *   max_names   – az out_names első dimenziójának mérete (max eltárolható nevek)
 *
 * Visszatérési érték:
 *   Az "mi" szakos hallgatók neveinek száma (0 és max_names között).
 *
 * Működés:
 *   1) Megnyitja a fájlt olvasásra.
 *   2) Soronként beolvassa a CSV sort egy bufferbe.
 *   3) strtok segítségével felbontja a sort három tokenre: név, életkor, szak.
 *   4) Ha a szak token "mi", kimásolja a nevet az out_names tömbbe.
 *   5) Bezárja a fájlt, majd visszatér a talált nevek számával.
 */
int load_mi_names(const char *filename, char out_names[][MAX_NAME_LEN], int max_names)
{
    FILE *fp = fopen(filename, "r");

    if (!fp) {
        fprintf(stderr, "Hiba: nem sikerült megnyitni a '%s' fájlt.\n", filename);
        return 0;
    }

    char line[MAX_LINE_LEN];
    int count = 0;

    while (count < max_names && fgets(line, sizeof(line), fp)) {
        // Sorvégi újsor karakter eltávolítása
        line[strcspn(line, "\r\n")] = '\0';

        // 1. token: név
        char *token = strtok(line, ",");

        if (!token) 
            continue;

        char name[MAX_NAME_LEN];
        strncpy(name, token, MAX_NAME_LEN);
        name[MAX_NAME_LEN - 1] = '\0';

        // 2. token: életkor (nem használjuk)
        token = strtok(NULL, ",");

        if (!token)
            continue;

        // 3. token: szak
        token = strtok(NULL, ",");

        if (!token) 
            continue;

        char *major = token;

        // Ha a szak "mi", kimásoljuk a nevet
        if (strcmp(major, "mi") == 0) {
            strncpy(out_names[count], name, MAX_NAME_LEN);
            out_names[count][MAX_NAME_LEN - 1] = '\0';
            count++;
        }
    }

    fclose(fp);

    return count;
}

/*
 * Függvény: print_names
 * ---------------------
 * Egy nevek listáját írja ki vesszővel és szóközzel elválasztva.
 *
 * Paraméterek:
 *   names – karaktertömb, amely count darab név tárolására alkalmas
 *   count – hány név van a tömbben
 *
 * Működés:
 *   Kiírja a names[0], names[1], ..., names[count-1] elemeket, 
 *   elválasztva ", " karakterekkel, végül sortörést ad.
 */
void print_names(char names[][MAX_NAME_LEN], int count)
{
    for (int i = 0; i < count; i++) {
        printf("%s", names[i]);
        
        if (i < count - 1) {
            printf(", ");
        }
    }

    puts("");
}

int main(void)
{
    // A fájl neve, amelyből beolvassuk a diákok adatait
    const char *filename = "names.csv";

    // Kimeneti tömb az "mi" szakos neveknek
    char mi_names[MAX_LINES][MAX_NAME_LEN];
    
    // Beolvassuk az "mi" szakos hallgatók neveit
    int mi_count = load_mi_names(filename, mi_names, MAX_LINES);

    // Kiírjuk a talált neveket
    print_names(mi_names, mi_count);

    return 0;  // sikeres befejezés
}
