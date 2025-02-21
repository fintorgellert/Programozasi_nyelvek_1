# Első hét

## Tartalomjegyzék
- [Bevezetés](#bevezetés)
- [Fájlok áttekintése](#fájlok-áttekintése)
- [Követelmények](#követelmények)
- [Futtatás](#futtatás)

## Bevezetés
Ez a projekt az első hét laborjának anyagát tartalmazza, amely során bevezetést kaptunk a **C programozási nyelv** alapjaiba. A labor célja az volt, hogy megismerkedjünk a C nyelv alapvető szintaktikai elemeivel és működésével, valamint az egyszerű programok írásával és futtatásával.

Az alábbi témák kerültek bemutatásra:

- Alapvető változók és kimenet
- Felhasználói bemenet kezelése
- Aritmetikai műveletek
- Feltételek és elágazások
- Ciklusok
- Egyszerű matematikai számítások

## Fájlok áttekintése
A projekt az alábbi C forráskódokat tartalmazza, amelyek az egyes témákhoz kapcsolódó példaprogramokat mutatják be:

- `arithmetic_operations.c` – Alapvető aritmetikai műveletek bemutatása (`+`, `-`, `*`, `/`, `%`).
- `declaration_and_output.c` – Változók deklarálása és kiíratása a konzolra.
- `even_or_odd.c` – Egy szám páros vagy páratlan voltának eldöntése.
- `hello.c` – Az első klasszikus *Hello, World!* program.
- `loop.c` – Ciklusok (`for`, `while`, `do-while`) használatának bemutatása.
- `rectangle.c` – Téglalap területének és kerületének kiszámítása.
- `square.c` – Négyzet területének és kerületének kiszámítása.
- `using_input.c` – Felhasználói bemenet (`scanf`) kezelése.

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
    gcc hello.c -o hello
    ```

2. **Futtatás**

    A fordított programot a következő módon indíthatod el:

    ```bash
    ./<kimeneti_fájl>
    ```

    Példa:

    ```bash
    ./hello
    ```