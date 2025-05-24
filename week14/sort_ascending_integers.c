#include <stdio.h>      
#include <stdlib.h>


/*
 * Függvény, amely kiírja egy egész számokat tartalmazó tömb elemeit
 *
 * Paraméterek:
 *   - n: a tömb elemeinek száma
 *   - array: maga a tömb (egész számokat tartalmazó tömb)
 */
void print_array(const int n, const int array[])
{
    // Végigmegyünk a tömb minden elemén
    for (int i = 0; i < n; i++)
    {
        // Kiírjuk az i-edik elemet, utána egy szóközt
        printf("%d ", array[i]);
    }
    // Miután az összes elemet kiírtuk, egy újsor karaktert is kiírunk
    puts("");  // Ez ugyanaz, mint a printf("\n"), csak egyszerűbb
}

/* 
 * Ez a függvény két érték összehasonlítását végzi el a qsort() rendezéshez
 *
 * Fontos: a qsort függvény void* típusokat ad át, ezért előbb konvertálni kell
 * 
 * Paraméterek:
 *   - left: az egyik elem címe
 *   - right: a másik elem címe
 * 
 * Visszatérési érték:
 *   - negatív szám, ha left < right
 *   - 0, ha left == right
 *   - pozitív szám, ha left > right 
 */
int compare_int_ascending(const void *left, const void *right)
{
    // Először konvertáljuk vissza a void pointereket integer pointerekké
    const int *a = left;
    const int *b = right;

    // Visszaadjuk az értékkülönbséget
    // Ez határozza meg az elemek sorrendjét a qsort számára
    return *a - *b;

    /*
        Példa:
        - Ha *a =  5 és *b = 10, akkor return -5 →  5 kerül előrébb
        - Ha *a = 10 és *b =  5, akkor return  5 → 10 kerül hátrébb
        - Ha egyenlők, return 0 → sorrend maradhat
    */
}

int main()
{
    // Egy statikus (fix méretű) tömb definiálása, amely 5 egész számot tartalmaz
    int numbers[] = { 88, 56, 100, 2, 25 };

    // A tömb méretének kiszámítása:
    // Teljes memória méret (byte) osztva egy elem méretével (int)
    int size = sizeof(numbers) / sizeof(numbers[0]);

    // Kiírjuk a tömb elemeit a rendezés előtt
    // Hasznos lehet ellenőrizni, hogy valóban rendez-e a program
    printf("Eredeti tömb: ");
    print_array(size, numbers);

    // Rendezzük a tömböt növekvő sorrendbe a qsort függvénnyel
    // Paraméterek:
    //   - numbers: maga a tömb
    //   - size: hány elem van benne
    //   - sizeof(int): egy elem mérete (a qsort ezt használja a pointerléptetéshez)
    //   - compare_int_ascending: az összehasonlító függvény, ami eldönti az elemek sorrendjét
    qsort(numbers, size, sizeof(int), compare_int_ascending);

    // Kiírjuk a tömböt a rendezés után is, hogy látható legyen a hatása
    printf("Rendezett tömb: ");
    print_array(size, numbers);

    // A program sikeres lefutást jelez
    return 0;
}