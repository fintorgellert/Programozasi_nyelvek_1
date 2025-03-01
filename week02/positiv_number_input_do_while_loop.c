/* Az <stdio.h> könyvtárat importálja, amely biztosítja a szabványos bemeneti és kimeneti
 * függvényeket, például a printf és scanf függvényeket. 
 */
#include <stdio.h> 

// A program belépési pontja, ahol a végrehajtás elkezdődik.
int main()  
{
    // Az 'number' változó, amely a felhasználó által megadott pozitív egész számot tárolja.
    int number;  

    // A 'do-while' ciklus, amely biztosítja, hogy a felhasználó **legalább egyszer** megadjon egy pozitív egész számot.
    do 
    {
        // Kiírja a felhasználónak, hogy egy pozitív egész számot kell megadnia.
        printf("Pozitiv egesz: ");  
        // A felhasználó beírja a számot, amelyet eltárolunk az 'number' változóban.
        scanf("%d", &number); 

        // A ciklus addig ismétlődik, amíg a megadott szám nem pozitív.
    } while (number <= 0);  

    // Kiírja a pozitív számot, amelyet a felhasználó megadott.
    printf("A szam: %d\n", number); 

    // A main függvény sikeres befejezését jelzi.
    return 0;  
}
