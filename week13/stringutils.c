#include "stringutils.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
 * mytolower:
 * ---------
 * A bemeneti szöveg összes karakterét kisbetűssé alakítja helyben.
 *
 * Paraméter:
 *   text[] - a módosítandó C-string
 */
void mytolower(char text[])
{
    int length = strlen(text);
    for (int i = 0; i < length; ++i)
    {
        text[i] = tolower((unsigned char)text[i]);
    }
}

/*
 * strcmpi:
 * -------
 * Kis- és nagybetű-független karakterlánc-összehasonlító függvény.
 * Lemásolja mindkét bemenetet, kisbetűssé alakítja, majd strcmp()-szel hasonlítja.
 *
 * Paraméterek:
 *   s - első C-string
 *   t - második C-string
 *
 * Visszatérési érték:
 *   <0, ha s < t
 *    0, ha s == t
 *   >0, ha s > t
 */
int strcmpi(const char* s, const char* t)
{
    // Dinamikus másolat mindkét stringre, hogy ne módosítsuk a bemenetet
    char* p1 = strdup(s);
    char* p2 = strdup(t);
    
    if (p1 == NULL || p2 == NULL) {
        // Memóriahiba esetén azonnali kilépés
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    // Kisbetűssé alakítás
    mytolower(p1);
    mytolower(p2);

    // Szokásos strcmp használata
    int result = strcmp(p1, p2);

    // Memória felszabadítása
    free(p1);
    free(p2);

    return result;
}