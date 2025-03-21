#include <stdio.h>

// Függvény a tömb legnagyobb elemének megtalálására
int max_array_element(int size, int array[]) {

    // Kezdetben a tömb első elemét tekintjük a legnagyobbnak
    int max = array[0]; 

    // A tömb többi elemét végigjárjuk
    for (int i = 1; i < size; i++) 
    {
        // Ha találunk egy nagyobb elemet, frissítjük a max értéket
        if (max < array[i]) 
            max = array[i];
    }

    // Visszatérünk a legnagyobb elemmel
    return max; 
}

int main() {
    
    // Tömb definiálása
    int array[10] = { 112, 95, 31, 14, 70, 64, 98, 12, 43, 55 }; 
    
    // Tömb mérete
    int size = 10; 

    // Meghívjuk a függvényt, hogy megtalálja a legnagyobb elemet
    int max = max_array_element(size, array); 

    // Eredmény kiiratása
    printf("Max element in array: %d\n", max);

    return 0;
}
