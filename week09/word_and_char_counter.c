#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef char * string;

/*
 * Ez a program megszámolja egy adott szövegben:
 * - a szavak számát,
 * - a karakterek számát (szóközök nélkül).
 *
 * Működés:
 * - A `for` ciklus karakterenként bejárja a szöveget.
 * - A `c_count` csak a nem-whitespace karaktereket számolja.
 * - A `word_count` minden alkalommal nő, amikor egy nem-whitespace karaktert találunk,
 *   és előzőleg nem voltunk szóban (azaz új szó kezdődik).
 *
 * Megjegyzés:
 * - Ez a megoldás jól kezeli a többszörös szóközöket és az újsor/tab karaktereket is,
 *   mivel a `isspace()` függvény mindenféle elválasztó karaktert felismer.
 */



 int main()
 {
    // A bemeneti szöveg, amit vizsgálunk
    string text = "Geza kek az eg!";

    // Változók a szavak és karakterek számolásához
    int word_count = 0;
    int c_count = 0;

    // Segédváltozó annak követésére, hogy jelenleg egy szóban vagyunk-e
    int in_word = 0;

    // A szöveg hosszának lekérése
    int length = strlen(text);

    // A szöveg karakterenkénti bejárása
    for (int i = 0; i < length; ++i) {
        // Ha az aktuális karakter whitespace (szóköz, tabulátor, sortörés stb.)
        if (isspace(text[i])) {
            // Akkor kiléptünk egy szóból
            in_word = 0;
        } else {
            // Minden nem-whitespace karaktert megszámolunk
            c_count++;

            // Ha előzőleg nem voltunk szóban, de most karaktert találtunk
            // akkor egy új szó kezdődött
            if (!in_word) {
                word_count++;
                in_word = 1; 
            }
        }
    }

    // Eredmények kiírása
    printf("A '%s' szoveg %d szobol all es %d karakterbol!\n", text, word_count, c_count);

    return 0;
 }