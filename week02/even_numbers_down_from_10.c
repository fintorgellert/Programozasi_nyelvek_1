/* Az #include direktíva a szükséges fejléceket importálja, ebben az esetben a <stdio.h> könyvtárat,
 * amely biztosítja a standard bemeneti és kimeneti függvényeket, például a printf és puts függvényeket.
 */
#include <stdio.h>  

// A program belépési pontja, a 'main' függvény, amely elindítja a program végrehajtását.
int main()  
{
    // A for ciklus 10-től 1-ig visszafelé számol és csak a páros számokat írja ki.
    for (int i = 10; i > 0; i--)  
    {
        // Ha a szám osztható 2-vel (páros szám), akkor kiírjuk.
        if (i % 2 == 0) 
        {
            // A printf segítségével kiírjuk az aktuális 'i' értékét, amelyet egy szóköz követ.
            printf("%d ", i);  
        }
    }

    // A puts() függvény egy új sort ír ki, hogy a következő kimenet új sorba kerüljön.
    puts("");  

    // A main függvény visszatérési értéke 0, amely a program sikeres befejezését jelzi.
    return 0;  
}
