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
| 1 | vector | 0.176164 | 0.0115395 | 0.00454175 | 0.066489 | 0.287222 |
| 2 | vector | 0.177578 | 0.011521 | 0.00468088 | 0.057938 | 0.278407 |
| 3 | vector | 0.175495 | 0.0115523 | 0.00445967 | 0.058606 | 0.276468 |
| 4 | vector | 0.172633 | 0.0115318 | 0.0044435  | 0.0570628 | 0.272149 |
| 5 | vector | 0.168244 | 0.011527  | 0.00458083 | 0.0579526 | 0.268913 |
| **Vidurkis** | **vector** | **0.1740228** | **0.01153432** | **0.00453963** | **0.0595006** | **0.27398425** |

| Bandymas | Konteineris | Nuskaitymas (s) | Rikiavimas (s) | Skirstymas (s) | Įrašymas (s) | Bendras (s) |
|-----------|--------------|------------------|-----------------|----------------|---------------|--------------|
| 1 | list | 0.1702 | 0.00489225 | 0.00409671 | 0.0624868 | 0.269579 |
| 2 | list | 0.168708 | 0.00501942 | 0.00403371 | 0.0586325 | 0.264649 |
| 3 | list | 0.170296 | 0.00490538 | 0.00407596 | 0.0587871 | 0.266035 |
| 4 | list | 0.16722 | 0.00494087 | 0.00397054 | 0.0580231 | 0.262445 |
| 5 | list | 0.16936 | 0.00492696 | 0.00416563 | 0.0605676 | 0.267616 |
| **Vidurkis** | **list** | **0.1691568** | **0.00493698** | **0.00406851** | **0.05969942** | **0.2660648** |



### Failas: studentai100000.txt

| Bandymas | Konteineris | Nuskaitymas (s) | Rikiavimas (s) | Skirstymas (s) | Įrašymas (s) | Bendras (s) |
|-----------|--------------|------------------|-----------------|----------------|---------------|--------------|
| 1 | vector | 1.94908 | 0.109441 | 0.0565124 | 0.743198 | 3.22701 |
| 2 | vector | 1.95463 | 0.109684 | 0.0568226 | 0.746689 | 3.23878 |
| 3 | vector | 1.95114 | 0.109568 | 0.0562744 | 0.747968 | 3.23365 |
| 4 | vector | 1.95353 | 0.109662 | 0.0562695 | 0.74455 | 3.23374 |
| 5 | vector | 1.95338 | 0.109681 | 0.0566496 | 0.772025 | 3.26356 |
| **Vidurkis** | **vector** | **1.952352** | **0.1096072** | **0.0565057** | **0.750886** | **3.239348** |
| 1 | list | 1.89887 | 0.059584 | 0.0440166 | 0.748445 | 3.1304 |
| 2 | list | 1.9003 | 0.0587617 | 0.0440044 | 0.74726 | 3.12653 |
| 3 | list | 1.8997 | 0.0612681 | 0.0437534 | 0.746813 | 3.12964 |
| 4 | list | 1.90076 | 0.0592625 | 0.0438078 | 0.745134 | 3.12519 |
| 5 | list | 1.89741 | 0.0589034 | 0.043041 | 0.746052 | 3.12291 |
| **Vidurkis** | **list** | **1.899408** | **0.05955594** | **0.04371726** | **0.7467408** | **3.126934** |


### Failas: studentai1000000.txt

| Bandymas | Konteineris | Nuskaitymas (s) | Rikiavimas (s) | Skirstymas (s) | Įrašymas (s) | Bendras (s) |
|-----------|--------------|------------------|-----------------|----------------|---------------|--------------|
| 1 | vector | 10.7494 | 0.930908 | 0.619063 | 3.47389 | 17.2934 |
| 2 | vector | 10.7496 | 0.931063 | 0.602372 | 3.48105 | 17.2512 |
| 3 | vector | 10.7689 | 0.9312 | 0.606412 | 3.48558 | 17.2742 |
| 4 | vector | 10.8101 | 0.931261 | 0.612848 | 3.50717 | 17.3557 |
| 5 | vector | 10.7401 | 0.931087 | 0.60758 | 3.50226 | 17.2681 |
| **Vidurkis** | **vector** | **10.76362** | **0.9311038** | **0.609655** | **3.48999** | **17.28852** |
| 1 | list | 10.3531 | 1.00843 | 0.423754 | 3.55158 | 16.9467 |
| 2 | list | 10.3377 | 0.924937 | 0.422754 | 3.54984 | 16.8326 |
| 3 | list | 10.3545 | 0.944997 | 0.42487 | 3.54099 | 16.8594 |
| 4 | list | 10.359 | 0.900489 | 0.429727 | 3.66561 | 16.9791 |
| 5 | list | 10.372 | 0.970854 | 0.42546 | 3.5222 | 16.8785 |
| **Vidurkis** | **list** | **10.35526** | **0.9499414** | **0.425313** | **3.566044** | **16.89926** |


## Aritmetinio vidurkio formulė

Kiekvienos eilutės vidurkis skaičiuojamas taip:

\[
\text{Vidurkis} = \frac{t_1 + t_2 + t_3 + t_4 + t_5}{5}
\]

Kur \( t_i \) — kiekvieno bandymo rezultatas sekundėmis.



##IŠVADOS
Atliekant našumo testus, pastebėta, kad std::list konteineris su dideliais duomenų rinkiniais (≥100000) veikė šiek tiek greičiau už std::vector.
Tai galima paaiškinti tuo, kad list::sort() nevykdo elementų kopijavimo, o tik sukeičia rodykles, todėl didesnių objektų atveju jis išvengia papildomų atminties operacijų.
Tačiau skirtumas tarp konteinerių nėra reikšmingas - abiejų augimas atitinka O(n log n) priklausomybę, o dominuojantis faktorius yra IO (failų skaitymas ir rašymas).
