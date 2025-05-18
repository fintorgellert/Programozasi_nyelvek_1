#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
 * my_tolower:
 * ------------
 * Ez a függvény minden karaktert kisbetűssé alakít a megadott szövegben.
 * A bemeneti szöveg karaktereit helyben módosítja (in-place).
 *
 * Paraméter:
 *   - text[]: a módosítandó karakterlánc (nullával lezárt C string)
 */
void my_tolower(char text[])
{
    // Megszámoljuk a karakterek számát
    int length = strlen(text); 

    for (int i = 0; i < length; ++i)
    {
        // Minden karaktert kisbetűsítünk
        text[i] = tolower(text[i]); 
    }
}

/*
 * capitalize_v1:
 * ----------------
 * A szöveg első karakterét nagybetűssé alakítja, a többit kisbetűssé.
 * Közvetlenül módosítja a bemenetként kapott karakterláncot.
 *
 * Példa:
 *   Bemenet: "pRoGrAMoZáS"
 *   Kimenet: "Programozás"
 */
void capitalize_v1(char text[])
{
    int length = strlen(text);

    // Üres szöveg esetén nincs mit csinálni
    if (length == 0) {
        return;
    } 

    // Először minden karaktert kisbetűssé alakítunk
    my_tolower(text); 
   
    // Majd az első karaktert nagybetűssé tesszük
    text[0] = toupper(text[0]);
}

/*
 * capitalize_v2:
 * ----------------
 * Ez a függvény nem módosítja közvetlenül a bemenetet.
 * Ehelyett létrehoz egy másolatot, amit módosít, és ezt adja vissza.
 *
 * Fontos: a visszatérési értéket a hívónak kell felszabadítania (free).
 *
 * Paraméter:
 *   - text: az eredeti karakterlánc (const – nem módosítható)
 *
 * Visszatérési érték:
 *   - Egy újonnan allokált karakterlánc, amely a kapitalizált változat
 */
char* capitalize_v2(const char* text)
{
    // Dinamikusan másolatot készítünk
    char *copy = strdup(text); 

    // A másolatot módosítjuk
    capitalize_v1(copy); 

    // Visszatérünk a módosított példánnyal
    return copy;               
}

/*
 * main:
 * ------
 * Teszteli a capitalize_v1 függvényt.
 * Az eredeti szó módosul.
 * 
 * Teszteli a capitalize_v2 függvényt.
 * Az eredeti szöveg változatlan marad, a visszatérési értéket kiírjuk.
 */
int main()
{
    // Tesztszó, vegyes kis- és nagybetűkkel
    char word[] = "pRoGramoZAs";  

    printf("Előtte: %s\n", word);

    // Ha ezt használnánk, az eredeti szó módosulna
    // capitalize_v1(word);    

    // Új sztringet kapunk vissza
    char* result = capitalize_v2(word); 

    printf("Utána: %s\n", result);

    // Fontos a lefoglalt memória felszabadítása!
    free(result);

    return 0;
}
