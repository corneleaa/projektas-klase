#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <chrono>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <ctime>

inline double mediana_ref(const std::vector<int>& v) {
    std::vector<int> tmp = v;
    return mediana(tmp);
}
class Studentas {
private:
    std::string vardas_;
    std::string pavarde_;
    std::vector<int> nd_;
    int egzaminas_;
    double galutinis_;

public:
    Studentas();
    Studentas(std::istream& is);
    ~Studentas();

    inline std::string vardas() const { return vardas_; }
    inline std::string pavarde() const { return pavarde_; }
    inline double galutinis() const { return galutinis_; }

    inline void setVardas(const std::string& v) { vardas_ = v; }
    inline void setPavarde(const std::string& p) { pavarde_ = p; }
    inline void setEgzaminas(int e) { egzaminas_ = e; }
    inline void setNd(const std::vector<int>& v) { nd_ = v; }

    std::istream& readStudent(std::istream& is);
    double skaiciuotiGalutini(double (*f)(const std::vector<int>&)) const;
    void perskaiciuoti(double (*f)(const std::vector<int>&));       // atnaujina galutinis_
    void spausdinti(std::ostream& os) const;
};

bool comparePagalVarda(const Studentas&, const Studentas&);
bool comparePagalPavarde(const Studentas&, const Studentas&);
bool comparePagalGalutini(const Studentas&, const Studentas&);

std::vector<Studentas> nuskaitytiIsFailo(const std::string& failas);

template <typename Container>
Container nuskaitytiIsFailoT(const std::string& failas) {
    Container grupe;
    std::ifstream in(failas);
    if (!in) {
        std::cerr << "Nepavyko atidaryti failo: " << failas << std::endl;
        return grupe;
    }
    std::string eil;
    std::getline(in, eil); // header
    while (std::getline(in, eil)) {
        if (eil.empty()) continue;
        std::istringstream iss(eil);
        Studentas s(iss);
        grupe.emplace_back(std::move(s));
    }
    std::cout << "Nuskaityta studentų: " << grupe.size() << std::endl;
    return grupe;
}
