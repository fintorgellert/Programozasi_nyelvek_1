/* Az <stdio.h> könyvtár importálása, amely a standard bemeneti és kimeneti 
 * műveletekhez szükséges (például printf függvény használatához). 
 */
#include <stdio.h>  

// A program belépési pontja, ahol a végrehajtás megkezdődik.
int main()  
{
    // Egy for ciklus, amely ötször hajtja végre a benne lévő utasításokat.
    for (int i = 0; i < 5; i++)  
    { 
        // Kiírja az aktuális ciklus számát (1-től 5-ig) és a "hello" szót.

        // Az 'i + 1' biztosítja, hogy a számozás 1-től kezdődjön, mivel 'i' kezdeti értéke 0.
        printf("%d) hello\n", i + 1); 
    }

    // A program sikeres befejezését jelzi a rendszer számára.
    return 0;  
}
