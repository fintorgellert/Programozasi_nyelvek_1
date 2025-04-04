/*
 * Program leírása:
 * ----------------
 * Ez a program lehetővé teszi a felhasználó számára, hogy jelszavakat adjon meg, 
 * és ellenőrzi azok erősségét. A jelszó akkor erős, ha legalább 8 karakter hosszú, 
 * és tartalmaz kisbetűt, nagybetűt és számjegyet.
 *
 * A felhasználó addig adhat meg jelszavakat, amíg a '*' karaktert nem írja be, 
 * amely jelzi a program befejezését.
 *
 * Futtatás:
 * ---------
 * Fordítsd le és futtasd a programot. Példa kimenet:
 *
 *     Adj meg jelszavakat '*' végjelig!
 *     
 *     Jelszó: hello
 *     Gyenge jelszó
 *     
 *     Jelszó: Password123
 *     Erős jelszó
 *     
 *     Jelszó: *
 *
 * A program sikeresen ellenőrzi a jelszavak erősségét és visszajelzést ad.
 */


#include <stdio.h>      // Standard I/O könyvtár a bemenetek és kimenetek kezeléséhez.
#include <string.h>     // Stringkezelő függvények használatához (pl. strlen).
#include <ctype.h>      // Karakterellenőrző függvények (pl. islower, isupper, isdigit).
#include "prog1.h"      // Külső fájl a `string` típus definíciójához.

#define MAX 200  // A jelszó maximális hossza.

/*
 * Függvény: is_strong
 * ----------------------
 * Megvizsgálja, hogy a megadott jelszó elég erős-e.
 * 
 * Egy jelszó erősnek számít, ha:
 *   - Legalább 8 karakter hosszú.
 *   - Tartalmaz kisbetűt.
 *   - Tartalmaz nagybetűt.
 *   - Tartalmaz számjegyet.
 * 
 * Paraméterek:
 *   - password: A vizsgálandó jelszó (karakterlánc).
 * 
 * Visszatérési érték:
 *   - 1 (igaz), ha a jelszó erős.
 *   - 0 (hamis), ha a jelszó nem elég erős.
 */
int is_strong(string password)
{
    int length = strlen(password);
    int long_enough = (length >= 8);
    int has_lowercase = 0;
    int has_uppercase = 0;
    int has_digit = 0;

    // Végigmegyünk a jelszó karakterein, és ellenőrizzük, hogy tartalmaz-e kisbetűt, nagybetűt és számot.
    for (int i = 0; i < length; i++)
    {
        char c = password[i];
        if (islower(c)) {
            has_lowercase = 1;
        }
        if (isupper(c)) {
            has_uppercase = 1;
        }
        if (isdigit(c)) {
            has_digit = 1;
        }
    }

    // Csak akkor erős a jelszó, ha mind a négy feltétel teljesül.
    return long_enough && has_lowercase && has_uppercase && has_digit;
}

int main()
{
    char text[MAX];

    // Felhasználói útmutató.
    puts("Adj meg jelszavakat '*' végjelig!");
    puts("");
    
    while (1)
    {
        // Jelszó bekérése a felhasználótól.
        printf("Jelszó: ");
        fgets(text, MAX, stdin);

        // Az újsor karakter eltávolítása.
        text[strlen(text) - 1] = '\0';  

        // Ha a felhasználó "*" jelet ad meg, kilépünk a ciklusból.
        if (strcmp(text, "*") == 0) {
            break;
        }

        // Jelszó erősségének ellenőrzése.
        if (is_strong(text)) {
            puts("Erős jelszó");
        } else {
            puts("Gyenge jelszó");
        }

        // Üres sor a jobb olvashatóság érdekében.
        puts("");  
    }

    return 0;
}

