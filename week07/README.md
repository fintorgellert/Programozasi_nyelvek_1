# Hetedik hét

## Tartalomjegyzék
- [Bevezetés](#bevezetés)
- [Fájlok áttekintése](#fájlok-áttekintése)
- [Követelmények](#követelmények)
- [Futtatás](#futtatás)

## Bevezetés
A hetedik hét labor során a C programozási nyelv fejlettebb témáival foglalkoztunk. A fő hangsúly a **tömbök** kezelésén, a **többértékű függvények** alkalmazásán, valamint az **algoritmusok** gyakorlati megvalósításán volt. Emellett bemutattunk olyan problémákat, amelyek során a felhasználó interakciója és bemenete szükséges.

Az alábbi témák kerültek bemutatásra:
- **Tömbök másolása és inicializálása**: Hogyan hozhatunk létre és másolhatunk tömböket.
- **Többértékű függvények**: Hogyan adhatunk vissza több értéket egy függvényből.
- **Szöveges algoritmusok**: Például a legerősebb jelszó keresése és a Vigenère titkosítás.
- **Pontok távolsága**: Hogyan számolhatjuk ki két pont közötti távolságot.
- **Mintafeladatok**: Olyan feladatok, amelyek segítenek a ZH-ra való felkészülésben.

## Fájlok áttekintése
A projekt az alábbi C forráskódokat tartalmazza, amelyek különböző algoritmusokat és problémákat oldanak meg:

- **`array_copy.c`** – Tömb másolása egy másik tömbbe.
- **`array_init.c`** – Tömb inicializálása és kitöltése.
- **`array_init_v2.c`** – Fejlettebb tömb inicializálás.
- **`different_numbers.c`** – Különböző számok keresése egy tömbben.
- **`distance between two points.c`** – Két pont közötti távolság kiszámítása.
- **`funtcion_return_more_value_2.c`** – Függvény, amely több értéket ad vissza.
- **`funtcion_return_more_value.c`** – Egy másik példa függvényekre, amelyek több értéket adnak vissza.
- **`longest_word.c`** – A leghosszabb szó keresése egy szövegben.
- **`sample_zh/task1.c`** – Minta ZH első feladata.
- **`sample_zh/task2.c`** – Minta ZH második feladata.
- **`sample_zh/task3.c`** – Minta ZH harmadik feladata.
- **`sample_zh/task4.c`** – Minta ZH negyedik feladata.
- **`sample_zh/prog1.c`** – Minta ZH program, amely több feladatot old meg.
- **`sample_zh/prog1.h`** – A fenti programhoz tartozó fejléces fájl.
- **`sample_zh/zh1-minta-2021-marc.pdf`** – Minta ZH feladatok PDF formátumban.
- **`point.c`** – Pontokkal kapcsolatos alapvető műveletek.
- **`prog1.c`** – Általános program különböző algoritmusokhoz.
- **`prog1.h`** – A `prog1.c` programhoz tartozó fejléces fájl.
- **`strong_password.c`** – Erős jelszó generálása.
- **`very_big_number.c`** – Nagy számok kezelése.
- **`vigenere_chiper.c`** – Vigenère titkosítás alkalmazása.

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
gcc strong_password.c -o strong_password
```

### **2. Futtatás**

A fordított programot az alábbi módon indíthatod el:

Példa:
```bash
./strong_password
```