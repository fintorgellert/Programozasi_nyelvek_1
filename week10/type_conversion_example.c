#include <stdio.h>
#include <stdlib.h>  // atoi, atof, itoa
#include <string.h>  // strcpy

/*
 * C nyelven a típusok közötti konvertálásokat különböző függvényekkel végezhetjük el.
 * A leggyakoribb típusok közötti konvertálások:
 *  - String -> int
 *  - String -> double
 *  - Int -> String
 *  - Int tömb -> String tömb
 *  - double -> int
 */

int main() {
    // 1. String -> int konverzió
    // Az atoi() függvény az input string-et egész számmá alakítja.
    // Példa: "12345" -> 12345
    // Ha a string nem tartalmaz érvényes számot, akkor az eredmény 0 lesz.
    char str1[] = "12345";
    int num1 = atoi(str1);  // atoi() függvény átalakítja a string-et int típusra
    printf("String to int: \"%s\" -> %d\n", str1, num1);

    // 2. String -> double konverzió
    // Az atof() függvény az input string-et lebegőpontos számmá (double) alakítja.
    // Példa: "123.45" -> 123.45
    // Ha a string nem tartalmaz érvényes számot, akkor az eredmény 0.0 lesz.
    char str2[] = "123.45";
    double num2 = atof(str2);  // atof() függvény átalakítja a string-et double típusra
    printf("String to double: \"%s\" -> %.2f\n", str2, num2);

    // 3. int -> String konverzió
    // Az sprintf() függvény segítségével formázott stringet hozhatunk létre egy szám alapján.
    // A számot stringgé alakítjuk, miközben formázott kimenetet adunk meg.
    // Példa: 6789 -> "6789"
    int num3 = 6789;
    char str3[20];                  // Előre biztosítunk helyet a string számára
    sprintf(str3, "%d", num3);      // sprintf() függvénnyel a számot stringgé konvertáljuk
    printf("Int to string: %d -> \"%s\"\n", num3, str3);

    // 4. double -> int konverzió
    // Az explicit típuskonverzióval a double típusú számot int típusúvá alakítjuk.
    // Megjegyzés: A tizedesjegyek elvesznek, tehát a szám lefele kerekítődik.
    // Példa: 987.65 -> 987
    double num4 = 987.65;
    int num5 = (int) num4;  // A double típusú számot explicit int típusúvá alakítjuk
    printf("Double to int: %.2f -> %d\n", num4, num5);

    // 5. int tömb -> String tömb konverzió
    // Az int típusú tömb minden elemét stringgé alakítjuk sprintf() segítségével.
    // Az egyes elemek stringgé konvertálása után azokat egy string tömbben tároljuk.
    // Példa: [1, 2, 3, 4, 5] -> ["1", "2", "3", "4", "5"]
    int arr[] = {1, 2, 3, 4, 5};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    char str_arr[arr_size][10];  // String tömb létrehozása, ahol minden elemhez 10 karakter helyet biztosítunk

    // Átalakítjuk az int tömb elemeit string tömb elemeivé
    for (int i = 0; i < arr_size; i++) {
        sprintf(str_arr[i], "%d", arr[i]);  // Az int értékeket stringgé alakítjuk
        printf("Int array to String array: %d -> \"%s\"\n", arr[i], str_arr[i]);
    }

    // 6. String -> char tömb konverzió
    // A strcpy() függvénnyel másolhatunk egy string-et egy karaktertömbbe.
    // A char tömbbe kerül a string minden egyes karaktere.
    // Példa: "Hello, world!" -> 'H', 'e', 'l', 'l', 'o', ' ', 'w', ...
    char str4[] = "Hello, world!";
    char char_arr[50];  // Előre biztosítunk helyet a karaktertömb számára
    strcpy(char_arr, str4);  // strcpy() függvénnyel másoljuk a string-et a karaktertömbbe
    printf("String to char array: \"%s\" -> \"%s\"\n", str4, char_arr);

    // 7. char tömb -> String (pointer használatával)
    // A C nyelvben a stringek `char` tömbök, ezért a char tömbök automatikusan string típusúak,
    // ha pointerrel hivatkozunk rájuk.
    // Példa: "C Programming!" -> "C Programming!"
    char char_arr2[] = "C Programming!";
    char *str5 = char_arr2;  // Egy pointert rendelünk a char tömb elejéhez
    printf("Char array to String: \"%s\" -> \"%s\"\n", char_arr2, str5);

    return 0;
}
