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
        // Számoljuk ki, hány szóközre van szükség az aktuális sor előtt, hogy középre kerüljön. 
        
        // A szóközök száma csökken a sorok számával.
        int spaces = n - i;  

        // A '#' karakterek száma nő a sorok számával. 
        int hashes = i;  

        // Belső ciklus, amely az aktuális sor előtt a megfelelő számú szóközt írja ki.
        for (int s = 0; s < spaces; ++s)
        {
            // Egyetlen szóköz kiírása.
            printf(" ");  
        }

        // Belső ciklus, amely az aktuális sorban a megfelelő számú '#' karaktert írja ki.
        for (int h = 0; h < hashes; ++h)
        {
            // Egy '#' karakter kiírása.
            putchar('#');  
        }

        // Új sor kiírása a következő sor megkezdéséhez.
        puts("");  
    }

    // A program sikeres befejezését jelzi.
    return 0;  
}
