/* Az <stdio.h> könyvtár importálása, amely biztosítja a bemeneti és kimeneti műveleteket, 
 * például a printf és scanf függvényeket. 
 */
#include <stdio.h>  

// A program belépési pontja, ahol a végrehajtás elkezdődik.
int main()  
{
    // Az 'n' változó, amely tárolja a felhasználó által megadott számot.
    int n; 

    // Kiírja a felhasználónak, hogy egy egész számot kell megadnia.
    printf("Adjon meg egy egész számot: ");  

    // A felhasználó megadja a számot, amelyet a program eltárol az 'n' változóban.
    scanf("%d", &n);  

    // Feltételvizsgálat a szám típusának (negatív, pozitív, nulla) meghatározására.
    
    if (n < 0) {            // Ha a szám kisebb, mint 0 (negatív szám), a program kiírja, hogy negatív. 
        printf("Megadott szám (%d) negatív.\n", n);
    } else if (0 < n) {     // Ha a szám nagyobb, mint 0 (pozitív szám), a program kiírja, hogy pozitív. 
        printf("Megadott szám (%d) pozitív.\n", n);
    } else {                // Ha egyik előző feltétel sem teljesül, akkor a szám nulla. 
        puts("Megadott szám nulla.");
    }

    // A program sikeres befejezését jelzi.
    return 0;  
}
