#include <stdio.h>

#define MAX 1000

/*
 * calculate_sum_recursive:
 * -------------------------
 * Ez a függvény rekurzívan számolja ki azokat a számokat 1-től n-1-ig, 
 * amelyek oszthatók 3-mal vagy 5-tel, és összeadja őket.
 *
 * Paraméterek:
 *   - current: az aktuális szám, amit vizsgálunk (kezdetben 1)
 *   - limit: a felső határ (a ciklus addig tart, amíg current < limit)
 *   - sum: az eddigi részösszeg (akkumulátor szerepű változó)
 *
 * Működés:
 *   A függvény minden egyes hívása vagy hozzáadja az aktuális számot az összeghez
 *   (ha osztható 3-mal vagy 5-tel), vagy nem. Ezután rekurzívan meghívja önmagát
 *   a következő számmal. Amikor eléri a határt, visszatér az összeggel.
 *
 * Rekurzió lényege:
 *   Minden függvényhívás "visszatér" az előző hívásba, és így adódnak össze
 *   az értékek végül.
 */
int calculate_sum_recursive(int current, int limit, int sum)
{
    // Báziseset: ha elértük vagy túlléptük a határt (pl. current == 1000), visszatérünk az összeggel
    if (current >= limit) {
        return sum;
    }

    // Ha az aktuális szám osztható 3-mal vagy 5-tel, hozzáadjuk az összeghez
    if (current % 3 == 0 || current % 5 == 0) {
        // Rekurzív hívás: vizsgáljuk a következő számot, az aktuálishoz hozzáadva a mostanit
        return calculate_sum_recursive(current + 1, limit, sum + current);
    } else {
        // Ha nem osztható, megyünk tovább, de az összeg változatlan marad
        return calculate_sum_recursive(current + 1, limit, sum);
    }
}

int main()
{
    // Meghívjuk a rekurzív összeadást 1-től 999-ig (MAX = 1000)
    int result = calculate_sum_recursive(1, MAX, 0);

    // Kiírjuk az eredményt
    printf("A 3-mal vagy 5-tel osztható számok összege 1 és %d között: %d\n", MAX - 1, result);

    return 0;
}