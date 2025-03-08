/* Az <stdio.h> könyvtár importálása, amely lehetővé teszi a 
 * szabványos bemeneti és kimeneti műveletek használatát, 
 * például a printf függvényt. 
 */
#include <stdio.h> 

/* A <math.h> könyvtár importálása, amely matematikai műveleteket 
 * biztosít, például a M_PI konstans használatát a π értékéhez. 
 */
#include <math.h>   

/* A kör területét kiszámító függvény.
 * Paraméter: r - a kör sugara (egész szám).
 * Visszatérési érték: a kör területe (lebegőpontos szám). 
 */
double area(int r)
{
    // A kör területének képlete: r^2 * π
    return r * r * M_PI;  
}

/* A kör kerületét kiszámító függvény.
 * Paraméter: r - a kör sugara (egész szám).
 * Visszatérési érték: a kör kerülete (lebegőpontos szám).
 */
double circumference(int r)
{
    // A kör kerületének képlete: 2 * r * π
    return 2 * r * M_PI;  
}

// A program belépési pontja.
int main()  
{
    /* Kiírjuk a kör kerületét, ahol a sugár 4.
     * %.2f azt jelenti, hogy az eredményt két tizedesjegyre kerekítve jelenítjük meg. 
     */
    printf("Kor kerulete: %.2f\n", circumference(4));

    // Kiírjuk a kör területét, ahol a sugár 4. 
    printf("Kor terulete: %.2f\n", area(4));

    // A program sikeres befejezését jelzi.
    return 0;  
}
