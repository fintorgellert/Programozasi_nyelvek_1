/* Az <stdio.h> könyvtár importálása, amely biztosítja a szabványos bemeneti és kimeneti 
 * függvényeket, például a printf és scanf függvényeket. 
 */
#include <stdio.h>                       

// A program belépési pontja, ahol a végrehajtás elkezdődik.
int main()  
{
    // Az 'i' változó kezdőértéke 0. Ez fogja számolni az iterációk számát.
    int i = 0;  

    // A while ciklus addig fut, amíg az 'i' kisebb, mint 5.
    while (i < 5)  
    {
        // Kiírja a számot (i + 1) és a nevet "Anna", minden iterációban.

        // Az 'i + 1' biztosítja, hogy az 1-től kezdődjön a számlálás.
        printf("(%d) Anna\n", i + 1);  

        // Minden egyes iteráció után növeli az 'i' változót.
        i++;  
    }

    // A program sikeres befejezését jelzi.
    return 0;  
}
