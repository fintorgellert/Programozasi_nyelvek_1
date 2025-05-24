#include <stdio.h>      
#include <stdlib.h>     

/*
 * Egy lebegőpontos (double) típusú tömb kiíratása
 *
 * Paraméterek:
 *  - n:     A tömb elemeinek száma
 *  - array: A tömb, amelynek értékeit kiíratjuk
 */ 
void print_array(const int n, const double array[])
{
    for (int i = 0; i < n; i++)
    {
        // 2 tizedesjeggyel kiírjuk az aktuális értéket
        printf("%.2lf ", array[i]);  
    }

    // Újsor kiírása a tömb után
    puts(""); 
}

/* 
 *  Összehasonlító függvény lebegőpontos számok csökkenő sorrendbe rendezéséhez
 *
 *  Ez a függvény a qsort-nak adható negyedik paraméterként
 * 
 * Paraméterek:
 *  - left:  Az első elem (void pointer, ezért át kell konvertálni double-ra)
 *  - right: A második elem (ugyanez)
 * 
 * Visszatérési érték:
 *    > 0, ha a második szám nagyobb -> a sorrend helyes,
 *    < 0, ha az első szám nagyobb   -> cserélni kell,
 *      0, ha egyenlőek -> nem kell csere 
 */
int compare_double_desc(const void *left, const void *right)
{
    // Az első szám konvertálása double pointerré
    const double *a = (const double *)left;  
    
    // A második szám konvertálása double pointerré
    const double *b = (const double *)right; 

    // Kiszámítjuk a különbséget (fordított sorrendhez: *b - *a)
    double diff = *b - *a;

    // A lebegőpontos különbség alapján határozzuk meg a sorrendet
    if (diff > 0) {
        // A második nagyobb -> nincs teendő (b elöl marad)
        return 1; 
    } else if (diff < 0) {
        // Az első nagyobb -> csere szükséges (a menjen előre)
        return -1;  
    } else {
        // A két szám egyenlő -> nem változtatunk
        return 0;   
    }
}

int main()
{
    // Egy double típusú számokat tartalmazó tömb, amelyet rendezni fogunk
    double numbers[] = {23.5, 7.9, 45.1, 12.0, 98.3, 34.7, 56.2, 11.4, 3.3, 78.6};

    // A tömb méretének meghatározása: teljes méret osztva egy elem méretével
    int size = sizeof(numbers) / sizeof(numbers[0]);

    // Kiírjuk a tömb tartalmát rendezés előtt
    printf("Eredeti tömb:\n");
    print_array(size, numbers);

    /* 
     * A qsort függvényt hívjuk meg a rendezéshez
     *
     * Paraméterei:
     *   - numbers: a rendezendő tömb
     *   - size: hány elem van benne
     *   - sizeof(double): egy elem mérete bájtban
     *   - compare_double_desc: az összehasonlító függvény a csökkenő sorrendhez
     */
    qsort(numbers, size, sizeof(double), compare_double_desc);

    // Kiírjuk a tömb tartalmát rendezés után
    printf("Rendezett tömb (csökkenő sorrend):\n");
    print_array(size, numbers);

    // A program sikeresen lefutott
    return 0; 
}
