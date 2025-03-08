/* Az #include direktíva a szükséges fejléceket importálja, ebben az esetben a <stdio.h> könyvtárat,
 * amely biztosítja a standard bemeneti és kimeneti függvényeket, például a printf és scanf függvényeket. 
 */
#include <stdio.h>

// A program belépési pontja, a 'main' függvény, amely elindítja a program végrehajtását.
int main()  
{ 
    // Az 'number' változó a felhasználó által megadott számot tárolja.
    int number;
    //  A 'count' változó számolja, hogy hány nem nulla számot adott meg a felhasználó.
    int count = 0; 

    // A do-while ciklus legalább egyszer lefut, és addig ismétlődik, amíg a felhasználó 0-t nem ad meg.
    do 
    {
        // Kérjük a felhasználót, hogy adjon meg egy egész számot.
        printf("Egesz szam (vege: 0): ");  
        // Beolvassuk a felhasználó által megadott számot és eltároljuk a 'number' változóban.
        scanf("%d", &number);  

        // Ha a felhasználó nem 0-t adott meg, akkor növeljük a 'count' változót.
        if (number != 0) {  
            ++count;  
        }

        // A ciklus addig folytatódik, amíg a felhasználó 0-t nem ad meg.
    } while (number != 0);  

    // Kiírjuk a beírt nem nulla számok darabszámát.
    printf("Elemek szama: %d\n", count); 

    // A main függvény visszatérési értéke 0, amely a program sikeres befejezését jelzi.
    return 0;  
}
