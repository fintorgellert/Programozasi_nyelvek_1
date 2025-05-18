# Tizenharmadik hét

## Tartalomjegyzék
- [Bevezetés](#bevezetés)
- [Fájlok áttekintése](#fájlok-áttekintése)
- [Követelmények](#követelmények)
- [Futtatás](#futtatás)

## Bevezetés
A tizenharmadik hét középpontjában a **karakterláncok kezelése**, a **dinamikus memóriakezelés**, valamint az **adatok szűrése és rendezése** állt. Ezen a héten moduláris programozás is előtérbe került, külön fejlécek és forrásállományok segítségével.

Témák:
- Karakterláncok módosítása (pl. kisbetű → nagybetű)
- Dinamikus tömbök használata és bővítése
- CSV állomány szűrése és rendezése adott szempontok szerint
- Függvények rekurzív megvalósítása
- Saját függvénykönyvtár (header/source fájl páros) használata

## Fájlok áttekintése

- **`capitalize.c`** – Karakterlánc első betűinek nagybetűssé alakítása.
- **`dyn_array.c`** – Dinamikusan bővíthető tömb kezelése C nyelven.
- **`filter_and_sort_pti_students.c.c`** – A `names.csv` fájl alapján kiszűri és rendezi a PTI szakos hallgatókat.
- **`ultiples_recursive.c`** – Rekurzív függvény, amely többszörösöket keres egy adott feltétel alapján.
- **`stringutils.c`** – Különböző karakterlánc-műveleteket megvalósító függvények implementációja.
- **`stringutils.h`** – A `stringutils.c` fájlhoz tartozó fejléces állomány.
- **`names.csv`** – CSV állomány hallgatók adataival, pl. név, szak, évfolyam.

## Követelmények
A programok futtatásához szükség van:
- **C fordítóra**, például **GCC** (GNU Compiler Collection)
- **Terminálra** vagy **Parancssorra** (Linux/Mac: Terminal, Windows: CMD vagy PowerShell)

## Futtatás
A programok futtatása és fordítása a következő lépésekkel történik:

### **1. Fordítás**
Nyiss egy terminált, navigálj a megfelelő mappába, és futtasd a következő parancsot:

Példa:
```bash
gcc capitalize.c -o capitalize
```

### **2. Futtatás**

A fordított programot az alábbi módon indíthatod el:

Példa:
```bash
./capitalize
```
