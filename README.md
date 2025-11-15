# Studentų rūšiavimo optimizavimas (v1.0)

## Projekto aprašymas

Ši programa skirta **studentų duomenų nuskaitymui, rikiavimui ir dalijimui į dvi kategorijas** – „vargšiukus“ (galutinis < 5) ir „kietuolius“ (galutinis ≥ 5).
Tyrimo tikslas – **įvertinti programos veikimo spartą**, priklausomai nuo:

1. **Naudojamo konteinerio tipo:** `std::vector` ir `std::list`
2. **Naudotos skaidymo strategijos:**

   * **1 strategija:** Du nauji konteineriai
   * **2 strategija:** Vienas naujas konteineris („vargšiukai“)
   * **3 strategija:** Optimizuota greičiausia versija naudojant STL algoritmus

---

## Naudojimosi instrukcija

1. Atsidarykite terminalą.
2. Sukompiliuokite programą:

   ```bash
   make
   ```

   arba:

   ```bash
   cmake .
   make
   ```
3. Paleiskite:

   ```bash
   ./projektas
   ```
4. Pasirinkite režimą:

   * `1` – Generuoti naują failą
   * `2` – Naudoti esamą failą
   * `3` – Įvesti duomenis ranka
5. Sekite nurodymus (pasirinkite konteinerį, skaičiavimo tipą, strategiją ir rikiavimo kriterijų).

---

## Failų struktūra

```
projektas/
├── main.cpp
├── studentas.cpp
├── studentas.h
├── Makefile
├── README.md
├── data/
│   ├── studentai10000.txt
│   ├── studentai100000.txt
│   └── studentai1000000.txt
└── results/
    ├── vargsiukai.txt
    ├── kietuoliai.txt
    └── plotukas.png
```

---

## Strategijų aprašymas
| Strategija | Veiksmas su pradiniu konteineriu  | Naudojami STL algoritmai / operacijos                     | Atminties naudojimas | Laiko sudėtingumas |
| **1** | Pradinis konteineris nekeičiant kopijuojamas į du naujus |(paprasti ciklai, push_back)             | Didelis              | O(n)               |
| **2** | Elementai šalinami iš bendro konteinerio | erase (list), indeksinis perrašymas (vector)               | Vidutinis            | O(n)            |
| **3** | Optimizuotas skaidymas naudojant STL     | remove_if, remove_copy_if, stable_partition, splice        | Mažiausias           | O(n)            |


## Testavimo rezultatai

**Testuota su failais:**
`studentai10000.txt`, `studentai100000.txt`, `studentai1000000.txt`
Kiekvienas testas kartotas 3 kartus. Pateikiami tikslūs laikai (sekundėmis).

---

### Vector konteineris — studentai10000.txt

| Run | read      | sort       | split       | write      | total     |
| --- | --------- | ---------- | ----------- | ---------- | --------- |
| 1   | 0.0447909 | 0.0013065  | 0.00060525  | 0.00543504 | 0.0544515 |
| 2   | 0.0407063 | 0.00131004 | 0.000587292 | 0.00659954 | 0.0515177 |
| 3   | 0.0400109 | 0.00131763 | 0.00054825  | 0.00529546 | 0.0495114 |
| 1   | 0.039795  | 0.0013015  | 0.000420625 | 0.00546987 | 0.0492835 |
| 2   | 0.040007  | 0.00130075 | 0.00039575  | 0.00537208 | 0.0493765 |
| 3   | 0.0399404 | 0.00130067 | 0.000448167 | 0.00534438 | 0.0493425 |
| 1   | 0.0397807 | 0.00130638 | 0.000596041 | 0.00533275 | 0.0493194 |
| 2   | 0.0399709 | 0.00130833 | 0.000748292 | 0.00559383 | 0.0499338 |
| 3   | 0.0408472 | 0.00131742 | 0.000593917 | 0.00571158 | 0.050816  |


---

###List konteineris — studentai10000.txt

