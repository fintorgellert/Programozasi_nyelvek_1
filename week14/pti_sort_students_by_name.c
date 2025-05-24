#include "stringutils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 100

typedef char* string;

typedef struct {
    char name[20];     // A hallgató neve
    int age;           // A hallgató életkora
    char major[5];     // A szak rövidítése
} Student;

// Dinamikusan beolvassuk a fájlt és csak a "pti" szakos hallgatókat tároljuk
// A `count` változó visszaadja a ténylegesen betöltött elemek számát
Student* load_file(const char* filename, int* count)
{
    char line[BUFSIZE];
    char* token;

    string name;
    int age;
    string major;

    // Kezdeti kapacitás a dinamikus tömbhöz
    int capacity = 10;                     

    // Ténylegesen betöltött elemek száma
    int size = 0;                           
    
    // Memóriafoglalás
    Student* students = malloc(capacity * sizeof(Student));  

    FILE* fp = fopen(filename, "r");

    if (!fp) {
        perror("Nem sikerült megnyitni a fájlt");
        *count = 0;
        return NULL;
    }

    // Soronként beolvassuk a fájl tartalmát
    while (fgets(line, BUFSIZE, fp) != NULL)
    {
        // Újsor karakter eltávolítása
        line[strlen(line) - 1] = '\0';  

        token = strtok(line, ",");
        name = token;

        token = strtok(NULL, ",");
        age = atoi(token);

        token = strtok(NULL, ",");
        major = token;

        // Csak a "pti" szakosokat tároljuk
        if (strcmpi(major, "pti") == 0)
        {
            // Ha a tömb megtelt, duplázzuk a kapacitást
            if (size >= capacity) {
                capacity *= 2;
                students = realloc(students, capacity * sizeof(Student));

                if (!students) {
                    perror("Memória újrafoglalás sikertelen");
                    fclose(fp);
                    *count = 0;
                    return NULL;
                }
            }

            // A beolvasott adatokat eltároljuk a struktúrában
            Student s;
            strcpy(s.name, name);
            s.age = age;
            strcpy(s.major, major);

            students[size] = s;
            size++;
        }
    }

    fclose(fp);
    *count = size;
    return students;
}

/*
 * Ez a függvény arra szolgál, hogy két hallgatót (Student típusú struktúrát) összehasonlítson a nevük szerint.
 * A cél az, hogy a qsort() függvény használata során meg tudjuk határozni a sorrendet két elem között.
 * 
 * Paraméterek:
 *   - left: az egyik összehasonlítandó hallgatóra mutató void* típusú mutató
 *   - right: a másik hallgatóra mutató void* típusú mutató
 * 
 * Mivel a qsort() csak void* mutatókkal dolgozik (általános mutató minden típusra),
 * először a void* típusú mutatókat vissza kell alakítanunk a konkrét Student* típusra,
 * hogy elérjük a `name` mezőt bennük.
 * 
 * Visszatérési érték (a strcmp() alapján):
 *   - negatív érték: ha az első név (a->name) kisebb, mint a második név (b->name)
 *   - 0: ha a két név megegyezik
 *   - pozitív érték: ha az első név nagyobb, mint a második
 * 
 * Ez a visszatérési érték alapján dönti el a qsort(), hogy cserélje-e a két elemet vagy sem.
 */
int compare_by_name(const void *left, const void *right)
{
    // Átalakítjuk a void* típusú mutatókat Student* típusra,
    // így elérhetővé válik a struktúra belső tartalma (például a name mező)
    const Student *a = (const Student*)left;
    const Student *b = (const Student*)right;

    // A strcmp() függvény a két név lexikografikus (ábécé szerinti) sorrendjét hasonlítja össze.
    // A visszatérési érték alapján a qsort() tudni fogja, melyik elem hova kerüljön.
    return strcmp(a->name, b->name);
}


// Főprogram
int main()
{
    const string filename = "names.csv";

    int count = 0;

    // Dinamikus beolvasás
    Student *students = load_file(filename, &count);            

    if (!students) {
        fprintf(stderr, "Hiba: nem sikerült betölteni az adatokat a fájlból vagy nem sikerült memóriahelyet lefoglalni.\n");
        
        // Hibakóddal kilépés
        exit(1);                                                
    }
    
    /*
     * A `qsort()` függvény beépített C standard könyvtári függvény,
     * amely egy tömb elemeit rendezi egy megadott összehasonlító függvény alapján.
     * 
     * Itt konkrétan a `students` nevű tömböt rendezzük, amely `Student` típusú elemeket tartalmaz.
     * A rendezés a `compare_by_name()` nevű függvény alapján történik, amely a hallgatók nevét hasonlítja össze.
     * 
     * Paraméterek:
     *   - students: a rendezendő tömb címe (első elem címe)
     *   - count: a tömb elemeinek száma
     *   - sizeof(Student): minden elem mérete byte-ban (a `Student` struktúra mérete)
     *   - compare_by_name: az összehasonlító függvény, amely meghatározza két elem sorrendjét
     * 
     * A `qsort()` működése során:
     *   - páronként meghívja a `compare_by_name()` függvényt a tömb elemeire,
     *   - ha a függvény negatív értéket ad vissza, az első elem marad előbb,
     *   - ha pozitív értéket, akkor cserél,
     *   - ha nulla, akkor egyenlőként kezeli őket.
     * 
     * Eredmény:
     *   A `students` tömb a végrehajtás után ábécérendben (növekvő sorrendben) fogja tartalmazni a neveket.
     */
    qsort(students, count, sizeof(Student), compare_by_name);

    for (int i = 0; i < count; i++) {
        // Név nagy kezdőbetűvel
        string formatted = capitalize(students[i].name);         
        
        if (i != 0)
            printf(", ");

        // Csak a nevet írjuk ki
        printf("%s", formatted); 

        // Felszabadítás 
        free(formatted);                                      
    }

    puts("");

    // Az összes hallgató tömbjének felszabadítása
    free(students);  

    return 0;
}
