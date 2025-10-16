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

// ✅ Nauja dalis – studento generavimas programiškai
Studentas generuotiStudenta(int id) {
    Studentas s;
    s.vardas = "Vardas" + std::to_string(id);
    s.pavarde = "Pavarde" + std::to_string(id);

    int nd = 5;
    for (int i = 0; i < nd; i++) {
        s.pazymiai.push_back(1 + rand() % 10);
    }

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

void rikiuotiStudentus(vector<Studentas>& grupe, const string& pagal) {
    if (pagal == "vardas") {
        std::sort(grupe.begin(), grupe.end(), [](auto& a, auto& b) { return a.vardas < b.vardas; });
    } else if (pagal == "pavarde") {
        std::sort(grupe.begin(), grupe.end(), [](auto& a, auto& b) { return a.pavarde < b.pavarde; });
    } else if (pagal == "galutinis") {
        std::sort(grupe.begin(), grupe.end(), [](auto& a, auto& b) { return a.galutinis < b.galutinis; });
    }
}

void padalintiStudentusTik(vector<Studentas>& grupe, vector<Studentas>& vargs, vector<Studentas>& kiet) {
    for (auto& s : grupe) {
        if (s.galutinis < 5.0) vargs.push_back(s);
        else kiet.push_back(s);
    }
}

void isvestiStudentus(const vector<Studentas>& grupe, const string& failoVardas) {
    ofstream out(failoVardas);
    out << setw(15) << left << "Vardas"
        << setw(15) << left << "Pavarde"
        << setw(10) << right << "Galutinis\n";
    for (auto& s : grupe) {
        out << setw(15) << left << s.vardas
            << setw(15) << left << s.pavarde
            << setw(10) << fixed << setprecision(2) << s.galutinis << "\n";
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
        istringstream iss(eilute);
        Studentas s;
        iss >> s.vardas >> s.pavarde;

        vector<int> paz;
        int pazymys;
        while (iss >> pazymys) paz.push_back(pazymys);

        if (!paz.empty()) {
            s.egzaminas = paz.back();
            paz.pop_back();
            s.pazymiai = paz;
            s.galutinis = skaiciuotiGalutini(s.pazymiai, s.egzaminas);
            grupe.push_back(s);
        }
    }
    return grupe;
}

// ✅ Ši funkcija buvo papildoma – skirsto studentus tiesiogiai į du failus skaitymo metu
void processStreaming(const string& failoVardas,
                      const string& failasVargs,
                      const string& failasKiet) {
    ifstream in(failoVardas);
    ofstream outV(failasVargs);
    ofstream outK(failasKiet);

    string eilute;
    getline(in, eilute); // praleidžiama antraštė
    while (getline(in, eilute)) {
        istringstream iss(eilute);
        Studentas s;
        iss >> s.vardas >> s.pavarde;
        vector<int> paz;
        int x;
        while (iss >> x) paz.push_back(x);
        if (!paz.empty()) {
            s.egzaminas = paz.back();
            paz.pop_back();
            s.pazymiai = paz;
            s.galutinis = skaiciuotiGalutini(s.pazymiai, s.egzaminas);
        }

        if (s.galutinis < 5.0)
            outV << s.vardas << " " << s.pavarde << " " << s.galutinis << "\n";
        else
            outK << s.vardas << " " << s.pavarde << " " << s.galutinis << "\n";
    }
}

