/* Az #include direktíva a <stdio.h> könyvtárat importálja, amely a szabványos 
 * bemeneti és kimeneti függvényeket (például printf) biztosítja. 
 */
#include <stdio.h>  

// A program belépési pontja, ahol a végrehajtás elkezdődik.
int main()  
{
    // Egy for ciklus, amely ötször hajtja végre a benne lévő utasításokat.

    /* A ciklusváltozó i kezdetben 0, és amíg i kisebb, mint 5, a ciklus fut. 
     * Minden iteráció végén az i értéke eggyel nő (i++). 
     */
    for (int i = 0; i < 5; i++)  
    {
        // Kiírja az aktuális ciklus számát (1-től 5-ig) és a "Anna" szót.

        // Az i + 1 kifejezés biztosítja, hogy a számozás 1-től induljon, mivel a ciklusváltozó i kezdetben 0.
        printf("(%d) Anna\n", i + 1);  
    }

    // A main függvény visszatérési értéke 0, amely a program sikeres futását jelzi.
    return 0;
}
