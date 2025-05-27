# Extra gyakorló óra

## Tartalomjegyzék
- [Bevezetés](#bevezetés)
- [Fájlok áttekintése](#fájlok-áttekintése)
- [Követelmények](#követelmények)
- [Fordítás és futtatás](#fordítás-és-futtatás)

## Bevezetés
Ez a könyvtár egy **extra gyakorló óra** anyagait tartalmazza, amely a máodik zárthelyi dolgozatra való felkészülést segíti. A példaprogramok különféle gyakorlati problémák megoldására fókuszálnak, beleértve a fájlkezelést, mátrixműveleteket, szövegfeldolgozást, adatfeldolgozást és saját függvénykönyvtárak használatát. Az anyag célja a korábban tanult ismeretek alkalmazása és elmélyítése.

Tartalmaz továbbá egy gyakorló feladtsort.

## Fájlok áttekintése

### Kódfájlok
- **`math_utils.c`**, **`math_utils.h`** – Saját matematikai segédfüggvények (pl. átlag, szórás).
- **`test_math_utils.c`** – Tesztprogram a `math_utils` függvények kipróbálásához.
- **`matrix_lower_triangle_avg.c`** – Mátrix alsó háromszögének átlagát számolja.
- **`matrix_lower_triangle_stddev.c`** – Mátrix főátló alatti eleknek a szórását számolja.
- **`popular_movies_filter_sorted.c`** – Filmek szűrése és rendezése egy CSV fájl alapján.
- **`weather_data_analyzer.c`** – Időjárási adatok feldolgozása.
- **`weekly_step_report.c`** – Heti lépésszám statisztikák készítése.
- **`text_compressor.c`** – Karakterek véletlenszerű eltávolítása egy szöveges állományból.
- **`tokenize_words_to_lines.c`** – Egy szöveg szavainak soronkénti kiírása.
- **`word_random_replacer.c`** – Szavak véletlenszerű cseréje egy szöveges állományban.

### Adatfájlok (`data/` mappa)
- **`daily_steps.csv`** – Lépésszám adatok.
- **`input.txt`** – Tesztadat a szöveges állományt feldolgozó programokhoz.
- **`measurements.csv`** – Hőmérsékleti mérések.
- **`movies.csv`** – Filmek adatai (cím, év, értékelés stb.).

### Dokumentáció
- **`practice_exam.pdf`** – Gyakorló feladatsor.

### Egyéb
- **`Makefile`** – Automatizált fordításhoz használható.

## Követelmények
A programok futtatásához szükséges:
- **C fordító**, pl. **GCC**
- **Terminál** vagy **parancssor** (Linux/macOS/Windows)
- Opcionálisan: **make** eszköz a Makefile futtatásához


## Fordítás és futtatás
A programok futtatása és fordítása a következő lépésekkel történik:

### **1. Fordítás**

Nyiss egy terminált, navigálj a megfelelő mappába, és futtasd a következő parancsot a kód forrdításához:

Példa:
```bash
gcc matrix_lower_triangle_avg.c -o matrix_lower_triangle_avg
gcc test_math_utils.c math_utils.c -o test
gcc tokenize_words_to_lines.c -o tokenize_words_to_lines
```

### **2. Futtatás**

A fordított programot az alábbi módon indíthatod el:

Példa:
```bash
./matrix_lower_triangle_avg
./test
./tokenize_words_to_lines input.txt output.txt
```
