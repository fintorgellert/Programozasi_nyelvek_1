/* Az <stdio.h> könyvtár importálása, amely biztosítja a szabványos 
 * bemeneti és kimeneti függvényeket, például a printf függvényt. 
 */
#include <stdio.h> 

/* Az <stdlib.h> könyvtár importálása, amely tartalmazza az abs() függvényt,
 * amely egy egész szám abszolút értékét adja vissza. 
 */
#include <stdlib.h>  

// A program belépési pontja, ahol a végrehajtás elkezdődik.
int main()  
{
    // Egy egész típusú változó (n) deklarálása és inicializálása -9 értékkel.
    int n = -9;  

    /* A printf függvény kiírja a szám abszolút értékét. 
     * Az abs(n) függvény kiszámolja az n abszolút értékét (negatív szám esetén pozitívvá alakítja). 
     */
    printf("|%d| = %d\n", n, abs(n));
        
    // A program sikeres befejezését jelzi.
    return 0;  
}
