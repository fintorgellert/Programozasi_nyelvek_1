# include <stdio.h>
# include <stdlib.h>  // A könyvtár, amely az exit függvényhez szükséges.
# include <string.h>  // A könyvtár, amely a string kezeléssel kapcsolatos függvényeket tartalmazza, például a strcmp-et.
# include "prog1.h"   // Külső fájl, amely a `string` típus definícióját tartalmazza.

/*
 * A parancssori argumentumok lehetővé teszik, hogy a felhasználó a program futtatásakor 
 * paramétereket adjon meg a program számára anélkül, hogy módosítania kellene a program kódját. 
 * Ezen argumentumok segítségével a program futásidejében adatokat adhatunk át a programnak,
 * amelyeket a program felhasználhat a műveletek végrehajtásához.
 * 
 * A parancssori argumentumok kezelését két változó segítségével végezzük el a main függvényben:
 *  - argc: Az argumentumok száma, amelyet a program parancssorából adnak meg. Az első argumentum mindig a program neve.
 *  - argv: Az argumentumok tömbje, amely tartalmazza a program nevét és a megadott paramétereket.   
*/

int main(int argc, string argv[]) {
    
    /* 
     * Elágazás a paraméterek számának ellenőrzésére:
     * Ha több, mint egy paramétert adnak meg a parancssorban, hibát jelezünk.
     * Az exit(3) utasítással a programot hibakóddal leállítjuk.
     */
    if (argc > 2) { 
        // Hibaüzenet kiírása.
        puts("Hiba! Maximum egy paraméter adható meg!");  

        // Kilépünk a programból hibakóddal, ha több, mint egy paraméter van.
        exit(3);  
    }

    // Ha nem adnak meg paramétert a parancssorban, akkor a program kimenete "Hello World!" lesz.
    if (argc == 1) {
        printf("Hello World!\n");
    } else {
        // Ha van paraméter (argv[1]), akkor az első paramétert elmentjük a `name` változóba.
        string name = argv[1];
        
        /*
         * Ha a paraméter "Batman" vagy "Robin", akkor speciális üzenetet írunk ki.
         * A strcmp() függvény összehasonlítja két karakterláncot. Ha egyenlőek, akkor 0-t ad vissza.
         */ 
        if (strcmp(name, "Batman") == 0 || strcmp(name, "Robin") == 0) {
            // Ha a paraméter "Batman" vagy "Robin", kiírjuk, hogy "Denevérveszély!".
            puts("Denevérveszély!");  
        } else {
            // Ha más név van, akkor azt kiírjuk, hogy "Hello [név]!"
            printf("Hello %s!\n", name);  
        }
    }

    return 0;  // A program sikeresen befejeződött.
}
