/* Az #include direktíva a szükséges fejléceket importálja, ebben az esetben a <stdio.h> könyvtárat,
 * amely biztosítja a standard bemeneti és kimeneti függvényeket, például a printf függvényt. 
 */
#include <stdio.h>  

/* A program belépési pontja, ahol a végrehajtás elindul. */
int main() {  
    // 'a' egész típusú változó, értéke: 20
    int a = 20; 
    // 'b' egész típusú változó, értéke: 3
    int b = 3;   

    // Az 'a' és 'b' változók értékeinek kiírása
    printf("a = %d\n", a);
    printf("b = %d\n", b);


    // Egész osztás: mivel mindkét operandus (a és b) egész szám, az eredmény is egész szám lesz

    int result = a / b;

    // 20 / 3 eredménye egész számként: 6 (a maradék elvész)
    printf("a / b = %d\n", result);  


    // Lebegőpontos osztások különböző módokon

    // Mindkét szám lebegőpontos, így a pontos eredményt kapjuk
    printf("20.0 / 3.0 = %f\n", 20.0 / 3.0);  

    // A 20.0 lebegőpontos, a 3 egész, így a művelet lebegőpontos
    printf("20.0 / 3 = %f\n", 20.0 / 3);    

    // A 3.0 lebegőpontos, ezért a művelet lebegőpontos marad 
    printf("20 / 3.0 = %f\n", 20 / 3.0);     
    

    // Típuskonverzió (cast) használata az egész számokat lebegőpontossá alakítva

    // Mindkét változót átalakítjuk float típusra
    printf("(float) a / (float) b = %f\n", (float) a / (float) b); 

    // Csak 'a'-t alakítjuk float-tá, az eredmény lebegőpontos lesz
    printf("(float) a / b = %f\n", (float) a / b); 

    // Csak 'b'-t alakítjuk float-tá, az eredmény szintén lebegőpontos lesz
    printf("a / (float) b = %f\n", a / (float) b);  
    

    // A main függvény visszatérési értéke 0, amely a program sikeres befejezését jelzi.    
    return 0; 
}
