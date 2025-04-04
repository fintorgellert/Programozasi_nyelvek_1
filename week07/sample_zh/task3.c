#include <stdio.h>

#define MAX 4000000  // A legnagyobb szám, ameddig a program számol (4 millió).

int main() {
    /*
     * A Fibonacci számok összegének tárolására szolgáló változó. 
     * Kezdetben 1, mivel az első szám (1) is hozzáadódik.
     */
    int sum = 1; 

    // Az első két Fibonacci szám: i = 1 és j = 2.
    int i = 1, j = 2;  

    /*
     * Végtelen ciklus, amely a Fibonacci sorozatot generálja, 
     * és az összeget csak a páratlan számokkal növeli.
     * A ciklus addig fut, amíg j kisebb, mint MAX (4 millió).
     */ 
    while (j < MAX)  
    {
        /*
         * A Fibonacci sorozat következő számának kiszámítása: 
         * j = j + i, majd i a régi j értékét veszi fel.
         */ 
        j += i;
        i = j - i;

        // Ha a j Fibonacci szám páratlan, hozzáadjuk az összeghez.
        if (j % 2 == 1)
            sum += j;
    }

    // Az összeg kiírása, ami a Fibonacci sorozat páratlan számainak összege.
    printf("%d\n", sum);

    return 0;  // A program sikeresen befejeződik.
}