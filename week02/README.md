# Második hét

## Tartalomjegyzék
- [Bevezetés](#bevezetés)
- [Fájlok áttekintése](#fájlok-áttekintése)
- [Követelmények](#követelmények)
- [Futtatás](#futtatás)

## Bevezetés
Ez a projekt a második hét laborjának anyagát tartalmazza, amely során mélyebb betekintést nyertünk a **C programozási nyelv** ciklusainak, típuskonverzióinak és a felhasználói bemenetek kezelésének alapjaiba. A labor célja az volt, hogy jobban megismerkedjünk a ciklusok (például `for`, `while`, `do-while`) és a típuskonverziók (pl. explicite típusátalakítás) alkalmazásával.

A következő témákat érintettük:
- **Ciklusok**: `for`, `while`, `do-while`
- **Felhasználói bemenet kezelése**
- **Típuskonverziók**: explicit típusátalakítás
- **Logikai műveletek**
- **Feltételes elágazások**

## Fájlok áttekintése
A projekt az alábbi C forráskódokat tartalmazza, amelyek az egyes témákhoz kapcsolódó példaprogramokat mutatják be:

- **`count_10_to_1.c`** – Csökkentő ciklussal számlál 10-től 1-ig.
- **`count_1_to_10.c`** – Növekvő ciklussal számlál 1-től 10-ig.
- **`count_entered_elements.c`** – A felhasználó által megadott számok alapján számolja meg az elemeket.
- **`even_numbers_down_from_10.c`** – Páros számok kiírása 10-től lefelé.
- **`explicit_type_casting.c`** – Példa explicite típuskonverzióra (pl. `int` -> `float`).
- **`for_loop.c`** – A `for` ciklus használatának bemutatása.
- **`loop_print_hello.c`** – Ciklussal egy formázott kiiratással a "#) Hello" üzenetet írjuk a kijelzőre .
- **`positiv_number_input_do_while_loop.c`** – A felhasználói bemenetek kezelése `do-while` ciklussal, amíg a felhasználó pozitív számot nem ad meg.
- **`positiv_number_input_while_loop.c`** – A felhasználói bemenetek kezelése `while` ciklussal.
- **`pozitive_negative_zero.c`** – A szám pozitív, negatív vagy nulla voltának ellenőrzése.
- **`sum_1_to_100.c`** – A 1-től 100-ig terjedő számok összegének kiszámítása.
- **`sum_multiples_3_and_5.c`** – A 3 és 5 többszöröseinek összegzése 1-től 100-ig.
- **`while_loop.c`** – A `while` ciklus alapvető használata.

## Követelmények
A programok futtatásához a következő szoftverek szükségesek:
- **C fordító**, például **GCC** (GNU Compiler Collection)
- **Terminál** vagy **Parancssor** (Linux/Mac: Terminal, Windows: CMD vagy PowerShell)

## Futtatás
A programok fordítása és futtatása a következő lépésekkel történik:

1. **Fordítás**

    Nyiss egy terminált, navigálj a megfelelő mappába, majd futtasd a következő parancsot:

    ```bash
    gcc <fájl_név>.c -o <kimeneti_fájl>
    ```

    Példa a `hello.c` program fordítására:
    ```bash
    gcc count_10_to_1.c -o count_10_to_1
    ```

2. **Futtatás**

    A fordított programot a következő módon indíthatod el:

    ```bash
    ./<kimeneti_fájl>
    ```

    Példa:

    ```bash
    ./count_10_to_1
    ```