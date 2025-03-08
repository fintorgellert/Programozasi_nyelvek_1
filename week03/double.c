/* Az <stdio.h> könyvtár importálása, amely lehetővé teszi a 
 * szabványos bemeneti és kimeneti műveletek használatát, 
 * például a printf függvényt.
 */
#include <stdio.h>  

/* Egy függvény, amely megdupláz egy egész számot.
 * Paraméter: n - egy egész szám, amelyet meg szeretnénk duplázni.
 * Visszatérési érték: a paraméter kétszerese. 
 */
int duplaz(int n) 
{
    // Az n értékének megduplázása.
    return 2 * n;
}

// A program belépési pontja.
int main()  
{
    /* Meghívjuk a duplaz függvényt 2-es paraméterrel 
     * és eltároljuk az eredményt a result változóban. 
     */
    int result = duplaz(2);  

    // Kiírjuk az eredményt a konzolra.
    printf("2 * 2 = %d\n", result);  

    // A program sikeres befejezését jelzi.
    return 0;  
}
