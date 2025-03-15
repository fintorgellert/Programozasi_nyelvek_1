#include <stdio.h>

int main() {
    // Két egész szám inicializálása
    int a = 3;
    int b = 9;

    // Kiírjuk a változók kezdeti értékeit
    printf("%d, %d\n", a, b);
    
    
    // Cseréljük meg a két változó értékét

    // Elmentjük az 'a' értékét egy ideiglenes változóba (tmp)
    int tmp = a;  

    // Az 'a' változónak adjuk a 'b' értékét
    a = b;  

    // A 'b' változónak adjuk az ideiglenes 'tmp' változó értékét, tehát az eredeti 'a' értékét       
    b = tmp;       

    // Kiírjuk a változók új értékeit, miután a csere megtörtént
    printf("%d, %d\n", a, b);

    // A program sikeresen lefutott
    return 0; 
}
