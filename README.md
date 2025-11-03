# Studentų rūšiavimo optimizavimas (v1.0)
## Projekto aprašymas

Ši programa skirta **studentų duomenų nuskaitymui, rikiavimui ir dalijimui į dvi kategorijas** – „vargšiukus“ (galutinis < 5) ir „kietuolius“ (galutinis ≥ 5).
Tyrimo tikslas – **įvertinti programos spartos priklausomybę** nuo:

1. **Naudojamo konteinerio tipo:** `std::vector` ir `std::list`
2. **Naudotos skaidymo strategijos:**

   * **1 strategija:** Du nauji konteineriai
   * **2 strategija:** Vienas naujas konteineris („vargšiukai“)
   * **3 strategija:** Optimizuota greičiausia versija naudojant STL algoritmus

---

## Naudojimosi instrukcija

1. Atsidarykite terminalą (arba CMD, jei Windows).
2. Sukompiliuokite programą:

   ```bash
   make
   ```

   arba naudokite CMake:

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
   * `3` – Įvesti studentus ranka
5. Toliau sekite ekrano nurodymus (pasirinkite konteinerį, skaičiavimo tipą, strategiją ir rikiavimo kriterijų).

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
│   ├── studentai1000.txt
│   ├── studentai10000.txt
│   └── studentai100000.txt
└── results/
    ├── vargsiukai.txt
    ├── kietuoliai.txt
    └── plotukas.png
