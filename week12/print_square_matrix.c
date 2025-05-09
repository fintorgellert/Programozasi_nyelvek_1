#include <stdio.h>

/*
 * Function: print_matrix
 * ----------------------
 * Egy n x n-es egész mátrixot ír ki táblázatos formában.
 *
 * Paraméterek:
 *   size   – a mátrix sorainak és oszlopainak közös száma (négyzetes mátrix)
 *   matrix – a kiírandó mátrix, ahol matrix[row][col] az adott sor és oszlop eleme
 *
 * Működés:
 *   1) Külső for-ciklus bejárja a sorokat (row = 0..size-1).
 *   2) Belső for-ciklus bejárja az adott sor oszlopait (col = 0..size-1).
 *   3) Minden elem után két tabulátort teszünk, hogy az oszlopok rendezettek legyenek.
 *   4) Sorok végén sortörést végzünk puts("")-szel.
 *   5) A teljes mátrix után egy üres sorral tagoljuk a kimenetet.
 */
void print_matrix(const int size, const int matrix[size][size])
{
    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size; col++)
        {
            // Kiírjuk az aktuális elemet, majd két tabulátorral térközt hagyunk
            printf("%d\t\t", matrix[row][col]);
        } 
        
        // sor végi sortörés
        puts(""); 
    }
    
    // üres sor a blokkok között
    puts("");      
}

/*
 * Function: print_main_diagonal
 * -----------------------------
 * Egy n x n-es mátrix főátlóját írja ki.
 * A főátló elemei azok, ahol sorindex == oszlopindex.
 *
 * Paraméterek:
 *   size   – a mátrix sorainak/oszlopainak száma
 *   matrix – a kiírandó mátrix
 *
 * Működés:
 *   1) Kiírjuk a "Főátló:" feliratot.
 *   2) Egyetlen for-ciklussal végigmegyünk i = 0..size-1 tartományon.
 *   3) Minden iterációban kiírjuk matrix[i][i] értékét és egy tabulátort.
 *   4) A végén sortörést végzünk puts("")-szel.
 */
void print_main_diagonal(const int size, const int matrix[size][size])
{
    puts("Főátló:");
    
    for (int i = 0; i < size; i++)
    {
        // Kiírjuk az i-edik főátló-elemet
        printf("%d\t", matrix[i][i]);
    }

    // sortörés a sor végén
    puts(""); 
}

int main()
{
    // Példa: 4x4-es négyzetes mátrix definiálása
    int matrix[4][4] = {
        {  1,  2,  3,  4 },
        { 14, 21, 33, 46 },
        { 91, 72, 43, 34 },
        {  9,  8,  7,  6 }
    };

    // mátrix mérete (sor/oszlop)
    int n = 4;  

    // A teljes mátrix kiírása
    puts("Mátrix tartalma:");
    print_matrix(n, matrix);

    // A mátrix főátlójának kiírása
    print_main_diagonal(n, matrix);

    return 0;  // sikeres befejezés
}
