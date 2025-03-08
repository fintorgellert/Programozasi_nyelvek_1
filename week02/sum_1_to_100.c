/* Az <stdio.h> könyvtár importálása, amely biztosítja a szabványos bemeneti és kimeneti 
 * függvényeket, például a printf és scanf függvényeket. 
 */
#include <stdio.h>  

// A program belépési pontja, ahol a végrehajtás elkezdődik.
int main()  
{
    // A 'sum' változó tárolja az összeget, amelyet a ciklus során számolunk.
    int sum = 0;  


    // A for ciklus, amely 1-től 100-ig számolja az összes számot, és hozzáadja őket a sum változóhoz. 

    // A ciklus változója (i) 1-től 100-ig növekszik.
    for (int i = 1; i <= 100; i++)  
    {
        // Minden egyes ciklusban hozzáadja az aktuális 'i' értéket a sum változóhoz.
        sum += i; 
    }

    // Miután a ciklus lefutott, kiírja a számok összegét (1-től 100-ig).

    // A végleges összeg kiírása.
    printf("1-től 100-ig a számok összege: %d\n", sum);  

    // A program sikeres befejezését jelzi.
    return 0;  
}
