/* Az <stdio.h> könyvtár importálása, amely biztosítja a szabványos 
 * bemeneti és kimeneti függvényeket, például a printf és puts függvényeket.
 */
#include <stdio.h>  

// A program belépési pontja, ahol a végrehajtás elkezdődik.
int main() {  

    /* Az első for ciklus célja, hogy megtalálja az első olyan számot az 1-10 intervallumban,
     * amely osztható 7-tel. 
     */
    for (int i = 1; i <= 10; i++) {  

        // Ha az i osztható 7-tel maradék nélkül (i % 7 == 0), akkor belépünk a blokkba.
        if (i % 7 == 0) {
            
            // Kiírjuk az első ilyen számot.
            printf("Az első 7-tel osztható szám: %d\n", i);  

            // A break utasítás kilépteti a ciklust, amint megtaláltuk az első osztható számot.
            break;  
        }
    }

    /* A második for ciklus végigmegy az 1-10 közötti számokon és kiírja őket, 
     * de kihagyja a 7-et a continue utasítással. 
     */
    for (int i = 1; i <= 10; i++) {  

        // Ha i értéke 7, akkor belépünk a blokkba.
        if (i == 7) {  

            /* A continue utasítás kihagyja a ciklus további részét 
             * és a következő iterációval folytatja a ciklust. 
             */
            continue;  
        }
        
        // Kiírjuk az aktuális i értékét, kivéve, ha az 7.
        printf("%d ", i);  
    }

    // Új sort írunk ki a jobb formázás érdekében.
    puts("");  

    // A program sikeres befejezését jelzi.
    return 0;  
}
