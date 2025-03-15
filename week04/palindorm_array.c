#include <stdio.h>

/*
    Ez a függvény ellenőrzi, hogy egy adott tömb palindróm-e.
    A palindróm azt jelenti, hogy előlről és hátulról olvasva ugyanazok az elemek találhatók benne.
    
    A függvény bemeneti paraméterei:
        - size: a tömb mérete (hány elem van benne)
        - array[]: maga a tömb, amelynek elemeit vizsgáljuk
    
    A függvény visszatérési értéke:
        - 1 (igaz), ha a tömb palindróm
        - 0 (hamis), ha nem az
*/
int is_palindrom_array(const int size, const int array[]) {

    // A ciklus csak a tömb feléig megy (size / 2), mert párhuzamosan hasonlítjuk az elejét és a végét.
    for (int i = 0; i < size / 2; i++) {

        // Ha a tömb egyik eleje nem egyezik meg a hozzá tartozó végével, akkor NEM palindróm
        if (array[i] != array[size - 1 - i]) {

            // Azonnal visszatérünk, mert már egy eltérés is kizárja a palindróm tulajdonságot
            return 0; 
        }
    }

    // Ha minden összehasonlítás sikeres, akkor a tömb palindróm
    return 1; 
}


int main() {

    // Példa tömb, amely palindróm (ugyanaz előlről és hátulról)
    int array[10] = { 1, 2, 4, 5, 3, 3, 5, 4, 2, 1 };
    
    // A tömb mérete. Ez mindig az elemek számát jelzi.
    const int size = 10;

    // Meghívjuk az is_palindrom_array függvényt a tömbbel, hogy eldöntsük, palindróm-e
    int is_palindrom = is_palindrom_array(size, array);

    // Kiírjuk a tömb elemeit, hogy a felhasználó is lássa, mit vizsgálunk
    printf("Array: ");

    for (int i = 0; i < size; i++) {
        
        // Kiírjuk az aktuális tömb elemet
        printf("%d ", array[i]); 
    }

    // Új sort kezdünk a formázás érdekében
    printf("\n");

    // Kiírjuk az eredményt: ha a függvény 1-et adott vissza, akkor "true", különben "false"
    printf("Array is palindrom: %s\n", is_palindrom ? "true" : "false");

    // A program sikeresen lefutott
    return 0;
}
