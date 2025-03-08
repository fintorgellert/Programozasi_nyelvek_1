/* Az <stdio.h> könyvtár importálása, amely lehetővé teszi a 
 * szabványos bemeneti és kimeneti műveletek használatát, 
 * például a printf és scanf függvényeket. 
 */
#include <stdio.h>  

// A program belépési pontja.
int main()  
{
    // Egy egész szám változó, amely a felhasználó által megadott értéket tárolja.
    int n;  

    // Kérdés kiírása a felhasználónak.
    printf("n: ");  

    // A felhasználótól kapott szám beolvasása.
    scanf("%d", &n);  

    // Külső ciklus, amely n sorból álló piramist hoz létre.
    for (int i = 1; i <= n; ++i)  
    {
        // Belső ciklus, amely az adott sorhoz tartozó '#' karaktereket írja ki.
        for (int j = 0; j < i; ++j)
        {
            // Egyetlen '#' karakter kiírása.
            putchar('#');  
        }

        // Új sor kiírása a következő sor megkezdéséhez.
        puts("");  
    }

    // A program sikeres befejezését jelzi.
    return 0; 
}
