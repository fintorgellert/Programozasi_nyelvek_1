#include <stdio.h>

// Az angol ábécé betűinek számát meghatározzuk, ami 26 betű.
#define SIZE 26

/*
 * Eljárás: feltolt
 * -----------------
 * Feltölti a paraméterül kapott tömböt az angol kisbetűkkel (az 'a' karaktertől 'z'-ig).
 * 
 * Paraméterek:
 *  - tomb[]: Egy karaktertömb, amelyet az angol kisbetűkkel töltünk fel.
 * 
 * Visszatérési érték:
 *  - Nincs visszatérési értéke (void). A `tomb` tömb tartalmát módosítja az eljárás.
 *  - Az eljárásban módosított tömb az 'a' karaktertől kezdve az 'z' karakterig tart.
 */
void feltolt(char tomb[]) {
    // A ciklus 0-tól 25-ig fut, hogy az 'a' - 'z' betűket rendeljen a tömbhöz.
    for (int i = 0; i < SIZE; i++) {
        /*
            Az 'a' karakter ASCII értékéhez hozzáadjuk az indexet (0-tól 25-ig),
            így az 'a' + 0 = 'a', 'a' + 1 = 'b', ..., 'a' + 25 = 'z' lesz.
        */
        tomb[i] = (char)((int)'a' + i);  
    }
}

/*
 * Eljárás: tomb_kiir
 * -------------------
 * Kiírja a tömbben található karaktereket.
 * 
 * Paraméterek:
 *  - tomb[]: Egy karaktertömb, amelyet ki kell írni.
 * 
 * Visszatérési érték:
 *  - Nincs visszatérési értéke (void). A karaktereket a képernyőre írja ki.
 *  - Az egyes karaktereket vesszővel elválasztva írja ki, az utolsót sortöréssel.
 */
void tomb_kiir(char tomb[]) {
    // A ciklus 0-tól 25-ig fut, kiírja az összes karaktert a tömbből.
    for (int i = 0; i < SIZE; i++) {
        /*
            Minden karaktert kiírunk. Ha az utolsó karakter, akkor sortörést adunk hozzá,
            ha nem az utolsó karakter, akkor vesszőt használunk elválasztásként.
        */
        printf("%c%c ", tomb[i], (SIZE - 1 == i) ? '\n' : ',');  
    }
}

int main() {
    // A `abece` karaktertömb létrehozása, amely az angol kisbetűk tárolására szolgál.
    char abece[SIZE];

    // Feltöltjük az `abece` tömböt az 'a' - 'z' karakterekkel.
    feltolt(abece);

    // Kiírjuk a tömb tartalmát (az angol ábécét).
    tomb_kiir(abece);

    return 0;  // A program sikeresen befejeződött.
}
