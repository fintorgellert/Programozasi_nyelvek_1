/*
 * Fordítás:
 *   $ gcc input_name.c prog1.c
 * 
 * Futtatás:
 *   $ ./a.out
 */ 

#include <stdio.h>
#include "prog1.h"  // Külső könyvtár, amely tartalmazza a `string` típust és a `get_string` függvényt

int main() {
    /*
     * A `get_string` függvény segítségével bekérünk egy nevet a felhasználótól.
     * A függvény egy stringet ad vissza, amelyet eltárolunk a `name` változóban.
     */
    string name = get_string("Neved: ");

    /*
     * Kiírjuk a felhasználó nevét egy üdvözlő üzenetben.
     * A `%s` formátum specifikátor segítségével helyettesítjük be a `name` változó értékét.
     */
    printf("Hello %s!\n", name);

    return 0;  // A program sikeresen lefutott
}
