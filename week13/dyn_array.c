#include <stdio.h>
#include <stdlib.h>

// A tömb kezdeti kapacitása
#define INITIAL_CAPACITY 2  

/*
 * Egy dinamikus tömb struktúrája.
 * - elems: a tömb elemeit tároló pointer
 * - length: jelenlegi elemszám (hány értéket tárol)
 * - capacity: a foglalt hely mérete (mennyi fér bele)
 */
typedef struct {
    int *elems;
    int length;
    int capacity;
} DynArray;

/*
 * mem_error_exit:
 * ----------------
 * Memóriafoglalási hiba esetén hibaüzenetet ír ki és kilép a programból.
 */
void mem_error_exit()
{
    fprintf(stderr, "Error: cannot allocate memory");
    exit(1);
}

/*
 * da_create:
 * ------------
 * Létrehoz egy új dinamikus tömböt.
 * Foglal memóriát a struktúrának és az elemek tömbjének is.
 *
 * Visszatérési érték:
 *   - Pointer a létrehozott DynArray struktúrára.
 */
DynArray * da_create()
{
    // Struktúra foglalása
    DynArray *result = malloc(sizeof(DynArray)); 
    if (result == NULL) {
        mem_error_exit();
    }

    int initial_capacity = INITIAL_CAPACITY;

    // Elem tömb foglalása
    result->elems = malloc(initial_capacity * sizeof(int)); 
    if (result->elems == NULL) {
        mem_error_exit();
    }

    // Kezdetben üres
    result->length = 0;                  

    // Beállítjuk a kezdeti kapacitást
    result->capacity = initial_capacity; 

    return result;
}

/*
 * da_append:
 * ------------
 * Új elemet fűz a dinamikus tömb végéhez.
 * Ha megtelik, akkor kétszeresére növeli a kapacitását (realloc).
 *
 * Paraméterek:
 *   - self: a dinamikus tömb pointere
 *   - data: a hozzáadandó érték
 */
void da_append(DynArray *self, int data)
{
    // Ha elértük a kapacitást, akkor bővítjük a memóriát
    if (self->length == self->capacity)
    {
        int new_capacity = 2 * self->capacity;
        self->elems = realloc(self->elems, new_capacity * sizeof(int));
        if (self->elems == NULL) {
            mem_error_exit();
        }
        self->capacity = new_capacity;
    }

    // Új érték elhelyezése a tömb végén
    self->elems[self->length] = data;
    self->length += 1;
}

/*
 * da_print:
 * ----------
 * Kiírja a dinamikus tömb aktuális elemeit a standard kimenetre.
 */
void da_print(DynArray *self)
{
    for (int i = 0; i < self->length; i++)
    {
        printf("%d ", self->elems[i]);
    }

    // Újsor
    puts(""); 
}

/*
 * da_clear:
 * ----------
 * Kiüríti a dinamikus tömböt.
 * Felszabadítja az elemek tömbjét, majd újraméretezi alapméretre.
 */
void da_clear(DynArray *self)
{
    // Régi memória felszabadítása
    free(self->elems); 

    // Új alapértelmezett méretű tömb foglalása
    self->elems = malloc(INITIAL_CAPACITY * sizeof(int));
    self->length = 0;
    self->capacity = INITIAL_CAPACITY;
}

/*
 * da_destroy:
 * ------------
 * Felszabadítja az összes lefoglalt memóriát (elemek + struktúra).
 * NULL pointert ad vissza, hogy ne maradjon érvénytelen pointer.
 */
void * da_destroy(DynArray *self)
{
    // Elem tömb felszabadítása
    free(self->elems);

    // Maga a struktúra felszabadítása 
    free(self);      

    return NULL;
}

/*
 * main:
 * ------
 * A dinamikus tömb működésének demonstrálása:
 * - Feltöltjük 1-9 közötti számokkal
 * - Kiírjuk
 * - Kiürítjük
 * - Feltöltjük 10-19 közötti számokkal
 * - Újra kiírjuk
 */
int main()
{
    // Létrehozzuk a dinamikus tömböt
    DynArray *arr = da_create(); 

    // Első feltöltés: 1–9
    for (int i = 1; i < 10; i++)
    {
        da_append(arr, i);
    }

    puts("Előtte:");
    da_print(arr);

    // Kiürítés
    da_clear(arr);

    // Második feltöltés: 10–19
    for (int i = 10; i < 20; i++)
    {
        da_append(arr, i);
    }

    puts("Utána:");
    da_print(arr);

    // Memória felszabadítása
    da_destroy(arr); 

    return 0;
}