| Run | read      | sort        | split       | write      | total     |
| --- | --------- | ----------- | ----------- | ---------- | --------- |
| 1   | 0.0398718 | 0.000597875 | 0.000581958 | 0.00532963 | 0.0487219 |
| 2   | 0.0396846 | 0.000611792 | 0.00066625  | 0.0214571  | 0.064726  |
| 3   | 0.039462  | 0.000642167 | 0.000634291 | 0.00554333 | 0.0486043 |
| 1   | 0.0396545 | 0.000625208 | 0.000406959 | 0.00533308 | 0.0483463 |
| 2   | 0.0399086 | 0.000605333 | 0.000425375 | 0.00561017 | 0.0488876 |
| 3   | 0.0397465 | 0.000624041 | 0.000408459 | 0.00560646 | 0.0487081 |
| 1   | 0.0393052 | 0.0006335   | 0.000075    | 0.00541525 | 0.0477405 |
| 2   | 0.0402215 | 0.000619958 | 0.000074541 | 0.00532925 | 0.0485455 |
| 3   | 0.039508  | 0.000594458 | 0.000079875 | 0.00534837 | 0.0478703 |


---

### Vector konteineris — studentai100000.txt

| Bandymas | read     | sort      | split      | write     | total    |
| -------- | -------- | --------- | ---------- | --------- | -------- |
| 1        | 0.51782  | 0.0161393 | 0.00764017 | 0.0481774 | 0.620821 |
| 2        | 0.498193 | 0.0161379 | 0.00854617 | 0.0554655 | 0.609095 |
| 3        | 0.491667 | 0.0161137 | 0.00717796 | 0.0469067 | 0.592165 |
| 1        | 0.492318 | 0.0161051 | 0.00400762 | 0.0473133 | 0.589907 |
| 2        | 0.502788 | 0.0162549 | 0.00415275 | 0.0467708 | 0.600684 |
| 3        | 0.506298 | 0.016173  | 0.00406892 | 0.0471822 | 0.604177 |
| 1        | 0.504219 | 0.0161212 | 0.00699933 | 0.0505474 | 0.608104 |
| 2        | 0.49995  | 0.0161415 | 0.00728267 | 0.047344  | 0.600919 |
| 3        | 0.500013 | 0.0162258 | 0.00665908 | 0.0473683 | 0.600398 |

---

### List konteineris — studentai100000.txt

| Bandymas | read     | sort       | split      | write     | total    |
| -------- | -------- | ---------- | ---------- | --------- | -------- |
| 1        | 0.498011 | 0.00915738 | 0.00638092 | 0.0476134 | 0.592003 |
| 2        | 0.502417 | 0.00789737 | 0.0063355  | 0.0479673 | 0.595186 |
| 3        | 0.499068 | 0.00785492 | 0.00615408 | 0.0482479 | 0.591857 |
| 1        | 0.502557 | 0.00905925 | 0.00483129 | 0.0469073 | 0.593758 |
| 2        | 0.504308 | 0.00888737 | 0.004778   | 0.0473574 | 0.596147 |
| 3        | 0.502692 | 0.00842821 | 0.00481483 | 0.047133  | 0.593785 |
| 1        | 0.500716 | 0.00845575 | 0.000786125| 0.046711  | 0.587247 |
| 2        | 0.506183 | 0.00884621 | 0.000785375| 0.0479742 | 0.594658 |
| 3        | 0.506068 | 0.00782254 | 0.000792333| 0.047133  | 0.592832 |

---

### Vector konteineris — studentai1000000.txt

