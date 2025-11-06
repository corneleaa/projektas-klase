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

void generuotiFaila(const string& failoVardas, int kiek) {
    ofstream out(failoVardas);
    if (!out) {
        cerr << "Nepavyko sukurti failo: " << failoVardas << endl;
        return;
    }
    out << "Vardas Pavarde ND1 ND2 ND3 ND4 ND5 Egzaminas\n";
    for (int i = 1; i <= kiek; i++) {
        Studentas s = generuotiStudenta(i);
        out << s.vardas << " " << s.pavarde << " ";
        for (int paz : s.pazymiai) out << paz << " ";
        out << s.egzaminas << "\n";
    }
}

vector<Studentas> nuskaitytiIsFailo(const string& failoVardas) {
    vector<Studentas> grupe;
    ifstream in(failoVardas);
    if (!in) {
        cerr << "Nepavyko atidaryti failo: " << failoVardas << endl;
        return grupe;
    }
    string eilute;
    getline(in, eilute);
    while (getline(in, eilute)) {
        if (eilute.empty()) continue;

        if (!eilute.empty() && eilute.back() == '\r')
            eilute.pop_back();
        std::replace(eilute.begin(), eilute.end(), '\t', ' ');

        istringstream iss(eilute);
        Studentas s;
        iss >> s.vardas >> s.pavarde;

        vector<int> paz;
        int pazymys;
        while (iss >> pazymys)
            paz.push_back(pazymys);
        if (!paz.empty()) {
            s.egzaminas = paz.back();
            paz.pop_back();
            s.pazymiai = paz;
            s.galutinis = skaiciuotiGalutini(s.pazymiai, s.egzaminas);
            grupe.push_back(s);
        }
    }
    cout << " Nuskaityta studentų: " << grupe.size() << endl;
    return grupe;
}
void rikiuotiStudentus(vector<Studentas>& grupe, const string& pagal) {
    if (pagal == "vardas")
        std::sort(grupe.begin(), grupe.end(), [](auto& a, auto& b){ return a.vardas < b.vardas; });
    else if (pagal == "pavarde")
        std::sort(grupe.begin(), grupe.end(), [](auto& a, auto& b){ return a.pavarde < b.pavarde; });
    else
        std::sort(grupe.begin(), grupe.end(), [](auto& a, auto& b){ return a.galutinis < b.galutinis; });
}
void padalintiStudentusTik(vector<Studentas>& grupe, vector<Studentas>& vargs, vector<Studentas>& kiet) {
    for (auto& s : grupe) {
        if (s.galutinis < 5.0) vargs.push_back(s);
        else kiet.push_back(s);
    }
}
void isvestiStudentus(const vector<Studentas>& grupe, const string& failoVardas) {
    ofstream out(failoVardas);
    if (!out) {
        cerr << "Nepavyko sukurti išvesties failo: " << failoVardas << endl;
        return;
    }
    out << setw(15) << left << "Vardas"
        << setw(15) << left << "Pavarde"
        << setw(10) << right << "Galutinis\n";
    for (auto& s : grupe)
        out << setw(15) << left << s.vardas
            << setw(15) << left << s.pavarde
            << setw(10) << fixed << setprecision(2) << s.galutinis << "\n";
}
bool yraVargsiukas(const Studentas& s) {
    return s.galutinis < 5.0;
}
void split_strat1_vector(const std::vector<Studentas>& src,
                         std::vector<Studentas>& vargs,
                         std::vector<Studentas>& kiet) {
    vargs.clear(); kiet.clear();
    std::partition_copy(src.begin(), src.end(),
                        std::back_inserter(vargs),
                        std::back_inserter(kiet),
                        yraVargsiukas);
}

void split_strat1_list(const std::list<Studentas>& src,
                       std::list<Studentas>& vargs,
                       std::list<Studentas>& kiet) {
    vargs.clear(); kiet.clear();
    std::partition_copy(src.begin(), src.end(),
                        std::back_inserter(vargs),
                        std::back_inserter(kiet),
                        yraVargsiukas);
}
void split_strat2_vector(std::vector<Studentas>& all,
                         std::vector<Studentas>& vargs) {
    vargs.clear();
    auto mid = std::partition(all.begin(), all.end(), yraVargsiukas);
    std::move(all.begin(), mid, std::back_inserter(vargs));
    all.erase(all.begin(), mid);
}

