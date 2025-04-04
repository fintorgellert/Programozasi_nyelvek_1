#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prog1.h"

// A merge függvény összefűzi két sztringet karakterenként.
void merge(string s1, string s2) {
    // Végigiterálunk a sztringek karakterein és kiírjuk őket párosával.
    for (int i = 0; s1[i] != '\0'; ++i) {
        // Az s1[i] és s2[i] karaktereket együtt írjuk ki.
        printf("%c%c", s1[i], s2[i]); 
    }

    // Új sort kezdünk a kiírás után.
    puts("");  
}

int main(int argc, string argv[]) {
    // Ellenőrizzük, hogy pontosan két sztringet adtak-e meg.
    if (argc != 3) {
        puts("Hiba! Adj meg pontosan két sztringet!");

        // Hiba esetén kilépünk.
        exit(1);  
    }

    // Az első sztring a parancssori argumentumokból.
    string s1 = argv[1];  

    // A második sztring a parancssori argumentumokból.
    string s2 = argv[2];  

    // Ellenőrizzük, hogy a két sztring azonos hosszúságú-e.
    if (strlen(s1) != strlen(s2)) {
        puts("Hiba! A két sztring legyen azonos hosszúságú!");

        // Hiba esetén kilépünk.
        exit(2);  
    }

    // Meghívjuk a merge függvényt, hogy a két sztringet összefűzzük és kiírjuk.
    merge(s1, s2);
    
    return 0;  // A program sikeresen befejeződik.
}
