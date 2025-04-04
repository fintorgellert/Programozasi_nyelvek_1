#include <stdio.h>
/*
 * Függvény: print_array
 * ----------------------
 * Egy egész számokat tartalmazó tömböt ír ki a konzolra.
 * 
 * Paraméterek:
 *  - n: A tömb mérete.
 *  - array[]: Az egész számokat tartalmazó tömb.
 * 
 * A tömb elemei egymás után kerülnek kiírásra, vesszővel elválasztva.
 */
void print_array(int n, int array[]) {
    for (int i = 0; i < n; ++i) {
        if (i != 0)
        {
            // Az első elem előtt nincs vessző
            printf(", ");  
        }
        
        // Az aktuális elem kiírása
        printf("%d", array[i]);  
    }

    // Új sor kiírása a végén
    puts("");  
}

int main() {
    int size, n;

    // A felhasználótól bekérjük, hogy hány számot szeretne megadni
    puts("Hány db számot szeretnél bevinni?");
    scanf("%d", &size);

    // A megadott számokat tároló tömb
    int numbers[size];  

    // A felhasználótól bekérjük a számokat és elmentjük őket a `numbers` tömbbe
    for (int i = 0; i < size; ++i) {
        printf("%d. szám: ", i + 1);
        scanf("%d", &n);

        // Az aktuális szám eltárolása
        numbers[i] = n;  
    }

    // Az abszolút értékeket tároló tömb
    int numbers_copy[size];  

    // Végigmegyünk a `numbers` tömb elemein, és kiszámítjuk az abszolút értéket
    for (int i = 0; i < size; ++i) {
        if (numbers[i] < 0) 
        {
            // Negatív szám esetén előjelet váltunk
            numbers_copy[i] = -1 * numbers[i];  
        } else 
        {
            // Pozitív szám esetén változatlan marad
            numbers_copy[i] = numbers[i];  
        }
    }

    // Kiírjuk az abszolút értékeket
    printf("A bevitt számok abszolútértékei: ");
    print_array(size, numbers_copy);

    // Kiírjuk az eredeti számokat
    printf("A megadott számok: ");
    print_array(size, numbers);

    return 0;  // A program sikeresen lefutott
}
