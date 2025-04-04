#include <stdio.h>

int main() {
    // Deklarálunk egy 10 elemű tömböt, amelynek minden eleme 0-ra van inicializálva.
    int array[10] = { 0 };  

    // A tömb méretét eltároljuk egy változóban.
    int size = 10;          

    /* 
     * A for ciklus végigiterál a tömb minden elemén.
     * Az 'i' index segítségével elérjük a tömb elemeit, és mindegyiket kiírjuk.
     */
    for (int i = 0; i < size; i++) {
        // Kiírjuk az aktuális tömb elemet, majd egy szóközt a rendezett megjelenítés érdekében.
        printf("%d ", array[i]);
    }

    // Új sort adunk a kimenet végére, hogy a következő kimenet új sorban jelenjen meg.
    puts("");  

    return 0;  // A program sikeresen lefutott, visszatérési érték 0.
}
