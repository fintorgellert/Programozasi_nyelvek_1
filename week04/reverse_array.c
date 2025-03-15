#include <stdio.h>

/* 
    Ez a függvény kiírja a tömb összes elemét
    
    Paraméterek:
        - size: a tömb mérete (hány elem található benne)
        - array[]: maga a tömb
*/
void print_array(int size, int array[]) {

    // Ciklus, amely végigmegy a tömb összes elemén és kiírja őket
    for (int i = 0; i < size; ++i) {

        // Kiírjuk az aktuális elem értékét
        printf("%d, ", array[i]);  
    }

    // Új sort kezdeményezünk a kiírás végén
    puts("");  
}


/*
    Ez a függvény megfordítja a tömb elemeit
    
    Paraméterek:
        - size: a tömb mérete (hány elem található benne)
        - array[]: maga a tömb, amelyet meg kell fordítani
*/
void reverse_array(int size, int array[]) {

    /*
        Ciklus, amely a tömb első felében halad, és felcseréli az elemeket
        az első és az utolsó, majd a második és a második utolsó, stb.
    */
    for (int i = 0; i < size / 2; i++) {

        // Az aktuális elem eltárolása egy ideiglenes változóban
        int tmp = array[i];  

        // Az aktuális elem helyére beírjuk a megfelelő utolsó elemet
        array[i] = array[size - 1 - i];  
        
        // Az utolsó elem helyére beírjuk az ideiglenes változó értékét
        array[size - 1 - i] = tmp;  
    }
}


int main() {

    // Létrehozunk egy példatömböt 10 elemmel
    int array[10] = { 2, 9, 3, 1, 7, 6, 8, 12, 4, 5 };

    // A tömb mérete
    int size = 10;

    // Kiírjuk a tömb elemeit a megfordítás előtt
    puts("Before reverse:");
    print_array(size, array);

    // Meghívjuk a reverse_array függvényt, hogy megfordítsuk a tömböt
    reverse_array(size, array);

    // Kiírjuk a tömb elemeit a megfordítás után
    puts("After reverse:");
    print_array(size, array);

    // A program sikeresen lefutott
    return 0;  
}
