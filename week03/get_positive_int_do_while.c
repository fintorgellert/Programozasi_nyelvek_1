/* Az <stdio.h> könyvtár importálása, amely lehetővé teszi a 
 * szabványos bemeneti és kimeneti műveletek használatát, 
 * például a printf és scanf függvényeket. 
 */
#include <stdio.h>  

/* Egy függvény, amely bekér egy pozitív egész számot a felhasználótól.
 * A felhasználó mindaddig új számot kell megadjon, amíg nem pozitív.
 * Visszatérési érték: a beolvasott pozitív egész szám. 
 */
int get_positive_int()
{
    // Egy egész szám tárolására szolgáló változó.
    int number; 

    do
    {
        // Kérdés kiírása a felhasználónak.
        printf("n: ");

        // A felhasználótól kapott szám beolvasása.
        scanf("%d", &number);  

        // Ha a szám negatív, a program újra bekéri az értéket.
    } while(number < 0);  

    // Visszaadja a beolvasott pozitív számot. 
    return number;  
}

// A program belépési pontja.
int main()  
{
    // Meghívjuk a get_positive_int függvényt, és eltároljuk az eredményt n-ben.
    int n = get_positive_int(); 

    // Kiírjuk a beolvasott pozitív számot.
    printf("A szam: %d\n", n);  

    // A program sikeres befejezését jelzi. 
    return 0;  
}
