#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000 // A tömb maximális mérete (1000 elem).

// A rand_int függvény véletlenszerű egész számot generál a megadott min és max értékek között.
int rand_int(int min, int max)
{
    // Az értékek közötti véletlenszerű számot generál.
    return min + (rand() % (max - min));
}

// A feltolt függvény feltölti a tömböt véletlenszerű számokkal a megadott tartományban (125 és 850 között).
void feltolt(const int n, int tomb[])
{
    for (int i = 0; i < n; ++i)
    {
        // Véletlenszerű számok generálása és a tömb elemeinek feltöltése.
        tomb[i] = rand_int(125, 850);
    }
}

// A tomb_atlaga függvény kiszámítja a tömb elemeinek átlagát.
double tomb_atlaga(const int n, const int tomb[])
{
    double sum = 0;

    for (int i = 0; i < n; ++i)
    {
        // Az összegzés.
        sum += tomb[i];
    }

    // Visszaadja az átlagot.
    return sum / n; 
}

int main()
{
    // A random számok generálásának inicializálása (2021 a magvetési érték).
    srand(2021); 

    // A véletlenszerű számokat tároló tömb.
    int random_numbers[SIZE] = {0}; 

    // A tömb feltöltése véletlenszerű számokkal.
    feltolt(SIZE, random_numbers); 

    // A változó, amely a tömb elemei közül hány szám nagyobb az átlagos értéknél.
    int count = 0;      

    // Az átlag kiszámítása.                            
    double avg = tomb_atlaga(SIZE, random_numbers); 

    // A ciklus, amely végigiterál a tömb elemein, és megszámolja, hány szám nagyobb az átlagos értéknél.
    for (int i = 0; i < SIZE; ++i)
    {
        if (random_numbers[i] > avg)
        {            
            /*
             * Ha az adott szám nagyobb, mint az átlag.
             * Növeljük a számlálót.
             */
            count++; 
        }
    }

    // Kiírjuk, hogy hány szám volt nagyobb, mint az átlag.
    printf("%d\n", count); 
    
    return 0; // A program sikeresen befejeződött.
}
