#include <stdio.h>

/* 
   A 'average_array' függvény kiszámítja egy tömb elemeinek átlagát.
   Paraméterek:
   - size: a tömb mérete (hány elem van benne).
   - array[]: az egész számokat tartalmazó tömb.
   Visszatérési érték: az elemek átlaga (lebegőpontos szám - float).
*/
float average_array(int size, int array[]) {
    // A számok összegének tárolására szolgáló változó.
    float sum = 0.0;  

    // Ciklus, amely végigmegy a tömb összes elemén.
    for (int i = 0; i < size; i++)  
    {
        // Az aktuális elem értékét hozzáadjuk az összeghez.
        sum += array[i];  
    }

    // Az összeg elosztása a tömb méretével, így kapjuk az átlagot.
    return sum / size;  
}

int main() {
    // Egy 10 elemű egész számokat tartalmazó tömb deklarálása és inicializálása.
    int array[10] = { 2, 9, 3, 1, 7, 6, 8, 0, 4, 5 };

    // A tömb méretének tárolása egy változóban.
    int size = 10; 

    // Az 'average_array' függvény meghívása az 'array' tömbbel, és az eredmény tárolása az 'avg' változóban.
    float avg = average_array(size, array);

    // Az átlag kiírása két tizedesjegy pontossággal.
    printf("Average of array: %.2f\n", avg);

    // A program sikeres befejezését jelzi.
    return 0;  
}
