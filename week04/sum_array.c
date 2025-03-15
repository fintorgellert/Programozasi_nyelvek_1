#include <stdio.h>

/* 
    Ez a függvény kiszámítja és visszaadja egy tömb összegét.

    Paraméterek:
        - size: a tömb mérete (hány elem található benne)
        - array[]: maga a tömb, amelynek az elemeit összeadjuk
*/
int sum_array(int size, int array[])
{
    // Inicializáljuk az összeg változót, kezdetben 0 értékkel
    int sum = 0;  

    // Végigmegyünk a tömb összes elemén
    for (int i = 0; i < size; ++i)
    {
        // Az aktuális elem értékét hozzáadjuk az összeghez
        sum += array[i];  
    }

    // Visszaadjuk az összegzett értéket
    return sum;
}

int main() 
{

    // Létrehozunk egy példatömböt 10 elemmel
    int array[10] = { 2, 9, 3, 1, 7, 6, 8, 0, 4, 5 };

    // A tömb mérete
    int size = 10;

    // Meghívjuk a sum_array függvényt, hogy kiszámoljuk a tömb összegét
    int sum = sum_array(size, array);

    // Kiírjuk a tömb összegét
    printf("Sum of array: %d\n", sum);

    // A program sikeresen lefutott
    return 0;  
}
