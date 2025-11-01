#include "studentas.h"
#include <filesystem>

int main() {
    srand(time(nullptr));

    cout << "Pasirinkite režimą:\n"
         << "1) Generuoti naują failą\n"
         << "2) Naudoti esamą failą\n"
         << "3) Įvesti duomenis ranka\n";
    int rezimas;
    cin >> rezimas;

    string failas;
    int kiek = 0;

    if (rezimas == 1) {
        cout << "Įveskite failo pavadinimą (pvz. studentai1000.txt): ";
        cin >> failas;
        if (failas.find('.') == string::npos) failas += ".txt";
        cout << "Kiek studentų generuoti? ";
        cin >> kiek;

        auto start_gen = std::chrono::high_resolution_clock::now();
        generuotiFaila(failas, kiek);
        auto end_gen = std::chrono::high_resolution_clock::now();

        cout << "Failas sugeneruotas per "
             << std::chrono::duration<double>(end_gen - start_gen).count()
             << " s.\n";
    }
    else if (rezimas == 2) {
        cout << "Įveskite esamo failo pavadinimą: ";
        cin >> failas;
        if (failas.find('.') == string::npos) failas += ".txt";
    }
    else if (rezimas == 3) {
        cout << "Pasirinkite konteinerį:\n"
             << "1) std::vector\n"
             << "2) std::list\n";
        int kon;
        cin >> kon;
        cout << "Kiek studentų norite įvesti? ";
        cin >> kiek;

        if (kon == 1) {
            vector<Studentas> grupe;
            for (int i = 0; i < kiek; i++) {
                Studentas s;
                cout << "\nStudentas #" << i + 1 << endl;
                cout << "Vardas: ";
                cin >> s.vardas;
                cout << "Pavarde: ";
                cin >> s.pavarde;
                cout << "Įveskite 5 namų darbų pažymius: ";
                for (int j = 0; j < 5; j++) {
                    int paz;
                    cin >> paz;
                    s.pazymiai.push_back(paz);
                }
                cout << "Egzamino pažymys: ";
                cin >> s.egzaminas;
                s.galutinis = skaiciuotiGalutiniPagalTipa(s.pazymiai, s.egzaminas, 1);

                grupe.push_back(s);
                cout << "Objekto adresas atmintyje (saugojamas konteineryje): " << &grupe.back() << endl; // nauja eilutė v0.3
            }
            ofstream out("ivedimas_vector.txt");
            out << left << setw(12) << "Vardas"
                << setw(12) << "Pavarde"
                << setw(10) << "Egzaminas"
                << setw(15) << "Galutinis(vid)" << "\n";
            for (auto &s : grupe) {
                out << left << setw(12) << s.vardas
                    << setw(12) << s.pavarde
                    << setw(10) << s.egzaminas
                    << setw(15) << fixed << setprecision(2) << s.galutinis << "\n";
            }
            cout << "Rezultatai įrašyti į failą: ivedimas_vector.txt\n";
        }
        else if (kon == 2) {
            list<Studentas> grupe;
            for (int i = 0; i < kiek; i++) {
                Studentas s;
                cout << "\nStudentas #" << i + 1 << endl;
                cout << "Vardas: ";
                cin >> s.vardas;
                cout << "Pavarde: ";
                cin >> s.pavarde;
                cout << "Įveskite 5 namų darbų pažymius: ";
                for (int j = 0; j < 5; j++) {
                    int paz;
                    cin >> paz;
                    s.pazymiai.push_back(paz);
                }
                cout << "Egzamino pažymys: ";
                cin >> s.egzaminas;
                s.galutinis = skaiciuotiGalutiniPagalTipa(s.pazymiai, s.egzaminas, 1);

                grupe.push_back(s);
                cout << "Objekto adresas atmintyje (saugojamas konteineryje): " << &grupe.back() << endl; // nauja eilutė v0.3
            }
            ofstream out("ivedimas_list.txt");
            out << left << setw(12) << "Vardas"
                << setw(12) << "Pavarde"
                << setw(10) << "Egzaminas"
                << setw(15) << "Galutinis(vid)" << "\n";
            for (auto &s : grupe) {
                out << left << setw(12) << s.vardas
                    << setw(12) << s.pavarde
                    << setw(10) << s.egzaminas
                    << setw(15) << fixed << setprecision(2) << s.galutinis << "\n";
            }
            cout << "Rezultatai įrašyti į failą: ivedimas_list.txt\n";
        }
        return 0;
    }

    cout << "Pasirinkite galutinio balo skaičiavimo būdą:\n"
         << "1) Pagal vidurkį\n"
         << "2) Pagal medianą\n"
         << "3) Pagal abu\n";
    int tipas;
    cin >> tipas;

    cout << "Pasirinkite konteinerį:\n"
         << "1) std::vector\n"
         << "2) std::list\n";
    int kon;
    cin >> kon;

    cout << "Rikiuoti pagal:\n"
         << "1) vardą\n"
         << "2) pavardę\n"
         << "3) galutinį\n";
    int rik;
    cin >> rik;

    string pagal;
    if (rik == 1) pagal = "vardas";
    else if (rik == 2) pagal = "pavarde";
    else pagal = "galutinis";

    cout << "\nDarbinis katalogas: " << std::filesystem::current_path() << "\n";

    auto start_total = std::chrono::high_resolution_clock::now();

    if (kon == 1) {
        auto start_read = std::chrono::high_resolution_clock::now();
        vector<Studentas> grupe = nuskaitytiIsFailo(failas);
        auto end_read = std::chrono::high_resolution_clock::now();
        cout << "Failo nuskaitymas (vector): "
             << std::chrono::duration<double>(end_read - start_read).count() << " s\n";

        for (auto &s : grupe)
            s.galutinis = skaiciuotiGalutiniPagalTipa(s.pazymiai, s.egzaminas, tipas);

        auto start_sort = std::chrono::high_resolution_clock::now();
        rikiuotiStudentus(grupe, pagal);
        auto end_sort = std::chrono::high_resolution_clock::now();
        cout << "Rikiavimas: "
             << std::chrono::duration<double>(end_sort - start_sort).count() << " s\n";

        auto start_split = std::chrono::high_resolution_clock::now();
        vector<Studentas> vargs, kiet;
        padalintiStudentusTik(grupe, vargs, kiet);
        auto end_split = std::chrono::high_resolution_clock::now();
        cout << "Padalinimas į 2 grupes: "
             << std::chrono::duration<double>(end_split - start_split).count() << " s\n";

        auto start_write = std::chrono::high_resolution_clock::now();
        ofstream outV("vargsiukai.txt");
        ofstream outK("kietuoliai.txt");

        auto spausdinti = [&](ofstream &out, const vector<Studentas> &v) {
            out << left << setw(12) << "Vardas"
                << setw(12) << "Pavarde"
                << setw(10) << "Egzaminas"
                << setw(15) << "Galutinis" << "\n";
            for (auto &s : v) {
                out << left << setw(12) << s.vardas
                    << setw(12) << s.pavarde
                    << setw(10) << s.egzaminas
                    << setw(15) << fixed << setprecision(2) << s.galutinis << "\n";
            }
        };

        spausdinti(outV, vargs);
        spausdinti(outK, kiet);

        auto end_write = std::chrono::high_resolution_clock::now();
        cout << "Įrašymas į failus (vargsiukai.txt ir kietuoliai.txt): "
             << std::chrono::duration<double>(end_write - start_write).count() << " s\n";
    }
    else {
        auto start_read = std::chrono::high_resolution_clock::now();
        list<Studentas> grupe = nuskaitytiIsFailoT<list<Studentas>>(failas);
        auto end_read = std::chrono::high_resolution_clock::now();
        cout << "Failo nuskaitymas (list): "
             << std::chrono::duration<double>(end_read - start_read).count() << " s\n";

        for (auto &s : grupe)
            s.galutinis = skaiciuotiGalutiniPagalTipa(s.pazymiai, s.egzaminas, tipas);

        auto start_sort = std::chrono::high_resolution_clock::now();
        if (pagal == "vardas")
            grupe.sort([](auto &a, auto &b) { return a.vardas < b.vardas; });
        else if (pagal == "pavarde")
            grupe.sort([](auto &a, auto &b) { return a.pavarde < b.pavarde; });
        else
            grupe.sort([](auto &a, auto &b) { return a.galutinis < b.galutinis; });
        auto end_sort = std::chrono::high_resolution_clock::now();
        cout << "Rikiavimas: "
             << std::chrono::duration<double>(end_sort - start_sort).count() << " s\n";

        auto start_split = std::chrono::high_resolution_clock::now();
        list<Studentas> vargs, kiet;
        padalintiStudentusTikT(grupe, vargs, kiet);
        auto end_split = std::chrono::high_resolution_clock::now();
        cout << "Padalinimas į 2 grupes: "
             << std::chrono::duration<double>(end_split - start_split).count() << " s\n";

        auto start_write = std::chrono::high_resolution_clock::now();
        ofstream outV("vargsiukai.txt");
        ofstream outK("kietuoliai.txt");

        auto spausdintiList = [&](ofstream &out, const list<Studentas> &v) {
            out << left << setw(12) << "Vardas"
                << setw(12) << "Pavarde"
                << setw(10) << "Egzaminas"
                << setw(15) << "Galutinis" << "\n";
            for (auto &s : v) {
                out << left << setw(12) << s.vardas
                    << setw(12) << s.pavarde
                    << setw(10) << s.egzaminas
                    << setw(15) << fixed << setprecision(2) << s.galutinis << "\n";
            }
        };

        spausdintiList(outV, vargs);
        spausdintiList(outK, kiet);

        auto end_write = std::chrono::high_resolution_clock::now();
        cout << "Įrašymas į failus (vargsiukai.txt ir kietuoliai.txt): "
             << std::chrono::duration<double>(end_write - start_write).count() << " s\n";
    }

    auto end_total = std::chrono::high_resolution_clock::now();
    cout << "Bendras veikimo laikas: "
         << std::chrono::duration<double>(end_total - start_total).count() << " s.\n";
    cout << "Rezultatų failai sukurti čia: " << std::filesystem::current_path() << endl;
    return 0;
}

