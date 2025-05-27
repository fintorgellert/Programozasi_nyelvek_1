#include <stdio.h>  // Szabványos bemenet/kimenet: printf, fopen stb.
#include <stdlib.h> // Memóriakezeléshez (malloc, realloc), kilépés (exit), konverziók (atoi)
#include <string.h> // Sztringek kezelésére (pl. strcpy, strtok)

// Egy sor beolvasásához elegendő karakterhossz (egy sor max ennyi karakterből állhat)
#define LINE_LENGTH 100

// A betöltendő rekordok tömbjének kezdeti mérete (majd bővítjük ha kell)
#define INITIAL_CAPACITY 1000

// Nap nevek maximális hossza, pl. "Wednesday" + null karakter
#define MAX_DAY_NAME_LEN 16

// Egy napi lépésszámot reprezentáló struktúra
typedef struct
{
    int week;                   // Hét száma (pl. 1, 2, 3, ...)
    char day[MAX_DAY_NAME_LEN]; // Nap neve (pl. Monday, Tuesday...)
    int steps;                  // Az adott napon megtett lépések száma
} WeekDaySteps;

// Azoknak a napoknak a tárolására szolgáló struktúra, amikor a lépésszám az adott héten az átlag alatt volt
typedef struct
{
    char day[MAX_DAY_NAME_LEN]; // Nap neve
    int steps;                  // Az adott napi lépésszám
} Below;

// Egy CSV fájlsor feldolgozása és átalakítása struktúrává
WeekDaySteps parse_record(char *line)
{
    // A sort pontosvessző alapján daraboljuk fel, és a mezőket konvertáljuk

    // Az első mező a hét száma, szövegből számmá konvertáljuk
    int week = atoi(strtok(line, ";"));

    // Második mező a nap neve
    char *day = strtok(NULL, ";");

    // Harmadik mező a lépésszám
    int steps = atoi(strtok(NULL, ";"));

    // Új struktúra létrehozása és feltöltése
    WeekDaySteps new_record;
    new_record.week = week;
    strcpy(new_record.day, day);
    new_record.steps = steps;

    return new_record;
}

// A fájl beolvasása, és a benne szereplő adatok tömbbe másolása
int load_data(const char *fname, WeekDaySteps **out_data)
{
    // Megpróbáljuk megnyitni a fájlt
    FILE *fp = fopen(fname, "r");

    // Ha nem sikerült, hibakódot adunk vissza
    if (!fp)
        return -1;

    // Memóriafoglalás a rekordok tömbjének
    WeekDaySteps *data = malloc(INITIAL_CAPACITY * sizeof(WeekDaySteps));

    // Ha a malloc hibát dob
    if (data == NULL)
    {
        fprintf(stderr, "Hiba: Nem sikerült memóriát foglalni.\n");
        fclose(fp);
        exit(1);
    }

    // Jelenlegi maximális kapacitás
    int capacity = INITIAL_CAPACITY;

    // Eddig beolvasott rekordok száma
    int count = 0;

    // Ide olvassuk be soronként a fájl tartalmát
    char line[LINE_LENGTH];

    // Fejléc átugrása (első sor nem tartalmaz adatokat)
    fgets(line, LINE_LENGTH, fp);

    // Soronként beolvassuk a fájlt
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        // Ha elértük a maximális kapacitást, újraméretezzük a tömböt
        if (count >= capacity)
        {
            capacity *= 2;
            WeekDaySteps *new_data = realloc(data, capacity * sizeof(WeekDaySteps));

            // realloc hibaellenőrzés
            if (new_data == NULL)
            {
                fprintf(stderr, "Hiba: Nem sikerült memóriát újrafoglalni.\n");

                // fontos, hogy a régi adatokat felszabadítsuk
                free(data);
                fclose(fp);
                exit(1);
            }

            // Sor feldolgozása és struktúra hozzáadása a tömbhöz
            data = new_data;
        }

        // A sort átalakítjuk struktúrává, majd eltároljuk
        data[count++] = parse_record(line);
    }

    // Fájl bezárása
    fclose(fp);

    // A dinamikusan foglalt tömb visszaadása a hívónak
    *out_data = data;

    // Beolvasott rekordok száma
    return count;
}

