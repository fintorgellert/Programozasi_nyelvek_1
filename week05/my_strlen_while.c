#include <stdio.h>   // Standard input-output könyvtár a kimenet kezeléséhez.
#include "prog1.h"   // Külső fájl, amely tartalmazza a `string` típus definícióját és egyéb szükséges elemeket.

int my_strlen(string s) {
    // A változó, amely számolja a string hosszát.
    int i = 0;

    /* 
     *  A ciklus addig tart, amíg a string nem ér véget. 
     *  A string végét a `'\0'` karakter jelzi, amely minden C string végén megtalálható.
     */
    while (s[i] != '\0') {  
        ++i;  // A `i` változó minden egyes iterációval növekszik.
    }

    // A ciklus végén az `i` változó értéke a string hossza lesz.
    return i;  
}

int main() {
    // A `text` változóban tároljuk a "hello" stringet.
    string text = "hello";   

    // Kiírjuk a "hello" string hosszát, amelyet a `my_strlen` függvény számol ki.
    printf("Hossz: %d\n", my_strlen(text));

    // Most teszteljük az üres stringet.
    
    // Üres string inicializálása.
    string emptyText = "";

    // Kiírjuk az üres string hosszát, amelyet szintén a `my_strlen` függvény számol ki.
    printf("Üres string hossza: %d\n", my_strlen(emptyText));

    return 0;  // A program sikeresen lefutott.
}
