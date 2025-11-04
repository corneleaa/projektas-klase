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

| Strategija | Aprašymas                                                                    | Naudoti STL algoritmai                                           | Atminties naudojimas           |
| ---------- | ---------------------------------------------------------------------------- | ---------------------------------------------------------------- | ------------------------------ |
| **1**      | Kuriami du nauji konteineriai („vargšiukai“ ir „kietuoliai“).                | `std::partition_copy`                                            | Didelis (duomenys dubliuojami) |
| **2**      | Kuriamas tik „vargšiukų“ konteineris, silpni studentai pašalinami iš bendro. | `std::partition`, `erase`, `splice`                              | Vidutinis                      |
| **3**      | Optimizuota versija naudojant efektyvius STL metodus.                        | `std::remove_if`, `std::remove_copy_if`, `std::stable_partition` | Mažiausias                     |

---

## Testavimo rezultatai

**Testuota su failais:**
`studentai10000.txt`, `studentai100000.txt`, `studentai1000000.txt`
Kiekvienas testas kartotas 3 kartus. Pateikiami tikslūs laikai (sekundėmis).

---

### Vector konteineris — studentai10000.txt

| Bandymas | Strategija | Nuskaitymas (s) | Rikiavimas (s) | Skirstymas (s) | Įrašymas (s) | Bendras (s) |
| -------- | ---------- | --------------- | -------------- | -------------- | ------------ | ----------- |
| 1        | 1          | 0.176802        | 0.011733       | 0.00497833     | 0.00949354   | 0.225143    |
| 2        | 1          | 0.174388        | 0.011748       | 0.00502871     | 0.00915188   | 0.222578    |
| 3        | 1          | 0.176422        | 0.0117576      | 0.00509237     | 0.00854437   | 0.224023    |
| 1        | 2          | 0.174511        | 0.0117719      | 0.00197142     | 0.0103111    | 0.220809    |
| 2        | 2          | 0.173692        | 0.0117344      | 0.00199771     | 0.00995008   | 0.21948     |
| 3        | 2          | 0.170056        | 0.011723       | 0.00202717     | 0.00832567   | 0.214283    |
| 1        | 3          | 0.162981        | 0.0117336      | 0.00452804     | 0.00956896   | 0.210888    |
| 2        | 3          | 0.174973        | 0.0117668      | 0.00442546     | 0.00837313   | 0.221631    |
| 3        | 3          | 0.169127        | 0.00487383     | 0.000353291    | 0.00877612   | 0.205471    |

---

###List konteineris — studentai10000.txt

| Bandymas | Strategija | Nuskaitymas (s) | Rikiavimas (s) | Skirstymas (s) | Įrašymas (s) | Bendras (s) |
| -------- | ---------- | --------------- | -------------- | -------------- | ------------ | ----------- |
| 1        | 1          | 0.155929        | 0.00490217     | 0.00422208     | 0.00943912   | 0.196909    |
| 2        | 1          | 0.170779        | 0.00488733     | 0.00436192     | 0.010068     | 0.212532    |
| 3        | 1          | 0.170635        | 0.00488333     | 0.00452508     | 0.009413     | 0.211787    |
| 1        | 2          | 0.168495        | 0.00490758     | 0.000363708    | 0.0103914    | 0.206617    |
| 2        | 2          | 0.171809        | 0.00490325     | 0.000362375    | 0.00995358   | 0.209469    |
| 3        | 2          | 0.168149        | 0.00488683     | 0.000345917    | 0.00916646   | 0.204801    |
| 1        | 3          | 0.156504        | 0.00487579     | 0.000357333    | 0.00931004   | 0.193391    |
| 2        | 3          | 0.165828        | 0.00490808     | 0.000363708    | 0.00847058   | 0.202077    |
| 3        | 3          | 0.168732        | 0.00489958     | 0.000354375    | 0.00845825   | 0.204977    |

---

### Vector konteineris — studentai100000.txt

| Bandymas | Strategija | Nuskaitymas | Rikiavimas | Skirstymas | Įrašymas  | Bendras |
| -------- | ---------- | ----------- | ---------- | ---------- | --------- | ------- |
| 1        | 1          | 1.98285     | 0.111561   | 0.0604001  | 0.0755691 | 2.53824 |
| 2        | 1          | 1.97227     | 0.111929   | 0.0599359  | 0.0746177 | 2.52749 |
| 3        | 1          | 1.96143     | 0.111655   | 0.0607049  | 0.0744775 | 2.51596 |
| 1        | 2          | 1.9717      | 0.112245   | 0.0230361  | 0.074624  | 2.49027 |
| 2        | 2          | 1.97542     | 0.111703   | 0.0234308  | 0.0747905 | 2.49445 |
| 3        | 2          | 1.97526     | 0.111959   | 0.0231305  | 0.0724896 | 2.48723 |
| 1        | 3          | 1.97825     | 0.112306   | 0.0553099  | 0.0744174 | 2.53069 |
| 2        | 3          | 1.97254     | 0.11219    | 0.0548223  | 0.0728491 | 2.52087 |
| 3        | 3          | 1.96995     | 0.111811   | 0.0560575  | 0.0745164 | 2.52123 |

