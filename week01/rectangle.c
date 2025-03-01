/* Az #include direktíva a szükséges fejléceket importálja, ebben az esetben a <stdio.h> könyvtárat,
 * amely biztosítja a standard bemeneti és kimeneti függvényeket, például a printf és scanf függvényeket. 
 */
#include <stdio.h>  

// A program belépési pontja, a 'main' függvény, amely elindítja a program végrehajtását.
int main() { 
    
    // Az 'a' változó tárolja a téglalap egyik oldalának hosszát.
    int a; 
    // A 'b' változó tárolja a téglalap másik oldalának hosszát. 
    int b;  

    // A printf segítségével arra kérjük a felhasználót, hogy adja meg az 'a' oldal hosszát.
    printf("Adja meg a téglalap a oldalhosszát! ");  
   
    // A scanf segítségével beolvassuk a felhasználó által megadott 'a' oldalt, és tároljuk az 'a' változóban.
    scanf("%d", &a);  

    // A printf segítségével arra kérjük a felhasználót, hogy adja meg a 'b' oldal hosszát.
    printf("Adja meg a téglalap b oldalhosszát! ");  
    // A scanf segítségével beolvassuk a felhasználó által megadott 'b' oldalt, és tároljuk a 'b' változóban.
    scanf("%d", &b);  

    /* A téglalap kerületét kiszámítjuk a képlet szerint: 
     *               K = 2 * (a + b), 
     * ahol 'a' és 'b' a téglalap két oldalának hossza. 
     */
    int circumference = 2 * (a + b);  

    /* A téglalap területét kiszámítjuk a képlet szerint: 
     *               T = a * b, 
     * ahol 'a' és 'b' a téglalap két oldalának hossza. 
     */
    int area = a * b;  

    // A printf segítségével kiíratjuk a téglalap kerületét a képernyőre. 
    printf("A téglalap kerülete: %d\n", circumference);  

    // A printf segítségével kiíratjuk a téglalap területét a képernyőre.
    printf("A téglalap területe: %d\n", area);  

   /* A main függvény visszatérési értéke 0, amely a program sikeres befejezését jelzi. 
    * Ez zárja le a program futtatását. 
    */
    return 0;  
}
