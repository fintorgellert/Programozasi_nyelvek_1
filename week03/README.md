# Harmadik hét

## Tartalomjegyzék
- [Bevezetés](#bevezetés)
- [Fájlok áttekintése](#fájlok-áttekintése)
- [Követelmények](#követelmények)
- [Futtatás](#futtatás)

## Bevezetés
A harmadik hét labor során a **C programozási nyelv** további alapvető eszközeit és vezérlési struktúráit vizsgáltuk. A következő témák kerültek bemutatásra:
- **Feltételes elágazások**: `if`, `else`, `switch`
- **A program vezérlésének irányítása**: `break`, `continue`
- **Matematikai műveletek**: abszolút érték, kör területének számítása
- **Felhasználói bemenet**: pozitív egész számok bekérése, típusellenőrzés

A labor során alkalmazott példák segítenek jobban megérteni a vezérlési struktúrákat és a matematikai műveleteket C-ben.

## Fájlok áttekintése
A projekt az alábbi C forráskódokat tartalmazza, amelyek az egyes témákhoz kapcsolódó példaprogramokat mutatják be:

- **`abs.c`** – Az abszolút érték kiszámítása.
- **`break_continue.c`** – A `break` és `continue` utasítások használata ciklusokban.
- **`circle.c`** – A kör területének kiszámítása, `pi` konstans használata.
- **`double.c`** – Egy szám kétszeresének kiszámítása.
- **`get_int.c`** – Felhasználói bemenet kérése egész számra.
- **`get_positive_int_do_while.c`** – A felhasználótól pozitív szám bekérése `do-while` ciklussal.
- **`get_positive_int_while.c`** – A felhasználótól pozitív szám bekérése `while` ciklussal.
- **`mario_v1.c`** – Mario híres piramisának egyszerűsített változata (`for` ciklussal).
- **`mario_v2.c`** – Mario piramisa, amely lehetővé teszi a felhasználói bemenet alapján történő magasságválasztást.
- **`my_abs.c`** – Saját abszolút érték függvény implementálása.

## Követelmények
A programok futtatásához a következő szoftverek szükségesek:
- **C fordító**, például **GCC** (GNU Compiler Collection)
- **Terminál** vagy **Parancssor** (Linux/Mac: Terminal, Windows: CMD vagy PowerShell)

## Futtatás
A programok fordítása és futtatása a következő lépésekkel történik:

1. **Fordítás**

    Nyiss egy terminált, navigálj a megfelelő mappába, majd futtasd a következő parancsot:

    Példa a `hello.c` program fordítására:
    ```bash
    gcc abs.c -o abs
    ```

2. **Futtatás**

    A fordított programot a következő módon indíthatod el:

    Példa:

    ```bash
    ./abs
    ```