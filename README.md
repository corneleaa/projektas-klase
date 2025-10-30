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




