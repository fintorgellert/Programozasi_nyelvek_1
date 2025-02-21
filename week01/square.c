/* Az #include direktíva a szükséges fejléceket importálja, ebben az esetben a <stdio.h> könyvtárat,
 * amely biztosítja a standard bemeneti és kimeneti függvényeket, mint például a printf és scanf függvényeket. 
 */
#include <stdio.h> 

// A program belépési pontja, a 'main' függvény, amely elindítja a program végrehajtását.
int main() {  
    
    // Az 'a' változó tárolja a négyzet oldalának hosszát, amelyet a felhasználó ad meg.
    int a;  

    // A printf segítségével arra kérjük a felhasználót, hogy adja meg a négyzet oldalának hosszát.
    printf("Adja meg a négyzet oldalhosszát! "); 

    // A scanf segítségével beolvassuk a felhasználó által megadott oldalhosszt, és tároljuk az 'a' változóban.
    scanf("%d", &a);  

    /* A négyzet kerületét kiszámítjuk a képlet szerint: 
     *              K = 4 * a,
     * ahol 'a' a négyzet oldalának hossza. 
     */
    int circumference = 4 * a;  

    /* A négyzet területét kiszámítjuk a képlet szerint: 
     *              T = a * a,
     * ahol 'a' a négyzet oldalának hossza. 
     */
    int area = a * a;  

    // A printf segítségével kiíratjuk a négyzet kerületét a képernyőre.
    printf("A négyzet kerülete: %d\n", circumference);  

    // A printf segítségével kiíratjuk a négyzet területét a képernyőre. 
    printf("A négyzet területe: %d\n", area);  
    
    /* A main függvény visszatérési értéke 0, amely a program sikeres befejezését jelzi. 
     * Ez zárja le a program futtatását. 
     */
    return 0;  
}