---

### List konteineris — studentai100000.txt

| Bandymas | Strategija | Nuskaitymas | Rikiavimas | Skirstymas | Įrašymas  | Bendras |
| -------- | ---------- | ----------- | ---------- | ---------- | --------- | ------- |
| 1        | 1          | 1.91209     | 0.0588086  | 0.0466546  | 0.0755923 | 2.40251 |
| 2        | 1          | 1.91746     | 0.0594487  | 0.0466809  | 0.0791645 | 2.41442 |
| 3        | 1          | 1.91867     | 0.0593138  | 0.0468968  | 0.0750668 | 2.41084 |
| 1        | 2          | 1.91334     | 0.059163   | 0.00385487 | 0.0781225 | 2.3647  |
| 2        | 2          | 1.91306     | 0.0595481  | 0.003948   | 0.0758625 | 2.36419 |
| 3        | 2          | 1.91444     | 0.0594884  | 0.003929   | 0.0796372 | 2.37035 |
| 1        | 3          | 1.90944     | 0.0595954  | 0.004093   | 0.0797801 | 2.36634 |
| 2        | 3          | 1.91515     | 0.059133   | 0.00389296 | 0.0769812 | 2.36502 |
| 3        | 3          | 1.92009     | 0.0588458  | 0.00390342 | 0.0776425 | 2.36667 |

---

### Vector konteineris — studentai1000000.txt

| Bandymas | Strategija | Nuskaitymas | Rikiavimas | Skirstymas | Įrašymas | Bendras |
| -------- | ---------- | ----------- | ---------- | ---------- | -------- | ------- |
| 1        | 1          | 10.9285     | 0.950733   | 0.639673   | 0.690554 | 14.2955 |
| 2        | 1          | 10.8999     | 0.948828   | 0.64004    | 0.705786 | 14.2922 |
| 3        | 1          | 10.9193     | 0.952191   | 0.646462   | 0.712151 | 14.3259 |
| 1        | 2          | 10.8582     | 0.955049   | 0.218335   | 0.668969 | 13.796  |
| 2        | 2          | 10.9061     | 0.947983   | 0.218852   | 0.675099 | 13.8404 |
| 3        | 2          | 10.8709     | 0.950394   | 0.227725   | 0.705465 | 13.8504 |
| 1        | 3          | 10.8563     | 0.948902   | 0.514019   | 0.68855  | 14.1    |
| 2        | 3          | 10.863      | 0.94666    | 0.510136   | 0.707173 | 14.1158 |
| 3        | 3          | 10.8714     | 0.948048   | 0.517614   | 0.699241 | 14.1311 |

---

###List konteineris — studentai1000000.txt

| Bandymas | Strategija | Nuskaitymas | Rikiavimas | Skirstymas | Įrašymas | Bendras |
| -------- | ---------- | ----------- | ---------- | ---------- | -------- | ------- |
| 1        | 1          | 10.4808     | 0.960199   | 0.452516   | 0.716586 | 13.7257 |
| 2        | 1          | 10.4771     | 0.993263   | 0.454589   | 0.71749  | 13.7589 |
| 3        | 1          | 10.5739     | 0.971315   | 0.44657    | 0.771101 | 13.8876 |
| 1        | 2          | 10.4832     | 0.966153   | 0.191484   | 0.750865 | 13.5304 |
| 2        | 2          | 10.4554     | 0.928719   | 0.139281   | 0.753215 | 13.4116 |
| 3        | 2          | 10.4413     | 0.969502   | 0.202206   | 0.744568 | 13.4819 |
| 1        | 3          | 10.4693     | 1.0575     | 0.140476   | 0.764683 | 13.5541 |
| 2        | 3          | 10.4651     | 0.956061   | 0.133795   | 0.735243 | 13.4003 |
| 3        | 3          | 10.4882     | 0.9845     | 0.195863   | 0.741129 | 13.5464 |

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

`std::partition`, `std::partition_copy`, `std::stable_partition`,
`std::remove_if`, `std::remove_copy_if`, `std::move`, `std::sort`, `std::splice`.

---

## Papildoma informacija

* Programos veikimas **nepriklauso nuo interneto**.
* Testuota **macOS 14.5 (Apple M1, 8 GB RAM)**, `g++ 13.2`.
* Vidutinė veikimo sparta apskaičiuota pagal 3 kartotinius testus kiekvienai strategijai ir konteineriui.

