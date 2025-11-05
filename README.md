# Studentų rūšiavimo optimizavimas (v1.1)

## Projekto aprašymas

Ši programos versija (**v1.1**) sukurta remiantis ankstesne `v1.0` struktūros (`struct`) realizacija, tačiau šįkart vietoje struktūros naudojama **pilnavertė klasė `Studentas`**.

Programos tikslas – **įvertinti klasės realizacijos įtaką veikimo spartai** ir **palyginti kompiliatoriaus optimizavimo lygių (`-O1`, `-O2`, `-O3`)** poveikį tiek veikimo greičiui, tiek `.exe` failo dydžiui.

---

## Funkcionalumas

Programa leidžia:

1. Nuskaityti ar sugeneruoti studentų duomenis;
2. Skaičiuoti galutinį balą (vidurkis / mediana);
3. Rikiuoti pagal vardą, pavardę ar galutinį balą;
4. Padalyti į dvi grupes — **vargšiukai** (<5) ir **kietuoliai** (≥5);
5. Palaiko konteinerius: `std::vector` ir `std::list`;
6. Realizuotos trys strategijos (1 – A+B, 2 – trynimas, 3 – optimizuota).

---

## Testavimo sąlygos

* Failai: `studentai10000.txt`, `studentai100000.txt`, `studentai1000000.txt`
* Testuota po **3 kartus kiekvienam dydžiui**
* Naudotas **vienas konteineris (`std::vector`)** ir **3-ioji strategija (optimizuota)**
* Kompiliatorius: `g++ (C++17)`
* OS: macOS / Linux / Windows

---

## Palyginimas: `struct` vs `class` (strategija 3, vector, po 3 bandymus, vektoriai)

| Versija | Studentų skaičius | Bandymas 1 (s) | Bandymas 2 (s) | Bandymas 3 (s) | Vidurkis (s) |
| ------- | ----------------- | -------------- | -------------- | -------------- | ------------ |
| struct  | 10000             |0.225143        |    0.210888    |     0.221631   |              |
| class   | 10000             |                |                |                |              |
| struct  | 100000            |  2.53069       |  2.52087       |      2.52123   |              |
| class   | 100000            |                |                |                |              |
| struct  | 1000000           | 14.1           |    14.1158     | 14.1311        |              |
| class   | 1000000           |                |                |                |              |

**Išvada:**


---

## Kompiliatoriaus optimizavimo flagų analizė (`-O1`, `-O2`, `-O3`)

Naudota **klasės (class)** versija, 1 000 000 studentų, strategija 3.

| Optimizavimo flagas | Bandymas 1 (s) | Bandymas 2 (s) | Bandymas 3 (s) | Vidurkis (s) | EXE dydis (KB) |
| ------------------- | -------------- | -------------- | -------------- | ------------ | -------------- |
| -O1                 |                |                |                |              |                |
| -O2                 |                |                |                |              |                |
| -O3                 |                |                |                |              |                |
**Išvada:**


---

## Techninė aplinka

| Parametras     | Reikšmė                                                     |
| -------------- | ----------------------------------------------------------- |
| CPU            | Apple M1 / Intel i5 / kt.                                   |
| RAM            | 8 GB                                                        |
| OS             | macOS 13.5 / Windows 11 / Ubuntu 24.04                      |
| Kompiliatorius | g++ 13.1.0 (C++17)                                          |
| Build flags    | `-std=c++17 -O3`                                            |
| Failų kiekis   | 4 (`main.cpp`, `Studentas.cpp`, `Studentas.h`, `mediana.h`) |

---

## Išvados


---

## Versijų istorija

| Versija | Aprašas            | Pakeitimai                                               |
| ------- | ------------------ | -------------------------------------------------------- |
| v1.0    | Struct realizacija | Studentų rūšiavimas naudojant `struct`                   |
| v1.1    | Class realizacija  | Naudojama `class Studentas`, destruktorius, flag analizė |

---

## Repozitorijos informacija


---
