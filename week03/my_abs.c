/* Az <stdio.h> könyvtár importálása, amely lehetővé teszi a szabványos bemeneti 
 * és kimeneti műveletek használatát, például a printf függvényt. 
 */
#include <stdio.h>  

/* A my_abs függvény deklarációja. 
 * Ez a függvény visszaadja a megadott szám abszolút értékét.
 */
int my_abs(int n);

// A program belépési pontja.
int main()  
{
    // A negatív szám tárolása, amelyet az abszolút érték kiszámításához használunk.
    int n = -9;  

    // Az abszolút érték kiszámítása és kiírása.
    printf("|%d| = %d\n", n, my_abs(n)); 

    // A program sikeres befejezését jelzi.
    return 0;  
}

// A my_abs függvény definíciója. 
int my_abs(int n) 
{
    // Ha a szám negatív, akkor a pozitív értékére változtatjuk.
    if (n < 0) {
        // A negatív szám pozitívvá alakítása.
        return -1 * n; 
    }

    // Ha a szám már pozitív, akkor azt visszaadjuk.
    return n;  
}
