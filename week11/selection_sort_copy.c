#include <stdio.h>
#include <stdlib.h>

/*
 * Egyszerű kiválasztásos rendezés (Selection Sort) egy másolatot készítve.
 * A rendezés O(n²) idő­komplexitású, lassú nagy tömbök esetén.
 */

/*
 * Függvény: swap
 * --------------
 * Két egész típusú változó értékét felcseréli.
 *
 * Paraméterek:
 *   a – pointer az első értékre
 *   b – pointer a második értékre
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
 * Függvény: sorted_copy
 * ---------------------
 * Létrehoz egy dinamikus másolatot az input tömbről, majd
 * kiválasztásos rendezéssel növekvő sorrendbe rendezi azt.
 *
 * Paraméterek:
 *   size  – az eredeti tömb mérete
 *   array – az eredeti tömb elemeit tartalmazó tömb
 *
 * Visszatérési érték:
 *   int* – pointer egy új, rendezett tömbre,
 *          amelyet a hívónak kell free()-val felszabadítania.
 *
 * Részletes leírás:
 * 1. Létrehozunk egy dinamikusan foglalt tömböt (malloc), hogy ne módosítsuk az eredetit.
 * 2. Belemásoljuk az eredeti tömb összes elemét.
 * 3. Két beágyazott ciklussal kiválasztásos rendezést hajtunk végre:
 *    - A külső i ciklus minden pozícióra kiválasztja a legalacsonyabb elemet a tömb aktuális részéből.
 *    - A belső j ciklus megkeresi a legkisebb elemet a [i..size-1] intervallumban.
 *    - Ha találunk nála kisebbet, swap-pel kicseréljük.
 */
int *sorted_copy(const int size, const int array[])
{
    // Dinamikus másolat létrehozása
    int *copy = malloc(size * sizeof(int));
    if (copy == NULL) {
        fprintf(stderr, "Hiba: malloc nem adott memóriát!\n");
        exit(1);
    }

    // Eredeti elemek másolása
    for (int i = 0; i < size; ++i) {
        copy[i] = array[i];
    }

    // Kiválasztásos rendezés (Selection Sort)
    for (int i = 0; i < size - 1; ++i) {
        // i pozícióra keressük a legkisebb elemet a maradék tömbben
        for (int j = i + 1; j < size; ++j) {
            // Ha találunk egy kisebbet, cseréljük
            if (copy[j] < copy[i]) {
                swap(&copy[i], &copy[j]);
            }
        }
    }

    return copy;
}

/*
 * Függvény: print_array
 * ---------------------
 * Egy egész típusú tömb elemeit írja ki szóközökkel elválasztva.
 *
 * Paraméterek:
 *   size  – a tömb elemeinek száma
 *   array – a kiírandó tömb
 */
void print_array(const int size, const int array[])
{
    for (int i = 0; i < size; ++i) {
        printf("%d", array[i]);

        if (i < size - 1) {
            putchar(' ');
        }
    }

    puts("");
}

int main()
{
    // Példa tömb, amelyet nem akarunk módosítani
    int numbers[] = { 45, 84, 36, 57, 65, 43, 45, 43, 56, 17 };
    
    // tömbhossz kiszámítása
    int n = sizeof(numbers) / sizeof(numbers[0]);  

    // Rendezett másolat készítése
    int *sorted = sorted_copy(n, numbers);

    // Eredeti tömb kiírása
    puts("Eredeti tomb:");
    print_array(n, numbers);

    // Rendezett másolat kiírása
    puts("Rendezett tomb (masolat):");
    print_array(n, sorted);

    // Dinamikus tömb felszabadítása
    free(sorted);

    return 0;
}
