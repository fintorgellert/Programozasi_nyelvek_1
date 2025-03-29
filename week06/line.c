#include <stdio.h>
 
/*
 * Eljárás: line
 * -----------------
 * Kiír egy vonalat, amely a paraméterül kapott karakterből áll, és a paraméterben megadott hosszúságú.
 * 
 * Paraméterek:
 *  - c: A karakter, amellyel a vonalat kitöltjük.
 *  - length: A vonal hossza, amely meghatározza, hogy hány karaktert írunk ki.
 * 
 * Visszatérési érték:
 * - Nincs visszatérési értéke (void). A vonal karaktereit a képernyőre írja ki.
 */
void line(char c, int length) {
    /*
     * A ciklus hossza a paraméterben megadott `length`, minden iterációban kiír egy karaktert.
     * A `putchar()` függvénnyel kiírjuk a paraméterül kapott karaktert.
     */
    for (int i = 0; i < length; ++i) {
        putchar(c);  
    }

    // A ciklus után sortörést adunk, hogy a következő kimenet új sorban jelenjen meg.
    puts("");  
}

int main() {
    // Meghívjuk a `line` eljárást, hogy kiírjon egy vonalat '-' karakterekből 20 hosszúságban.
    line('-', 20);

    return 0;  // A program sikeresen befejeződött.
}