```

---

## Strategijų aprašymas

| Strategija | Aprašymas                                                                    | Pagrindiniai algoritmai                           | Atminties naudojimas          |
| ---------- | ---------------------------------------------------------------------------- | ------------------------------------------------- | ----------------------------- |
| **1**      | Kuriami du nauji konteineriai – „vargšiukai“ ir „kietuoliai“.                | `std::partition_copy`                             | Didelis (dubluojami duomenys) |
| **2**      | Kuriamas tik „vargšiukų“ konteineris, iš bendro pašalinami silpni studentai. | `std::partition`, `erase`, `splice`               | Vidutinis                     |
| **3**      | Optimizuota versija naudojant efektyvius STL metodus.                        | `remove_if`, `remove_copy_if`, `stable_partition` | Mažiausias                    |

---

## Testavimo rezultatai

**Testuota su failais:**
`studentai1000.txt`, `studentai10000.txt`, `studentai100000.txt`

Kiekvienas testas kartotas **5 kartus**, pateikiami vidurkiai.

### Vector konteineris studentai10000.txt

| Bandymas | Strategija | Nuskaitymas (s) | Rikiavimas (s) | Skirstymas (s) | Įrašymas (s) | Bendras (s) |
| -------- | ---------- | --------------- | -------------- | -------------- | ------------ | ----------- |
| 1        | 1          | 0.176802        | 0.011733       | 0.00497833     | 0.00949354   | 0.225143    |
| 2        | 1          | ...             | ...            | ...            | ...          | ...         |
| 3        | 1          | ...             | ...            | ...            | ...          | ...         |

### List konteineris studentai10000.txt

| Bandymas | Strategija | Nuskaitymas (s) | Rikiavimas (s) | Skirstymas (s) | Įrašymas (s) | Bendras (s) |
| -------- | ---------- | --------------- | -------------- | -------------- | ------------ | ----------- |
| 1        | 1          | ...             | ...            | ...            | ...          | ...         |
| 2        | 1          | ...             | ...            | ...            | ...          | ...         |
| 3        | 1          | ...             | ...            | ...            | ...          | ...         |

### Vector konteineris studentai10000.txt

| Bandymas | Strategija | Nuskaitymas (s) | Rikiavimas (s) | Skirstymas (s) | Įrašymas (s) | Bendras (s) |
| -------- | ---------- | --------------- | -------------- | -------------- | ------------ | ----------- |
| 1        | 2          | ...             | ...            | ...            | ...          | ...         |
| 2        | 2          | ...             | ...            | ...            | ...          | ...         |
| 3        | 2          | ...             | ...            | ...            | ...          | ...         |

### List konteineris studentai10000.txt

| Bandymas | Strategija | Nuskaitymas (s) | Rikiavimas (s) | Skirstymas (s) | Įrašymas (s) | Bendras (s) |
| -------- | ---------- | --------------- | -------------- | -------------- | ------------ | ----------- |
| 1        | 2          | ...             | ...            | ...            | ...          | ...         |
| 2        | 2          | ...             | ...            | ...            | ...          | ...         |
| 3        | 2          | ...             | ...            | ...            | ...          | ...         |

###Vector konteineris studentai10000.txt

| Bandymas | Strategija | Nuskaitymas (s) | Rikiavimas (s) | Skirstymas (s) | Įrašymas (s) | Bendras (s) |
| -------- | ---------- | --------------- | -------------- | -------------- | ------------ | ----------- |
| 1        | 3          | ...             | ...            | ...            | ...          | ...         |
| 2        | 3          | ...             | ...            | ...            | ...          | ...         |
| 3        | 3          | ...             | ...            | ...            | ...          | ...         |

### List konteineris studentai10000.txt

| Bandymas | Strategija | Nuskaitymas (s) | Rikiavimas (s) | Skirstymas (s) | Įrašymas (s) | Bendras (s) |
| -------- | ---------- | --------------- | -------------- | -------------- | ------------ | ----------- |
| 1        | 3          | ...             | ...            | ...            | ...          | ...         |
| 2        | 3          | ...             | ...            | ...            | ...          | ...         |
| 3        | 3          | ...             | ...            | ...            | ...          | ...         |
### Vector konteineris studentai100000.txt

| Bandymas | Strategija | Nuskaitymas (s) | Rikiavimas (s) | Skirstymas (s) | Įrašymas (s) | Bendras (s) |
| -------- | ---------- | --------------- | -------------- | -------------- | ------------ | ----------- |
| 1        | 1          | ...             | ...            | ...            | ...          | ...         |
| 2        | 1          | ...             | ...            | ...            | ...          | ...         |
| 3        | 1          | ...             | ...            | ...            | ...          | ...         |

### List konteineris studentai100000.txt

| Bandymas | Strategija | Nuskaitymas (s) | Rikiavimas (s) | Skirstymas (s) | Įrašymas (s) | Bendras (s) |
| -------- | ---------- | --------------- | -------------- | -------------- | ------------ | ----------- |
| 1        | 1          | ...             | ...            | ...            | ...          | ...         |
| 2        | 1          | ...             | ...            | ...            | ...          | ...         |
| 3        | 1          | ...             | ...            | ...            | ...          | ...         |

### Vector konteineris studentai100000.txt

| Bandymas | Strategija | Nuskaitymas (s) | Rikiavimas (s) | Skirstymas (s) | Įrašymas (s) | Bendras (s) |
| -------- | ---------- | --------------- | -------------- | -------------- | ------------ | ----------- |
| 1        | 2          | ...             | ...            | ...            | ...          | ...         |
| 2        | 2          | ...             | ...            | ...            | ...          | ...         |
| 3        | 2          | ...             | ...            | ...            | ...          | ...         |

### List konteineris studentai100000.txt

| Bandymas | Strategija | Nuskaitymas (s) | Rikiavimas (s) | Skirstymas (s) | Įrašymas (s) | Bendras (s) |
| -------- | ---------- | --------------- | -------------- | -------------- | ------------ | ----------- |
| 1        | 2          | ...             | ...            | ...            | ...          | ...         |
| 2        | 2          | ...             | ...            | ...            | ...          | ...         |
| 3        | 2          | ...             | ...            | ...            | ...          | ...         |

###Vector konteineris studentai100000.txt

| Bandymas | Strategija | Nuskaitymas (s) | Rikiavimas (s) | Skirstymas (s) | Įrašymas (s) | Bendras (s) |
| -------- | ---------- | --------------- | -------------- | -------------- | ------------ | ----------- |
| 1        | 3          | ...             | ...            | ...            | ...          | ...         |
| 2        | 3          | ...             | ...            | ...            | ...          | ...         |
| 3        | 3          | ...             | ...            | ...            | ...          | ...         |

### List konteineris studentai100000.txt

| Bandymas | Strategija | Nuskaitymas (s) | Rikiavimas (s) | Skirstymas (s) | Įrašymas (s) | Bendras (s) |
| -------- | ---------- | --------------- | -------------- | -------------- | ------------ | ----------- |
| 1        | 3          | ...             | ...            | ...            | ...          | ...         |
| 2        | 3          | ...             | ...            | ...            | ...          | ...         |
| 3        | 3          | ...             | ...            | ...            | ...          | ...         |
### Vector konteineris studentai1000000.txt

| Bandymas | Strategija | Nuskaitymas (s) | Rikiavimas (s) | Skirstymas (s) | Įrašymas (s) | Bendras (s) |
| -------- | ---------- | --------------- | -------------- | -------------- | ------------ | ----------- |
| 1        | 1          | ...             | ...            | ...            | ...          | ...         |
| 2        | 1          | ...             | ...            | ...            | ...          | ...         |
| 3        | 1          | ...             | ...            | ...            | ...          | ...         |

### List konteineris studentai1000000.txt

| Bandymas | Strategija | Nuskaitymas (s) | Rikiavimas (s) | Skirstymas (s) | Įrašymas (s) | Bendras (s) |
| -------- | ---------- | --------------- | -------------- | -------------- | ------------ | ----------- |
| 1        | 1          | ...             | ...            | ...            | ...          | ...         |
| 2        | 1          | ...             | ...            | ...            | ...          | ...         |
| 3        | 1          | ...             | ...            | ...            | ...          | ...         |

### Vector konteineris studentai1000000.txt

| Bandymas | Strategija | Nuskaitymas (s) | Rikiavimas (s) | Skirstymas (s) | Įrašymas (s) | Bendras (s) |
| -------- | ---------- | --------------- | -------------- | -------------- | ------------ | ----------- |
| 1        | 2          | ...             | ...            | ...            | ...          | ...         |
| 2        | 2          | ...             | ...            | ...            | ...          | ...         |
| 3        | 2          | ...             | ...            | ...            | ...          | ...         |

### List konteineris studentai1000000.txt

| Bandymas | Strategija | Nuskaitymas (s) | Rikiavimas (s) | Skirstymas (s) | Įrašymas (s) | Bendras (s) |
| -------- | ---------- | --------------- | -------------- | -------------- | ------------ | ----------- |
| 1        | 2          | ...             | ...            | ...            | ...          | ...         |
| 2        | 2          | ...             | ...            | ...            | ...          | ...         |
| 3        | 2          | ...             | ...            | ...            | ...          | ...         |

###Vector konteineris studentai1000000.txt

| Bandymas | Strategija | Nuskaitymas (s) | Rikiavimas (s) | Skirstymas (s) | Įrašymas (s) | Bendras (s) |
| -------- | ---------- | --------------- | -------------- | -------------- | ------------ | ----------- |
| 1        | 3          | ...             | ...            | ...            | ...          | ...         |
| 2        | 3          | ...             | ...            | ...            | ...          | ...         |
| 3        | 3          | ...             | ...            | ...            | ...          | ...         |

### List konteineris studentai1000000.txt

| Bandymas | Strategija | Nuskaitymas (s) | Rikiavimas (s) | Skirstymas (s) | Įrašymas (s) | Bendras (s) |
| -------- | ---------- | --------------- | -------------- | -------------- | ------------ | ----------- |
| 1        | 3          | ...             | ...            | ...            | ...          | ...         |
| 2        | 3          | ...             | ...            | ...            | ...          | ...         |
| 3        | 3          | ...             | ...            | ...            | ...          | ...         |


---



---

##Naudoti STL algoritmai

`std::partition`, `std::partition_copy`, `std::stable_partition`,
`std::remove_if`, `std::remove_copy_if`, `std::move`, `std::sort`, `std::splice`.

---

##Papildoma informacija

* Programos veikimas **nepriklauso nuo interneto**.
* Testuota **macOS 14.5 (Apple M1, 8 GB RAM)**, `g++ 13.2`.
* Vidutinė veikimo sparta skaičiuota pagal 5 bandymus kiekvienai strategijai.

