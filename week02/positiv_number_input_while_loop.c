/* Az <stdio.h> könyvtár importálása, amely a standard bemeneti és kimeneti 
 * műveletekhez szükséges (például printf és scanf függvényekhez). 
 */
#include <stdio.h> 

// A program belépési pontja, ahol a végrehajtás elkezdődik.
int main()  
{
    // Az 'number' változó tárolja a felhasználó által megadott pozitív egész számot.
    int number;  

    // Kiírja a felhasználónak, hogy egy pozitív egész számot kell megadnia.
    printf("Pozitiv egesz: ");  

    // A felhasználó megadja a számot, amelyet a program eltárol az 'number' változóban.
    scanf("%d", &number);

    // A while ciklus addig fut, amíg a megadott szám nem pozitív (nagyobb, mint 0).

    // Ha a szám nem pozitív (0 vagy negatív), újra kér egy számot.
    while (number <= 0)  
    {
        // Kiírja újra a kérést.
        printf("Pozitiv egesz: ");  

        // A felhasználó ismét megad egy számot.
        scanf("%d", &number);  
    }
    
    // Miután a felhasználó pozitív számot adott meg, a program kiírja a számot.

    // Kiírja a pozitív számot, amelyet a felhasználó megadott.
    printf("A szam: %d\n", number); 

    // A program sikeres befejezését jelzi.
    return 0;  
}