void split_strat2_list(std::list<Studentas>& all,
                       std::list<Studentas>& vargs) {
    vargs.clear();
    for (auto it = all.begin(); it != all.end();) {
        if (yraVargsiukas(*it)) {
            auto cur = it++;
            vargs.splice(vargs.end(), all, cur);
        } else ++it;
    }
}
void split_strat3_vector(std::vector<Studentas>& all,
                         std::vector<Studentas>& vargs) {
    vargs.clear();
    vargs.reserve(all.size() / 2);
    std::remove_copy_if(all.begin(), all.end(),
                        std::back_inserter(vargs),
                        [](const Studentas& s){ return s.galutinis >= 5.0; });

    auto it = std::remove_if(all.begin(), all.end(),
                             [](const Studentas& s){ return s.galutinis < 5.0; });
    all.erase(it, all.end());

    all.shrink_to_fit();
    vargs.shrink_to_fit();
}
void split_strat3_vector_stable(std::vector<Studentas>& all,
                                std::vector<Studentas>& vargs) {
    vargs.clear();
    vargs.reserve(all.size() / 2);

    auto mid = std::stable_partition(all.begin(), all.end(),
                                     [](const Studentas& s){ return s.galutinis < 5.0; });

    vargs.insert(vargs.end(),
                 std::make_move_iterator(all.begin()),
                 std::make_move_iterator(mid));

    all.erase(all.begin(), mid);
}
void split_strat3_list(std::list<Studentas>& all,
                       std::list<Studentas>& vargs) {
    vargs.clear();
    for (auto it = all.begin(); it != all.end();) {
        if (it->galutinis < 5.0) {
            auto moveIt = it++;
            vargs.splice(vargs.end(), all, moveIt);
        } else ++it;
    }
}
template <typename Container>
Container nuskaitytiIsFailoT(const string& failoVardas) {
    Container grupe;
    ifstream in(failoVardas);
    if (!in) {
        cerr << "Nepavyko atidaryti failo: " << failoVardas << endl;
        return grupe;
    }

    string eilute;
    getline(in, eilute);

    while (getline(in, eilute)) {
        if (eilute.empty()) continue;

        if (!eilute.empty() && eilute.back() == '\r')
            eilute.pop_back();

        std::replace(eilute.begin(), eilute.end(), '\t', ' ');

        istringstream iss(eilute);
        Studentas s;
        iss >> s.vardas >> s.pavarde;

        vector<int> paz;
        int pazymys;
        while (iss >> pazymys)
            paz.push_back(pazymys);

        if (!paz.empty()) {
            s.egzaminas = paz.back();
            paz.pop_back();
            s.pazymiai = paz;
            s.galutinis = skaiciuotiGalutini(s.pazymiai, s.egzaminas);
            grupe.emplace_back(std::move(s));
        }
    }

    cout << " Nuskaityta studentų: " << grupe.size() << endl;
    return grupe;
}
template <typename Container>
void padalintiStudentusTikT(const Container& grupe, Container& vargs, Container& kiet) {
    for (const auto& s : grupe) {
        if (s.galutinis < 5.0) vargs.emplace_back(s);
        else kiet.emplace_back(s);
    }
}
template <typename Container>
void isvestiStudentusT(const Container& grupe, const string& failoVardas) {
    ofstream out(failoVardas);
    if (!out) {
        cerr << "Nepavyko sukurti išvesties failo: " << failoVardas << endl;
        return;
    }
    out << setw(15) << left << "Vardas"
        << setw(15) << left << "Pavarde"
        << setw(10) << right << "Galutinis\n";
    for (const auto& s : grupe)
        out << setw(15) << left << s.vardas
            << setw(15) << left << s.pavarde
            << setw(10) << fixed << setprecision(2) << s.galutinis << "\n";
}
template vector<Studentas> nuskaitytiIsFailoT<vector<Studentas>>(const string&);
template list<Studentas> nuskaitytiIsFailoT<list<Studentas>>(const string&);
template void padalintiStudentusTikT<vector<Studentas>>(const vector<Studentas>&, vector<Studentas>&, vector<Studentas>&);
template void padalintiStudentusTikT<list<Studentas>>(const list<Studentas>&, list<Studentas>&, list<Studentas>&);
template void isvestiStudentusT<vector<Studentas>>(const vector<Studentas>&, const string&);
template void isvestiStudentusT<list<Studentas>>(const list<Studentas>&, const string&);