| Bandymas | read    | sort     | split     | write    | total   |
| -------- | ------- | -------- | --------- | -------- | ------- |
| 1        | 3.11131 | 0.186825 | 0.0828276 | 0.47079  | 4.08959 |
| 2        | 2.51351 | 0.171063 | 0.0779357 | 0.459184 | 3.3323  |
| 3        | 2.47488 | 0.170372 | 0.07843   | 0.458599 | 3.29083 |
| Bandymas | read    | sort     | split     | write    | total   |
| -------- | ------- | -------- | --------- | -------- | ------- |
| 1        | 2.47015 | 0.171408 | 0.0387484 | 0.457934 | 3.2482  |
| 2        | 2.47337 | 0.171231 | 0.0387698 | 0.4547   | 3.24648 |
| 3        | 2.50332 | 0.171083 | 0.0388096 | 0.45525  | 3.27733 |
| Bandymas | read    | sort     | split     | write    | total   |
| -------- | ------- | -------- | --------- | -------- | ------- |
| 1        | 2.50619 | 0.170471 | 0.0603332 | 0.460864 | 3.30546 |
| 2        | 2.51629 | 0.171571 | 0.060434  | 0.458571 | 3.31671 |
| 3        | 2.5008  | 0.170766 | 0.0607156 | 0.462842 | 3.30523 |



---

###List konteineris — studentai1000000.txt
| Bandymas | read    | sort     | split     | write    | total   |
| -------- | ------- | -------- | --------- | -------- | ------- |
| 1        | 2.46526 | 0.092585 | 0.0617778 | 0.458283 | 3.19078 |
| 2        | 2.45635 | 0.102082 | 0.0604711 | 0.460257 | 3.19255 |
| 3        | 2.44234 | 0.092733 | 0.0661261 | 0.465773 | 3.17713 |
| 1        | 2.43015 | 0.0848369| 0.0434126 | 0.458144 | 3.12761 |
| 2        | 2.44552 | 0.101877 | 0.0448305 | 0.452067 | 3.15618 |
| 3        | 2.40576 | 0.0924986| 0.0440405 | 0.455808 | 3.10936 |
| 1        | 2.44956 | 0.0977974| 0.00903075| 0.455922 | 3.12309 |
| 2        | 2.44839 | 0.0877277| 0.00795854| 0.464209 | 3.11764 |
| 3        | 2.45953 | 0.0994346| 0.00924646| 0.464743 | 3.14346 |


---

## Rezultatų analizė

### Pagrindinės įžvalgos

* Skirtumai tarp strategijų nėra dideli, nes **disko nuskaitymas ir įrašymas** sudaro ~90 % viso vykdymo laiko.
* Kompiliatoriaus `-O2` optimizacijos ir STL algoritmai (`remove_if`, `partition_copy`, `splice`) dirba itin efektyviai.
* `std::list` teoriškai turi pranašumą trynimo operacijose, bet dėl **cache locality** efektyvumo `std::vector` dažnai veikia greičiau.
* Strategijos **2 ir 3** pasirodė efektyviausios, nes išvengiama perteklinio kopijavimo.

### Išvados

* **Vector + strategija 2** pasižymėjo geriausiu santykiu tarp spartos ir atminties naudojimo.
* **List + strategija 2 ar 3** veikė stabiliai, bet be žymaus pranašumo.
* Skirtumai tarp konteinerių mažėjo didėjant duomenų kiekiui dėl I/O dominavimo.
* Norint pamatyti ryškesnius algoritmų skirtumus, reikėtų testuoti tik **rikiavimo ir skaidymo etapus**, be failų skaitymo/rašymo.

---

## Naudoti STL algoritmai

Rikiavimui:

std::sort

std::stable_sort 

Skaidymui / filtravimui:

std::remove_if

std::remove_copy_if

std::stable_partition

Kopijavimui / pernešimui:

std::move

std::make_move_iterator

List operacijoms:

std::list::erase

std::list::splice

Pagalbiniams veiksmams:

std::back_inserter

std::replace

std::next
---

## Papildoma informacija

* Programos veikimas **nepriklauso nuo interneto**.
* Testuota **macOS 14.5 (Apple M1, 8 GB RAM)**, `g++ 13.2`.
* Vidutinė veikimo sparta apskaičiuota pagal 3 kartotinius testus kiekvienai strategijai ir konteineriui.


