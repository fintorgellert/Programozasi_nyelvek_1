#include <stdio.h>   

// A számok tárolására szolgáló tömb maximális mérete (0-tól 99-ig indexelve, összesen 100 elem).
#define SIZE 100      

/*
 * Függvény: get_int_between
 * --------------------------
 * Célja:
 *   Bekér egy egész számot a felhasználótól, amely vagy 0, vagy a megadott [min, max] intervallumba esik.
 *
 * Paraméterek:
 *   - min: Az elfogadható értékek alsó határa.
 *   - max: Az elfogadható értékek felső határa.
 *
 * Visszatérési érték:
 *   - A felhasználó által megadott szám, ha az 0 vagy az [min, max] intervallumba esik.
 *
 * Működés:
 *   A függvény egy végtelen ciklusban kér be számot. Amennyiben a bevitt érték 0, vagy min <= n <= max,
 *   akkor visszatér ezzel az értékkel. Ellenkező esetben hibát ír ki, és újra kéri a felhasználótól a számot.
 */
int get_int_between(int min, int max) {
    // A változó, amelyben a felhasználó által beírt számot tároljuk.
    int n; 

    // Végtelen ciklus, amely csak akkor szakad meg, ha a szám megfelel a feltételeknek.
    while (1) {  
        // Kéri a felhasználót, hogy adjon meg egy számot.    
        printf("Szám: ");  

        // Beolvassa a számot a standard bemenetről.
        scanf("%d", &n);       

        /*
         * Ellenőrizzük, hogy a beírt szám az elfogadható intervallumba esik-e,
         * vagy éppenséggel 0-e. (0 mindig elfogadott, mint kilépési feltétel.)
         */
        if ((min <= n && n <= max) || (n == 0)) {
            // Ha az érték megfelel, visszatérünk vele.
            return n; 
        }

        // Ha az érték nem esik az intervallumba, hibaüzenetet írunk ki.
        puts("Ez a szám kívül esik az elfogadható intervallumon!");
    }
}

/*
 * Függvény: get_different_numbers
 * -------------------------------
 * Célja:
 *   Megszámolja, hány különböző szám került be a tömbbe.
 *
 * Paraméterek:
 *   - array[]: Egy olyan egész számokat tartalmazó tömb, amelyben 0 azt jelenti, hogy az adott indexű szám nem lett megadva,
 *              míg 1 azt jelzi, hogy az adott indexű szám meg lett adva.
 *
 * Visszatérési érték:
 *   - A tömb azon indexeinek száma, amelyek értéke 1, azaz a különböző számok darabszáma.
 */
int get_different_numbers(int array[]) {
    // Számláló, amely a különböző számok darabszámát tartalmazza.
    int count = 0;  

    // A for ciklus végigiterál a tömb minden elemén (0-tól SIZE-ig).
    for (int i = 0; i < SIZE; ++i) {
        // Ha az adott indexű érték 1, az azt jelenti, hogy a szám szerepel a felhasználó által megadott értékek között.
        if (array[i]) {
            // Növeljük a számlálót.
            count++;  
        }
    }

    // Visszatérünk a különböző számok darabszámával.
    return count;  
}

/*
 * Függvény: print_array
 * ----------------------
 * Célja:
 *   Kiírja a tömbben rögzített indexeket, ahol az érték 1.
 *   Ezek az indexek a felhasználó által megadott számok.
 *
 * Paraméterek:
 *   - array[]: Egy olyan tömb, amely a számok jelenlétét jelzi (0: nem adott, 1: adott).
 *
 * Működés:
 *   A függvény végigiterál a tömb elemein, és ha egy elem értéke 1, akkor azt az indexet kiírja.
 *   Az elemek vesszővel vannak elválasztva, és az utolsó elem után új sort kezd.
 */
void print_array(int array[]) {
    // Logikai flag a formázott kiíráshoz: ha az első elem, akkor nem írunk vesszőt.
    int first = 1;  

    // Iterálunk a tömb minden elemén.
    for (int i = 0; i < SIZE; ++i) {
        // Csak azokat az indexeket írjuk ki, ahol az érték 1 (tehát a szám meg lett adva).
        if (array[i]) {
            // Ha nem az első kiírt elem, akkor vesszővel elválasztjuk az elemeket.
            if (!first) {
                printf(", ");
            }

            // Kiírjuk az aktuális indexet, ami a felhasználó által megadott számot jelzi.
            printf("%d", i);

            // Miután az első elemet kiírtuk, a flag értéke 0-ra változik.
            first = 0;
        }
    }
    
    puts("");  // Új sort kezdünk a kiírás végén.
}

int main() {
    // Olyan tömb, amelyben 0 jelzi, hogy egy adott szám nem lett megadva, és 1, hogy a szám meg lett adva.
    int numbers[SIZE];  
                        
    // Inicializáljuk a tömböt 0-ra, hogy minden index elején a szám "nem lett megadva" állapotban legyen.
    for (int i = 0; i < SIZE; ++i) {
        numbers[i] = 0;
    }

    /*
     * A while ciklus addig fut, amíg a felhasználó 0-t nem ad meg.
     * A get_int_between függvény segítségével bekérjük a számot, 
     * amelynek 1 és 99 közötti értéknek kell lennie, vagy 0-nak, ami a kilépést jelzi.
     */
    while (1) {
        int n = get_int_between(1, 99);

        // Ha a felhasználó 0-t adott meg, akkor kilépünk a ciklusból.
        if (n == 0) {
            break;
        }

        /*
         * Ha a szám meg lett adva, akkor az adott indexű elem értékét 1-re állítjuk,
         * így jelezve, hogy ez a szám szerepel a felhasználó által bevitt értékek között.
         */
        numbers[n] = 1;
    }
    
    // Megszámoljuk, hány különböző számot adott meg a felhasználó.
    int count = get_different_numbers(numbers);
    
    // Kiírjuk a különböző számok darabszámát.
    printf("%d db különböző szám lett megadva.\n", count);
    
    // Kiírjuk a különböző számokat növekvő sorrendben.
    printf("Ezek (növekvő sorrendben): ");
    print_array(numbers);
    
    return 0;  // A program sikeresen befejeződött.
}
