#include <stdio.h>
#include <string.h>

/*
 * Eljárás: split_and_print
 * -------------------------
 * Egy bemeneti karakterláncot feloszt a megadott elválasztók mentén,
 * és minden egyes token-t (szót) külön sorban kiír.
 *
 * Paraméterek:
 *   input      – a szó feldolgozandó karaktertömb (módosulhat a strtok miatt!)
 *   delimiters – a karakterek halmaza, amelyek mentén felosztjuk a stringet
 *
 * Működés:
 * 1) strtok() első hívása: megkapja az input stringet és az elválasztókat,
 *    visszaadja az első token kezdetét.
 * 2) Míg a token nem NULL:
 *      a) puts()-szal kiírjuk a token tartalmát (egy sortöréssel zárva).
 *      b) strtok(NULL, delimiters) – folytatjuk a felosztást az előző helyről.
 * 3) strtok belsőleg módosítja az eredeti inputot: az elválasztó karaktereket '\0'-ra cseréli.
 */

/* Felosztja a 'line' változót a ",;" karakterek mentén, és kiírja az eredményt */
void split_and_print(char *line, const char *delimiters) {
    // első token lekérése
    char *token = strtok(line, delimiters);

    while (token != NULL) { 
        // token kiírása új sorban
        puts(token);     
                            
        // következő token
        token = strtok(NULL, delimiters);     
    }
}

int main() {
    /* 
     * Példa bemenet: 
     * "aa,;bb,,,;;;cc;,d"
     * Elválasztók: ',' és ';'
     */
    char line[] = "aa,;bb,,,;;;cc;,d";
    const char *delimiters = ",;";

    // A split_and_print függvény meghívása a bemutató stringgel és elválasztókkal
    split_and_print(line, delimiters);

    return 0;  // sikeres befejezés
}
