#include "studentas.h"
double skaiciuotiVidurki(const vector<int>& v) {
    if (v.empty()) return 0.0;
    double suma = 0;
    for (int x : v) suma += x;
    return suma / v.size();
}

double skaiciuotiMediana(vector<int> v) {
    if (v.empty()) return 0.0;
    std::sort(v.begin(), v.end());
    size_t n = v.size();
    if (n % 2 == 0)
        return (v[n/2 - 1] + v[n/2]) / 2.0;
    else
        return v[n/2];
}

double skaiciuotiGalutini(const vector<int>& paz, int egz) {
    return skaiciuotiVidurki(paz) * 0.4 + egz * 0.6;
}

double skaiciuotiGalutiniPagalTipa(const vector<int>& paz, int egz, int tipas) {
    double vid = skaiciuotiVidurki(paz);
    double med = skaiciuotiMediana(paz);
    if (tipas == 1) return vid * 0.4 + egz * 0.6;
    if (tipas == 2) return med * 0.4 + egz * 0.6;
    return ((vid + med) / 2.0) * 0.4 + egz * 0.6;
}
Studentas generuotiStudenta(int id) {
    Studentas s;
    s.vardas = "Vardas" + std::to_string(id);
    s.pavarde = "Pavarde" + std::to_string(id);
    for (int i = 0; i < 5; i++) s.pazymiai.push_back(1 + rand() % 10);
    s.egzaminas = 1 + rand() % 10;
    s.galutinis = skaiciuotiGalutini(s.pazymiai, s.egzaminas);
    return s;
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

