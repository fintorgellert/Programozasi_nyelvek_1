#include <stdio.h>

/*
 * Függvény: sum_elements
 * ---------------------
 * Egy n x m méretű egész mátrix (két dimenziós tömb) összes elemének összegét számolja ki.
 *
 * Paraméterek:
 *   rows   – a mátrix sorainak száma
 *   cols   – a mátrix oszlopainak száma
 *   matrix – a beolvasandó mátrix, ahol matrix[row][col] az adott sor és oszlop eleme
 *
 * Visszatérési érték:
 *   Az összes elem összege (int).
 *
 * Működés:
 *   1) Létrehoz egy sum változót, kezdetben 0-val.
 *   2) Kettős for-ciklussal végigiterál a mátrix sorain (0..rows-1) és oszlopain (0..cols-1).
 *   3) Minden elem értékét hozzáadja a sum-hoz.
 *   4) A ciklusok után visszatér a sum értékével.
 */
int sum_elements(const int rows, const int cols, const int matrix[rows][cols])
{ 
    // Az összeg tárolására szolgáló változó, kezdetben nulla
    int sum = 0; 

    // Külső ciklus: végigmegyünk minden soron
    for (int row = 0; row < rows; row++)
    {
        // Belső ciklus: végigmegyünk minden oszlopon az aktuális sorban
        for (int col = 0; col < cols; col++)
        {
            // Hozzáadjuk a mátrix aktuális elemét az összeghez
            sum += matrix[row][col];
        }
    }

    // Visszatérünk az elemek összegével
    return sum;  
}

/*
 * Function: print_matrix
 * ---------------------
 * Kiírja a mátrix tartalmát soronként, oszloponként szóközzel elválasztva.
 *
 * Paraméterek:
 *   rows   – a mátrix sorainak száma
 *   cols   – a mátrix oszlopainak száma
 *   matrix – a kiírandó mátrix
 *
 * Működés:
 *   Egy dupla for-ciklus segítségével végigmegyünk a mátrix minden elemén,
 *   és printf-pel kiírjuk az elemeket, majd minden sor után sortörést alkalmazunk.
 */
void print_matrix(const int rows, const int cols, const int matrix[rows][cols])
{
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            // Kiírjuk az aktuális elemet egy szóközzel elválasztva
            printf("%d ", matrix[row][col]);
        }
        
        // Sortörés a sor végén
        printf("\n");  
    }
}

int main()
{
    // Példa mátrix definiálása: 4 sor, 6 oszlop
    int matrix[][6] = {
        {  1,  2,  3,  4,  5,  6 },
        { 14, 21, 33, 46, 54, 67 },
        { 91, 72, 43, 34, 25, 66 },
        {  9,  8,  7,  6,  5,  4 }
    };

    // Mátrix dimenziók tárolása változókban
    
    // Sorok száma
    int rows = 4;
    
    // Oszlopok száma   
    int cols = 6;   


    // A mátrix tartalmának megjelenítése
    puts("Matrix tartalma:");
    print_matrix(rows, cols, matrix);

    // Az összeg kiszámítása a sum_elements függvénnyel
    int total = sum_elements(rows, cols, matrix);

    // Az összeg kiírása
    printf("Osszeg: %d\n", total);

    return 0;  // Program sikeres befejezése
}
