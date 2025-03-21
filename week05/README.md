# Ötödik hét

## Tartalomjegyzék
- [Bevezetés](#bevezetés)
- [Fájlok áttekintése](#fájlok-áttekintése)
- [Követelmények](#követelmények)
- [Futtatás](#futtatás)

## Bevezetés
Az ötödik hét labor során a **C programozási nyelvben** történő **sztringek és karakterek kezelését** tanulmányoztuk. A labor célja a karakterek és sztringek kezelésének alapvető műveleteinek bemutatása volt. Ezen a héten olyan műveletek kerültek bemutatásra, mint a karakterek keresése, a sztringek hossza, palindrom ellenőrzése, valamint a felhasználói bemenetek kezelése.

A következő témák kerültek bemutatásra:
- **Sztringek kezelése**: karakterek keresése és manipulálása
- **Bemenet kezelése**: felhasználói adatok beolvasása
- **Sztringek hosszának meghatározása**: saját függvények írása sztringek hosszának kiszámítására
- **Palindrom ellenőrzése**

## Fájlok áttekintése
A projekt az alábbi C forráskódokat tartalmazza, amelyek a sztringek és karakterek kezelésére szolgáló műveleteket mutatják be:

- **`contains_char.c`** – Ellenőrzi, hogy egy adott karakter szerepel-e a sztringben.
- **`find_char.c`** – Megkeresi egy karakter indexét a sztringben.
- **`input_name.c`** – Felhasználói név bevitele és kiíratása.
- **`my_strlen_for.c`** – A sztring hosszának meghatározása egy `for` ciklussal.
- **`my_strlen_while.c`** – A sztring hosszának meghatározása egy `while` ciklussal.
- **`palindrome.c`** – Ellenőrzi, hogy egy sztring palindrom-e (ugyanaz előről és hátulról olvasva).
- **`prog1.c`** – Egy általános program, amely sztringeket kezel.
- **`prog1.h`** – A `prog1.c` programhoz tartozó fejléces fájl.
- **`string_length.c`** – A sztring hosszának kiszámítása és kiíratása.

## Követelmények
A programok futtatásához a következő szoftverek szükségesek:
- **C fordító**, például **GCC** (GNU Compiler Collection)
- **Terminál** vagy **Parancssor** (Linux/Mac: Terminal, Windows: CMD vagy PowerShell)

## Futtatás
A programok futtatása és fordítása a következő lépésekkel történik:

### **1. Fordítás**
Nyiss egy terminált, navigálj a megfelelő mappába, és futtasd a következő parancsot:

Ha a programod egy saját header fájlt használ, például `prog1.h`-t, akkor a megfelelő forráskódokat is fordítanod kell, hogy a header fájlban definiált függvények és eljárások elérhetőek legyenek. Ebben az esetben a header fájlt tartalmazó programot a következő módon fordíthatod le:

Példa:
```bash
gcc input_name.c prog1.c -o input_name
```

Ez a parancs mind a `prog1.c`-t, mind pedig az `input_name.c` fájlt lefordítja, és a két fájl összekapcsolásával hozza létre az `input_name` nevű végrehajtható fájlt. Ha több fájl is szükséges a programhoz, azokat mind bele kell foglalni a fordítási parancsba.

### **2. Futtatás**

A fordított programot az alábbi módon indíthatod el:

Példa:
```bash
./input_name
```
