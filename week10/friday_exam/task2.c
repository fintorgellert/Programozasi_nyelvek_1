/*
 * Ez a program egy interaktív módon működő statisztikai elemző, 
 * amely a felhasználótól számokat kér be egészen addig, 
 * amíg a felhasználó "***" szöveget nem ír be.
 * 
 * A program a következő statisztikai adatokat számolja ki:
 *   - A legnagyobb szám (maximum),
 *   - A legkisebb szám (minimum),
 *   - Az összes szám átlaga.
 */

 #include <stdio.h>   
 #include <stdlib.h> 
 #include <string.h>  
 
 // Maximális hossz a szövegbeolvasáshoz
 #define SIZE 200    
 
 int main()
{
    // Változók deklarálása és inicializálása
    double n;             // aktuálisan beolvasott szám
    double min, max;      // a legkisebb és legnagyobb szám
    double sum;           // az összegzett érték (összes szám összege)
    double count = 0;     // a megadott számok száma
    double first = 1;     // logikai segédváltozó az első számhoz
    char text[SIZE];      // a felhasználótól kapott szöveg (pl. "42.5" vagy "***")

    while (1)
    {
        // Interaktív kérdés felhasználóhoz
        printf("Szám (vége: ***): ");
        fgets(text, SIZE, stdin);                   // beolvassuk a szöveget (max. SIZE karakterig)
        text[strlen(text) - 1] = '\0';              // eltávolítjuk a sortörés karaktert a végéről

        // Ha a beírt szöveg "***", akkor kilépünk a ciklusból
        if (strcmp("***", text) == 0)
            break;

        // A beolvasott szöveget átalakítjuk valós számmá (double típussá)
        n = atof(text);

        if (first) {
            first = 0;  // első szám már be lett állítva

            min = n;    // kezdőérték: ez lesz a legkisebb szám
            max = n;    // kezdőérték: ez lesz a legnagyobb szám
            sum = n;    // összeg kezdőértéke
            count++;    // számok számlálója
            continue;   // továbblépés a következő iterációra
        }

        // Ha az aktuális szám kisebb, mint a jelenlegi minimum, frissítjük
        if (min > n)
            min = n;
        
        // Ha az aktuális szám nagyobb, mint a jelenlegi maximum, frissítjük
        if (max < n)
            max = n;
        
        count++;       // növeljük a számok számát
        sum += n;      // hozzáadjuk az aktuális számot az összeghez
    }

    if (count > 0) {
        // Ha legalább egy számot megadtunk, kiírjuk az eredményeket
        printf("\nLegnagyobb érték: %.2lf\n", max);
        printf("Legkisebb érték: %.2lf\n", min);
        printf("Átlag: %.2lf\n", sum / count);
    } else {
        // Ha nem adtunk meg semmit (rögtön "***"), akkor üzenetet küldünk
        puts("Hello! Nem adtál meg egyetlen számot sem!");
    }

    return 0;  // program vége
}

