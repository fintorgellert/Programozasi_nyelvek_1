#include <stdio.h>

/* 
   A 'contains' függvény ellenőrzi, hogy egy adott elem szerepel-e egy tömbben.
   Paraméterek:
   - element: az az érték, amit keresünk a tömbben.
   - size: a tömb mérete.
   - array[]: maga a tömb, amelyben keresünk.
   Visszatérési érték:
   - 1 (igaz), ha az elem megtalálható a tömbben.
   - 0 (hamis), ha az elem nincs a tömbben.
*/
char contains(int element, int size, int array[]) {
    // Végigmegyünk a tömb összes elemén.
    for (int i = 0; i < size; ++i)  
    {
        /*
          Ha a tömb aktuális eleme megegyezik a keresett elemmel,
          visszatérünk 1-gyel (igaz érték).
         */ 
        if (array[i] == element) 
            return 1;  
    }

    // Ha végigmentünk a tömbön, és nem találtuk meg, visszatérünk 0-val (hamis).
    return 0;  
}

int main() {
    // Egy 10 elemű egész számokat tartalmazó tömb inicializálása.
    int array[10] = { 112, 95, 31, 14, 70, 64, 98, 12, 43, 55 };

    // A tömb méretének tárolása egy változóban.
    int size = 10;  

    // Az első keresett elem.
    int element = 70;  

    // A második keresett elem.
    int element2 = 2;   

    // Meghívjuk a 'contains' függvényt a két különböző elemre.
    char result  = contains(element, size, array);
    char result2 = contains(element2, size, array);

    // Kiírjuk az eredményeket, ha a visszatérési érték 1, akkor "true", ha 0, akkor "false".
    printf("Contains %d in array? %s\n", element,  result ? "true" : "false");
    printf("Contains %d in array? %s\n", element2, result2 ? "true" : "false");

    // A program sikeres befejezése.
    return 0;  
}
