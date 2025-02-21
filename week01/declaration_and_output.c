/* Az #include direktíva a szükséges fejléceket importálja, ebben az esetben a <stdio.h> könyvtárat,
 * amely biztosítja a standard bemeneti és kimeneti funkciókat, mint például a printf függvényt. 
 */
#include <stdio.h>

// A program belépési pontja, a 'main' függvény, amely a C program végrehajtásának kezdete.
int main() {  

	// változók deklarálása

	/* A 'letter' változó egy karaktert tárol, amelyet az egyszerű karakterekre vonatkozó típus (char) deklarál. 
     * Itt az 'A' karaktert tároljuk. 
	 */
	char letter = 'A';  

	/* A 'number' változó egy egész számot tárol, és a típus az 'int', amely egész számokat képes kezelni.
     * Itt a 2025 értéket tároljuk.
	 */
	int number = 2025; 

	/* A 'pi' változó egy egyszeres pontosságú lebegőpontos számot tárol (float típus). 
     * Az 'f' suffix jelezni, hogy ez egy float típusú literál. 
	 */
	float pi = 3.141592f;  

	/* Az 'e' változó kétszeres pontosságú lebegőpontos számot tárol (double típus), 
     * amely nagyobb pontosságú számokat képes tárolni, mint a float típus. 
	 */
	double e = 2.718281828459045;  

	// változó értékeinek kiíratása

	/* A printf függvény segítségével kiírjuk a 'letter' változó értékét, amely egy karakter ('A'). 
	 * A '%c' formátum specifikátor a karakterek kiíratására szolgál. 
	 */
	printf("Karakter: %c\n", letter);  

	// A 'number' változó egy egész szám, amit a '%d' formátum specifikátorral írunk ki.
	printf("Egész szám: %d\n", number); 

	// A 'pi' változó értéke (lebegőpontos szám) kiírása a '%f' formátum specifikátorral történik.
	printf("Pi értéke: %f\n", pi);  

	/* A 'e' változó kétszeres pontosságú lebegőpontos szám, amit a '%lf' formátum specifikátorral írunk ki. 
     * A 'double' típushoz a '%lf' megfelelő, ami a kétszeres pontosságú számokat jeleníti meg. 
	 */
	printf("e szám értéke: %lf\n", e); 

	/* A fő függvény (main) visszatérési értéke 0, ami a program sikeres befejezését jelzi. 
     * Ez zárja le a program végrehajtását. 
	 */
	return 0;
}
