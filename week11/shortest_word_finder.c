#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Program célja:
 * --------------
 * A parancssori argumentumként átadott szavak közül megtalálja és kiírja
 * azokat, amelyek legrövidebb hosszúságúak. Ha nem adtak át egyetlen szót sem,
 * hibaüzenettel leáll.
 */

/*
 * Kiírja azokat a szavakat, amelyek hossza megegyezik a legkisebb hosszúsággal
 * Paraméterek:
 *   n     – argumentumok száma (argc)
 *   array – argumentumokat tartalmazó tömb (argv)
 *   min   – a legrövidebb szó hossza
 */
void print_array(const int n, char* array[], const int min) {
    // i = 1-től indulunk, mert array[0] a program neve
    for (int i = 1; i < n; i++) {
        // Ha a szó hossza pontosan megegyezik a minimummal, kiírjuk
        if (strlen(array[i]) == min) {
            puts(array[i]);
        }
    }
}

int main(int argc, char* argv[]) {
    // Ha nem adtak át egyetlen szót sem (csak a program neve szerepel argc-ben)
    if (argc == 1) {
        // Hibát írunk a hibakimenetre és visszatérünk nem nulla kóddal
        fprintf(stderr, "Nem adtal meg egyetlen szot sem!\n");
        exit(1);
    }

    // A legrövidebb szó hosszát az első átadott szó hosszával inicializáljuk
    int shortest = strlen(argv[1]);

    // Végigmegyünk a többi szón, hogy megtaláljuk a valódi legrövidebbet
    for (int i = 2; i < argc; i++) {
        int length = strlen(argv[i]);
        // Ha az aktuális szó rövidebb, frissítjük a shortest változót
        if (length < shortest) {
            shortest = length;
        }
    }

    // Kiírjuk az összes olyan szót, melynek hossza megegyezik a legrövidebb hosszúsággal
    print_array(argc, argv, shortest);

    return 0;
}
