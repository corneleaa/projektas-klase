
#ifndef STUDENTAS_UTILS_H
#define STUDENTAS_UTILS_H

#include "studentas.h"
#include <list>
#include <typeinfo>

template <typename Container>
void rikiuotiStudentus(Container& grupe, const std::string& pagal) {
    if (pagal == "vardas") {
        grupe.sort([](const Studentas& a, const Studentas& b) { return a.vardas < b.vardas; });
    } else if (pagal == "pavarde") {
        grupe.sort([](const Studentas& a, const Studentas& b) { return a.pavarde < b.pavarde; });
    } else if (pagal == "galutinis") {
        grupe.sort([](const Studentas& a, const Studentas& b) { return a.galutinis > b.galutinis; });
    } else if (pagal == "vidurkis") {
        grupe.sort([](const Studentas& a, const Studentas& b) {
            return skaiciuotiVidurki(a.pazymiai) > skaiciuotiVidurki(b.pazymiai);
        });
    } else if (pagal == "mediana") {
        grupe.sort([](const Studentas& a, const Studentas& b) {
            return skaiciuotiMediana(a.pazymiai) > skaiciuotiMediana(b.pazymiai);
        });
    }
}

// Vektoriui naudojame std::sort, nes neturi .sort()
template <>
void rikiuotiStudentus(std::vector<Studentas>& grupe, const std::string& pagal);

template <typename Container>
void padalintiStudentusTik(Container& grupe, Container& vargs, Container& kiet) {
    for (auto& s : grupe) {
        if (s.galutinis < 5.0)
            vargs.push_back(s);
        else
            kiet.push_back(s);
    }
}

template <typename Container>
void isvestiStudentus(const Container& grupe, const std::string& failoVardas) {
    std::ofstream out(failoVardas);
    out << std::setw(15) << std::left << "Vardas"
        << std::setw(15) << std::left << "Pavarde"
        << std::setw(10) << std::right << "Galutinis\n";
    for (auto& s : grupe) {
        out << std::setw(15) << std::left << s.vardas
            << std::setw(15) << std::left << s.pavarde
            << std::setw(10) << std::fixed << std::setprecision(2) << s.galutinis << "\n";
    }
}

#endif
