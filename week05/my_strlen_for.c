#include <stdio.h>   // Standard input-output könyvtár a kimenet kezeléséhez.
#include "prog1.h"   // Külső fájl, amely tartalmazza a `string` típus definícióját és egyéb szükséges elemeket.

int my_strlen(string s) {
    int i;

    /*
     * A `for` ciklus addig fut, amíg el nem érjük a string végét.
     * A string végét a `'\0'` karakter jelzi, amely minden C string végén megtalálható.
     * A ciklus minden egyes iterációval növeli az `i` változót, így számolja a karaktereket.
     */
    for (i = 0; s[i] != '\0'; ++i)
    {
        // A ciklus testében nincs semmi művelet, csak a string végéig való iterálás történik.
    }

    /*
     * A ciklus végén az `i` változó a string hosszát fogja tartalmazni,
     * mivel az utolsó lépésben a ciklus a nullához (a string végét jelző karakterhez) ér.
     */

    /*
     * Ha egy üres stringet adunk át a függvénynek (pl. `""`),
     * akkor az első ciklusfeltétel (`s[i] != '\0'`) már az első iterációban teljesülni fog,
     * mivel az üres string első eleme a `'\0'` karakter. Ilyenkor a ciklus egyszer sem fut le,
     * és az `i` változó értéke a 0 marad.
     */

    // Az üres string esetén a hossz 0 lesz, mivel nem tartalmaz karaktereket.
    return i;  
}

int main() {
    // A `text` változóban tároljuk a "Hello" stringet.
    string text = "Hello"; 
    
    // Üres string inicializálása.  
    string empty_text = "";

    // Kiírjuk a "Hello" string hosszát, amelyet a `my_strlen` függvény segítségével számolunk ki.
    printf("Megadott név hossza: %d\n", my_strlen(text));

    // Kiírjuk az üres string hosszát, amelyet a `my_strlen` függvény segítségével számolunk ki.
    printf("Üres string hossza: %d\n", my_strlen(empty_text));

    return 0;  // A program sikeresen lefutott.
}
