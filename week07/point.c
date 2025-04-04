#include <stdio.h> 

/*
 * Típusdefiníció: Point
 * ----------------------
 * Ez a struktúra két egész számot tartalmaz, amely egy pont koordinátáit reprezentálja a síkon.
 *
 * Tagok:
 *   - x: A pont vízszintes (x) koordinátája.
 *   - y: A pont függőleges (y) koordinátája.
 */
typedef struct {
    int x;
    int y;
} Point;


int main()
{
    // Két Point típusú változó deklarálása és inicializálása.
    // Az 'a' pont koordinátái: x = 1, y = 2.
    Point a = { 1, 2 };
    // A 'b' pont koordinátái: x = 6, y = 5.
    Point b = { 6, 5 };

    // A pontok koordinátáinak kiírása a konzolra.
    // Az első printf az 'a' pontot írja ki a formátumban "A(x, y)".
    printf("A(%d, %d)\n", a.x, a.y);

    // A második printf az 'b' pontot írja ki a formátumban "B(x, y)".
    printf("B(%d, %d)\n", b.x, b.y);    

    return 0;  // A program sikeres befejeződését jelzi.
}
