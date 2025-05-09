/*
 * A felhasználótól számokat kérünk be egymás után, amíg az 0-t nem ír be.
 * A számokkal egy különleges szabályrendszer alapján számolunk:
 *   - Az első szám az eredmény kezdőértéke lesz.
 *   - Minden negatív számot kivonunk, de mivel -(-n), ez gyakorlatilag hozzáadás.
 *   - Ha a következő szám kisebb, mint az eddigi eredmény → osztás.
 *   - Ha nagyobb, mint az eddigi eredmény → szorzás.
 *   - Egyenlő esetén nem történik semmi.
 * A ciklus 0 esetén leáll, és kiírjuk az eredményt két tizedesjeggyel.
 */

#include <stdio.h>

/*
 * Függvény: get_double
 * ----------------------
 * Célja: A felhasználótól kér be egy lebegőpontos számot (double).
 * Bemenet: egy szöveg (prompt), amelyet a felhasználónak kiír a kérés előtt.
 * Kimenet: a felhasználó által beírt valós szám (double).
 */ 
double get_double(char* prompt) {
    double n;
    printf("%s", prompt);
    scanf("%lf", &n);       // %lf formátum a double típushoz
    return n;
}

int main() {
    // Jelzi, hogy az első számot olvassuk-e be. 
    // Ha igen, akkor azt egyszerűen beállítjuk kezdőértéknek.
    int first = 1;

    // Ez tárolja a folyamatosan frissülő eredményt, amit a bemeneti számokkal módosítunk.
    double result = 0;

    // Végtelen ciklus – a felhasználó akkor szakítja meg, ha 0-t ad meg
    while (1)
    {
        // Felhasználótól bekérünk egy számot
        double n = get_double("Szám: ");

        // Ha a szám 0 → kilépés a ciklusból (vége a számításnak)
        if (n == 0)
            break;

        // Ha ez az első szám, akkor beállítjuk az eredményt erre az értékre
        if (first) {
            result = n;
            first = 0;
            continue;
        }

        // A számítás logikája:
        // -----------------------
        // Ha a következő szám **negatív** → kivonás helyett kivonás mínusza (tehát: hozzáadjuk abszolút értékét)
        if (n < 0)
            result -= n;

        // Ha az aktuális eredmény **nagyobb** a következő számnál → osztunk vele
        else if (result > n)
            result /= n;

        // Ha az aktuális eredmény **kisebb** a következő számnál → szorzunk vele
        else if (result < n)
            result *= n;

        // Megjegyzés: ha az új szám egyenlő az eredménnyel, nem történik semmi
        // (semelyik feltétel sem igaz, nincs else ág)
    }

    // A végső eredmény kiírása a ciklus után
    printf("Eredmény: %.2lf\n", result);    

    return 0;
}
