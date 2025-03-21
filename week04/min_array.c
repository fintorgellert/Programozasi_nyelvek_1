#include <stdio.h>

// Függvény a tömb legkisebb elemének meghatározására
int min_array_element(int size, int array[]) {
    
    // Kezdetben a tömb első elemét tekintjük a legkisebbnek
    int min = array[0]; 

    // A tömb többi elemét végigjárjuk
    for (int i = 1; i < size; i++) 
    {
        
        // Ha találunk egy kisebb elemet, frissítjük a min értéket
        if (array[i] < min) 
            min = array[i];
    }

    // Visszatérünk a legkisebb elemmel
    return min; 
}

int main() {

    // Tömb deklarálása
    int array[10] = { 112, 95, 31, 14, 70, 64, 98, 12, 43, 55 };

    // Tömb mérete
    int size = 10; 

    // Függvény meghívása a legkisebb elem megtalálására
    int min = min_array_element(size, array); 

    // Kiírjuk az eredményt
    printf("Min element in array: %d\n", min); 

    return 0;
}
