/* Az #include direktíva a szükséges fejléceket importálja, ebben az esetben a <stdio.h> könyvtárat,
 * amely biztosítja a standard bemeneti és kimeneti funkciókat, mint például a printf, scanf és puts függvényeket. 
 */
#include <stdio.h>  

// A program belépési pontja, a 'main' függvény, amely a program végrehajtását kezdi el.
int main() {  
    
    // Az i változó egy számláló, amelyet mindhárom ciklusnál használunk a számok kezelésére.
    int i = 0;

    // A puts függvény segítségével kiírjuk, hogy a következő ciklus egy 'while' ciklus lesz. 
    puts("while ciklussal:"); 
    
    // A while ciklus, amely akkor hajtódik végre, amíg az 'i' változó kisebb, mint 5.
    while (i < 5) {  
        // A puts kiírja, hogy "Anna" a képernyőre.
        puts("Anna");  
        // Az i változó értékét növeljük minden egyes ciklus után, hogy a ciklus végreérjen. 
        i++;            
    }
    
    // Egy üres sort írunk ki a két ciklus között, hogy elkülönítsük őket.
    puts(""); 
    
    // A for ciklus kiírása a következő ciklus előtt.
    puts("for ciklussal:");  
    
    // A for ciklus, amely 5 alkalommal fut le, és minden alkalommal kiírja az "Anna" szót.
    for (i = 0; i < 5; i++) {  
        // Az "Anna" szót írjuk ki minden egyes iterációban.
        puts("Anna");  
    }
    
    // Egy újabb üres sort írunk ki a két ciklus között.
    puts("");  
    
    // Az n változó a felhasználó által megadott számot tárolja, hogy hány alkalommal írjuk ki az "Anna" szót.
    int n;  
    
    // A printf segítségével arra kérjük a felhasználót, hogy adjon meg egy számot.
    printf("Kérem adjon meg egy egész számot! ");  

    // A scanf segítségével beolvassuk a felhasználó által megadott számot, és tároljuk az 'n' változóban. 
    scanf("%d", &n);  
    
    // A felhasználónak megadott szám szerint kiírjuk, hány alkalommal jelenjen meg az "Anna" szó. 
    printf("Név bekért számú (%d darab) alkalommal való kiiratása:\n", n);  
    
    // A for ciklus, amely 'n' alkalommal fut le, és minden egyes alkalommal kiírja az "Anna" szót.
    for (i = 0; i < n; i++) {  
        // Az "Anna" szót írjuk ki a képernyőre minden egyes iterációban
        puts("Anna"); 
    }
    
    /* A main függvény visszatérési értéke 0, amely a program sikeres befejezését jelzi. 
     * Ez zárja le a program futtatását. 
     */
    return 0;  
}
