# Tizennegyedik hét

## Tartalomjegyzék
- [Bevezetés](#bevezetés)
- [Fájlok áttekintése](#fájlok-áttekintése)
- [Követelmények](#követelmények)
- [Futtatás](#futtatás)

## Bevezetés
A tizennegyedik hét fókuszában az **adatstruktúrák** (pl. láncolt lista), valamint a **rendezési algoritmusok** álltak. Emellett a gyakorlat során újrahasznosítható függvénykönyvtárakat is készítettünk, külön fejléces állománnyal.

Az alábbi témák kerültek feldolgozásra:
- **Láncolt listák** létrehozása és kezelése
- **Egész számok rendezése növekvő sorrendbe**
- **Lebegőpontos számok rendezése csökkenő sorrendbe**
- **Hallgatók rendezése név szerint**
- **Saját string függvénykönyvtár használata**

## Fájlok áttekintése

- **`linked_list.c`** – Egyszerű láncolt lista létrehozása és bejárása.
- **`sort_ascending_integers.c`** – Egész számok növekvő sorrendbe rendezése.
- **`sort_descending_doubles.c`** – Valós számok csökkenő sorrendbe rendezése.
- **`pti_sort_students_by_name.c`** – `names.csv` alapján hallgatók név szerinti rendezése.
- **`stringutils.c`** – Karakterláncokkal végzett műveleteket tartalmazó segédfüggvények.
- **`stringutils.h`** – A `stringutils.c` fájlhoz tartozó fejléces állomány.
- **`names.csv`** – CSV formátumú hallgatói adatok (név, szak, évfolyam).

## Követelmények
A programok futtatásához szükséges:
- **C fordító**, például **GCC**
- **Terminál** vagy **Parancssor** (Linux/Mac: Terminal, Windows: CMD vagy PowerShell)

## Futtatás
A programok futtatása és fordítása a következő lépésekkel történik:

### **1. Fordítás**
Nyiss egy terminált, navigálj a megfelelő mappába, és futtasd a következő parancsot a kód forrdításához:

Példa:
```bash
gcc pti_sort_students_by_name.c stringutils.c -o sort_students
gcc linked_list.c -o linked_list
```

### **2. Futtatás**

A fordított programot az alábbi módon indíthatod el:

Példa:
```bash
./sort_students
./linked_list
```
