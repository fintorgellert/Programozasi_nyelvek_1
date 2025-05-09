#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Egy sor maximális hossza karakterekben
#define MAX_LINE_LEN 100   


/*
 * Program célja:
 * -------------
 * • Egy parancssori argumentumban megadott szöveges fájlból beolvasni
 *   soronként egy-egy egész számot.
 * • Az így beolvasott számokat Quick Sort algoritmussal növekvő sorrendbe tenni.
 */


/* 
 * swap: két egész szám értékét felcseréli.
 *
 * Paraméterek:
 *   a, b – pointerek az elcserélendő elemekre.
 */
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


/* 
 * quicksort: in-place Quick Sort rendezés.
 *
 * Paraméterek:
 *   a     – rendezendő tömb
 *   left  – rendezés alsó indexe
 *   right – rendezés felső indexe
 * 
 * Működés:
 *   1) Pivotként a tömb középső elemét választjuk.
 *   2) Két indexet (i és j) mozgatunk a tömb két végén: 
 *      – addig lépnek befelé, amíg nem találnak a pivotnál rosszabb oldalon álló
 *      elemet.
 *   3) Ha i ≤ j, cseréljük az a[i] és a[j] értékét, majd léptetjük i-t és j-t.
 *   4) Rekurzív módon hívjuk magunkat a pivot előtti (bal..j) és utáni (i..jobb) részekre.
 */
void quicksort(int a[], int left, int right) {
    int i = left, j = right;

    // pivot: a középső elem
    int pivot = a[(left + right) / 2];

    // Partícionálás: i jobbra, j balra mozog
    while (i <= j) {
        // Balról keressük az első olyan elemet, ami ≥ pivot
        while (a[i] < pivot) {
            ++i;
        }

        // Jobbról keressük az első olyan elemet, ami ≤ pivot
        while (a[j] > pivot) {
            --j;
        }

        // Ha az i index még nem lépett át a j indexen (i ≤ j), akkor cseréljük az elemeket
        if (i <= j) {
            swap(&a[i], &a[j]);

            // tovább lépünk
            ++i;    
            --j;
        }
    }

    // Rekurzív hívások a két partrícióra
    if (left < j) {
        quicksort(a, left, j);
    }

    if (i < right) {
        quicksort(a, i, right);
    }
}


/*
 * count_file_lines: megszámolja egy megnyitott fájl sorait.
 *
 * Paraméterek:
 * file – FILE* mutató olvasásra megnyitott fájlhoz.
 * 
 * Visszatérési érték:
 * A fájl sorainak száma; a függvény bezárja a fájlt is.
 */
int count_file_lines(FILE *file) {
    char buffer[MAX_LINE_LEN];
    int lines = 0;

    // Minden sikeres sorolvasás növeli a számlálót
    while (fgets(buffer, MAX_LINE_LEN, file) != NULL) {
        lines++;
    }

    fclose(file);

    return lines;
}


/* 
 * load_integers_from_file: beolvassa a fájl sorait, egész számmá konvertálja,
 * és egy tömbbe helyezi.
 * 
 * Paraméterek:
 *   file – FILE* mutató az olvasandó fájlhoz.
 *   arr  – egész számokat tároló tömb.
 */
void load_integers_from_file(FILE *file, int arr[]) {
    char buffer[MAX_LINE_LEN];
    int idx = 0;

    // Soronként olvasunk
    while (fgets(buffer, MAX_LINE_LEN, file) != NULL) {
        // Újsor eltávolítása a végéről
        buffer[strcspn(buffer, "\n")] = '\0';

        // String -> int
        arr[idx++] = atoi(buffer);
    }

    fclose(file);
}

/*

 * print_array: egy egész szám tömböt ír ki soronként.
 *
 * Paraméterek:
 *   size – a tömb elemeinek száma.
 *   arr  – a kiírandó tömb.
 */
void print_array(int size, const int arr[]) {
    for (int i = 0; i < size; i++) {
        printf("%d\n", arr[i]);
    }
}

int main(int argc, char* argv[]) {
    // Argumentum ellenőrzés: pontosan egy fájlnév kell
    if (argc != 2) {
        fprintf(stderr, "Hiba! Add meg a bemeneti fájl nevét!\n");
        exit(2);
    }
    const char *filename = argv[1];

    // Fájl megnyitása sorok számolásához
    FILE *fp1 = fopen(filename, "r");

    if (!fp1) {
        fprintf(stderr, "Hiba! Nem sikerült megnyitni: %s\n", filename);
        exit(1);
    }

    int n = count_file_lines(fp1);

    // Dinamikus tömb foglalása
    int *numbers = malloc(n * sizeof(int));

    if (!numbers) {
        fprintf(stderr, "Hiba! Nem sikerült memóriát foglalni!\n");
        exit(3);
    }

    // Fájl újranyitása és beolvasás
    FILE *fp2 = fopen(filename, "r");
    load_integers_from_file(fp2, numbers);

    // Rendezés Quick Sort-tal
    quicksort(numbers, 0, n - 1);

    // Rendezett tömb kiírása
    print_array(n, numbers);

    // Memória felszabadítása
    free(numbers);

    return 0;
}
