#include <stdio.h>

/*
    Ez a függvény kiszámolja egy tömb összes elemének szorzatát.

    Paraméterek:
        - size: a tömb mérete (hány elem van benne)
        - array[]: maga a tömb, amelynek elemeit szorozzuk
*/ 
int product_array(int size, int array[]) {
    
    // A szorzás kezdő értéke 1 (mert a szorzásnál 1 a semleges elem)
    int product = 1; 

    // Végigmegyünk a tömb összes elemén
    for (int i = 0; i < size; i++)
    {
        /*
            Minden egyes elem szorzása a korábban számított eredménnyel
            Az aktuális elem hozzáadása a szorzathoz
        */ 
        product *= array[i]; 
    }

    // A végén visszaadjuk a szorzatot
    return product;
}

int main() {

    // Létrehozunk egy példatömböt 10 elemmel
    int array[10] = { 2, 9, 3, 1, 7, 6, 8, 12, 4, 5 };

    // A tömb mérete (hány elem van benne)
    int size = 10;

    // Meghívjuk a product_array függvényt, hogy kiszámoljuk a szorzatot
    int product = product_array(size, array);

    // Kiírjuk az eredményt (a tömb elemeinek szorzata)
    printf("Product of array: %d\n", product);

    // A program sikeresen lefutott
    return 0; 
}
