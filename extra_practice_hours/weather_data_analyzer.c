#include <stdio.h>  // fájlkezeléshez, printf, fprintf stb.
#include <stdlib.h> // malloc, realloc, atof, exit
#include <string.h> // szövegkezeléshez: strtok, strcpy stb.

// Egy sor maximum ennyi karakter lehet
#define LINE_LENGTH 100

// A struktúratömb kezdeti mérete
#define INITIAL_CAPACITY 1000

// Egy mérési rekordot reprezentáló struktúra.
// Egy naphoz három hőmérsékletmérés (reggel, dél, este) és ezek átlaga tartozik.
typedef struct
{
    char date[11];  // Dátum "YYYY-MM-DD" formátumban (10 karakter + null terminátor)
    double morning; // Reggeli hőmérséklet
    double noon;    // Déli hőmérséklet
    double evening; // Esti hőmérséklet
    double average; // A három mérés átlaga
} Measurement;

// Átlaghőmérséklet kiszámítása három mérésből
double calc_avg(double a, double b, double c)
{
    return (a + b + c) / 3.0;
}

// Egy CSV fájlból származó sor feldolgozása és Measurement struktúrává alakítása
Measurement parse_record(char *line)
{
    // Lokális változó, ami majd visszatér
    Measurement m;

    // A strtok() feldarabolja a sort a megadott elválasztó karakter mentén (itt: ';')

    // Első token = dátum
    char *tok = strtok(line, ";");

    // Átmásoljuk a dátumot a struktúrába
    strcpy(m.date, tok);

    // Következő token = reggeli mérés
    tok = strtok(NULL, ";");

    // Szövegből lebegőpontos számot csinálunk
    m.morning = atof(tok);

    // Következő token = déli mérés
    tok = strtok(NULL, ";");
    m.noon = atof(tok);

    // Következő token = esti mérés
    tok = strtok(NULL, ";");
    m.evening = atof(tok);

    // Átlag számítása
    m.average = calc_avg(m.morning, m.noon, m.evening);

    // A kitöltött struktúra visszaadása
    return m;
}


// Fájl beolvasása, és a rekordok tömbbe mentése dinamikusan
int load_measurements(const char *fname, Measurement **out_data)
{
    // Fájl megnyitása olvasásra
    FILE *fp = fopen(fname, "r"); 

    // Ha nem sikerült megnyitni a fájlt
    if (!fp)
        return -1;

    // Memóriafoglalás a rekordok tömbjének
    Measurement *data = malloc(INITIAL_CAPACITY * sizeof(Measurement));

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

    // Fejléc átugrása (pl. "Dátum;Reggel;Dél;Este")
    fgets(line, sizeof(line), fp);

    // Soronként beolvassuk a fájlt
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        // Ha elértük a maximális kapacitást, újraméretezzük a tömböt
        if (count >= capacity)
        {
            capacity *= 2;
            Measurement *new_data = realloc(data, capacity * sizeof(Measurement));

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

    // Ennyi rekordot olvastunk be
    return count;
}

// Két Measurement rekord összehasonlítása átlag szerint (csökkenő sorrend)
// Ezt használja majd a qsort rendezéshez
int compare_avg_desc(const void *left, const void *right)
{
    const Measurement *m1 = left;
    const Measurement *m2 = right;

    double diff = m2->average - m1->average;

    if (diff == 0)
        return 0;
    else if (diff < 0)
        return -1;
    else
        return 1;
}

// Adatok kiírása a konzolra: előbb rendezés, aztán listázás
void print_results(const int count, Measurement *data)
{
    // Rendezés csökkenő sorrendbe átlag szerint
    qsort(data, count, sizeof(Measurement), compare_avg_desc);

    // Kiírás: minden rekordot egyenként kiírunk
    for (int i = 0; i < count; i++)
    {
        printf("Dátum: %s\n", data[i].date);
        printf("Reggeli: %.1f°C, Déli: %.1f°C, Esti: %.1f°C\n",
               data[i].morning, data[i].noon, data[i].evening);
        printf("Átlagos hőmérséklet: %.2f°C\n", data[i].average);

        // Elválasztó sor a rekordok között
        printf("---\n");
    }
}

// A program belépési pontja
int main()
{
    // A beolvasandó CSV fájl elérési útvonala
    char *fname = "data/measurements.csv"; 

    // Itt fogjuk tárolni a beolvasott rekordokat
    Measurement *data = NULL;             

    // Adatok betöltése a fájlból
    int count = load_measurements(fname, &data);

   // Ha nem sikerült megnyitni a fájlt
    if (count < 0)
    {
        fprintf(stderr, "Hiba: Nem sikerült megnyitni a fájlt.\n");

        // Kilépés hibával
        exit(2); 
    }

    // Kiírjuk a rendezett rekordokat
    print_results(count, data);

    // Dinamikusan lefoglalt memória felszabadítása
    free(data);

    return 0; // Dinamikusan lefoglalt memória felszabadítása
}
