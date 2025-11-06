#include "studentas.h"
#include <chrono>
#include <filesystem>

Studentas::Studentas() : egzaminas_(0), galutinis_(0.0) {}
Studentas::~Studentas() {}
Studentas::Studentas(std::istream& is) { readStudent(is); }

std::istream& Studentas::readStudent(std::istream& is) {
    is >> vardas_ >> pavarde_;
    nd_.resize(5);
    for (int i = 0; i < 5; ++i) is >> nd_[i];
    is >> egzaminas_;
    // pradinis galutinis pagal vidurkį
    galutinis_ = skaiciuotiGalutini(vidurkis);
    return is;
}

double Studentas::skaiciuotiGalutini(double (*f)(const std::vector<int>&)) const {
    return 0.4 * f(nd_) + 0.6 * egzaminas_;
}

void Studentas::perskaiciuoti(double (*f)(const std::vector<int>&)) {
    galutinis_ = 0.4 * f(nd_) + 0.6 * egzaminas_;
}

void Studentas::spausdinti(std::ostream& os) const {
    os << std::left << std::setw(12) << vardas_
       << std::setw(12) << pavarde_
       << std::setw(10) << std::fixed << std::setprecision(2) << galutinis_ << "\n";
}

bool comparePagalVarda(const Studentas& a, const Studentas& b) { return a.vardas() < b.vardas(); }
bool comparePagalPavarde(const Studentas& a, const Studentas& b) { return a.pavarde() < b.pavarde(); }
bool comparePagalGalutini(const Studentas& a, const Studentas& b) { return a.galutinis() < b.galutinis(); }

std::vector<Studentas> nuskaitytiIsFailo(const std::string& failas) {
    return nuskaitytiIsFailoT<std::vector<Studentas>>(failas);
}
void isvestiStudentus(const std::vector<Studentas>& grupe, const std::string& failas) {
    isvestiStudentusT(grupe, failas);
}
Studentas generuotiStudenta(int id) {
    Studentas s;
    s.setVardas("Vardas" + std::to_string(id));
    s.setPavarde("Pavarde" + std::to_string(id));
    std::vector<int> nd;
    nd.reserve(5);
    for (int i = 0; i < 5; ++i) nd.push_back(1 + rand() % 10);
    s.setNd(nd);
    s.setEgzaminas(1 + rand() % 10);
    s.perskaiciuoti(vidurkis);
    return s;
}
void generuotiFaila(const std::string& failoVardas, int kiek) {
    std::ofstream out(failoVardas);
    out << "Vardas Pavarde ND1 ND2 ND3 ND4 ND5 Egzaminas\n";
    for (int i = 1; i <= kiek; ++i) {
        Studentas s = generuotiStudenta(i);
        out << s.vardas() << " " << s.pavarde() << " ";
        for (int j = 0; j < 5; ++j) out << (rand() % 10 + 1) << " ";
        out << (rand() % 10 + 1) << "\n";
    }
}
static inline bool isVargs(const Studentas& s) { return s.galutinis() < 5.0; }

void split_strat1_vector(const std::vector<Studentas>& src,
                         std::vector<Studentas>& vargs,
                         std::vector<Studentas>& kiet) {
    vargs.clear(); kiet.clear();
    std::partition_copy(src.begin(), src.end(),
                        std::back_inserter(vargs),
                        std::back_inserter(kiet),
                        isVargs);
}

void split_strat2_vector(std::vector<Studentas>& all,
                         std::vector<Studentas>& vargs) {
    vargs.clear();
    auto mid = std::partition(all.begin(), all.end(), isVargs);
    std::move(all.begin(), mid, std::back_inserter(vargs));
    all.erase(all.begin(), mid);
}

void split_strat3_vector(std::vector<Studentas>& all,
                         std::vector<Studentas>& vargs) {
    vargs.clear();
    vargs.reserve(all.size() / 2);
    std::remove_copy_if(all.begin(), all.end(),
                        std::back_inserter(vargs),
                        [](const Studentas& s){ return !isVargs(s); });
    auto it = std::remove_if(all.begin(), all.end(), isVargs);
    all.erase(it, all.end());
    all.shrink_to_fit();
    vargs.shrink_to_fit();
}
void split_strat1_list(const std::list<Studentas>& src,
                       std::list<Studentas>& vargs,
                       std::list<Studentas>& kiet) {
    vargs.clear(); kiet.clear();
    std::partition_copy(src.begin(), src.end(),
                        std::back_inserter(vargs),
                        std::back_inserter(kiet),
                        isVargs);
}

void split_strat2_list(std::list<Studentas>& all,
                       std::list<Studentas>& vargs) {
    vargs.clear();
    for (auto it = all.begin(); it != all.end(); ) {
        if (isVargs(*it)) {
            auto cur = it++;
            vargs.splice(vargs.end(), all, cur);
        } else ++it;
    }
}
void split_strat3_list(std::list<Studentas>& all,
                       std::list<Studentas>& vargs) {
    split_strat2_list(all, vargs);
}
