/* Az #include direktíva a szükséges fejléceket importálja, ebben az esetben a <stdio.h> könyvtárat,
 * amely biztosítja a standard bemeneti és kimeneti funkciókat, mint például a printf és scanf függvényeket. 
 */
#include <stdio.h> 

// A program belépési pontja, a 'main' függvény, amely a program végrehajtását kezdi el.
int main() {  

    // A 'number' változó egy egész számot tárol, amelyet a felhasználó ad meg.
    int number;  

    /* A printf függvény segítségével kiíratjuk a kérdést a felhasználónak, 
     * hogy adjon meg egy egész számot. 
     */
    printf("Adjon meg egy egész számot! ");  

    /* A scanf függvény segítségével beolvassuk a felhasználó által megadott egész számot.
     * Az "%d" formátum specifikátor az egész számokra vonatkozik, az '&number' pedig a 'number'
     * változó címére mutat, hogy a felhasználó által megadott számot oda tároljuk. 
     */
    scanf("%d", &number);  

    /* Az if-else szerkezet a szám páros vagy páratlan voltát ellenőrzi.
        
     * Az if feltétel ellenőrzi, hogy a szám osztható-e 2-tel (páros szám). 
     * Az '% 2' operátor a maradékos osztás, és ha a maradék 0, akkor páros számról van szó. 
     */
    if (number % 2 == 0) {  
        // Ha a szám páros, akkor ezt a szöveget írja ki.
        printf("%d az egy páros szám!\n", number);  
    } else {    // Ha a szám nem páros, akkor páratlan szám.
        // Ha a szám páratlan, akkor ezt a szöveget írja ki.
        printf("%d az egy páratlan szám!\n", number); 
    }

    // A main függvény visszatérési értéke 0, ami azt jelzi, hogy a program sikeresen befejeződött.
    return 0;  
}
