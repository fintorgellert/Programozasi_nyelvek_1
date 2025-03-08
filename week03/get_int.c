/* Az <stdio.h> könyvtár importálása, amely lehetővé teszi a 
 * szabványos bemeneti és kimeneti műveletek használatát, 
 * például a printf és scanf függvényeket. 
 */
#include <stdio.h>  

/* Egy függvény, amely bekér egy egész számot a felhasználótól.
 * Visszatérési érték: a beolvasott egész szám. 
 */
int get_int()
{
    // Egy egész szám tárolására szolgáló változó.
    int number;  

    // Kérdés kiírása a felhasználónak.
    printf("n: "); 

    // A felhasználótól kapott szám beolvasása.
    scanf("%d", &number);  

    // Visszaadja a beolvasott számot.
    return number;  
}

// A program belépési pontja.
int main()  
{
    // Meghívjuk a get_int függvényt, és eltároljuk a visszatérési értékét n-ben.
    int n = get_int();  

    // Kiírjuk a beolvasott számot.
    printf("A szam: %d\n", n);  

    // A program sikeres befejezését jelzi.
    return 0;  
}
