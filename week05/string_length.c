#include <stdio.h>
#include <string.h>   // A stringekkel kapcsolatos függvények, például strlen (string hosszának meghatározása).
#include "prog1.h"    // Külső könyvtár, amely tartalmazza a `string` típust és a `get_string` függvényt.

int main() {
    // Kérjük a felhasználót, hogy adja meg a nevét, és tároljuk el egy `string` típusú változóban.
    string name = get_string("Neved: ");   

    /*
     * A `strlen` függvény segítségével meghatározzuk a string hosszát.
     * A `strlen` a C nyelvben használt standard könyvtári függvény, amely egy string hosszát számolja meg,
     * tehát visszatér a karakterek számával, figyelmen kívül hagyva a null terminátort (`'\0'`).
     */
    int string_length = strlen(name);

    // Kiírjuk a felhasználó által megadott név hosszát.
    printf("Megadott név hossza: %d\n", string_length);

    return 0;  // A program sikeresen lefutott.
}
