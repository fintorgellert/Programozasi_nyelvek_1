#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Ez a program bemutatja, hogyan lehet egy egész számokból álló tömböt
 * véletlenszerűen feltölteni, majd kiszámolni belőle a minimumot, maximumot
 * és az elemek átlagát. Az eredményeket egy struktúrában (`Result`)
 * adjuk vissza a `calculate` függvényből.
 *
 * Fő lépések:
 * 1. A `srand(0)` segítségével fix seed-et állítunk be, így a véletlenszámok mindig ugyanazok (teszteléshez).
 * 2. Feltöltjük a tömböt 10 és 99 közötti véletlen számokkal.
 * 3. A `calculate` függvény kiszámítja:
 *    - a legkisebb értéket (`min`)
 *    - a legnagyobb értéket (`max`)
 *    - az elemek átlagát (`average`)
 * 4. A `main` kiírja a tömb elemeit, valamint az eredményeket.
 */

 
/* 
 * Struktúra: Result
 * -----------------
 * Ebben a struktúrában tároljuk a számítások eredményeit:
 *   int min       – a tömb legkisebb eleme
 *   int max       – a tömb legnagyobb eleme
 *   float average – az elemek átlaga
 */
typedef struct {
    int min;
    int max;
    float average;
} Result;

/*
 * Függvény: calculate
 * -------------------
 * Paraméterek:
 *   int array[] – bemeneti egész számokat tartalmazó tömb
 *   int size    – a tömb mérete
 *
 * Lépések:
 * 1. Inicializáljuk a `min` és `max` változókat a tömb első elemével.
 * 2. Végigiterálunk a tömb elemein:
 *    - ha kisebb értéket találunk, frissítjük `min`-t
 *    - ha nagyobbat, frissítjük `max`-ot
 *    - minden elemet hozzáadunk az `sum` változóhoz
 * 3. Az átlagot `(float)sum / size` képlettel számoljuk ki.
 * 4. Az eredményeket egy `Result` struktúrában adjuk vissza.
 *
 * Visszatérési érték:
 *   Result – benne a minimum, maximum és az átlag
 */
Result calculate(int array[], int size) {
    Result result;
    int sum = 0;

    // Kezdőérték beállítása az első elemre
    result.min = array[0];
    result.max = array[0];

    // A tömb bejárása
    for (int i = 0; i < size; i++) {
        if (array[i] < result.min) {
            // új minimum érték
            result.min = array[i];  
        }
        if (array[i] > result.max) {
            // új maximum érték
            result.max = array[i];  
        }
        
        // összeg gyűjtése
        sum += array[i];           
    }

    // Átlag számítása
    result.average = (float)sum / size;

    // Eredmények visszaadása
    return result;
}

int main() {
    // Véletlenszám-generátor inicializálása (fix értékkel, teszteléshez)
    srand(0);

    // 10 elemű tömb deklarálása és feltöltése véletlen számokkal [10, 99] tartományban
    int array[10];
    for (int i = 0; i < 10; i++) {
        array[i] = rand() % 90 + 10;  // 0–89 + 10 => 10–99
    }

    // Tömb elemeinek kiírása
    printf("A tömb elemei: ");
    for (int i = 0; i < 10; i++) {
        printf("%d", array[i]);
        if (i < 9) {
            printf(", ");  // az utolsó elem után nem teszünk vesszőt
        }
    }
    printf("\n");

    // Számítás végrehajtása és eredmény elmentése
    Result result = calculate(array, 10);

    // Eredmények kiírása
    printf("Legkisebb elem: %d\n", result.min);
    printf("Legnagyobb elem: %d\n", result.max);
    printf("Az elemek átlaga: %.1f\n", result.average);

    return 0;
}
