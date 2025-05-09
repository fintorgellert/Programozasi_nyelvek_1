# Tizenegyedik hét

## Tartalomjegyzék
- [Bevezetés](#bevezetés)
- [Fájlok áttekintése](#fájlok-áttekintése)
- [Követelmények](#követelmények)
- [Futtatás](#futtatás)

## Bevezetés
A tizenegyedik hét laborjában gyakorlati problémák megoldására fókuszáltunk, amelyek során fájlkezelést, sor- és szófeldolgozást, valamint alapvető statisztikai és rendezési algoritmusokat alkalmaztunk. A cél az volt, hogy tovább mélyítsük a C programozási nyelvben szerzett ismereteinket valós életből vett feladatokon keresztül.

A feldolgozott témák:
- **Fájlkezelés**: Számok olvasása és írása fájlba.
- **Szöveg- és sorfeldolgozás**: Sorok és szavak számolása, rövid szavak azonosítása.
- **Egyszerű statisztikák**: Minimum, maximum, átlag, összeg.
- **Alap algoritmusok**: Egyszerű rendezési algoritmus (pl. szelekciós rendezés).
- **Véletlenszám-generálás**: Lottószám generátor készítése.

## Fájlok áttekintése

- **`array_statistics.c`** – Tömb elemein végzett statisztikai műveletek (összeg, átlag, minimum, maximum).
- **`count_lines.c`** – Sorok megszámlálása egy adott szövegfájlban.
- **`filter_and_export_numbers.c`** – Fájlban szereplő számok szűrése és kiírása egy új fájlba.
- **`random_lottery_generator.c`** – Véletlenszerű lottószámok generálása.
- **`selection_sort_copy.c`** – Egyszerű szelekciós rendezési algoritmus implementálása.
- **`shortest_word_finder.c`** – A legrövidebb szó megtalálása egy szövegben.
- **`sum_real_numbers.c`** – Valós számok összeadása fájlból olvasva.

### Dokumentumok

A `doc/` mappában bemeneti fájlokat találunk a programokhoz:
- **`in.txt`** – Valós számokat tartalmaz a `filter_and_export_numbers.c` programhoz.
- **`real_numbers.txt`** – Valós számokat tartalmazó fájl a `sum_real_numbers.c` programhoz.

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
gcc filter_and_export_numbers.c -o filfilter_and_export_numberster
```

### **2. Futtatás**

A fordított programot az alábbi módon indíthatod el:

Példa:
```bash
./filter_and_export_numbers
```