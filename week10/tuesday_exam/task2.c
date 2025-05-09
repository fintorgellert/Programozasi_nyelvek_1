/*
 * Ez a program megkeresi az összes olyan Mersenne-prímet, amely kisebb, mint 1 000 000.
 * Mersenne-prímek a következő alakú prímek: 2^p - 1, ahol p is prím.
 * 
 * A program lépései:
 *   1. Végigmegy p=2-től kezdődően.
 *   2. Minden p-re megnézi, hogy:
 *       - p prím-e?
 *       - ha igen, akkor kiszámítja a 2^p - 1 értéket (ez a Mersenne-szám)
 *       - ellenőrzi, hogy ez az érték is prím-e
 *   3. Ha mindkét feltétel teljesül, a Mersenne-prímeket kiírja, és összeadja.
 *   4. A keresést akkor fejezi be, ha a 2^p - 1 már meghaladja az 1 000 000-t.
 */

#include <stdio.h>
#include <math.h>

// Maximum érték, aminél nagyobb Mersenne-prímet már nem keresünk
#define MAX_LIMIT 1000000 

/*
 * ---------------------------------------------------------
 * Egyszerű prímszám-ellenőrző függvény
 * ---------------------------------------------------------
 * BEMENET: egy egész szám (num)
 * KIMENET: 1, ha num prím; 0, ha nem prím
 * MŰKÖDÉS:
 *     - 1 vagy annál kisebb szám nem lehet prím.
 *     - Ellenőrzi, hogy létezik-e olyan szám 2-től num/2-ig, amely osztója num-nak.
 *     - Ha igen → nem prím.
 *     - Ha nincs ilyen → prím.
 */
int is_prime(int num) {
    if (num <= 1)
        return 0; // 1 vagy annál kisebb szám nem lehet prím

    // Feltételezzük, hogy a szám prím, kivéve ha osztható más kisebb számokkal
    for (int i = 2; i <= num / 2; ++i) {
        if (num % i == 0)
            return 0; // találtunk osztót => nem prím
    }

    return 1; // nem találtunk osztót => prím
}


/*
 * ---------------------------------------------------------
 * Mersenne-prím vizsgálat
 * ---------------------------------------------------------
 * BEMENET: egy egész szám (p)
 * KIMENET: 1, ha p alapján képzett Mersenne-szám (2^p - 1) prím; különben 0
 * MŰKÖDÉS:
 *     - Először ellenőrzi, hogy p prím-e.
 *     - Ha nem → azonnal visszatér 0-val.
 *     - Ha igen → kiszámítja M_p = 2^p - 1.
 *     - Ha M_p > MAX_LIMIT → nem foglalkozunk vele, visszatér 0-val.
 *     - Ha nem haladja meg → megnézi, hogy M_p is prím-e.
 *     - Ha igen → valóban Mersenne-prím.
 */
int is_mersenne_prime(const int p) {
    if (!is_prime(p))
        return 0; // ha p nem prím, akkor M_p sem lehet az

    int mp = pow(2, p) - 1; // M_p = 2^p - 1

    if (mp > MAX_LIMIT)
        return 0; // ha már túl nagy, nem foglalkozunk vele

    return is_prime(mp); // ha mp is prím, akkor Mersenne-prím
}

int main() {
    int sum = 0; // összegző változó a megtalált Mersenne-prímekhez

    // p értékeit 2-től indítjuk, mert p=1 esetén 2^1-1 = 1 nem prím
    for (int p = 2; ; p++) {
        int mp = pow(2, p) - 1; // M_p = 2^p - 1

        // Ha meghaladjuk a felső határt, kilépünk
        if (mp > MAX_LIMIT)
            break; 

                // Ha p és 2^p - 1 is prím, akkor Mersenne-prím
        if (is_mersenne_prime(p)) {
            printf("Mersenne-prím: M_%d = %d\n", p, mp);    
            sum += mp;                                     
        }
    }

    // Összegzett Mersenne-prímek kiírása
    printf("Összeg: %d\n", sum); 

    return 0;
}
