/*
 * Feladat:
 * --------
 * Egy 7 elemű egész tömböt töltsünk fel véletlenszámokkal [0–9] zárt intervallumból (az első elem
 * nem lehet nulla), majd abból a tömbből képezzünk egy hétjegyű számot. A program:
 *   1) Kiírja a tömb elemeit
 *   2) Összefűzi a számjegyeket egy egész számmá
 *   3) Kiírja, hogy ez a szám palindróma-e (visszafelé olvasva ugyanaz)
 *   4) Kiszámolja és kiírja a szám mínusz egy értékét (ehhez írjon egy `int minus_one(const int n, const int digits[])` szignatúráju függvényt)
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
 #include <math.h>
 
 #define SIZE 7   // A tömb hossza (számjegyek száma)
 #define MAX  9   // A véletlen számjegyek felső határa (0..9)
 
/* 
 * Függvény: minus_one
 * -------------------
 * A tömbből képzett számot előállítja, majd kivon belőle 1-et.
 * 
 * Paraméterek:
 *   n        – a tömb hosszúsága (számjegyek száma)
 *   digits[] – a számjegyeket tartalmazó tömb
 * 
 * Visszatérési érték:
 *   Az összeállított szám mínusz egy.
 * 
 * Megjegyzés:
 *   A számjegyek súlyozását 10 hatványozásával adjuk meg.
  */
 int minus_one(const int n, const int digits[]) {
     int result = 0;
 
     // Minden számjegy helyiértéken történő összegzése
     for (int i = 0; i < n; ++i) 
     {
         // pow(10, n-i-1) adja a 10^(helyiérték)-et, pl. i=0 -> 10^6
         result += (int)pow(10.0, (double)n - i - 1) * digits[i];
     }
 
     // visszatérünk a képzett szám mínusz egy értékével
     return result - 1;
 }
 
 /* 
  * Függvény: is_palindrome
  * -----------------------
  * Ellenőrzi, hogy a tömb számjegyeiből képzett szám palindróma-e.
  * 
  * Paraméterek:
  *   n        – a tömb hosszúsága
  *   digits[] – a számjegyeket tartalmazó tömb
  * 
  * Visszatérési érték:
  *   1, ha palindróma; 0 egyébként.
  * 
  * Megközelítés:
  *   Elölről és hátulról párban hasonlítjuk össze az elemeket.
  */
 int is_palindrom(const int n, const int digits[]) {
     for (int i = 0; i < n / 2; ++i) {
         // ha az i-edik és a visszafelé i-edik számjegy különböznek, nem palindróma
         if (digits[i] != digits[n - 1 - i])
             return 0;
     }

     return 1;
 }
 
 int main() {
     // Inicializáljuk a véletlenszám-generátort az aktuális idővel
     srand(time(NULL));
 
     int numbers[SIZE];   // Számjegyek tömbje
     int rand_num;
 
     printf("Tömb elemei: ");

     // Véletlen számjegyek generálása és kiírása
     for (int i = 0; i < SIZE; ++i) {
         if (i == 0)
             // Az első számjegy nem lehet nulla, ezért 1..9 között választunk
             rand_num = 1 + rand() % MAX;
         else
             // A többi számjegy lehet 0..9
             rand_num = rand() % (MAX + 1);
 
         numbers[i] = rand_num;
         printf("%d ", rand_num);
     }
     
     // sortörés
     puts("");  
 
     // A tömbből képzett szám: eredmény + 1 (mert minus_one visszaad minus egy)
     int formed = minus_one(SIZE, numbers) + 1;
     printf("A tömb elemeiből alkotott szám: %d\n", formed);
 
     // Palindróma vizsgálat
     if (is_palindrom(SIZE, numbers))
         printf("A(z) %d palindrom.\n", formed);
     else
         printf("A(z) %d nem palindrom.\n", formed);
 
     // Mínusz egy érték
     int minus1 = minus_one(SIZE, numbers);
     printf("Mínusz egy: %d\n", minus1);
 
     return 0;  // Program sikeres befejezése
 }
 