# Hatodik hét

## Tartalomjegyzék
- [Bevezetés](#bevezetés)
- [Fájlok áttekintése](#fájlok-áttekintése)
- [Követelmények](#követelmények)
- [Futtatás](#futtatás)

## Bevezetés
A hatodik hét labor során a C programozási nyelvben a **karakterek és sztringek további kezelését** tanulmányoztuk. A labor célja a különböző sztring műveletek, például karakterek számolása, karakterek keresése, és sztringek összehasonlítása volt. Emellett bemutatásra kerültek a sztringek és karakterek keresésére szolgáló különböző algoritmusok és azok alkalmazása. Bevezetésre került a parancssori argumentumok kezelése is.

Az alábbi témák kerültek bemutatásra:
- **Sztringek és karakterek számlálása**: hány előfordulása van egy karakternek egy sztringben.
- **Sztringek keresése**: egy adott karakter vagy mintázat keresése egy sztringben.
- **Sztringek manipulálása**: sztringek összehasonlítása és módosítása.
- **Felhasználói bemenetek kezelése**: sztringek bevitele és kiíratása.

## Fájlok áttekintése
A projekt az alábbi C forráskódokat tartalmazza, amelyek a sztringekkel kapcsolatos műveleteket mutatják be:

- **`char_count.c`** – Megszámolja, hogy hány előfordulása van egy karakternek egy sztringben.
- **`english_abc.c`** – A teljes angol ABC kiírása.
- **`hello_batman.c`** – A program parancssori argumentumok segítségével üdvözli a felhasználót.
- **`line.c`** – Egy egyszerű program, amely egy vonalat rajzol ki a képernyőre.
- **`match_ends.c`** – Ellenőrzi, hogy egy sztring első és utolsó karaktere megegyezik-e.
- **`prog1.c`** – Általános program sztringek kezelésére.
- **`prog1.h`** – A `prog1.c` programhoz tartozó fejléces fájl.
- **`rfind_char.c`** – Megkeresi egy karakter utolsó előfordulását egy sztringben.
- **`string_scan.c`** – Felhasználói bemenet beolvasása és sztringek kezelése.
- **`sum_from_args.c`** – A program parancssori argumentumaiból számolja ki a számok összegét.
- **`text_char_statistics.c`** – A program parancssori agumentumból átadott szöveg karakterstatisztikája.

## Követelmények
A programok futtatásához a következő szoftverek szükségesek:
- **C fordító**, például **GCC** (GNU Compiler Collection)
- **Terminál** vagy **Parancssor** (Linux/Mac: Terminal, Windows: CMD vagy PowerShell)

## Futtatás
A programok futtatása és fordítása a következő lépésekkel történik:

### **1. Fordítás**
Nyiss egy terminált, navigálj a megfelelő mappába, és futtasd a következő parancsot:

Példa:
```bash
gcc char_count.c -o char_count
```

### **2. Futtatás**

A fordított programot az alábbi módon indíthatod el:

Példa:
```bash
./char_count
```