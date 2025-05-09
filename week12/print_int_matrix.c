#include <stdio.h>

/*
 * Függvény: print_matrix
 * ----------------------
 * Egy egész számokból álló mátrixot ír ki táblázatos formában.
 *
 * Paraméterek:
 *   rows   – a mátrix sorainak száma
 *   cols   – a mátrix oszlopainak száma
 *   matrix – a kiírandó mátrix, ahol matrix[row][col] az adott sor és oszlop eleme
 *
 * Működés:
 *   1) Külső for-ciklus: végigmegyünk a sorokon (0..rows-1).
 *   2) Belső for-ciklus: minden soron belül végigmegyünk az oszlopokon (0..cols-1).
 *   3) Minden iterációban printf-tel kiírjuk a matrix[row][col] értéket két tabulátorral
 *      elválasztva, hogy a számok szépen oszlopokba rendeződjenek.
 *   4) A sor végén puts("")-szel sortörést végzünk.
 */
void print_matrix(const int rows, const int cols, const int matrix[rows][cols])
{
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            // Kiírjuk az aktuális elemet, majd két tabulátorral térközt hagyunk
            printf("%d\t\t", matrix[row][col]);
        }

        // Sor vége: sortörés
        puts("");
    }
}

int main()
{
    /*
     * Példa egy mátrixra, amely 4 sorból és 6 oszlopból áll.
     * A mátrixot statikusan definiáljuk.
     */
    int example_matrix[][6] = {
        {  1,  2,  3,  4,  5,  6 },
        { 14, 21, 33, 46, 54, 67 },
        { 91, 72, 43, 34, 25, 66 },
        {  9,  8,  7,  6,  5,  4 }
    };

    // A mátrix dimenziói

    // sorok száma
    int rows = 4;   

    // oszlopok száma
    int cols = 6;   

    // A mátrix tartalmának kiírása a konzolra
    puts("A matrix tartalma:");
    print_matrix(rows, cols, example_matrix);

    return 0;  // sikeres befejezés
}
