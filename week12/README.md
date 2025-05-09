# Tizenkettedik hét

## Tartalomjegyzék
- [Bevezetés](#bevezetés)
- [Fájlok áttekintése](#fájlok-áttekintése)
- [Követelmények](#követelmények)
- [Futtatás](#futtatás)

## Bevezetés
A tizenkettedik heti labor célja az volt, hogy elmélyítsük tudásunkat a **mátrixok kezelésében**, **állományok feldolgozásában**, valamint a **rendezési algoritmusok** használatában.

A fő témák:
- **Mátrixok létrehozása és megjelenítése** (egész, karakterlánc és négyzetes mátrixok)
- **Mátrix elemeinek összegzése**
- **Fájlbeolvasás és szűrés** (CSV és szöveges állományból)
- **Adatok rendezése halomrendezéssel (quicksort)**
- **Szöveg darabolása és feldolgozása**

## Fájlok áttekintése

- **`print_int_matrix.c`** – Egész számokat tartalmazó mátrix kiírása a konzolra.
- **`print_square_matrix.c`** – Négyzetes mátrix megjelenítése.
- **`print_string_matrix.c`** – Karakterláncokat tartalmazó mátrix kiírása.
- **`matrix_sum.c`** – Mátrix elemeinek összegzése.
- **`quicksort_file_input.c`** – Gyorsrendezés (quicksort) alkalmazása fájlból beolvasott adatokra.
- **`split_and_print.c`** – Szöveg feldarabolása meghatározott elválasztó mentén és kiíratása.
- **`filter_mi_students.c`** – A `names.csv` fájlból kiszűri azokat a hallgatókat, akik „MI” szakosak.
- **`doc/millions.txt`** – Példaállomány nagy számú adat feldolgozásához.
- **`doc/names.csv`** – CSV állomány hallgatók adataival (pl. név, szak, évfolyam).

### Pót-ZH feladatok(`makeup_exam/`)
- **`task1.c`** – Vizsgafeladat 1. – Szám mínusz egy
- **`task2.c`** – Vizsgafeladat 2. – Halmazok metszete
- **`task3.c`** – Vizsgafeladat 3. – Számvadászat
- **`task4.c`** – Vizsgafeladat 4. – Pangramma

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
gcc matrix_sum.c -o matrix_sum
```

### **2. Futtatás**

A fordított programot az alábbi módon indíthatod el:

Példa:
```bash
./matrix_sum
```

**Megjegyzés:** Egyes programok fájlokat olvasnak a `doc/` mappából, például `names.csv` vagy `millions.txt`. Ezeket a fájlokat mindig tartsd az elérési útvonalon belül!