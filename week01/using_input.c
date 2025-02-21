/* Az #include direktíva a szükséges fejléceket importálja, ebben az esetben a <stdio.h> könyvtárat,
 * amely biztosítja a standard bemeneti és kimeneti függvényeket, mint például a printf és scanf függvényeket. 
 */
#include <stdio.h>  

// A program belépési pontja, a 'main' függvény, amely elindítja a program végrehajtását.
int main() {  

    // A 'number' változó tárolja a felhasználó által megadott egész számot.
    int number;  

    // A printf segítségével arra kérjük a felhasználót, hogy adjon meg egy egész számot.
    printf("Adjon meg egy egész számot! ");  

    // A scanf segítségével beolvassuk a felhasználó által megadott számot és tároljuk a 'number' változóban.
    scanf("%d", &number);  

    // A printf segítségével kiíratjuk a felhasználó által megadott számot.
    printf("A megadott szám: %d\n", number); 
    
    /* A main függvény visszatérési értéke 0, amely a program sikeres befejezését jelzi. 
     * Ez zárja le a program futtatását.
     */
    return 0;  
}
