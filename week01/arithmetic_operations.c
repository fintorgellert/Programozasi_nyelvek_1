/* Itt kezdődik a program, az #include direktíva a szükséges könyvtárat importálja. 
 * A <stdio.h> könyvtár tartalmazza az alapvető bemeneti és kimeneti műveletekhez szükséges 
 * függvényeket, mint például a printf és scanf. 
 */
#include <stdio.h> 

/* A program belépési pontja, a fő függvény (main), amely minden C programban kötelező. 
 * Ez a függvény végzi el a kód tényleges futtatását. 
 */
int main() {  

	int x;  // Deklaráljuk az 'x' változót, amely az első számot fogja tárolni.
	int y;  // Deklaráljuk a 'y' változót, amely a második számot fogja tárolni.

    /* A printf függvény a képernyőre ír ki szöveget, 
     * jelen esetben arra kéri a felhasználót, hogy adja meg az első számot. 
     */
	printf("Adja meg az első számot! "); 

    /* A scanf függvény lehetővé teszi, hogy a felhasználó számot adjon meg a konzolon. 
     * Az "%d" formátum specifikátor az egész számok bevitelére vonatkozik, 
     * az '&x' az 'x' változó címét adja át, hogy a felhasználó által megadott értéket 
     * a változó tárolni tudja. 
     */
	scanf("%d", &x);  
	
	printf("Adja meg a második számot! ");  // Hasonlóan az előző sorhoz, csak most a második számot kérjük.
	scanf("%d", &y);                        // Az első szám beolvasása után a második szám beolvasása következik.

	// Itt kezdődnek a különböző aritmetikai műveletek, amelyeket az x és y változókon hajtunk végre 

	// Összeadás: az x és y változókat összeadjuk, és az eredményt tároljuk az 'addition' változóban.
	int addition = x + y;

	// Kivonás: az x-ből kivonjuk y-t, és az eredményt tároljuk a 'subtraction' változóban.         
	int subtraction = x - y;   

	// Szorzás: az x és y változót összeszorozzuk, és az eredményt tároljuk a 'multiplication' változóban.   
	int multiplication = x * y;  

	// Osztás: az x változót elosztjuk y-val, és az eredményt tároljuk a 'division' változóban. 
	int division = x / y;        

	// Moduló osztás: az x és y közötti osztás maradékát számoljuk ki, és tároljuk a 'modulo_division' változóban. 
	int modulo_division = x % y; 

    /* Ez egy új sorba kezdődő szöveg, amely jelzi, hogy a következő részen az aritmetikai műveletek 
     * eredményei lesznek kiírva. 
     */
	printf("Két számmal végzet aritmetikai műveletek:\n");  

	/* Az alábbi printf utasítások kiírják a műveletek eredményeit,
     * minden műveletnél a megfelelő formátumban jelenítve meg a két számot és az eredményt. 
     */
	printf("%d + %d = %d\n", x, y, addition);           // Kiírjuk az x és y számok összegét. 
	printf("%d - %d = %d\n", x, y, subtraction);        // Kiírjuk az x és y különbségét. 
	printf("%d * %d = %d\n", x, y, multiplication);     // Kiírjuk az x és y szorzatát. 
	printf("%d / %d = %d\n", x, y, division);           // Kiírjuk az x és y hányadosát. 
	printf("%d %% %d = %d\n", x, y, modulo_division);   // Kiírjuk az x és y közötti osztás maradékát. A '%%' karakterek azért szükségesek, mert a '%' karaktert a printf-nek escape-elni kell.

    /* A fő függvény (main) visszatérési értéke 0, amely jelezheti, hogy a program sikeresen lefutott. 
     * Ez a sor lezárja a programot. 
     */
	return 0; 
}
