#include <stdio.h>

/* 
   A 'find' függvény megkeresi az adott elemet a tömbben és visszaadja az indexét.
   Paraméterek:
   - element: a keresett szám.
   - size: a tömb mérete.
   - array[]: a tömb, amelyben keresünk.
   Visszatérési érték:
   - Ha az elem megtalálható, visszatérünk az indexével.
   - Ha az elem nincs a tömbben, visszatérünk -1-gyel.
*/
int find(int element, int size, int array[]) {
    // Végigmegyünk a tömb összes elemén.
    for (int i = 0; i < size; i++)  
    {
        /*
            Ha megtaláltuk az elemet,
            visszatérünk az indexével.
        */
        if (array[i] == element)
            return i; 
    }

    // Ha nem találtuk meg, visszatérünk -1-gyel.
    return -1;  
}

int main() {
    // Egy 10 elemű tömb inicializálása
    int array[10] = { 112, 95, 31, 14, 70, 64, 98, 12, 43, 55 };

    // A tömb mérete
    int size = 10;  

    // Az első keresett szám
    int element = 70;  

    // A második keresett szám
    int element2 = 2;   

    // Meghívjuk a 'find' függvényt a két különböző elemre
    int result  = find(element, size, array);
    int result2 = find(element2, size, array);

    // Kiírjuk az eredményeket
    if (result != -1)
        printf("%d is at position %d in the array.\n", element, result);
    else
        printf("%d is not in the array.\n", element);

    if (result2 != -1)
        printf("%d is at position %d in the array.\n", element2, result2);
    else
        printf("%d is not in the array.\n", element2);

    // A program sikeres befejezése.
    return 0;  
}
