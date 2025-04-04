#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// A beolvasható szám maximális hossza.
#define SIZE 1024  

/*
 * A program egy számjegyekből álló karakterláncot kér be a felhasználótól, majd kiszámolja
 * az egyes számjegyek összegét. Pl. ha a felhasználó "1234"-et ad meg, akkor az összeg: 1 + 2 + 3 + 4 = 10.
 * 
 * Fontos: A program csak számjegyeket tartalmazó bemenetet vár! Hibás bemenet esetén figyelmeztetést ad.
 */

int main() {
    int sum = 0;
    char str_number[SIZE];

    // Szám bekérése a felhasználótól.
    printf("Szám: ");
    fgets(str_number, SIZE, stdin);
    
    // Az újsor karakter eltávolítása.
    str_number[strcspn(str_number, "\n")] = '\0'; 

    // Bemenet ellenőrzése: csak számjegyeket fogadunk el.
    for (int i = 0; str_number[i] != '\0'; ++i) {
        if (!isdigit(str_number[i])) {
            printf("Hiba! Csak számjegyeket adhatsz meg.\n");
            return 1;
        }

        // Karaktert számjeggyé alakítunk és összeadjuk.
        sum += str_number[i] - '0';  
    }

    printf("A számjegyek összege: %d\n", sum);

    return 0;
}
