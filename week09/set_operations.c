/*
 *  Halmazelméleti műveletek – Alapfogalmak és alkalmazás
 *  
 *  Ebben a programban két egész számokat tartalmazó halmazon végzünk alapvető
 *  halmazelméleti műveleteket: uniót és különbséget.
 *  
 *  Halmaz:
 *     Egy olyan matematikai struktúra, amely egyértelmű, nem ismétlődő elemekből áll.
 *  
 *  Unió (∪):
 *     Két halmaz uniója az a halmaz, amely tartalmaz minden olyan elemet,
 *     amely legalább az egyik halmazban benne van.
 *     Pl. A = {1, 2}, B = {2, 3} → A ∪ B = {1, 2, 3}
 *  
 *  Különbség (\):
 *     A \ B jelentése: az A halmaz azon elemei, amelyek **nem** szerepelnek a B halmazban.
 *     Pl. A = {1, 2, 3}, B = {2, 4} → A \ B = {1, 3}
 *  
 *  Fontos:
 *  - A halmazok reprezentációja tömbökön keresztül történik.
 *  - Az ismétlődések kiszűrése manuálisan történik, mert a tömb engedi az ismétlést.
 */

#include <stdio.h>

/*
 * Függvény: print_set
 * --------------------
 * Egy egész számokból álló halmaz elemeit írja ki vesszővel elválasztva.
 * Hasznos az unió és különbség eredményének megjelenítéséhez.
 */
void print_set(int n, int set[]) {
    for (int i = 0; i < n; ++i) {
        if (i != 0) {
            printf(", ");
        }
        printf("%d", set[i]);
    }
    puts(""); // Újsor a végén
}

/*
 * Függvény: unio
 * ---------------
 * Két halmaz unióját számítja ki (A ∪ B), vagyis minden olyan elemet, ami 
 * legalább az egyik halmazban szerepel, duplikáció nélkül.
 * 
 * Lépések:
 * 1. Az első halmaz minden elemét átmásoljuk az új tömbbe.
 * 2. A második halmaz minden eleméről ellenőrizzük, hogy nincs-e már az új tömbben.
 *    Ha nincs, akkor hozzáadjuk.
 */
void unio(int size_A, int A[], int size_B, int B[]) {
    // A ∪ B legrosszabb esetben az összes elemet tartalmazza
    int C[size_A + size_B]; 

    // Az aktuális elemszám a C tömbben
    int count = 0;          

    // Első halmaz elemeinek átvétele
    for (int i = 0; i < size_A; ++i) {
        C[count++] = A[i];
    }

    // Második halmaz elemeinek ellenőrzése
    for (int i = 0; i < size_B; ++i) {
        int flag = 1;

        // Megnézzük, benne van-e már az adott elem a C tömbben
        for (int j = 0; j < count; ++j) {
            if (C[j] == B[i]) {
                // Már benne van, nem kell újra felvenni
                flag = 0; 
                break;
            }
        }

        // Ha nem volt benne, hozzáadjuk
        if (flag) {
            C[count++] = B[i];
        }
    }

    // Eredmény kiírása
    print_set(count, C);
}

/*
 * Függvény: difference
 * -------------------
 * A \ B halmazkülönbséget számolja ki, azaz minden olyan elemet az A halmazból,
 * amely nem szerepel a B halmazban.
 * 
 * A difference(B, A) meghívásával kiszámolhatjuk a B \ A különbséget is.
 */
void difference(int size_A, int A[], int size_B, int B[]) {
    // Segédbool annak jelzésére, hogy kell-e vessző
    int first = 1; 

    for (int i = 0; i < size_A; ++i) {
        int flag = 1;

        // Itt minden A[i] elemet összevetünk a B összes elemével
        for (int j = 0; j < size_B; ++j) {
            if (A[i] == B[j]) {
                flag = 0;
                break;
            }
        }

        // Ha az elem nem volt benne B-ben, akkor kiírjuk
        if (flag) {
            if (!first) {
                printf(", ");
            }
            printf("%d", A[i]);
            first = 0;
        }
    }

    // Újsor a végén
    puts(""); 
}


int main() {
    // Halmaz A deklarálása
    int A[4] = { 3, 7, 8, 21 };
    int size_A = 4;

    // Halmaz B deklarálása
    int B[7] = { 3, 4, 5, 22, 54, 85, 100 };
    int size_B = 7;

    // Unió kiírása
    printf("A ∪ B = ");
    unio(size_A, A, size_B, B);

    // A \ B kiírása
    printf("A \\ B = ");
    difference(size_A, A, size_B, B);

    // B \ A kiírása
    printf("B \\ A = ");
    difference(size_B, B, size_A, A);

    return 0;
}
