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

### 10000 studentų

| Bandymas | Konteineris | Nuskaitymas (s) | Rikiavimas (s) | Skirstymas (s) | Įrašymas (s) | Bendras (s) |
|-----------|--------------|------------------|-----------------|----------------|---------------|--------------|
| 1 | vector | 0.175591 | 0.0115464 | 0.00474875 | 0.00867858 | 0.227076 |
| 2 | vector | 0.17568 | 0.0115464 | 0.00456754 | 0.0103163 | 0.228851 |
| 3 | vector | 0.17513 | 0.0115297 | 0.00456187 | 0.0100867 | 0.227954 |
| 4 | vector | 0.176823 | 0.0115283 | 0.00496588 | 0.00963508 | 0.229234 |
| 5 | vector | 0.174953 | 0.0115517 | 0.00451067 | 0.00968696 | 0.227201 |
| **Vidurkis** | **vector** | **0.1756354** | **0.0115405** | **0.00461694** | **0.00968072** | **0.2280632** |

| Bandymas | Konteineris | Nuskaitymas (s) | Rikiavimas (s) | Skirstymas (s) | Įrašymas (s) | Bendras (s) |
|-----------|--------------|------------------|-----------------|----------------|---------------|--------------|
| 1 | list | 0.164867 | 0.00487642 | 0.00403167 | 0.0102722 | 0.211752 |
| 2 | list | 0.171591 | 0.0049 | 0.00418758 | 0.00983054 | 0.218426 |
| 3 | list | 0.169788 | 0.00491575 | 0.00413113 | 0.0111506 | 0.218175 |
| 4 | list | 0.168597 | 0.00488942 | 0.00437563 | 0.00962504 | 0.215345 |
| 5 | list | 0.169231 | 0.00489871 | 0.00406117 | 0.0102132 | 0.216657 |
| **Vidurkis** | **list** | **0.1688148** | **0.00489606** | **0.00415744** | **0.01021832** | **0.2160536** |



### Failas: studentai100000.txt

| Bandymas | Konteineris | Nuskaitymas (s) | Rikiavimas (s) | Skirstymas (s) | Įrašymas (s) | Bendras (s) |
|-----------|--------------|------------------|-----------------|----------------|---------------|--------------|
| 1 | vector | 1.95496 | 0.109588 | 0.0565428 | 0.0738203 | 2.56237 |
| 2 | vector | 1.96168 | 0.110407 | 0.0572812 | 0.074156 | 2.57102 |
| 3 | vector | 1.95086 | 0.109805 | 0.0580786 | 0.0736433 | 2.56073 |
| 4 | vector | 1.95553 | 0.109861 | 0.0562749 | 0.0715375 | 2.56018 |
| 5 | vector | 1.95827 | 0.110345 | 0.056764 | 0.0742126 | 2.56623 |
| **Vidurkis** | **vector** | **1.95626** | **0.1100012** | **0.0569883** | **0.07347394** | **2.564106** |
| Bandymas | Konteineris | Nuskaitymas (s) | Rikiavimas (s) | Skirstymas (s) | Įrašymas (s) | Bendras (s) |
|-----------|--------------|------------------|-----------------|----------------|---------------|--------------|
| 1 | list | 1.90264 | 0.059831 | 0.0428828 | 0.0768214 | 2.45718 |
| 2 | list | 1.90017 | 0.0587782 | 0.0428805 | 0.0735481 | 2.44845 |
| 3 | list | 1.89771 | 0.059216 | 0.0429826 | 0.0768972 | 2.45478 |
| 4 | list | 1.89742 | 0.0585392 | 0.0429447 | 0.0733745 | 2.44284 |
| 5 | list | 1.90709 | 0.0596722 | 0.0430569 | 0.0752584 | 2.4614 |
| **Vidurkis** | **list** | **1.901006** | **0.05920732** | **0.0429495** | **0.07525402** | **2.45293** |

### Failas: studentai1000000.txt

| Bandymas | Konteineris | Nuskaitymas (s) | Rikiavimas (s) | Skirstymas (s) | Įrašymas (s) | Bendras (s) |
|-----------|--------------|------------------|-----------------|----------------|---------------|--------------|
| 1 | vector | 10.8458 | 0.931456 | 0.615147 | 0.709413 | 14.5719 |
| 2 | vector | 10.8512 | 0.930616 | 0.612778 | 0.695331 | 14.5539 |
| 3 | vector | 10.8646 | 0.930977 | 0.613725 | 0.70119 | 14.5792 |
| 4 | vector | 10.851 | 0.931184 | 0.611117 | 0.702762 | 14.5599 |
| 5 | vector | 10.8507 | 0.931353 | 0.600573 | 0.6836 | 14.5361 |
| **Vidurkis** | **vector** | **10.85266** | **0.9311172** | **0.610668** | **0.6984592** | **14.5602** |

| Bandymas | Konteineris | Nuskaitymas (s) | Rikiavimas (s) | Skirstymas (s) | Įrašymas (s) | Bendras (s) |
|-----------|--------------|------------------|-----------------|----------------|---------------|--------------|
| 1 | list | 6.35973 | 0.612782 | 0.280037 | 0.447591 | 8.6879 |
| 2 | list | 6.38003 | 0.596525 | 0.274064 | 0.435851 | 8.6753 |
| 3 | list | 6.36701 | 0.61063 | 0.277318 | 0.442935 | 8.68168 |
| 4 | list | 6.35428 | 0.614099 | 0.277986 | 0.439055 | 8.67452 |
| 5 | list | 6.36034 | 0.613786 | 0.278289 | 0.43717 | 8.67651 |
| **Vidurkis** | **list** | **6.364278** | **0.6095644** | **0.277538** | **0.4406104** | **8.679218** |


## Aritmetinio vidurkio formulė

Kiekvienos eilutės vidurkis skaičiuojamas taip:

\[
\text{Vidurkis} = \frac{t_1 + t_2 + t_3 + t_4 + t_5}{5}
\]

Kur \( t_i \) — kiekvieno bandymo rezultatas sekundėmis.

##IŠVADOS
- Mažiems duomenų kiekiams (`10 000`) skirtumas tarp `vector` ir `list` minimalus.  
- Didėjant duomenų apimčiai (`100 000–1 000 000`), `std::list` tampa spartesnis.  
- IO (failų nuskaitymas ir įrašymas) sudaro daugiau nei 70 % viso vykdymo laiko.  
- Abiejų konteinerių augimas atitinka **O(n log n)**.  
- Su 1 000 000 įrašų `list` yra apie **40 % greitesnis** už `vector`.
