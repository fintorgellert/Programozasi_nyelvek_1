#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SIZE 1024  // A bemeneti szöveg maximális hossza.

int main()
{
    // A karakterek típusainak számlálására szolgáló változók.
    int lower = 0, upper = 0, digit = 0, space = 0;

    // A szöveg tárolására szolgáló tömb.
    char text[SIZE];  

    // Végtelen ciklus, ami addig tart, amíg a felhasználó "*" karaktert nem ad meg.
    while (1)
    {
        // A felhasználó bemenetének kérése.
        printf("Szöveg (vége: *): ");

        // A szöveg beolvasása a felhasználótól.
        fgets(text, SIZE, stdin);  

        // Az utolsó karakter (újsor) eltávolítása.
        text[strlen(text) - 1] = '\0';  

        // A ciklus megszakítása, ha a felhasználó "*" karaktert ad meg.
        if (strcmp(text, "*") == 0)
            break;

        // A szöveg karaktereinek vizsgálata.
        for (int i = 0; text[i] != 0; ++i)
        {
            // Az aktuális karakter.
            char c = text[i];

            // Kisbetűk számlálása.
            if (islower(c))
                lower++;

            // Nagybetűk számlálása.
            else if (isupper(c))
                upper++;

            // Számjegyek számlálása.
            else if (isdigit(c))
                digit++;

            // Szóközök számlálása.
            else if (isspace(c))
                space++;
        }
    }

    // Üres sor kiírása.
    puts("");

    /*
     * A karakterek típusainak kiírása a felhasználónak.
     * A %-4d kifejezés a számok formázott kiírását végzi.
     * A %-4d azt jelenti, hogy a szám balra igazítva, 4 karakter szélességben lesz kiírva.
     * Ha a szám kevesebb, mint 4 karakter, akkor szóközökkel kitölti a kért szélességet.
     * Például: ha a szám 3, akkor a kimenet: "3   ".
     */ 
    printf("Kisbetűk száma:   %-4d\n", lower);
    printf("Nagybetűk száma:  %-4d\n", upper);
    printf("Szóközök száma:   %-4d\n", space);
    printf("Számjegyek száma: %-4d\n", digit);

    return 0;  // A program sikeresen befejeződik.
}
