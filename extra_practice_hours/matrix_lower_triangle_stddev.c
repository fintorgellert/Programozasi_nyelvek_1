#include <stdio.h>   // A printf, puts függvényekhez szükséges (kiíráshoz)
#include <stdlib.h>  // A rand(), srand() függvényekhez
#include <math.h>    // sqrt() függvény a négyzetgyök számításhoz

/*
 * drand: Lebegőpontos véletlenszám generálása egy adott [lo, hi] intervallumban.
 *
 * A működés:
 * - rand() egész számot ad vissza 0 és RAND_MAX között.
 * - Ezt lebegőpontossá konvertálva és felszorozva az intervallum hosszával (hi - lo),
 *   majd hozzáadva az alsó határt (lo), megkapjuk a kívánt tartományba eső értéket.
 */
double drand(double lo, double hi)
{
    return lo + ((double)rand() / RAND_MAX) * (hi - lo);
}

/*
 * fill_matrix: n x n méretű mátrix véletlen számokkal való feltöltése.
 *
 * A véletlenszámok tartománya: [1.0, 5.0]
 * A ciklusok bejárják a mátrix minden sorát és oszlopát.
 */
void fill_matrix(const int n, double matrix[n][n])
{
    for (int row = 0; row < n; ++row)
    {
        for (int column = 0; column < n; ++column)
        {
            // minden elem véletlen szám
            matrix[row][column] = drand(1.0, 5.0);
        }
    }
}

/*
 * print_matrix: A teljes mátrix képernyőre írása 2 tizedesjegy pontossággal.
 *
 * Minden elem után tabulátor karakter, minden sor után új sor.
 */
void print_matrix(const int n, const double matrix[n][n])
{
    for (int row = 0; row < n; ++row)
    {
        for (int column = 0; column < n; ++column)
        {
            printf("%.2f\t", matrix[row][column]);
        }

        puts("");
    }
}

/*
 * print_lower_triangle: A főátló alatti mátrixrész kiírása.
 *
 * Csak azokat az elemeket írja ki, ahol a sorindex nagyobb, mint az oszlopindex.
 * Ez az ún. "alsó háromszög főátló alatti része", pl. [1][0], [2][0], [2][1], stb.
 */
void print_lower_triangle(const int n, const double matrix[n][n])
{
    for (int row = 0; row < n; ++row)
    {
        for (int column = 0; column < n; ++column)
        {
            // főátló alatti pozíció
            if (row > column) 
                printf("%.2f\t", matrix[row][column]);
        }

        puts("");
    }
}

/*
 * average_lower_triangle: A főátló alatti elemek átlaga.
 *
 * - Összegzi a főátló alatti elemeket (row > column),
 * - Megszámolja őket,
 * - Visszaadja az átlagot a `*avg` mutató segítségével.
 */
void average_lower_triangle(const int n, const double matrix[n][n], double *avg)
{
    double sum = 0;
    int count = 0;

    for (int row = 0; row < n; ++row)
    {
        for (int column = 0; column < n; ++column)
        {
            if (row > column)
            {
                sum += matrix[row][column];
                count++;
            }
        }
    }
    
    // átlag kiszámítása
    *avg = sum / count; 
}

/*
 * lower_triangle_s: A főátló alatti elemek szórásának (standard deviation) számítása.
 *
 * Működés:
 * 1. Először kiszámítja az átlagot a `average_lower_triangle` függvény segítségével.
 * 2. Ezután minden főátló alatti elemre kiszámolja a négyzetes eltérést az átlagtól.
 * 3. Az eltérések négyzetösszegéből és elemszámból kiszámítja a szórást:
 *    szórás = √(Σ(xi - átlag)² / (n - 1))
 */
void lower_triangle_s(const int n, const double matrix[n][n], double *s)
{
    double avg = 0.0;

    // Átlag meghívása
    average_lower_triangle(n, matrix, &avg);

    double sum = 0;
    int count = 0;

    for (int row = 0; row < n; ++row)
    {
        for (int column = 0; column < n; ++column)
        {
            if (row > column)
            {
                // eltérés az átlagtól
                double diff = matrix[row][column] - avg; 

                // eltérés négyzete hozzáadva
                sum += diff * diff;                     
                count++;
            }
        }
    }

    // A klasszikus szórás képlete alapján
    *s = sqrt((1.0 / (count - 1)) * sum);
}

/*
 * A program főfüggvénye: itt történik a vezérlés.
 *
 * - Inicializálja a véletlenszám-generátort
 * - Létrehozza és feltölti a mátrixot
 * - Kiírja a teljes mátrixot
 * - Kiírja a főátló alatti elemeket
 * - Kiszámolja és kiírja a főátló alatti elemek átlagát és szórását
 */
int main()
{
    // Véletlenszám-generátor inicializálása rögzített maggal (ismételhető értékek)
    srand(2025);  

    // 4x4-es mátrix deklarálása
    double matrix[4][4];  

    // Mátrix mérete
    int n = 4;   
    
    // Szórás tárolására szolgáló változó
    double s = 0.0;              

    // Mátrix feltöltése véletlen számokkal
    fill_matrix(n, matrix); 

    puts("\nRandom lebegőpontos értékekkel feltöltött mártsix:\n");

    // Teljes mátrix kiírása
    print_matrix(n, matrix); 

    puts("\n\nA főátló alatti elemek:");

    // Csak főátló alatti elemek kiírása
    print_lower_triangle(n, matrix);

    // Szórás kiszámítása
    lower_triangle_s(n, matrix, &s); 

    // Szórás értékének kiírása
    printf("A főátló alatti elemek szórása: %.2f\n", s);

    return 0; // Program vége
}
