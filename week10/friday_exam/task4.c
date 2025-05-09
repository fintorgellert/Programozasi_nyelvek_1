/*
 * Ez a program egy szöveget Caesar-kódolással titkosít. A Caesar-kódolás egy
 * egyszerű karakter-eltolásos módszer, ahol minden betűt egy adott számmal 
 * (eltolással) eltolunk az ábécében. Az eltolás mértékét és a titkosítandó 
 * szöveget parancssori argumentumként kell megadni.
 * 
 * Működés:
 * Például ha a szöveg: "ABC" és az eltolás 3, akkor az eredmény: "DEF".
 * Nem betű karakterek nem változnak (pl. számok, szóköz, írásjelek).
 */

#include <stdio.h>     
#include <stdlib.h>    
#include <string.h>  
#include <ctype.h>     

typedef char * string;

/*
 * Caesar-kódolást végző eljárás definíciója
 * 
 * Bemenet:
 * - string text: a titkosítandó szöveg (parancssorból kapjuk)
 * - int shift: az eltolás mértéke (pozitív egész szám)
 * 
 * Működés:
 * - minden kis- és nagybetűt a megadott eltolással módosít
 * - az ábécé körkörösen viselkedik (pl. 'Z' + 1 = 'A')
 * - más karaktereket (pl. számok, szóköz) változatlanul hagy
 * 
 * Kimenet:
 * - a titkosított szöveg a képernyőre kerül kiírásra
 */
void caesar_encoder(string text, const int shift) {
    int size = strlen(text) + 1;         // szöveg hossza +1 a lezáró \0 karakter miatt
    char code_text[size];                // kódolt szöveg számára helyfoglalás

    for (int i = 0; text[i] != '\0'; ++i) {
        char c = text[i];                // aktuális karakter
        char new_c;

        if (islower(c)) {
            /* 
             * Ha a karakter kisbetű (pl. 'a'–'z'), akkor az ASCII táblázat szerint 'a' = 97, 'z' = 122
             * Először a karakter pozícióját számítjuk ki az ábécében:
             * Pl. ha c = 'c', akkor (c - 'a') = ('c' - 'a') = (99 - 97) = 2 → az 'c' a 2. pozíció (0-alapú)
             *
             * Aztán hozzáadjuk az eltolást:
             * Ha shift = 3, akkor 2 + 3 = 5 → az 5. pozícióra kell ugranunk, ami az 'f'
             * 
             * Ezután modulo 26-tal biztosítjuk, hogy ha túllépjük a 'z'-t, akkor körbeérjünk az 'a'-ra.
             * Például ha c = 'y' (pozíció: 24), shift = 5, akkor:
             * (24 + 5) % 26 = 3 → visszalépünk az ábécé elejére, az eredmény: 'd'
             * 
             * Végül visszaalakítjuk pozícióból karakterré: 'a' + új_pozíció
             * Példa: 'a' + 5 = 97 + 5 = 102 = 'f'
             */
        
            new_c = 'a' + (c - 'a' + shift) % 26;
            code_text[i] = new_c;

        } else if (isupper(c)) {
            /*
             * Nagybetűk esetén hasonló a logika, csak 'A'-t használunk bázisnak (ASCII: 'A' = 65)
             * Pl. c = 'D' → (c - 'A') = 3
             * Shift = 4 → 3 + 4 = 7 → 'A' + 7 = 'H'
             *  Ha túllépnénk a 'Z'-t, modulo 26 gondoskodik a körbefordulásról
             */

            new_c = 'A' + (c - 'A' + shift) % 26;
            code_text[i] = new_c;
            
        } else {
            // Nem betű karaktereket (pl. számok, írásjelek, szóközök) változatlanul hagyjuk
            code_text[i] = c;
        }
        
    }

    code_text[size - 1] = '\0';          // lezárjuk a stringet

    printf("Titkosított szöveg: '%s'\n", code_text);
}


int main(int argc, string argv[]) {

    // Ellenőrizzük, hogy pontosan 2 parancssori argumentumot kapunk (programnéven kívül)
    if (argc != 3)
    {
        puts("Hiba: Pontosan kettő parancssori argumentumot kell megadni!");
        puts("Használat: ./caesar <szoveg> <eltolas>");
        exit(1);  // kilépés hibakóddal
    }

    // Parancssori argumentumok feldolgozása
    string text = argv[1];       // az első argumentum a titkosítandó szöveg
    int shift = atoi(argv[2]);  // a második argumentum az eltolás (stringből int)

    // Alap hibakezelés – negatív eltolást nem engedünk
    if (shift < 0) {
        puts("Hiba: A negatív eltolás kezelése nem része ennek a programnak.");
        exit(2);  // kilépés másik hibakóddal
    }

    // Meghívjuk a Caesar-kódolót
    caesar_encoder(text, shift);

    return 0;
}
