/* Az #include direktíva a szükséges fejléceket importálja, ebben az esetben a <stdio.h> könyvtárat,
 * amely biztosítja a standard bemeneti és kimeneti funkciókat, például a printf függvényt. 
 */
#include <stdio.h>  

// A program belépési pontja, a 'main' függvény, amely minden C programban kötelező és a program végrehajtását kezdi el.
int main() {  

    /* A printf függvény segítségével kiírjuk a képernyőre a "Hello, World!" üzenetet. 
     * A "\n" karakterek egy új sort eredményeznek, hogy a következő kimenet új sorban jelenjen meg. 
     */
    printf("Hello, World!\n");  
    
    /* A main függvény visszatérési értéke 0, amely a program sikeres befejezését jelzi. 
     * Ez zárja le a program futtatását. 
     */
    return 0;  
}
