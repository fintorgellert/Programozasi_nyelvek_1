#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "stringutils.h"  // Feltételezzük, hogy tartalmaz egy strcmpi függvényt (kis- és nagybetű érzéketlen összehasonlításhoz)

// A maximálisan tárolható hallgatók száma
#define MAX_STUDENTS 100     

// Egy sor maximális hossza a fájlból (karakterekben)
#define LINE_BUFFER 100      

/*
 * 'string' típusdefiníció a jobb olvashatóság érdekében.
 * A 'string' valójában char pointert (karakterlánc) jelent.
 */
typedef char* string;

/*
 * 'Student' struktúra – egy hallgató adatait tartalmazza:
 *   - name: a hallgató neve
 *   - age: életkor (egész számként)
 *   - major: a szak rövidítése (pl. "PTI")
 */
typedef struct {
    char name[20];
    int age;
    char major[5];
} Student;

/*
 * load_students:
 * ---------------
 * Feladata: fájlból soronként beolvasni a hallgatók adatait,
 *           majd eltárolni a PTI szakosokat egy tömbbe.
 *
 * Paraméterek:
 *   - filename: a beolvasandó fájl neve (pl. "nevek.csv")
 *   - max: a maximálisan eltárolható hallgatók száma
 *   - students: a hallgatókat tároló tömb
 *
 * Visszatérési érték:
 *   - A beolvasott és eltárolt PTI-s hallgatók száma
 *
 * A fájl elvárt formátuma soronként:
 *   név,kor,szak
 * Például:
 *   anna,21,pti
 */
int load_students(const char* filename, int max, Student students[]) {
    // Számláló a tömbhöz
    int count = 0; 

    // A fájlból olvasott sor
    char line[LINE_BUFFER]; 

    // Daraboláshoz használt pointer
    char* token; 

    string name;
    int age;
    string major;

    // Fájl megnyitása olvasásra
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Nem sikerült megnyitni a fájlt");
        return 0;
    }

    // Soronként beolvassuk a fájlt
    while (fgets(line, LINE_BUFFER, file) != NULL) {
        // Sorvégi újsor karakter eltávolítása ('\n')
        line[strcspn(line, "\n")] = '\0';

        // A sor szétbontása ',' mentén három részre: név, kor, szak
        token = strtok(line, ",");
        name = token;

        token = strtok(NULL, ",");

        // kor -> egész számmá konvertáljuk
        age = atoi(token); 

        token = strtok(NULL, ",");
        major = token;

        // Csak a PTI szakosokat vesszük figyelembe (kis-nagybetű nem számít)
        if (strcmpi(major, "pti") == 0) {
            Student s;

            // A beolvasott adatokat betöltjük a struktúrába
            strcpy(s.name, name);
            s.age = age;
            strcpy(s.major, major);

            students[count++] = s;

            // túlcsordulás elkerülése
            if (count >= max) 
                break; 
        }
    }

    // Fájl bezárása
    fclose(file); 

    // A sikeresen eltárolt hallgatók száma
    return count; 
}

/*
 * print_student:
 * ---------------
 * Egy hallgató adatainak kiírása standard kimenetre.
 *
 * Paraméter:
 *   - s: pointer a hallgató struktúrára
 */
void print_student(const Student* s) {
    printf("%s, %d, %s\n", s->name, s->age, s->major);
}

/*
 * sort_students_by_name:
 * -----------------------
 * Buborékrendezéssel növekvő sorrendbe rendezi a hallgatókat név szerint.
 *
 * Paraméterek:
 *   - students: a hallgatók tömbje
 *   - n: a hallgatók száma
 *
 * A rendezés alapja az ABC szerinti sorrend (strcmp segítségével).
 */
void sort_students_by_name(Student students[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (strcmp(students[j].name, students[j + 1].name) > 0) {
                // Ha a j. név "nagyobb", mint a j+1. név, cseréljük őket
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

/*
 * main:
 * ------
 * A program belépési pontja.
 * 1. Betölti a hallgatókat a fájlból.
 * 2. Szűri a PTI szakosokat.
 * 3. Rendezés név szerint.
 * 4. Kiírás a képernyőre.
 */
int main() {
    // A bemeneti CSV fájl neve
    const char* filename = "names.csv"; 

    // Hallgatók tömbje
    Student students[MAX_STUDENTS];     

    // Betöltés fájlból
    int student_count = load_students(filename, MAX_STUDENTS, students); 

    printf("Beolvasott PTI szakos hallgatók száma: %d\n", student_count);

    // Rendezés név szerint
    sort_students_by_name(students, student_count); 

    // Kiírás: minden hallgató adatainak megjelenítése
    for (int i = 0; i < student_count; i++) {
        print_student(&students[i]);
    }

    return 0;
}
