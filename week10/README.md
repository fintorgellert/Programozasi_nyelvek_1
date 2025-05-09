# Tizedik hét

## Tartalomjegyzék
- [Bevezetés](#bevezetés)
- [Fájlok áttekintése](#fájlok-áttekintése)
- [Követelmények](#követelmények)
- [Futtatás](#futtatás)

## Bevezetés
A tizedik hét labor során a C programozásban mélyebb technikákkal és algoritmusokkal ismerkedtünk meg. A fókuszban az **algoritmusok** és a **karakterláncok manipulálása**, valamint az **adatkezelési technikák** álltak. Továbbá betekintést nyertünk a **típuskonverziók** és a **véletlenszerű számok generálásának** lehetőségeibe is.

Az alábbi témák kerültek bemutatásra:
- **Halmazműveletek**: Halmazok uniója és különbsége.
- **Véletlenszerű intervallumok generálása**: Hogyan generálhatunk véletlenszerű számokat.
- **Típuskonverziók**: Hogyan konvertálhatunk adatokat egyik típusból a másikba.
- **Karakterláncok elemzése**: Szavak és karakterek számolása.
- **Vizsga feladatok**: Az I. ZH feladatainak megoldása.

## Fájlok áttekintése
A projekt az alábbi C forráskódokat tartalmazza:

- **`random_intervals_example.c`** – Példa a véletlenszerű intervallumok használatára C-ben.
- **`set_operations.c`** – Halmazműveletek alapvető alkalmazása (unió, különbség stb.).
- **`type_conversion_example.c`** – Típuskonverziók bemutatása C-ben (típusok közötti átváltás).
- **`word_and_char_counter.c`** – Program, amely megszámolja a szavakat és karaktereket egy adott karakterláncban.

### Vizsga feladatok
A következő feladatok az I. ZH feladat lehetséges megoldásait tartalmazza:

- **Kedd ZH (`tuesday_exam/`)**
  - `task1.c` – C program az első feladathoz - Számkereső.
  - `task2.c` – C program a második feladathoz - Mersenne-prímek.
  - `task3.c` – C program a harmadik feladathoz - Meteorológiai előrejelzés.
  - `task4.c` – C program a negyedik feladathoz - Eredmények útján.

- **Péntek ZH (`friday_exam/`)**
  - `task1.c` – C program az első feladathoz - Hatványozás.
  - `task2.c` – C program a második feladathoz - Egy kis statisztika.
  - `task3.c` – C program a harmadik feladathoz - Kavalkád.
  - `task4.c` – C program a negyedik feladathoz - Caesar-titkosítás.


## Követelmények
A programok futtatásához szükség van:
- **C fordítóra**, például **GCC** (GNU Compiler Collection).
- **Terminálra** vagy **Parancssorra** (Linux/Mac: Terminal, Windows: CMD vagy PowerShell).

## Futtatás
A programok futtatása és fordítása a következő lépésekkel történik:

### **1. Fordítás**
Nyiss egy terminált, navigálj a megfelelő mappába, és futtasd a következő parancsot:

Példa:
```bash
gcc random_intervals_example.c -o random_intervals_example
```

### **2. Futtatás**

A fordított programot az alábbi módon indíthatod el:

Példa:
```bash
./random_intervals_example
```