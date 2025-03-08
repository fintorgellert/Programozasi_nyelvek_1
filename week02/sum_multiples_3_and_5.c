/* Az <stdio.h> könyvtár importálása, amely biztosítja a szabványos bemeneti és kimeneti 
 * függvényeket, például a printf és scanf függvényeket. 
 */
#include <stdio.h> 

// A LIMIT konstans tárolja a ciklus végső értékét (1000).
const int LIMIT = 1000;  

// A program belépési pontja, ahol a végrehajtás elkezdődik.
int main()  
{
    // A 'sum' változó tárolja az összeget, amelyet a program számolni fog.
    int sum = 0; 

    // A for ciklus 0-tól LIMIT-ig iterál, és minden olyan számot hozzáad a sum változóhoz, amely 3-mal vagy 5-tel osztható.

    // A ciklus 0-tól kezdve, egészen 999-ig fut.
    for (int i = 0; i < LIMIT; i++)  
    {
        // A feltétel vizsgálata: ha az i szám 3-mal vagy 5-tel osztható, akkor hozzáadjuk a sum-hoz.
        
        // Az i számot akkor adjuk hozzá, ha osztható 3-mal vagy 5-tel.
        if (i % 3 == 0 || i % 5 == 0) 
        {
            // Hozzáadjuk az i értékét a sum változóhoz.
            sum += i;  
        }
    }

    // Miután a ciklus végigfutott, kiírjuk az összeget.
    printf("1000-nél kisebb pozitív egész számok összege, mely 3-nak vagy 5-nek többszöröse: %d\n", sum);

    // A program sikeres befejezését jelzi.
    return 0;  
}
