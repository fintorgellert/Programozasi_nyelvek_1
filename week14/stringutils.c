#include "stringutils.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* 
 * Ez a függvény a kapott karaktertömb összes karakterét kisbetűssé alakítja.
 * A `tolower()` függvény használatával minden karakter ASCII értékét konvertálja kisbetűs megfelelőjére.
 * 
 * FONTOS: ez a függvény "in-place" dolgozik, tehát az eredeti karaktertömb módosul.
 */
void to_lower_case(char text[]) {
    // Meghatározzuk a string hosszát
    int length = strlen(text); 

    for (int i = 0; i < length; ++i) {
        // Minden karaktert kisbetűsítünk
        text[i] = tolower(text[i]);  
    }
}

/* 
 * Ez a függvény két stringet hasonlít össze kis- és nagybetű érzéketlen módon.
 *
 * A működése:
 * 1. Lemásolja a két stringet dinamikusan
 * 2. Mindkét másolatot kisbetűsítjük
 * 3. Összehasonlítjuk őket a `strcmp` segítségével
 * 4. Felszabadítjuk a memóriát, majd visszatérünk az összehasonlítás eredményével.
 */
int strcmpi(const char* s1, const char* s2) {
    // Dinamikusan lefoglalunk egy másolatot az első stringből
    char* copy1 = strdup(s1);  

    // Második string másolása
    char* copy2 = strdup(s2);  

    // Mindkét másolatot kisbetűsítjük
    to_lower_case(copy1);      
    to_lower_case(copy2);

    // Szimpla strcmp, de most már kisbetűsítve
    int result = strcmp(copy1, copy2);  

    // Felszabadítjuk a lefoglalt memóriát
    free(copy1); 
    free(copy2);

    // Visszatérünk az összehasonlítás eredményével: <0, =0, >0
    return result;  
}

/* 
 * Ez a függvény egy stringet másol, és úgy alakít át,
 * hogy csak az első betű nagybetű, a többi kisbetű lesz.
 * Példa: "jANOS" -> "Janos"
 *
 * A működés lépései:
 * 1. NULL ellenőrzés
 * 2. strdup - dinamikus másolat létrehozása
 * 3. Kisbetűsítés az egész szóra
 * 4. Az első karaktert nagybetűsítjük (ha nem üres)
 * 5. Visszatérünk az újonnan létrehozott stringgel
 *
 * FONTOS: a visszatérő stringet a hívónak kell `free()`-vel felszabadítania!
 */
char* capitalize(const char* text) {
    if (text == NULL) {
        // Ha üres a bemenet, visszatérünk NULL-lal
        return NULL;  
    }

    // String másolat létrehozása
    char* copy = strdup(text);  

    if (copy == NULL) {
        // Sikeres memóriakezelés ellenőrzése
        return NULL;  
    }

    if (copy[0] == '\0') {
        // Ha a string üres, visszaadjuk változtatás nélkül
        return copy;  
    }

    // Először minden betűt kisbetűsítünk
    to_lower_case(copy);        

    // Majd az első betűt nagybetűvé alakítjuk
    copy[0] = toupper(copy[0]); 

    // Az újonnan létrehozott, módosított stringgel térünk vissza
    return copy;  
}