// Megkeresi, hogy hány hét szerepel az adatokban (a legnagyobb hét számát adja vissza)
int find_max_week(const WeekDaySteps *data, int count)
{
    int maxweek = 0;

    for (int i = 0; i < count; i++)
    {
        if (data[i].week > maxweek)
            maxweek = data[i].week;
    }

    return maxweek;
}

// Egy adott hétre összegzi a napi lépésszámokat, kiszámítja az átlagot,
// és eltárolja azokat a napokat, ahol a lépésszám az átlag alatt van
int collect_below(const WeekDaySteps *data, int count, int week, Below *below, int *out_sum, double *out_avg)
{
    int sum = 0, n = 0;

    // Összegyűjtjük az adott héthez tartozó napi lépésszámokat
    for (int i = 0; i < count; i++)
    {
        if (data[i].week == week)
        {
            sum += data[i].steps;
            n++;
        }
    }

    // Ha az adott héthez nincs adat
    if (n == 0)
        return 0; 

    // Heti összeg visszaadása
    *out_sum = sum;        
    
    // Heti átlag visszaadása
    *out_avg = (double)sum / n; 

    int number_of_below = 0;

    // Újra végigmegyünk, és eltároljuk azokat a napokat, ahol az érték átlag alatti
    for (int i = 0; i < count; i++)
    {
        if (data[i].week == week && data[i].steps < *out_avg)
        {
            strcpy(below[number_of_below].day, data[i].day);
            below[number_of_below].steps = data[i].steps;
            number_of_below++;
        }
    }

    // Átlag alatti napok száma
    return number_of_below; 
}

// Összehasonlító függvény, amit a qsort hív meg – csökkenő sorrendbe rendezi a lépésszámokat
int cmp_desc(const void *left, const void *right)
{
    const Below *below1 = (const Below *)left;
    const Below *below2 = (const Below *)right;

    return below2->steps - below1->steps;
}

// Egy hét eredményeinek kiírása: összeg, átlag, és az átlag alatti napok kilistázása
void print_week(int week, int sum, double avg, Below *below, int number_of_below)
{
    printf("--- Week %d ---\n", week);
    printf("Heti teljes lépésszám: %d lépés\n", sum);
    printf("Heti átlagos lépésszám: %.0f lépés\n", avg);

    if (number_of_below > 0)
    {
        printf("A következő napokon volt az átlag alatt a lépésszám:\n");

        // Átlag alatti napok rendezése csökkenő sorrendbe
        qsort(below, number_of_below, sizeof(Below), cmp_desc);

        // A rendezett napok kiírása
        for (int i = 0; i < number_of_below; i++)
        {
            printf("%-9s %5d lépés\n", below[i].day, below[i].steps);
        }
    }
    else
    {
        // Ha minden nap elérte vagy meghaladta az átlagot
        printf("Minden nap elérte vagy meghaladta az átlagot.\n");
    }

    printf("\n");
}

// A program belépési pontja
int main()
{
    // A beolvasandó CSV fájl elérési útvonala
    char *fname = "data/daily_steps.csv"; 

    // Mutató a rekordokat tartalmazó tömbre
    WeekDaySteps *data = NULL;           

    // Beolvassuk az adatokat a fájlból
    int count = load_data(fname, &data);

    // Ha a fájl nem volt megnyitható, hibaüzenetet írunk és kilépünk
    if (count < 0)
    { 
        perror("Hiba a fájl megnyitásakor!");
        exit(1);
    }

    // Megkeressük a legnagyobb hét számát
    int max_week = find_max_week(data, count);

    // Ideiglenes tömb az adott héten átlag alatti napokhoz (max. 7 nap lehet)
    Below below[7];

    // Végigmegyünk az összes héten 1-től a legnagyobbig
    for (int week = 1; week <= max_week; week++)
    {
        int sum;
        double avg;

        // Megkeressük az átlag alatti napokat, és összesítjük az adatokat
        int number_of_below = collect_below(data, count, week, below, &sum, &avg);

        // Ha volt ilyen nap, kiírjuk az eredményt
        if (number_of_below >= 0)
            print_week(week, sum, avg, below, number_of_below);
    }

    // Dinamikusan lefoglalt memória felszabadítása
    free(data);

    return 0; // Program vége
}
