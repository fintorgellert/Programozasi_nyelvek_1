#include <stdio.h>

int main()
{
    // A piramis magasságát tároló változó
    int magassag = 0; 

    // Bekérjük a felhasználótól a piramis magasságát
    printf("Magassag: ");
    scanf("%d", &magassag);

    // Külső ciklus: sorokat generál (1-től a megadott magasságig)
    for (int sor = 1; sor <= magassag; sor++)
    {
        // Az adott sorhoz szükséges szóközök száma
        int space = magassag - sor; 
        
        // Az adott sorhoz szükséges '#' karakterek száma
        int hashes = sor;           

        // Szóközök kiírása a bal oldali '#' karakterek előtt
        for (int oszlop = 1; oszlop <= space; oszlop++)
        {
            putchar(' ');
        }

        // Bal oldali '#' oszlop kiírása
        for (int k = 0; k < hashes; k++)
        {
            putchar('#');
        }

        // Középső rés: két szóköz
        puts("  ");

        // Jobb oldali '#' oszlop kiírása
        for (int h = 0; h < sor; h++)
        {
            putchar('#');
        }

        // Új sor
        puts("");
    }

    return 0;
}
