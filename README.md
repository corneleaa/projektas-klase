#Konteinerių testavimas (v0.3)

##Užduoties tikslas
Ištirti patobulintos programos veikimo spartą priklausomai nuo naudojamo konteinerio tipo:
- `std::vector<Studentas>`
- `std::list<Studentas>`
### Tiriamieji žingsniai:
1. Studentų duomenų **nuskaitymas** iš failo.  
2. Studentų **rūšiavimas** pagal pasirinktą kriterijų.  
3. Studentų **skirstymas** į dvi grupes (kieti ir vargšai).  
4. Rezultatų **įrašymas** į failus.  
5. Laikų palyginimas tarp `vector` ir `list`.

---

##Testavimo aplinka

| Parametras | Aprašymas |
|-------------|------------|
| Kompiuteris | MacBook Air (M1, 2020) |
| Procesorius (CPU / Chip) | Apple M1 |
| Atmintis (RAM) | 8 GB |
| Diskas | 245 GB SSD |
| Operacinė sistema | macOS Sequoia 15.5 |
| Kompiliatorius | Xcode (Clang++) |
| Optimizacijos lygis | -O2 (numatytas Xcode projekto) |

---

## Testavimo duomenys
Naudoti dėstytojo pateikti failai:
studentai10000.txt
studentai100000.txt
studentai1000000.txt
##Testavimo rezultatai

Testai atlikti su 3 skirtingais duomenų failais (`studentai10000.txt`, `studentai100000.txt`, `studentai1000000.txt`), kiekvienas paleistas **5 kartus** abiem konteinerių tipams (`std::vector` ir `std::list`).

### Failas: studentai10000.txt

| Bandymas | Konteineris | Nuskaitymas (s) | Rikiavimas (s) | Skirstymas (s) | Įrašymas (s) | Bendras (s) |
|-----------|--------------|------------------|-----------------|----------------|---------------|--------------|
| 1 | vector |  |  |  |  |  |
| 2 | vector |  |  |  |  |  |
| 3 | vector |  |  |  |  |  |
| 4 | vector |  |  |  |  |  |
| 5 | vector |  |  |  |  |  |
| **Vidurkis** | **vector** | **(∑/5)** | **(∑/5)** | **(∑/5)** | **(∑/5)** | **(∑/5)** |
| 1 | list |  |  |  |  |  |
| 2 | list |  |  |  |  |  |
| 3 | list |  |  |  |  |  |
| 4 | list |  |  |  |  |  |
| 5 | list |  |  |  |  |  |
| **Vidurkis** | **list** | **(∑/5)** | **(∑/5)** | **(∑/5)** | **(∑/5)** | **(∑/5)** |


### Failas: studentai100000.txt

| Bandymas | Konteineris | Nuskaitymas (s) | Rikiavimas (s) | Skirstymas (s) | Įrašymas (s) | Bendras (s) |
|-----------|--------------|------------------|-----------------|----------------|---------------|--------------|
| 1 | vector |  |  |  |  |  |
| 2 | vector |  |  |  |  |  |
| 3 | vector |  |  |  |  |  |
| 4 | vector |  |  |  |  |  |
| 5 | vector |  |  |  |  |  |
| **Vidurkis** | **vector** | **(∑/5)** | **(∑/5)** | **(∑/5)** | **(∑/5)** | **(∑/5)** |
| 1 | list |  |  |  |  |  |
| 2 | list |  |  |  |  |  |
| 3 | list |  |  |  |  |  |
| 4 | list |  |  |  |  |  |
| 5 | list |  |  |  |  |  |
| **Vidurkis** | **list** | **(∑/5)** | **(∑/5)** | **(∑/5)** | **(∑/5)** | **(∑/5)** |


### Failas: studentai1000000.txt

| Bandymas | Konteineris | Nuskaitymas (s) | Rikiavimas (s) | Skirstymas (s) | Įrašymas (s) | Bendras (s) |
|-----------|--------------|------------------|-----------------|----------------|---------------|--------------|
| 1 | vector |  |  |  |  |  |
| 2 | vector |  |  |  |  |  |
| 3 | vector |  |  |  |  |  |
| 4 | vector |  |  |  |  |  |
| 5 | vector |  |  |  |  |  |
| **Vidurkis** | **vector** | **(∑/5)** | **(∑/5)** | **(∑/5)** | **(∑/5)** | **(∑/5)** |
| 1 | list |  |  |  |  |  |
| 2 | list |  |  |  |  |  |
| 3 | list |  |  |  |  |  |
| 4 | list |  |  |  |  |  |
| 5 | list |  |  |  |  |  |
| **Vidurkis** | **list** | **(∑/5)** | **(∑/5)** | **(∑/5)** | **(∑/5)** | **(∑/5)** |


## Aritmetinio vidurkio formulė

Kiekvienos eilutės vidurkis skaičiuojamas taip:

\[
\text{Vidurkis} = \frac{t_1 + t_2 + t_3 + t_4 + t_5}{5}
\]

Kur \( t_i \) — kiekvieno bandymo rezultatas sekundėmis.




