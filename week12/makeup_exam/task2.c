/* 
 * Feladat:
 *
 * Kérjünk be két halmazt a felhasználótól egész számok formájában (legfeljebb 20 eleműek lehetnek), 
 * ellenőrizzük, hogy valóban halmazokról van-e szó (vagyis nincsenek bennük ismétlődő elemek), 
 * ehhez írjunk egy `int is_set(const int size, const int set[])` szignatúrájú függvényt,
 * majd írjuk ki e két halmaz metszetét (azon elemeket, melyek mindkét halmazban szerepelnek), 
 * ezt a `void intersection(const int size_A, const int A[], const int size_B, const int B[])` 
 * szignaturájú eljárásba szervezzük ki.
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 20  // Maximális elemszám halmazonként

/* 
 * Függvény: is_set
 * ----------------
 * Ellenőrzi, hogy egy tömb valóban halmazt reprezentál-e, 
 * azaz minden eleme egyedi-e.
 *
 * Paraméterek:
 *   size – a tömb mérete
 *   set[] – az elemeket tartalmazó tömb
 *
 * Visszatérési érték:
 *   1 (true),  ha a tömb valódi halmaz
 *   0 (false), ha van benne duplikált érték
 */
int is_set(const int size, const int set[]) {
    if (size == 0)
        return 1;  // Üres halmaz is halmaz

    // Ideiglenes tároló az egyedi elemekhez
    int seen[size];  
    int count = 0;

    for (int i = 0; i < size; ++i) {
        // Ellenőrizzük, hogy az aktuális elem már szerepel-e
        for (int j = 0; j < count; ++j) {
            if (seen[j] == set[i])
                return 0;  // Duplikált, tehát nem halmaz
        }

        // Ha új elem, eltároljuk
        seen[count++] = set[i];
    }

    // Minden elem egyedi
    return 1;  
}

/* 
 * Függvény: get_int
 * ------------------
 * Bekér egy egész számot a felhasználótól.
 *
 * Paraméter:
 *   prompt – a kiírandó szöveg
 *
 * Visszatérési érték:
 *   A beolvasott egész szám
 */
int get_int(char* prompt) {
    int n;
    printf("%s", prompt);
    scanf("%d", &n);
    return n;
}

/* 
 * Függvény: intersection
 * -----------------------
 * Két halmaz (A és B) metszetét számolja ki, és kiírja.
 *
 * Paraméterek:
 *   size_A – A halmaz elemszáma
 *   A[]    – A halmaz elemei
 *   size_B – B halmaz elemszáma
 *   B[]    – B halmaz elemei
 */
void intersection(const int size_A, const int A[], const int size_B, const int B[]) {
    // A metszet elemeit tároló tömb
    int C[SIZE];  
    int count = 0;

    for (int i = 0; i < size_A; ++i) {
        for (int j = 0; j < size_B; ++j) {
            if (A[i] == B[j]) 
            {
                // Talált közös elem
                C[count++] = A[i];  

                // Duplikációt kizárhatjuk, mert bemenet halmaz
                break;  
            }
        }
    }

    printf("Metszet: ");

    if (count == 0) {
        printf("üres halmaz\n");
    } else {
        for (int i = 0; i < count; ++i) {
            printf("%d ", C[i]);
        }
        
        puts("");
    }
}

int main()
{
    // --- A halmaz beolvasása ---
    int size_A = get_int("A szamossaga (max 20): ");
    if (size_A < 0 || size_A > SIZE) {
        puts("Hiba: Érvénytelen elemszám!");
        return 1;
    }

    int A[size_A];
    for (int i = 0; i < size_A; ++i) {
        printf("A%d = ", i + 1);
        scanf("%d", &A[i]);
    }

    // --- Halmazság ellenőrzése ---
    if (!is_set(size_A, A)) {
        puts("Hiba: Az 'A' halmaz elemei nem egyediek!");
        exit(1);
    }

    // --- B halmaz beolvasása ---
    int size_B = get_int("B szamossaga (max 20): ");
    if (size_B < 0 || size_B > SIZE) {
        puts("Hiba: Érvénytelen elemszám!");
        return 1;
    }

    int B[size_B];
    for (int i = 0; i < size_B; ++i) {
        printf("B%d = ", i + 1);
        scanf("%d", &B[i]);
    }

    if (!is_set(size_B, B)) {
        puts("Hiba: A 'B' halmaz elemei nem egyediek!");
        exit(1);
    }

    // --- Metszet kiírása ---
    intersection(size_A, A, size_B, B);

    return 0;
}
