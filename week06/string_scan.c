#include <stdio.h>
#include <string.h>   // A stringekkel kapcsolatos műveletekhez szükséges könyvtár (pl. strlen).

// A `SIZE` konstans, amely meghatározza a karakterlánc maximális hosszát (itt 200 karakter).
#define SIZE 200

int main() {
    // A `text` változó egy karaktertömb, amelybe a felhasználó nevét fogjuk tárolni.
    char text[SIZE];

    // Felhasználói bemenet kérése: a program kéri, hogy adja meg a nevét.
    printf("Mi a neved: ");

    /*
     * A `fgets` függvénnyel beolvassuk a felhasználó válaszát.
     * A `SIZE` biztosítja, hogy legfeljebb 200 karaktert olvassunk be, és megakadályozza a túlcsordulást.
     */ 
    fgets(text, SIZE, stdin);

    /*
     * Az `fgets` egy új sort is hozzáad a bemeneti szöveg végéhez ('\n'),
     * így ezt eltávolítjuk a sztring végéről.
     * A `strlen(text) - 1` a sztring hosszának utolsó karakterére mutat, azaz az új sor karakterére.
     * A `\0` karaktert helyezünk el ott, hogy a sztring végén ne legyen új sor karakter.
     */
    text[strlen(text) - 1] = '\0';

    // A felhasználónak köszönünk és kiírjuk a nevét.
    printf("Hello %s!\n", text);

    return 0;  // A program sikeresen befejeződött.
}
