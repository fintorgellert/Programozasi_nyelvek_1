/*
===============================================================================
    LÁNCOLT LISTÁK (Linked Lists) – MAGYARÁZAT ÉS MŰKÖDÉS

    Mi az a láncolt lista?

    A láncolt lista egy dinamikus adatszerkezet, amelyet elemek (csomópontok) 
    sorozata alkot. Minden elem (node) két dolgot tartalmaz:
        1. az adatot (pl. egy egész szám),
        2. egy mutatót a következő elemre a listában (vagy NULL, ha nincs több).

    A lista első elemére egy „fej” (head) nevű mutató mutat.
    A legutolsó elem „következő mutatója” NULL, ezzel jelezve a lista végét.

    Hogyan működik?

    - A lista elemei nem egymás után helyezkednek el a memóriában, 
      mint például egy tömb esetén, hanem szórtan.
    - Új elem beszúrásakor `malloc` segítségével dinamikusan foglalunk memóriát.
    - Minden elem mutat a következőre: így épül fel a lánc.
    - Bejáráskor a fej (head) mutatótól indulunk, és minden csomópontból 
      a „következő mutatóval” lépünk tovább, amíg NULL-hoz nem érünk.

    Előnyei:

    - Dinamikus méretű – annyi elemet tartalmazhat, amennyi memória rendelkezésre áll.
    - Hatékony beszúrás és törlés – különösen a lista elején vagy közepén, 
       nem kell az elemeket eltolni, mint tömbnél.
    - Nem szükséges előre megadni a maximális méretet.

    Hátrányai:

    - Lassabb elérés – nem lehet közvetlenül egy adott indexű elemhez ugrani,
       minden lépésnél végig kell menni a láncon.
    - Minden elemhez szükség van egy mutató tárolására, ez memóriát igényel.
    - Bonyolultabb kezelni, mint például egy tömböt – több hibalehetőség, pl. memóriafelszabadítás elfelejtése.

    Mire jó a láncolt lista?

    Olyan esetekben hasznos, amikor:
        - nem tudjuk előre, mennyi adatot fogunk tárolni,
        - gyakran szúrunk be vagy törlünk adatokat a lista közepéről,
        - fontos a dinamikus memóriakezelés.

    Típusai:

    - Egyszeresen láncolt lista: minden elem csak a következőre mutat.
    - Duplán láncolt lista: minden elem az előzőre és a következőre is mutat.
    - Körkörös láncolt lista: az utolsó elem visszamutat az elsőre.

===============================================================================
*/

#include <stdio.h>      // Szükséges az input/output (pl. printf, scanf) műveletekhez
#include <stdbool.h>    // A `bool`, `true` és `false` típusok és konstansok használatához
#include <stdlib.h>     // Dinamikus memóriafoglaláshoz: malloc, free

// Egy láncolt lista egy elemének (csomópontjának) a struktúrája
typedef struct node {
    int data;               // Az aktuális elem által tárolt érték (egész szám)
    struct node *next;      // Mutató a következő elemre a listában (NULL, ha nincs több)
} Node;

// Két globális mutató: a lista elejére (head) és végére (tail) mutatnak
Node *head = NULL;          // A lista kezdete; kezdetben nincs egyetlen elem sem, ezért NULL
Node *tail = NULL;          // A lista vége; kezdetben nincs vég, mert nincs elem

// Egy új szám beszúrása a lista végére
void ll_insert(int number)
{
    Node *new_node = malloc(sizeof(Node));  // Dinamikusan lefoglalunk helyet egy új listaelemnek
    new_node->data = number;                // Beállítjuk az új elem adattagját
    new_node->next = NULL;                  // Az új elem után még nincs semmi, ez lesz a lista vége

    if (head == NULL)   // Ha a lista jelenleg üres (nincs fej)
    {
        head = new_node;    // A fej az új elemre mutat
        tail = new_node;    // Mivel ez az egyetlen elem, a vége is ez
    }
    else
    {
        tail->next = new_node;  // Az eddigi utolsó elem "next" mezőjét beállítjuk, hogy az új elemre mutasson
        tail = new_node;        // Frissítjük a lista végét: az új elem mostantól a vége
    }
}

// A lista elemeinek kiíratása sorban
void ll_print()
{
    Node *current = head;     // Kezdjük a bejárást a lista elején

    while (current != NULL)   // Amíg nem érjük el a lista végét (NULL), folytatjuk
    {
        printf("%d\n", current->data);  // Kiírjuk az aktuális elem értékét
        current = current->next;        // Továbblépünk a következő elemre
    }
}

// Rekurzív függvény a lista elemeinek felszabadítására
void ll_free_recursive(Node *current)
{
    if (current != NULL)  // Ha még nem értünk a lista végére
    {
        Node *next_node = current->next;  // Elmentjük a következő elem címét
        free(current);                    // Felszabadítjuk az aktuális elemet a memóriából
        ll_free_recursive(next_node);     // Meghívjuk önmagát a következő elemre (rekurzió)
    }
}

// Ez a függvény elindítja a rekurzív törlést a lista elejétől
void ll_clear()
{
    ll_free_recursive(head);  // A törlést a head mutató által jelölt első elemtől kezdjük
    head = NULL;              // A head mutatót NULL-ra állítjuk, jelezve, hogy a lista üres
    tail = NULL;              // A tail mutatót is NULL-ra állítjuk
}

// A program belépési pontja (main függvény)
int main()
{
    int number;

    while (true)
    {
        printf("Adj meg egy pozitív számot 0 végjelig: ");
        scanf("%d", &number);  // Beolvassuk a felhasználó által megadott számot

        if (number == 0) {
            puts("bye");       // Kilépési üzenet
            break;             // Kilépünk a ciklusból
        }

        ll_insert(number);     // A beolvasott számot beszúrjuk a láncolt lista végére
    }

    puts("---");

    ll_print();     // Kiírjuk az összegyűjtött számokat a láncolt listából

    ll_clear();     // Felszabadítjuk a dinamikusan foglalt memóriaelemeket

    return 0;       // A program sikeresen befejeződött
}
