#include <stdio.h>      // A fájlkezeléshez és a kiíratáshoz szükséges függvényeket tartalmazza (pl. printf, fopen, fgets)
#include <stdlib.h>     // Általános segédfüggvények, mint a malloc, free, exit, atof, atoi stb.
#include <string.h>     // Sztring (karakterlánc) műveletekhez szükséges (pl. strtok, strcpy, strcmp)

/*
 * Program célja
 *
 * Ez a program egy CSV (pontosvesszővel tagolt) fájlból beolvassa a filmek adatait, 
 * majd csak azokat a filmeket tartja meg, amelyek legalább 500.000 szavazatot kaptak.
 *
 * A program:
 *   - beolvassa a fájlt soronként,
 *   - kinyeri belőle az IMDb értékelést, címet és szavazatszámot,
 *   - csak a népszerű filmeket tárolja (szavazatszám alapján),
 *   - rendezi őket cím szerint (visszafelé ABC sorrendben),
 *   - kiírja a címeket, valamint hogy hány film felelt meg a feltételnek.
 */

// Kezdeti méret a filmek listájának (ha betelik, bővítjük)
#define INITIAL_CAPACITY 100     

// Amennyivel bővítjük a tömböt, ha elfogyott a hely
#define REALLOC_MULTIPLIER 1.5  

// Egy beolvasott sor maximális hossza
#define BUFFER_SIZE 256  

// Csak azok a filmek kerülnek be a listába, amelyek szavazatszáma >= 500000
#define VOTE_THRESHOLD 500000   

/*
 * Film struktúra létrehozása
 * 
 * Ez a struktúra egyetlen film adatait tárolja:
 *   - imdbRating: az IMDb szerinti értékelés (tört szám)
 *   - title: a film címe (karakterlánc)
 *   - voteCount: szavazatok száma (egész szám)
 */
typedef struct {
    float imdbRating;
    char title[128];
    int voteCount;
} Movie;

/*
 * Összehasonlító függvény a qsort számára
 * 
 * A qsort függvény ezt fogja hívni, hogy eldöntse két elem sorrendjét.
 * Jelen esetben két film címét hasonlítjuk össze visszafelé ABC sorrendben.
 * (Pl. "Zorro" előrébb lesz, mint "Avatar")
 */
int compare_titles_desc(const void *a, const void *b) {
    Movie *movie1 = (Movie *)a;
    Movie *movie2 = (Movie *)b;

    return strcmp(movie2->title, movie1->title);
}

int main(void)
{
    /*
     * Fájl megnyitása olvasásra
     * 
     * A bemenetet a "movies.csv" nevű fájlból olvassuk.
     * Ha nem sikerül megnyitni (pl. nem létezik a fájl), hibaüzenetet írunk ki, és kilépünk.
     */
    FILE *file = fopen("data/movies.csv", "r");

    if (file == NULL) {
        fprintf(stderr, "Hiba a fájl megnyitása során!\n");
        exit(EXIT_FAILURE);
    }

    /*
     * Dinamikus tömb létrehozása a filmekhez
     * 
     * Mivel nem tudjuk előre, hány filmet fogunk beolvasni,
     * egy dinamikus (növekvő méretű) tömböt használunk.
     * Ez egy tömb a Movie típusú pointerekből (mivel malloc-ot fogunk használni minden filmhez külön).
     */
    Movie *movies = malloc(INITIAL_CAPACITY * sizeof(Movie));

    // Ha a malloc hibát dob
    if (movies == NULL)
    {
        fprintf(stderr, "Hiba: Nem sikerült memóriát foglalni.\n");
        fclose(file);
        exit(1);
    }

    // jelenlegi maximális kapacitás
    int capacity = INITIAL_CAPACITY;  

    // eddig eltárolt filmek száma
    int movieCount = 0;              

    // ideiglenes tároló egy-egy beolvasott sorhoz
    char lineBuffer[BUFFER_SIZE];     

    /*
     * Soronként beolvassuk a fájlt
     *
     * Minden sort feldolgozunk, majd kivesszük belőle az adatokat.
     */
    while (fgets(lineBuffer, BUFFER_SIZE, file) != NULL) {
        // Eltávolítjuk a sor végéről az esetleges újsor karaktert
        lineBuffer[strcspn(lineBuffer, "\n")] = '\0';

        /*
         * Adatok kinyerése a sorból
         *
         * A sor három részre van tagolva pontosvesszővel:
         *  1. IMDb értékelés (pl. 8.5)
         *  2. Cím (pl. "Inception")
         *  3. Szavazatok száma (pl. 2100000)
         */

        // szöveget lebegőpontos számmá alakít
        float imdbRating = atof(strtok(lineBuffer, ";"));     
        
        // második mező: cím
        char *title = strtok(NULL, ";");                      

        // harmadik mező: egész számmá alakítva
        int voteCount = atoi(strtok(NULL, ";"));              

        /*
         * Csak a népszerű filmeket tároljuk el
         *
         * Ha egy film szavazatszáma elérte az 500000-et, bekerül a listába.
         */
        if (voteCount >= VOTE_THRESHOLD) {
            // Ha a tömb betelt, újraméretezzük (REALLOC_MULTIPLIER-rel növelve)
            if (movieCount >= capacity) {
                capacity = capacity * REALLOC_MULTIPLIER;
                movies = realloc(movies, capacity * sizeof(Movie));

                // realloc hibaellenőrzés
                if (movies == NULL)
                {
                    fprintf(stderr, "Hiba: Nem sikerült memóriát újrafoglalni.\n");

                    // fontos, hogy a régi adatokat felszabadítsuk
                    free(movies);
                    fclose(file);
                    exit(1);
                }
            }

            // Új film létrehozása és kitöltése adatokkal
            Movie movie;
            movie.imdbRating = imdbRating;
            movie.voteCount = voteCount;

            // címet bemásoljuk a struktúrába
            strcpy(movie.title, title);  

            // Hozzáadjuk a film pointerét a listához
            movies[movieCount++] = movie;
        }
    }

    // Bezárjuk a fájlt, mert már nincs rá szükség
    fclose(file);

    /*
     * Filmek rendezése cím szerint csökkenő sorrendben (Z->A)
     * A rendezés qsort függvénnyel történik, ami gyorsrendezést valósít meg.
     */
    qsort(movies, movieCount, sizeof(Movie *), compare_titles_desc);

    /*
     * Kiírjuk a rendezett filmcímeket
     */
    for (int i = 0; i < movieCount; i++) {
        puts(movies[i].title);
    }

    // Kiírjuk a filmek számát, amelyek megfeleltek a szűrésnek
    printf("\nFilmek száma, amelyekre legalább %d szavazat érkezett: %d\n", VOTE_THRESHOLD, movieCount);

    // A films tömb maga is dinamikus volt
    free(movies);

    return EXIT_SUCCESS;
}
