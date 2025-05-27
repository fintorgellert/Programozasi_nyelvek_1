#include <stdio.h>   // Szükséges a printf, puts stb. függvényekhez (kiírás)
#include <stdlib.h>  // Tartalmazza a rand(), srand(), malloc() stb. függvényeket

/*
 * Ez a függvény lebegőpontos (float típusú) véletlenszámot generál a [lo, hi] intervallumban.
 *
 * A működés lépései:
 * 1. A rand() függvény egész számot generál 0 és RAND_MAX között.
 * 2. A rand() értékét lebegőpontossá konvertáljuk (float) típussá, majd elosztjuk RAND_MAX-szal,
 *    így kapunk egy számot a [0.0, 1.0] intervallumban.
 * 3. Ezt az értéket felszorozzuk (hi - lo) tartománnyal, így a végeredmény egy [0, hi - lo] szám.
 * 4. Végül hozzáadjuk az alsó határt (lo), hogy megkapjuk a [lo, hi] közötti végső értéket.
 */
float drand_v1(float lo, float hi) 
{
    return lo + ((float)rand() / RAND_MAX) * (hi - lo);
}

/*
 * Ez a függvény szintén véletlenszerű lebegőpontos számot generál, 
 * de itt előbb egész számot generálunk a [lo, hi] intervallumban,
 * majd elosztjuk 100-zal, hogy két tizedesjegyet kapjunk.
 *
 * Példa: ha rand() % (hi - lo + 1) eredménye 123, akkor 123 / 100.0 = 1.23
 */
float drand_v2(int lo, int hi) 
{
    return (lo + (rand() % (hi - lo + 1))) / 100.0;
}

/*
 * Ez a verzió lehetővé teszi, hogy megadjuk a kívánt pontosságot (mantisa).
 * Például ha mantisa = 1000000, akkor a számok akár 6 tizedesjegy pontosságúak lehetnek.
 *
 * A működés:
 * 1. A lo és hi értékeket megszorozzuk a mantisával, így egész számokká válnak.
 * 2. Generálunk egy egész számot a [l, h] intervallumban.
 * 3. A végső értéket visszaalakítjuk float típussá a mantisával való osztással.
 */
float drand_v3(float lo, float hi, float mantisa)
{
    int l = lo * mantisa;
    int h = hi * mantisa;

    return (float)(l + (rand() % (h - l + 1))) / mantisa;
}

/*
 * Ez a függvény egy n×n méretű mátrixot tölt fel véletlenszerű értékekkel a [-2.0, 2.0] tartományból.
 *
 * A működés:
 * - Két egymásba ágyazott ciklus segítségével bejárjuk a mátrix minden sorát és oszlopát.
 * - Minden egyes mátrix elemhez meghívjuk a drand_v1 függvényt,
 *   így minden elem más-más véletlen értéket kap.
 */
void fill_matrix(const int n, float matrix[n][n]) 
{
    // Sorokon végigmegyünk
    for (int row = 0; row < n; ++row)          
    {
        // Minden oszlopon végigmegyünk a sorban
        for (int col = 0; col < n; ++col)      
        {
            // A mátrix [row][col] pozícióját feltöltjük egy véletlen számmal
            matrix[row][col] = drand_v1(-2.00, 2.00);
        }
    }
}

/*
 * Ez a függvény kiírja a teljes n×n mátrixot a képernyőre.
 *
 * A működés:
 * - Két egymásba ágyazott ciklus soronként bejárja a mátrixot.
 * - Minden elemet 1 tizedesjegy pontossággal írunk ki, tabulátorral elválasztva.
 */
void print_matrix(const int n, const float matrix[n][n]) 
{
    for (int row = 0; row < n; ++row) 
    {
        for (int col = 0; col < n; ++col)
        {
            // Minden elem kiírása formázva
            printf("%5.1f\t", matrix[row][col]);
        }

        // Sor vége → új sor kezdése
        puts(""); 
    }
}

/*
 * Ez a függvény csak a mátrix alsó háromszögét írja ki.
 * Az alsó háromszög olyan elemeket tartalmaz, amelyek sorindexe >= oszlopindex (beleértve az átlót is).
 *
 * Például egy 3x3-as mátrix esetén az alábbi elemek:
 * [0][0]
 * [1][0], [1][1]
 * [2][0], [2][1], [2][2]
 */
void print_lower_triangle(const int n, const float matrix[n][n]) 
{
    for (int row = 0; row < n; ++row) 
    {
        for (int col = 0; col < n; ++col)
        {
            // Csak akkor írjuk ki, ha az oszlopindex kisebb vagy egyenlő a sorindexszel
            if (col <= row)
                printf("%5.1lf\t", matrix[row][col]);
        }

        // Új sor
        puts(""); 
    }
}

/*
 * Ez a függvény kiszámítja az alsó háromszög elemeinek átlagát.
 *
 * A működés:
 * - Összeadjuk az alsó háromszög minden elemét (ha col <= row),
 * - Számoljuk, hány ilyen elem van (count),
 * - Az átlagot kiszámítjuk (sum / count) és visszaadjuk a `*avg` mutató segítségével.
 */
void lower_triangle_average(const int n, const float matrix[n][n], float *avg)
{
    float sum = 0;
    int count = 0;

    for (int row = 0; row < n; ++row) 
    {
        for (int col = 0; col < n; ++col)
        {
            // Csak az alsó háromszög elemeit vesszük figyelembe
            if (col <= row) {
                // Összegyűjtjük az értékeket
                sum += matrix[row][col];  

                // Megszámoljuk, hány ilyen van
                count++;                 
            }
        }
    }

    // Átlag érték kiszámítása, amit a hívó fél a `*avg` változón keresztül kap meg
    *avg = sum / count;
}

/*
 * A program belépési pontja, a főfüggvény.
 *
 * Itt történik:
 * - a véletlenszám-generátor inicializálása,
 * - mátrix létrehozása és feltöltése,
 * - mátrix teljes tartalmának kiírása,
 * - csak az alsó háromszög kiírása,
 * - alsó háromszög átlagának kiszámítása és kiírása.
 */
int main()
{
    // A rand() függvény inicializálása adott maggal, hogy mindig ugyanazokat a számokat kapjuk
    srand(2025);  

    // 5x5-ös mátrix létrehozása
    float matrix[5][5];  

    // Mátrix méretének változója
    int n = 5;           

    // Átlag értékének tárolására
    float avg = 0.0;     

    // Mátrix feltöltése véletlenszerű értékekkel
    fill_matrix(n, matrix);  

    // A teljes mátrix kiírása
    printf("A teljes mátrix:\n");
    print_matrix(n, matrix);

    // Sor elválasztás
    puts(""); 

    // Az alsó háromszög elemeinek kiírása
    printf("Az alsó háromszög elemei:\n");
    print_lower_triangle(n, matrix); 

    // Sor elválasztás
    puts(""); 

    // Átlag kiszámítása (pointerrel visszatérve)
    lower_triangle_average(n, matrix, &avg); 

    // Az eredmény kiírása magyar szöveggel
    printf("A számított alsó háromszög átlaga: %.2f\n", avg);

    return 0;  // Sikeres program befejezés
}
