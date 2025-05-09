// Version C: Rendezett, ismétlődések nélküli véletlen számlista generálása

/*
 * Ez a program egy megadott mennyiségű (N) véletlenszámot generál egy [lower, upper] intervallumból,
 * úgy, hogy minden szám csak egyszer fordulhat elő (egyedi számok). A generálás után a számokat
 * növekvő sorrendbe rendezzük és kiírjuk.
 * 
 * Főbb lépések:
 * 1. Bekérjük N (darabszám), alsó és felső határt.
 * 2. A generate_numbers_once() függvény addig generál egyedi véletlenszámokat,
 *    amíg el nem éri a kívánt darabszámot, vagy a tartomány kimerül.
 * 3. A sort_array() függvény rendezésre buborék­­rendezést alkalmaz.
 * 4. Kiírjuk az eredményt.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Eljárás: generate_numbers_once
 * --------------------------------
 * Egyedi véletlen számokat generál egy [lower,upper] zárt intervallumból,
 * amíg el nem éri a count darabszámot, vagy kiderül, hogy több egyedi számot
 * nem lehet előállítani (tartomány kimerülése esetén).
 *
 * Paraméterek:
 *   output[] – a tömb, amit feltöltünk az egyedi számokkal
 *   count    – hány egyedi számot szeretnénk generálni
 *   lower    – intervallum alsó határa (zárt)
 *   upper    – intervallum felső határa (zárt)
 *
 * Működés:
 *   - A while ciklus addig fut, amíg generated < count.
 *   - Minden iterációban előállítunk egy véletlenszámot candidate.
 *   - Ellenőrizzük, hogy a candidate már szerepel-e az output tömbben.
 *       - Ha nem szerepel, hozzáadjuk, és növeljük generated értékét.
 *   - Ha a tartomány mérete kevesebb, mint a kért count, kilépünk, mert nincs elég
 *     egyedi szám.
 */
void generate_numbers_once(int output[], int count, int lower, int upper) {
    int generated = 0;

    // Ha a tartomány mérete kisebb, mint a kért darabszám, nem lehet egyedi számokat generálni
    if (upper - lower + 1 < count) {
        return;
    }

    while (generated < count) {
        // Véletlenszám generálása a [lower, upper] intervallumból
        int candidate = rand() % (upper - lower + 1) + lower;

        // Ellenőrizzük, hogy candidate már szerepel-e az eddig generált szá­mok között
        int exists = 0;
        for (int i = 0; i < generated; i++) {
            if (output[i] == candidate) {
                exists = 1;
                break;
            }
        }

        // Ha még nem szerepelt, hozzáadjuk a tömbhöz
        if (!exists) {
            output[generated++] = candidate;
        }

        // A ciklus magától kilép, ha generated == count
    }
}

/*
 * Eljárás: sort_array
 * ---------------------
 * Buborék­rendezéssel (bubble sort) növekvő sorrendbe rendezi az array elemeit.
 *
 * Paraméterek:
 *   array[] – a rendezendő tömb
 *   size    – a tömb mérete
 *
 * Működés:
 *   Két beágyazott ciklust használ:
 *   - A külső pass ciklusok száma size-1
 *   - A belső ciklus végigmegy az eddig nem rendezett részen, és kicseréli a
 *     szomszédos elemeket, ha rossz sorrendben vannak.
 */
void sort_array(int array[], int size) {
    for (int pass = 0; pass < size - 1; pass++) {
        for (int i = 0; i < size - 1 - pass; i++) {
            if (array[i] > array[i + 1]) {

                // Csere (swap)
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
}

int main() {
    int N, lower, upper;

    // Véletlenszám-generátor inicializálása
    // Minden futáskot más véletlenszám generálása
    srand(time(NULL));

    // Felhasználói bemenet bekérése
    printf("Hány db random számot kérsz? ");
    scanf("%d", &N);
    printf("Alsó határ: ");
    scanf("%d", &lower);
    printf("Felső határ (zárt intervallum): ");
    scanf("%d", &upper);

    // Dinamikus tömb deklarálása a kért darabszámnak megfelelően
    int numbers[N];

    // Egyedi véletlen számok generálása
    generate_numbers_once(numbers, N, lower, upper);

    // Számok rendezése növekvő sorrendbe
    sort_array(numbers, N);

    // Eredmény kiírása
    printf("A generált számok: ");
    for (int i = 0; i < N; i++) {
        printf("%d", numbers[i]);
        if (i < N - 1) {
            printf(", ");
        }
    }
    printf("\n");

    return 0;
}
