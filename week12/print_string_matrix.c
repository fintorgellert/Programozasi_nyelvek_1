#include <stdio.h>

// string típus: karakterláncokra mutató pointer
typedef char* string;  

/*
 * Függvény: print_matrix
 * ----------------------
 * Kinyomtat egy sor- és oszlopszámmal definiált 2D-s string mátrixot táblázatos formában.
 *
 * Paraméterek:
 *   rows  – a mátrix sorainak száma
 *   cols  – a mátrix oszlopainak száma
 *   words – a kiírandó string mátrix, ahol words[row][col] az adott sor és oszlop eleme
 *
 * Működés lépésről lépésre:
 * 1) Két beágyazott for-ciklus segítségével végigjárjuk a mátrix sorait és oszlopait.
 * 2) Minden adott words[row][col] elemet kiírunk a printf-tel, két tabulátorral elválasztva,
 *    hogy a szavak szépen oszlopba rendezve jelenjenek meg.
 * 3) Az egyes sorok után puts("")-szel sortörést illesztünk be.
 */
void print_matrix(int rows, int cols, string words[rows][cols]) {
    for (int row = 0; row < rows; row++) 
    {
        // Minden sor elemeit egymás után kiírjuk
        for (int col = 0; col < cols; col++) 
        {
            // Kiírás: %s a stringhez, \t\t a két tabulátor az oszlopok elkülönítéséhez
            printf("%s\t\t", words[row][col]);
        }
        
        // sorvégi sortörés
        puts("");  
    }  
}

int main() {
    // Példaadat: 2 sor és 3 oszlop
    string words[2][3] = {
        { "bab",  "kiwi", "narancs" },
        { "alma", "dio",  "mogyoro" }
    };

    // Mátrix sorainak száma
    int rows = 2;  
    
    // Mátrix oszlopainak száma
    int cols = 3;  


    // A mátrix tartalmának megjelenítése a konzolon
    
    // Meghívjuk a print_matrix függvényt az adatainkkal
    print_matrix(rows, cols, words);

    return 0;  // Program sikeres befejezése
}
