#include <stdio.h>

/*
    Ez a függvény kiírja egy tömb összes elemét a képernyőre

    Paraméterek:
        - size: a tömb mérete (hány elem van benne)
        - array[]: maga a tömb, amelynek elemeit kiírjuk
*/ 
void print_array(int size, int array[]) {

    // Végigmegyünk a tömb összes elemén
    for (int i = 0; i < size; ++i) {

        // Kiírjuk az aktuális tömb elemet, vesszővel elválasztva
        printf("%d, ", array[i]);
    }

    // Új sort kezdünk a formázás érdekében
    puts("");
}


int main() {

    // Létrehozunk egy példatömböt 10 elemmel
    int array[10] = { 2, 9, 3, 1, 7, 6, 8, 0, 4, 5 };

    // A tömb mérete (hány elemből áll)
    int size = 10;

    // Meghívjuk a print_array függvényt, hogy kiírjuk a tömb elemeit
    print_array(size, array);

    // A program sikeresen lefutott
    return 0; 
}
